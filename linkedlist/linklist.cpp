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
   node*tail;
   public:
    List(){
        head=tail=NULL;
    } 
void push_front(int val){
    node* newnode=new node(val);
    if (head==NULL)
    {
        head=tail=newnode;
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
    node* newnode1=new node(val);
    if(head==NULL)
    {
        head=tail=newnode1;
    }
else{

tail->next=newnode1;
tail=newnode1;


}

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
