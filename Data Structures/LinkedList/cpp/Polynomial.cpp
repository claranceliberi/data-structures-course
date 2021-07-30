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


Node  *createPolynomial(int numberOfTerms,char variable){
    Node *headNode;

    headNode = new Node;
    //setting variable and number of terms;
    headNode->numberOfTerms = numberOfTerms;
    headNode->variable = variable;

    Node *t, *last;
    int coefficient,exponent;

    last = headNode;


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

    return headNode;
}


void displayPolynomial(struct Node *polynomial){
    char variable ;

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

Node *sumOfPolynomial(Node *fp, Node *sp){
    //fp first polynomial;
    //sp second polynomial;

    Node *sum, *last, *temp;
    last = new Node;
    last->next = new Node;
    last->next->variable = fp->variable;
    sum = last;


    while(fp && sp){
        if(fp->exponent > sp->exponent){
            temp = new Node;
            temp->exponent = fp->exponent;
            temp->coefficient = fp->coefficient;
            temp->next = NULL;
            last->next = temp;
            last = last->next;
            fp = fp->next;

        }
        else if(sp->exponent > fp->exponent){
            temp = new Node;
            temp->exponent = sp->exponent;
            temp->coefficient = sp->coefficient;
            temp->next = NULL;
            last->next = temp;
            last = last->next;
            sp = sp->next;
        }
        else{
            temp = new Node;
            temp->exponent = fp->exponent;
            temp->coefficient = sp->coefficient + fp->coefficient;
            temp->next = NULL;
            last->next = temp;
            last = last->next;
            sp = sp->next;
            fp = fp->next;
        }


    }

    while(fp || sp){
        if(fp){
            temp = new Node;
            temp->exponent = fp->exponent;
            temp->coefficient = fp->coefficient;
            temp->next = NULL;
            last->next = temp;
            last = last->next;
            fp = fp->next;
        }
        if(sp){
            temp = new Node;
            temp->exponent = sp->exponent;
            temp->coefficient = sp->coefficient;
            temp->next = NULL;
            last->next = temp;
            last = last->next;
            sp = sp->next;
        }


    }
    return sum->next;
}


int main(){

    int numberOfTermsOfPolynomial, valueOfTheVariable;
    char variableOfThePolynomial;

    Node *firstPolynomial, *secondPolynomial, *sum;

    cout << " CREATE FIRST POLYNOMIAL " << endl;
    cout << " Enter number of coefficient :" ;
    cin >> numberOfTermsOfPolynomial;
    cout << " Enter variable character of the polynomial (x or y):" ;
    cin >> variableOfThePolynomial;
    cout << endl;
    
    firstPolynomial = createPolynomial(numberOfTermsOfPolynomial,variableOfThePolynomial);


    cout << " CREATE SECOND POLYNOMIAL " << endl;
    cout << " Enter number of coefficient :" ;
    cin >> numberOfTermsOfPolynomial;
    cout << " Enter variable character of the polynomial (x or y):" ;
    cin >> variableOfThePolynomial;
    cout << endl;

    secondPolynomial = createPolynomial(numberOfTermsOfPolynomial,variableOfThePolynomial);


    cout << " ___ DISPLAY ___ " << endl;
    
    cout << "first polynomial " << endl;
    displayPolynomial(firstPolynomial);
    
    cout << "second polynomial " << endl;
    displayPolynomial(secondPolynomial);


    //space
    cout << "\n\n\n";
    
    cout << " ___ CALCULATION ___ " << endl << endl;
    
    cout << "first polynomial " << endl;
    cout << "enter value for " << firstPolynomial->variable << " : ";
    cin >> valueOfTheVariable ;
    calculatePolynomial(firstPolynomial,valueOfTheVariable);

    //space
    cout << "\n";

    cout << "second polynomial " << endl;
    cout << "enter value for " << secondPolynomial->variable << " : ";
    cin >> valueOfTheVariable;
    calculatePolynomial(secondPolynomial,valueOfTheVariable);

    //space
    cout << "\n\n\n";

    cout << " ___ ADDITION ___ " << endl << endl;

    cout << "addition of first and second polynomial " << endl;
    sum = sumOfPolynomial(firstPolynomial,secondPolynomial);

    displayPolynomial(sum);
//    calculatePolynomial(secondPolynomial,valueOfTheVariable);


    return 0;
}



