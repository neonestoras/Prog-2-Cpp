#include <iostream>
#include <vector>

using namespace std;

void print1(vector<int> a)
{
	for(int i=0;i<a.size();i++)
	{
		cout << a[i] << endl;
	}
}

template<class T>
void print2(vector<T> vin)
{
	for(int i=0;i<vin.size();i++)
	{
		cout << vin[i] << endl;
	}
}

int main()
{
	
	vector<int> vint;
	vector<char> vchar;
	vector<double> vdouble;
	vint.push_back(3);
	vint.push_back(1);
	vint.push_back(4);
	cout << "Part A" << endl;
	print1(vint);
	vchar.push_back('p');
	vchar.push_back('i');
	vdouble.push_back(3.14);
	vdouble.push_back(2.71);
	cout << "Part B" << endl;
	print2(vint);
	print2(vchar);
	print2(vdouble);

	return 0;
}