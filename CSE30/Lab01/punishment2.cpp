#include <iostream>
using namespace std;

int main() {
	int loop;
	int typo;
	cout << "Enter the number of lines for the punishment:";
	cin >> loop;
	if (loop >= 0) {
		cout << "Enter the line for which we want to make a typo:";
		cin >> typo;
		if (typo >= 0 && typo <= loop) {
			for (int i = 1; i <= loop; i++) {
				if (i == typo) {
					cout << "I will always use object oriented programing." << endl;
					continue;
				}
				cout << "I will always use object oriented programming." << endl;
			}
		}
		else {
			cout << "You entered an incorrect value for the line typo!" << endl;
		}
	}
	else {
		cout << "You entered an incorrect value for the number of lines!" << endl;
	}
	return 0;
}