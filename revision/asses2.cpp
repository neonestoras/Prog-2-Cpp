#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



struct Pdata //data that every protein imput contains
{
    int id;
    string gi;
    string ref;
    string sequence;
    string description;
    bool recorded=false;
};

//global variables
Pdata temp_protein;//temporary variables
string temp;
ofstream outfile;//record to an external text file

int mainmenu()//main menu print and selection
{
    int m_slct;
    std::cout << endl << "Select an option from the menu below" << endl
              <<"1) Overview of the database" << endl
              <<"2)Search by protein #" << endl
              <<"3) Search by gi #" << endl
              <<"4) Search by ref #" << endl
              <<"5) Search by keyword" << endl
              <<"6) Quit database " << endl
              <<"selection:  " << endl;
    cin >> m_slct;
    return m_slct;
}
 
int proteinoption()//protein menu print and selection
{
    int p_slct;
    std::cout << endl << "Select and option from the menu below" << endl
            << "1) Description of the protein" << endl
            << "2) Protein sequence" << endl
            << "3) Protein statistics" << endl
            << "4) Record protein to file" << endl
            << "5) Return to main menu" << endl
            <<"selection:  " << endl;
    cin >> p_slct;
    return p_slct;

}    


void protmenu()//protein menu comands 
{
    bool opened_out=false;
    int countA = 0, countB = 0, countC = 0, countD = 0, countE = 0, countF = 0, countG = 0, countH = 0,
        countI = 0, countK = 0, countL = 0, countM = 0, countN = 0, countP = 0, countQ = 0, countR = 0,
        countS = 0, countT = 0, countU = 0, countV = 0, countW = 0, countX = 0, countY = 0, countZ = 0;

    int prot_option=proteinoption();//enter prot menu with the selected id protein

                        while(prot_option!=5)//quit at 6
                        {
                            switch (prot_option)
                            {
                                case 1 :
                                    std::cout << "Description of the protein:" << endl
                                              << "item id : " << temp_protein.id << endl
                                              << "gi id : " << temp_protein.gi << endl
                                              << "ref id : " << temp_protein.ref << endl
                                              << "name : " << temp_protein.description << endl;
                                break;

                                case 2 :
                                    std::cout << "Protein sequence"<< endl << temp_protein.sequence << endl << endl;
                                break;

                                case 3 :
                                    countA = 0; countB = 0; countC = 0; countD = 0; countE = 0; countF = 0; countG = 0; countH = 0;
                                    countI = 0; countK = 0; countL = 0; countM = 0; countN = 0; countP = 0; countQ = 0; countR = 0;
                                    countS = 0; countT = 0; countU = 0; countV = 0; countW = 0; countX = 0; countY = 0; countZ = 0;
                                    temp=temp_protein.sequence;//store sequence in temporary string
                                    for (int i=0; i < temp_protein.sequence.size(); i++)
                                    {
                                       switch (temp[i]) //count letters of sequence and increase counters for each
                                        {
                                            case 'A' :
                                            countA++;
                                            break;

                                            case 'B' :
                                            countB++;
                                            break;
                                            
                                            case 'C' :
                                            countC++;
                                            break;

                                            case 'D' :
                                            countD++;
                                            break;

                                            case 'E' :
                                            countE++;
                                            break;

                                            case 'F' :
                                            countF++;
                                            break;
                                            
                                            
                                            case 'G' :
                                            countG++;
                                            break;

                                            case 'H' :
                                            countH++;
                                            break;

                                            case 'I' :
                                            countI++;
                                            break;
                                            
                                            case 'K' :
                                            countK++;
                                            break;
                                            
                                            case 'L' :
                                            countL++;
                                            break;
                                            
                                            case 'M' :
                                            countM++;
                                            break;
                                            
                                            case 'N' :
                                            countN++;
                                            break;
                                            
                                            case 'P' :
                                            countP++;
                                            break;
                                            
                                            case 'Q' :
                                            countQ++;
                                            break;
                                            
                                            case 'R' :
                                            countR++;
                                            break;
                                            
                                            case 'S' :
                                            countS++;
                                            break;
                                            
                                            case 'T' :
                                            countT++;
                                            break;
                                            
                                            case 'U' :
                                            countU++;
                                            break;
                                            
                                            case 'V' :
                                            countV++;
                                            break;
                                            
                                            case 'W' :
                                            countW++;
                                            break;
                                            
                                            case 'X' :
                                            countX++;
                                            break;
                                            
                                            case 'Y' :
                                            countA++;
                                            break;
                                            
                                            case 'Z' :
                                            countZ++;
                                            break;
                                            
                                        }
                                    }
                                    //print results
                                    std::cout   << "Total number of amino acids: " << temp_protein.sequence.size() << endl 
                                                << "A  " << countA << "    P  " << countP << endl
                                                << "B  " << countB << "    Q  " << countQ << endl
                                                << "C  " << countC << "    R  " << countR << endl
                                                << "D  " << countD << "    S  " << countS << endl
                                                << "E  " << countE << "    T  " << countT << endl
                                                << "F  " << countF << "    U  " << countU << endl
                                                << "G  " << countG << "    V  " << countV << endl
                                                << "H  " << countH << "    W  " << countW << endl
                                                << "I  " << countI << "    Y  " << countY << endl
                                                << "K  " << countK << "    Z  " << countZ << endl
                                                << "L  " << countL << "    X  " << countX << endl
                                                << "M  " << countM << "    *  0" << endl
                                                << "N  " << countN << "    -  0" << endl;

                                break;

                                case 4://record protein to file
                                    //create an output file if it has not been created yet
                                    if (!opened_out) {outfile.clear(); outfile.open("recordedproteins.txt"); opened_out=true;}
                                    
                                    if (!temp_protein.recorded)//avoid exporting protein data of the same protein many times
                                    {
                                        temp_protein.recorded=true;
                                        outfile << ">gi|" << temp_protein.gi
                                                << "|ref|" << temp_protein.ref
                                                << temp_protein.description
                                                << temp_protein.sequence << endl;
                                        cout << "Protein recorded" << endl;
                                    }
                                    else {std::cout << "the protein is already recorded" << endl;}
                                break;
                                
                            }
                            prot_option=proteinoption();
                        }
}




