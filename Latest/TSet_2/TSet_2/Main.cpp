#include "TSet.h"
#include <stdio.h>
#include <cstdlib>
#include < string.h > 
#include <conio.h>
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
	int menu,c,a,b,universe=100;
	TSet *Array;
	Array = new TSet [MAX_SIZE_ARRAY];
	
	
	TSet B(universe);
	*set=2;
	B.ENTER(set);
	Array[1]=B;
	Array[2]=B;
	Array[3]=B;
	Array[4]=B;
	//Array = new TSet [3];
///-----------------------------------------
	do{				
		//printf("\n���������� ������ ��� ��������� �������� ������ ���� ������� ������ �������� ����������, ������� ������������ ���������� �� �������� � ����������� ������ ����������\n");
		printf("\n ��������� ��������  �� ������� ��-�� ������������ � ������ ��-��\n"); // 0: ������� ����. ������� � ����������\n 1: ����\n
		printf(" 1: �����\n 2: �������� ������� � ��-��\n 3: ������� ������� �� ��-��\n \t4:U (�����������)\n \t5: ^ (�����������)\n \t6: ~ (���������)\n \t7: == (���������)\n 8: ������������\n 9:���� ��-��\n 10:  ����������\n");
	scanf("%d", &menu); 
///-----------------------------------------
	/*if (menu==0)
	{
		printf("������� ���������\n");
		universe = input (MAX_SIZE_SET);
	}*/
///-----------------------------------------
	
	if (menu==9)
	{
		printf("������� ��-�� ��� ����������\n"); // �� ���� ���� set, ����� ��������� ��-�� ������������ �����������, � � ���� ������������� �������� �������� set 
		c = input (MAX_SIZE_ARRAY);
		printf("���� �������������� � �������� ������� ����� �������\n");
		scanf("%s",set);
		TSet B(universe);
		B.ENTER(set);
		Array[c]=B;
	};
///-----------------------------------------
	if (menu==1)
	{
		printf("1 - ����� ��-��\n0 - ����� �������� ����\n");
		menu = input (MAX_SIZE_ARRAY);
		printf("����� ��-�� �������?\n");
		c = input (MAX_SIZE_ARRAY);
		printf("\n");
		if (menu==1)
			Array[c].output();
		else if (menu==0)
			if (Array[c]==Array[4]) 
				{printf("\n������ ��-��\n"); } 
			else
			{
			TBitField OUT=Array[c];
			OUT.output();
			}
		getchar();
		getchar();
	};
///-----------------------------------------
	if (menu==2)
	{
		printf("� ����� ��-��� ��������?\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� �������\n");
		b = input (universe);
		Array[a]+b;
	};
///-----------------------------------------
		if (menu==3)
	{
		printf("� ����� ��-��� ��������?\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� �������\n");
		b = input (universe);
		Array[a]-b;
	};
///-----------------------------------------
		if (menu==4)
	{
		printf("������� ������ ��-��\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� ������ ��-��\n");
		b = input (MAX_SIZE_ARRAY);
		/*printf("Enter nuber of result slot\n");
		c = input (MAX_SIZE_ARRAY);*/
		Array[3]=Array[a]+Array[b];
		
			//Array[3].output();
			//getchar();
		
	};
///-----------------------------------------
		if (menu==5)
	{
		//printf("������� ������ ��-��\n");
		//a = input (MAX_SIZE_ARRAY);
		//printf("������� ������ ��-��\n");
		//b = input (MAX_SIZE_ARRAY);
		//printf("Enter nuber of result slot\n");
		//c = input (MAX_SIZE_ARRAY);
		Array[3]=Array[1]*Array[2];
	};
///-----------------------------------------
			if (menu==6)
	{
		printf("������� ��-��\n");
		a = input (MAX_SIZE_ARRAY);
		//printf("Enter nuber of result slot\n");
		//c = input (MAX_SIZE_ARRAY);
		Array[3]=~Array[a];
	};
///-----------------------------------------
		if (menu==7)
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
///-----------------------------------------
		if (menu==8)
	{
		printf("������� ��-��, �������� ����� ������������� ��������\n");
		a = input (MAX_SIZE_ARRAY);
		printf("������� ��-��, �� �������� ����� ������� ��������\n");
		b = input (MAX_SIZE_ARRAY);
		Array[a]=Array[b];
	};
 ///-----------------------------------------
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
///-----------------------------------------
	system("cls"); //����� ������ �������� ��������� ������ �������
	}while(menu!=10);
	return 0;
}