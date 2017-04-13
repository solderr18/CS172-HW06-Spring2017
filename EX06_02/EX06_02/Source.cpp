#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	string filename;
	cout << "Enter file name" << endl;
	cin >> filename;
	fstream file;
	file.open(filename, ios::in); //input
	if (file.fail()) {
		cout << "can't open file" << endl;
		return 0;
	}
	char character;
	int count = 0;
	while (file >> character) {
		count++;
	}
	cout << "Number of Characters: " << count << endl;
}