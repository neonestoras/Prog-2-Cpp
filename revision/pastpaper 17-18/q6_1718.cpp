#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct wording
{
    int counts=0;
    string word;
};

int main()
{
    vector<wording> words;
    vector<string> text;
    string temp_s;
    wording temp;

    ifstream infile;
    infile.open("gaddress.txt");
    while(!infile.eof())
    {
        while(getline(infile,temp_s,' '))
        {
            cout << temp_s << " ";
            text.push_back(temp_s);
            
        }
    }
    infile.close();

    int i=1;
    int j;
    bool rec;
    temp.word=text[0];
    temp.counts=1;
    words.push_back(temp);
    while ( i < text.size())
    {
        j=0;
        rec=false;
        while (j < words.size())
        {
            if (text[i]==words[j].word)
            {
                words[j].counts++;
                rec=true;
                break;
            }
            j++;
        }
        if (!rec)
        {
            temp.word=text[i];
            temp.counts=1;
            words.push_back(temp);
        }
        i++;
    }

    for (i=0;i<words.size();i++)
    {
        cout << endl 
            << words[i].word << " " << words[i].counts; 
    }


	return 0;
}