int main ()
{

    vector<Pdata> proteins;//protein database stored
    
    int idnum=0;
    int i;
    int mainselection;//main and initial menu selection input 
    
    ifstream inFile;
    


    
    std::cout <<"Welcome to the Protein Database" << endl << endl
              <<"Select an option from the menu below" << endl
              <<"1) Load the abridged protein data"  <<endl
              <<"2) Load the complete protein data" << endl
              <<"3) Quit database" << endl
              << "selection: ";
    cin >> mainselection;

    if (mainselection==1){temp="protein_a.fa";}//load abridged data
    else if (mainselection==2){temp="protein_c.fa";}//load complete file
    else if(mainselection==3){std::cout << endl << "quit program";return 0;}


    inFile.open(temp);//open selected file

    if (inFile.fail())//if file opening fails
    {
        cerr << "Error opening file" << endl;
        exit(1);
    }


                while (!inFile.eof())//load data into proteins vector
                {
                    while (getline(inFile,temp,'>'))//store each string, all protein data to temporary variable
                    {
                        if (idnum)//skip the first '>'
                        {
                            int   p_gi=temp.find('|',3);//find the position in the string where different 
                            int   p_ref=temp.find('|',p_gi+5);//types of informations are sepparated
                            int   p_description=temp.find('\n');
                            
                            temp_protein.id=idnum++;//store the data between the separations found above
                            temp_protein.gi=temp.substr(3, p_gi-3 );
                            temp_protein.ref=temp.substr(p_gi+5, p_ref - p_gi - 5 );
                            temp_protein.description=temp.substr(p_ref, p_description-p_ref );
                            temp_protein.sequence=temp.substr(p_description);

                            proteins.push_back(temp_protein);//put the compleately filled protein in the database
                        }
                        else if (idnum==0)
                        {
                            idnum=1;
                            std::cout << "Loading data..." << endl;
                            
                        }
                    }
                }
                inFile.close();//end of load data and close file
                std::cout << "Data Loaded" << endl << endl;

            mainselection=mainmenu();//1st selection of  main menu oprion
           while (mainselection != 6)//quit at 6
           {
                
                if (mainselection == 1)
                    {
                        std::cout << "The proteins in the database are from GenBank(R)" << endl
                                    << "Total number of proteins in the database:" << idnum << endl
                                    << "Amino acids are represented by the following characters:" << endl
                                    << "A  alanine               P  proline" << endl
                                    << "B  aspartate/asparagine  Q  glutamine" << endl
                                    << "C  cystine               R  arginine" << endl
                                    << "D  aspartate             S  serine" << endl
                                    << "E  glutamate             T  threonine" << endl
                                    << "F  phenylalanine         U  selenocysteine" << endl
                                    << "G  glycine               V  valine" << endl
                                    << "H  histidine             W  tryptophan" << endl
                                    << "I  isoleucine            Y  tyrosine" << endl
                                    << "K  lysine                Z  glutamate/glutamine" << endl 
                                    << "L  leucine               X  any" << endl
                                    << "M  methionine            *  translation stop" << endl
                                    << "N  asparagine            -  gap of indeterminate length" << endl
                                    <<endl;
                    }

                else if (mainselection == 2 || 3 || 4 || 5)
                {//convert search type of search to id and then acces protein menu if found
                        int searchid;
                        int prot_option;
                        bool found=false;
                        string search_gi;
                        string search_ref;

                        if (mainselection == 2)//id
                        {
                            std::cout << "Enter an item id" << endl;
                            cin >> searchid;
                            
                            while (searchid<1 || searchid > proteins.size() || cin.fail())
                            {
                                cin.clear();
                                std::cout <<"the input does not match any protein" << endl
                                        << "Enter an item id" << endl;
                                cin >> searchid;
                            }
                            temp_protein=proteins[--searchid];
                            protmenu();
                        }
                        else if (mainselection == 3)//gi
                        {
                                std::cout << "Enter a gi number" << endl;
                                cin >> search_gi;

                                while (!found)
                                {
                                    for ( idnum=0; idnum < proteins.size(); idnum++)
                                    {
                                        if (search_gi == proteins[idnum].gi)
                                        {
                                            searchid=idnum;
                                            found=true;
                                            break;
                                        }
                                        
                                    }
                                    if (!found)
                                    {
                                        std::cout << "no match found" << endl;
                                        cin.clear();
                                        std::cout << "Enter a gi number" << endl;
                                        cin >> search_gi;
                                    }
                                }
                            temp_protein=proteins[searchid];
                            protmenu();
                        }

                        else if (mainselection == 4)//ref
                        {
                                std::cout << "Enter a reference " << endl;
                                cin >> search_ref;
                                while (!found)
                                {
                                    for ( idnum=0; idnum < proteins.size(); idnum++)
                                    {
                                        if (search_ref == proteins[idnum].ref)
                                        {
                                            searchid=idnum;
                                            found=true;
                                            break;
                                        }
                                    }

                                    if (!found)
                                        {
                                        std::cout << "no match found" << endl;
                                        cin.clear();
                                        std::cout << "Enter a reference" << endl;
                                        cin >> search_ref;
                                        }
                                }
                            temp_protein=proteins[searchid];
                            protmenu();
                        }

                        else if (mainselection == 5)//keyword search
                        {
                            string key;
                            std::cout << "enter a keyworld"<<endl;
                            cin >> key;
                            vector <Pdata> finds;
                            finds.clear();
                            for (i=0; i < proteins.size(); i++)
                            {   
                                    if (!(proteins[i].description.find(key) == string::npos) )
                                    {
                                        finds.push_back( proteins[i] );

                                        std::cout << finds.size() << ") "
                                                << " item id: " << proteins[i].id
                                                << " gi id: " << proteins[i].gi
                                                << " ref id: " << proteins[i].ref << endl
                                                << "  " << proteins[i].description << endl;
                                                
                                    }   
                            }
                            if (finds.size())
                            {
                                std::cout << "select a protein"<<endl;
                                cin >> searchid;
                                searchid=proteins[searchid].id+1;
                                temp_protein=proteins[--searchid];
                                protmenu();
                            }
                            else 
                            {
                                std::cout << "no proteins found" << endl;
                            }
                        }
       
                }
                mainselection=mainmenu();//main menu selection
            }

    outfile.close();//close output file
    return 0;
}