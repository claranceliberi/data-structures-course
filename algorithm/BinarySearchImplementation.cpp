#include<iostream>
using namespace std;


// function to implement binary search algorithm

void BinarySearch(int array[],int value){
	int begin=0,end=sizeof(array),position=-1,mid;
  
  while(begin<=end){ 
      mid=(begin+end)/2;
   if(array[mid]==value){
	 position=mid;
	 cout<<"SUCCESSFULLY SEARCH \n FOUND ON INDEX: "<<position<<endl;
	 exit(0);
    }
else if(array[mid]>value){
	end=mid-1;
}
else{
	begin=mid+1;
}

}
		if(position=-1){
		cout<<"VALUE NOT FOUND, SEARCH UNSUCCESSFUL"<<endl;
	}
}


int main(){
	int array[] = { 1, 12,14,25,30, 39, 74,64,67,87,99};
//	calling the function
	BinarySearch(array,30);
	return 0;
}
