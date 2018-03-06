#include "Queen.h"
#include <gtest/gtest.h>

class QueenTest: public ::testing::Test {
protected:
};

TEST_F(QueenTest, testingMovement) {
  Queen Queen1(false);
  int newPosition[2]={7,7}; // White Queen init in (7,7)
	int result = Queen1.moveOK(newPosition);
	ASSERT_TRUE(result);
  int newPosition2[2]={0,3}; // White Queen init in (0,3)
	int result2 = Queen1.moveOK(newPosition2);
	ASSERT_TRUE(result2);
  int newPosition3[2]={3,3}; // White Queen init in (3,3)
  int result3 = Queen1.moveOK(newPosition3);
  ASSERT_FALSE(result3);

  Queen Queen2(true);
  int newPosition4[2]={7,0}; // Black Queen init in (7,0)
	int result4 = Queen2.moveOK(newPosition4);
	ASSERT_TRUE(result4);
  int newPosition5[2]={6,5}; // Black Queen init in (6,5)
  int result5 = Queen2.moveOK(newPosition5);
  ASSERT_FALSE(result5);
}
