#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct word
{
	int counts;
	string txt;
};

int main()
{
	string temps;
	vector <string> text;
	vector <word> list;
	
	ifstream infile;
	infile.open("gaddress.txt");
	
	
	while (!infile.eof())
	{
		while (getline(infile,temps,' '))
		{
			cout << temps << " ";
			text.push_back(temps);
		}
	}
	cout <<endl;
	infile.close();
	
	word tempword;
	tempword.txt=text[0];
	tempword.counts=1;
	list.push_back(tempword);
	for (int i=1;i<text.size();i++)
	{
		bool rec=false;
		for (int j=0;j<list.size();j++)
		{
			if (text[i]==list[j].txt)
				{
					list[j].counts++;
					rec=true;	
				}
		}
		if (!rec)
		{
			tempword.txt=text[i];
			tempword.counts=1;
			list.push_back(tempword);
		}
	}
	
	for (int j=0;j<list.size();j++)
		{
			cout << list[j].txt << " " << list[j].counts << endl;
		}
	
	
	return 0;
}