#include "root.h"
#include "bmp.h"
#include "touch.h"
#include "font.h"
#include "login.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct lcd lcd;

const char *filename_user = "./user.txt";//?????????
const char *filename_power = "./power.txt";//??????
int dirent;
int alter;


//?§Ø??????????
CustomerNode* isExist(char *username)
{
	CustomerNode* p = g_customers->next;
	while (p)
	{
		if (strcmp(p->customer.name, username) == 0)
			return p;
		else
			p = p->next;
	}
	return 0;
}

//??????§Ø????????
void ReadFileforCustomer(const char* filename)
{
	FILE* fp = 0;
	CustomerNode* p, * t;
	//?????????
	g_customers = (CustomerNode*)malloc(sizeof(CustomerNode));
	g_customers->next = NULL;
	p = g_customers;
 
	//?????
	if ((fp = fopen(filename, "r")) == 0)
	{
		printf("%s ??????????\n", filename);
		return;
	}
	//??????????
	while (!feof(fp))
	{
		t = (CustomerNode*)malloc(sizeof(CustomerNode));
		t->next = NULL;
		//????????????????????????
		fscanf(fp, "%s %s %s", t->customer.name, t->customer.pwd,t->customer.tou);
        //printf("%s",t->customer.name);
		if (strlen(t->customer.name) > 0)
		{
			p->next = t;
			p = t;
		}
		else
			free(t); //????????????t???????t???????§¹?????????????????????????
	}
    
	fclose(fp);
	printf("%s ????????????\n", filename);
	
}
//????????§Õ?????
void WreiteFileforCustomer(const char* filename)
{
	FILE* fp;
	CustomerNode* p = g_customers->next;
	fp = fopen(filename, "w");
	if (fp == 0)
	{
		printf("%s:????????\n", filename);
        perror( " ");
		return;
	}
	
	while (p!=NULL)
	{
		printf("%s %s\n",p->customer.name,p->customer.pwd);
		fprintf(fp, "%s %s %s \n", p->customer.name,p->customer.pwd,p->customer.tou);
		p = p->next;
	}
	fclose(fp);
}

// //?????????????
// void show_user()
// {
    
//     CustomerNode *p = g_customers->next;
//     int tou_y=50;
//     int name_y=70;
//     while(p->next!=NULL)
//     {
       
//         printf("%s %s %s\n", p->customer.name,p->customer.pwd,p->customer.tou);
//         //??????
//         char data[15];
// 		snprintf(data, 15, "./img/%s.bmp", p->customer.tou);
//         display_bmp(data, lcd.map_ptr, 50, tou_y);
//         tou_y+=100;
//         //??????
//         char *String=p->customer.name;
//         Display_characterX(210,name_y,String,0x00000000,2);
//         name_y+=100;


//         p=p->next;
//     }
//     int x=0,y=0;
//     while(1)
//     {
//         get_xy(&x,&y);
//         if(x>633&&x<781&&y>371&&y<450)//??????
//         {
//             root();
//         }
//     }

// }
void show_user()
{
    
    CustomerNode *p = g_customers->next;
    int tou_y=50;
    int name_y=70;
    while(p->next!=NULL)
    {
       
        printf("%s %s %s\n", p->customer.name,p->customer.pwd,p->customer.tou);
        //??????
        char data[15];
		snprintf(data, 15, "./img/%s.bmp", p->customer.tou);
        display_bmp(data, lcd.map_ptr, 50, tou_y);
        tou_y+=100;
        //??????
        char *String=p->customer.name;
        Display_characterX(210,name_y,String,0x00000000,2);
        name_y+=100;


        p=p->next;
    }
    int x=0,y=0;
    while(1)
    {
        get_xy(&x,&y);
        if(x>633&&x<781&&y>371&&y<450)//??????
        {
            root();
        }
    }

}

