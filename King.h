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

class King :public Piece {

public:
	bool moveOK( int newPosition[]) {
		int a = newPosition[0] - this->x;
		int b = newPosition[1] - this->y;
		a = a * a;
		b = b * b;
		if (a==1 || b==1 || a+b==2) {
			return true;
		} return false;
	}

	King(bool black) {
			this->black=black;
			figure='k';
			x=3;
			y=0;
			if (black==false) {
				figure='K';
				y=7;
			}
		}
};

#endif /* KING_H_ */
