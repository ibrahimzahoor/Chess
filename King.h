#include"ChessPieces.h"

#ifndef King_H
#define King_H

class King: public ChessPieces
{
public:
	King(char clr);

	char Get_Piece_Color();
	char Get_Piece_Symbol();

	bool MovePossible(ChessPieces *Board[8][8], int Src_Row, int Src_Col, int Dest_Row, int Dest_Col);
};

#endif