//???????
void add_user()
{
    Init_Font();
    display_bmp("./img/zhuce.bmp", lcd.map_ptr, 0, 0);

    CustomerNode *t,*x;
    t = (CustomerNode*)malloc(sizeof(CustomerNode));
    t->next = NULL;
    int a;
    srand((unsigned)time(NULL));
    a = rand() % 5;

    char ch;
    int ix = 0,iy = 0;
	
	char input_id1[20];
	char input_pasward1[20];

	while(1)
	{
		get_xy(&ix,&iy);
		printf("%d %d\n",ix,iy);
		//??????
		if(ix>103&&ix<380&&iy>222&&iy<274)
		{
			printf("please input your id:\n");
			
			jianpan(input_id1,105,236);
		}
		//???????
		else if(ix>103&&ix<380&&iy>311&&iy<377)
		{
			
			printf("please input your pasward:\n");
			jianpan(input_pasward1,105,313);
		}
		else if(ix>547&&ix<800&&iy>0&&iy<80)
        {
            root();
        }
		//???
		else if(ix>133&&ix<233&&iy>323&&iy<445)
		{
           
            strcpy(t->customer.name,input_id1);
            strcpy(t->customer.pwd,input_pasward1);
            char tou_name[15];
		    snprintf(tou_name, 15, "tou%d",a);
            strcpy(t->customer.tou,tou_name);

            t->next = g_customers->next;
			g_customers->next = t;
			//???????
			WreiteFileforCustomer(filename_user);
            printf("??????\n");
			add_user();
        } 
	}
	
	UnInit_Font(); 
}
    
//???
void del_user()
{
    display_bmp("./img/del_user.bmp", lcd.map_ptr, 0, 0);
    CustomerNode *p = g_customers->next;
    int tou_y=50;
    int name_y=70;
    while(p->next!=NULL)
    {
       
        printf("%s %s %s\n", p->customer.name,p->customer.pwd,p->customer.tou);
        //??????
        char data[15];
		snprintf(data, 15, "./img/%s.bmp", p->customer.tou);
        display_bmp(data, lcd.map_ptr, 50, tou_y);
        tou_y+=100;
        //??????
        char *String=p->customer.name;
        Display_characterX(210,name_y,String,0x00000000,2);
        name_y+=100;
        p=p->next;
    }
    while(1)
    {
        int delx=0,dely=0;
        get_xy(&delx,&dely);
        if(delx>0&&delx<400&&dely>50&&dely<110)
        {
			printf("%s %s %s",p->customer.name,p->customer.pwd,p->customer.tou);
            printf("1\n");
        }
        else if(delx>0&&delx<400&&dely>150&&dely<210)
        {
            printf("2\n");
        }
        else if(delx>0&&delx<400&&dely>250&&dely<310)
        {
            printf("3\n");
        }
        else if(delx>0&&delx<400&&dely>350&&dely<410)
        {
            printf("4\n");
        }
		else if(delx>635&&delx<787&&dely>77&&dely<166)//???
        {
            printf("5\n");
        }
		else if(delx>635&&delx<777&&dely>367&&dely<454)//????
        {
            root();
        }
		
    }

}

