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
	/*struct vip inf[15] = { {1,"����",100},{2,"����",600},
	{3,"����",500},{4,"·��",1000},{5,"Ǯ7",900},{6,"��ǹ",100},
	{7,"С����",100},{8,"����",100},{-1," ",-1} };
	struct vip books[15] = { {1,"���������ؼ�",100},{2,"�ഺ�����ֲ�",20},{3,"����ȫ��",500},
		{4,"JAVA����",100},{5,"C���Գ������",200},{6,"ѩ�к�����",50},{7,"����",20},{8,"C++ primer",50},{-1," ",-1} };*/
	struct vip inf[15];
	Inputvipfp(inf);
	struct vip books[15];
	Inputvipfp1(books);
	while (start) {                     //������֤ϵͳ�Լ�����
		system("cls");
		printf("******************************\n");
		printf("\n");
		printf("*       ͼ�����۹���ϵͳ     *\n");
		printf("\n");
		printf("*        1.��¼              *\n");
		printf("\n");
		printf("*        2.�˳�              *\n");
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
			printf("�������û���:\n");
			//getchar();
			gets_s(Username);
			printf("����������:\n");
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
				printf("���������������!\n");
				printf("���ʻ�Ҫ������\n");
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