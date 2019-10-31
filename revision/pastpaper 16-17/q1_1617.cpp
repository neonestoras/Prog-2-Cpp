#include <iostream>

using namespace std;



int main()
{
    int a;
    cin >> a;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        
        cout << "Error: Enter only 0 or 1" << endl;
        cout << "Enter in a new value for a" << endl;
        cin >> a;
    }
}