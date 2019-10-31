#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string a;
    string temp;
    getline(cin,a);
    int p=0;
    int nextp;
    vector<string> words;
    do
    {   
        nextp=a.find(' ',p);
        temp=a.substr(p,nextp-p);
        words.push_back(temp);
        p=nextp+1;
    }while(p>0);
    for (int i=0;i<words.size();i++)
    {
        cout << words[i]<<endl;
    }
    
    return 0;
}