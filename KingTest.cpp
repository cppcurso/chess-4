#include "King.h"
#include <gtest/gtest.h>

class KingTest: public ::testing::Test {
protected:

};

TEST_F(KingTest, testingMovement) {
  King king1(false); // White King Init in(3,7)
  int newPosition[2]={3,5};  //wrong vertical mov
  int result = king1.moveOK(newPosition);
  ASSERT_FALSE(result);
  int newPosition2[2]={3,6};  //correct vertical mov
  int result2 = king1.moveOK(newPosition2);
  ASSERT_TRUE(result2);
  int newPosition5[2]={4,7};  //correct horizontal mov
  int result5 = king1.moveOK(newPosition5);
  ASSERT_TRUE(result5);
  int newPosition6[2]={4,6};  //correct diagonal mov
  int result6 = king1.moveOK(newPosition6);
  ASSERT_TRUE(result6);
  int newPosition3[2]={1,10};  //wrong mov outside board
  int result3 = king1.moveOK(newPosition3);
  ASSERT_FALSE(result3);
  int newPosition4[2]={1,5};  //wrong mov inside board
  int result4 = king1.moveOK(newPosition4);
  ASSERT_FALSE(result4);

  }