//??????§Ø????????
void readpower(const char* filename)
{
	
    FILE *fp1 = fopen(filename,"a");
	
    if(fp1 == NULL)
    {
        perror("fopen failed");
    }
	printf("111\n");
    fscanf(fp1,"%d %d",&dirent,&alter);
    fclose(fp1);
}
void writerpower(const char* filename)
{
	FILE* fp1 = fopen(filename, "a+");
	if (fp1 == 0)
	{
		printf("%s:????????\n", filename);
        perror( " ");
		
	}
	fprintf(fp1, "%d %d\n", dirent,alter);
	fclose(fp1);
}
char* itoa(int num,char* str,int radix)
{
    char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";//??????
    unsigned unum;//???????????????????,??????????????????
    int i=0,j,k;//i??????????????????¦Ë????????i???????????????????????????????????????????????k????????????????¦Ë??;j?????????????????????
 
    //???????????????????
    if(radix==10&&num<0)//??????????????????????
    {
        unum=(unsigned)-num;//??num??????????unum
        str[i++]='-';//?????????????????'-'?????????????1
    }
    else unum=(unsigned)num;//????num????????????unum
 
    //???????????????????????
    do
    {
        str[i++]=index[unum%(unsigned)radix];//?unum??????¦Ë?????????str???¦Ë??????????1
        unum/=radix;//unum???????¦Ë
 
    }while(unum);//???unum?0??????
 
    str[i]='\0';//??????????????'\0'?????c???????????'\0'??????
 
    //????????????
    if(str[0]=='-') k=1;//?????????????????????????????žD?????
    else k=0;//???????????????????
 
    char temp;//??????????????????????
    for(j=k;j<=(i-1)/2;j++)//?¦Â??????????i?????????????????????????????????1
    {
        temp=str[j];//???????????????
        str[j]=str[i-1+k-j];//¦Â??????????
        str[i-1+k-j]=temp;//????????????(???????????????)????¦Â??
    }
 
    return str;//???????????????
 
}
void power()
{
	
	readpower(filename_power);
    display_bmp("./img/shezhi.bmp", lcd.map_ptr, 0, 0);
    
	char one[256];
	char two[256];
	itoa(dirent,one,10);
	itoa(dirent,two,10);
	Display_characterX(355,125,one,0x00000000,3);
	Display_characterX(355,280,two,0x00000000,3);
	while(1)
	{
		int powerx,powery;
		printf("%d %d\n", dirent,alter);
		get_xy(&powerx,&powery);
		if(powerx>234&&powerx<319&&powery>115&&powery<182)//?????
		{
			dirent--;
			itoa(dirent,one,10);
			Clean_Area(344,128,80,40,0xffffffff);
			Display_characterX(355,125,one,0x00000000,3);
		}
		else if(powerx>453&&powerx<517&&powery>109&&powery<177)//?????
		{
			dirent++;
			itoa(dirent,one,10);
			Clean_Area(344,128,80,40,0xffffffff);
			Display_characterX(355,125,one,0x00000000,3);
		}
		else if(powerx>234&&powerx<324&&powery>271&&powery<339)//??????
		{
			alter--;
			itoa(alter,two,10);
			Clean_Area(344,275,80,40,0xffffffff);
			Display_characterX(355,280,two,0x00000000,3);
		}
		else if(powerx>461&&powerx<579&&powery>270&&powery<335)//??????
		{
			alter++;
			itoa(alter,two,10);
			Clean_Area(344,275,80,40,0xffffffff);
			Display_characterX(355,280,two,0x00000000,3);
		}
		else if(powerx>138&&powerx<270&&powery>382&&powery<443)//???
		{
			writerpower(filename_power);
		}
		else if(powerx>448&&powerx<600&&powery>381&&powery<435)//????
		{
			root();
			
		}
	}
	
    

}
void root()//?????????????
{
    
    display_bmp("./img/root.bmp", lcd.map_ptr, 0, 0);
    int x=0,y=0;
    ReadFileforCustomer(filename_user);
    
	
    while(1)
    {
        get_xy(&x,&y);
		
        if(x>571&&x<741&&y>62&&y<147)//??????
        {
            display_bmp("./img/show_user.bmp", lcd.map_ptr, 0, 0);
            show_user();
        }
        else if(x>65&&x<235&&y>62&&y<147)//???????
        {
            add_user();
            
        }
        else if(x>320&&x<448&&y>62&&y<147)//??????
        {
            del_user();
            
        }
        else if(x>65&&x<235&&y>339&&y<423)//??????
        {
            power();
            
        }
         else if(x>320&&x<448&&y>339&&y<423)//??????
        {
            
            
        }
         else if(x>571&&x<741&&y>339&&y<423)//????
        {
            
            sigin();
        }
        
    }
}