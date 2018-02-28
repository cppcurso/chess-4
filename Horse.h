/*
 * Horse.h
 *
 *  Created on: 28/02/2018
 *      Author: usuario
 */


#define HORSE_H_
#include "Piece.h"
short int countHorse =0;

class Horse : public Piece{
public:

	bool checkMove(int x, int y){
			int a = x - this->x;
			int b = y - this->y;
			a = a * a;
			b = b * b;
			if(a + b == 5){
				return true;
			}return false;
		}

	int virtual move(int x, int i){
			this->x = x;
			this->y = y;
	}

	Horse(bool black) {
		this->black=black;
		if (black==true) {
			countHorse--;
			figure='h';
			x =6-countHorse*5;
			y=0;

		}
		else if (black==false) {
			figure='H';
			x = 1+ countHorse*5;
			y = 7;
			countHorse++;
		}
	}
};
