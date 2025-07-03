#include<iostream>
using namespace std;

struct node{
    int data;
    int next;
};

class Static_List{
    private:
        static const int size=100;
        node n[size];
        int list;
        int avial;
        int getnode(int x){
            if(avial==-1){
                cout<<"Overflow" << endl;
                return -1;
            }
            else{
                int index;
                index=avial;
                avial=n[index].next;
                n[index].data=x;
                n[index].next=-1;
                return index;
            }
        }
        void freenode(int index){
            n[index].next=avial;
            avial=index;
            if(index==list){
                list=-1;
            }
        }
        void initalize(){
            for (int i=0;i<size;i++){
                n[i].next=i+1;
            }
            n[size-1].next=-1;
        }
    public:
        Static_List():list(-1),avial(0){
            initalize();
        }
        void insertBeg(int x){
            int index=getnode(x);
            if(index == -1) return;
            n[index].next=list;
            list=index;
        }
        void insertEnd(int x){
            if(list==-1){
                insertBeg(x);
                return;
            }
            int index=getnode(x);
            if(index == -1) return;
            int i=list;
            while(n[i].next!=-1){
                i=n[i].next;
            }
            n[i].next=index;
        }
        void insertAfter(int x,int sp){
            if(list==-1){
                insertBeg(x);
                return;
            }
            int i=list;
            while(i != -1 && n[i].data!=sp){
                i=n[i].next;
            }
            if(i == -1){
                cout << "Element not found." << endl;
                return;
            }
            int index=getnode(x);
            if(index == -1) return;
            n[index].next=n[i].next;
            n[i].next=index;
        }
        void deletionBeg(){
            if(list==-1){
                cout<<"Underflow"<<endl;
                return;
            }
            int index=list;
            list=n[list].next;
            int del_item=n[index].data;
            freenode(index);
            cout<<"The deleted item is :"<<del_item<<endl;
        }
        void deletionEnd(){
            if(list==-1){
                cout<<"Underflow"<<endl;
                return;
            }
            int i = list;
            int prev = -1;
            while(n[i].next != -1){
                prev = i;
                i = n[i].next;
            }
            int del_item = n[i].data;
            if(prev == -1){
                // Only one node
                list = -1;
            }else{
                n[prev].next = -1;
            }
            freenode(i);
            cout << "The deleted item is: " << del_item << endl;
        }
        void deletionAfter(int sp){
            if(list==-1){
                cout<<"Underflow"<<endl;
                return;
            }
            int i = list;
            while(i != -1 && n[i].data != sp){
                i = n[i].next;
            }
            if(i == -1 || n[i].next == -1){
                cout << "No node exists after the specified item." << endl;
                return;
            }
            int del_index = n[i].next;
            int del_item = n[del_index].data;
            n[i].next = n[del_index].next;
            freenode(del_index);
            cout << "The deleted item after " << sp << " is: " << del_item << endl;
        }
        void display(){
            if(list == -1){
                cout << "List is empty." << endl;
                return;
            }
            int i = list;
            cout << "List: ";
            while(i != -1){
                cout << n[i].data << " ";
                i = n[i].next;
            }
            cout << endl;
        }
};

int main(){
    Static_List sl;
    sl.insertBeg(12);
    sl.insertEnd(23);
    sl.insertEnd(50);
    sl.display();
    sl.insertAfter(40,12);
    sl.display();
    sl.deletionBeg();
    sl.display();
    sl.deletionAfter(23);
    sl.display();
    \
    return 0;

    
}