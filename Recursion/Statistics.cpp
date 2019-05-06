#include <iostream>
#include "Statistics.h"

using namespace std;

float getMean(int array [], int size) {
  float sum = 0;

for (int i = 0; i < size; i++){
    sum+=array[i];
  }
float mean = (sum/size);
return mean;
}


float squareRoot(float number)
{
const float ACCURACY=0.001;
float lower, upper, guess;

 if (number < 1)
 {
  lower = number;
  upper = 1;
 }
 else
 {
  lower = 1;
  upper = number;
 }

 while ((upper-lower) > ACCURACY)
 {
  guess = (lower + upper)/2;
  if(guess*guess > number)
   upper = guess;
  else
   lower = guess;
 }
 return (lower + upper)/2;

}



float getStDev(int array[], int size)
{
  float total=0;
  float x;
  float mean = getMean(array,size);

  for (int i = 0; i < size ; i++)
    {
      x = (array[i] - mean);
      total += x*x;
    }

  x = (total/size);

  return squareRoot(x);

}
