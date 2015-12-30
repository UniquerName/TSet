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
setlocale(LC_ALL, "Russian");	//Явык
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
		//printf("\nИзначально первые два множества содержат только один элемент равный значению универсума, который впоследствии заменяется на вводимый и дополняется новыми элементами\n");
		//printf("\nВ третье мн-во записывается результат операций из алгебры мн-тв\n"); // 0: Задайте макс. элемент в универсуме\n 1: Ввод\n
		printf(" 1: Вывод\n 2: Ввод\n 3: Добавить элемент к мн-ву\n 4: удалить элемент из мн-ва\n \t5:U (Объединение)\n \t6: /\ (Пересечение)\n \t7: ~ (Отрицание)\n \t8: == (Сравнение)\n \t9: Присваивание\n 0:  Завершение\n");
	scanf("%d", &menu); 
///-----------------------------------------
	/*if (menu==0)
	{
		printf("Введите универсум\n");
		universe = input (MAX_SIZE_SET);
	}*/
///-----------------------------------------
	
	if (menu==2)
	{
		printf("укажите мн-во для ввода\n"); 
		c = input (MAX_SIZE_ARRAY);
		printf("Начните ввод \n Например: {x1,x2,x3,...}\n");
		scanf("%s",set);
		TSet B(universe);
		B.ENTER(set);
		Array[c]=B;
	};
//==========================================
	if (menu==1)
	{
		//printf("1 - вывод мн-ва\n2 - вывод битового поля\n");
		//int S = input (MAX_SIZE_ARRAY);
		printf("Какое мн-во вывести?\n");
		c = input (MAX_SIZE_ARRAY);
		printf("\n");
		{
			TBitField OUT=Array[c];
			int a=OUT.GetLength();
			printf("Битовое поле:\n");
			OUT.output();
			printf("\n");
			//printf("\t Length = %d\n",a);
			if ( a==1 ) printf("Мн-во пустое\n");
			else {
				int i=0;
				while ((OUT.GetBit(i) ==0) && (i<a))
				{ 
				 i+=1;
				}
				if ( i < (a-1) ){
			printf("множество:\n");
				Array[c].output();
				}
				else  printf("Мн-во пустое\n");
				}
			}
		/*if (S==1) {
			TBitField OUT=Array[c];
			int a=OUT.GetLength();
			//printf("%d\n",a);
			if (a==1) printf("Мн-во пустое\n");
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
				//printf("Мн-во пустое \n");
				*/
		getchar();
		getchar();
	};
///-----------------------------------------
	if (menu==3)
	{
		printf("С каким мн-вом работать?\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Введите элемент\n");
		b = input (universe);
		Array[a]+b;
	};
///-----------------------------------------
		if (menu==4)
	{
		printf("С каким мн-вом работать?\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Введите элемент\n");
		b = input (universe);
		Array[a]-b;
	};
//==========================================
		if (menu==5)
	{
		/*printf("Укажите первое мн-во\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Укажите второе мн-во\n");
		b = input (MAX_SIZE_ARRAY);
		printf("Enter nuber of result slot\n");
		c = input (MAX_SIZE_ARRAY);*/
		Array[3]=Array[1]+Array[2];
	};
//==========================================
		if (menu==6)
	{
		/*printf("Укажите первое мн-во\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Укажите второе мн-во\n");
		b = input (MAX_SIZE_ARRAY);
		printf("Укажите результирующее мн-во\n");
		c = input (MAX_SIZE_ARRAY);*/
		Array[3]=Array[1]*Array[2];
	};
//==========================================
			if (menu==7)
	{
		printf("Укажите мн-во\n");
		a = input (MAX_SIZE_ARRAY);
		//printf("Enter nuber of result slot\n");
		//c = input (MAX_SIZE_ARRAY);
		Array[3]=~Array[a];
	};
//==========================================
		if (menu==8)
	{
		printf("Укажите первое мн-во\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Укажите второе мн-во\n");
		b = input (MAX_SIZE_ARRAY);
		if(Array[a]==Array[b]) printf("Мн-ва равны");
		else printf("Мн-ва различаются");
		getchar();
		getchar();
	};
//==========================================
		if (menu==9)
	{
		printf("Укажите мн-во, которому будут присваиваться значения\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Укажите мн-во, из которого будут браться значения\n");
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
	system("cls"); //после каждой операции останется только менюшка
	}while(menu!=0);
	return 0;
}