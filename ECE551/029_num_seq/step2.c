// This file is for Step 2.
// You should do
//  Step 2 (A): write seq2
//  Step 2 (B): write main to test seq2
//  Step 2 (C): write sumSeq2
//  Step 2 (D): add test cases to main to test sumSeq2
//
// Be sure to #include any header files you need!

/* This assignment is the individual work of 
Rijish Ganguly for ECE 551 */

#include <stdio.h>
#include <stdlib.h>

int seq2(int x) {
  return (x * (x + 3)) + 1;
}

int sumSeq2(int low, int high) {
  int sumAnswer = 0;

  if (low > high) {
    return 0;
  }

  else if (low == high) {
    return 0;  //not possible to include and exclude the same number
  }

  else {
    for (int i = low; i < high; i++) {
      sumAnswer += seq2(i);  //Compexity is O(n)
    }
  }

  return sumAnswer;
}

int main() {
  /*

  *****************************************************
  Start testing for int seq2(int x)
  *****************************************************

  */

  int answer;

  //test case 1

  answer = seq2(0);
  printf("seq2(%d) = %d\n", 0, answer);

  //test case 2

  answer = seq2(1);
  printf("seq2(%d) = %d\n", 1, answer);

  //test case 3

  answer = seq2(5);
  printf("seq2(%d) = %d\n", 5, answer);

  //test case 4

  answer = seq2(45);
  printf("seq2(%d) = %d\n", 45, answer);

  //test case 5

  answer = seq2(-4);
  printf("seq2(%d) = %d\n", -4, answer);

  //test case 6

  answer = seq2(-20);
  printf("seq2(%d) = %d\n", -20, answer);

  //test case 7

  answer = seq2(-1);
  printf("seq2(%d) = %d\n", -1, answer);

  //test case 8

  answer = seq2(12345);
  printf("seq2(%d) = %d\n", 12345, answer);

  /*

  *****************************************************
  Start testing for int sumSeq2(int high, int low)
  *****************************************************

  */

  int returnAnswer;

  //test case 1
  returnAnswer = sumSeq2(0, 2);
  printf("sumSeq2(%d, %d) = %d\n", 0, 2, returnAnswer);

  //test case 2
  returnAnswer = sumSeq2(3, 6);
  printf("sumSeq2(%d, %d) = %d\n", 3, 6, returnAnswer);

  //test case 3
  returnAnswer = sumSeq2(9, 7);
  printf("sumSeq2(%d, %d) = %d\n", 9, 7, returnAnswer);

  //test case 4
  returnAnswer = sumSeq2(-5, -3);
  printf("sumSeq2(%d, %d) = %d\n", -5, -3, returnAnswer);

  //test case 5
  returnAnswer = sumSeq2(-6, 3);
  printf("sumSeq2(%d, %d) = %d\n", -6, 3, returnAnswer);

  //test case 6
  returnAnswer = sumSeq2(3, 3);
  printf("sumSeq2(%d, %d) = %d\n", 3, 3, returnAnswer);

  //test case 7
  returnAnswer = sumSeq2(2, 3);
  printf("sumSeq2(%d, %d) = %d\n", 2, 3, returnAnswer);

  //test case 8
  returnAnswer = sumSeq2(0, 1);
  printf("sumSeq2(%d, %d) = %d\n", 0, 1, returnAnswer);

  return 0;
}
