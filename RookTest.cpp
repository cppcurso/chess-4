#include "Rook.h"
#include <gtest/gtest.h>

class RookTest: public ::testing::Test {
protected:

};

TEST_F(RookTest, testingMovement) {
  Rook Rook1(false); // Black Rook Init in(0,7)
  int newPosition[2]={0,5};
	int result = Rook1.moveOK(newPosition);
	ASSERT_TRUE(result);
}
