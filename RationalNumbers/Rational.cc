/*-----------------------------------------------------------
 * Course : CSCI 689                Assignment :08
 * Author: Iram Mehmooda            ZID : Z1818371
 * Program : Rational numbers
 * ----------------------------------------------------------
*/
#include "Rational.h"    //including header file


/*---------------------------------------------------------
 * parameterized constructor
 *-------------------------------------------------------
 *  */
Rational::Rational(const int& n,const int& d):num(n),den(d){
	if(d==0)
		cerr<<"Error: division by zero";
	
	else{
		int g=gcd(abs(n),abs(d));  //calling gcd function
		num=n/g;
		den=d/g;
		if(d<0){
			num=-num;
			den=-den;}
		
	}
}

/*------------------------------------------------------
 * copy constructor
---------------------------------------------------------*/
Rational::Rational(const Rational& r):num(r.num),den(r.den){}

/*---------------------------------------------------------
 * Assignment operator
------------------------------------------------------------
*/
Rational& Rational::operator=(const Rational& r){
	if(this!=&r){
		num=r.num;
		den=r.den;
	}
	return *this;
}
/*--------------------------------------------------------
 * Function that returns gcd of two denomerators
----------------------------------------------------------*/
int Rational::gcd(int x,int y){
	int r=x%y;
	while(r!=0){
		x=y;
		y=r;
		r=x%y;
	}
	return y;
}
/*------------------------------------------------
 * Function to overload += operator
--------------------------------------------------*/
Rational& Rational::operator+=(const Rational& r){
	num=(num*(r.den))+(den*r.num);
	den=den*r.den;
	int g=gcd(abs(num),abs(den));
	num/=g;
	den/=g;
	return *this;
}
/*-----------------------------------------------
 * Function to overload -= operator
 * ---------------------------------------------*/
Rational& Rational::operator-=(const Rational& r){
	num=(num*(r.den))-(den*r.num);
	den=den*(r.den);
	int g=gcd(abs(num),abs(den));
	num/=g;
	den/=g;
	return *this;
	 
}
/*------------------------------------------------
 *Function to overload *= operator
 * -----------------------------------------------*/
Rational& Rational::operator*=(const Rational& r){
	num=num*(r.num);
	den=den*(r.den);
	int g=gcd(abs(num),abs(den));
	num/=g;
	den/=g;
	return *this;

}
/*------------------------------------------------
 *Function to overload /= operator
 * ----------------------------------------------*/
Rational& Rational::operator/=(const Rational& r){
	num=num*(r.den);
	den=den*(r.num);
	int g=gcd(abs(num),abs(den));
	num/=g;
	den/=g;
	return *this;

}
/*------------------------------------------------
 * Function to overload pre-increment operator
 * -----------------------------------------------*/ 
Rational& Rational::operator++(){
	num=num+den;
	return *this;
}
/*------------------------------------------------
 *Function to overload pre-decrement operator
 * ----------------------------------------------*/
Rational& Rational::operator--(){
	num=num-den;
	return *this;
}
/*-----------------------------------------------
 * Function to overload post-increment operator
 * --------------------------------------------- */
Rational Rational::operator++(int unused){
	unused=0;
	Rational i(num,den);
	num=num+den+unused;
	return i;
}
/*----------------------------------------------
 *Function to overload post-decrement operator
 *---------------------------------------------*/
Rational Rational::operator--(int unused){
	 unused=0;
	 Rational i(num,den);
	 num=num-den+unused;
	 return i;
}
/*------------------------------------------------------
 *Function to overload + operator
 * -----------------------------------------------------*/
Rational operator+(const Rational& r1,const Rational& r2){
	return Rational(r1.num*r2.den+r2.num*r1.den,r1.den*r2.den);
}
/*------------------------------------------------------
 Function to overload - operator
 ------------------------------------------------------*/
Rational operator-(const Rational& r1,const Rational& r2){
	return Rational((r1.num*r2.den)-(r2.num*r1.den),r1.den*r2.den);
}
/*------------------------------------------------------
 Function to overload * operator
 -------------------------------------------------------*/
Rational operator*(const Rational& r1,const Rational& r2){
	return Rational (r1.num*r2.num,r1.den*r2.den);
}
/*-----------------------------------------------------
  Function to overload / operator
 ------------------------------------------------------ */
Rational operator/(const Rational& r1,const Rational& r2){
	return Rational(r1.num*r2.den,r1.den*r2.num);
}
/*----------------------------------------------------
 Function to overload == operator
 ----------------------------------------------------- */
bool operator==(const Rational& r1,const Rational& r2){
	if(r1.num==r2.num && r1.den==r2.den)
		return true;
	else
		return false;
}
/*-----------------------------------------------------
 Function to overload != operator
 ------------------------------------------------------ */
bool operator!=(const Rational& r1,const Rational& r2){
	if(r1.num==r2.num && r2.den==r1.den)
		return false;
	else
		return true;
}
/*---------------------------------------------------
 * Function to overload < operator
 ----------------------------------------------------*/
bool operator<(const Rational& r1,const Rational& r2){
	if((r1.num*r2.den)<(r2.num*r1.den))
		return true;
	else
		return false;
}
/*----------------------------------------------------
 * Function to overload <= operator
 -----------------------------------------------------*/
bool operator<=(const Rational& r1,const Rational& r2){
	 if((r1.num*r2.den)<=(r2.num*r1.den))
		 return true;
	 else
		 return false;
}
/*---------------------------------------------------
 * Function to overload > operator
 ----------------------------------------------------- */
bool operator>(const Rational& r1,const Rational& r2){
	if((r1.num*r2.den)>(r2.num*r1.den))
		return true;
	else
		return false;
}
/*-----------------------------------------------------
 Function to overload >= operator
 ------------------------------------------------------ */
bool operator>=(const Rational& r1,const Rational& r2){
	if((r1.num*r2.den)>=(r2.num*r1.den))
		return true;
	else
		return false;
}
/*--------------------------------------------------
Function to overload stream insertion operator 
----------------------------------------------------*/
ostream& operator<<(ostream& os, const Rational& r){
	if(r.den==1)
		os<<r.num;
	else if(r.num<0 && r.den<0)
		os<<-r.num<<'/'<<-r.den;
	else
		os<<r.num<<'/'<<r.den;
	return os;
}
/*---------------------------------------------------
 * Function to overload stream extraction operator
  --------------------------------------------------
  */
istream& operator>>(istream& is,  Rational& r){
	string s,s1,s2;
	getline(cin,s);
	size_t position=s.find_first_not_of("/1234567890-\t ");
	if(position==string::npos){
		int c=s.find_first_of('/');
		if(c>0){
			s1=s.substr(0,c-1);
			s2=s.substr(c+1,s.length());
			int d=atoi(s1.c_str());
			int e=atoi(s2.c_str());
			auto s3 = std::regex_replace(s1,std::regex("\\s+"), "");
			auto s4 = std::regex_replace(s2,std::regex("\\s+"), "");
			int x=atoi(s3.c_str());
			int y=atoi(s4.c_str());
			if(d==x && e==y){
				r.num=x;
				r.den=y;
				return is;
			}
			else{
				cout<<"Error: line "<<'"'<<s<<'"'<<" contains invalid number"<<endl;
			}
			
		}
		else{
			auto s5 = std::regex_replace(s,std::regex("\\s+"), "");

			 int f=atoi(s5.c_str());
			 r.num=f;
			 r.den=1;
			
		}
	}
	else{
	
		cout<<"Error: line "<<'"'<<s<<'"'<<" contains invalid number"<<endl;
		
	}
	
	return is;
}



       























	















