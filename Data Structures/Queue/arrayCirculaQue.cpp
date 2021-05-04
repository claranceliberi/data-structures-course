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


int main(){
    int* queue = createCQueue(SIZE);

    cout << isFull() << " and " << isEmpty() << endl;
    return 0;
}