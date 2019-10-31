#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
string name;
Node* p_next;
public:
Node(){this->name="";this ->p_next=nullptr;};
Node(string name_in, Node* p_next_in){this->name=name_in;this ->p_next=p_next_in;};
string getName(){return name;};
void setName(string name_in){this->name=name_in;};
Node* getNext()
{
   return p_next;
}
void setNext(Node* p_next_in){this ->p_next=p_next_in;};
};


class Queue
{
private:
Node* p_head;
public:
Queue(){p_head=nullptr;}
void addNode(string name_in){p_head = new Node(name_in,p_head);}
string removeNode()
{
    string removed_name;
    for (Node* i=p_head;i!=nullptr;i=i->getNext())
    {
        if (i->getNext()==nullptr && i==p_head)
        {
            removed_name=i->getName();
            delete p_head;

        }
        else if (i->getNext()->getNext()==nullptr)
        {
            
            removed_name=i->getNext()->getName();
            delete  i->getNext();
            i->setNext(nullptr);
            break;


        }
    }
    return removed_name;
}
void printQueue()
{
    cout << "Current Queue: " << endl;
     for (Node* i=p_head;i!=nullptr;i=i->getNext())
     {
         cout << i->getName() << endl;
     }
    
}
~Queue()
{
    while (p_head!=nullptr)
    {
        removeNode();
    }
}
};

int main()
{
    Queue line;
line.addNode("james");
line.addNode("greg");
line.addNode("sarah");
line.addNode("catherine");
line.addNode("julie");
line.addNode("alex");
line.printQueue();
cout<<" > removing "<<line.removeNode()<<" from queue."<<endl;
cout<<" > removing "<<line.removeNode()<<" from queue."<<endl;
line.printQueue();
line.addNode("jack");
line.addNode("angela");
line.printQueue();

    return 0;
}