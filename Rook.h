/*
 * Rook.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */
#include "Piece.h"
short int countRook =0;

class Rook : public Piece
{
public:

	bool moveOK( int newPosition[])
	{
		if (newPosition[0]==this->x || newPosition[1] ==this->y) return true;
		return false;
	}

	bool  move( int newPosition[]) {
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
