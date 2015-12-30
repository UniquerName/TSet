
typedef unsigned int TELEM;

class TBitField
{
	int BitLen; //����� ����
	int MemLen; //����� ������
	TELEM *pMem; //��������� �� �������������� � ������
	int GetMemIndex ( const int n ) const; 
	TELEM GetMemMask ( const int n ) const;
public:
	TBitField (int len = 1);
	TBitField (const TBitField &bf) ;
	~TBitField ();
	 //������������ � ����������
	int GetLength(void) const;
	void SetBit ( const int n );
	void  ClrBit ( const int n );
	int  GetBit ( const int n ) const; 
	TBitField & operator=(const TBitField &bf); //������������
	int  operator==(const TBitField &bf); //���������
	TBitField operator| (const TBitField &bf); // ���
	TBitField operator& (const TBitField &bf); // �
	TBitField operator~ ();  //���������
	void output ();
	void ENTER (char * command);
};