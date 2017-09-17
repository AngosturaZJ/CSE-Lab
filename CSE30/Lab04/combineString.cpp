#include <iostream>
#include <string>
using namespace std;

string combineStr(string input, int repeat){
	string result;
	if (repeat > 0){
		// use for loop to repeat string
 		for (int i = 0; i < repeat; i++){
			result += input;
		}
	}
	return result;
}

int main(){
	string input; // original string
	int repeat; // numbers of time user want to repeat
	cout << "Enter a string: ";
	cin >> input;
	cout << "Enter a number of times: ";
	cin >> repeat;
	// check for correct number
	if (repeat < 0){
		cout << "Please enter the correct number!" << endl;
	}else if (repeat == 0){
		cout << "" << endl;
	}else{
 		cout << "The resulting string is: " << combineStr(input, repeat)  << endl;
	}
	return 0;
}
