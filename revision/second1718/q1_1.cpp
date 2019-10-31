#include <iostream>

using namespace std;

void print(char a[2][3])
{
	cout<< "-------";
	for (int i=0; i<2 ;i++)
	{
		cout<< endl<<"|";
		for (int j=0; j<3 ;j++)
		{
			cout << a[i][j]<<"|";
		}
		cout<<  endl<< "-------";
	}
}

int main()
{
	char a[2][3];
	int boxes=0;
	int rw,co;
	
	for (int i=0; i<2 ;i++)
	{
		for (int j=0; j<3 ;j++)
		{
			a[i][j]=' ';
		}
	}
	print(a);
	while (boxes < 6)
	{
		do 
		{
		cout << endl<<"enter row 1-2: ";
		cin >> rw;
		rw--;
		cout << endl << "enter column 1-3: ";
		cin >> co;
		co--;
		}while(a[rw][co]=='X');
		a[rw][co]='X';
		boxes++;
		print(a);
	
	}
	
	return 0;
}