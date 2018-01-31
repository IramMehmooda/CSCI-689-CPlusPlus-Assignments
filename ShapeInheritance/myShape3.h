#ifndef shape_h3
#define shape_h3
#include "Shape.h" //including header file of abstract class Shape 
#include "Shape2.h" //including header file of Shape2 
//#include <iostream>
//#include <cmath>
using namespace std;
/*-------------------------------------------------------------------------
 Class: Cube
 Base Class: Square
 Purpose: Inherits functions of Square class and calculates area, perimeter
          and volume of Cube by inheriting specific funcions of Square Class.
	  It also prints the varibales of a Cube.
*------------------------------------------------------------------------*/
class Cube :public Square{
	public:
		Cube(const double& s=0.0);
		double area() const;
		double perimeter()const;
		double volume() const;
		void print() const;
		~Cube();
};
/*-------------------------------------------------------------------------
  Class: Box
  Base Class: Rectangle
  Purpose: Inherits functions of Rectangle class and calculates area, perimeter
           and volume of Box by inheriting specific funcions of Rectangle Class.
           It also prints the varibales of a Box.
 *------------------------------------------------------------------------*/
class Box :public Rectangle{
	public:
		Box(const double& l=0.0, const double& w=0.0,const double& h=0.0);
		double area() const;
		double perimeter()const;
		double volume() const;
		void print() const;
		~Box();
	private:
		double height;
};
/*-------------------------------------------------------------------------
 Class: Cylinder
 Base Class: Circle
 Purpose: Inherits functions of Circle class and calculates area, perimeter
          and volume of Cyclinder by inheriting specific funcions of Circle Class.
          It also prints the varibales of a Cylinder.
 *------------------------------------------------------------------------*/
class Cylinder :public Circle{
	public:
		Cylinder(const double& r=0.0,const double& h=0.0);
		double area() const;
		double perimeter()const;
		double volume() const;
		void print() const;
		~Cylinder();
	private:
		double height;

};
/*-------------------------------------------------------------------------
 Class: Cone
 Base Class: Circle
 Purpose: Inherits functions of Circle class and calculates area, perimeter
          and volume of Cone by inheriting specific funcions of Circle Class.
          It also prints the varibales of a Cone.
 *------------------------------------------------------------------------*/

class Cone :public Circle{
	public:
		Cone(const double& r=0.0,const  double& h=0.0);
		Cone& operator=(const Cone &c);
		Cone& operator+=(const Cone &c);
		double area() const;
		double perimeter()const;
		double volume() const;
		void print() const;
		~Cone();
	private:
		double height;
};
/*-------------------------------------------------------------------------
 Class: Sphere
 Base Class: Circle
 Purpose: Inherits functions of Circle class and calculates area, perimeter
          and volume of Sphere by inheriting specific funcions of Circle Class.
          It also prints the varibales of a Sphere.
 *------------------------------------------------------------------------*/
class Sphere :public Circle{
	public:
		Sphere(const double& r=0.0);
		double area() const;
		double volume() const;
		~Sphere();
};
/*-------------------------------------------------------------------------
 Class: Tetrahedron
 Base Class: equTrianlge (equilateral Triangle)
 Purpose: Inherits functions of equTrianlge class and calculates area, perimeter
          and volume of Tetrahedron by inheriting specific funcions of equTrianlge Class.
          It also prints the varibales of a Tetrahedron.
 *------------------------------------------------------------------------*/
class Tetrahedron :public equTriangle{
	public:
		Tetrahedron(const double& a=0.0);
		Tetrahedron(const Tetrahedron& t);
		Tetrhedron& operator=(const Tetrahedron &t);
		Tetrhedron& operator+=(const Tetrahedron &t);
		double area() const;
		double perimeter()const;
		double volume() const;
		~Tetrahedron();
};
#endif





