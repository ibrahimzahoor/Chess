#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;
#include"King.h"
#include"Knight.h"
#include"Pawn.h"
#include"Bishop.h"
#include"Queen.h"
#include"Rook.h"
#include"ChessBoard.h"
#include"myconsole.h"

int Ascii_to_int(char z);


ChessBoard::ChessBoard()
{
	for(int i=0; i<8; ++i)
	{
		for(int j=0; j<8; ++j)
		{
			this->Board[i][j]=nullptr;
		}
	}
	//FOR WHITES
	this->Board[7][0]=new Rook('W');
	this->Board[7][1]=new Knight('W');
	this->Board[7][2]=new Bishop('W');
	this->Board[7][3]=new Queen('W');
	this->Board[7][4]=new King('W');
	this->Board[7][5]=new Bishop('W');
	this->Board[7][6]=new Knight('W');
	this->Board[7][7]=new Rook('W');
	
	this->Board[6][0]=new Pawn('W');
	this->Board[6][1]=new Pawn('W');
	this->Board[6][2]=new Pawn('W');
	this->Board[6][3]=new Pawn('W');
	this->Board[6][4]=new Pawn('W');
	this->Board[6][5]=new Pawn('W');
	this->Board[6][6]=new Pawn('W');
	this->Board[6][7]=new Pawn('W');
	
	//for black
	this->Board[0][0]=new Rook('B');
	this->Board[0][1]=new Knight('B');
	this->Board[0][2]=new Bishop('B');
	this->Board[0][3]=new Queen('B');
	this->Board[0][4]=new King('B');
	this->Board[0][5]=new Bishop('B');
	this->Board[0][6]=new Knight('B');
	this->Board[0][7]=new Rook('B');

	this->Board[1][0]=new Pawn('B');
	this->Board[1][1]=new Pawn('B');
	this->Board[1][2]=new Pawn('B');
	this->Board[1][3]=new Pawn('B');
	this->Board[1][4]=new Pawn('B');
	this->Board[1][5]=new Pawn('B');
	this->Board[1][6]=new Pawn('B');
	this->Board[1][7]=new Pawn('B');
}

ChessBoard::~ChessBoard()
{
	
	for(int i=0; i<8; ++i)
	{
		for(int j=0; j<8; ++j)
		{
			//delete[] this->Board[i][j];  //giving error unresolved external "`vector deleting destructor'"
		}
	}
	//delete[] this->Board;  //is it the right solution?
}


void ChessBoard::Move(char color)
{
	int Src_Row=0, Src_Col, Dest_Row, Dest_Col;
	char arr1[5]={};
	char arr2[5]={};
	char won_color=0;
	bool flag=false;
	
	while(flag==false)
	{
		cout<<"MOVE FROM:  ";
		cin>>arr1;
		
		if(strcmp(arr1,"back")==0)
		{
			if(color=='W')
			{
				throw 0;
			}else
				throw 1;
		}
		cout<<"MOVE TO:  ";
		cin>>arr2;
		if(strcmp(arr2,"back")==0)
		{
			if(color=='W')
			{
				throw 0;
			}else
				throw 1;
		}

		Src_Row=Ascii_to_int(arr1[0]);
		Src_Col=Ascii_to_int(arr1[1]);
		Dest_Row=Ascii_to_int(arr2[0]);
		Dest_Col=Ascii_to_int(arr2[1]);

		if(Src_Row!=-1 && Src_Col!=-1 && Dest_Row!=-1 && Dest_Col!=-1)
		{
			if(this->Board[Src_Row][Src_Col]!=nullptr)
			{
				if(this->Board[Src_Row][Src_Col]->Get_Piece_Color()==color)
				{
					if(this->Board[Src_Row][Src_Col]->MovePossible(Board,Src_Row,Src_Col, Dest_Row,Dest_Col)==true)
					{
						flag=true;
						if(this->Board[Dest_Row][Dest_Col]!=nullptr)
						{
							if(this->Board[Dest_Row][Dest_Col]->Get_Piece_Symbol()=='K')
							{
								won_color=this->Board[Dest_Row][Dest_Col]->Get_Piece_Color();
								this->Board[Dest_Row][Dest_Col]=this->Board[Src_Row][Src_Col];
								this->Board[Src_Row][Src_Col]=nullptr;
								throw won_color;
							}
							else
							{
								this->Board[Dest_Row][Dest_Col]=this->Board[Src_Row][Src_Col];
								this->Board[Src_Row][Src_Col]=nullptr;
							}
						}
						else
						{
							this->Board[Dest_Row][Dest_Col]=this->Board[Src_Row][Src_Col];
							this->Board[Src_Row][Src_Col]=nullptr;
						}
					}else
					{
						cout<<"\t\t\tI N V A L I D    M O V E !!!!\n\t\t   PLEASE ENTER THE POSITIONS AGAIN:"<<endl;
					}
				}else cout<<"\t\t\tI N V A L I D    M O V E !!!!\n\t\t   PLEASE ENTER THE POSITIONS AGAIN:"<<endl;
			}else cout<<"\n\t\t\tI N V A L I D    E N T R Y !!!!\n\t\t   PLEASE ENTER THE POSITIONS AGAIN"<<endl;
		}else cout<<"\n\t\t\tI N V A L I D    E N T R Y !!!!\n\t\t   PLEASE ENTER THE POSITIONS AGAIN"<<endl;
	}
}

