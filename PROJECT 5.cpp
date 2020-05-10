#include <iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node *left, *right;
};
struct node *insertElement(struct node *root, int data){
	if(root==NULL){
		struct node *newNode;
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if(root->data > data){
		root->left = insertElement(root->left,data);
	}
	else if(root->data<data){
		root->right = insertElement(root->right,data);
	}
	return root;
}
void postorderTraversal(struct node *root){
	if(root == NULL)
	return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->data<<" -> ";
}
int main(){
	int val,option;
	struct node *root = NULL;
	cout<<endl<<"***** BINARY SEARCH TREE *****"<<endl<<endl;
	do{
	cout<<"Press 1 to insert element "<<endl;
	cout<<"Press 2 to see postorder output of the BST "<<endl;
	cout<<"Press 0 to EXIT "<<endl;
	cout<<endl<<endl<<"Enter your option: ";
	cin>>option;
	switch(option){
		case 1: cout<<endl<<"Enter the value of the new node : ";
	cin>>val;
	cout<<endl;
	root = insertElement(root,val);
	break;
	    case 2: cout<<endl<<endl<<"The elements of the tree  are: (POSTORDER) "<<endl;
	    cout<<endl;
	    postorderTraversal(root);
	    cout<<endl<<endl;
	    break;
	}
    }while(option!=0);
	return 0;
}
