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

void newPlay(bool turnBlack, int pieceToMove[], Board board)
 {
   printTurn(turnBlack);
   Piece* pieceTaked;
   do{
     cout<<" X OF THE FIGURE TO MOVE"<<endl;
     cin >> pieceToMove[0];
     cout<<" Y OF THE FIGURE TO MOVE"<<endl;
     cin >> pieceToMove[1];
     pieceTaked=board.findPiece(pieceToMove[0],pieceToMove[1],turnBlack);
  }
  while (pieceTaked==NULL);
}

void move(int newPosition[])
 {
   cout<<" X OF THE NEW POSITION"<<endl;
   cin >> newPosition[0];
   cout<<" Y OF THE NEW POSITION"<<endl;
   cin >> newPosition[1];
   //board.checkMotion(newPosition[0],newPosition[1]);
 }

int main(){
  Board board;
  int pieceToMove[2];
  board.newGame();
  newPlay(checkTurn(turn), pieceToMove, board);

}
