#include <iostream>
#include <vector>
using namespace std;
class Shape
{
protected:
	double x;
	double y;
public:
	Shape();
	Shape(double x_in, double y_in);
	virtual double area() {;};
	virtual double perimeter() {;};
};

Shape::Shape()
{
	x=0;
	y=0;
}

Shape::Shape(double x_in, double y_in)
{
	x=x_in;
	y=y_in;
};

class Rectangle : public Shape
{
private:
	double w;
	double h;
public:
	Rectangle();
	Rectangle(double x_in, double y_in, double w_in, double h_in);
	double area() {return w*h;};
	double perimeter() {return 2*w+2*h;};
};

Rectangle::Rectangle():Shape()
{
	w=0;
	h=0;
}

Rectangle::Rectangle(double x_in, double y_in, double w_in, double h_in):Shape(x_in,y_in)
{
	w=w_in;
	h=h_in;
};


class Circle : public Shape
{
private:
	double r;
public:
	Circle();
	Circle(double x_in, double y_in, double r_in);
	double area() {return 3.14*r*r;};
	double perimeter() {return 2*3.14*r;};
};

Circle::Circle():Shape()
{
	r=0;
}

Circle::Circle(double x_in, double y_in, double r_in):Shape(x_in,y_in)
{
	r=r_in;
};
int main()
{
	
	Rectangle r0;
Rectangle r1(0,0,2,5); // the order is x, y, w, h
Circle c0;
Circle c1(0,0,4); // the order is x, y, r
cout << "Part A." << endl;
cout << "area: " << r0.area() << endl;
cout << "perimeter: " << r0.perimeter() << endl;
cout << "area: " << r1.area() << endl;
cout << "perimeter: " << r1.perimeter() << endl;
cout << "area: " << c0.area() << endl;
cout << "perimeter: " << c0.perimeter() << endl;
cout << "area: " << c1.area() << endl;
cout << "perimeter: " << c1.perimeter() << endl;

cout << endl <<"Part B." << endl;

vector<Shape*> vs;

vs.push_back(new Rectangle(0,0,2,5));
vs.push_back(new Rectangle(1,2,2,2));
vs.push_back(new Circle(0,0,4)); // the order is x, y, r
vs.push_back(new Circle(1,2,2));

for (int i=0;i<vs.size();i++)
{
	cout << "area: " << vs[i]->area() << endl;
	cout << "perimeter: " << vs[i]->perimeter() << endl;
}

	
	
	
	return 0;
}