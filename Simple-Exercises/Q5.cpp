
//Problem5

#include <iostream>
#include <cctype>
using namespace std;

int main() {


	char input;
	cout << "Enter a letter: ";
	cin >> input;
	if (!(isalpha(input))) {
		cout << "YOU DID NOT ENTER A LETTER" << endl;
		return 0;
	}
	input = toupper(input);
	char result;
	if (input != 'Z')
		result = static_cast<char>(input + 1);
	else
		result = 'A';

	cout << "CRYPTO: " << result;
	return 0;

}
