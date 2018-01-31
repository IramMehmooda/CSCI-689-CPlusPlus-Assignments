/*------------------------------------------------------------------------------
 *COurse : CSCI 689                                          Assignment No.10
  Author: Iram Mehmooda                                      ZID: Z1818371
  Program: Shape                                             Source File No.2
 * -----------------------------------------------------------------------------*/
#include "/home/cs689/progs/17f/p10/Shape2.h"//including header file 2

/*---------------------------------------------------------------------------
 *Class: Rectangle
  Base class: Shape
  Purpose: Calculates the area and perimeter of a rectangle and prints its variables
 * --------------------------------------------------------------------------*/

Rectangle :: Rectangle ( const double& l, const double& w ):length(l),width(w){}

Rectangle :: Rectangle ( const Rectangle& r ){copy(r);}

void Rectangle::copy(const Rectangle& r){
	length=r.length;
	width=r.width;
}


Rectangle& Rectangle::operator=(const Rectangle &r){
	 if(this!=&r){
		 length=r.length;
		 width=r.width;
	 }
	 return *this;
}

Rectangle& Rectangle::operator+=(const Rectangle &r){
	length+=r.length;
	width=r.width;
	return *this;
}

Rectangle::~Rectangle(){}

double Rectangle::area() const{
	double area= length*width;
	return area;
}

double Rectangle::perimeter() const{
	double perimeter=2*(length+width);
	return perimeter;
}

void Rectangle::print() const{
	cout << "length = " << length << " : width = " << width;
}

/*---------------------------------------------------------------------------
 Class: Circle
 Base class: Shape
 Purpose: Calculates the area and perimeter of a circle and prints its variables
 * --------------------------------------------------------------------------*/

Circle::Circle(const double& r):radius(r){}

Circle::Circle(const Circle &c){copy(c);}

void Circle::copy(const Circle& c){
	radius=c.radius;
}


Circle& Circle::operator=(const Circle &c){
	if(this!=&c){
		radius=c.radius;
	}
	return *this;
}

Circle& Circle::operator+=(const Circle &c){
	radius+=c.radius;
	return *this;
}

Circle::~Circle(){}

double Circle::area() const{
	double area=PI*radius*radius;
	return area;
}

double Circle::perimeter() const{
	double perimeter=2*PI*radius;
	return perimeter;
}

void Circle::print() const{
	cout << "radius = " << radius;
}
/*---------------------------------------------------------------------------
 Class: Triangle
 Base class: Shape
 Purpose: Calculates the area and perimeter of a triangle and prints its variables
  --------------------------------------------------------------------------*/

Triangle::Triangle(const double& a1,const double& b1,const double& c1){
	a=a1;
	b=b1;
	c=c1;
}

void Triangle::copy(const Triangle& t){
	a=t.a;
	b=t.b;
	c=t.c;
}


Triangle::Triangle(const Triangle &t){copy(t);}

Triangle& Triangle::operator=(const Triangle &t){
	if(this!=&t){
		a=t.a;
		b=t.b;
		c=t.c;
	}
	return *this;
}

Triangle& Triangle::operator+=(const Triangle &t){
	a+=t.a;
	b+=t.b;
	c+=t.c;
	return *this;
}

Triangle::~Triangle(){}

double Triangle::area() const{
	double s= (a + b + c)*0.5;
	double area=sqrt(s*(s-a)*(s-b)*(s-c));
	return area;
	
}

double Triangle::perimeter() const{
	double perimeter =a + b + c;
	return perimeter;
}

void Triangle::print() const{
	cout << "a = " << a << " : b = " << b << " : c = " << c;
}

/*---------------------------------------------------------------------------
 Class: Square
 Base class: Rectangle
 Purpose: Inherits methods from Rectangle class for calculating the area and 
          perimeter of a rectangle and also prints the length of its side
 --------------------------------------------------------------------------*/
Square::Square(const double& s) :Rectangle(s, s){}

Square::Square(const Square& sq):Rectangle(sq){}

Square& Square::operator=(const Square &sq){
	        Rectangle::operator=(sq);
		        return *this;
}

Square& Square::operator+=(const Square &sq){
	                Rectangle::operator+=(sq);
			                        return *this;
}



Square::~Square(){}
void Square::print ( ) const{
	cout<<"length = "<<length;
}
/*---------------------------------------------------------------------------
 Class: rightTriangle
 Base class: Triangle
 Purpose: Inherits methods from Triangle class for calculating the area and
          perimeter and also prints its variables
 --------------------------------------------------------------------------*/
rightTriangle::rightTriangle(const double& a1, const double& b1):Triangle(a1,b1,sqrt((a1*a1)+(b1*b1))){
	//a=a1;
        //b=b1;
        //c=sqrt((a1*a1)+(b1*b1));
}
rightTriangle::rightTriangle(const rightTriangle& r):Triangle(r){}

rightTriangle& rightTriangle::operator=(const rightTriangle &t){
	Triangle::operator=(t);
	return *this;
}

rightTriangle& rightTriangle::operator+=(const rightTriangle &t){
	        Triangle::operator+=(t);
		        return *this;
}


void rightTriangle::print() const{
	cout <<"length = " << a << " : height = " << b;
}
rightTriangle::~rightTriangle(){}
/*---------------------------------------------------------------------------
 Class: equTriangle
 Base class: Triangle
 Purpose: Inherits methods from Triangle class for calculating the area and
            perimeter and also prints its variables
 --------------------------------------------------------------------------*/


equTriangle::equTriangle(const double& a1):Triangle(a1,a1,a1){
	//a=a1;
	//b=a1;
	//c=a1;
}

equTriangle::equTriangle(const equTriangle& e):Triangle(e){
	//a=e.a;
	//b=e.a;
	//c=e.a;
}

equTriangle& equTriangle::operator=(const equTriangle &t){
	        Triangle::operator=(t);
		        return *this;
}

equTriangle& equTriangle::operator+=(const equTriangle &t){
	                Triangle::operator+=(t);
			                        return *this;
}

void equTriangle::print() const{
	cout <<"length = " << a;
}
equTriangle::~equTriangle(){}
       





	
