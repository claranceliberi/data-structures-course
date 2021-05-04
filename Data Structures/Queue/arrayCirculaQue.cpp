#include <iostream>
using namespace std;

#define SIZE 5
int front = -1, rear = -1;

//create and return array of circular que
int* createCQueue(int size){
    int *array = new int[size] ;
    return array;
}

//check whether circular que is full
int isFull(){
    if((front == 0 && rear == SIZE - 1) || (front == rear + 1))
        return 1;
    return 0;
}

//check whether que is full or empty
int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}

// add element to que
int enQueue(int *queue, int data){

    //check over flow
    if(isFull()){
        cout << "Queue overflow" << endl;
        return 0;
    }

    if(isEmpty())
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = data;

    return 1;
}

//delete element from array
int deQueue(int *queue){
    int element;

    if(isEmpty()){
        cout << "Queue underflow" << endl;
        return -1;
    }

    element = queue[front];
    front = (front + 1 ) % size;

//    if que is left empty make front and real to -1
    if(front == rear){
        front = rear = -1;
    }

    return element

}

int main(){
    int* queue = createCQueue(SIZE);
    enQueue(queue,3);
    enQueue(queue,4);
    enQueue(queue,1);
    enQueue(queue,23);

//    cout << queue[0] << endl;
//    cout << isFull() << " and " << isEmpty() << endl;
    return 0;
}