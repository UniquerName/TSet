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
setlocale(LC_ALL, "Russian");	//Явык
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
		//printf("\nИзначально первые два множества содержат только один элемент равный значению универсума, который впоследствии заменяется на вводимый и дополняется новыми элементами\n");
		printf("\n результат операций  из алгебры мн-тв записывается в третье мн-во\n"); // 0: Задайте макс. элемент в универсуме\n 1: Ввод\n
		printf(" 1: Вывод\n 2: Добавить элемент к мн-ву\n 3: удалить элемент из мн-ва\n \t4:U (Объединение)\n \t5: ^ (Пересечение)\n \t6: ~ (Отрицание)\n \t7: == (Сравнение)\n 8: Присваивание\n 9:Ввод мн-ва\n 10:  Завершение\n");
	scanf("%d", &menu); 
///-----------------------------------------
	/*if (menu==0)
	{
		printf("Введите универсум\n");
		universe = input (MAX_SIZE_SET);
	}*/
///-----------------------------------------
	
	if (menu==9)
	{
		printf("Укажите мн-во для заполнения\n"); // на ввод идет set, затем создается мн-во ограниченное универсумом, и в него подставляется заданное значение set 
		c = input (MAX_SIZE_ARRAY);
		printf("Ввод осуществляется в фигурных скобках через запятую\n");
		scanf("%s",set);
		TSet B(universe);
		B.ENTER(set);
		Array[c]=B;
	};
///-----------------------------------------
	if (menu==1)
	{
		printf("1 - вывод мн-ва\n0 - вывод битового поля\n");
		menu = input (MAX_SIZE_ARRAY);
		printf("Какое мн-во вывести?\n");
		c = input (MAX_SIZE_ARRAY);
		printf("\n");
		if (menu==1)
			Array[c].output();
		else if (menu==0)
			if (Array[c]==Array[4]) 
				{printf("\nПустое мн-во\n"); } 
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
		printf("С каким мн-вом работать?\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Введите элемент\n");
		b = input (universe);
		Array[a]+b;
	};
///-----------------------------------------
		if (menu==3)
	{
		printf("С каким мн-вом работать?\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Введите элемент\n");
		b = input (universe);
		Array[a]-b;
	};
///-----------------------------------------
		if (menu==4)
	{
		printf("Укажите первое мн-во\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Укажите второе мн-во\n");
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
		//printf("Укажите первое мн-во\n");
		//a = input (MAX_SIZE_ARRAY);
		//printf("Укажите второе мн-во\n");
		//b = input (MAX_SIZE_ARRAY);
		//printf("Enter nuber of result slot\n");
		//c = input (MAX_SIZE_ARRAY);
		Array[3]=Array[1]*Array[2];
	};
///-----------------------------------------
			if (menu==6)
	{
		printf("Укажите мн-во\n");
		a = input (MAX_SIZE_ARRAY);
		//printf("Enter nuber of result slot\n");
		//c = input (MAX_SIZE_ARRAY);
		Array[3]=~Array[a];
	};
///-----------------------------------------
		if (menu==7)
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
///-----------------------------------------
		if (menu==8)
	{
		printf("Укажите мн-во, которому будут присваиваться значения\n");
		a = input (MAX_SIZE_ARRAY);
		printf("Укажите мн-во, из которого будут браться значения\n");
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
	system("cls"); //после каждой операции останется только менюшка
	}while(menu!=10);
	return 0;
}