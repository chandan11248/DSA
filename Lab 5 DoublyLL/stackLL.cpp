#include <iostream>
using namespace std;

class Node{
    public:
        Node* next;
        int data;
        Node(int val){
            data = val;
            next = NULL;
        }
};

class Stack{
    public:
        Node* head;
        Stack(){
            head = NULL;
        }

        void push(int val){
            Node* newNode = new Node(val);
            if(head == NULL){
                head = newNode;
                return;
            }
            else{
                newNode ->next = head;
                head = newNode;
            }
        }

        void pop(){
            if(head == NULL){
                cout << "Stack is already Empty" << endl;
                return;
            }
            Node* temp = head;
            head = head -> next;
            temp -> next = NULL;
            delete temp;
        }

        void display(){
            if(head == NULL){
                cout << "Stack is Empty" << endl;
                return;
            }
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " | " ;
                temp = temp -> next;
            }
            cout << endl;
        }
};
int main() {
    Stack sll;
    int choice;

    while (true) {                       // <-- infinite loop
        cout << "\n--- Stack Menu ---\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Display\n"
             << "4. Exit\n"
             << "Enter choice: ";
        if (!(cin >> choice)) {          // handle non-integer input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            continue;
        }

        switch (choice) {
            case 1: {
                int val;
                cout << "Value to push: ";
                cin >> val;
                sll.push(val);
                break;
            }
            case 2:
                sll.pop();
                break;
            case 3:
                sll.display();
                break;
            case 4:                      // terminate loop (optional)
                cout << "Good-bye!\n";
                return 0;
            default:
                cout << "Choose 1-4 only.\n";
        }
    }
}