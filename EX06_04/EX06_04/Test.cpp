#include <iostream>
#include "Circle.h"
using namespace std;

int Circle::numberOfObjects = 0;

int main() {
	Circle s1(5), s2(3), s3, s4(6), s5(1);
	cout << "s1 rad 5, s2 rad3, s3 rad1, s4 rad 6";
	cout << "circle 1 has radius " << s1.getRadius() << endl;
	cout << "s1 and s2 == operator test" << endl;
	cout << "s1 = s2?? " << boolalpha << (s1 == s2) << endl;
	cout  << "s1 and s2 > operator test" << endl;
	cout << s1.getRadius() << " > " << s2.getRadius() << " ? " << (s1 > s2) << endl;
	cout << "s3 and s2 < operator test" << endl;
	cout << s3.getRadius() << " < " << s2.getRadius() << " ? " << (s3 < s2) << endl;
	cout << "s4 and s2 >= operator test" << endl;
	cout << s4.getRadius() << " >= " << s2.getRadius() << " ? " << (s4 >= s2) << endl;
	cout << "s3 and s5 <= operator test" << endl;
	cout << s3.getRadius() << " <= " << s5.getRadius() << " ? " << (s3 > s5) << endl;
	return 0;
}