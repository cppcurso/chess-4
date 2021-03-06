/*
 * Pawn.h
 *
 *  Created on: 27/02/2018
 *      Author: usuario
 */
#include "Piece.h"

short int countPawn = 0;

class Pawn :  public Piece {

public:
	bool moveOK(int newPosition[])
	 {
		if (black==true && this->y==1 && newPosition[1]-this->y<=2) return true;
		if (black==false && this->y==6 && this->y-newPosition[1]<=2) return true;
		if (newPosition[0]-this->x==1||newPosition[0]-this->x==-1) return true;
		if (black==false && (newPosition[1]-this->y)==-1) return true;
		if (black==true && (newPosition[1]-this->y)==1) return true;

		return false;
	 }

	 void move(int newPosition[]) {
		this->x=newPosition[0];
		this->y=newPosition[1];
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
