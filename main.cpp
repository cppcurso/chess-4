#include <iostream>
#include"Board.h"

//_____CHESS_____//

unsigned int plays = 1;

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

Piece* newPiece(bool turnBlack)
 {
   printTurn(turnBlack);
   int pieceToMove[2];
   Piece* pieceTaked;
   do{
     cout<<" X OF THE FIGURE TO MOVE"<<endl;
     cin >> pieceToMove[0];
     cout<<" Y OF THE FIGURE TO MOVE"<<endl;
     cin >> pieceToMove[1];
     pieceTaked=Board::getBoard().findPiece(pieceToMove[0],pieceToMove[1],turnBlack);
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

void turn() {
  Piece* pieceToMove;
  int newPosition[2];
  pieceToMove = newPiece(checkTurn(plays));
  bool out=false;
  do
  {
    out=false;
    getNewPosition(newPosition);
    if (Board::getBoard().validMoment(newPosition, pieceToMove))
    {
      pieceToMove->move(newPosition);
      Board::getBoard().initBoard();
    Board::getBoard().writeBoard();
      Board::getBoard().printBoard();
      plays++;
      out=true;
    }
   }
    while(out==false);
}

int main()
{
  Board::getBoard();
  Board::getBoard().startGame();
  do
{
  turn();
}
while(plays <15);
cout<<"END"<<endl;
}
