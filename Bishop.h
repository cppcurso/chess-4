/*
 * Bishop.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */

#ifndef BISHOP_H_
#define BISHOP_H_
#include <stdlib.h>
#include "Piece.h"
short int countBishop = 0;

class Bishop : public Piece
{
public:
	bool checkMove(int x, int y){
			int a = x - this->x;
			int b = y - this->y;
			a = abs(a);
			b = abs(b);
			if(a == b){
				return true;
			} return false;
		}

	int virtual move(int x, int i){
		this->x = x;
		this->y = y;
	}

	Bishop(bool black) {
		this->black=black;
		if (black==true) {
			countBishop--;
			figure='b';
			x =5- countBishop*3;
			y=0;

		}
		else if (black==false) {
			figure='B';
			x = 2+ countBishop*3;
			y = 7;
			countBishop++;
		}
	}
};

#endif /* BISHOP_H_ */
