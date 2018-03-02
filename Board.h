
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
  Piece* blackPieces[16];
  Piece* whitePieces[16];

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

void fillArray(Piece* pieces[], bool black)
 {
  for (size_t i = 0; i < 14; i++)
  {
    if (i<8) {
      pieces[i]= new Pawn(black);
    }
    if (i>=8&&i<10) {
      pieces[i]= new Rook(black);
    }
    if (i>=10&&i<12) {
      pieces[i]= new Horse(black);
    }
    if (i>=12&&i<14) {
      pieces[i]= new Bishop(black);
    }
  }
  pieces[14]= new King(black);
  pieces[15]= new Queen(black);
}

void writeBoard()
{
	  for (int i = 0; i < 16; i++) {
		      int a = whitePieces[i]->x;
          int b = whitePieces[i]->y;
          int c = blackPieces[i]->x;
          int d = blackPieces[i]->y;
          pieces[a][b]=whitePieces[i]->figure;
          pieces[c][d]=blackPieces[i]->figure;
	  }
}

bool isEmpty(int newPosition[])
{
  if((pieces[newPosition[0]][newPosition[1]]) == '-'){
   return true;
   cout << "vacio" << endl;
   } return false;
}

void newGame()
{
  initBoard();
  fillArray(blackPieces, false);
  fillArray(whitePieces, true);
  writeBoard();
  printBoard();
}

bool limitsOK(int x,int y){
	if (x>7||x<0 || y>7||y<0)
  {
		return false;
  }
    return true;
	}


Piece* findPiece(int x, int y, bool turnBlack) {
  if (!limitsOK(x,y)) {
    std::cout << "LIMITE" << '\n';return NULL;
   }
  if (turnBlack==true) {
    std::cout << "NEGRAS" << '\n';
    for (size_t i = 0; i < 16; i++) {
      if (blackPieces[i]->x==x && blackPieces[i]->y==y) return blackPieces[i];
    }
  }
  if (turnBlack==false)
  {
  //  std::cout << "BLANCAS" << '\n';
    for (size_t i = 0; i < 16; i++)
     {
       if (whitePieces[i]->x==x && whitePieces[i]->y==y)
       {
         return whitePieces[i];

       }
  }
}
  return NULL;
}
bool validMoment(int newPosition[], Piece* pieceToMove)
{
  if ( limitsOK( newPosition[0],newPosition[1]) && isEmpty(newPosition) )
  {
    pieceToMove->moveOK(newPosition);
  }
}
};
