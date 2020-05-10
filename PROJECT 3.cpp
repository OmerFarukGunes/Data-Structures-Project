#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	char data;
	struct Node *next, *prev;
};
struct Node *start = NULL;
struct Node *create_ll(struct Node *start){
	struct Node *new_node, *ptr;
	char add;
	cout<<endl<<"Enter 'q' to end: "<<endl;
	cout<<endl<<"Enter the data: ";
	cin>>add;
	while(add!='q'){
		if(start==NULL){
			new_node = (struct Node*)malloc(sizeof(struct Node));
			new_node->prev = NULL;
			new_node->data = add;
			new_node->next = NULL;
			start = new_node;
		}
		else{
			ptr=start;
			new_node = (struct Node*)malloc(sizeof(struct Node));
			new_node->data=add;
			while(ptr->next != NULL){
				ptr=ptr->next;
			}
			ptr->next=new_node;
			new_node->prev = ptr;
			new_node->next = NULL;
		}
		cout<<endl<<"Enter the data: ";
		cin>>add;
	}
	return start;
}
struct Node *display(struct Node *start){
	struct Node *ptr;
	ptr=start;
	while(ptr != NULL){
		cout<<ptr->data;
		ptr=ptr->next;
	}
	return 0;
}
bool isPalindrome(struct Node *left){
	if(left==NULL){
		return 1;
	}
	struct Node *right = left;
	while(right->next != NULL){
		right=right->next;
	}
	while(left != right){
		if(left->data != right->data){
			return 0;
		}
		left = left->next;
		right=right->prev;
		
	}
	return 1;
}

struct Node *insert_beg(struct Node *start){
	struct Node *new_node;
	char add;
	cout<<"Enter the data: ";
	cin>>add;
	new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=add;
	start->prev=new_node;
	new_node->next=start;
	new_node->prev = NULL;
	start=new_node;
	return start;
}
struct Node *insert_end(struct Node *start){
	struct Node *ptr, *new_node;
	char add;
	cout<<"Enter the data: ";
	cin>>add;
	new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data=add;
	ptr=start;
	while(ptr->next != NULL){
		ptr=ptr->next;
	}
	ptr->next=new_node;
	new_node->prev=ptr;
	new_node->next=NULL;
	return start;
}
int main(){
	int option;
	do{
		cout<<endl<<endl<<"****** MAIN MENU ******";
		cout<<endl<<"1- Create a list";
		cout<<endl<<"2- Display List";
		cout<<endl<<"3- Add a value at the beginning";
		cout<<endl<<"4- Add a value at the end";
		cout<<endl<<"5- Is it palindrome? Check that..";
		cout<<endl<<"6- EXIT";
		cout<<endl<<"Enter your option: ";
		cin>>option;
		switch(option){
			case 1: start = create_ll(start);
			cout<<endl<<endl<<"Doubly Linked List Created..";
			break;
			case 2: cout<<endl;
			start = display(start);
			break;
			case 3: start = insert_beg(start);
			break;
			case 4: start = insert_end(start);
			break;
			case 5: if(isPalindrome(start)){
				cout<<endl<<"It is palindrome..";
			}
			else{
				cout<<endl<<"It is not palindrome..";
			}
			break;
		}
		
	}while(option!=6);
	return (0);
}
