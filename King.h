/*
 * King.h
 *
 *  Created on: 28/02/2018
 *      Author: usuario
 */

#include "Piece.h"
#ifndef KING_H_
#define KING_H_
#include <stdlib.h>

class King : public Piece {

public:
	bool checkMove(int x, int y) {
		int a = x - this->x;
		int b = y - this->y;
		a = a * a;
		b = b * b;
		if (this->y+1==y || this->x+1==x || a+b==2) {
			return true;
		} return false;
	}

	int virtual move (int x, int y) {
		this->x=x;
		this->y=y;
	}

	King() {
			figure='K';
			x=3;
			y=0;
		}
};

#endif /* KING_H_ */
