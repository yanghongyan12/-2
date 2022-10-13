#include "touch.h"
int tsfd ;//触摸屏驱动
//打开触摸屏
int touch_open()	
{	
	tsfd=open("/dev/input/event0",O_RDWR);	//打开触摸屏驱动
	
	if(tsfd==-1)
	{
		perror("打开触摸屏失败!\n");
		return -1;
	}
	return 0;
	
}

int get_xy(int *x, int *y)		//获取触摸屏的坐标值
{
	struct input_event myevent;
	int count = 0;
	while(1)
	{
		read(tsfd,&myevent,sizeof(myevent));
		
		if(myevent.type==EV_ABS) //说明触发的是触摸屏事件
		{
			if(myevent.code==ABS_X) //x坐标
			{
				*x = (myevent.value*800)/1024;
				count ++;
			}
			
			if(myevent.code==ABS_Y) //y坐标
			{
				*y = (myevent.value*480)/600;
				count ++;
			}
		}
		if(count == 2)break;
	}
}	

//关闭触摸屏
int touch_close()	
{
	close(tsfd);
	return 0;
}

