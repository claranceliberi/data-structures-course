//
// Created by ntwar on 3/11/2021.
//
#include <iostream>
#include <climits>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* top;

void push(int data){
    Node* temp = new Node();

    if(!temp){
        cout << " Heap overflow";
        exit(1);
    }

    temp->data = data;
    temp->next = top;

    top = temp;

}

bool isEmpty(){
    return top == NULL;
}

int peek(){
    if(!isEmpty())
        return top->data;
    else
        exit(1);
}

int pop(){
    Node* temp;

    if(!isEmpty()){
        temp = top;
        int data = temp->data;
        top = top->next;
        temp->next = NULL;
        free(temp);

        return data;
    } else{
        cout << " stack underflow" << endl;
        exit(1);
        return INT_MIN;
    }
}


void display(){
    Node* temp;

    if(isEmpty()){
        cout << "stack underflow" << endl;
        exit(1);
    }else{
        temp = top;

        while(temp){
            cout << temp->data ;
            if (temp->next) cout << "->";

            temp = temp->next;
        }
    }
}

int main(){
    push(10);
    push(14);
    push(23);
    display();
    cout << endl;
    cout << "peaked el " << peek() << endl;
    cout << "popped el" << pop() << endl;
    cout << "peaked el " << peek() << endl;

    display();
    cout << endl;


    return 0;
}
