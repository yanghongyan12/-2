#include "bmp.h"

static struct fb_var_screeninfo vinfo;

unsigned int get_file_size(char *file_name)
{
    struct stat fielstatu;
    int ret = stat(file_name, &fielstatu);
    if(ret == 0)
    {
        return fielstatu.st_size;
    }

    return 0;
}


void lcd_init(struct  lcd *p)
{
    // ��LCD�豸�ļ�
    p->fd = open("/dev/fb0", O_RDWR);    //32bit
    if(p->fd == -1)
    {
        perror("open LCD device failed");
        exit(0);
    }
    //��ȡLCDӲ������ --> ����ʾ����Ŀ�͸�
    memset(&vinfo, 0, sizeof vinfo);
    ioctl(p->fd, FBIOGET_VSCREENINFO, &vinfo);
    // �����ڴ�ӳ��                lcd��       lcd��          lcdɫ��
    p->map_ptr = (int *)mmap(NULL, vinfo.xres*vinfo.yres*vinfo.bits_per_pixel/8, 
                           PROT_READ|PROT_WRITE, MAP_SHARED, p->fd, 0);
    if(p->map_ptr == MAP_FAILED)
    {
        perror("memory mapping failed");
        exit(0);
    }

    return;
}

void lcd_uninit(struct  lcd *p)
{
    // ���ӳ��
    munmap(p->map_ptr, vinfo.xres*vinfo.yres*vinfo.bits_per_pixel/8);

    // �ر�LCD�豸�ļ�
    close(p->fd);
}

void display_bmp(char *filename, int *ptr, unsigned int x_f, unsigned int y_f)
{
    // ��BMPͼƬ�ļ�
    FILE *bmp_fd = fopen(filename, "r");
    if(bmp_fd == NULL)
    {
        perror("open BMP file failed");
        exit(0);
    }
    // ��ȡͼƬ�ļ���ͼ������
    unsigned int bitmap_datasize, bitmap_width, bitmap_height;
    fseek(bmp_fd, 18, SEEK_SET);   //����λͼ�����Ϣ��
    fread(&bitmap_width, sizeof bitmap_width, 1, bmp_fd);   //��ȡ���
    fread(&bitmap_height, sizeof bitmap_height, 1, bmp_fd); //��ȡ�߶�
    bitmap_datasize = bitmap_width*bitmap_height;
    //size = get_file_size("mao.bmp");  //24bit
    printf("bitmap_datasize = %d\n", bitmap_datasize);
    char *pbmp_buf = calloc(1, bitmap_datasize*3);
    if(pbmp_buf == NULL)
    {
        perror("calloc failed");
        exit(0);
    }
    //�˵�ʣ�µ�λͼ��Ϣ
    fseek(bmp_fd, 28, SEEK_CUR);
    fread(pbmp_buf, bitmap_datasize*3, 1, bmp_fd);

    // �ر�BMP�ļ�
    fclose(bmp_fd);
   
    int color;
    // ��ͼ�����ݴ���LCDӳ���ڴ���
    for (int i = 0; i < bitmap_height; i++)
    {
        for (int j = 0; j < bitmap_width; j++)
        {
            color = pbmp_buf[((bitmap_height-1-i)*bitmap_width+j)*3]        | 
                    pbmp_buf[((bitmap_height-1-i)*bitmap_width+j)*3+1]<<8   | 
                    pbmp_buf[((bitmap_height-1-i)*bitmap_width+j)*3+2]<<16  | 
                    0x00<<24;
            memcpy(ptr+(i+y_f)*vinfo.xres+j+x_f, &color, sizeof color); //�ڴ濽��
        }
        
    }

    // �ͷ��ڴ�
    free(pbmp_buf);
}
