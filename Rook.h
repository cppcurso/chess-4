
#include "Piece.h"
short int countRook =0;

class Rook : public Piece{
	char figure ='R';

public:

	bool checkMove(int x, int y)
	{
		if (x==this->x || y ==this->y) return true;
	}

	int virtual move(int x, int y) {
		this->x=x;
		this->y=y;
	}
	Rook(){
		x=1+countRook*7;
		y=1;
		countRook++;
	}
};
