//
// Created by ntwar on 2/4/2021.
//

#include <iostream>
//using namespace std;

struct Stops {
    string names ;
    string price;
    string arrival;

    struct Stops *next;
}* first = NULL;

void create(struct Stops flights[], int n){
    struct Stops *last;
    first = (struct Stops*)malloc(sizeof(struct Stops));
    first->names = flights[0].names;
    first->price = flights[0].price;
    first->arrival = flights[0].arrival;

    last = first;

    int i;struct Stops *t;

    for(i=1;i<n;i++){
        t = (struct Stops*)malloc(sizeof(struct Stops));
        t->names = flights[i].names;
        t->price = flights[i].price;
        t->arrival = flights[i].arrival;

        t->next = NULL;
        last->next = t;

        last = t;
    }
}

void display(struct Stops *stops){
    while(stops->next != NULL){
        cout << stops->names <<endl;
        stops = stops->next;
    }
}

int main(){
    struct Stops flights[5] = {
            {"Ntwari ","300","8:30"},
            {"Liberi","3003","9:30"},
            {"Clarance","1100","10:25"},
            {"Daniel","500","12:00"},
            {"Shallon","600","1:50"},
    };
    create(flights,5);
    display(first);

    return 0;
}
