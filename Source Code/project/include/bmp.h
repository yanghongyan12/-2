#ifndef _BMP_H_
#define _BMP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <linux/fb.h>  
#include <sys/ioctl.h> 

struct  lcd
{
    int fd;
    int *map_ptr;
};

unsigned int get_file_size(char *file_name);
void lcd_init(struct  lcd *p);
void lcd_uninit(struct  lcd *p);
void display_bmp(char *filename, int *ptr, unsigned int x_f, unsigned int y_f);

#endif
