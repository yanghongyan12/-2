#ifndef _ROOT_H_
#define _ROOT_H_
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
//??????????
typedef struct _customer
{
  
	char name[20];
    char pwd[20];
    char tou[20];
}Customer;

//???????????
typedef struct _customernode
{
	Customer customer;
	struct _customernode* next;
}CustomerNode;

CustomerNode* g_customers;  //???????§Û?????


void root();
//??????§Ø????????
void ReadFileforCustomer(const char* filename);
//????????§Õ?????
void WreiteFileforCustomer(const char* filename);
//?????????????
void show_user();
//???????
void add_user();
//???
void del_user();
//??????§Ø????????
void readpower(const char* filename);
void writerpower(const char* filename);
char* itoa(int num,char* str,int radix);
void power();
CustomerNode* isExist(char* usermane);
char* itoa(int num,char* str,int radix);
#endif