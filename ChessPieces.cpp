#include"ChessPieces.h"

ChessPieces::ChessPieces(char clr):color(clr),Symbol(0)
{}

char ChessPieces::Get_Piece_Color()
{
	return this->color;
}
