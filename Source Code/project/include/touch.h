#ifndef _TOUCH_H_
#define _TOUCH_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <linux/input.h>
#include <errno.h>
#include <dirent.h>


int touch_open();
int get_xy(int *x, int *y);
int touch_close();

#endif