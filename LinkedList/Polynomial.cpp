//
// Created by ntwar on 3/3/2021.
//
#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    int numberOfTerms; //initiation
    char variable; // initiation
    int coefficient;
    int exponent;
    struct Node *next;
} * head = NULL;


void createPolynomial(int numberOfTerms,char variable){
    head = new Node;
    //setting variable and number of terms;
    head->numberOfTerms = numberOfTerms;
    head->variable = variable;

    Node *t, *last;
    int coefficient,exponent;

    last = head;


    cout << endl;
    cout << "Term " << 1 << endl;
    cout << "Enter coefficient : ";
    cin >> coefficient;
    cout << "Enter exponent : ";
    cin >> exponent;
    cout << endl << endl;

    last->coefficient = coefficient;
    last->exponent = exponent;


    for(int i=1; i<numberOfTerms; i++){
        t = new Node;

        cout << endl;
        cout << "Term " << i + 1 << endl;
        cout << "Enter coefficient : ";
        cin >> coefficient;
        cout << "Enter exponent : ";
        cin >> exponent;
        cout << endl << endl;

        t->coefficient = coefficient;
        t->exponent = exponent;

        last->next = t;
        last = last->next;

    }

}

char variable ;

void displayPolynomial(struct Node *polynomial){
    if(polynomial->variable)
        variable = polynomial->variable;

    cout << "f(" << variable << ") = ";
    while(polynomial != NULL){
        cout << polynomial->coefficient << variable << "^" << polynomial->exponent ;

        if(polynomial->next)
            cout << " + ";

        polynomial = polynomial->next;
    }

    cout << endl;
}

void calculatePolynomial(struct Node *poly,int variable){
    int total = 0;

    while(poly){
        total += poly->coefficient * pow(variable,poly->exponent);
        poly = poly->next;
    }

    cout << "f(" << variable << ") = " << total << endl;
}

int main(){

    createPolynomial(3,'x');

    displayPolynomial(head);

    calculatePolynomial(head,2);
    return 0;
}



