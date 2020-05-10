#include<iostream>
using namespace std;
float *input_inline(float array[],int size){
	int k;
	for(int i=0; i<size;i++){ //aray elemanları kullanıcıdan alındı ve araya eklendi.
		cout<<"Enter value of "<<i+1<<". member"<<endl;
		cin>>array[i];
	}      
	for(int j=0;j<size;j++){
    	for(int i=0; i<size;i++){  //küçükten büyüğe sıralama yapıldı.
	    	if(array[j]<array[i]){
			k=array[i];
			array[i]=array[j];
			array[j]=k;
		}
	}
	}
	return array; //fonksiyon içerisinde oluşan array maine gönderildi.
}
void control(float array1[],float array2[],int size1,int size2){
	int k=0,j=0;
	bool control=false;
	while(array1[k]!=array2[j]){ // 2. dizinin ilk elemanı 1. dizinin hangi elemanına eşitse oradan sonra kontrolü sağlayacağız
 k++;
 	}
	for(int i=k;i<size1;i++){ //ilk dizinin eşitliği olduğu yerden itibaren kontrol sağlancak
		if(j!=size2){	//2. dizinin boyutunu aşmadığı süre boyunca kontrol sağlanacak.
		if(array1[i]==array2[j]){ //değerlerin eşit olup olmadığının kontrolünü sağladım.
				 j++;
	             control=true; //eğer değerler sıralı bir şekilde durmadan aynıysa control true olacak.
				}
				else if(array1[i]!=array2[j]){ //eğer bir yerde sıralı eşitlik bozulursa
					control=false; //döngü sonlanacak.
					goto none;
				}
		}
		}
	none:
if(control==true){ //sub array ise
cout<<"Array2 is subset of array1";
}
else if(control==false){// değil ise
	cout<<"Array2 is not subset of array2";
}
}
int main(){
	int i,j;
	float *ptr;
	cout<<"Enter size of first array"<<endl;  
	cin>>i;
	cout<<"Enter size of second array"<<endl;
	cin>>j;
	float array1[i];
	float array2[j];  //main başlangıcından buraya kadar dizilerin boyutlarıyla beraber tanımı yaptık.
	ptr=&array1[0]; //ptr yi array1 in adresine eşitledik.
   ptr=input_inline(array1,i); //fonksiyona gönderdiğimiz arrayin içerisine eleman eklemeleri sıralı şekilde yapıp tekrar pointera eşitledik bu şekilde dizimiz istenen şekli aldı
   	ptr=&array2[0]; //array1 için yapılan işlemleri array2 içinde yaptık. ptr artık array1 in adresini tutması gerekmiyor.
   ptr=input_inline(array2,j); //ptr array1 in adresindeki değişiklikleri yaptı şuan sıra array2 de.
   if(i>=j ){ //büyük olan dizinin alt elemanını kontrol edeceğimizden control fonkuna büyük elemanı ilk göndermeliyiz.
   control (array1,array2,i,j);
   }
   else if(j>i){
   	 control (array2,array1,j,i);
   }
	return 0;
}
