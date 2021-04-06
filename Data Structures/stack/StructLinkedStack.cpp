//
// Created by ntwar on 3/11/2021.
//
#include <iostream>
#include <climits>

using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* top;


void push(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

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
    struct Node* temp;

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
    struct Node* temp;

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