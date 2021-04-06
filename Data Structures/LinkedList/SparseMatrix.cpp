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

//
//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//
//struct Node
//{
//    int value;
//    int row_position;
//    int column_postion;
//    struct Node *next;
//};
//
//void create_new_node(struct Node** start, int non_zero_element,
//                     int row_index, int column_index )
//{
//    struct Node *temp, *r;
//    temp = *start;
//    if (temp == NULL)
//    {
//
//        temp = (struct Node *) malloc (sizeof(struct Node));
//        temp->value = non_zero_element;
//        temp->row_position = row_index;
//        temp->column_postion = column_index;
//        temp->next = NULL;
//        *start = temp;
//
//    }
//    else
//    {
//        while (temp->next != NULL)
//            temp = temp->next;
//
//        // Create new node dynamically
//        r = (struct Node *) malloc (sizeof(struct Node));
//        r->value = non_zero_element;
//        r->row_position = row_index;
//        r->column_postion = column_index;
//        r->next = NULL;
//        temp->next = r;
//
//    }
//}
//
//
//void createSparceMatrix(Node ** start, int numberOfRows, int numberOfColumns){
//    int numberOfNonZeroElements,columnIndexInRow, value;
//
//    for (int i = 0; i < numberOfRows; i++){
//
//        cout << "Enter Number of non-zero elements for row number " <<i+1<<endl;
//        cin >> numberOfNonZeroElements;
//        for (int j = 0; j < numberOfNonZeroElements; j++){
//            columnIndex:    cout << "Column Index in row: ";
//            cin >> columnIndexInRow;
//            cout << "value: ";
//            cin >> value;
//            if (value != 0 && columnIndexInRow<numberOfColumns){
//                create_new_node(start, value, i, columnIndexInRow);
//            }
//            else{
//                goto columnIndex;
//            }
//        }
//    }
//
//}
//
//
//
//int main(){
//    int choice, numberOfRows, numberOfColumns;
//    struct Node* start = NULL;
//    struct Node* startOne = NULL;
//    struct Node* startTwo = NULL;
//    do{
//        cout << "=================================" << endl;
//        cout << "||  Sparce Matrix Manipulator  ||" << endl;
//        cout << "||   1.Create Sparce Matrix    ||" << endl;
//        cout << "||   2.Display Sparce Matrix   ||" << endl;
//        cout << "||   3.Add two Sparce Matrices ||" << endl;
//        cout << "||   4.Exit                    ||" << endl;
//        cout << "=================================" << endl;
//
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//            case 1:
//                cout << "How many rows does your matrix have: ";
//                cin >> numberOfRows;
//                cout << "How many columns does your matrix have: ";
//                cin >> numberOfColumns;
//                createSparceMatrix(&start,numberOfRows,numberOfColumns);
//                break;
//            case 2:
//                PrintMatrix(&start,numberOfRows,numberOfColumns);
//                break;
//            case 3:
//                cout << "How many rows will your matrices have: ";
//                cin >> numberOfRows;
//                cout << "How many columns will your matrices have: ";
//                cin >> numberOfColumns;
//                cout << "For first Matrix:  "<<endl;
//                createSparceMatrix(&startOne,numberOfRows,numberOfColumns);
//                cout << "For second Matrix:  "<<endl;
//                createSparceMatrix(&startTwo,numberOfRows,numberOfColumns);
//                addSparceMatrix(&startOne, &startTwo, numberOfRows, numberOfColumns);
//                break;
//
//            case 4:
//                return 0;
//                break;
//            default:
//                cout << "Sorry Invalid input";
//                break;
//        }
//    }while (choice!=4);
//
//    return 0;
//}

void PrintMatrix(Node** start, int numberOfRows, int numberOfColumns){

    cout << "========Your Matrix====="<<endl;

    Node *temp = *start;

    for (int i = 0; i < numberOfRows; i++){

        for (int j = 0; j < numberOfColumns; j++){

            if(temp->row_position == i && temp->column_postion == j){
                cout << temp->value << " ";
                if(temp->next!=NULL){
                    temp = temp->next;
                }
            }
            else{
                cout << "0 ";
            }


        }
        cout <<endl;
    }

    cout << "========================"<<endl;


}


void addSparceMatrix(Node** startOne,Node** startTwo,int numberOfRows, int numberOfColumns){

    cout << "========Your Matrix====="<<endl;

    Node *temp = *startOne;
    Node *tempTwo = *startTwo;

    for (int i = 0; i < numberOfRows; i++){

        for (int j = 0; j < numberOfColumns; j++){

            if( (temp->row_position == i && temp->column_postion == j) && (tempTwo->row_position == i && tempTwo->column_postion == j) ){
                cout << temp->value+tempTwo->value << " ";
                if(temp->next!=NULL || tempTwo->next!=NULL){
                    temp = temp->next;
                    tempTwo = tempTwo->next;
                }
            }
            else if( (temp->row_position == i && temp->column_postion == j) ){
                cout << temp->value << " ";
                if(temp->next!=NULL){
                    temp = temp->next;
                }
            }
            else if( (tempTwo->row_position == i && tempTwo->column_postion == j) ){
                cout << tempTwo->value << " ";
                if(tempTwo->next!=NULL){
                    tempTwo = tempTwo->next;
                }
            }
            else{
                cout << " 0 ";
            }

        }
        cout <<endl;
    }

    cout << "========================"<<endl;
}
