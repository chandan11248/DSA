#include<iostream>
using namespace std;
 class node {
 
 public:
int data;
 
 node* next;
 node(int val)
 {
    data=val;
    next=NULL;

 }
 };


 class  List{
   node* head;
   public:
    List(){
        head==NULL;
    } 
void push_front(int val){
    node* newnode=new node(val);
    if (head==NULL)
    {
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;

    }
}
void display(){
    node* temp;
    temp=head;
    while (temp!=NULL)

    {
    cout<<temp->data;
    cout<<"->";
    temp=temp->next;

    }
    cout<<"NULL";
}

void push_back(int val){
    node* temp;
    temp=head;
    node* newnode=new node(val);
    if (head==NULL)
    {
        head=newnode;
    }
    else{
            while (temp->next!=NULL)
    {
    temp->next=newnode;
newnode->next=NULL;
    }


    }

    
 }

void pop_front()
{
    
}
void pop_front()
{
    
}



 };

 int main()
 {
    List ll;
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);

    ll.display();
    cout<<endl;
    ll.push_back(50);
    ll.display();

    return 0;
 }
