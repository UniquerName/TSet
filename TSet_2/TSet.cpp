#include "TSet.h"
#include <iostream>
#include <stdio.h>

TSet :: TSet (int mp) : MaxPower(mp), BitField(mp) {};

TSet :: TSet (const TSet &s) : MaxPower(s.MaxPower), BitField(s.BitField) {};

TSet :: TSet (const TBitField &bf) : MaxPower(bf.GetLength()), BitField(bf) {};

TSet :: operator TBitField()
{
  TBitField res(this->BitField);
  return res;
}

int TSet :: GetMaxPower ( void ) const
{
	return MaxPower;
}

void TSet :: InsElem  ( const int n )
{
	BitField.SetBit(n);
}

void TSet :: DelElem  ( const int n )
{
	BitField.ClrBit(n);
}

int TSet :: IsMember ( const int n ) const
{
	return BitField.GetBit(n);
}

int TSet :: operator==(const TSet &s)
{
	return BitField == s.BitField;
}

TSet & TSet :: operator=(const TSet &s)
{
	MaxPower=s.MaxPower;
	BitField=s.BitField;
	return *this;
}

TSet TSet :: operator+  (const int n)
{
	TSet res(*this);
	BitField.SetBit(n);        /////?????????????????
	return res;
}

TSet TSet :: operator-  (const int n)
{
	TSet res(*this);
	BitField.ClrBit(n);        /////?????????????????
	return res;
}

TSet TSet :: operator+ (const TSet &s) 
{
  TSet res(BitField | s.BitField);
  return res;
}

TSet TSet :: operator* (const TSet &s) 
{
  TSet res(BitField & s.BitField);
  return res;
}

TSet TSet :: operator~ ( void )
{
  TSet res(~BitField);
  return res;
}

void TSet :: output ()
{
	int i=0, m=1;
	printf("{");
	while (m)
	//if(f=1)
	//{f=0; printf("ћн-во пусто");}
	//else
		if (IsMember(i++))
		{
			m=0;
			printf("%d", i-1);
		}
	for(i; i<MaxPower; i++)
		if (IsMember(i))
				printf(",%d", i);
	printf("}");
}


void TSet :: ENTER (char *set)
{
	int i=-1, elem=0;
	while(set[++i]!='{');

	do
	{
		i++;
		do
			elem=elem*10+set[i++]-48;
		while ((set[i]!=',')&&(set[i]!='}'));
		InsElem(elem);
		elem=0; 
	}
	while (set[i]!='}');
}

int TSet :: first (int n)
{
	int i=n;
	while (IsMember(i++) == 0);
	return i-1;
}
