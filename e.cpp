#include <iostream>
using namespace std;

class CircularQueue {
    static const int SIZE = 5;  // fixed size (static array)
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }
bool isfull()
{
    if(count==SIZE){
        return true;
    }
    else{
        return false;
    }
}
bool isempty()
{
    if(count==0){
        return true;
    }
    else{
        return false;
    }
}
    void enqueue(int v){
     if(isfull()==true)
     {
        cout<<"queue full";

     }
     else{
                if (isempty())
            front = 0;
        rear = (rear+1)%SIZE;

        arr[rear]=v;
        count++;
     }}
void dequeue(){
     if(isempty()==true)
     {
        cout<<"queue empty";

     }
     else{
        front = (front+1)%SIZE;
        count--;
     }
    }
void display(){
    cout<<endl;
    for(int i=0;i<count;i++){
        cout<<arr[(front+i)%SIZE]<<"  ";
    }

}

};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.enqueue(60);
    q.enqueue(70);
    q.display();

    return 0;
}