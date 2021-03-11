//
// Created by ntwar on 2/4/2021.
//

#include <iostream>
using namespace std;

//struct stop
struct Stop {
    string names ;
    double price;
    string arrival;

    struct Stop *next;
}* firstStop = NULL;

//creating flights
void createFlightStops(struct Stop flights[], int numberOfFlightStops){
    struct Stop *lastStop;
    struct Stop *temporaryFlightStop;


    firstStop = (struct Stop*)malloc(sizeof(struct Stop));
    firstStop->names = flights[0].names;
    firstStop->price = flights[0].price;
    firstStop->arrival = flights[0].arrival;

    lastStop = firstStop;


    for(int i=1; i< numberOfFlightStops; i++){
        temporaryFlightStop = (struct Stop*)malloc(sizeof(struct Stop));

        temporaryFlightStop->names = flights[i].names;
        temporaryFlightStop->price = flights[i].price;
        temporaryFlightStop->arrival = flights[i].arrival;
        temporaryFlightStop->next = NULL;

        lastStop->next = temporaryFlightStop;

        lastStop = temporaryFlightStop;
        lastStop = lastStop->next;
    }
}

//displaying flights
void displayFlightStops(struct Stop *stops){
    cout << "Names"  << "\t" << "Price" << "\t" << "Arrival" <<endl;
    cout << "---------------------------"<<endl;

    while(stops != NULL){

        cout << stops->names  << "\t" << stops->price << "\t" << stops->arrival <<endl;
        stops = stops->next;
    }
}

struct Stop *search(struct Stop *ptr, int key){

    while(ptr != NULL ){

        if(ptr->price == key) return ptr;

        ptr = ptr->next;
    }

    return NULL;
}

//stop with maximum price
struct Stop *maxPrice(struct Stop *ptr){

    struct Stop *max = ptr;

    while(ptr != NULL ){

        if(ptr->price > max->price) max = ptr;

        ptr = ptr->next;
    }

    return max;
}

//stop with maximum price
int countStops(struct Stop *ptr){

    int counts = 0;

    while(ptr != NULL ){
        counts++;
        ptr = ptr->next;
    }

    return counts;
}

int main(){
    struct Stop flights[6] = {
            { "Kigali",300,"8:15 PM"},
            {"Entebbe",300,"5:45 AM"},
            {"Bruxelles",800,"10:25"},
            {"Bruxelles",10000,"10:25"},
            {"Newark",1400,"4:00 PM"},
            {"Logan",2000,"5:00 PM"},

    };
    createFlightStops(flights,6);
//    displayFlightStops(firstStop);

//    struct Stop *foundStop = search(firstStop,400);
    struct Stop *maximumPriceStop = maxPrice(firstStop);

    cout<<countStops(firstStop) << endl;

    cout << maximumPriceStop->names << "\t" << maximumPriceStop->price << "\t" << maximumPriceStop->arrival  << endl;

    return 0;
}
