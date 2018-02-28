/*
 * Pawn.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */


short int countPawn = 0;

class Pawn : public Piece {
	 char figure = 'P';
public:
	bool checkMove(int x, int y) {
		if (this->y+1==y) {
			return true;
		} return false;
	}

	int virtual move (int x, int y) {
		this->x=x;
		this->y=y;
	}

	Pawn() {
		x=countPawn;
		y=countPawn+1;
		countPawn++;
	}

};
