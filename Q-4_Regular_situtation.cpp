#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
public:
    node* next;
    char x;
};
node *root=NULL;
node *iter=NULL; //linked list ve onun gerekli elemanlarýný tanýmladýk classlarla tanýmladýk.
class Node
{
public:
    Node* next;
    char y;
}; //kuyruk yapýsý için class tanýmladýk.
typedef Node queue;
queue *front=NULL;
queue *back=NULL;
queue *temp=NULL; //queue ve onun için gerekli elemanlarý tanýmladýk.
void add(){
	string aorb;
	int i=0;
	cout<<"Enter string which includes a or b. You can exit with entering different value."<<endl;
	cin>>aorb; //kullanýAcýdan a ya da b giriþi yapacaðý deðiþkeni tanýmladýk ve aldýk.
	int count_ab=0; 
	while(aorb[i]=='a' || aorb[i]=='b'){ //eleman a veya b ise devam et.
	if(aorb[i]=='a'){
		if(front==NULL){ //kuyruðumuz boþ ise ilk elemaný buraya ekle.
				front=(queue*)malloc(sizeof(queue));  //alan aç
				front->y=aorb[i];      //açýlan alana aorb yi ekle
				front->next=NULL;   //sonraki eleman null eþitlemesi yaptýk.
				back=front;    //ilk eleman olduðundan ön ve arkasý ayný yer oldu.
		}
		else if(front !=NULL){   //ilk elemanýmýz var ise
				back->next=(queue*)malloc(sizeof(queue));    //kuyruðun gerisine yer aç
				back->next->y=aorb[i];        //elemana eþitle
				back=back->next;   //yeni elemanýmýz kuyruðun arkasý olur (fifo)
				back->next=NULL;   //arkayý NULL a eþitledik.
	}
	}
		else if(aorb[i]=='b'){  //eðer elemanýmýz kuyruktakilere eþit deðilse.
         	if(root==NULL){  //listemizde eleman yok ise
				root=(node*)malloc(sizeof(node));  //listede ilk elemaný yani kökü oluþturuyoruz.
				root->x=aorb[i];   //kok girilen elemana eþit oluyor.
				root->next=NULL;  //kokün nexti null oldu.
			}
			else if(root!=NULL){  //Listemizin kökü var ise
				iter=root;  //hareket ettireceðimiz elemaný köke eþitliyoruz.
				while(iter->next!=NULL){ //iterimiz son elemana ulaþana dek hareket ediyoruz.
				iter=iter->next; }
				 iter->next=(node*)malloc(sizeof(node));  //son elemandan sonrasýna yeni node açýyoruz.
				 iter->next->x=aorb[i];   //açýlan node girilen elemana eþit oldu.
				 iter->next->next=NULL;		  //yeni elemanýn sonu null oldu.	
			}
		}i++;
		}
}
void show(){
	   iter=root; 
		temp=front;
			while(iter!=NULL){
			cout<<iter->x;
			iter=iter->next;
		}
			while(temp!=NULL){
			cout<<temp->y;
			temp=temp->next;
		}
		cout<<endl; 
}
void deleting(int a_coefficent,	int b_coefficent){
	cout<<"First regular situation: ";
	show();
	 bool control=true; //her bir a silinmesinde katsayý kadar b eleman silindiðini kontrol edeceðimiz deðiþken
      int counta;
      int countb;
   while(front!=NULL && root!=NULL){  //iki listenin herhangi biri boþalana kadar devam edeceðiz.
    temp=front;
    iter=root;
    counta=0;
    countb=0;
	while(temp!=NULL){
    temp=temp->next;
    counta++;
	}
    while(iter!=NULL){
    iter=iter->next;
    countb++;
	}  //listede kalan elemanlarý hesapladýk.
    iter=root;
    temp=front;
    if(counta>=a_coefficent && countb>=b_coefficent){  	 //listemizde girilen katsayýlardan daha az eleman var ise silme iþlemi yapamayýz.
   	   if(control=true){  //ilk b nin kat sayýsý kadar b silecez.
		   for(int i=0;i<b_coefficent;i++){
   	    	iter=root;  //geçici eleman köke eþitlendi
   	    	root=root->next;  //kökümüz nexte eþit oldu
   	    	free(iter); //eski kökümüzü sildik.
   	    	control=false; //b katsayýsý kadar eleman sildik b den.
		   }
		   }
		   if(control==false){  //þimdi ise b kaysayýsý kadar b sildiysek a katsayýsý kadar a sileceðiz.
		   	for(int i=0;i<a_coefficent;i++){
		   		temp=front;   //geçicimiz ön elemana eþitlendi
		   		front=front->next;  //yeni ön eleman atandý.
		   		free(temp);  //eski ön elemanýmýz silindi
		   		control=true;  //controlumuzu düzelttik.
			   }
		   }
		  
	    cout<<"Deleting a amount of "<<a_coefficent<<" and deleting b amount of "<<b_coefficent<<" the rest of them :"<<endl;
	show(); //kalan elemanlar her silme iþleminde tekrardan ekrana yazýldý.
   } 
   else if(counta<a_coefficent || countb<b_coefficent) { //listede katsayýlardan daha az eleman varsa döngü bitirildi.
   	break;
   }}
}
void getCoefficent(){
		int a_coefficent;
	int b_coefficent;
	 cout<<"Please enter coefficent of a"<<endl; //a nýn katsayýsý alýndý
	 cin>>a_coefficent;
	  cout<<"Please enter coefficent of b"<<endl; // b nin katsayýsý alýndý.
	 cin>>b_coefficent;
	 system("CLS"); //ekran temizlendi.
	deleting(a_coefficent,b_coefficent); //katsayýlara göre silme iþlmeleri yapacak fonksiyon çaðýrýldý.
}
void check(){
	 if(root==NULL&&front==NULL){  //eðer listelerde eleman kalmadýysa 
   	cout<<"This situation is organized"<<endl;  //bu mesaj verilecek
   }
   else{  //listelerin birinde bile eleman kaldýysa
   		cout<<"This situation is not organized"<<endl; //bu mesaj gelecek.
   }
}
int main(){
	int operate;
	do{
		back:
	cout<<"Choose operate"<<endl;
	cout<<"1. Add"<<endl<<"2. Control and listing step by step"<<endl<<"3. show"<<endl<<"4. Exit"<<endl; //seçenekler
	cin>>operate;
	switch(operate){
		case 1: add(); break;
		case 2:	if(root==NULL || front==NULL){
			cout<<"You need input element at the list"<<endl; //olurda liste boþsa önce eleman ekletmeyi yaptýralým kullanýcýya.
			goto back;
		}
		show(); //katsayýlarý almadan önce listede eleman varsa yazdýrdýk.
		getCoefficent(); 
        check();  break;
        case 3: show();
	}	}while(operate!=4);
	return 0;
}
