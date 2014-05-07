#include"Knight.h"

Knight::Knight(char clr):ChessPieces(clr)
{
	this->Symbol='N';
}

char Knight::Get_Piece_Color()
{
	return this->color;
}

char Knight::Get_Piece_Symbol()
{
	return this->Symbol;
}

bool Knight::MovePossible(ChessPieces *Board[8][8], int src_i, int src_j, int dest_i, int dest_j)
{
	if(Board[dest_i][dest_j]==nullptr || this->Get_Piece_Color()!=Board[dest_i][dest_j]->Get_Piece_Color())
	{
		if((dest_i==src_i-1) && (dest_j==src_j+2))
		{
			return true;
		}
		else if((dest_i==src_i+1) && (dest_j==src_j+1))
		{
			return true;
		} 
		else if(dest_i==src_i+2)
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
		else if(dest_j==src_j-2)
		{
			if(dest_i==src_i+1)
			{
				return true;
			}
			else if(dest_i==src_i-1)
			{
				return true;
			}
		}
		else if(dest_i==src_i-2)
		{
			if(dest_j==src_j-1)
			{
				return true;
			}
			else if(dest_j==src_j+1)
			{
				return true;
			}
		}	
	}
	return false;
}