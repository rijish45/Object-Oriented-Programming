
//Problem3


#include <iostream>
using namespace std;


int main()
{
	int first;
	int second;
	int count = 0;
	cout << "Enter two numbers between 0-100: ";
	cin >> first >> second;  //input from user for the two numbers
	if (first > 100 || first < 0 || second > 100 || second < 0){
		cout << "Please enter valid numbers between 0 and 100." << endl;
		return 0;
	}
	int num1 = first;  //num1 and num2 are declared for cout
	int num2 = second;
	while ((first != 0) || (second!= 0)) //Till both first and second become zero the loop goes on
	{
		int third = first % 3;  //remainder after dividing by 3
		int fourth= second % 3; //remainder after diving by 3
		if (third != fourth)
			count++;           //increase count if condition meets to calculate hamming distance
		first /= 3; //keep on modifying first and second
		second /= 3;
	}

	cout << "Hamming Distance between " << num1  << " " << "and " << num2 << " " << "when the numbers are in ternary format is: " << count << endl;
    return 0;
}
