#include "bmp.h"
#include "login.h"
int main(int argc, char **argv)
{
    struct lcd lcd;
    //初始化LCD
    lcd_init(&lcd);

    //显示大图
	int i;
	
	for(int i=0; i<=30; i++)
	{
		char data[15];
		snprintf(data, 15, "./img/%d.bmp", i);
		printf("data:%s\n", data);
		
		display_bmp(data, lcd.map_ptr, 0, 0);
		usleep(1000);	
	}	
	
	//开始、登录和注册
	login();
	//管理员界面
	display_bmp("./img/root.bmp", lcd.map_ptr, 0, 0);
   
	 //释放LCD
    lcd_uninit(&lcd);

    return 0;
}
