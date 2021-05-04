//
// Created by ntwar on 5/4/2021.
//

// C++ code to implement Priority Queue
// using Linked List
#include <bits/stdc++.h>
using namespace std;

// Node
typedef struct node
{
    int data;

    // Lower values indicate
    // higher priority
    int priority;

    struct node* next;

} Node;

//  create a new node
Node* newNode(int data, int priority)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    return temp;
}

// Return the value at head
int peek(Node** head)
{
    return (*head)->data;
}

// Removes the element with the highest priority form the list
void pop(Node** head)
{
    Node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

// push according to priority
void push(Node** head, int data, int priority){
    Node* start = (*head);

    Node* temp = newNode(data, priority);

    // Special Case: The head of list has
    // lesser priority than new node. So
    // insert newnode before head node
    // and change head node.
    if ((*head)->priority > priority)
    {

        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else
    {

        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->priority < priority)
        {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}

// Function to check is list is empty
int isEmpty(Node** head)
{
    return (*head) == NULL;
}

// Driver code
int main()
{


    Node* pq = newNode(4, 1);
    push(&pq, 5, 2);
    push(&pq, 6, 3);
    push(&pq, 7, 0);

    while (!isEmpty(&pq))
    {
        cout << " " << peek(&pq);
        pop(&pq);
    }
    return 0;
}

// This code is contributed by shivanisinghss2110
