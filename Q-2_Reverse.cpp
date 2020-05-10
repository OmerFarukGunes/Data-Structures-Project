
#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
int main(){
	string *word=new string();
	string temp;
	string *r_word=new string();
	cout<<"Enter your letter"<<endl;
    getline(cin,*word); //girilen cümleyi alýyoruz.
    temp=*word;
    int i;
    while(temp[i+1]!=NULL){ //girilen stringin boyutunu öðrenmeye çalýþtýk.
  i++;
}
for(int j=i;j>=0;j--){
	*r_word+=temp[j];
}
    cout<<*r_word;
}
