#include "Horse.h"
#include <gtest/gtest.h>

class HorseTest: public ::testing::Test {
protected:

};

TEST_F(HorseTest, testingMovement) {
  Horse horse1(false); // White Horse Init in(1,7)
  int newPosition[2]={1,5};  //wrong vertical mov
  int result = horse1.moveOK(newPosition);
  ASSERT_FALSE(result);
  int newPosition2[2]={0,5};  //correct L mov
  int result2 = horse1.moveOK(newPosition2);
  ASSERT_TRUE(result2);
  int newPosition3[2]={1,10};  //wrong mov outside board
  int result3 = horse1.moveOK(newPosition3);
  ASSERT_FALSE(result3);
  int newPosition4[2]={5,5};  //wrong mov
  int result4 = horse1.moveOK(newPosition4);
  ASSERT_FALSE(result4);

  }
