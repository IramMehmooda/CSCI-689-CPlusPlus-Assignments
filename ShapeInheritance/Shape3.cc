#include "/home/cs689/progs/17f/p10/Shape3.h" //including header file of this source file
/*---------------------------------------------------------------
 *Class : Cube
 *--------------------------------------------------------------*/
Cube::Cube(const double& s):Square(s){}//implementation of parameterized constructor
Cube::Cube(const Cube& c):Square(c){}

Cube& Cube::operator=(const Cube& c){
	Square::operator=(c);
	return *this;
}
Cube& Cube::operator+=(const Cube& c){
	        Square::operator+=(c);
		        return *this;
}

double Cube::area() const{ //function for calculating the area 
	double areaOfSquare=Square::area();
	double area= 6*areaOfSquare; //inheriting the area function of a Square for returning the area of a Cube
	return area;
}

double Cube::perimeter() const{ //function for calculating the perimeter
	return 0;
}

double Cube::volume() const{  //function for calculating the volume
       double areaOfSquare=Square::area();
       double volume=areaOfSquare*length;  //inheriting the area of Square function for returning the volume of cube
       return volume;
}

void Cube::print() const{
	cout <<"length = " << length; //printing the length of a cube
}
Cube::~Cube(){} //destructing the cube

/*---------------------------------------------------------------
 Class : Box
 *--------------------------------------------------------------*/
Box::Box(const double& l,const double& w,const double& h):Rectangle(l,w){//implementation of parameterized constructor
	//length=l;
	//width=w;
	height=h;
}
Box::Box(const Box& b):Rectangle(b),height(b.height){}

Box& Box::operator=(const Box& b){
	if(this!=&b){
		Rectangle::operator=(b);
		height=b.height;
	}

	return *this;
}

Box& Box::operator+=(const Box& b){
	        Rectangle::operator+=(b);
		height+=b.height;
		return *this;
}

double Box::area() const{//function for calculating the area
	double topArea=Rectangle::area();
	double topPerimeter=Rectangle::perimeter();
	double area=2*topArea+height*topPerimeter;
	return area;//inheriting the specific functions from Rectangle for returning the area
}

double Box::volume() const{//function for calculating the volume
	double topArea=Rectangle::area();
	double volume=height*topArea;//inheriting the specific functions from Rectangle for returning the volume
	return volume;
}

double Box::perimeter() const{//function for calculating the perimete
	return 0;
}

void Box::print() const{
	cout << "length = " << length << " : width = " << width << " : height = " << height;//printing the length of a cube
}
Box::~Box(){}//destructing the cube
/*--------------------------------------------------------------
 Class : Cylinder
 --------------------------------------------------------------*/

Cylinder::Cylinder(const double& r,const double& h):Circle(r){//implementation of parameterized constructo
	//radius=r;
	height=h;
}

Cylinder::Cylinder(const Cylinder& cy):Circle(cy){}

Cylinder& Cylinder::operator=(const Cylinder& cy){
	if(this!=&cy){
		Circle::operator=(cy);
		height=cy.height;
	}
	return *this;
}

Cylinder& Cylinder::operator+=(const Cylinder& cy){
	        Circle::operator+=(cy);
		height+=cy.height;
		        return *this;
}


double Cylinder::area() const{//function for calculating the area
	double baseArea= Circle::area();
	double areaOfLateralSurface=height*Circle::perimeter();
	double area=2*baseArea+areaOfLateralSurface;//inheriting the specific functions from Circle for returning the area
	return area;
}

double Cylinder::perimeter() const{//function for calculating the perimeter
	return 0;
}

double Cylinder::volume() const{//function for calculating the volume
	double baseArea=Circle::area();
	double volume=height*baseArea;
	return volume;//inheriting the specific functions from Circle for returning the volum
}

void Cylinder::print() const{
	cout << "radius = " << radius << " : height = " << height;//printing the variables of a Cyclinder
}
Cylinder::~Cylinder(){}//destructing the cyclinder
/*--------------------------------------------------------------
 Class : Cone
 --------------------------------------------------------------*/

