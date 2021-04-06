
#include<bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;
} * start = NULL;

//inserting at the end
void createLinkedPerindrome(char string[],int size){
    struct Node *temp, *head;

    temp = new Node;
    temp->next = NULL;
    temp->data = string[0];
    temp = temp->next;

    for (int i=1; i< size; i++){
        temp->next = NULL;
        temp->data = string[i];
        temp = temp->next;
    }

}

// Function to check if the linked list
// is palindrome or not
bool isPalindrome(Node* head){

    // Temp pointer
    Node* slow= head;

    // Declare a stack
    stack <char> s;


    // Push all elements of the list
    // to the stack
    while(slow != NULL){
        s.push(slow->data);

        // Move ahead
        slow = slow->next;
    }

    // Iterate in the list again and
    // check by popping from the stack
    while(head != NULL ){

        // Get the top most element
        int i=s.top();

        // Pop the element
        s.pop();

        // Check if data is not
        // same as popped element
        if(head -> data != i){
            return false;
        }

        // Move ahead
        head=head->next;
    }

    return true;
}

// Driver Code
int main(){



    char string[100];
    cout << "enter a string" << endl;
    cin >> string ;

    if(isPalindrome(start))
        cout<<"word is a palindrome " << endl;
    else
        cout<<"word is not palindrome " << endl;

    return 0;
}
 