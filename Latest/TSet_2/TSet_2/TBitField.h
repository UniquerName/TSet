
typedef unsigned int TELEM;

class TBitField
{
	int BitLen; //длина бита
	int MemLen; //длина памяти
	TELEM *pMem; //указатель на местоположение в памяти
	int GetMemIndex ( const int n ) const; 
	TELEM GetMemMask ( const int n ) const;
public:
	TBitField (int len = 1);
	TBitField (const TBitField &bf) ;
	~TBitField ();
	 //конструкторы и деструктор
	int GetLength(void) const;
	void SetBit ( const int n );
	void  ClrBit ( const int n );
	int  GetBit ( const int n ) const; 
	TBitField & operator=(const TBitField &bf); //присваивание
	int  operator==(const TBitField &bf); //сравнение
	TBitField operator| (const TBitField &bf); // или
	TBitField operator& (const TBitField &bf); // и
	TBitField operator~ ();  //отрицание
	void output ();
	void ENTER (char * command);
};