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

class Queen :  public Piece {

public:
	bool  moveOK( int newPosition[]) {
		int a = newPosition[0] - this->x;
		int b = newPosition[1]- this->y;
		a = abs (a);
		b = abs (b);
		if (this->y==newPosition[1] || this->x==newPosition[0] || a == b) {
			return true;
		} return false;
	}

	int  move (int x, int y) {
		this->x=x;
		this->y=y;
	}

	Queen(bool black) {
		this->black=black;
		figure='q';
		x=4;
		y=0;
		if (black==false) {
			figure='Q';
			y=7;
		}
		}
};

#endif /* QUEEN_H_ */
