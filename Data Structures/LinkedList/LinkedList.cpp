#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

struct Node *start = NULL;

void traverse(){
    struct Node* temp;
    if(start == NULL)
        cout<<"\nEmpty list\n";
    else{
        temp = start;
        while(temp != NULL) {
            cout<<"\t\tData = "<<temp->data<<endl;
            temp = temp -> next;
            cout<<"\t\t";
        }
    }
}
//Inserting at head
void insertAtHead(){
    int value;
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter number to be inserted: \n";
    cin>>value;
    temp->data = value;
    temp->next=start;
    start = temp;
}
//inserting at the end
void insertAtEnd(){
    int value;
    struct Node *temp, *head;
    temp = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter number to be inserted: \n";
    cin>>value;
    temp->next = NULL;
    temp->data = value;
    head = start;
    while(head->next != NULL){
        head= head->next;
    }
    head->next = temp;
}
//Inserting at the specified node
void insertAtPosition(){
    struct Node *temp, *newnode;
    int pos, value, i = 1;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    cout<<"Enter position and value you want to insert\n";
    cin>>pos;
    cin>>value;
    temp = start;
    newnode->data = value;
    newnode->next = NULL;
    while(i < pos - 1){
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
//Deleting from the front
void deleteFirst(){
    struct Node *temp;
    if(start == NULL){
        cout<<"\n List is empty\n";
    }else{
        temp = start;
        start = start->next;
        free(temp);
    }
}
//Deleting from the end
void deleteEnd(){
    struct Node *temp, *prevnode;
    if(start == NULL){
        cout<<"\nList is empty\n";
    }else{
        temp = start;
        while(temp->next != NULL){
            prevnode = temp;
            temp = temp->next;
        }
        free(temp);
        prevnode->next = NULL;
    }
}
//Deleting from the specified node
void deletePosition(){
    struct Node *temp, *position;
    int i = 1, pos;
    if(start == NULL){
        cout<<"\nList is empty\n";
    }else{
        cout<<"Enter index: \n";
        cin>>pos;
        position = (struct Node*)malloc(sizeof(struct Node));
        temp = start;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        position = temp->next;
        temp->next = position->next;
        free(position);
    }
}
int main(){
    int choice;
    while (1) {
        cout<<"|-------------------------------------------------|\n";
        cout<<"|                   LINKED MENU                   |\n";
        cout<<"|-------------------------------------------------|\n";
        cout<<"|               1. List Elements                  |\n";
        cout<<"|               2. At head insertion              |\n";
        cout<<"|               3. At tail insertion              |\n";
        cout<<"|               4. Insertion at any position      |\n";
        cout<<"|-------------------------------------------------|\n";
        cout<<"|               5. At head deletion               |\n";
        cout<<"|               6. At tail deletion               |\n";
        cout<<"|               7. Deletion at any position       |\n";
        cout<<"|-------------------------------------------------|\n";
        cout<<"|-------------------------------------------------|\n";
        cin>>choice;
        switch (choice){
            case 1:
                traverse();
                break;
            case 2:
                insertAtHead();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                insertAtPosition();
                break;
            case 5:
                deleteFirst();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                deletePosition();
                break;
            case 8:
                cout<<"See you!\n";
                exit(1);
                break;
            default:
                printf("Incorrect Choice\n");
        }
    }
    return 0;
}