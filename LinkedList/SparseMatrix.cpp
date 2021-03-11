//
// Created by ntwar on 3/4/2021.
//

#include <iostream>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */


struct Node {
    int colPosition;
    int rowPosition;
    int value;
    struct Node *next;

} * start = NULL;


void createSparseNode(int rows, int cols ){
    start = new Node;

    Node *temp, *last;

    last = start;
    int numberOfNonZerosValues, columnNumber, value;


    for(int i=0; i< rows; i++){
        enterRow:
        cout << "enter number of non zeros values at row " << i+1 << " : " ;
        cin >> numberOfNonZerosValues;

        if(numberOfNonZerosValues > cols){
            cout << RED << "number is greater than maximum :)" << RESET << endl;
            goto enterRow;
        }

        for(int j =0; j<numberOfNonZerosValues; j++){
            enterCol:
            temp = new Node;

            cout << "\t Enter col number : ";
            cin >> columnNumber;

            if(columnNumber > cols){
                cout << RED << " column number is greater than maximum" << RESET << endl;
                goto enterCol;
            }

            cout  << "\t Enter value at " << columnNumber << " column : ";
            cin >> value;

            if(i==0 && j==0){
                cout << "\nstarting \n";
                last->rowPosition = i;
                last->colPosition = columnNumber - 1;
                last->value = value;
                last->next = NULL;
            }else{
                temp->rowPosition = i;
                temp->colPosition = columnNumber - 1;
                temp->value = value;

                last->next = temp;
                last = last->next;
            }

            cout << endl;
        }
    }

}

//function to display value at a given point if present
// or print 0 if there was no number found at a point
void displayMatrixAtPoint(int row, int col){
    bool numberFound = false;
    struct Node *tmp = start;

    while(tmp != NULL && !numberFound){
        if(tmp->rowPosition == row && tmp->colPosition == col){
            cout << " " << tmp->value << " ";
            numberFound = true;
        }
        tmp = tmp->next;
    }

    if(!numberFound)
        cout << " 0 ";
}

//handle displaying matrix
void displayMatrix(int rows, int cols){

    for(int i = 0; i < rows; i++){
        for( int k=0; k< cols; k++){
            displayMatrixAtPoint(i,k); // display value at point
            cout << "\t" ; //tab to separate values
        }
        cout << "\n" ; // to start new line of new row
    }
}


void addMatrix (int rows, int cols){

}

int main(){

    int rows = 0;
    int cols = 0;

    cout << "number of rows : ";
    cin >> rows;
    cout << "number of cols : ";
    cin >> cols;
    cout << endl;

    createSparseNode(rows,cols);
    displayMatrix(rows,cols);


    return 0;
}