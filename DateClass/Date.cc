/*-----------------------------------------------------------------------
Course: CS689                        Assignment:07
Author: Iram Mehmooda                ZID:Z1818371
Program:The Date Class
-------------------------------------------------------------------------
 */

#include "Date.h" //including header file of Date class
//Implementation of Class Date
//Parameterized constructor with default values 
Date::Date(const string& m,const int& d,const int& y):month(m),day(d),year(y){Month();}
//copy constructor
Date::Date(const Date& d):month(d.month),day(d.day),year(d.year){}
//operator overloading
Date& Date::operator=(const Date& d){
	if(this!=&d){
		month=d.month;
		day=d.day;
		year=d.year;
	}
	return *this;
}
//Implementation of setter methods:
//setting the value of month
void Date::setMonth(const string& m){
	month=m;
	Month();
}
//setting the value of day
void Date::setDay(const int& d){
	day=d;
}
//setting the value of year
void Date::setYear(const int& y){
	year=y;
}
//getter methods
//getting the value of month
string Date::getMonth()const{
	return month;
}
//getting the value of day
int Date::getDay() const{
	return day;
}
//getting the value of year
int Date::getYear() const{
	return year;
}
/*--------------------------------------------------
 *function : Month
 return type: void
 arguments :none
 funnctionality: provide case insensitivity to month
                 of date the entered
 *--------------------------------------------------*/
void Date::Month(){
	month[0]=toupper(month[0]);        //converting the first letter of month to upper case
	for(unsigned i=1;i<month.length();i++){ //converting the remaining letters to lower case
		month[i]=tolower(month[i]);
	}
}
/*--------------------------------------------------
 function : isValidDate
 return type: bool
 arguments : none
 funnctionality: Perfoms validation by calling different
                 functions and returns true if the date
		 is valid 
 --------------------------------------------------*/

bool Date::isValidDate() const{
	bool valid;
	if(isValidMonth()){              //checking if the month is valid
		int daysMonth=daysInMonth(month);
		//cout<< daysMonth<<endl;
		if(day>0 && day<=daysMonth && (year > 0||year<0)){          //checking if the month is valid
		           //checking if the year is valid
				valid=true;   //setting the value of boolean valid to true if all conditions are met
			
		}
	}
	
	else{
		valid=false;
	}
	return valid;
}
/*--------------------------------------------------
 function : toString
 return type: string
 arguments :none
 funnctionality: convert the date entered to the given 
                 format
 *--------------------------------------------------*/

string Date::toString() const{
	string dd=intToString(day);
	string yyyy=intToString(year);
	string mmm=month.substr(0,3);
	string fullDate=dd+"-"+mmm+"-"+yyyy;
	return fullDate;

}
/*--------------------------------------------------
 function : isValidMonth
 return type: bool
 arguments :none
 functionality: checking if the month is valid
 -------------------------------------------------*/

bool Date::isValidMonth()const{
	bool validMonth=false;
	for(unsigned i=0;i<months.size();i++){ //iterating through the vector months 
		if(months[i]==month){  //checking if the month entered is equal to any of the month in months vector
			validMonth=true;
		}
	}
	return validMonth;
}
/*--------------------------------------------------
 function : daysInMonth
 return type: int
 arguments : string
 funnctionality: providing the number of days in a month
 ---------------------------------------------------*/

int Date::daysInMonth(const string& m) const{
	int days;
	if(m=="April"||m=="June"||m=="September"||m=="November"){                         
			days=30;
	}
	else if(m== "February"){
			if(isLeapYear()==true){
				days=29;    //calling method isLeapYear to check if the year is a leap year
			}
			else{
				days=28;
			}
	}
	else{
		days=31;
	}
	return days;
}

/*--------------------------------------------------
 function : isLeapYear
 return type: bool
 arguments :none
 functionality: checking if entered year is a leap year
 -------------------------------------------------*/

bool Date::isLeapYear()const{
	bool validYear=false;
	if(((year%4==0) && (year%100!=0)) || (year%400==0)) //condition for a leap year
		validYear=true;
	return validYear;
}

/*----------------------------------------------------
  Function to convert integer to string
  Argumnents  :integer
  return type : String
  ----------------------------------------------------
*/
string intToString(const int& n){
	string dateAndYear=to_string(n);
	return dateAndYear;
	}
/*---------------------------------------------------
  Function to overload >> operator
  Argumnents  :istream and Date object
  return type :istream
 ----------------------------------------------------*/

istream& operator>>(istream& is,Date& d){
	is>>d.month;
	is>>d.day;
	char c;
	is>>c;
	if(isdigit(c)){
		is.unget();
	}
	is>>d.year;
	return is;
	
}
/*---------------------------------------------------
  Function to overload << operator
  Argumnents  :ostream and Date object
  return type :ostream
-----------------------------------------------------*/

ostream& operator<<(ostream& os,const Date& d){
	os<<d.month<<" "<<d.day<<", "<<d.year;
	return os;
}
/*Function to add number of days
  Arguments : integr of number of days to be added
  return type:Date object
 */
Date& Date::addDay(const int& n){
	day+=n;
	//cout<<" D 1 Day = " << day<<endl;
	
	if(day>daysInMonth(month)){
		while(day>daysInMonth(month)){
			day-=daysInMonth(month);
			if(months[11]==month){
				month=months[0];
				year+=1;
			}
			else{
				//for(unsigned i=0;i<months.size();i++){
				//	if(months[i]==month)
				int i=monthIndex();
				month=months[i+1];
				
			} 
		}
	}
	else if(day<1){
	//	int d;
		while(day<=0){

			if(month==months[0]){
				month=months[11];
				year-=1;
			}
			else{
				//for(int j=months.size()-1;j>0;j--){
				//	if(months[j]==month)
				int j=monthIndex();
				month=months[j-1];
				}
			
			day=daysInMonth(month)+day;
			}
		//day=d;
	}
	
	return *this;
}
/*Function to add number of months
  Arguments : integr of number of months to be added
  return type:Date object
 */

