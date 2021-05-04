#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d) //Insert elements in Queue
{
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;

    if((r==NULL)&&(f==NULL)){
        f = r = n;
        r->next = f;
    }
    else{
        r->next = n;
        r = n;
        n->next = f;
    }
}
void dequeue() {// Delete an element from Queue
    struct node* t;
    t = f;

    if((f==NULL)&&(r==NULL))
        printf("\nQueue underflow");
    else if(f == r){
        f = r = NULL;
        free(t);
    }
    else{
        f = f->next;
        r->next = f;
        free(t);
    }


}
void display(){ // Print the elements of Queue
    struct node* t;
    t = f;
    if((f==NULL)&&(r==NULL))
        printf("\nQueue is Empty");
    else{
        do{
            printf(" %d",t->data);
            t = t->next;
        }while(t != f);
    }
    cout << "\n" << endl;
}
int main(){

    enqueue(2);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    enqueue(7);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}