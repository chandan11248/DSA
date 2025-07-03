#include<iostream>
using namespace std;

class Node{
  public:
    Node* next;
    Node* prev;
    int data;  
    Node(int val){
        next = prev = NULL;
        data = val;
    }
};

class List{
    public:
        Node* head;

        List(){
            head = NULL;
        }

        void pushFront(int val){
            Node* newNode = new Node(val);
            if (head == NULL){
                head = newNode;
            }
            else{
                newNode -> next = head;
                head -> prev = newNode;
                head = newNode;
            }
        }

        void pushBack(int val){
            Node* newNode = new Node(val);
            if (head == NULL){
                head = newNode;
            }
            else{
                Node* temp = head;
                while(temp -> next != NULL){
                    temp = temp -> next;
                }
                temp -> next = newNode;
                newNode -> prev = temp;
            }
        }

        void insertAfterSp(int val, int spData){
            Node* newNode = new Node(val);
            if(head == NULL){
                cout << "List is empty specific val not found" << endl;
                return;
            }
            Node* temp = head;
            while(temp ->data != spData ){
                temp = temp -> next;
                if(temp == NULL){
                    cout << "Data Not Found" << endl;
                    return;
                }
            }
            newNode -> next = temp -> next;
            newNode -> prev = temp;
            temp -> next = newNode;
        }

        void insertBeforeSp(int val, int spData){
            Node* newNode = new Node(val);
            if(head == NULL){
                cout << "List is empty specific val not found" << endl;
                return;
            }
            Node* temp = head;
            while(temp ->data != spData ){
                temp = temp -> next;
                if(temp == NULL){
                    cout << "Data Not Found" << endl;
                    return;
                }
            }
            newNode -> prev = temp -> prev;
            newNode -> next = temp;
            (temp->prev) -> next =newNode;
            temp -> prev = newNode;
        }

        void popFront(){
            if(head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            else{
                Node* temp = head;
                head = head -> next;
                if(head != NULL){
                    head -> prev = NULL;
                }
                temp -> next = NULL;
                delete temp;
                
            }
        }

        void popEnd(){
            if(head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            else{
                Node* temp = head;
                Node* prev = temp;
                while(temp->next != NULL){
                    temp = temp -> next;
                }
                prev = temp -> prev;
                prev -> next = NULL;
                temp -> prev = NULL;
                delete temp;
            }
        }

        void deleteAfterSp(int spData){
            if(head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            else{
                Node* temp = head;
                Node* afterNode = temp;
                while(temp ->data != spData ){
                    temp = temp -> next;
                    if(temp == NULL){
                        cout << "Data Not Found" << endl;
                        return;
                    }
            }
            if(temp -> next == NULL){
                cout << "It is last node: "<< endl;
                return;
            }
            afterNode = temp -> next;
            temp -> next = afterNode -> next;
            if(afterNode->next != NULL){
                (afterNode -> next)->prev = temp;
            }
            afterNode -> next = afterNode -> prev = NULL;
            delete afterNode;
            }
        }

        void deleteBeforeSp(int spData){
            if(head == NULL){
                cout << "List is empty" << endl;
                return;
            }
            else{
                Node* temp = head;
                Node* beforeNode = temp;
                while(temp ->data != spData ){
                    temp = temp -> next;
                    if(temp == NULL){
                        cout << "Data Not Found" << endl;
                        return;
                    }
            }
            if(temp -> prev == NULL){
                cout << "It is first node: "<< endl;
                return;
            }
            beforeNode = temp -> prev;
            temp -> prev = beforeNode -> prev;
            if(beforeNode->prev != NULL){
                (beforeNode -> prev)->next = temp;
            }
            beforeNode -> next = beforeNode -> prev = NULL;
            delete beforeNode;
            }
        }

        void display(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " <=> " ;
            temp = temp ->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    List ll;
    int choice, val, sp;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Push Front\n2. Push Back\n3. Insert After Specific\n4. Insert Before Specific\n";
        cout << "5. Pop Front\n6. Pop End\n7. Delete After Specific\n8. Delete Before Specific\n";
        cout << "9. Display\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            ll.pushFront(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            ll.pushBack(val);
            break;
        case 3:
            cout << "Enter specific value and new value: ";
            cin >> sp >> val;
            ll.insertAfterSp(sp, val);
            break;
        case 4:
            cout << "Enter specific value and new value: ";
            cin >> sp >> val;
            ll.insertBeforeSp(sp, val);
            break;
        case 5:
            ll.popFront();
            break;
        case 6:
            ll.popEnd();
            break;
        case 7:
            cout << "Enter specific value: ";
            cin >> sp;
            ll.deleteAfterSp(sp);
            break;
        case 8:
            cout << "Enter specific value: ";
            cin >> sp;
            ll.deleteBeforeSp(sp);
            break;
        case 9:
            ll.display();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}