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

void newGame(Piece whitePieces[16])
{
  for (size_t i = 0; i < 8; i++)
  {
    whitePieces[i]=Pawn();
  }
}
void printBoard() {
	initBoard();
	  for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
		  std::cout << pieces[i][j];
		}
		std::cout << '\n';
	  }
}

bool valid(int x,int y,char figure) {
	if (x>7||y>7) {
		return false;
	}
}
};
