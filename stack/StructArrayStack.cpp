//
// Created by ntwar on 3/11/2021.
//

#include <iostream>
#include <climits>

using namespace std;

struct Stack{
    int top;            //pointing to top element
    unsigned capacity;  //capacity of the stack
    int* array;         //data in the stuck
};

//function create stack of given capacity it initializes size of stack as 0
struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
}

//is stack full
bool isFull(struct Stack* stack){
    return stack->top == stack->capacity -1;
}

//if stack is empty
bool isEmpty(struct Stack* stack){
    return stack->top == -1;
}


//add item to stack
void push(struct Stack* stack, int item){
    if(isFull(stack)){
        cout << "stack overflow" << endl;
        return;
    }

    stack->array[++stack->top] = item;
    cout << item << " pushed to stack " << endl;
}


//remove item on stack
int pop(struct Stack* stack){
    if(isEmpty(stack)){
        cout << "stack underflow" << endl;
        return INT_MIN;
    }

    return stack->array[stack->top--];
}

//return top number of array
int peek(struct Stack* stack){
    if(isEmpty(stack))
        return INT_MIN;

    return stack->array[stack->top];
}

int main(){
    struct Stack* stack = createStack(10);

    cout << "is stack full " << isFull(stack) << endl;
    cout << "is stack emtpy  " << isEmpty(stack) << endl;

    push(stack,22);
    push(stack,32);

    cout << "poped el " << pop(stack) << endl;
    cout << "peeked el " << peek(stack) << endl;

    return 0;
}