Date& Date::addMonth(const int& n){
	int m=n%12;
	int yearAdded=n/12;
	year+=yearAdded;
	if(n>0){
		int i=monthIndex();
		for(int count=1;count<=m;count++){
			if(i==11){
				month=months[0];
				year+=1;
			}
			else
				month=months[i];
		}
		/*for(unsigned i=0;i<months.size();i++){
			if(months[i]==month){
				for(int count=1;count<=m;count++){
					//month=month[i+1];
					if(month==months[11]){
						month=months[0];
						year+=1;
					}
					else
						 month=months[i+1];
				}
			}
			
		}*/
		//addYear(yearAdded);
		//year+=yearAdded;
		if(day>daysInMonth(month)){
			month=months[i+1];
			day=day-daysInMonth(month);
		}
	}
	else if(n<0){
		int i=monthIndex();
		for(int count=-1;count>=m;count--){
			if(month==months[0]){
				month=months[11];
				year-=1;
			}
			else
				month=months[i-1];
		}
		/*
		for(unsigned i=0;i<months.size();i++){
			if(months[i]==month){
				for(int count=-1;count>=m;count--){
					if(month==months[0]){
							month=months[11];
							year-=1;
					}
					else
						month=months[i-1];
				}
			}
		}*/
		if(day>daysInMonth(month)){
			month=months[i-1];
			day=daysInMonth(month)-(day-daysInMonth(month));
		//addYear(yearAdded);
		//year-=yearAdded;
		}

	}

	return *this;
}
/*Function to add number of years
  Arguments : integr of number of years to be added
  return type:Date object
 */
Date& Date::addYear(const int& n){
	if(n==0)
		year=year;
	/*else if(year>0 && n>0)
		year+=n;
	else if(year<0 && n<0)
		year-=n;
	else if(year>0 && n<0){
		if((year-n)>0)
			year+=n;
		else
			year=year+n-1;
	}		
	else if(year<0 && n>0){
		if((n-year)<0){
			year=year+n+1;
	}
	if(month==months[1] && day==29 && isLeapYear()==0){
		day=1;
		month=months[2];
	}*/
	else if((year>0 && n>0) || (year<0 && n<0))
		year+=n;
	else if(year>0 && n<0){
		int y=year+n;
		if(y<=0)
			year=year+n-1;
		else
			year+=n;
	}
	else if(year<0 && n>0){
		int y=year+n;
		if(y>=0)
			year=year+n+1;
		else
			year+=n;
	}
	if(day>daysInMonth(month)){
		int i=monthIndex();
		if(n>0){
			//int i=monthIndex();
			month=months[i+1];
			day=1;
		}

		else{
			month=months[i-1];
			day=daysInMonth(month);
		}
	}


	return *this;
}
/*Function to find day index
  Arguments : none
  return type: integer
 */
int Date::dayIndex()const{
	int index =0;
	int temp = monthIndex();
	if(year==YE){
		//int temp = monthIndex();
		cout<<" Month index "<<temp<<endl;
		for(int i=0;i<=temp;i++){
			if(months[i]!=month){
				index+=daysInMonth(month);
				 }
			 else{
				 index+=day;
				  }
		}
	}
	else if(year>YE){
		for(int y=1;y<=year;y++){
			if(y!=year){
				for(unsigned i=0;i<months.size();i++){
						index+=daysInMonth(months[i]);
				}
			
	
				//cout<<"Index of : 1 "<<index<<endl;
			}
			else if(y==year){
				for(int i=0;i<=temp;i++){
					if(months[i]!=month){
						index+=daysInMonth(month);
					}
					else{
						index+=day;
					}
					 //cout<<"Index of : 2 "<<index<<endl;

				}
			}
		}
		//index=year*index;
		}
	else if(year<=-1){
		int temp;

		for(int y=-1;y>=year;y--){
			if(y!=year){
				for(int i=months.size()-1;i>=0;i--){
					index-=daysInMonth(months[i]);
				}
			}
			else if(y==year){
				for(int i=months.size()-1;i>=temp;i--){
					if(months[i]!=month){
						index-=daysInMonth(months[i]);
					}
					else{
						index=index-(daysInMonth(months[i])-day);
					}
				}
			}
		}
	}
	return index;
}
/*Function to find month index
  Arguments : none
  return type: integer
 */

int Date::monthIndex() const{
	int d;
	for(unsigned i=0;i<months.size();i++){
		if(months[i]==month)
			d=i;
	}
	return d;
}
/*Function to find day index
 *   Arguments : none
 *     return type: integer
  */
unsigned dateDiff( const Date& d1, const Date& d2){
	long i=d1.dayIndex();
	long j=d2.dayIndex();
	cout<< "i = " <<i <<" j = "<<j;
	long k;
	if((i>0 && j>0) ||(i<0 && j<0)){
		if(i<j){
			k=j-i;
			cout<<" k is "<<k<<endl;
		}
		else if(i>j){
			k=i-j;
		}
	}
	else if(i<0 && j>0){
		k=j-i-1;
	}
	else if(i>0 && j<0){
		k=i-j-1;
	}
	else if(i==j){
		k=0;
	}
	return k; 
}

	
















