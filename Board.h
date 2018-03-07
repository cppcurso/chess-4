#include"Piece.h"
#include"Queen.h"
#include"King.h"
#include"Horse.h"
#include"Bishop.h"
#include"Pawn.h"
#include"Rook.h"
#include <vector>
#include <iostream>
 //for (auto& *Piece: pieces)
using namespace std;

class Board {

  Board() {};
  Board(const Board& s);
  void operator=(const Board& s);
public:
  static Board& getBoard() {
      static Board newBoard;
      return newBoard;
  }
  char board[8][8];
  vector <Piece*> whitePiecesVector;
  vector <Piece*> blackPiecesVector;
  //Piece* blackPieces[16];
  //Piece* whitePieces[16];


 void printBoard() {
  std::cout << '\n';
  std::cout << "    ";
  for (size_t i = 0; i < 8; i++)
    {
      std::cout << i << " ";
    }
    std::cout << '\n';
    std::cout << "    ---------------" << '\n';
    std::cout << "         BLACK" << '\n';
  for (int j = 0; j < 8; j++)
  {
    std::cout << j<<"|  ";
    for (int i = 0; i < 8; i++)
    {
      cout <<board[i][j]<<" ";
    }
  cout <<endl;
  }
  std::cout << "         WHITE" << '\n';
}

void fillVector(vector <Piece*> &pieces, bool black)
 {
  for (size_t i = 0; i < 14; i++)
  {
    if (i<8) {
      pieces.push_back(new Pawn(black));
    }
    if (i>=8&&i<10) {
       pieces.push_back(new Rook(black));
    }
    if (i>=10&&i<12) {
      pieces.push_back( new Horse(black));
    }
    if (i>=12&&i<14) {
      pieces.push_back( new Bishop(black));
    }
  }
  pieces.push_back( new King(black));
  pieces.push_back( new Queen(black));
}

void writeBoard(vector <Piece*> &pieces )
{   for (auto& piece : pieces)
	  {
		      int coorX = piece->x;
          int coorY = piece->y;
          board[coorX][coorY]=piece->figure;
	  }
}
void initBoard() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
    	board[i][j] = '-';
    }
  }
}
bool isEmpty(int newPosition[])
{
  if((board[newPosition[0]][newPosition[1]]) == '-'){
   return true;
   } return false;
}
void upDateBoard()
{
  initBoard();
  writeBoard(whitePiecesVector);
  writeBoard(blackPiecesVector);
}
void startGame()
{
  fillVector(whitePiecesVector, false);
  fillVector(blackPiecesVector, true);
  upDateBoard();
  printBoard();
}

bool limitsOK(int x,int y){
	if (x>7||x<0 || y>7||y<0)
  {
		return false;
  }
    return true;
	}
Piece* findPiece(int x, int y, bool turnBlack) {
  if (!limitsOK(x,y)) {
    std::cout << '\n';
    std::cout << "------------------------------" << '\n';
    std::cout << "THE POSITION IS OUTSIDE THE LIMIT" << '\n'; return NULL;
    std::cout << "------------------------------" << '\n' << endl;
   }
  if (turnBlack==true)
  {
    for (auto& piece: blackPiecesVector)
      if (piece->x==x && piece->y==y) return piece;
    }
  if (turnBlack==false)
  {
    for (auto& piece: whitePiecesVector)
     {
       if (piece->x==x && piece->y==y)
       {
         return piece;
       }
     }
}
  return NULL;
}
bool validMoment(int newPosition[], Piece* pieceToMove, bool black)
{
  return true;
  if (limitsOK(newPosition[0],newPosition[1])
  && isEmpty(newPosition)
  && pieceToMove->moveOK(newPosition)
  && checkWay(newPosition,pieceToMove,black))
  {
  return true;
  }
  std::cout << "------------------------------" << '\n';
  std::cout << "THE PIECE CAN'T MOVE THERE" << '\n';
  std::cout << "------------------------------" << '\n' << endl;
  return false;
}

bool checkWay(int newPosition[], Piece* pieceToMove, bool blacks)
{
  if (pieceToMove->figure=='H' || pieceToMove->figure=='h') return true;
  int position[2];
  position[0]=pieceToMove->x;
  position[1]=pieceToMove->y;
  while (position[0]!=newPosition[0] || position[1]!=newPosition[1] )
{
  if (newPosition[0]>position[0]) position[0]++;
  else if(newPosition[0]<position[0]) position[0]--;
  if (newPosition[1]>position[1]) position[1]++;
  else if(newPosition[1]<position[1]) position[1]--;
   if (!isEmpty(position))
   {
     if (pieceToMove->black!=blacks)
     {
      std::cout << "------------------------------" << '\n';
      std::cout << "A PIECE CAN'T JUMP OTHER PIECES"<< '\n';
      std::cout << "------------------------------" << '\n' << endl;
      }
      else if (position[0]==newPosition[0]&&position[1]==newPosition[1]) // si mi destino es la pieza
      {
         if (blacks)
        {
           eat(newPosition,whitePiecesVector);
         }
         else  eat(newPosition,blackPiecesVector);
         return true;
      }
     return false;
  }
}
  return true;
}

void eat(int newPosition[],vector <Piece*> &piecesVector)
{ std::cout << "COMEN" << '\n';
    Piece* a;
    for (auto it = piecesVector.begin(); it < piecesVector.end(); it++)
    {
           a =*it;
            if (a->x==newPosition[0] && a->y==newPosition[1])
              {
                  piecesVector.erase(it);
                }
        }
}
};
