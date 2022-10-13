#include "touch.h"
int tsfd ;//����������
//�򿪴�����
int touch_open()	
{	
	tsfd=open("/dev/input/event0",O_RDWR);	//�򿪴���������
	
	if(tsfd==-1)
	{
		perror("�򿪴�����ʧ��!\n");
		return -1;
	}
	return 0;
	
}

int get_xy(int *x, int *y)		//��ȡ������������ֵ
{
	struct input_event myevent;
	int count = 0;
	while(1)
	{
		read(tsfd,&myevent,sizeof(myevent));
		
		if(myevent.type==EV_ABS) //˵���������Ǵ������¼�
		{
			if(myevent.code==ABS_X) //x����
			{
				*x = (myevent.value*800)/1024;
				count ++;
			}
			
			if(myevent.code==ABS_Y) //y����
			{
				*y = (myevent.value*480)/600;
				count ++;
			}
		}
		if(count == 2)break;
	}
}	

//�رմ�����
int touch_close()	
{
	close(tsfd);
	return 0;
}

