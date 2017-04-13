#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

int main() {
	//EX06_01 13.1 CREATE A TEXT FILE done
	srand(time(NULL));
	ofstream fout;
	fout.open("Excersize13_1.txt");

	if (fout.fail()) {
		cout << "can't open file" << endl;
		return 0;
	}
	for (int i = 0; i < 100; i++) {
		fout << rand() % 100 << endl;
	}
}