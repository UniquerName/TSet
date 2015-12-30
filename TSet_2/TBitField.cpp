#include "TBitField.h"
#include <iostream>
#include <stdio.h>

///-----------------------------------------
int TBitField :: GetMemIndex (const int n) const {
	return n >> 5;
}            
///-----------------------------------------
TELEM TBitField :: GetMemMask (const int n) const {
	return 1 << (n & 31);
}             
///-----------------------------------------
TBitField :: TBitField(int len) : BitLen(len) {
  MemLen = ( len + 31 ) >> 5; 
  pMem   = new TELEM[MemLen];
  if ( pMem != NULL )
    for ( int i=0; i < MemLen; i++ ) pMem[i] = 0;
}            
///-----------------------------------------
TBitField :: TBitField(const TBitField &bf) {
	BitLen = bf.BitLen;
	MemLen = bf.MemLen;
	pMem   = new TELEM[MemLen];
	if ( pMem != NULL )
		for ( int i=0; i < MemLen; i++ ) pMem[i] = bf.pMem[i];
}            
///-----------------------------------------
TBitField :: ~TBitField() {
delete [] pMem;
}            
///-----------------------------------------
// ====================================================================================доступ к битам битового поля
///-----------------------------------------
int TBitField :: GetLength(void) const { // получить длину (к-во битов)
  return BitLen;
}             
///-----------------------------------------
void TBitField :: SetBit ( const int n ) { // установить бит
  if ( (n > -1) && (n < BitLen) )
    pMem[GetMemIndex(n)] |= GetMemMask(n);
}           
///-----------------------------------------
void TBitField :: ClrBit ( const int n ) { 
  if ( (n > -1) && (n < BitLen) )
    pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}              
///-----------------------------------------
int TBitField :: GetBit ( const int n ) const {
	if ( (n > -1) && (n < BitLen) )
		return (GetMemMask(n) & pMem[GetMemIndex(n)]) >> n;
}            
///-----------------------------------------
// ====================================================================================битовые операции

TBitField & TBitField :: operator=(const TBitField &bf) {		//присваивание
	if (MemLen != bf.MemLen)
	{
		delete[] pMem;
		MemLen = bf.MemLen;
		pMem = new TELEM [MemLen];
	}
	BitLen = bf.BitLen;
	for (int i=0; i<MemLen; i++)
		pMem[i] = bf.pMem[i];
	return (*this);
}             
///-----------------------------------------
int  TBitField :: operator==(const TBitField &bf) {				//сравнение
  int res = 1;
  if ( BitLen != bf.BitLen ) res = 0;
  else
    for ( int i=0; i < MemLen; i++ )
      if ( pMem[i] != bf.pMem[i] ) { res = 0; break; }
  return res;
}             
///-----------------------------------------
TBitField TBitField :: operator| (const TBitField &bf) {
  int i, len = BitLen;
  if ( bf.BitLen > len ) len = bf.BitLen;
  TBitField temp(len);
  for ( i=0; i < MemLen;    i++ ) temp.pMem[i]  =    pMem[i];
  for ( i=0; i < bf.MemLen; i++ ) temp.pMem[i] |= bf.pMem[i];
  return temp;
}             
///-----------------------------------------

TBitField TBitField :: operator& (const TBitField &bf) {
  int i, len = BitLen;
  if ( bf.BitLen > len ) len = bf.BitLen;
  TBitField temp(len);
  for ( i=0; i < MemLen;    i++ ) temp.pMem[i]  =    pMem[i];
  for ( i=0; i < bf.MemLen; i++ ) temp.pMem[i] &= bf.pMem[i];
  return temp;
}           
///-----------------------------------------
void TBitField :: output ()
{
	int i=0,max=0;
	for(i;i<BitLen;i++)
		if (GetBit(i))
			max=i;
	for(i=0; i<max+1; i++)
		printf("%d", GetBit(i));
	//for(i=0; i<max+1; i++)
	//	printf("%d", GetBit(i));
			//printf("\n\tmax = %d", max);
			//if ((max == 1) && (GetBit(0)==0)) printf ("Мн-во пустое\n");
			//printf("\t\tmax = %d", max);
			//BitLen=max;
	//i=0;
	//while (GetBit(i) == 0)
	// {
	//	i = i+1;
	//}
	//if (i==max) printf("\nМн-во пустое\n");
	//else
	
			//if (GetBit(i) != 0)
}             
///-----------------------------------------
void TBitField :: ENTER (char * command)
{
	int i;
	TBitField A;
	for(i = 0; i<BitLen; i++)
	{
		if (command[i]==48)
			ClrBit(i);
		else if (command[i]==49)
			SetBit(i);
		else break;
	}
}
///-----------------------------------------
TBitField TBitField :: operator~ ( void ) {
	TBitField res(BitLen);
	for (int i=0; i < MemLen;    i++ ) res.pMem[i] = ~pMem[i];
	return res;
}             
///-----------------------------------------
// ввод/вывод

/*istream &operator>>(istream &istr, TBitField &bf) { // ввод
  // формат данных - последовательность из 0 и 1 без пробелов
  // начальные пробелы игнорируются
  // при получении не 0 или 1 - завершение ввода
  int i=0; char ch;
  // поиск {
  do { istr >> ch; } while (ch != ' ');
  // ввод элементов и включение в множество
  while (1) { istr >> ch;
    if ( ch == '0' ) bf.ClrBit(i++);
    else if ( ch == '1' ) bf.SetBit(i++); else break;
  }
  return istr;
}      */        /*---------------------------------------------*/