#include "TSet.h"
#include <stdio.h>
#include <cstdlib>
#include < string.h > 
#include <iostream>
#define MAX_SIZE_ARRAY 5 //100
#define MAX_SIZE_STRING 1000
#define MAX_SIZE_SET 1000

TSet Viol (int n)
{
	int i,j,p;
	TSet A(n);
	for (i=2; i<n; i++)
		A.InsElem(i);
	for (p=2; p < n>>1; p=A.first(p+1))
		for (i=p+1; i<n; i++)
			if (i%p==0) A.DelElem(i);
	return A;
}

int input (int max)
{
	int abc;
	do
		scanf("%d",&abc);
	while((abc<0)||(abc>=max));
	return abc;
}

int main ()
{
setlocale(LC_ALL, "Russian");	//����
	char set[MAX_SIZE_STRING];
	int menu,c,a,b,universe=100; //,c,a,b
	TSet *Array;
	Array = new TSet [MAX_SIZE_ARRAY];
	
	
	/*TSet B(universe);
	*set='{0}';
	B.ENTER(set);
	Array[1]=B;
	Array[2]=B;
	Array[3]=B;*/
	//Array = new TSet [3];
///-----------------------------------------
	do{				
		//printf("\n���������� ������ ��� ��������� �������� ������ ���� ������� ������ �������� ����������, ������� ������������ ���������� �� �������� � ����������� ������ ����������\n");
		//printf("\n� ������ ��-�� ������������ ��������� �������� �� ������� ��-��\n"); // 0: ������� ����. ������� � ����������\n 1: ����\n
		printf(" 1: �����\n 2: ����\n 3: �������� ������� � ��-��\n 4: ������� ������� �� ��-��\n \t5:U (�����������)\n \t6: /\ (�����������)\n \t7: ~ (���������)\n \t8: == (���������)\n \t9: ������������\n 0:  ����������\n");
	scanf("%d", &menu); 
///-----------------------------------------
	/*if (menu==0)
	{
		printf("������� ���������\n");
		universe = input (MAX_SIZE_SET);
	}*/
///-----------------------------------------
	
	if (menu==2)
	{
		printf("������� ��-�� ��� �����\n"); 
		c = input (MAX_SIZE_ARRAY);
		printf("������� ���� \n ��������: {x1,x2,x3,...}\n");
		scanf("%s",set);
		TSet B(universe);
		B.ENTER(set);
		Array[c]=B;
	};
//==========================================
	if (menu==1)
	{
		//printf("1 - ����� ��-��\n2 - ����� �������� ����\n");
		//int S = input (MAX_SIZE_ARRAY);
		printf("����� ��-�� �������?\n");
		c = input (MAX_SIZE_ARRAY);
		printf("\n");
		{
			TBitField OUT=Array[c];
			int a=OUT.GetLength();
			printf("������� ����:\n");
			OUT.output();
			printf("\n");
			//printf("\t Length = %d\n",a);
			if ( a==1 ) printf("��-�� ������\n");
			else {
				int i=0;
				while ((OUT.GetBit(i) ==0) && (i<a))
				{ 
				 i+=1;
				}
				if ( i < (a-1) ){
			printf("���������:\n");
				Array[c].output();
				}
				else  printf("��-�� ������\n");
				}
			}
		/*if (S==1) {
			TBitField OUT=Array[c];
			int a=OUT.GetLength();
			//printf("%d\n",a);
			if (a==1) printf("��-�� ������\n");
			else Array[c].output();
		}
		else if (S==2)
		{
			TBitField OUT=Array[c];
			OUT.output();
		}
	//TBitField OUT=Array[c];
		//	OUT.output();
			//if (OUT.output()==' ')
				//printf("��-�� ������ \n");
				*/
		getchar();
		getchar();
	};
///-----------------------------------------
	if (menu==3)
	{
		printf("� ����� ��-��� ��������?\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� �������\n");
		b = input (universe);
		Array[a]+b;
	};
///-----------------------------------------
		if (menu==4)
	{
		printf("� ����� ��-��� ��������?\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� �������\n");
		b = input (universe);
		Array[a]-b;
	};
//==========================================
		if (menu==5)
	{
		/*printf("������� ������ ��-��\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� ������ ��-��\n");
		b = input (MAX_SIZE_ARRAY);
		printf("Enter nuber of result slot\n");
		c = input (MAX_SIZE_ARRAY);*/
		Array[3]=Array[1]+Array[2];
	};
//==========================================
		if (menu==6)
	{
		/*printf("������� ������ ��-��\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� ������ ��-��\n");
		b = input (MAX_SIZE_ARRAY);
		printf("������� �������������� ��-��\n");
		c = input (MAX_SIZE_ARRAY);*/
		Array[3]=Array[1]*Array[2];
	};
//==========================================
			if (menu==7)
	{
		printf("������� ��-��\n");
		a = input (MAX_SIZE_ARRAY);
		//printf("Enter nuber of result slot\n");
		//c = input (MAX_SIZE_ARRAY);
		Array[3]=~Array[a];
	};
//==========================================
		if (menu==8)
	{
		printf("������� ������ ��-��\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� ������ ��-��\n");
		b = input (MAX_SIZE_ARRAY);
		if(Array[a]==Array[b]) printf("��-�� �����");
		else printf("��-�� �����������");
		getchar();
		getchar();
	};
//==========================================
		if (menu==9)
	{
		printf("������� ��-��, �������� ����� ������������� ��������\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� ��-��, �� �������� ����� ������� ��������\n");
		b = input (MAX_SIZE_ARRAY);
		Array[a]=Array[b];
	};
 //==========================================
	/*	if (menu==9)
	{
		printf("Enter N\n");
		do
			scanf("%d",&a);
		while((a<0)||(a>=MAX_SIZE_SET));
		Viol(a).output();
		getchar();
		getchar();
	};*/
//==========================================
	system("cls"); //����� ������ �������� ��������� ������ �������
	}while(menu!=0);
	return 0;
}