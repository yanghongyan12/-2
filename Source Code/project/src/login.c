#include "bmp.h"
#include "login.h"
#include "font.h"
#include "touch.h"
#include "root.h"
#include "user.h"

struct lcd lcd;
char *banziname="12345";//内置账号
char *banzipassword="12345";//内置密码

//???????
void jianpan(char name[20],int start_idx,int start_idy)
{
	int number;
	int id_num=0;
	int x = 0,y = 0;
	while(1)
	{
				
		get_xy(&x,&y);
		if(x>547&&x<648&&y>360&&y<430)//???
		{
			if(id_num==0)
			{
				printf("the input box is empry,please iput\n");
			}
			else
			{
				id_num--;
				start_idx-=20;
				Clean_Area(start_idx,start_idy,30,30,0xffffffff);
			}
		}
		else if(x>448&&x<547&&y>153&&y<223)//1
		{
			printf("1\n");
			Display_characterX(start_idx,start_idy,"1",0x00000000,2);
			start_idx+=20;
			number = 1;
			name[id_num++] = '0'+ number;
		}
		else if(x>547&&x<648&&y>153&&y<223)//2

		{
			printf("2\n");
			Display_characterX(start_idx,start_idy,"2",0x00000000,2);
			start_idx+=20;
			number = 2;
			name[id_num++] = '0'+ number;
			
		}
		else if(x>648&&x<746&&y>153&&y<223)//3
		{
			printf("3\n");
			Display_characterX(start_idx,start_idy,"3",0x00000000,2);
			start_idx+=20;
			number = 3;
			name[id_num++] = '0'+ number;
		}
		else if(x>448&&x<547&&y>223&&y<294)//4
		{
			printf("4\n");
			Display_characterX(start_idx,start_idy,"4",0x00000000,2);
			start_idx+=20;
			number = 4;
			name[id_num++] = '0'+ number;
		}
		else if(x>547&&x<648&&y>223&&y<294)//5
		{
			printf("5\n");
			Display_characterX(start_idx,start_idy,"5",0x00000000,2);
			start_idx+=20;
			number = 5;
			name[id_num++] = '0'+ number;
		}
		else if(x>648&&x<746&&y>223&&y<294)//6
		{
			printf("6\n");
			Display_characterX(start_idx,start_idy,"6",0x00000000,2);
			start_idx+=20;
			number = 6;
			name[id_num++] = '0'+ number;
		}
		else if(x>448&&x<547&&y>294&&y<360)//7
		{
			printf("7\n");
			Display_characterX(start_idx,start_idy,"7",0x00000000,2);
			start_idx+=20;
			number = 7;
			name[id_num++] = '0'+ number;
		}
		else if(x>547&&x<648&&y>294&&y<360)//8
		{
			printf("8\n");
			Display_characterX(start_idx,start_idy,"8",0x00000000,2);
			start_idx+=20;
			number = 8;
			name[id_num++] = '0'+ number;
		}
		else if(x>648&&x<746&&y>294&&y<360)//9
		{
			printf("9\n");
			Display_characterX(start_idx,start_idy,"9",0x00000000,2);
			start_idx+=20;
			number = 9;
			name[id_num++] = '0'+ number;
		}
		else if(x>448&&x<547&&y>360&&y<430)//0
		{
			printf("0\n");
			Display_characterX(start_idx,start_idy,"0",0x00000000,2);
			start_idx+=20;
			number = 0;
			name[id_num++] = '0'+ number;
		}
		else if(x>648&&x<746&&y>360&&y<430)//OK
		{
			name[id_num]='\0';
			printf("%s\n",name);
			break;
		}
	}
}
void sigin()
{
	Init_Font(); 		
	
	display_bmp("./login.bmp", lcd.map_ptr, 0, 0);
	
	int ix = 0,iy = 0;
	char input_pasward[20];
	char input_id[20];
	int number;
	while(1)
	{
		get_xy(&ix,&iy);
		printf("%d %d\n",ix,iy);
		//账号
		if(ix>103&&ix<380&&iy>222&&iy<274)
		{
			printf("please input your id:\n");
			
			jianpan(input_id,105,236);
		}
		//密码
		else if(ix>103&&ix<380&&iy>311&&iy<377)
		{
			printf("please input your pasward:\n");
			jianpan(input_pasward,105,313);
		}
		
		//登录
		else if(ix>133&&ix<233&&iy>323&&iy<445)
		{
			
			ReadFileforCustomer("./user.txt");
			//普通用户
			CustomerNode* p=0;
			printf("%s\n",input_id);
			printf("%s\n",input_pasward);
			p = isExist(input_id);
			printf("hahahah111\n");
			//管理员界面
			int ret1 = strcmp(input_id,banziname);
			int ret2 = strcmp(input_pasward,banzipassword);
			printf("hahahah111\n");
			if(p)
			{
				//user();
				printf("进入普通用户界面\n");
				memu();
			}
			else if(ret1==0&&ret2==0)
			{
				printf("login successfully\n");
				root();
				return;
			}
			
			printf("hahahah\n");
		 }
	
	}
	UnInit_Font(); 
	

}
void login()
{
	
	lcd_init(&lcd);
	Init_Font(); 	//打开字库	
	char *String = "welcome";
	touch_open();//???????
	
	display_bmp("./img/start.bmp", lcd.map_ptr, 0, 0);
	
	//显示文字
	Display_characterX(50,100,String,0xfffffff,3);
	int tx = 0,ty = 0;
	while(1)
	{
		get_xy(&tx,&ty);//???????????????
		if(tx<800&&ty<480)
		{
			//???????
			sigin();
			return;
		}
	}
	lcd_uninit(&lcd);
	UnInit_Font(); //关闭字库
	touch_close();//????????
}
