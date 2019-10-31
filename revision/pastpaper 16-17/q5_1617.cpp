#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RNA
{
private:
vector<char> seq;

public:
//constr and dissstruct
RNA(){this->seq.push_back(' ') ;}
RNA(string seq_in)
{
    for (int i=0; i< seq_in.size();i++)
    {
        this->seq.push_back(seq_in[i]);
    }
}
RNA(const RNA &in)
{
    this->seq=in.seq;
}
~RNA(){};
//help functions
vector<char> get_sequence(){return seq;}
void set_sequence(string seq_in)
{
    this->seq.clear();
    for (int i=0; i< seq_in.size();i++)
    {
        this->seq.push_back(seq_in[i]);
    }
}
void set_sequence(vector<char> seq_in)
{
    this->seq.clear();
    for (int i=0; i< seq_in.size();i++)
    {
        this->seq.push_back(seq_in[i]);
    }
}
void print()
{
    for (int i=0; i< this->seq.size();i++)
    {
        cout << this->seq[i];
    }
}
//overloading operators
RNA operator=(const RNA& in)
{
    seq = in.seq;
    return *this;
}
friend RNA operator+(RNA in1,RNA in2)
{
    RNA temprna;
    vector<char> newseq;
    newseq=in1.get_sequence();
    
    for(int i=0;i<in2.seq.size();i++)
    {
        newseq.push_back(in2.seq[i]);
    }
    temprna.set_sequence(newseq);
    return temprna;
}
friend ostream& operator<<(ostream& os, RNA rna)
{
    string tempseq;
    for (int i=0; i< rna.seq.size();i++)
    {
        tempseq.push_back(rna.seq[i]);
    }
    return os << tempseq;
}
friend bool operator==(RNA& in1,RNA& in2)
{
    bool output=true;
    if (in1.seq.size()!=in1.seq.size()){return false;}
    for (int i=0;i<in1.seq.size();i++)
    {
        if (in1.seq[i]!=in2.seq[i]){output=false;}
    }
    return output;
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
cout << endl << "Part C" << endl;
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