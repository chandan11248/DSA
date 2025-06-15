#include <iostream>
#define MAX 5
using namespace std;


template<class T>
class CircularQueue{
    private:
        T queue[MAX];
        int front, rear;
    public:
        CircularQueue(){
            front = -1;
            rear = -1;
        }
       
        bool isEmpty(){
            return (front == -1);
        }
       
        bool isFull(){
            return ((rear + 1) % MAX == front);
        }
       
        void enqueue(T item){
            if(isFull()){
                throw std::overflow_error("Queue Overflow: Circular queue is full.");
            }
            if(isEmpty()){
                front = 0;
            }
            rear = (rear + 1) % MAX;
            queue[rear] = item;
        }
       
        T dequeue(){
            if(isEmpty()){
                throw std::underflow_error("Queue Underflow: Circular queue is empty.");
            }
            T item = queue[front];
            if(front == rear){ 
                front = rear = -1;
            } else {
                front = (front + 1) % MAX;
            }
            return item;
        }
       
        void display(){
            if(isEmpty()){
                std::cout << "Queue is empty.\n";
                return;
            }
            std::cout << "Circular Queue elements: ";
            int i = front;
            while(true){
                std::cout << queue[i] << " ";
                if(i == rear) break;
                i = (i + 1) % MAX;
            }
            std::cout << std::endl;
        }
};


int main(){
    CircularQueue<int> cq;



int x;
int add;
    while (1) {
        
        cout << "\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nChoose: ";
        cin >> x;
        switch (x) {
            case 1:

            cout<<"enter the  integer:";
            cin>>add;
             cq.enqueue(add);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
            cq.display();
            break;
            default:
            cout << "INVALID CHOICE" << endl;
        }
    }
    return 0;

}





  
