#ifndef _prog9_h
#define _prog9_h
#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;
//#include <string>
void process_token ( const string& token, stack < double >& S );
bool unarySign ( const char& c, const string& token, const unsigned& i );
bool floatPoint ( const char& c, const string& token, const unsigned& i );
double getNumber ( const char& c, const string& token, unsigned& i, const bool& floatPointFlag );
bool isValidOperator ( const char& c );
double operation ( const char& c, const double& x, const double& y );
double popStack ( stack < double >& S );
void printResult ( const stack < double >& S );
void emptyStack ( stack < double >& S );
double stringToDouble( string );
#endif
