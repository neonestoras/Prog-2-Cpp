#include <iostream>

using namespace std;

bool check(char c)
{
	int i=int(c);
	if ((i>64 && i<91)||(i>96 && i<123 )){return true;}
	else{return false;}
}

void print(char a[3][3])
{
	cout << endl << "-------";
	for (int i=0;i<3;i++)
	{
		cout << endl << "|";
		for (int j=0;j<3;j++)
		{
			cout << a[i][j] << "|";
		}
		cout << endl << "-------";
	}
}

int main()
{
	
		int boxes=0;
		int rw,co;
		char c;
		char a[3][3];
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				a[i][j]=' ';
			}
		}
		print(a);
		while (boxes < 9)
		{
			
			do
			{
				cout << endl << "char: ";
				cin>> c;
				cout << endl;
			}while(!check(c));
			do{
			do
			{
				cout << "row: ";
				cin >> rw;
				rw--;
				cout <<endl;
			}while(rw>=3 || rw<0 || cin.fail());
			
			do
			{
				cout << "colum: ";
				cin >> co;
				co--;
				cout <<endl;
			}while(co>=3 || co<0 || cin.fail());
			}while(a[rw][co]!=' ');
			a[rw][co]=c;
			print(a);
			boxes++;
		}
	
	
	return 0;
}