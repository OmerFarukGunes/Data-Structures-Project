#include <iostream>
#include <string.h>
using namespace std;
int main(){
	cout<<endl<<endl<<"****** REVERSE OF A WORD ******"<<endl<<endl;
	string *str=new string();
	cout<<endl<<"Enter a word to learn its reverse: "<<endl;
	cin>>*str;
	string temp;
	temp=*str;
	*str=" ";
		int i=0;
	while(temp[i+1]!='\0'){
		i++;
	}
	cout<<endl<<"Inverse of word that you entered: ";
	for(int j=i;j>=0;j--){
		*str +=temp[j];
	}
	cout<<*str<<endl;
	return 0;
}
