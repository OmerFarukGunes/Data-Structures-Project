#include <iostream>
#include<stdlib.h>
using namespace std;
struct Node{
	char letter;
	struct Node* next;
};
struct Node *top = NULL;
struct Node *top2 = NULL;
void push(char letter_1){
	struct Node *temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->letter=letter_1;
	temp->next=NULL;
	if(top!=NULL){
		temp->next=top;
	}
	top=temp;
}
void keep_b(char letter_1){
	struct Node *temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->letter=letter_1;
	temp->next=NULL;
	if(top2!=NULL){
		temp->next=top2;
	}
	top2=temp;
}
void pop(){
	struct Node *temp;
	if(top->letter == NULL){
		cout<<endl<<"Stack Underflow"<<endl;
	}
	else{
		temp=top;
		top=top->next;
	}
	free(temp);
}
int peek(){
	return top->letter;
}
void display(){
	struct Node *temp;
		temp = top;
		cout<<endl;
		while(temp != NULL){
			cout<< temp->letter;
			temp = temp->next;
		}
		cout<<endl;
}
void print(){
	struct Node *temp;
		temp = top2;
		cout<<endl;
		while(temp != NULL){
			cout<< temp->letter;
			temp = temp->next;
		}
		cout<<endl;
}
int main(){
	char letter;
	int option;
	int count_a=0, count_b=0;
	cout<<endl<<"****** REGULAR EXPRESSION PRACTICE ******"<<endl<<endl;
	do{
		cout<<endl<<"1- Insert"<<endl;
		cout<<"2- Display the expression"<<endl;
		cout<<"3- Check if the expression is regular or not"<<endl;
		cout<<"4- Press 0 to EXIT"<<endl;
		cout<<"Enter your option: ";
		cin>>option;
		switch(option){
			case 1: cout<<endl<<"Enter a letter.. ('a' or 'b')"<<endl;
			cin>>letter;
			
			if(letter != 'b' && letter != 'a'){
				cout<<"The value that you entered is incorrect!"<<endl;
			}
			if(letter == 'a'){
				push(letter);
				count_a++;
			}
			if(letter == 'b'){
			keep_b(letter);
			count_b++;
			
			}
			break;
			case 2: display();
			break;
			case 3: int coefficient_a, coefficient_b;
			 cout<<endl<<"Enter the coefficient of 'a' : ";
				cin>>coefficient_a;
				cout<<endl<<"Enter the coefficient of 'b': ";
				cin>>coefficient_b;
				if(coefficient_a>coefficient_b){
					pop();
					while(count_b>0){
					for(int i=0;i<=count_b-coefficient_b;i++){
						pop();
					}
					count_b--;
				}
			}
			else if(coefficient_b>coefficient_a){
				pop();
				while(count_a>0){
					for(int j=0;j<=count_a-coefficient_a;j++){
						pop();
					}
					count_a--;
				}
			}
			
				break;
			}
				
	}while(option!=0);
	return 0;
}

