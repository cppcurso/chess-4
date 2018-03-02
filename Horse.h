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

	bool virtual moveOk( int newPosition[])
	{
			int a = newPosition[0] - this->x;
			int b = newPosition[1]- this->y;
			a = a * a;
			b = b * b;
			if(a + b == 5){
				return true;
			}return false;
		}

	bool virtual moveOk( int newPosition[])
	{
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
