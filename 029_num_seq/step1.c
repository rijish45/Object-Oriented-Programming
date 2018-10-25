// This file is for Step 1.
// You should do
//  Step 1 (A): write seq1
//  Step 1 (B): write main to test seq1
//  Step 1 (C): write printSeq1Range
//  Step 1 (D): add test cases to main to test printSeq1Range
//
// Be sure to #include any header files you need!

/*
 The assignment is the individual effort
 of Rijish Ganguly for ECE 551

 */

#include <stdio.h>
#include <stdlib.h>

int seq1(int x) {
  if (x == 0)
    return -3;
  else
    return -3 + 4 * x;
}

void printSeq1Range(int low, int high) {
  if (high == low || high < low) {
    printf("\n");
  }

  //special case I found during testing
  else if (high - low == 1) {
    int answer = seq1(low);
    printf("%d\n", answer);
  }

  else {
    int printNum = seq1(low);
    printf("%d, ", printNum);

    for (int i = low + 1; i < high; i++) {
      if (i != high - 1) {
        printNum += 4;
        printf("%d, ", printNum);
      }

      else {
        printNum += 4;
        printf("%d\n", printNum);
      }
    }
  }
}

int main() {
  /* 
   
   *******************************************************
   Start testing for int seq1(int x)
   *******************************************************
  
  */

  int answer;
  //test case 1
  answer = seq1(0);
  printf("seq1(%d) = %d\n", 0, answer);

  //test case 2
  answer = seq1(1);
  printf("seq1(%d) = %d\n", 1, answer);

  //test case 3
  answer = seq1(-1);
  printf("seq1(%d) = %d\n", -1, answer);

  //test case 4
  answer = seq1(-4);
  printf("seq1(%d) = %d\n", -4, answer);

  //test case 5
  answer = seq1(345);
  printf("seq1(%d) = %d\n", 345, answer);

  //test case 6
  answer = seq1(-1234);
  printf("seq1(%d) = %d\n", -1234, answer);

  answer = seq1(3245);
  printf("seq1(%d) = %d\n", 3245, answer);

  /*
   ********************************************************
   Start testing for void printSeq1Range(int high, int low)
   ********************************************************
  */

  //test case 1
  printf("printSeq1Range(%d, %d)\n", 0, 4);
  printSeq1Range(0, 4);

  //test case 2
  printf("printSeq1Range(%d, %d)\n", -3, 2);
  printSeq1Range(-3, 2);

  //test case 3
  printf("printSeq1Range(%d, %d)\n", 0, 0);
  printSeq1Range(0, 0);

  //test case 4
  printf("printSeq1Range(%d, %d)\n", 3, 1);
  printSeq1Range(3, 1);

  //test case 5
  printf("printSeq1Range(%d, %d)\n", -6, 6);
  printSeq1Range(-6, 6);

  //test case 6
  printf("printSeq1Range(%d, %d)\n", 1, 7);
  printSeq1Range(1, 7);

  //test case 7
  printf("printSeq1Range(%d, %d)\n", -3, 0);
  printSeq1Range(-3, 0);

  //test case 8
  printf("printSeq1Range(%d, %d)\n", 1, 2);
  printSeq1Range(1, 2);

  //test case 9
  printf("printSeq1Range(%d, %d)\n", 3, -4);
  printSeq1Range(3, -4);

  //test case 10
  printf("printSeq1Range(%d, %d)\n", -6, -1);
  printSeq1Range(-6, -1);

  //test case 11
  printf("printSeq1Range(%d, %d)\n", -4, -3);
  printSeq1Range(-4, -3);

  return 0;
}
