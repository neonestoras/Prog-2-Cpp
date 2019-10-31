#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
    int z;
};

Point initialisePoint(int x_in, int y_in, int z_in)
{
    Point p;
    p.x=x_in;
    p.y=y_in;
    p.z=z_in;
    return p;
}
Point addPoint(Point pos1, Point pos2)
{
    Point p;
    p.x=pos1.x+pos2.x;
    p.y=pos1.y+pos2.y;
    p.z=pos1.z+pos2.z;
    return p;
}

void displayPoint(Point pos_in)
{
    cout << "x: " << pos_in.x
    << ", y: " << pos_in.y
    << ", z: " << pos_in.z
    << endl;
}


int main()
{

    Point pos1;
    Point pos2;
    pos1.x = 10;
    pos1.y = 11;
    pos1.z = 12;
    pos2 = initialisePoint(1, 2, 3);
    displayPoint(pos1);
    displayPoint(pos2);
    displayPoint(addPoint(pos1, pos2));
    

    return 0;
}