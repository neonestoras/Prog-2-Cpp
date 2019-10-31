#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RNA
{
private:
	vector<char> seq;
public:
	RNA(){seq="";}
	RNA(RNA& in)
	{
		for (int i=0;i<in->seq.size();i++)
			seq.push_back(in->seq[i]);
	}
	RNA(string seq_in)
	{
		for (int i=0;i<seq_in.size();i++)
			seq.push_back(seq_in[i]);
	}
	~RNA(){}
	
	
	vector<char> get_sequence()
	{
		this->seq;
	}
	void set_sequence(string seq_in)
	{
		for (int i=0;i<seq_in.size();i++)
			this->seq.push_back(seq_in[i]);
	}
	void set_sequence(vector<char> seq_in)
	{
		for (int i=0;i<seq_in.size();i++)
			this->seq.push_back(seq_in[i]);
	}
	void print()
	{
		for (int i=0;i<this->seq.size();i++)
				cout << this->seq[i];
	}
	
};

int main()
{
	
	// Part A
RNA rna0("AUG");
RNA rnaN("UAG");
RNA rna1;
RNA rna2 = rna0;
RNA rna3;
RNA rna4;
cout << "Part A" << endl;
// Part B
cout << "Part B" << endl;
rna0.print();
rnaN.print();
rna1.print();
rna2.print();
rna3.print();
rna3.set_sequence("GUCUCUACC");
rna4.set_sequence("AAAGACCAU");
// Part C
cout << "Part C" << endl;
rna2 = rna3;
cout << rna0 << endl;
cout << rnaN << endl;
cout << rna1 << endl;
cout << rna2 << endl;
cout << rna3 << endl;
cout << rna4 << endl;
cout << rna0 + rna3 + rnaN << endl;
cout << rna0 + rna4 + rnaN << endl;
if (rna2 == rna3)
cout << "the sequences match" << endl;
else
cout << "the sequences do not match" << endl;
if (rna3 == rna4)
cout << "the sequences match" << endl;
else
cout << "the sequences do not match" << endl;
	
	
	
	return 0;
}