void ChessBoard::Start()
{
	int option=0, counter=0;
	bool is_end=false, not_start=false;
	char turn=0;
	
	while(option!=6)
	{
		try
		{
			option=Menu();
			switch(option)
			{
			case 1:
				this->ChessBoard::ChessBoard();
				counter=0;
				is_end=false;
				not_start==false;

				while(is_end==false)
				{
					system("cls");
					this->Show();
					if(counter%2==0)
					{
						cout<<"\t\t\tW H I T E S   T U R N"<<endl;
						this->Move('W');
					}else
					{
						cout<<"\t\t\tB L A C K    T U R N"<<endl;
						this->Move('B');
					}
					counter++;
				}
				break;
			case 2:
				is_end=false;
				if(not_start==true)
				{
					is_end=true;
					cout<<"NOT AVALIBLE";
					Sleep(500);
				}
				
				while(is_end==false)
				{
					system("cls");
					this->Show();
					if(counter%2==0)
					{
						cout<<"\t\t\tW H I T E S   T U R N"<<endl;
						this->Move('W');
					}else
					{
						cout<<"\t\t\tB L A C K    T U R N"<<endl;
						this->Move('B');
					}
					counter++;	
				}
				break;
			
			case 3:
				is_end=false;
				not_start=false;
				turn=this->Load_From_File();
				if(turn=='W')
				{
					counter=0;
				}else counter=1;
				
				while(is_end==false)
				{
					system("cls");
					this->Show();
					if(counter%2==0)
					{
						cout<<"\t\t\tW H I T E S   T U R N"<<endl;
						this->Move('W');
					}else
					{
					cout<<"\t\t\tB L A C K    T U R N"<<endl;
					this->Move('B');
					}
					counter++;
				}
				break;
			case 4:
				if(counter%2==0)
				{
					turn='W';
				}else turn='B';;
				this->Save_To_File(turn);
				break;
				
			case 5:
				this->Instructions();
				break;
					
			case 6:
				int choice=0;
				PlaceCursor(17,33);
				cout<<"DO YOU WANT TO SAVE GAME BEFORE EXIT?(Y/N)"<<endl;
				choice=CheckKeyPressed(30000);
				if(choice=='Y' || choice=='y')
				{
					if(counter%2==0)
					{
						turn='W';
					}else turn='B';;
					this->Save_To_File(turn);
				}
				PlaceCursor(22,35);
				cout<<"	T H A N K    Y O U!!!"<<endl;
				PlaceCursor(20,36);
				cout<<"For Playing BLACK & WHITE CHESS";
				PlaceCursor(26,38);
				cout<<"BY IBRAHIM ZAHOOR";
				PlaceCursor(28,39);
				cout<<"FAST-NU LAHORE";
				Sleep(3500);
				break;
			}
		}
		catch(int var)
		{
			counter=var;
			is_end=true;
		}
		catch(char * A)
		{
			is_end=true;
			PlaceCursor(25,33);
			cout<<A<<endl;
			PlaceCursor(22,35);
			cout<<"Press Any Key to Enter Choice Again"<<endl;
			CheckKeyPressed(30000);
		}
		catch(char a)
		{
			not_start=true;
			system("cls");
			this->Show();
			this->ChessBoard::ChessBoard();
			PlaceCursor(7,38);
			if(a=='B')
			{
				cout<<"\t\t   B L A C K     K I N G    IS     D E A D   "<<endl;
				cout<<"\t\t\t\tW H I T E S    W O N"<<endl;
			}
			else if(a=='W')
			{
				cout<<"\t\t   W H I T E      K I N G    IS     D E A D   "<<endl;
				cout<<"\t\t\t\tB L A C K    W O N"<<endl;
			}
			for(int i=7;i<60; i++)
			{
				SetColorAtPoint(i,39,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			}
			cout<<"\t\t\tPress Any Key To Go Back To Main Menu"<<endl;
			CheckKeyPressed(100000);
		}
	}
}

char ChessBoard::Load_From_File()
{
	ifstream fin;
	
	fin.open("save_game.txt");

	char character=0, color=0, turn=0;
	bool saved=false;
	
	if(fin.is_open()==true)
	{
		fin>>saved>>turn;
		if(saved==true)
		{
			for(int i=0; i<8; ++i)
			{
				for(int j=0; j<8; ++j)
				{
					fin>>character;
					if(character!='X')
					{
						fin>>color;
						PlaceCursor(5,7);
						switch(character)
						{
						case 'P':
							this->Board[i][j]=new Pawn(color);
							break;
						case 'R':
							this->Board[i][j]=new Rook(color);
							break;
						case 'B':
							this->Board[i][j]=new Bishop(color);
							break;
						case 'N':
							this->Board[i][j]=new Knight(color);
							break;
						case 'K':
							this->Board[i][j]=new King(color);
							break;
						case 'Q':
							this->Board[i][j]=new Queen(color);
							break;
						}
					}else this->Board[i][j]=nullptr;
				}
			}
		}else throw "NO SAVED GAME AVALIBLE";
	}else throw "SAVE FILE COULD NOR BE OPENED"; 
	fin.close();
	
	return turn;
}

void ChessBoard::Save_To_File(char turn)
{
	ifstream fin;
	ofstream fout;
	
	fout.open("save_game.txt");

	if(fout.is_open()==true)
	{
		fout<<'1'<<turn;
		for(int i=0; i<8; ++i)
		{
			for(int j=0; j<8; ++j)
			{
				if(this->Board[i][j]!=nullptr)
				{
					fout<<this->Board[i][j]->Get_Piece_Symbol()<<this->Board[i][j]->Get_Piece_Color();
				}
				else fout<<'X';
			}
		}
		PlaceCursor(16,33);
		cout<<"G A M E   S A V E D    S U C E S S F U L L Y"<<endl;
		PlaceCursor(18,35);
		cout<<"Press Any Key to Enter Choice Again"<<endl;
	}else throw "ERROR SAVING GAME";
	fout.close();
	CheckKeyPressed(30000);
}

int ChessBoard::Menu()
{
		system("cls");
		int choice=0;
		char boundary=186;
		int x=0,y= 5;
			for ( x = 13; x<=60; x++)
				{
					 PlaceCursor(x,y);
					 cout<<boundary;
					 SetColorAtPoint(x,y,  FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					 PlaceCursor(x,y+25);
					 cout<<boundary;
					 SetColorAtPoint(x,y+25, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
				}
		x=13;
			 for (y= 5 ; y<=30; y++)
				 {
					 PlaceCursor(x,y);
					 cout<<boundary;
					 SetColorAtPoint(x,y,FOREGROUND_GREEN| FOREGROUND_INTENSITY);
					 PlaceCursor(x+47,y);
					 cout<<boundary;
					 SetColorAtPoint(x+47,y,FOREGROUND_GREEN| FOREGROUND_INTENSITY);
				 }
				 
		x= 19; y=7; 
		PlaceCursor(x,y);
		cout<<"  WELCOME TO BLACK & WHITE CHESS GAME";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		x=15;
		y+=3;
		PlaceCursor(x,y);
		cout<<"  Enter '1' to Start New Game";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=3;
		PlaceCursor(x,y);
		cout<<"  Enter '2' To Resume Game";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=3;
		PlaceCursor(x,y);
		cout<<"  Enter '3' To Play Last Saved Game";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=3;
		PlaceCursor(x,y);
		cout<<"  Enter '4' To Save the Game";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=3;
		PlaceCursor(x,y);
		cout<<"  Enter '5' To Show The Instructions";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=3;
		PlaceCursor(x+1,y);
		cout<<" Enter '6' To Exit The Game";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=3;
		PlaceCursor(x+1,y);
		cout<<" Enter Choice Please -->>>> ";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		cin>>choice;
		return choice;
}

void ChessBoard::Instructions()
{
		system("cls");
		int choice=0,x=0,y=5;
		char boundary=186;
			
			for ( x = 7; x<=70; x++)
				{
					 PlaceCursor(x,y);
					 cout<<boundary;
					 SetColorAtPoint(x,y,  FOREGROUND_GREEN | FOREGROUND_INTENSITY);
					 PlaceCursor(x,y+30);
					 cout<<boundary;
					 SetColorAtPoint(x,y+30, FOREGROUND_GREEN| FOREGROUND_INTENSITY);
				}
				
		x=7;
			 for (y= 5 ; y<=35; y++)
				 {
					 PlaceCursor(x,y);
					 cout<<boundary;
					 SetColorAtPoint(x,y,FOREGROUND_GREEN| FOREGROUND_INTENSITY);
					 PlaceCursor(x+64,y);
					 cout<<boundary;
					 SetColorAtPoint(x+64,y,FOREGROUND_GREEN| FOREGROUND_INTENSITY);
				 }
				 
		x= 26; y=8; 
		PlaceCursor(x,y);
		cout<<"  I N S T R U C T I O N S";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		x=9;
		y+=5;
		PlaceCursor(x,y);
		cout<<"1) First Enter The Position of The Piece You Want To Move";
		for(int i=x;i<66; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=4;
		PlaceCursor(x,y);
		cout<<"2) Then Enter The New Positin";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		
		y+=4;
		PlaceCursor(x,y);
		cout<<"3) For Entering ROW Number Respective ROW Numbers (1,2,3..)";
		PlaceCursor(x+3,y+1);
		cout<<"Are Given on RIGHT And LEFT Side Of Board";
		for(int i=x;i<66; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		for(int i=x;i<66; i++)
		{
			SetColorAtPoint(i,y+1,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=4;
		PlaceCursor(x,y);
		cout<<"4) For Entering COLUMN number Respective COLUMN Letters";
		PlaceCursor(x+3,y+1);
		cout<<" (A,B,C..) Are Given on UPPER And LOWER Side Of Board";
		for(int i=x;i<66; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		for(int i=x;i<66; i++)
		{
			SetColorAtPoint(i,y+1,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=4;
		PlaceCursor(x+15,y);
		cout<<"E N J O Y   Y O U R   G A M E";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		y+=4;
		PlaceCursor(x+10,y);
		cout<<"PRESS Any Key To Go Back to Main Menu";
		for(int i=x;i<60; i++)
		{
			SetColorAtPoint(i,y,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		cin.ignore();
		CheckKeyPressed(30000);
}

void ChessBoard::Show()
{
	cout<<endl;

	char A=186, B=205, C=201, D=187,E=188,F=200, G=203, H=185,I=202, J=204,K=206, L=176;
	
	cout<<"       "<<C;
	for(int q=0; q<63; ++q)
	{
		cout<<B;
		
	}cout<<D<<endl;
	cout<<"       "<<A<<"       A      B      C      D      E      F      G      H      "<<A<<endl;
	
	cout<<"       "<<A<<"   "<<C;
	for(int q=0; q<7; ++q)
	{
		cout<<B<<B<<B<<B<<B<<B<<G;
	}
	cout<<B<<B<<B<<B<<B<<B<<D<<"   "<<A<<endl<<"       "<<A<<"   "<<A;
	
	for(int q=0; q<8; ++q)
	{
		if(q%2!=0)
		{
			cout<<L<<L<<L<<L<<L<<L<<A;
		}else
		{
			cout<<"      "<<A;
		}
	}
	cout<<"   "<<A<<endl;
	int number=8;
	bool flag=true;
	for(int i=0; i<8; ++i)
	{
		cout<<"       "<<A<<' '<<number<<' '<<A;
		for(int j=0; j<8; ++j)
		{
			if(this->Board[i][j]!=nullptr)
			{
				if(flag==true)
				{
					if(j%2!=0)
					{
						cout<<L<<L<<this->Board[i][j]->Get_Piece_Color()<<this->Board[i][j]->Get_Piece_Symbol()<<L<<L<<A;
					}
					else
					{
						cout<<"  "<<this->Board[i][j]->Get_Piece_Color()<<this->Board[i][j]->Get_Piece_Symbol()<<"  "<<A;
					}
				}
				else if(flag==false)
				{
					if(j%2==0)
					{
						cout<<L<<L<<this->Board[i][j]->Get_Piece_Color()<<this->Board[i][j]->Get_Piece_Symbol()<<L<<L<<A;
					}
					else
					{
						cout<<"  "<<this->Board[i][j]->Get_Piece_Color()<<this->Board[i][j]->Get_Piece_Symbol()<<"  "<<A;
					}
				}
			}
			else 
			{
				if(flag==true)
				{
					if(j%2!=0)
					{
						cout<<L<<L<<L<<L<<L<<L<<A;
					}
					else
					{
						cout<<"      "<<A;
					}
				}
				else if(flag==false)
				{
					if(j%2==0)
					{
						cout<<L<<L<<L<<L<<L<<L<<A;
					}
					else
					{
						cout<<"      "<<A;
					}
				}	
			}
		}
		cout<<" "<<number<<" "<<A<<endl<<"       "<<A<<"   "<<A;
		number--;
		
		for(int q=0; q<8; ++q)
		{
			if(flag==true)
				{
					if(q%2!=0)
					{
						cout<<L<<L<<L<<L<<L<<L<<A;
					}
					else
					{
						cout<<"      "<<A;
					}
				}
				else if(flag==false)
				{
					if(q%2==0)
					{
						cout<<L<<L<<L<<L<<L<<L<<A;
					}
					else
					{
						cout<<"      "<<A;
					}
				}
		}
		cout<<"   "<<A<<endl;

		if(i!=7)
		{
			cout<<"       "<<A<<"   "<<J;
			for(int q=0; q<7; ++q)
			{
				cout<<B<<B<<B<<B<<B<<B<<K;
			}cout<<B<<B<<B<<B<<B<<B<<H<<"   "<<A<<endl<<"       "<<A<<"   "<<A;
			
			for(int q=0; q<8; ++q)
			{
				if(flag==false)
				{
					if(q%2!=0)
					{
						cout<<L<<L<<L<<L<<L<<L<<A;
					}
					else
					{
						cout<<"      "<<A;
					}
				}
				else if(flag==true)
				{
					if(q%2==0)
					{
						cout<<L<<L<<L<<L<<L<<L<<A;
					}
					else
					{
						cout<<"      "<<A;
					}
				}
			}
			cout<<"   "<<A<<endl;
		}
		if(flag==true) flag=false;
		else flag=true;
	}

	cout<<"       "<<A<<"   "<<F;
	for(int q=0; q<7; ++q)
		{
			cout<<B<<B<<B<<B<<B<<B<<I;
		}cout<<B<<B<<B<<B<<B<<B<<E<<"   "<<A<<endl;

	cout<<"       "<<A<<"       A      B      C      D      E      F      G      H      "<<A<<endl;
	cout<<"       "<<F;
	for(int q=0; q<63; ++q)
	{
		cout<<B;
	}cout<<E<<endl;

	for(int i=0; i<78; i++)
	{
		for(int j=0; j<45; j++)
		{
			SetColorAtPoint(i,j,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
	}
	
	cout<<"                  TYPE \"back\" ANYTIME TO GO BACK TO MAIN MENU"<<endl;
	for(int i=10; i<70; i++)
	{
		SetColorAtPoint(i,38,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
}

int Ascii_to_int(char i)
{
	int b=0, z=i;
	
	if(z>=65 && z<=72)
	{
		b=z-65;
	}
	else if(z>=97 && z<=104)
	{
		b=z-97;
	}
	else switch(z)
	{
	case 56:
		b=0;
		break;
	case 55:
		b=1;
		break;
	case 54:
		b=2;
		break;
	case 53:
		b=3;
		break;
	case 52:
		b=4;
		break;
	case 51:
		b=5;
		break;
	case 50:
		b=6;
		break;
	case 49:
		b=7;
		break;
	default:
		b=-1;
	}
	return b;
}