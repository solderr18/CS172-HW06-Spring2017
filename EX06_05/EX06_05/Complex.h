#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
	double real;
	double imaginary;
public:
	Complex() {
		real = 0;
		imaginary = 0;
	}
	Complex(double a) {
		real = a;
		imaginary = 0;
	}
	Complex(double a, double b) {
		real = a;
		imaginary = b;
	}
	double getReal() const { return real; }
	double getImaginary() const { return imaginary; }

	Complex add(const Complex& s) const {
		double a = real + s.getReal(); //(re+sRe) + i (im + sIm) order doesnt matter w +
		double b = imaginary + s.getImaginary();
		return Complex(a, b);
	}

	Complex& Complex:: operator+=(const Complex& s) {
		*this = add(s);//pointer back to obj s
		return *this;
	}

	Complex minus(const Complex& s) const { //(r-sR) + i(im - sIm) something MINUS class S
		double a = real - s.getReal();
		double b = imaginary - s.getImaginary();
		return Complex(a, b);
	}
	Complex& Complex:: operator-=(const Complex& s) {
		*this = minus(s);
		return *this;
	}

	Complex times(const Complex& s) const {//( re*sR - im*sI) + i(im*sR + re*sI)  
		double a = real*s.getReal() - imaginary*s.getImaginary();
		double b = imaginary*s.getReal() + real*s.getImaginary();
		return Complex(a, b);
	}
	Complex& Complex:: operator*=(const Complex& s) {
		*this = times(s);
		return *this;
	}

	Complex divide(const Complex& s) const {//( re*sR + im*sI)/(s.Re^2 + s.Im^2) + i (im*sR - re*sI)/(s.Re^2 + s.Im^2)  
		double denom = s.getReal()*s.getReal() + s.getImaginary()*s.getImaginary(); //denominator. to declutter code
		double a = (real*s.getReal() + imaginary*s.getImaginary()) / denom;
		double b = (imaginary*s.getReal() - real*s.getImaginary()) / denom;
		return Complex(a, b);
	}
	Complex& Complex:: operator/=(const Complex& s) {
		*this = divide(s);
		return *this;
	}

	double abs() const {
		return (sqrt(real *real + imaginary*imaginary));
	}

	double & Complex:: operator[](int index) {
		if (index == 0)
			return real;
		else
			return imaginary;
	} // put in [0] will retur real component, anything else will return imaginary comp


	Complex& Complex:: operator++(int variable) { //postfix
		Complex temp = *this;
		*this = add(1);//pointer back to obj s
		return temp;
	}
	Complex& Complex:: operator--(int variable) { //postfix
		Complex temp = *this;
		*this = minus(1);//pointer back to obj s
		return temp;
	}

	Complex & Complex:: operator++() { //preffix
		real++;
		return *this;
	}
	Complex & Complex:: operator--() { //preffix
		real--;
		return *this;
	}
	string toStringFxn() {
		if (imaginary != 0)
			return (to_string(real + '+  i' + imaginary));
		else //if im(Z) = 0, just return Re comp
			return (to_string(real));
	}

	friend istream& operator >> (istream&, Complex&s);
};
Complex operator+(const Complex&s1, const Complex&s2) { //s1 + s2
	return s1.add(s2);
}
Complex operator-(const Complex&s1, const Complex&s2) { // s1 - s2
	return s1.minus(s2);
}
Complex operator*(const Complex&s1, const Complex&s2) { // s1*s2
	return s1.times(s2);
}
Complex operator/(const Complex&s1, const Complex&s2) { // (s1/s2)
	return s1.divide(s2);
}

ostream& operator<<(ostream & out, const Complex& s) { 
	if (s.getImaginary() == 0)
		out << s.getReal(); //??????
	else
		out << s.getReal() << " + " << s.getImaginary() << "i" << endl;
	return out;
}

istream& operator >> (istream & in, Complex& s) { 
	cout << "Real comp: ";
	in >> s.real; 
	cout << "Im comp: ";
	in >> s.imaginary;
	return in;
}

#endif