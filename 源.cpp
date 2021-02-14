#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <string.h>
#include "library.h" 
#include <graphics.h>
int main()
{
	int start = 1;
	/*struct vip inf[15] = { {1,"张三",100},{2,"李四",600},
	{3,"王五",500},{4,"路六",1000},{5,"钱7",900},{6,"大枪",100},
	{7,"小李子",100},{8,"敏敏",100},{-1," ",-1} };
	struct vip books[15] = { {1,"马保国武林秘籍",100},{2,"青春修炼手册",20},{3,"龙族全集",500},
		{4,"JAVA宝典",100},{5,"C语言程序设计",200},{6,"雪中悍刀行",50},{7,"剑来",20},{8,"C++ primer",50},{-1," ",-1} };*/
	struct vip inf[15];
	Inputvipfp(inf);
	struct vip books[15];
	Inputvipfp1(books);
	while (start) {                     //密码验证系统以及整体
		system("cls");
		printf("******************************\n");
		printf("\n");
		printf("*       图书销售管理系统     *\n");
		printf("\n");
		printf("*        1.登录              *\n");
		printf("\n");
		printf("*        2.退出              *\n");
		printf("\n");
		printf("******************************\n");
		char sbs;
		sbs = _getch();
		while (sbs == '1') {
			system("cls");
			char Username[10];
			char password[10];
			char rightname[10] = "admin";
			char rightword[10] = "123456";
			printf("请输入用户名:\n");
			//getchar();
			gets_s(Username);
			printf("请输入密码:\n");
			//getchar();
			gets_s(password);
			if (!strcmp(Username, rightname) && !strcmp(password, rightword))
			{
				int choice1 = 1;
				while (choice1 == 1)
				{
					choice1 = librabyq(inf, books);
				}
				sbs = '0';
			}
			else {
				char restart;
				printf("您输入的密码有误!\n");
				printf("请问还要重输吗？\n");
				printf("Y or N?\n");
				restart = _getch();
				if (restart == 'Y' || restart == 'y')
					sbs = '1';
				else sbs='0';

			}
			if (sbs == '2') start = 0;
		}
		if (sbs == '2') start = 0;
		
	}
	return 0;
}