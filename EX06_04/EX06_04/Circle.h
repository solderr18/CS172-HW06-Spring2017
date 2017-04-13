#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
using namespace std;

class Circle {
private:
	double radius;
	static int numberOfObjects;
public:
	Circle() {
		radius = 1;
		numberOfObjects++;
	}
	Circle(double r) {
		radius = r;
		numberOfObjects++;
	}
	double getArea() const { return 3.14*radius*radius; }
	double getRadius() const { return radius; }
	void setRadius(double r) { radius = r; }
	static int getNumberOfObjects() { return numberOfObjects; }

	bool operator==(Circle& s) {
		if (s.getRadius() == radius)
			return true;
		else
			return false;
	}
	bool operator>(Circle& s) {
		if (s.getRadius() < radius)
			return true;
		else
			return false;
	}
	bool operator>=(Circle& s) {
		if (s.getRadius() <= radius)
			return true;
		else
			return false;
	}
	bool operator<(Circle& s) {
		if (s.getRadius() > radius)
			return true;
		else
			return false;
	}
	bool operator<=(Circle& s) {
		if (s.getRadius() >= radius)
			return true;
		else
			return false;
	}
	bool operator!=(Circle& s) {
		if (s.getRadius() != radius)
			return true;
		else
			return false;
	}
};
#endif