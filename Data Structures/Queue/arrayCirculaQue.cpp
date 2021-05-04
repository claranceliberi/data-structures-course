#include <iostream>
using namespace std;

int* createCQueue(int size){
    int *array = new int[size] ;
    return array;
}

int main(){
    int* queue = createCQueue(10);

    return 0;
}