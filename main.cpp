#include <iostream>
#include"Board.h"

//_____CHESS_____//

unsigned int turn = 1;

bool checkTurn(unsigned int turn) {
  if (turn%2==0) {
    return true;
  }
  return false;
}

void printTurn(bool turnBlack) {
  if (turnBlack == false) {
    cout<< "----------WHITE TURN-----------"<<endl;
  }
  else {
    cout<< "----------BLACK TURN-----------"<<endl;
  }
}

Piece* newPlay(bool turnBlack,  Board board)
 {
   printTurn(turnBlack);
   int pieceToMove[2];
   Piece* pieceTaked;
   do{
     cout<<" X OF THE FIGURE TO MOVE"<<endl;
     cin >> pieceToMove[0];
     cout<<" Y OF THE FIGURE TO MOVE"<<endl;
     cin >> pieceToMove[1];
     pieceTaked=board.findPiece(pieceToMove[0],pieceToMove[1],turnBlack);
  }
  while (pieceTaked==NULL);
return pieceTaked;
}

void getNewPosition(int newPosition[])
 {
   cout<<" X OF THE NEW POSITION"<<endl;
   cin >> newPosition[0];
   cout<<" Y OF THE NEW POSITION"<<endl;
   cin >> newPosition[1];
 }

int main(){
  Board board;
  Piece* pieceToMove;
  int newPosition[2];
  board.newGame();
  pieceToMove = newPlay(checkTurn(turn), board);
  getNewPosition(newPosition);
  if (board.validMoment(newPosition, pieceToMove)) {
    //board.move(getNewPosition(newPosition), pieceToMove);
    std::cout << "Moviendo pieza" << '\n';
  } else {
    std::cout << "Moviento inválido, haz otro" << '\n';
  }

}
