/*
 * Pawn.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */


short int countPawn = 0;

class Pawn :  public Piece {

public:
	//char figure = 'P';
	bool  moveOK(int newPosition[]) override {
		if (this->y+1==newPosition[1]) {
			return true;
		} return false;
	}

	int move(int x, int y) {
		this->x=x;
		this->y=y;
	}

	Pawn(bool black) {
		this->black=black;
		if (black==true) {
			countPawn--;
			figure='p';
			x=countPawn;
			y=1;
		}
		else if (black==false) {
			figure='P';
			y=6;
			x=countPawn;
			countPawn++;
		}
	}

};
