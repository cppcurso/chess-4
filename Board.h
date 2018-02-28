/*
 * Board.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */
 #include"Piece.h"
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
void writeBoard()
 {
  for (size_t i = 0; i < 8; i++)
  {
    whitePieces[i]=Pawn();

  }
  for (size_t i = 0; i < count; i++) {
    /* code */
  }
}
{
	  for (int i = 0; i < 8; i++) {
		      int a= whitePieces[i].x;
          int b=whitePieces[i].y;
          pieces[a][b]=whitePieces[i].figure;
	  }
}

 void fill
void newGame()
{

  writeBoard();
  printBoard();
}



bool valid(int x,int y,char figure) {
	if (x>7||y>7) {
		return false;
	}
}
};
