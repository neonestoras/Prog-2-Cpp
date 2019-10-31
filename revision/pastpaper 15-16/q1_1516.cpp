#include <iostream>

using namespace std;

void print(char array[4][4])
{
     cout << endl << "---------" << endl;
    for (int i=0;i<4;i++)
    {
        cout << "|";
        for (int j=0;j<4;j++)
        {
            cout << array[i][j] << "|";
        }
        cout << endl << "---------" << endl;
    }
}

int main()
{
    char a[4][4];
    int rw,co;
    int i,j;
    char c;

    for (i=0;i<4;i++)
    {
        for (j=0;j<4;j++)
        {
            a[i][j]='-';
        }
    }

    print(a);
    while (true)
    {
        cout << endl <<"enter character : ";
        cin >> c;
        cout << endl <<"enter row(1-4)";
        cin >> rw; rw--;
        cout << endl <<"enter column (1-4)";
        cin >> co; co--;
        a[rw][co]=c;
        print(a);
    }

    return 0;
}