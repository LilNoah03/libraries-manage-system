#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <graphics.h>
struct vip//�����Ա��Ϣ����ͼ����Ϣ�����ݽṹ
{
	int vipnum;
	char vipinf[60];
	int vipscore;
	struct vip* next;
};
struct vip *Inputvipfp(struct vip inf[15])//����Ա�ļ���Ϣд������
{
	FILE* fp;
	if ((fp = fopen(".\\vip.txt", "r")) == NULL)
	{
		printf("�ļ���������رոó�������һ�����ԡ�\n");
	}
	for (int j = 0; !feof(fp);j++)
	{
		fscanf(fp, "%3d %10s %10d", &inf[j].vipnum, &inf[j].vipinf, &inf[j].vipscore);
	}
		fclose(fp);
		return inf;
}
struct vip *Inputvipfp1(struct vip inf[15])//���鼮�ļ���Ϣд������
{
	FILE* fp;
	if ((fp = fopen(".\\books.txt", "r")) == NULL)
	{
		printf("�ļ���������رոó�������һ�����ԡ�\n");
	}
	for (int i = 0; !feof(fp); i++)
	{
		fscanf(fp, "%5d%20s%10d", &inf[i].vipnum, &inf[i].vipinf, &inf[i].vipscore);
	}
		fclose(fp);
		return inf;
}
void Outputvipfp(struct vip inf[15])//����Ա������Ϣд���ļ�
{
	FILE* fp;
	if ((fp = fopen(".\\vip.txt", "w")) == NULL)
	{
		printf("�ļ���������رոó�������һ�����ԡ�\n");
	}
	for (int i = 0; inf[i].vipnum != -1; i++)
	{
		fprintf(fp, "%3d %10s %10d\n", inf[i].vipnum, inf[i].vipinf, inf[i].vipscore);
	}
	fprintf(fp, "%3d %10s %10d\n", -1, "-1", -1);
	fclose(fp);
}
void Outputvipfp1(struct vip inf[15])//���鼮������Ϣд���ļ�
{
	FILE* fp;
		if ((fp = fopen(".\\books.txt", "w")) == NULL)
		{
			printf("�ļ���������رոó�������һ�����ԡ�\n");
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
void DeleteMemory(struct vip* head)//����ڴ溯�� 
{
	struct vip* p = head, * pr = NULL;
	while (p != NULL)
	{
		pr = p;
		p = p->next;
		free(pr);
	}
}
void PrintLink(struct vip* head)//���ͼ����Ϣ���߻�Ա��Ϣ�ĺ���(ѭ��ʹ�ã�
{
	struct vip* p = head;
	for (int i = 0; p!=NULL; i++)
	{	
		printf("%d\t %s\t %d\t\n", p->vipnum, p->vipinf, p->vipscore);
		p = p->next;
	}
}
struct vip *built(struct vip* head, struct vip inf[15])//������Ա�Ļ�����Ϣ����
{
	int i = 0;
	struct vip* p = NULL;
	struct vip* pr = head;
	for (i = 0; i < Find(inf); i++) {
		p = (struct vip*)malloc(sizeof(struct vip));
		if (p == NULL)
		{
			printf("������BUG��������һ��");

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
char VIP(struct vip inf[15])//��Ա�������ܺ���
{
	system("cls");
	struct vip* head = NULL;
	head = built(head, inf);
	char choice2;
	printf("ͼ�����ϵͳ>��Ա����\n");
	printf("******************************\n");
	printf("\n");
	printf("*       1.��ʾ���л�Ա       *\n");
	printf("\n");
	printf("*       2.��ӻ�Ա��Ϣ       *\n");
	printf("\n");
	printf("*       3.�޸Ļ�Ա��Ϣ       *\n");
	printf("\n");
	printf("*       4.ɾ����Ա��Ϣ       *\n");
	printf("\n");
	printf("*       5.�������˵�         *\n");
	printf("\n");
	printf("******************************\n");
	printf("����������ѡ��1-5��\n");
	choice2 = _getch();
	if (choice2 == '1')//��ʾ��Ա����
	{
		system("cls");//����
		printf("��Ա��   ��Ա��   ����\t\n");
		//printf("%d\n", Inputfp(information));
		
		PrintLink(head);
		DeleteMemory(head);
		//Outputvipfp(inf);
		printf("1.������һ��\n");
		printf("2.����ʹ��\n");
		printf("����������ѡ��1-2��\n");
	
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
	if (choice2 == '2')//��ӻ�Ա��Ϣ����
	{
		system("cls");
		printf("ͼ�����ϵͳ>��Ա����>��ӻ�Ա\n");
		printf("����������ӵĻ�Ա��Ϣ:\n");
		int NUM, SCORE; char NAME[30];
		printf("��Ա��:\n");
		scanf("%d", &NUM);
		printf("��Ա��\n");
		scanf("%s", NAME);
		printf("����:");
		scanf("%d",&SCORE);
		DeleteMemory(head);
		int k = Find(inf);
		inf[k+ 1] = inf[k];
		inf[k].vipnum = NUM;
		strcpy(inf[k].vipinf, NAME);
		inf[k].vipscore = SCORE;
		Outputvipfp(inf);
		printf("1.������һ��\n");
		printf("2.����ʹ��\n");
		printf("����������ѡ��1-2��\n");
		
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
	if (choice2 == '3')//�޸Ļ�Ա��Ϣ����
	{
		system("cls");
		printf("ͼ�����ϵͳ>��Ա����>�޸Ļ�Ա\n");
		printf("���������޸ĵĻ�Ա��Ϣ:\n");
		int NUM, SCORE; char NAME[30];
		printf("��Ա��:\n");
		scanf("%d", &NUM);
		printf("��Ա��\n");
		scanf("%s", NAME);
		printf("����:");
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
			printf("��Ǹû���ҵ���Ҫ�޸ĵ���Ϣ"); return '1';
		}
		inf[po].vipnum = NUM;
		strcpy(inf[po].vipinf, NAME);
		inf[po].vipscore = SCORE;
		Outputvipfp(inf);
		printf("1.������һ��\n");
		printf("2.����ʹ��\n");
		printf("����������ѡ��1-2��\n");
		
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
	if (choice2 == '4')//ɾ������
	{
		system("cls");
		printf("ͼ�����ϵͳ>��Ա����>ɾ����Ա\n");
		int OK;
		printf("��������ɾ���Ļ�Ա��Ϣ:\n");
		printf("��Ա��:\n");
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
			printf("��Ǹû���ҵ���Ҫ�޸ĵ���Ϣ"); return '1';
		}
		for(int y=po;y<=Find(inf);y++)
		{
			inf[y] = inf[y + 1];
		}
		head = built(head, inf);
		Outputvipfp(inf);
		//printf("%d",pst);
		printf("1.������һ��\n");
		printf("2.����ʹ��\n");
		printf("����������ѡ��1-2��\n");
	
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
	if (choice2 == '5')//�������˵�
	{
		return '0';
	}
}
char book(struct vip inf[15])//�鼮�������ܺ���
{
	system("cls");
	struct vip* head = NULL;
	head = built(head,inf);
	char choice2;
	printf("ͼ�����ϵͳ>�鼮����\n");
	printf("******************************\n");
	printf("\n");
	printf("*       1.��ʾ�����鼮       *\n");
	printf("\n");
	printf("*       2.����鼮��Ϣ       *\n");
	printf("\n");
	printf("*       3.�޸��鼮��Ϣ       *\n");
	printf("\n");
	printf("*       4.ɾ���鼮��Ϣ       *\n");
	printf("\n");
	printf("*       5.�������˵�         *\n");
	printf("\n");
	printf("******************************\n");
	printf("����������ѡ��1-5��\n");
	choice2 = _getch();
	if (choice2 == '1')//��ʾ�鼮����
	{
		system("cls");//����
		printf("�鼮��     �鼮��     ����\t\n");
		//printf("%d\n", Inputfp(information));
		PrintLink(head);
		DeleteMemory(head);
		printf("1.������һ��\n");
		printf("2.����ʹ��\n");
		printf("����������ѡ��1-2��\n");
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
	if (choice2 == '2')//����鼮��Ϣ����
	{
		system("cls");
		printf("ͼ�����ϵͳ>�鼮����>����鼮\n");
		int NUM, SCORE; char NAME[30];
		printf("�鼮��:\n");
		scanf("%d", &NUM);
		printf("�鼮��:\n");
		scanf("%s", NAME);
		printf("����:");
		scanf("%d", &SCORE);
		int k = Find(inf);
		inf[k + 1] = inf[k];
		inf[k].vipnum = NUM;
		strcpy(inf[k].vipinf, NAME);
		inf[k].vipscore = SCORE;
		DeleteMemory(head);
		Outputvipfp1(inf);
		printf("1.������һ��\n");
		printf("2.����ʹ��\n");
		printf("����������ѡ��1-2��\n");
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
	if (choice2 == '3')//�޸��鼮��Ϣ����
	{
		system("cls");
		printf("ͼ�����ϵͳ>�鼮����>�޸��鼮\n");
		int NUM, SCORE; char NAME[30];
		printf("�鼮��:\n");
		scanf("%d", &NUM);
		printf("�鼮��\n");
		scanf("%s", NAME);
		printf("����:");
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
			printf("��Ǹû���ҵ���Ҫ�޸ĵ���Ϣ"); return '1';
		}
		inf[po].vipnum = NUM;
		strcpy(inf[po].vipinf, NAME);
		inf[po].vipscore = SCORE;
		Outputvipfp1(inf);
		printf("1.������һ��\n");
		printf("2.����ʹ��\n");
		printf("����������ѡ��1-2��\n");
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
	if (choice2 == '4')//ɾ������
	{
		system("cls");
		printf("ͼ�����ϵͳ>�鼮����>ɾ���鼮\n");
		int OK;
		//int pst = -1;
		printf("��������ɾ�����鼮��Ϣ:\n");
		printf("�鼮��:\n");
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
			printf("��Ǹû���ҵ���Ҫ�޸ĵ���Ϣ"); return '1';
		}
		for (int y = po; y < Find(inf); y++)
		{
			inf[y] = inf[y + 1];
		}
		head = built(head, inf);
		Outputvipfp1(inf);
		printf("1.������һ��\n");
		printf("2.����ʹ��\n");
		printf("����������ѡ��1-2��\n");
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
	if (choice2 == '5')//�������˵�
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
	printf("��������Ҫʹ�õĻ�Ա���룺\n");
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
		printf("��Ǹû���ҵ���Ҫʹ�õĻ�Ա��Ϣ");
		printf("�Ƿ�������� Y or N?\n ");
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
	printf("��������Ҫ������鼮���:\n");
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
		printf("��Ǹû���ҵ���Ҫ������鼮");
		printf("�Ƿ�������� Y or N?\n ");
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
	printf("��������Ҫ������鼮������\n");
	scanf("%d", &sl);
	total = sl * books[pst1].vipscore;
	printf("��Ҫ������鼮Ϊ:%d ����Ϊ%s,����Ϊ%d\n",bnh,books[pst1].vipinf,sl);
	printf("���۳�����%d\n", total);
	printf("�Ƿ������ Y or N\n");
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
			printf("�ܱ�Ǹ���Ļ��ֲ����Թ��򣬻�ȱ%dԪ\n", total- inf[pst].vipscore);
			printf("�Ƿ�ϣ��ʹ�ñ��֧����ʽ���Y or N?\n");
			char sh;
			sh = _getch();
			if (sh == 'Y' || sh == 'y')
			{
				inf[pst].vipscore = 0;
				Outputvipfp(inf);
				printf("��ѡ����Ҫʹ�õ�֧����ʽ��1-3����\n");
				printf("1.֧����\n2.΢��֧��\n3.�ֽ�֧��\n");
				char SHE;
				SHE = _getch();
				if(SHE=='1')
				{
					IMAGE img;
					if (_waccess(_T(".\\alipay.jpg"), 0) < 0)
					{
						printf("�ļ������ڣ�ԭ�������:1.��Դ�����ڣ�2.·������3.�޷�ʶ���ļ�(��)��\n");
							// ��Դ������ʱ���˳����򣬲���������
					}
					initgraph(580, 850);
					loadimage(&img, _T(".\\alipay.jpg"), 580, 850);
					putimage(0, 0, &img);
					getchar(); // ��������ر�
					closegraph(); // �ر�ͼ�ν���
					
				}
				if(SHE=='2')
				{
					IMAGE img;
					if (_waccess(_T(".\\wechat.jpg"), 0) < 0)
					{
						printf("�ļ������ڣ�ԭ�������:1.��Դ�����ڣ�2.·������3.�޷�ʶ���ļ�(��)��\n");
							 // ��Դ������ʱ���˳����򣬲���������
					}
					initgraph(600, 845);
					loadimage(&img, _T(".\\wechat.jpg"), 600,845);
					putimage(0, 0, &img);
					getchar(); // ��������ر�
					closegraph(); // �ر�ͼ�ν���
				}
				if (SHE == '3') printf("��֧���ֽ�%dԪ", total - inf[pst].vipscore);
				printf("�Ƿ�������� Y or N?\n ");
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
				printf("�Ƿ�������� Y or N?\n ");
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
int librabyq(struct vip inf[15],struct vip books[15])//ͼ�����ϵͳ�ܺ���
{
	char choice6='a';
	while (choice6) {
		system("cls");
		printf("******************************\n");
		printf("\n");
		printf("*       ͼ�����۹���ϵͳ     *\n");
		printf("\n");
		printf("*        1.��Ա����          *\n");
		printf("\n");
		printf("*        2.�鼮����          *\n");
		printf("\n");
		printf("*        3.�������          *\n");
		printf("\n");
		printf("*        4.ע��              *\n");
		printf("\n");
		printf("******************************\n");
		printf("����������ѡ��1-4��\n");
		
		choice6 = _getch();
		while (choice6 == '1')//��Ա����ϵͳ
		{
			choice6 = VIP(inf);
			if (choice6 == '9')
				return 0;
		}
	
		while (choice6 == '2')//�鼮����ϵͳ
		{
			choice6 = book(books);
			if (choice6 == '9')
				return 0;
		}
		while (choice6 == '3')//�������ϵͳ
		{
			choice6 = Buy(inf, books);
			
		}
		if (choice6 == '4')//���ص�½����
		{
			choice6 = 0;
			return 0;
		}
	}
}

