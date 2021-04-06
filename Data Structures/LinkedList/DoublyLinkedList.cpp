#include <iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*head=NULL;

void createDLL(int A[], int n){
    head = new Node;
    head->data=A[0];
    head->prev = head->next= NULL;
    Node *t, *last;
    int i;
    last=head;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void display(struct Node *p){
    while(p){
        cout<<p->data;
        p=p->next;
    }
}
void insert_at_head(int value){
    Node *t = new Node;
    t->data = value;
    t->next = head;
    t->prev = NULL;
    head->prev = t;
    head = t;
}
void insert_at_tail(int value){
    Node *t = new Node;
    t->data = value;
    Node *p = head;
    while(p->next!=NULL) p=p->next;
    p->next = t;
    t->prev = p;
    t->next = NULL;
}
void insert_after_given_node(int value, int data_given){
    Node *t = new Node;
    t->data = value;
    Node *p = new Node;
    p = head;
    while(p->data!=data_given) p = p->next;
    t->next = p->next;
    t->next = p->next;
    t->prev = p;
    p->next->prev=t;
    p->next = t;
}
void delete_at_given_node(Node *start, int given_data){
    Node * temp, ptr = start;

    while(ptr->data != given_data) ptr = ptr->next;

    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    delete temp;

}


int main(){
    int A[] = {30, 20, 40, 40, 50};
    createDLL(A,5);
    cout << "All Data: " << endl;
    //display(head);
    insert_at_head(500);
    //display(head);
    insert_after_given_node(20,40);
    display(head);
}