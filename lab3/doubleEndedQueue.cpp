#include <iostream>
using namespace std;

#define SIZE 10  

class Deque {
private:
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

   
    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }


    bool isEmpty() {
        return (front == -1);
    }

    
    void addFront(int value) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        arr[front] = value;
    }

   
    void addRear(int value) {
        if (isFull()) {
            cout << "Deque is full\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = value;
    }

   
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deleted from front: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // d. Delete from end
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deleted from rear: " << arr[rear] << endl;
        if (front == rear) {
            front = rear = -1; 
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;

   int x;
int add;
    while (1) {
        
        cout << "\n1.addfront\n2.addrear\n3.deletefront\n4.deleterear\n5.display\nChoose: ";
        cin >> x;
        switch (x) {
            case 1:

            cout<<"enter the  integer:";
            cin>>add;
             dq.addFront(add);
                break;
            case 2:
            cout<<"enter the  integer:";
            cin>>add;
                dq.addRear(add);
                break;
            case 3:
            dq.deleteFront();
            break;
            case 4:
            dq.deleteRear();
            break;
             case 5:
            dq.display();
            break;
            default:
            cout << "INVALID CHOICE" << endl;
        }
    }
    return 0;

}
