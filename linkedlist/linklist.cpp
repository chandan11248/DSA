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
class List
{
    public:
    node* head;
    node* tail;
    List()
    {
        head=tail=NULL;
    }
int pushfront(int val){
    node* newnode = new node(val);
    if (head==NULL)
    {
        head=tail=newnode;
    }
else {
    newnode->next=head;
    head=newnode;
}

}

};

int main()
{
 List ll;
 ll.pushfront(3);
 



    return 0;
}