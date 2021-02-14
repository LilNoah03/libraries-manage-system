#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
struct vip//储存会员信息或者图书信息的数据结构
{
	int vipnum;
	char vipinf[60];
	int vipscore;
	struct vip* next;
};
struct vip *Inputvipfp(struct vip inf[15])//将会员文件信息写入数组
{
	FILE* fp;
	if ((fp = fopen(".\\vip.txt", "r")) == NULL)
	{
		printf("文件打开有误，请关闭该程序重启一下试试。\n");
	}
	for (int j = 0; !feof(fp);j++)
	{
		fscanf(fp, "%3d %10s %10d", &inf[j].vipnum, &inf[j].vipinf, &inf[j].vipscore);
	}
		fclose(fp);
		return inf;
}
struct vip *Inputvipfp1(struct vip inf[15])//将书籍文件信息写入数组
{
	FILE* fp;
	if ((fp = fopen(".\\books.txt", "r")) == NULL)
	{
		printf("文件打开有误，请关闭该程序重启一下试试。\n");
	}
	for (int i = 0; !feof(fp); i++)
	{
		fscanf(fp, "%5d%20s%10d", &inf[i].vipnum, &inf[i].vipinf, &inf[i].vipscore);
	}
		fclose(fp);
		return inf;
}
void Outputvipfp(struct vip inf[15])//将会员数组信息写入文件
{
	FILE* fp;
	if ((fp = fopen(".\\vip.txt", "w")) == NULL)
	{
		printf("文件打开有误，请关闭该程序重启一下试试。\n");
	}
	for (int i = 0; inf[i].vipnum != -1; i++)
	{
		fprintf(fp, "%3d %10s %10d\n", inf[i].vipnum, inf[i].vipinf, inf[i].vipscore);
	}
	fprintf(fp, "%3d %10s %10d\n", -1, "-1", -1);
	fclose(fp);
}
void Outputvipfp1(struct vip inf[15])//将书籍数组信息写入文件
{
	FILE* fp;
		if ((fp = fopen(".\\books.txt", "w")) == NULL)
		{
			printf("文件打开有误，请关闭该程序重启一下试试。\n");
		}

	for (int i = 0; inf[i].vipnum != -1; i++)
	{
		fprintf(fp, "%5d%20s%10d\n", inf[i].vipnum, inf[i].vipinf, inf[i].vipscore);
	}
	fprintf(fp, "%5d%20s%10d\n", -1, "-1", -1);
	fclose(fp);
}
int Find(struct vip inf[15])
{
	int j;
	for (int i = 0; i < 15; i++)
	{
		if (inf[i].vipnum == -1)
		{
			j = i;
		}
	}
	return j;
}
void DeleteMemory(struct vip* head)//清除内存函数 
{
	struct vip* p = head, * pr = NULL;
	while (p != NULL)
	{
		pr = p;
		p = p->next;
		free(pr);
	}
}
void PrintLink(struct vip* head)//输出图书信息或者会员信息的函数(循环使用）
{
	struct vip* p = head;
	for (int i = 0; p!=NULL; i++)
	{	
		printf("%d\t %s\t %d\t\n", p->vipnum, p->vipinf, p->vipscore);
		p = p->next;
	}
}
struct vip *built(struct vip* head, struct vip inf[15])//构建会员的基本信息函数
{
	int i = 0;
	struct vip* p = NULL;
	struct vip* pr = head;
	for (i = 0; i < Find(inf); i++) {
		p = (struct vip*)malloc(sizeof(struct vip));
		if (p == NULL)
		{
			printf("出现了BUG，请再试一次");

		}
		if (head == NULL)
		{
			head = p;
			pr = head;
		}
		else
		{
			while (pr->next != NULL)
			{
				pr = pr->next;

			}
			pr->next = p;
		}
		p->vipnum = inf[i].vipnum;
		strcpy(p->vipinf, inf[i].vipinf);
		p->vipscore = inf[i].vipscore;
		p->next = NULL;
	}
	return head;
}
char VIP(struct vip inf[15])//会员管理功能总函数
{
	system("cls");
	struct vip* head = NULL;
	head = built(head, inf);
	char choice2;
	printf("图书管理系统>会员管理\n");
	printf("******************************\n");
	printf("\n");
	printf("*       1.显示所有会员       *\n");
	printf("\n");
	printf("*       2.添加会员信息       *\n");
	printf("\n");
	printf("*       3.修改会员信息       *\n");
	printf("\n");
	printf("*       4.删除会员信息       *\n");
	printf("\n");
	printf("*       5.返回主菜单         *\n");
	printf("\n");
	printf("******************************\n");
	printf("请输入您的选择（1-5）\n");
	choice2 = _getch();
	if (choice2 == '1')//显示会员功能
	{
		system("cls");//清屏
		printf("会员号   会员名   积分\t\n");
		//printf("%d\n", Inputfp(information));
		
		PrintLink(head);
		DeleteMemory(head);
		//Outputvipfp(inf);
		printf("1.返回上一级\n");
		printf("2.结束使用\n");
		printf("请输入您的选择（1-2）\n");
	
		char a2;
		a2 = _getch();
		if (a2 == '1')
		{
			return '1';
		}
		if (a2 == '2')
		{
			return '9';
		}
	}
	if (choice2 == '2')//添加会员信息功能
	{
		system("cls");
		printf("图书管理系统>会员管理>添加会员\n");
		printf("输入您想添加的会员信息:\n");
		int NUM, SCORE; char NAME[30];
		printf("会员号:\n");
		scanf("%d", &NUM);
		printf("会员名\n");
		scanf("%s", NAME);
		printf("积分:");
		scanf("%d",&SCORE);
		DeleteMemory(head);
		int k = Find(inf);
		inf[k+ 1] = inf[k];
		inf[k].vipnum = NUM;
		strcpy(inf[k].vipinf, NAME);
		inf[k].vipscore = SCORE;
		Outputvipfp(inf);
		printf("1.返回上一级\n");
		printf("2.结束使用\n");
		printf("请输入您的选择（1-2）\n");
		
		char abd;
		abd = _getch();
		if (abd == '1')
		{
			return '1';
		}
		if (abd == '2')
		{
			return '9';
		}
	}
	if (choice2 == '3')//修改会员信息功能
	{
		system("cls");
		printf("图书管理系统>会员管理>修改会员\n");
		printf("输入您想修改的会员信息:\n");
		int NUM, SCORE; char NAME[30];
		printf("会员号:\n");
		scanf("%d", &NUM);
		printf("会员名\n");
		scanf("%s", NAME);
		printf("积分:");
		scanf("%d", &SCORE);
		DeleteMemory(head);
		int po=-1;
		for(int q=0;q<15;q++)
		{
			if(inf[q].vipnum==NUM)
			{
				po = q;
			}
		}
		if (po == -1) {
			printf("抱歉没能找到您要修改的信息"); return '1';
		}
		inf[po].vipnum = NUM;
		strcpy(inf[po].vipinf, NAME);
		inf[po].vipscore = SCORE;
		Outputvipfp(inf);
		printf("1.返回上一级\n");
		printf("2.结束使用\n");
		printf("请输入您的选择（1-2）\n");
		
		char abc;
		abc = _getch();
		if (abc == '1')
		{
			return '1';
		}
		if (abc == '2')
		{
			return '9';
		}
	}
	if (choice2 == '4')//删除功能
	{
		system("cls");
		printf("图书管理系统>会员管理>删除会员\n");
		int OK;
		printf("输入您想删除的会员信息:\n");
		printf("会员号:\n");
		scanf("%d", &OK);
		getchar();
		int po = -1;
		for (int q = 0; q < 15; q++)
		{
			if (inf[q].vipnum == OK)
			{
				po = q;
			}
		}
		if (po == -1) {
			printf("抱歉没能找到您要修改的信息"); return '1';
		}
		for(int y=po;y<=Find(inf);y++)
		{
			inf[y] = inf[y + 1];
		}
		head = built(head, inf);
		Outputvipfp(inf);
		//printf("%d",pst);
		printf("1.返回上一级\n");
		printf("2.结束使用\n");
		printf("请输入您的选择（1-2）\n");
	
		char ab;
		ab = _getch();
		if (ab == '1')
		{
			return '1';
		}
		if (ab == '2')
		{
			return '9';
		}
	}
	if (choice2 == '5')//返回主菜单
	{
		return '0';
	}
}
char book(struct vip inf[15])//书籍管理功能总函数
{
	system("cls");
	struct vip* head = NULL;
	head = built(head,inf);
	char choice2;
	printf("图书管理系统>书籍管理\n");
	printf("******************************\n");
	printf("\n");
	printf("*       1.显示所有书籍       *\n");
	printf("\n");
	printf("*       2.添加书籍信息       *\n");
	printf("\n");
	printf("*       3.修改书籍信息       *\n");
	printf("\n");
	printf("*       4.删除书籍信息       *\n");
	printf("\n");
	printf("*       5.返回主菜单         *\n");
	printf("\n");
	printf("******************************\n");
	printf("请输入您的选择（1-5）\n");
	choice2 = _getch();
	if (choice2 == '1')//显示书籍功能
	{
		system("cls");//清屏
		printf("书籍号     书籍名     积分\t\n");
		//printf("%d\n", Inputfp(information));
		PrintLink(head);
		DeleteMemory(head);
		printf("1.返回上一级\n");
		printf("2.结束使用\n");
		printf("请输入您的选择（1-2）\n");
		char a2;
		a2 = _getch();
		if (a2 == '1')
		{
			return '2';
		}
		if (a2 == '2')
		{
			return '9';
		}
	}
	if (choice2 == '2')//添加书籍信息功能
	{
		system("cls");
		printf("图书管理系统>书籍管理>添加书籍\n");
		int NUM, SCORE; char NAME[30];
		printf("书籍号:\n");
		scanf("%d", &NUM);
		printf("书籍名:\n");
		scanf("%s", NAME);
		printf("积分:");
		scanf("%d", &SCORE);
		int k = Find(inf);
		inf[k + 1] = inf[k];
		inf[k].vipnum = NUM;
		strcpy(inf[k].vipinf, NAME);
		inf[k].vipscore = SCORE;
		DeleteMemory(head);
		Outputvipfp1(inf);
		printf("1.返回上一级\n");
		printf("2.结束使用\n");
		printf("请输入您的选择（1-2）\n");
		char abd;
		abd = _getch();
		if (abd == '1')
		{
			return '2';
		}
		if (abd == '2')
		{
			return '9';
		}
	}
	if (choice2 == '3')//修改书籍信息功能
	{
		system("cls");
		printf("图书管理系统>书籍管理>修改书籍\n");
		int NUM, SCORE; char NAME[30];
		printf("书籍号:\n");
		scanf("%d", &NUM);
		printf("书籍名\n");
		scanf("%s", NAME);
		printf("积分:");
		scanf("%d", &SCORE);
		DeleteMemory(head);
		int po = -1;
		for (int q = 0; q < 15; q++)
		{
			if (inf[q].vipnum == NUM)
			{
				po = q;
			}
		}
		if (po == -1) {
			printf("抱歉没能找到您要修改的信息"); return '1';
		}
		inf[po].vipnum = NUM;
		strcpy(inf[po].vipinf, NAME);
		inf[po].vipscore = SCORE;
		Outputvipfp1(inf);
		printf("1.返回上一级\n");
		printf("2.结束使用\n");
		printf("请输入您的选择（1-2）\n");
		char abc;
		abc = _getch();
		if (abc == '1')
		{
			return '2';
		}
		if (abc == '2')
		{
			return '9';
		}
	}
	if (choice2 == '4')//删除功能
	{
		system("cls");
		printf("图书管理系统>书籍管理>删除书籍\n");
		int OK;
		//int pst = -1;
		printf("输入您想删除的书籍信息:\n");
		printf("书籍号:\n");
		scanf("%d", &OK);

		int po = -1;
		for (int q = 0; q < 15; q++)
		{
			if (inf[q].vipnum == OK)
			{
				po = q;
			}
		}
		if (po == -1) {
			printf("抱歉没能找到您要修改的信息"); return '1';
		}
		for (int y = po; y < Find(inf); y++)
		{
			inf[y] = inf[y + 1];
		}
		head = built(head, inf);
		Outputvipfp1(inf);
		printf("1.返回上一级\n");
		printf("2.结束使用\n");
		printf("请输入您的选择（1-2）\n");
		char ab;
		ab = _getch();
		if (ab == '1')
		{
			return '2';
		}
		if (ab == '2')
		{
			return '9';
		}
	}
	if (choice2 == '5')//返回主菜单
	{
		return '0';
	}
}
char Buy(struct vip inf[15],struct vip books[15])
{
	system("cls");
	struct vip* head = NULL;
	head = built(head, books);
	struct vip* head1 = NULL;
	head1 = built(head1, inf);
	PrintLink(head);
	printf("\n");
	PrintLink(head1);
	printf("请输入您要使用的会员号码：\n");
	int vnumber;
	scanf("%d", &vnumber);
	int pst = -1;
	for (int q = 0; q < 15; q++)
	{
		if (inf[q].vipnum == vnumber)
		{
			pst = q;
		}
	}
	if (pst == -1) {
		printf("抱歉没能找到您要使用的会员信息");
		printf("是否继续购买？ Y or N?\n ");
		char ob;
		ob = _getch();
		if (ob == 'Y' || ob == 'y')
		{
			system("cls");
			Buy(inf, books);
		}
		else return '0';
	}
	int sl, bnh,total;
	printf("请输入您要购买的书籍编号:\n");
	scanf("%d", &bnh);
	int pst1 = -1;
	for (int q = 0; q < 15; q++)
	{
		if (books[q].vipnum == bnh)
		{
			pst1 = q;
		}
	}
	if (pst1 == -1) {
		printf("抱歉没能找到您要购买的书籍");
		printf("是否继续购买？ Y or N?\n ");
		char oi;
		oi = _getch();
		if (oi == 'Y' || oi == 'y')
		{
			system("cls");
			Buy(inf, books);
		}
		else return '0';
		return '1';
	}
	printf("请输入您要购买的书籍数量：\n");
	scanf("%d", &sl);
	total = sl * books[pst1].vipscore;
	printf("您要购买的书籍为:%d 名称为%s,数量为%d\n",bnh,books[pst1].vipinf,sl);
	printf("将扣除积分%d\n", total);
	printf("是否继续？ Y or N\n");
	char SB;
	SB = _getch();
	getchar();
	if (SB == 'N'||SB=='n')
	{
		return '0';
	}
	if(SB=='Y'||SB=='y')
	{	
		if (inf[pst].vipscore >= total)
		{
		inf[pst].vipscore = inf[pst].vipscore - total;
		Outputvipfp(inf);
		return '1';
		}
			
		else
		{
			printf("很抱歉您的积分不足以购买，还缺%d元\n", total- inf[pst].vipscore);
			printf("是否希望使用别的支付方式付款？Y or N?\n");
			char sh;
			sh = _getch();
			if (sh == 'Y' || sh == 'y')
			{
				inf[pst].vipscore = 0;
				Outputvipfp(inf);
				printf("请选择您要使用的支付方式（1-3）：\n");
				printf("1.支付宝\n2.微信支付\n3.现金支付\n");
				char SHE;
				SHE = _getch();
				if(SHE=='1')
				{
					IMAGE img;
					if (_waccess(_T(".\\alipay.jpg"), 0) < 0)
					{
						printf("文件不存在，原因可能是:1.资源不存在；2.路径错误；3.无法识别文件(夹)名\n");
							// 资源不存在时，退出程序，不继续往下
					}
					initgraph(580, 850);
					loadimage(&img, _T(".\\alipay.jpg"), 580, 850);
					putimage(0, 0, &img);
					getchar(); // 按任意键关闭
					closegraph(); // 关闭图形界面
					
				}
				if(SHE=='2')
				{
					IMAGE img;
					if (_waccess(_T(".\\wechat.jpg"), 0) < 0)
					{
						printf("文件不存在，原因可能是:1.资源不存在；2.路径错误；3.无法识别文件(夹)名\n");
							 // 资源不存在时，退出程序，不继续往下
					}
					initgraph(600, 845);
					loadimage(&img, _T(".\\wechat.jpg"), 600,845);
					putimage(0, 0, &img);
					getchar(); // 按任意键关闭
					closegraph(); // 关闭图形界面
				}
				if (SHE == '3') printf("请支付现金%d元", total - inf[pst].vipscore);
				printf("是否继续购买？ Y or N?\n ");
				char h;
				h = _getch();
				if (h == 'Y' || h == 'y')
				{
					system("cls");
					Buy(inf, books);
				}
				else return '0';
			}
			else {
				printf("是否继续购买？ Y or N?\n ");
				char h;
				h = _getch();
				if (h == 'Y' || h == 'y')
				{
					system("cls");
					Buy(inf, books);
				}
				else return '0';
			}
		}
	}
	
}
int librabyq(struct vip inf[15],struct vip books[15])//图书管理系统总函数
{
	char choice6='a';
	while (choice6) {
		system("cls");
		printf("******************************\n");
		printf("\n");
		printf("*       图书销售管理系统     *\n");
		printf("\n");
		printf("*        1.会员管理          *\n");
		printf("\n");
		printf("*        2.书籍管理          *\n");
		printf("\n");
		printf("*        3.购物结算          *\n");
		printf("\n");
		printf("*        4.注销              *\n");
		printf("\n");
		printf("******************************\n");
		printf("请输入您的选择（1-4）\n");
		
		choice6 = _getch();
		while (choice6 == '1')//会员管理系统
		{
			choice6 = VIP(inf);
			if (choice6 == '9')
				return 0;
		}
	
		while (choice6 == '2')//书籍管理系统
		{
			choice6 = book(books);
			if (choice6 == '9')
				return 0;
		}
		while (choice6 == '3')//购物结算系统
		{
			choice6 = Buy(inf, books);
			
		}
		if (choice6 == '4')//返回登陆界面
		{
			choice6 = 0;
			return 0;
		}
	}
}

