/*
 * Bishop.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */

#ifndef BISHOP_H_
#define BISHOP_H_
#include <stdlib.h>
short int countBishop =0;

class Bishop : public Piece{
public:
	figure = 'B';

	int virtual move(int x, int i){
		this->x = x;
		this->y = y;
	}

	bool checkMove(int x, int y){
		x - this->x = a;
		y - this->y = b;
		a = abs(a);
		b = abs(b);
		if(a == b){
			return true;
		} return false;
	}

	Bishop(){
			x = 2+ countBishop*3;
			y = 1;
			countBishop++;
		}
};

#endif /* BISHOP_H_ */
