#include <stdio.h>
#include<stdlib.h>
struct Node { 
    int key; 
    struct Node* next; 
}; 
//queue ve stacklerde kullan�lacak d���mler olu�turuldu
struct Queue { 
    struct Node *front, *rear; 
}; 
//queue olu�turuldu
struct Stack { 
    struct Node *top, *back; 
}; 
//stack olu�turuldu
struct Node* newNode(int k) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //stack veya queue i�in yeni bir d���m alan a��ld�
    temp->key = k; 
    temp->next = NULL; 
    return temp; //d���m i�erisine de�er atand� ve geri d�nd�
}
struct Stack* createStack()
{
   struct Stack* oddList = (struct Stack*)malloc(sizeof(struct Stack)); //bellekte stack i�in alan a��ld�
   oddList->back=oddList->top=NULL;
   return oddList;
}

void push (struct Stack *oddList, int value)
{
    struct Node* temp = newNode(value);  //ilk olarak yeni node de�eriyle beraber olu�turuldu
    if (oddList->top == NULL)  //ilk de�er ise en tepeye ve en arkaya olacak �ekilde de�er stack i�erisine atand�
	{ 
        oddList->top = oddList->back = temp; 
        return; //fonksiyondan ��k�ld�
    } 
    temp->next=oddList->top; 
    oddList->top = temp; //ilk de�er de�il ise yeni de�er stackin tepe noktas�na atand� 
}

void pop(struct Stack *oddList)
{
	struct Node* temp=oddList->top; //stack silme i�lemi i�in tepe noktas� tutuldu
    oddList->top=oddList->top->next; // tepe nokta stack i�erisinden ��kar�ld�
	temp=NULL; //tutulan eski tepe nokta temizlendi
}

struct Queue* createQueue() 
{ 
    struct Queue* list = (struct Queue*)malloc(sizeof(struct Queue)); //bellekte queue i�in alan ayr�ld�
    list->front = list->rear = NULL; 
    return list; 
} 

