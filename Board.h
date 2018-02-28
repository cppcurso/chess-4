
 #include"Piece.h"
 #include"Queen.h"
#include"King.h"
 #include"Horse.h"
#include"Bishop.h"
#include"Pawn.h"
#include"Rook.h"
#include <iostream>
using namespace std;

class Board {
public:
  char pieces[8][8];
  Piece blackPieces[16];
  Piece whitePieces[16];

void initBoard() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
    	pieces[i][j] = 'X';
    }
  }
}
 void printBoard()
{
  for (int j = 0; j < 8; j++)
  {
    for (int i = 0; i < 8; i++)
    {
      cout <<pieces[i][j]<<" ";
    }
  cout <<endl;
  }
}
void fillArray()
 {
  for (size_t i = 0; i < 14; i++)
  {
    if (i<8) {
      whitePieces[i]=Pawn();
      blackPieces[i]=Pawn();
    }
    if (i>=8&&i<10) {
      whitePieces[i]=Rook();
      blackPieces[i]=Rook();
    }
    if (i>=10&&i<12) {
      whitePieces[i]=Horse();
      blackPieces[i]=Horse();
    }
    if (i>=12&&i<14) {
      whitePieces[i]=Bishop();
      blackPieces[i]=Bishop();
    }
    whitePieces[14]=King();
    whitePieces[15]=Queen();
    blackPieces[14]=King();
    blackPieces[15]=Queen();
  }
}
void writeBoard()
{
	  for (int i = 0; i < 16; i++) {
		      int a = whitePieces[i].x;
          int b = whitePieces[i].y;
          int c = blackPieces[i].x;
          int d = blackPieces[i].y;
          pieces[a][b]=whitePieces[i].figure;
          pieces[c][d]=blackPieces[i].figure;
	  }
}
void newGame()
{
  initBoard();
  fillArray();
  writeBoard();
  printBoard();
}



bool valid(int x,int y,char figure) {
	if (x>7||y>7) {
		return false;
	}
}
};
