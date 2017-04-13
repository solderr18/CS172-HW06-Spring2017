#include <iostream>
#include <string>
#include "Complex.h"
using namespace std;



int main() {
	Complex c1(2, 2), c2;
	Complex x = c1++;
	c1 - x; //should = 1
	cout << c1;

	cin >> c2;

	return 0;
}