#include <iostream>

using namespace std;

class Point 
{
    private:
    int x;
    int y;
    int z;
    public:
    Point(){x=0;y=0;z=0;};
    Point(int x_in,int y_in,int z_in)
    {
        this-> x = x_in;
        this-> y = y_in;
        this-> z = z_in;
    };
    ~Point(){};

    void print()
    {
       cout << "("
            << x << ","
            << y << ","
            << z <<")"
             << endl;
    }

    friend ostream& operator <<(ostream& os, Point pt1);
    friend Point operator +( Point& p1_in, Point& p2_in )
    {
        Point p_out;
        p_out.x=p1_in.x+p2_in.x;
        p_out.y=p1_in.y+p2_in.y;
        return p_out;
    }
    Point operator =(const Point& p);
    friend Point operator -(Point p)
    {
        Point pt;
        pt.x=-p.x;
        pt.y=-p.y;
        pt.z=-p.z;
        return pt;
    }
    int operator [](int i)
    {
        if (i==0){return x;}
        else if (i==1){return y;}
        else if (i==2){return z;}
        return 0;
    }
};

ostream& operator <<(ostream& os, Point pt1)
{
    return os <<"("<< pt1.x <<","<< pt1.y <<","<< pt1.z <<")";
}

Point Point::operator =(const Point& pt_in)
{	
	x = pt_in.x;
	y = pt_in.y;
    z = pt_in.z;
	return *this;
}

int main()
{

 Point p4;
 Point p1(2,3,4);
 p1.print();
 cout << p1 << endl;

    p4 = p1;
    cout << p4;
    cout << endl << -p4;
    cout << endl << p4[1]<< p4[2]<<p4[0]<<endl;


	return 0;
}
