#include <iostream>
#include <string>
using namespace std;


int main()
{
    string name;
    string surname;
    int age;
    float weight;
    int count;

    
    do
    {
        cout <<"name:";
        cin >> name;
        cout << endl;
        count=0;
        for (int i=0; i<name.size(); i++)
        {
            if (int(name[i]) < 65){count++;}
        }
    }while (count);

    cout <<"surname:";
    cin >> surname;
    cout << endl;
    
    cout <<"age:";
        cin >> age;
        cout << endl;

        cout <<"weight: ";
        cin >> weight;
        cout << endl;

    cout << "your name is" << name 
    << " " << surname
    << " you are "<< age << "years old"
    << " and you weight" << weight << "kg " << endl;

    return 0;
}