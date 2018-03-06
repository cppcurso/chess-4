#include "Bishop.h"
#include <gtest/gtest.h>

class BishopTest: public ::testing::Test {
protected:

};

TEST_F(BishopTest, testingMovement) {
  Bishop bishop1(false); // White Bishop Init in(2,7)
  int newPosition[2]={2,5};  //wrong vertical mov
  int result = bishop1.moveOK(newPosition);
  ASSERT_FALSE(result);
  int newPosition2[2]={4,5};  //correct diagonal mov
  int result2 = bishop1.moveOK(newPosition2);
  ASSERT_TRUE(result2);
  int newPosition3[2]={1,10};  //wrong mov outside board
  int result3 = bishop1.moveOK(newPosition3);
  ASSERT_FALSE(result3);
  int newPosition4[2]={1,5};  //wrong mov
  int result4 = bishop1.moveOK(newPosition4);
  ASSERT_FALSE(result4);

  }
