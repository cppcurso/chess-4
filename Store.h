
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
  // for (auto& piece: whitePieces)
  // {
  //     file.write((char*) piece, sizeof(Piece));
  //
  //   }
  //   for (auto& piece: blackPieces)
  //   {
  //       file.write((char*) piece, sizeof(Piece));
  //   }
  file.write((char*)sizeof(whitePieces), sizeof(int));
  file.write((char*)whitePieces[0], sizeof(Piece));
  }

  static void loadBoard()
  {
    int sizeOfWhit
    Piece* piece;
    ifstream file("Savedplay", ios::binary);
          file.read((char *) piece, sizeof(Piece));
        std::cout << piece->figure<<piece->x<<piece->y << '\n';
  }
};
