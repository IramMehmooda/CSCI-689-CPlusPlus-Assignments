#ifndef shape_h2
#define shape_h2
#include "Shape.h"   //including header file of abstract class Shape
#include <iostream>
#include <cmath>
#define PI (4*atan(1))  //defining a constant PI
using namespace std;


//Prototype of Rectangle class, this class inherits Shape class
class Rectangle:public Shape{
	//public member functions 
	public:
		Rectangle(const double& l=0.0,const double& w=0.0); //parameterized constructor
		Rectangle(const Rectangle& r); //Copy Constructor
		Rectangle& operator=(const Rectangle& r); //Assigment operator
		Rectangle& operator += (const Rectangle& r); //operator overloading of +=
		~Rectangle(); //Destructor
		double area() const; //Function prototype for calculating the area of rectangle
		double perimeter() const; //Function prototype for calculating the perimeter of rectangle
		void print() const;  //printig the variables of a rectangle
	protected: 
		double width,length;  //variables defining length and width of a rectangle
};
//Prototype of Circle class, this class inherits Shape class
class Circle :public Shape{
	public:
		Circle(const double& rd=0.0);//parameterized constructor
		Circle(const Circle &c);//Copy Constructor
		Circle& operator=(const Circle &c);//Assigment operator
		Circle& operator+=(const Circle &c);//operator overloading of 
		~Circle();//Destructor
		double area () const;//Function prototype for calculating the area
		double perimeter() const;//Function prototype for calculating the perimete
		void print() const;//printig the variables
	protected:
		double radius;//variables defining radius of a cricle

};
//Prototype of Triangle class, this class inherits Shape class
class Triangle :public Shape{
	public:
		Triangle(const double& a1=0.0,b1=0.0,c1=0.0);//parameterized constructor
		Triangle(const Triangle &t);//Copy Constructor
		Triangle& operator=(const Triangle &t);//Assigment operator
		Triangle& operator+=(const Triangle &t);//operator overloading
		~Triangle();//Destructor
		double area() const;//Function prototype for calculating the area
		double perimeter() const;//Function prototype for calculating the perimeter
		void print() const;//printig the variables
	protected:
		double a,b,c;//variables defining radius of a cricle
};
//Prototype of Square class, this class inherits Rectangle class
class Square :public Rectangle{
	public:
		Square(const double& s=0.0);//parameterized constructor
		~Square();//Destructor
		void print() const;//printig the variable
};
//Prototype of right angled triangle class, this class inherits Triangle class
class rightTriangle :public Triangle{
	public:
		rightTriangle(const double& a1=0.0,const double& b1=0.0);//parameterized constructor
		~rightTriangle();//Destructor
		void print() const;//printig the variable
};
//Prototype of equilateral triangle class, this class inherits Triangle class
class equTriangle: public Triangle{
	public:
		equTriangle(const double& a1=0.0);//parameterized constructor
		~equTriangle();//Destructor
		void print() const;//printig the variable
};
#endif //ending the if condition of header



		




