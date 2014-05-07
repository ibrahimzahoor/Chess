#ifndef ChessPieces_H
#define ChessPieces_H

class ChessPieces
{
protected:
	char color;
	char Symbol;
public:
	ChessPieces(char clr);

	virtual char Get_Piece_Color()=0;
	virtual char Get_Piece_Symbol()=0;

	virtual bool MovePossible(ChessPieces *Board[8][8], int Src_Row, int Src_Col, int Dest_Row, int Dest_Col)=0;
	
	~ChessPieces();
};

#endif