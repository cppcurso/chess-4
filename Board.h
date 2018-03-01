
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
    	pieces[i][j] = '-';
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
void fillArrayWhite()
 {
  for (size_t i = 0; i < 14; i++)
  {
    if (i<8) {
      whitePieces[i]=Pawn(false);
    }
    if (i>=8&&i<10) {
      whitePieces[i]=Rook(false);
    }
    if (i>=10&&i<12) {
      whitePieces[i]=Horse(false);
    }
    if (i>=12&&i<14) {
      whitePieces[i]=Bishop(false);
    }
  }
  whitePieces[14]=King(false);
  whitePieces[15]=Queen(false);
}

void fillArrayBlack()
 {
  for (size_t i = 0; i < 14; i++)
  {
    if (i<8) {
      blackPieces[i]=Pawn(true);
    }
    if (i>=8&&i<10) {
      blackPieces[i]=Rook(true);
    }
    if (i>=10&&i<12) {
      blackPieces[i]=Horse(true);
    }
    if (i>=12&&i<14) {
      blackPieces[i]=Bishop(true);
    }
  }
  blackPieces[14]=King(true);
  blackPieces[15]=Queen(true);
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
  fillArrayWhite();
  fillArrayBlack();
  writeBoard();
  printBoard();
}

bool valid(int x,int y,char figure) {
	if (x>7||y>7) {
		return false;
	}
}

bool checkTurn(int turn) {
  if (turn%2==0) {
    return true;
  }
  return false;
}

bool findPiece(int x, int y, bool turnBlack) {
  if (turnBlack==true) {
    for (size_t i = 0; i < 16; i++) {
      if (blackPieces[i].x==x && blackPieces[i].y==y) return true;
    }
    return false;
  }

  if (turnBlack==false) {
    for (size_t i = 0; i < 16; i++) {
      if (whitePieces[i].x==x && whitePieces[i].y==y) return true;
    }
    return false;
  }
}
};
