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

Piece* newPiece(bool turnBlack,  Board board)
 {
   printTurn(turnBlack);
   int pieceToMove[2];
   Piece* pieceTaked;
   do{
     cout<<" X OF THE FIGURE TO MOVE"<<endl;
     cin >> pieceToMove[0];
     cout<<" Y OF THE FIGURE TO MOVE"<<endl;
     cin >> pieceToMove[1];
     pieceTaked=board.findPiece(pieceToMove,turnBlack);
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

int main()
{
  Board board;
  Piece* pieceToMove;
  int newPosition[2];
  board.newGame();
  do
{
<<<<<<< HEAD
  pieceToMove = newPlay(checkTurn(turn), board);
  getNewPosition(newPosition);
  if (board.validMoment(newPosition, pieceToMove)) {
    pieceToMove->move(newPosition);
    board.initBoard();
    board.writeBoard();
    std::cout << "Moviendo pieza" << '\n';
    board.printBoard();
    turn++;
  } else {
    std::cout << "Movimiento inválido, haz otro" << '\n';
  }
}
while(3==3);
=======
  pieceToMove = newPiece(checkTurn(turn), board);
  getNewPosition(newPosition);
  while(board.validMoment(newPosition, pieceToMove))
    {
      pieceToMove->move(newPosition);
      board.writeBoard();
    }
  board.initBoard();
  board.printBoard();
  turn++;
}
while(turn <15);
>>>>>>> c69bf8554c841d8807d5cee85aaba9e34694644f
}
