#include "TBitField.h"

class TSet {
  private:
    int  MaxPower; // максимальная мощность множества
    TBitField BitField;
  public:
	TSet(int mp=1);
	TSet(const TSet &s);       // конструктор копирования
	TSet(const TBitField &bf); // конструктор преобразования типа
	operator TBitField();
	int GetMaxPower ( void ) const;      // максимальная мощность множества
	void InsElem  ( const int n ); // включить элемент в множество
	void DelElem  ( const int n );       // удалить элемент из множества
	int  IsMember ( const int n ) const; // проверить наличие элемента в мн-е
	int  operator==(const TSet &s);  // сравнение
	TSet & operator=(const TSet &s); // присваивание
	TSet operator+  (const int n);   // включение элемента в множество
	TSet operator-  (const int n);   // удаление элемента из множества
	TSet operator+  (const TSet &s); // объединение
	TSet operator*  (const TSet &s); // пересечение
	TSet operator~  ( void );        // дополнение
	int first (int);
	void output ();
	void ENTER (char * command);
};