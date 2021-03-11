//
// Created by ntwar on 3/11/2021.
//
#include <iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};


void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int(size);
}

void enqueue(struct Queue *q, int x){
    if(q->rear == (q->size - 1)){
        cout << "Que is full" << endl;
    }
    if(q->front == -1 && q->rear == -1){
        q->front = 0;
        q->rear=0;
    }
    else q->rear = q->rear + 1;

    q->Q[q->rear] = x;
}

void dequeue(struct Queue *q){
    if(q->front > q->rear || q->front == -1)
        cout << "Que is already empty" << endl;
    else{
        q->front = ++q->front;
    }
}

void display(struct Queue *q){
    for(int i=q->front; i <= q->rear; i++){
        cout << q->Q[i] << " ";
    }
}

int main(){
    struct Queue *queue = (struct Queue*)malloc(sizeof(Queue));
    create(queue,10);
    enqueue(queue,23);
    enqueue(queue,54);
    enqueue(queue,13);
    enqueue(queue,39);
    display(queue);

    enqueue(queue,40);
    cout << endl;

    dequeue(queue);
    cout << endl;

    display(queue);

    return 0;
}
