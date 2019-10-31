#include <iostream>
#include <string>

using namespace std;

template <class T>
class Database
{
    private:
    string name;
    int id;
    T val;
    public:
    Database()
    {
        name=" ";
        id=0;
        val=0;
    }
    Database(string name_in, int id_in, T val_in)
    {
        this->name=name_in;
        this->id=id_in;
        this->val=val_in;
    }
    ~Database(){}
    void setName(string name_in)
    {
        this->name=name_in;
    }
    void setID(int id_in)
    {
        this->id=id_in;
    }
    void setVal(T val_in)
    {
        this->val=val_in;
    }
    string getName()
    {
        return name;
    }
    int getID()
    {
        return id;
    }
    T getVal()
    {
        return val;
    }
    void print()
    {
        cout << "Name: " << this->name
            << ", ID: " << this->id
            << ", val: " << this->val
            << endl;
    }
};

int main()
{

Database<int> data1;
Database<int> data2("triangle", 15, 68);
Database<double> data3("square", 12, 12.7123);
data1.print();
data2.print();
data3.print();
data1.setName("circle");
data1.setID(3);
data1.setVal(12);
data1.print();
data2.print();
data3.print();
cout<<"Name: "<<data3.getName()<<", ID: "<< data3.getID()
<<", val: "<<data3.getVal()<<endl;

    return 0;
}