void enQueue(struct Queue* list, int value) 
{ 
    struct Node* temp = newNode(value);  //queue i�erisine konacak yeni node de�eriyle beraber olu�turuldu
  
    if (list->rear == NULL)  //liste bo� ise e�er �n ve arka tek bir de�ere e�itlendi
	{ 
        list->front = list->rear = temp; 
        return; 
    } 
    list->rear->next = temp; 
    list->rear=temp; //queue mant���yla yeni gelen eleman en arka s�raya eklendi
}
void deque(struct Queue *list)
{
	struct Node *temp=list->front; //queue mant���nda listeden eleman ��kacaksa ilk s�radan ��kar
	list->front=list->front->next; //ilk s�ra g�ncellenir
	temp=NULL; //eski ilk s�ra bellekten silinir
}
struct Queue *reverseSystem(struct Queue *list, struct Stack *oddList)
{   
    struct Queue *reverseTemp=createQueue(); //ters �evirme i�lemi i�in yedek queue olu�turuldu
	while(list->front != NULL)
	{  
		if(list->front->key %2 == 1) //listede s�ra gelen tek numara varsa
		{ 
		  enQueue(reverseTemp,oddList->top->key); //listede tek numara geldi�i zaman yedek listeye stack i�erisinde eleman eklenir
		  deque(list); //listeden al�nan elemanlar ��kart�l�r.
		  pop(oddList); //stackten al�nan elemanlar ��kart�l�r.
		}
		else
		{
		  enQueue(reverseTemp,list->front->key); //listedeki de�er tek numara de�ilse yedek listeye oldu�u gibi eklenir
		  deque(list); //yedek listeye eklenen eleman listeden silinir.
		}
	}
	return reverseTemp; //olu�turulan yani istenen yedek liste geri d�nd�r�l�r
}
void print(struct Queue* list,int counter,int size)
{  
	printf("\n");
	if(counter>0)
	printf("Reverse Queue: ");
	else
	printf("Queue:         ");
	struct Node* temp;
	int i=0;
	temp = list->front;
	for(i=0;i<size;i++)
	{ 
	    printf("%d ",temp->key); //listenin yazd�rma i�lemi 
	    temp=temp->next;
	}
	printf("\n");
	if(counter>0) //liste i�erisine atanm�� counter de�erleri yazd�r�l�r.
	{   
	    printf("Reverse Count: ");
		temp = list->front;
	    for(i=0;i<size;i++)
		{ 
		 if(temp->key%2==1) //tek say�l� numaralar� kontrol eden if
		 {
	       if(temp->key>=10) //konsolda daha d�zg�n yaz�m i�in konan if else kontrol�
	        printf("%d  ",counter);
		   else
	        printf("%d ",counter);
	       counter--;
		 }
		 else if(temp->key>=10)//konsolda daha d�zg�n yaz�m i�in konan if else kontrol�
		  printf("   ");
		 else
		  printf("  ");
		 temp=temp->next;
		}
	}
}
void addingSystem()
{  
    struct Queue* list; //data.txt doyas�ndan �ekilecek verilerin eklenece�i liste
    struct Stack* oddList; //tek say�lar�n tutulaca�� stack
    struct Node* temp; //liste ve stacklerde gezilecek d���m
	int size=0,i=0,counter=0,value=0; //size data.txt den �ekilecek veri boyutu
	//i for d�ng�s� i�in kullan�lacak. Counter tek say�lar�n say�s�n� tutacak ve her tek say�n�n sabit counter de�eri olacak.
	//value data dan �ekilecek de�er
    FILE *fp; 
	fp = fopen("data.txt","r+" ); //data dosyam�z� okuma modunda a��yoruz. 
    fscanf(fp,"%d",&size); //her bir sat�r�n boyutunu �ekiyoruz.
    while(fscanf(fp,"%d",&value) !=EOF) //ilk de�erimizi al�yoruz. her sat�r sonunda alaca��m�z bu de�er dosyan�n sonuna ula�t��� zaman d�ng� bitecektir.
	{    
	    list = createQueue();  //liste olu�turuldu
	    oddList = createStack(); //stack olu�turuldu
	    for(i=0;i<size;i++) //sat�r boyu de�erler al�n�yor
		{ 
	      enQueue(list,value); //listeye de�er eklendi
	      fscanf(fp,",%d",&value); //yeni de�er al�nd�
		}
	    print(list,0,size); //liste yaz�ld�
	    temp = list->front; //temp listenin ba��na atand�	  
		  
		printf("Count:         ");
	    for(i=0;i<size;i++)
		{ 
		 if(temp->key%2==1) //tek say�l� numaralar� kontrol eden if
		 {
	       push(oddList,temp->key); //listedeki tek say�lar stacke at�ld�
	       counter++; //her tek say� i�in counter artt�r�ld�
	       if(temp->key>=10) //konsolda daha d�zg�n yaz�m i�in kullan�lan if else kontrol�
	        printf("%d  ",counter);
		   else
	        printf("%d ",counter);
		 }
		 else if(temp->key>=10)//konsolda daha d�zg�n yaz�m i�in kullan�lan if else kontrol�
		 printf("   ");
		 else
		 printf("  ");
		 temp=temp->next;
		}
		
		list = reverseSystem(list,oddList); //sadece tek say�lar�n yerleri de�i�tirilmesi i�in fonksiyon �a��r�ld� ve listemize atand�
        print(list,counter,size); //yeni liste yaz�ld�
		
		list=NULL; 
		oddList=NULL;
		counter=0;
		temp=NULL; //t�m veriler s�f�rland�
		printf("\n");
	}
}
void main()
{
     addingSystem(); //data.txt dosyas�ndan veri �ekimi i�in fonk �a��r�ld�
}
