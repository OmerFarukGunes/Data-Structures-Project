#include<iostream>
#include<stdlib.h>
#include <fstream>
using namespace std;
class list
{
public:
    list *next;
    list *prev;
    char x;
};    //objemiz tanýmlandý.
typedef list node;
node *front=NULL;
node *back=NULL;
node *iter=NULL; //gerekli liste elemanlarý oluþturuldu.
node *add(node *root,char y){
	if(root==NULL){ //liste boþ ise
		root=(node*)malloc(sizeof(node)); //belletke yer açýldý.
		root->x=y;
		root->next=NULL;
		root->prev=NULL;
		back=root; //atamalar yapýldý. liste queue mantýðýyla çalýþacaðýndan ilk eleman hem back hem front oldu.
		return root;
	}
	iter=root; //Liste boþ deðilse.
	while(iter->next!=NULL) //listenin son elemanýna kadar gidildi.
	iter=iter->next; 
	iter->next=(node*)malloc(sizeof(node)); //son elemandan sonra yeni yer açýldý.
	iter->next->x=y; 
	iter->next->prev=iter;
	iter->next->next=NULL;
	back=iter->next; //yeni eklenen eleman listenin sonu olur.
	return root;
}
void print(){
	iter=front;
   while(iter!=NULL){
   	cout<<iter->x;
   	iter=iter->next;
	}
 // iter son elemana gelene dek yazma iþlemi yapar.
cout<<endl;
}
void organize(){
	cout<<front->x<<" is deleted";
	front->x=back->x;
	cout<<" and "<<front->x<<" is placed, new situation: ";
	print();
}
void control(){
while(front!=back){ //ilk ve son eleman birbirine eþit deðilse yani listede tek bir eleman kalmadýysa.
if(front->x==back->x ){ //front ve back deðerleri aynýysa
	iter=front;
	front=front->next;
    cout<<iter->x<<"'s are deleted, new situtation: ";
	free(iter);
	front->prev=NULL;
	if(front->next==NULL){//eðer front ileriye alýndýðýnda backe eþit olduysa direk burada silme iþlemini gerçekleþtir ve döngüden çýk. yani listede son iki eleman kaldýysa.
		free(back);
		goto resume;
	} 
	iter=back;
	back=back->prev;
    free(iter); //ayný þekilde back bir ileriye alýnýr ve eski back silinir.
    back->next=NULL; 
    print(); //her silme iþleminde ekrana yazdýrma fonksiyonu çaðrýlýr kullanýcý bilgilendirilir.
}
else if(front->x!=back->x){ //eðer eþitlik durumu yoksa düzenleme fonku çaðrýlýr.
cout<<"This situation is not panlinormic, so it will fix."<<endl;
	organize();
}
}
   resume:
   cout<<endl<<"Finally, this situation is palindromic"<<endl;
}
int main(){
	char y;
     ifstream readFile("Deneme.txt"); //dosya kontrolü saðlanýr.
   if(readFile.is_open()){ //eðer dosya mevcut ve açýlabiliyorsa
    while (readFile>>y){ //dosyada karakter karakter aldýðýmýz deðerleri y ye eþitliyoruz.
   front=add(front,y); //listeye ekleme iþlemi yapýlýyor
   }
    readFile.close(); //iþlemler bittiðinde dosya kapatýlýr.
  }
  else{
  	cout<<"File does not exist"<<endl; //dosya mevcut deðilse.
  }
  print(); //oluþan durum ekrana yazýlýr.
   control(); //listenin palinormic olup olmadýðý kontrol ediliyor.
}
