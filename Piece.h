/*
 * Piece.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */

#ifndef PIECE_H_
#define PIECE_H_

class Piece {
public:
	int x=0;
	int y=0;
	char figure;
	bool black;
  bool virtual moveOK(int newPosition[])=0;
	//void virtual move (int newPosition[])=0;
	void move(int newPosition[]) {
		this->x=newPosition[0];
		this->y=newPosition[1];
	}
};

#endif /* PIECE_H_ */
