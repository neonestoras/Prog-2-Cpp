#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

struct pdata 
{
    string category;
    string id;
    string name;
    string sequence;
    int number;

};

void printprotein(pdata p)
{
    cout << p.number << " >" << p.category << "| " << p.name << endl
        << p.sequence << endl;
}

/*The category is drugbank_target
The identification is P45059
The name is Peptidoglycan synthase FtsI (DB00303)
The sequence is ATGGTGAAATTTAATTCCTCGCGTAAATCAGGTAAGTCAAAAAAAACAATT…

>drugbank_target|P45059 Peptidoglycan synthase FtsI (DB00303)
ATGGTGAAATTTAATTCCTCGCGTAAATCAGGTAAGTCAAAAAAAACAATTAGAAAATTG...
*/
int main()
{
    string tempstr;
    pdata ptemp;
    vector <pdata> list;
    int idnum=0;

    ifstream infile;
    infile.open("gene.fasta");

    while (!infile.eof())
    {
        while(getline(infile,tempstr,'>'))
        {
            if (idnum++)
            {
                int pcat=tempstr.find('|');
                int pid=tempstr.find(' ',pcat);
                int pname=tempstr.find(')',pid);

                ptemp.category=tempstr.substr(0,pcat);
                ptemp.id=tempstr.substr(pcat+1,pid-pcat);
                ptemp.name=tempstr.substr(pid+1,pname-pid);
                ptemp.sequence=tempstr.substr(pname+2);
                ptemp.number=idnum-1;

                list.push_back(ptemp);

                if (idnum==2)
                {
                    //cout << "Part A:"<< endl << tempstr << endl;
                    printprotein(list[0]);
                }

            }
        }
    }
    infile.close();


    cout << "Part B:" << endl;
    printprotein(list[0]);
    printprotein(list[1]);
    printprotein(list[999]);
    printprotein(list[list.size()-1]);


   cout << endl <<"Part C:" << endl;
    for (int i=0; i< list.size(); i++)
    {
        if (list[i].name.find("receptor") != string::npos)//apekswwwwwwwwwwwwwwww
        {
            printprotein(list[i]);
        }
    }
    

    return 0;
}