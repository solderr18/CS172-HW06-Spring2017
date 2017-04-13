#include <iostream>
#include <string>
#include "Complex.h"
using namespace std;



int main() {
	Complex c1(2, 2), c2, c3;
	Complex x = c1++;
	c1 - x; //should = 1
	cout << c1;
	cout << "Enter the first complex number: " << endl;
	cin >> c2;
	cout << "Enter the second complex number: " << endl;
	cin >> c3;
	cout << "Plus test -> " << c2 + c3 << endl;
	c2 - c3;
	cout << "Minus test -> " << c2 - c3 << endl;
	c2 * c3;
	cout << "Times test -> " << c2*c3 << endl;
	c2 / c3;
	cout << "Divides test -> " << c2/c3 << endl;
	cout << "abs test -> " << c2.abs() << endl;
	return 0;
}