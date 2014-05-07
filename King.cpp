#include"King.h"

King::King(char clr): ChessPieces(clr)
{
	this->Symbol='K';
}

char King::Get_Piece_Color()
{
	return this->color;
}

char King::Get_Piece_Symbol()
{
	return this->Symbol;
}

bool King::MovePossible(ChessPieces *Board[8][8], int src_i, int src_j, int dest_i, int dest_j)
{
	if(Board[dest_i][dest_j]==nullptr || this->Get_Piece_Color()!=Board[dest_i][dest_j]->Get_Piece_Color())
	{
		if(dest_i==src_i)
		{
			if(dest_j==src_j+1)
			{
				return true;
			}
			else if(dest_j==src_j-1)
			{
				return true;
			}
		}
		else if(dest_i==src_i-1)
		{
			if(dest_j==src_j+1)
			{
				return true;
			}
			else if(dest_j==src_j-1)
			{
				return true;
			}
			else if(dest_j==src_j)
			{
				return true;
			}
		}
		else if(dest_i==src_i+1)
		{
			if(dest_j==src_j+1)
			{
				return true;
			}
			else if(dest_j==src_j)
			{
				return true;
			}
			else if(dest_j==src_j-1)
			{
				return true;
			}
		}
	}
	return false;
}