#include<iostream>
using namespace std;
class tree
{
public:
    tree* right;
    tree *left;
    int value;
};
tree *root=NULL;
tree *iter=NULL; //tree yapýsý oluþturuldu.
void printPostorder(tree*node) 
{ 
    if (node == NULL) 
        return; 
    printPostorder(node->left); //  en sola recursive 
    printPostorder(node->right); //en saða recursive
    cout << node->value << " "; //ve deðeri ekrana yazdýr.
} 
tree *add(tree *root,int x){
	if(root==NULL){//ilk eleman null veya recursive sonucu en sað veya en soll eleman null ise 
	   root= new tree(); //yeni node aç
	    root->left=NULL; 
	    root->right=NULL; //her iki tarafý nulla eþitle 
	    root->value=x;  //deðerini ata.
	    return root; //ilk deðer ise maine döndür. recursive sonucu girilen deðer ise recursive in baþladýðý yere deðeri döndürüyoruz.
	}
	if(root->value<x){  //deðerimiz aðaçtaki deðerden büyük ise fonksiyonu aðacýn saðýna gidecek þekilde recursive yapýyoruz.
		root->right=add(root->right,x);
		return root;    //aðacýn saðýna ekleme iþlemlerini yaptýktan sonra rootu döndürüyoruz.
	}
	    root->left=add(root->left,x);//yukarýdaki iki ifede girmediyse gelen deðer aðaçtakinden küçük olacaktýr.
	    //bu yüzden fonksiyonu durmadan recursive yapýyor ve küçük olan deðeri yerine yerleþtiriyoruz.
	    return root; //root geri döndürüyoruz
}
int main(){
	int x;
	cout<<"Enter a value for including tree. You can exist when you enter 0"<<endl;
	cin>>x;
	while(x!=0){ //kullanýcý 0 girene kadar.
		root=add(root,x); //ekleme iþlemi yapýlýyor.
		cin>>x;
	}
	printPostorder(root);
	return 0;
}
