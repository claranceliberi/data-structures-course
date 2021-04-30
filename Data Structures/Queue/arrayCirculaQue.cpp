#include <iostream>
using namespace std;

int arraycqueue[10];
int front = -1, rear = -1, n=5;

void displayCQue() {
    int f = front, r = rear;
    if (front == -1) {
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue elements are :\n";
    if (f <= r) {
        while (f <= r){
            cout<<arraycqueue[f]<<" ";
            f++;
        }
    } else {
        while (f <= n - 1) {
            cout<<arraycqueue[f]<<" ";
            f++;
        }
        f = 0;
        while (f <= r) {
            cout<<arraycqueue[f]<<" ";
            f++;
        }
    }
    cout<<endl;
}

void insertOnCQue(int val) {
   if ((front == 0 && rear == n-1) || (front == rear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (front == -1) {
      front = 0;
      rear = 0;
   } else {
      if (rear == n - 1)
      rear = 0;
      else
      rear = rear + 1;
   }
   arraycqueue[rear] = val ;
}
void deleteOnCQue() {
   if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<arraycqueue[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}

int main() {

   int choice, val;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";

   do {
      cout<<"Enter choice : "<<endl;
      cin>>choice;
      switch(choice) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         insertOnCQue(val);
         break;

         case 2:
         deleteOnCQue();
         break;

         case 3:
         displayCQue();
         break;

         case 4:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect  choice!\n";
      }
   } while(choice != 4);
   return 0;
}
