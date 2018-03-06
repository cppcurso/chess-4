#include "Rook.h"
#include <gtest/gtest.h>

class RookTest: public ::testing::Test {
protected:

};

TEST_F(RookTest, testingMovement) {
  Rook Rook1(false); // White Rook Init in(0,7)
  int newPosition[2]={0,5};  //correct vertical mov
	int result = Rook1.moveOK(newPosition);
	ASSERT_TRUE(result);
  int newPosition3[2]={7,7};  //correct mov vertical final board
  int result3 = Rook1.moveOK(newPosition3);
  ASSERT_TRUE(result3);
  int newPosition4[2]={0,0};   //correct mov horizontal final board
  int result4 = Rook1.moveOK(newPosition4);
  ASSERT_TRUE(result4);
  int newPosition2[2]={2,5};  //wrong mov inside board
	int result2 = Rook1.moveOK(newPosition2);
	ASSERT_FALSE(result2)
  int newPosition5[2]={2,10};  //wrong mov outside board
	int result5 = Rook1.moveOK(newPosition5);
	ASSERT_FALSE(result5);

}
