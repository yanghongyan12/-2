#include "user.h"
#include "bmp.h"
#include "touch.h"
#include <time.h>
#include "root.h"
#include "font.h"
#include "login.h"
struct lcd lcd;
int hour1 ;
int min1 ;
void memu()
{
	display_bmp("./img/user.bmp", lcd.map_ptr, 0, 0);
	int userx=0,usery=0;
	
	while(1)
    {
        get_xy(&userx,&usery);
        if(userx>65&&userx<235&&usery>62&&usery<147)//??????
        {  
            user_info();
        }
        else if(userx>318&&userx<489&&usery>62&&usery<150)//??????
        {
            time_t t;
            struct tm * lt;
            //???Unix??????
            time (&t);
            //????????
            lt = localtime (&t);
            //??????
            hour1 = lt->tm_hour;
            min1 = lt->tm_min;

            start_power();
        }
        // else if(x>320&&x<448&&y>62&&y<147)//??????
        // {
        //     del_user();
            
        // }
        // else if(x>65&&x<235&&y>339&&y<423)//??????
        // {
        //     power();
            
        // }
        //  else if(x>320&&x<448&&y>339&&y<423)//??????
        // {
            
            
        // }
        else if(userx>571&&userx<741&&usery>339&&usery<423)//????
        {
            
            sigin();
            
        }
        
    }
}
void user_info()
{
	display_bmp("./img/user_info.bmp", lcd.map_ptr, 0, 0);
	int fx=0,fy=0;
	while(1)
	{
		get_xy(&fx,&fy);
		printf("1\n");
			//?????????
		if(fx>644&&fx<782&&fy>404&&fy<470)
		{
			printf("1\n");
			memu();
		}
			
	}
}
void start_power()
{
    Init_Font();
    display_bmp("./img/start_power.bmp", lcd.map_ptr, 0, 0);
    printf ( "??????%d:%d\n",hour1, min1);
    int ix,iy;
    while (1)
    {
        get_xy(&ix,&iy);
        if(ix>547&&ix<800&&iy>0&&iy<80)
        {
            memu();
        }
        else if(ix>541&&ix<739&&iy>326&&iy<438)
        {
            time_t t2;
            struct tm * lt2;
            //???Unix??????
            time (&t2);
            //????????
            lt2 = localtime (&t2);
            //??????
            int hour2 = lt2->tm_hour;
            int min2 = lt2->tm_min;
            printf ( "??????%d:%d\n",hour2, min2);
            int hour = hour2-hour1;
            int min = min2-min1;
            int time = hour*60+min;
            int money = time*3;
            char time1[256];
            char money1[256];
            itoa(time,time1,10);
            itoa(money,money1,10);
            char string[500];
            strcat(string,"??????");
            strcat(string,time1);
            strcat(string,"???????????");
            strcat(string,money1);
            Display_characterX(22,373,string,0xFFA500,2);
        }
    }
    UnInit_Font();
    
    
}