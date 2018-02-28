/*
 * Queen.h
 *
 *  Created on: 28/02/2018
 *      Author: usuario
 */

#include "Piece.h"
#ifndef QUEEN_H_
#define QUEEN_H_
#include <stdlib.h>

class Queen : public Piece {

public:
	bool checkMove(int x, int y) {
		int a = x - this->x;
		int b = y - this->y;
		a = abs (a);
		b = abs (b);
		if (this->y==y || this->x==x || a == b) {
			return true;
		} return false;
	}

	int virtual move (int x, int y) {
		this->x=x;
		this->y=y;
	}

	Queen() {
			figure='Q';
			x=4;
			y=0;
		}
};

#endif /* QUEEN_H_ */
