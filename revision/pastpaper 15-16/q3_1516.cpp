#include <iostream>

using namespace std;

int processData(int a, int b)
{
    int out;
    out=3*a+5*b;
    return out;
}

double processData(double a, double b)
{
    double out;
    out=3*a+5*b;
    return out;
}

int main()
{
    int iv1 = 2;
    int iv2 = 4;
    int iv3;
    float fv1 = 2.1;
    float fv2 = 4.4;
    float fv3;
    iv3 = processData(iv1, iv2);
    fv3 = processData(fv1, fv2);
    cout << "integer output: " << iv3 << endl;
    cout << "integer output: " << fv3 << endl;

    return 0;
}