#include <iostream>
#include"Board.h"
#include"Store.h"

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
    std::cout << '\n';
    cout<< "----------WHITE TURN-----------"<<endl;
  }
  else {
    std::cout << '\n';
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
     if (pieceTaked==NULL) {
     std::cout << "------------------------------" << '\n';
     std::cout << "THE PIECE ISN'T FOUND" << '\n';
     std::cout << "------------------------------" << '\n' << endl;
   }
  }
  while (pieceTaked==NULL);
return pieceTaked;
std::cout << '\n';
}

void getNewPosition(int newPosition[])
 {
   int pieceToMove[2];
   cout<<" X OF THE NEW POSITION"<<endl;
   cin >> newPosition[0];
   cout<<" Y OF THE NEW POSITION"<<endl;
   cin >> newPosition[1];
 }

void turn() {

  Piece* pieceToMove;
  int newPosition[2];
  bool out=false;
  do
  {
    Board::getBoard().upDateBoard();
    Board::getBoard().printBoard();
    out=false;
    pieceToMove = newPiece(checkTurn(plays));
    getNewPosition(newPosition);
    if (Board::getBoard().validMoment(newPosition, pieceToMove, checkTurn(plays)))
    {
      pieceToMove->move(newPosition);
      plays++;
      Store::saveBoard(Board::getBoard().whitePiecesVector,Board::getBoard().blackPiecesVector);
      out=true;
    }
   }
    while(out==false);
}
int main()
{
  char ans;
  std::cout << "Restart Game? Y/N" << '\n';
  cin>>ans;
  if(ans=='Y')
  {
  Store::loadBoard(Board::getBoard().whitePiecesVector,Board::getBoard().blackPiecesVector);
  }
  else if(ans=='N')
  {
  Board::getBoard().startGame();
    }
  do
  {
  turn();
  }
  while(plays <15);
  cout<<"END"<<endl;
}
