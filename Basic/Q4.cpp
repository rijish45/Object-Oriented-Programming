
//Problem4


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int run = 0; // running total


/*overloaded blackJack function takes two input and returns the running total converting the inputs
into their respective values. Integers take their numerical values.
Char 'A' takes numerical value 11 and the other characters takes the value 10. */



//takes two integer
int blackJack (int x, int y){
run+=x+y;
return run;
}

//takes an integer and a character
int blackJack (int x, char y){
  int num;
  if (y=='A'){
    num=11;
  }
  else
  num=10;

  run+=num+x;
  return run;
}

//takes character first and an integer
int blackJack (char x, int y){
  int num;
  if(x=='A'){
    num=11;
  }
  else
  num=10;
  run+=num+y;
  return run;
}

//takes two characters
int blackJack (char x, char y){
  int num1 = 0;
	int num2 = 0;
	if (x == 'A')
	{
		num1 = 11;
	}
	else
  num1=10;

	if (y == 'A')
	{
		num2 = 11;
	}
	else
		num2= 10;

	run+=num1+num2;
	return run;
}

//takes an integer
int blackJack (int x){
  run+=x;
  return run;
}

//takes a character
int blackJack (char x){
  int num;
  if (x == 'A')
	{
		num = 11;
	}
	else
		num = 10;
run+=num;
}



int main(){

  srand(time(0));
  int n1 = 1 + rand()%13;  //produces two random numbers for first double draw
  int n2 = 1 + rand()%13;
  char default1;
  char default2;
  char def;
switch (n1){
  case 1:
          default1='A';  //if numerical value of the draw is 1, it corresponds to A
          break;
  case 11:
          default1='K'; //if numerical value of draw is 11, it corresponds to K
          break;
  case 12:
          default1='Q'; //if numerical value of draw is 12, it corrsponds to Q
          break;
  case 13:
          default1='J'; // if numerical value of draw is 13, it corresponds to J
          break;
  default:
          default1=false; //otherwise default is assigned a false boolean value
}


switch(n2){            //similar to different n1 value scenarios
  case 1:
        default2='A';
        break;
  case 11:
        default2='K';
        break;
  case 12:
        default2='Q';
        break;
  case 13:
        default2='J';
        break;
  default:
        default2=false;
}


//different conditions under which different overloaded blackJack functions are called

if (default1!=false && default2!=false) {
  blackJack(default1,default2);   //both are letters;
}
else if(default1==false && default2==false){
  blackJack(n1,n2);  //both are integers;
}
else if (default1=false && default2!=false){
  blackJack(n1,default2);  //one is letter and one is an integer
}
else
blackJack(default1,n2); //one is letter and one is an integers

cout << "Welcome to EC327 Black Jack" << endl;
cout << "Total: " << run << endl;

char choice;
int random;

while(run < 21) {  //while the run value is less than 21 loop continues
  cout << "Draw Again (y/n): " ;
  cin >> choice;
  if (choice!='y' && choice!='n'){ //if user chooses neither y or n
    cout << "Total: " << run << endl;
    cout << "Error Occured." << endl;
    return 0;
  }
  else if (choice=='y'){
    random = 1 + rand()%13;
    if (random==1){
      def='A';
      blackJack (def);
    }
    else if(random==11){
      def='K';
      blackJack(def);
    }
    else if(random==12){
      def='Q';
      blackJack(def);
      }
    else if (random==13){
      def='J';
      blackJack(def);
    }
    else{
     blackJack(random);
   }
   cout << "Total: " << run << endl;
  }

    else if (choice=='n'){ //if user picks n
    cout << "Total: " << run << endl;
    cout << "You quit with " << run << endl;
    return 0;
  }

}

  if (run==21){  //if run equals to 21
     cout << "WON BLACKJACK" << endl;
     return 0;
    }

  if (run > 21){ //if run is greater than 21
    cout << "FAILED BLACKJACK" << endl;
    return -1;
    }


return 0;
}
