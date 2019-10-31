#include <iostream>

using namespace std;

class Shape 
{
protected:
    double x;
    double y;
public:
    Shape(){this->x=0;this->y=0;};
    Shape(double x_in,double y_in)
    {
        this->x=x_in;
        this->y=y_in;
    };
    ~Shape(){};

    virtual double getArea(){};
    virtual double getPerimeter(){};

};

class Rectangle : public Shape
{
    private:
        double w;
        double h;

    public:
        Rectangle() : Shape() {this->w=0;this->h=0;};
        Rectangle(double x_in,double y_in,double w_in, double h_in) : Shape(x_in,y_in)
        {this->w=w_in;this->h=h_in;}
        ~Rectangle(){}

        double getArea()
        {
            return w*h;
        }

        double getPerimeter()
        {
            return (this->w+this->h)*2;
        }
};

class Circle : public Shape
{
    private:
        double r;

    public:
        Circle() : Shape() {this->r=0;};
        Circle(double x_in,double y_in,double r_in) : Shape(x_in,y_in)
        {this->r=r_in;}
        ~Circle(){}

        double getArea()
        {
            return 3.14*r*r;
        }

        double getPerimeter()
        {
            return 2*3.14*r;
        }
};

int main()
{

Shape* p_shape;
Rectangle shape1(1,2,15,10);
Circle shape2(3,2,10);
cout<< "shape 1 area: " << shape1.getArea() <<endl;
cout<< "shape 1 perimeter: " << shape1.getPerimeter() <<endl;
cout<< "shape 2 area: " << shape2.getArea() <<endl;
cout<< "shape 2 perimeter: " << shape2.getPerimeter() <<endl;
p_shape = &shape1;
cout<< "shape 1 area: " << p_shape->getArea() <<endl;
cout<< "shape 1 perimeter: " << p_shape->getPerimeter() <<endl;
p_shape = &shape2;
cout<< "shape 2 area: " << p_shape->getArea() <<endl;
cout<< "shape 2 perimeter: " << p_shape->getPerimeter() <<endl;
    return 0;
}