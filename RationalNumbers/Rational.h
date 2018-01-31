#ifndef _rational_h
#define _rational_h
#include <iostream>
#include <cstdlib>
#include<cctype>
#include <string>
#include <sstream>
#include <regex>
#include <algorithm>

using namespace std;

// Defining Class Rational
class Rational{
	//private variables and functions
	private:
		int num;   //numerator
		int den;  //denominator
		int gcd(int,int); //function to calculate GCD
	public:
		//public mmeber functions
		Rational(const int& n=0,const int& d=1);
		Rational(const Rational& r);
		Rational& operator=(const Rational& r);
		Rational& operator-=(const Rational& r);
		Rational& operator*=(const Rational& r);
		Rational& operator/=(const Rational& r);
		Rational& operator+=(const Rational& r);
		Rational& operator++();
		Rational& operator--();
		Rational operator++(int);
		Rational operator--(int);
		//friend functions
		friend Rational operator+(const Rational& r1,const Rational& r2);
		friend Rational operator-(const Rational& r1,const Rational& r2);
		friend Rational operator*(const Rational& r1,const Rational& r2);
		friend Rational operator/(const Rational& r1,const Rational& r2);
		friend bool operator==(const Rational& r1,const Rational& r2);
		friend bool operator!=(const Rational& r1,const Rational& r2);
		friend bool operator<(const Rational& r1,const Rational& r2);
		friend bool operator<=(const Rational& r1,const Rational& r2);
		friend bool operator>(const Rational& r1,const Rational& r2);
		friend bool operator>=(const Rational& r1,const Rational& r2);
		friend ostream& operator<<(ostream& os,const Rational& r);
		friend istream& operator>>(istream& is , Rational& r);
};
//prototypes of friend functions
Rational operator+(const Rational& r1,const Rational& r2);
Rational operator-(const Rational& r1,const Rational& r2);
Rational operator*(const Rational& r1,const Rational& r2);
Rational operator/(const Rational& r1,const Rational& r2);
bool operator==(const Rational& r1,const Rational& r2);
bool operator!=(const Rational& r1,const Rational& r2);
bool operator<(const Rational& r1,const Rational& r2);
bool operator<=(const Rational& r1,const Rational& r2);
bool operator>(const Rational& r1,const Rational& r2);
bool operator>=(const Rational& r1,const Rational& r2);
ostream& operator<<(ostream& os,const Rational& r);
istream& operator>>(istream& is , Rational& r);


#endif
