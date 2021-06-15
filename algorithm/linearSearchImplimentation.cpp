#include<iostream>
using namespace std;

//function to implemet linear search algorithm

void search(int array[],int value){
	int i=0;
	int position=-1;
	
	while(i<sizeof(array)){
		if(array[i]==value){
			position=i;
			cout<<"VALUE FOUND, SEARCHSUCCESSFUL\n ON INDEX: "<<position<<endl;
	      exit(0);
		}
		i++;
		
	}
	
	if(position=-1){
		cout<<"VALUE NOT FOUND, SEARCH UNSUCCESSFUL"<<endl;
	}
	
}



int main(){
	
	int array[] = {87, 25, 14, 39, 74, 1, 99, 12, 30, 67};
	
//	calling the function
	search(array,30);
	return 0;
}