Cone::Cone(const double& r,const double& h):Circle(r){//implementation of parameterized constructor
	//radius=r;
	height=h;
}

Cone::Cone(const Cone& c):Circle(c),height(c.height){}
Cone& Cone::operator=(const Cone& c){//assignment operator implementation
	if(this!=&c){
		Circle::operator=(c);
		//radius=c.radius;
		height=c.height;
	}
	return *this;
}

Cone& Cone::operator+=(const Cone &c){//operator overloading for += operator
	Circle::operator+=(c);
		//radius+=c.radius;
	height+=c.height;
	return *this;
}


double Cone::area() const{//function for calculatingarea 
	double slantHeight=sqrt((radius*radius) +(height*height));
	double baseArea=Circle::area();
	double basePerimeter=Circle::perimeter();
	double areaLS=0.5*slantHeight*basePerimeter;
	double area=baseArea+areaLS;//inheriting the specific functions from Circle for returning the area
	return area;
}

double Cone::perimeter() const{//function for calculating the perimeter
	return 0;
}

double Cone::volume() const{//function for calculating the volume
	double baseArea=Circle::area();
	double volume=(height*baseArea)/3;
	return volume;//inheriting the specific functions from Circle for returning the volume
}

void Cone::print() const{
	cout << "radius = " << radius << " : height = " << height;//printing the variables of a Cyclinde
}

Cone::~Cone(){}//destructing
/*----------------------------------------------------------------------
Class: Sphere
 * --------------------------------------------------------------------*/

Sphere::Sphere(const double& r) :Circle(r){}//implementation of parameterized constructor

Sphere::Sphere(const Sphere& sp):Circle(sp){}

Sphere& Sphere::operator=(const Sphere& sp){
	Circle::operator=(sp);
	return *this;
}

Sphere& Sphere::operator+=(const Sphere& sp){
	        Circle::operator+=(sp);
		return *this;
}

double Sphere::area() const{//function for calculating area
	double area=4*Circle::area();
	return area;//inheriting the specific functions from Circle for returning the area
}

double Sphere::volume() const{//function for calculating the volume
	double volume=(4*radius*Circle::area())/3;
	return volume;//inheriting the specific functions from Circle for returning the volume
}

Sphere::~Sphere(){}//destructing
/*----------------------------------------------------------------------
 Class: Sphere
* --------------------------------------------------------------------*/

Tetrahedron::Tetrahedron(const double& a):equTriangle(a){}//implementation of parameterized constructor

Tetrahedron::Tetrahedron(const Tetrahedron& t):equTriangle(t){}

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& t){
	equTriangle::operator=(t);
	return *this;
}

Tetrahedron& Tetrahedron::operator+=(const Tetrahedron& t){
	        equTriangle::operator+=(t);
		return *this;
}


//Tetrahedron::Tetrahedron(const Tetrahedron& t):equTriangle(t){}//copy constructor 
/*Tetrahedron& Tetrahedron::operator=(const Tetrahedron &t){//assignment operator
	if(this!=&t){
		a=t.a;
		b=t.a;
		c=t.a;
	}
	return *this;
}

Tetrahedron& Tetrahedron::operator+=(const Tetrahedron &t){//operator overloading
	a+=t.a;
	b+=t.a;
	c+=t.a;
	return *this;
}
*/
double Tetrahedron::area() const{//function for calculating area
	double areaPhase=equTriangle::area();
	double area=4 *areaPhase;//inheriting the specific functions from equTriangle for returning the area
	return area;
}

double Tetrahedron::perimeter() const{//function for returning perimeter
	return 0;
}

double Tetrahedron::volume() const{////function for calculating the volume
	double height=sqrt(0.666666)*a;
	double areaFace=equTriangle::area();
	double volume=(height*areaFace)/3;//inheriting the specific functions from equTriangle for returning the volume
	return volume;
}

Tetrahedron::~Tetrahedron(){}//Destructing Tetrahedron





