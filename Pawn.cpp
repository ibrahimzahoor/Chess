#include"Pawn.h"

Pawn::Pawn(char clr):ChessPieces(clr)
{
	this->Symbol='P';
}

char Pawn::Get_Piece_Symbol()
{
	return this->Symbol;
}

char Pawn::Get_Piece_Color()
{
	return this->color;
}

bool Pawn::MovePossible(ChessPieces *Board[8][8], int src_i, int src_j, int dest_i, int dest_j)
{
	if(Board[dest_i][dest_j]==nullptr)
	{
		if(src_j==dest_j)
		{
			if(this->Get_Piece_Color()=='W')
			{
				if(dest_i==src_i-1)
				{
					return true;
				}
			}
			else if(this->Get_Piece_Color()=='B')
			{
				if(dest_i==src_i+1)
				{
					return true;
				}
			}
		}
	}
	//done if destination is nullptr
	
	else if(Board[dest_i][dest_j]!=nullptr)
	{
  		if(dest_j==src_j+1 || dest_j==src_j-1)
		{
			if(this->Get_Piece_Color()=='W')
			{
				if(dest_i==src_i-1)
				{
					return true;
				}
			}
			else
			{
				if(dest_i==src_i+1)
				{
					return true;
				}
			}
		}
	}
	return false;
}
