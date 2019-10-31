#include <iostream>

using namespace std;

double de_distance(double t)
{
	//d = ct/2
	return  750*t;
}

int main()
{
	
	double time;
	
	cout << "Part A:" << endl
		<< "If an echo returns 80 microseconds later, then there was an object located"
			<< de_distance(0.000008) << "metre(s) away" << endl;
	cout << "Part A:" << endl;
	do
	{
		cout << "Enter a time in seconds: ";
		cin >> time;
		if (!cin.fail())
			cout << endl <<"The object is located" <<de_distance(time)<<" metre(s) away"<<endl;
	}while(!cin.fail());
	
	
	return 0;
}