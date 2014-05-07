#include"Queen.h"

Queen::Queen(char clr):ChessPieces(clr)
{
	this->Symbol='Q';
}

char Queen::Get_Piece_Color()
{
	return this->color;
}

char Queen::Get_Piece_Symbol()
{
	return this->Symbol;
}

bool Queen::MovePossible(ChessPieces *Board[8][8], int src_i, int src_j, int dest_i, int dest_j)
{
	if(dest_i==src_i)
	{
		if(dest_j > src_j)
		{
			int i=0;
			for(i=1; Board[src_i][src_j+i]==nullptr; ++i)
			{
				if(src_j+i==dest_j)
					return true;
			}
				
			if(src_j+i==dest_j)
			{
				if(Board[src_i][src_j+i]->Get_Piece_Color()!=this->Get_Piece_Color())
				{
					return true;
				}
				else return false;
			}
		}
		else if(dest_j < src_j)
		{
			int i=0;
			for(i=1; Board[src_i][src_j-i]==nullptr; ++i)
			{
				if(src_j-i==dest_j)
					return true;
			}
				
			if(src_j-i==dest_j)
			{
				if(Board[src_i][src_j-i]->Get_Piece_Color()!=this->Get_Piece_Color())
				{
					return true;
				}
				else return false;
			}
		}
	}
	else if(dest_j==src_j)
	{
		if(dest_i > src_i)
		{
			int i=0;
			for(i=1; Board[src_i+i][src_j]==nullptr; ++i)
			{
				if(src_i+i==dest_i)
					return true;
			}
				
			if(src_i+i==dest_i)
			{
				if(Board[src_i+i][src_j]->Get_Piece_Color()!=this->Get_Piece_Color())
				{
					return true;
				}
				else return false;
			}
		}
		else if(dest_i < src_i)
		{
			int i=0;
			for(i=1; Board[src_i-i][src_j]==nullptr; ++i)
			{
				if(src_i-i==dest_i)
					return true;
			}
				
			if(src_i-i==dest_i)
			{
				if(Board[src_i-i][src_j]->Get_Piece_Color()!=this->Get_Piece_Color())
				{
					return true;
				}
				else return false;
			}
		}
	}
	else if(dest_i < src_i && dest_j > src_j)
			{
				int i=0;
				for(i=1; Board[src_i-i][src_j+i]==nullptr; ++i)
				{
					if((src_i-i==dest_i) && (src_j+i==dest_j))
						return true;
				}
				
				if((src_i-i==dest_i) && (src_j+i==dest_j))
				{
					if(Board[src_i-i][src_j+i]->Get_Piece_Color()!=this->Get_Piece_Color())
					{
						return true;
					}
					else return false;
				}
			}
			else if(dest_i > src_i && dest_j > src_j)
			{
				int i=0;
				for(i=1; Board[src_i+i][src_j+i]==nullptr; ++i)
				{
					if((src_i+i==dest_i) && (src_j+i==dest_j))
						return true;
				}
				
				if((src_i+i==dest_i) && (src_j+i==dest_j))
				{
					if(Board[src_i+i][src_j+i]->Get_Piece_Color()!=this->Get_Piece_Color())
					{
						return true;
					}
					else return false;
				}
			}
			else if(dest_i > src_i && dest_j < src_j)
			{
				int i=0;
				for(i=1; Board[src_i+i][src_j-i]==nullptr; ++i)
				{
					if((src_i+i==dest_i) && (src_j-i==dest_j))
						return true;
				}
				
				if((src_i+i==dest_i) && (src_j-i==dest_j))
				{
					if(Board[src_i+i][src_j-i]->Get_Piece_Color()!=this->Get_Piece_Color())
					{
						return true;
					}
					else return false;
				}
			}
			else if(dest_i < src_i && dest_j < src_j)
			{
				int i=0;
				for(i=1; Board[src_i-i][src_j-i]==nullptr; ++i)
				{
					if((src_i-i==dest_i) && (src_j-i==dest_j))
						return true;
				}
				
				if((src_i-i==dest_i) && (src_j-i==dest_j))
				{
					if(Board[src_i-i][src_j-i]->Get_Piece_Color()!=this->Get_Piece_Color())
					{
						return true;
					}
					else return false;
				}
			}
	return false;
}