#include"ChessPieces.h"

#ifndef Queen_H
#define Queen_H

class Queen: public ChessPieces
{
public:
	Queen(char clr);

	char Get_Piece_Color();
	char Get_Piece_Symbol();
	
	bool MovePossible(ChessPieces *Board[8][8], int Src_Row, int Src_Col, int Dest_Row, int Dest_Col);

};

#endif