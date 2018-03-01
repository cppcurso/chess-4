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

 void newPlay(bool turnBlack, int newPosition[])
 {
   if (turnBlack == false) {
     cout<< "----------WHITE TURN-----------"<<endl;
   }
   else {
     cout<< "----------BLACK TURN-----------"<<endl;
   }
   cout<<" X OF THE FIGURE TO MOVE"<<endl;
   cin >> newPosition[0];
   cout<<" Y OF THE FIGURE TO MOVE"<<endl;
   cin >> newPosition[1];
}


int main(){
  Board board;
  int newPosition[2];
  board.newGame();
  newPlay(checkTurn(turn), newPosition);
  std::cout << newPosition[0] << '\n';
  std::cout << newPosition[1] << '\n';
}
