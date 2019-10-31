#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile;
    string temps;
    int cA=0,cG=0,cT=0,cC=0;
    
    infile.open("q01in.txt");
    while (!infile.eof())
    {
        while (getline(infile,temps,'\n'))
        {
            cA=0;cG=0;cT=0;cC=0;
            int psec = temps.find('\t',3);
            cout << temps << "\t";
            for (int i=psec;i<temps.size();i++)
            {
                switch (temps[i])
                {
                    case 'A' :
                    cA++;
                    break;
                    case 'G' :
                    cG++;
                    break;
                    case 'T' :
                    cT++;
                    break;
                    case 'C' :
                    cC++;
                    break;
                }
            }
            cout << "A: " << cA
            << " G: " << cG
            << " T: " << cT
            << " C: " << cC
            << endl;
        }
    }
    infile.close();

    return 0;
}