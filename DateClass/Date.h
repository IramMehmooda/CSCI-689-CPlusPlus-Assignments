#ifndef _Date_h
#define _Date_h
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#define MONTH "January"
#define DAY 1
#define YEAR 2000
#define YE 1
using namespace std;

string intToString(const int&); //non-member function
//unsigned dateDiff(const Date&,const Date&);//non-member function
//Creating a Date class
class Date{
	//declaring all variables required variables
	string month;
	int day,year;
	int monthIndex() const;
	vector<string> months{ "January","February","March","April","May","June","July","August","September","October","November","December" }; //declaring months vector to use in isValidMonth function
	//function prototypes of all private member functions
	bool isValidMonth() const;
	int daysInMonth(const string& ) const;
	bool isLeapYear() const;
	//function prototypes of all public member functions
	public:
		Date(const string& m=MONTH,const int&d=DAY,const int& y=YEAR);    //constructor of Date class
		Date(const Date& d);//copy constructor
		Date& operator=(const Date& d);//operator overloading
		//setter methods
		void setMonth(const string&);
		void setDay(const int&);
		void setYear(const int&);
		//getter methods
		string getMonth() const;
		int getDay() const;
		int getYear() const;
		//other public member functions
		void Month();
		bool isValidDate() const;
		string toString() const;
		Date& addDay(const int&);
		Date& addMonth(const int&);
		Date& addYear(const int&);
		int dayIndex() const;
		//function prototypes of non-member friend functions
		friend istream& operator>>(istream& is, Date& d);
		friend ostream& operator<<(ostream& os, const Date& d);


};

istream& operator>>(istream&, Date&);
ostream& operator<<(ostream&, const Date&);
unsigned dateDiff(const Date&,const Date&);//non-member function
#endif
