#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
//T,T,T,Phe,F,Phenylalanine

struct pdata
{
	char codon[3];
	string code;
	char letter;
	string name;
};

int main()
{
	vector<pdata> proteins;
	string temps;
	pdata temp_prot;
	string three_letters="";
	string dna;
	dna.clear();
	ifstream infile;
	infile.open("dna2protein.csv");
	
	while (!infile.eof())
	{
		while (getline(infile,temps,'\n'))
		{
			temp_prot.codon[0]=temps[0];
			temp_prot.codon[1]=temps[2];
			temp_prot.codon[2]=temps[4];
			temp_prot.code=temps.substr(6,3);
			temp_prot.letter=temps[10];
			temp_prot.name=temps.substr(12);
			
			cout<< endl << temp_prot.codon[0]
				<< temp_prot.codon[1]
				<< temp_prot.codon[2]
				<<" "
				<<temp_prot.code<<" "<<temp_prot.letter<<" "
				<< temp_prot.name;
			
			proteins.push_back(temp_prot);
		}
	}
	infile.close();
	
	cout << endl << "Enter a protein" << endl << ">";
	temps.clear();
	cin >> temps;
	
	for (int i=0;i<temps.size();i++)
	{
		int j=0;
		while (proteins[j].letter!=temps[i])
			{j++;}
		
		three_letters=three_letters+" "+proteins[j].code;
		
		for (int z=0;z<3;z++)
			{dna.push_back(proteins[j].codon[z]);}
		dna.push_back(' ');
		
	}
	cout << endl << "1letter: " << temps;
	cout << endl << "3-letter DNA code:"<<dna;
	cout << endl << "3letter" << three_letters;
	
	return 0;
}