#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct pdata
{
    char codon[3];
    string code;
    char letter;
    string name;
};

void printprot(pdata prot)
{
    cout << prot.codon[0] << prot.codon[1] << prot.codon[2]
        << " " << prot.code << " " << prot.letter
        << " " << prot.name << endl;
}

void printcodon(char a[3])
{
    cout << a[0] << a[1] << a[2]
        << " ";
}

int main()
{
    string temp;
    pdata tprot;
    vector<pdata> proteins;

    ifstream infile;
    infile.open("dna2protein.csv");
    while (!infile.eof())
    {
        while (getline(infile,temp,'\n'))
        {
            tprot.codon[0]=temp[0];
            tprot.codon[1]=temp[2];
            tprot.codon[2]=temp[4];
            tprot.code = temp.substr(6,3);
            tprot.letter = temp[10];
            tprot.name = temp.substr(12);
            proteins.push_back(tprot);
        }
        
    }

    for (int i=0; i < proteins.size(); i++)
    {
        printprot(proteins[i]);
    }

    cout<< "Enter a Protein sequence:" << endl << "> ";
    cin >> temp;
    cout << "1-letter AA code: " << temp << endl
        << "3-letter AA code: ";
    
    for (int j=0; j<temp.size(); j++)
    {
        int i=0;
        while (proteins[i].letter!=temp[j])
        {
            i++;
        }
        printcodon(proteins[i].codon);
    }

    return 0;
}