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
	virtual void move(int x,int y,char figure) {

	}
};

#endif /* PIECE_H_ */
