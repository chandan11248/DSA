#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }

};
class list
{
    node* head;
    node* tail;
    list()
    {
        head=tail=NULL;
    }

};

int main()
{


    return 0;
}