/*
 * Pawn.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */

#ifndef PAWN_H_
#define PAWN_H_

short int countPawn = 0;

class Pawn : public Piece {
	figure = 'P';
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





#endif /* PAWN_H_ */
