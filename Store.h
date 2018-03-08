
#include "Piece.h"
#include <vector>
#include <fstream>
#include <thread>
using namespace std;
class Store
{
public:


static void saveBoard(vector <Piece*> &whitePieces,vector <Piece*> &blackPieces )
  {

  ofstream file("Savedplay", ios::binary);

  int whiteSize=whitePieces.size();
  int blackSize=blackPieces.size();
  file.write((char*)&whiteSize, sizeof(int));
  for (auto& piece: whitePieces)
  {
      file.write((char*) piece, sizeof(Piece));

  }
  file.write((char*)&blackSize, sizeof(int));
    for (auto& piece: blackPieces)
    {
        file.write((char*) piece, sizeof(Piece));
    }
  }

  static void loadBoard(vector <Piece*> &whitePieces,vector <Piece*> &blackPieces)
  {
    int sizeOfWhites, sizeOfBlacks;
    ifstream file("Savedplay", ios::binary);
    file.read((char *)&sizeOfWhites, sizeof(int));
   for (size_t i = 0; i <sizeOfWhites; i++)
    {
      Piece* piece=new Pawn(true);
     file.read((char *)piece, sizeof(Piece));
     whitePieces.push_back(piece);

    }
   file.read((char *) &sizeOfBlacks, sizeof(int));
   for (size_t i = 0; i <sizeOfBlacks; i++)
    {
      Piece* piece=new Rook(true);
     file.read((char *)piece, sizeof(Piece));
     blackPieces.push_back(piece);
    }
  }
};
