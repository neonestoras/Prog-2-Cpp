#include <iostream>

using namespace std;


print(string line)
{
	cout << line;
}

print(int integer)
{
	cout << integer;
}

print(int a[5])
{
	for (int i=0;i<5;i++)
		cout << a[i];
}
int main()
{
	string line_str = "Question 3";
	print(line_str);
	int x = 999;
	print(x);
	int array[5] = {5, 4, 3, 2, 1};
	print(array);
	
	return 0;
}