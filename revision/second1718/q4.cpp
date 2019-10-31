#include <iostream>

using namespace std;

class Point
{
	private:
	double x;
	double y;
	double z;
	public:
	Point(){x=0;y=0;z=0;}
	Point(int xin,int yin,int zin)
	{
		x=xin;
		y=yin;
		z=zin;
	}
	~Point(){}
	
	void print()
	{
		cout << "("<<this->x<<","<<this->y<<","<<this->z<<")";
	}
	
	friend ostream& operator<<(ostream& os, Point p)
	{
		return os << "("<<p.x<<","<<p.y<<","<<p.z<<")";
	}
	Point& operator=(const Point p)
	{
		x=p.x;
		y=p.y;
		z=p.z;
		return *this;
	}
	friend Point operator+(const Point& p1,const Point& p2)
	{
		Point pout;
		pout.x=p1.x+p2.x;
		pout.y=p1.y+p2.y;
		pout.z=p1.z+p2.z;
		return pout;
	}
	double operator[](int in)
	{
		if (in==0){return this->x;}
		else if (in==1){return this->y;}
		else if (in==2){return this->z;}
		return 0;
	}
};

int main()
{
	
	Point pt1(2,3,4);
pt1.print();
Point pt2(5,6,7);
Point pt3;
pt3 = pt2;
cout << "pt1: " << pt1 << endl;
cout << "pt2: " << pt2 << endl;
cout << "pt3: " << pt3 << endl;
cout << "pt1 + pt2 = " << pt1 + pt2 << endl;
cout << "pt1[0]<<pt1[1]<<pt1[2]: " << pt1[0]<<pt1[1]<<pt1[2]<< endl;
	return 0;
}