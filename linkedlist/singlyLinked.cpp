#include <iostream>
using namespace std;

class Node {
private:
    int val;
    Node *next;

public:
    Node(int val) : val(val), next(nullptr) {}

    static void insertAtHead(Node* &head, int data) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    static void insertAtTail(Node *head, int val) {
        if (head == nullptr) return;
        Node *temp = head;
        Node *newNode = new Node(val);
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    static void insertAtPosition(Node* &head, int val, int position) {
        if (position < 0) return;

        if (position == 0) {
            insertAtHead(head, val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        int currPos = 0;

        while (currPos != position - 1 && temp != nullptr) {
            temp = temp->next;
            currPos++;
        }

        if (temp == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    static void insertAfterNode(Node* &head, int val, int data) {
        Node* temp = head;
        while (temp != nullptr && temp->val != data) {
            temp = temp->next;
        }

        if (temp == nullptr) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    static void insertBeforeNode(Node* &head, int val, int data) {
        if (head == nullptr) return;

        if (head->val == data) {
            insertAtHead(head, val);
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->val != data) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    static void deleteFromHead(Node* &head) {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    static void deleteFromTail(Node* &head) {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    static void deleteAfterNode(Node* head, int data) {
        if (head == nullptr) return;

        Node* temp = head;
        while (temp != nullptr && temp->val != data) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) return;

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    static void deleteFromPosition(Node* &head, int position) {
        if (head == nullptr || position < 0) return;

        if (position == 0) {
            deleteFromHead(head);
            return;
        }

        int currPosition = 0;
        Node* temp = head;

        while (currPosition != position - 1 && temp != nullptr) {
            temp = temp->next;
            currPosition++;
        }

        if (temp == nullptr || temp->next == nullptr) return;

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    static void display(Node* head) {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    Node* head = nullptr;
    int choice, val, pos, key;

    while (1) {
        cout << "\nLinked List Operations Menu:\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert After Value\n";
        cout << "5. Insert Before Value\n";
        cout << "6. Delete from Head\n";
        cout << "7. Delete from Tail\n";
        cout << "8. Delete from Position\n";
        cout << "9. Delete After Value\n";
        cout << "10. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> val;
                Node::insertAtHead(head, val);
                break;

            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> val;
                if (head == nullptr)
                    Node::insertAtHead(head, val);
                else
                    Node::insertAtTail(head, val);
                break;

            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                Node::insertAtPosition(head, val, pos);
                break;

            case 4:
                cout << "Enter value to insert and existing node value: ";
                cin >> val >> key;
                Node::insertAfterNode(head, val, key);
                break;

            case 5:
                cout << "Enter value to insert and node value before which to insert: ";
                cin >> val >> key;
                Node::insertBeforeNode(head, val, key);
                break;

            case 6:
                Node::deleteFromHead(head);
                break;

            case 7:
                Node::deleteFromTail(head);
                break;

            case 8:
                cout << "Enter position to delete from: ";
                cin >> pos;
                Node::deleteFromPosition(head, pos);
                break;

            case 9:
                cout << "Enter value of node after which to delete: ";
                cin >> key;
                Node::deleteAfterNode(head, key);
                break;

            case 10:
                Node::display(head);
                break;

            case 0:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}