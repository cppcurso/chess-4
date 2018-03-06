#include "Pawn.h"
#include <gtest/gtest.h>

class PawnTest: public ::testing::Test {
protected:
};

TEST_F(PawnTest, testingMovement) {
  Pawn Pawn1(false);
  int newPosition[2]={6,5}; // White Pawn move to (6,5)
	int result = Pawn1.moveOK(newPosition);
	ASSERT_TRUE(result);
  int newPosition2[2]={6,4}; // White Pawn move to (6,4)
	int result2 = Pawn1.moveOK(newPosition2);
	ASSERT_FALSE(result2);
  int newPosition3[2]={9,9}; // White Pawn move to (9,9)
	int result3 = Pawn1.moveOK(newPosition3);
	ASSERT_FALSE(result3);
}
