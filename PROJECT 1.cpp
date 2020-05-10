#include <iostream>
using namespace std;

void take_elements1(int array[], int size){ //This function takes elements of arrays from user..
	for(int i=0;i<size;i++){
		cin>>array[i];
	}
}
void display(int array[],int size){ //This function prints arrays to the screen..
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
}
void sort_array(int array[],int size){ //This function sorts arrays..
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<(size-i-1);j++){
			if(array[j]>array[j+1]){
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}
void add_element1(int array1[],int *size1, int element1,int position1){ //This function add elements to the arrays..
	*size1=*size1+1;
	for(int i=*size1;i>=position1;i--){
		array1[i]=array1[i-1];
	}
	array1[position1-1]=element1;
}
void add_element2(int array2[],int *size2, int element2,int position2){ //This function add elements to the arrays..
	*size2=*size2+1;
	for(int i=*size2;i>=position2;i--){
		array2[i]=array2[i-1];
	}
	array2[position2-1]=element2;
}
void delete_element1(int array[],int *size, int position){ //This function deletes an element from the arrays..
	for(int i=position-1;i<=*size;i++){
		array[i]=array[i+1];
	}
	*size=*size-1;
}
void delete_element2(int array[],int *size, int position){ //This function deletes an element from the arrays..
	for(int i=position-1;i<*size;i++){
		array[i]=array[i+1];
	}
	*size=*size-1;
}
bool SubArrayFind(int array_1[], int array_2[],int *size_1,int *size_2){ //This Function checks the subset of the array..
	int i = 0, j=0;
	int m=0,n=0;
	if(*size_1 > *size_2){
		while(array_1[i]!=array_2[0]){
			i++;
		}
		while(j<*size_2){
			if(array_2[j]==array_1[i]){
				i++;
				j++;
			}
			else{
				return 0;
			}
		}
	}
	else if(*size_1 < *size_2){
		while(array_1[0]!=array_2[m]){
			m++;
		}
		while(n<*size_1){
			if(array_1[n]==array_2[m]){
				m++;
				n++;
			}
			else{
				return 0;
			}
		}
	}
	return 1;
}
	
int main(){
	int size_1,size_2,option;
	cout<<"Enter size of the first array: "<<endl;
	cin>>size_1;
	int ary_1[size_1];
	cout<<"Enter elements of the first array: "<<endl;
	take_elements1(ary_1,size_1);
	cout<<"Enter size of the second array: "<<endl;
	cin>>size_2;
	int ary_2[size_2];
	cout<<"Enter elements of the second array:"<<endl;
	take_elements1(ary_2,size_2);
	do{
		cout<<endl<<endl<<"**** MAIN MENU ****";
		cout<<endl<< "1: Display the arrays ";
		cout<<endl<< "2: Sort the arrays: ";
		cout<<endl<< "3: Add an element to the arrays ";
		cout<<endl<< "4: Delete an element from the arrays ";
		cout<<endl<< "5: Check that is an array a subset of the other array or not? ";
		cout<<endl<< "6: EXIT ";
		cout<<endl<<endl<< "Enter your option:" ;
		cin>>option;
		switch(option){
			case 1: cout<<endl<<"First array:  ";
			display(ary_1,size_1);
			cout<<endl<<"Second array: ";
			display(ary_2,size_2);
			    break;
			case 2: sort_array(ary_1,size_1);
			cout<<endl<<"First array (SORTED):  ";
			display(ary_1,size_1);
			sort_array(ary_2,size_2);
			cout<<endl<<"Second array (SORTED): ";
			display(ary_2,size_2);
				break;
			case 3: cout<<"Which arrays do you want to add elements to? 1 or 2? "<<endl;
			int choice,element_1,element_2,position_1,position_2;
			cin>>choice;
			if(choice==1){
				cout<<"Enter element : "<<endl;
				cin>>element_1;
				cout<<"Enter position : "<<endl;
				cin>>position_1;
				add_element1(ary_1,&size_1,element_1,position_1);
			}
			else if(choice==2){
				cout<<"Enter element : ";
				cin>>element_2;
				cout<<endl<<"Enter position : ";
				cin>>position_2;
				add_element2(ary_2,&size_2,element_2,position_2);
			}
			else{
				cout<<"Your choice is incorrect! "<<endl;
			}
			    break;
			case 4: cout<<"Which array do you want to delete elements from? 1 or 2?"<<endl;
			int DeleteChoice,position1,position2;
			cin>>DeleteChoice;
			if(DeleteChoice==1){
				cout<<"Enter the position: ";
				cin>>position1;
				delete_element1(ary_1,&size_1,position1);
			}
			else if(DeleteChoice==2){
				cout<<"Enter the position: ";
				cin>>position2;
				delete_element2(ary_2,&size_2,position2);
			}
			else{
				cout<<"Your choice is incorrect! "<<endl;
			}
			    break;
			case 5: if(SubArrayFind(ary_1,ary_2,&size_1,&size_2)){
				cout<<endl<<"Array with fewer elements is a subset of the other.. "<<endl;
			}
			else {
				if(size_1!=size_2){
					cout<<endl<<"Array with fewer elements is not a subset of the other.. "<<endl;
				}
			}
			
			    break;
		}
	}while(option!=6);
	return 0;
}
