#include"ChessPieces.h"

#ifndef ChessBoard_H
#define ChessBoard_H

class ChessBoard
{
private:
	ChessPieces *Board[8][8];
public:
	ChessBoard();

	void Move(char color);
	void Save_To_File(char turn);
	char Load_From_File();
	void Start();
	void Show();
	int Menu();
	void Instructions();
	
	~ChessBoard();
};

#endif