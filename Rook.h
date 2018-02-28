/*
 * Rook.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */
#include "Piece.h"
short int countRook =0;

class Rook : public Piece{
public:

	bool checkMove(int x, int y)
	{
		if (x==this->x || y ==this->y) return true;
	}

	int virtual move(int x, int y) {
		this->x=x;
		this->y=y;
	}
	Rook(bool black) {
		this->black=black;
		if (black==true) {
			countRook--;
			figure='r';
			x =countRook*7;
			y=0;

		}
		else if (black==false) {
			figure='R';
			x = countRook*7;
			y = 7;
			countRook++;
		}
	}
};
