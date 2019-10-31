#include <iostream>
#include <string>

using namespace std;


//james choi, you are 35 years old and weigh 66 kilograms.
bool findnumber(string in)
{
	for (int i=0;i<in.size();i++)
	{
		if (int(in[i])<64)
			return true;
	}
	return false;
}

int main()
{
	string name;
	string last;
	int age;
	float w;
	do
	{
	cout<<"Enter your first name: ";
	cin >> name;
	}while(findnumber(name));
	
	
	
	cout<<"Enter your last name: ";
	cin >> last;
	cout<<"Enter your age (years): ";
	cin >> age;
	cout<<"Enter your weight (kg): ";
	cin >> w;
	
	cout<<endl << name << " " << last << " , you are "<<age << " years old and weight "
	<<w<< " kilograms."
	
	
	return 0;
}