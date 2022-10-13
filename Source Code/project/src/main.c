#include "bmp.h"
#include "login.h"
int main(int argc, char **argv)
{
    struct lcd lcd;
    //��ʼ��LCD
    lcd_init(&lcd);

    //��ʾ��ͼ
	int i;
	
	for(int i=0; i<=30; i++)
	{
		char data[15];
		snprintf(data, 15, "./img/%d.bmp", i);
		printf("data:%s\n", data);
		
		display_bmp(data, lcd.map_ptr, 0, 0);
		usleep(1000);	
	}	
	
	//��ʼ����¼��ע��
	login();
	//����Ա����
	display_bmp("./img/root.bmp", lcd.map_ptr, 0, 0);
   
	 //�ͷ�LCD
    lcd_uninit(&lcd);

    return 0;
}
