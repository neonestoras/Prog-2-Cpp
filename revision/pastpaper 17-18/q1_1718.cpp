#include <iostream>

using namespace std;

const int columns=3;
const int rows=2;
const char c='X';

void printarray(char array[rows][columns])
{
    for (int i=0; i < rows; i++)
    {
        cout << "-------" << endl << "|";
        for (int j=0; j < columns; j++)
        {
            cout << array[i][j] << "|";
        }
        cout << endl;
    }

}

int main()
{
    char a[rows][columns];
    int rw,col;
    int boxes=0;
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < columns; j++)
        {
            a[i][j]=' ';
        }
    }

    printarray(a);
    while (boxes < rows*columns)
    {

        do
        {
            cout << "Enter row (1-2):  ";
            cin >> rw;
            
            cout << endl;
        }while( rw < 0 || rw > rows);

        do{
            cout << "Enter column (1-3):  ";
            cin >> col;
            
            cout << endl;
        }while (col < 0 || col > columns);
        col--;
        rw--;
        if (a[rw][col]==' ')
        {
        a[rw][col]=c;
        boxes++;
        printarray(a);
        }
        else 
        {
            cout << "already taken"<<endl;
        }
        

    }
return 0;
}