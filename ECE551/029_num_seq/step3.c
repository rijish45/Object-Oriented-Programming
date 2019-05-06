// This file is for Step 3.
// You should do
//  Step 3 (A): write seq3
//  Step 3 (B): write main to test seq3
//  Step 3 (C): write countEvenInSeq3Range
//  Step 3 (D): add test cases to main to test countEvenInSeq3Range
//
// Be sure to #include any header files you need!

/* This assignment is the individual work 
of Rijish Ganguly for ECE 551 */

#include <stdio.h>
#include <stdlib.h>

int seq3(int x, int y) {
  return x * y + (2 * y) - (3 * x);
}

int countEvenInSeq3Range(int xLow, int xHi, int yLow, int yHi) {
  int numEven = 0;

  if (xLow > xHi || yLow > yHi || xLow == xHi || yLow == yHi) {
    return 0;
  }

  else {
    for (int i = xLow; i < xHi; i++) {
      for (int j = yLow; j < yHi; j++) {
        int checknum = seq3(i, j);
        if (checknum % 2 == 0) {
          numEven += 1;
        }
      }
    }
  }

  return numEven;
}

int main() {
  /*

       *****************************************************
       Start testing for int seq3(int x, int y)
       *****************************************************


  */

  int answer;
  //test case 1
  answer = seq3(0, 0);
  printf("seq3(%d, %d) = %d\n", 0, 0, answer);

  //test case 2
  answer = seq3(1, 5);
  printf("seq3(%d, %d) = %d\n", 1, 5, answer);

  //test case 3
  answer = seq3(-1, -6);
  printf("seq3(%d, %d) = %d\n", -1, -6, answer);

  //test case 4
  answer = seq3(-4, 0);
  printf("seq3(%d, %d) = %d\n", -4, 0, answer);

  //test case 5
  answer = seq3(-10, -12);
  printf("seq3(%d. %d) = %d\n", -10, -12, answer);

  //test case 6
  answer = seq3(5, 20);
  printf("seq3(%d, %d) = %d\n", 5, 20, answer);

  //test case 7
  answer = seq3(12234, 1234);
  printf("seq3(%d, %d) = %d\n", 12234, 1234, answer);

  //test case 8
  answer = seq3(-234, -5334);
  printf("seq3(%d, %d) = %d\n", -234, -5334, answer);

  //test case 9
  answer = seq3(-4355, 5674);
  printf("seq3(%d, %d) = %d\n", -4355, 5674, answer);

  /*

       **********************************************************************
       Start testing for int countEvenInSeq3Range(int x, int y, int z, int w)
       **********************************************************************

   */

  int returnAnswer;

  //test case 1
  returnAnswer = countEvenInSeq3Range(0, 2, 0, 3);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 2, 0, 3, returnAnswer);

  //test case 2
  returnAnswer = countEvenInSeq3Range(1, 0, 0, 3);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 1, 0, 0, 3, returnAnswer);

  //test case 3
  returnAnswer = countEvenInSeq3Range(0, 0, 0, 3);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 0, 0, 3, returnAnswer);

  //test case 4
  returnAnswer = countEvenInSeq3Range(0, 2, 1, 0);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 2, 1, 0, returnAnswer);

  //test case 5
  returnAnswer = countEvenInSeq3Range(0, 0, 0, 0);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 2, 1, 0, returnAnswer);

  //test case 6
  returnAnswer = countEvenInSeq3Range(-3, 0, 0, 4);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 2, 1, 0, returnAnswer);

  //test case 7
  returnAnswer = countEvenInSeq3Range(0, 3, -3, -1);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 0, 3, -3, -1, returnAnswer);

  //test case 8
  returnAnswer = countEvenInSeq3Range(-5, 5, -4, 4);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", -5, 5, -4, 4, returnAnswer);

  //test case 9
  returnAnswer = countEvenInSeq3Range(1, 0, 1, 0);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 1, 0, 1, 0, returnAnswer);

  //test case 10
  returnAnswer = countEvenInSeq3Range(234, 450, 23, 57);
  printf("countEvenInSeq3Range(%d, %d, %d, %d) = %d\n", 234, 450, 23, 57, returnAnswer);

  return 0;
}
