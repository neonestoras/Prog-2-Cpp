#include <iostream>
#include <vector>
#include <string>
using namespace std;

class cell 
{
    private:
    string name;
    vector<cell*> children;
    public:
    cell()
    {
        this->name="";
        this->children.push_back(nullptr);
    }
    cell(string name_in,int  n_children_in)
    {
        this->name=name_in;
        for (int i=0;i<n_children_in;i++)
        {
            this->children.push_back(nullptr);
        }
    }
    
    ~cell(){}
    //help functions
    string getname(){return name;};
    void setname(string name_in){this->name=name_in;};
    cell* getchild(int n){return children[n];};
    void setchild(cell* child_in,int n)
    {
        children[n]=child_in;
    };
    int getnumchildren(){return children.size();};

};

class list 
{
    private:
    cell* next;
    public:
    list(){next=nullptr;}
    ~list(){};


    void addcell(cell* parent, int n_children)
    {
        string t3code;
        int tNchild = 0;

        cout << "For " << parent->getname() << ", enter child " << n_children+1 << "'s id (3 letters) >\t";
        cin >> t3code;
        cout << "Enter the number of children this child has >\t";
        cin >> tNchild;
        cell *p_temp = new cell(t3code, tNchild);
        parent->setchild(p_temp,n_children);


            for (int i=0; i<tNchild; i++)
                {
                    addcell(p_temp, i);
                }	


    }
    void fill()
    {
        string t3code;
        int tNchild = 0;

        // Request node
        cout << "Enter the cell's id (3 letters) >\t\t";
        cin >> t3code;
        cout << "Enter the number of children it has >\t\t";
        cin >> tNchild;
        
        cell *p_temp = new cell(t3code, tNchild);
        next = p_temp;
        
        for (int i=0; i<tNchild; i++)
        {
            addcell(next, i);
        }	
    }

    void printcell(cell* head, int level)
    {
        for (int i=0;i<level;i++){cout << "\t";}
        cout << head->getname() << endl;;
        for (int i=0; i<head->getnumchildren(); i++)
        {
            printcell(head->getchild(i), ++level);
        }
        level--;

    }

    void print()
    {
        int level = 0;
        cout << next->getname() << endl;;
        for (int i=0; i<next->getnumchildren(); i++)
        {
            printcell(next->getchild(i), ++level);
        }
        
    }
    
};

int main()
{
    
    list c_tree;


	cout << "Phylogenic Cancer Tree" << endl;
	cout << endl;
	cout << "Enter tree cells:" << endl;
	c_tree.fill();
	cout << endl;
	cout << "Display tree:" << endl;
	c_tree.print();

    return 0;
}