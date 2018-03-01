#include <iostream>
#include"Board.h"

//_____CHESS_____//

 void newPlay(bool black,)
 {
   if (black == false) {cout<< "----------WHITE TURN-----------"<<endl;}
   else {cout<< "----------BLACK TURN-----------"<<endl;}
   cout<<" X OF THE FIGURE TO MOVE"<<endl;
   //ask_x();
   cout<<" Y OF THE FIGURE TO MOVE"<<endl;
   //ask_Y();
 }
int ask_X()
{
  int x;
  cin>>x;
  return x;
}
int ask_Y()
{
  int y;
  cin>>y;
  return y;
}

}
int main(){
  Board board;
  //board.newGame();
board.newGame();


}
