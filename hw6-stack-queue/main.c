#include <stdio.h>
#include<stdlib.h>
struct Node { 
    int key; 
    struct Node* next; 
}; 
//queue ve stacklerde kullanýlacak düðümler oluþturuldu
struct Queue { 
    struct Node *front, *rear; 
}; 
//queue oluþturuldu
struct Stack { 
    struct Node *top, *back; 
}; 
//stack oluþturuldu
struct Node* newNode(int k) 
{ 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));  //stack veya queue için yeni bir düðüm alan açýldý
    temp->key = k; 
    temp->next = NULL; 
    return temp; //düðüm içerisine deðer atandý ve geri döndü
}
struct Stack* createStack()
{
   struct Stack* oddList = (struct Stack*)malloc(sizeof(struct Stack)); //bellekte stack için alan açýldý
   oddList->back=oddList->top=NULL;
   return oddList;
}

void push (struct Stack *oddList, int value)
{
    struct Node* temp = newNode(value);  //ilk olarak yeni node deðeriyle beraber oluþturuldu
    if (oddList->top == NULL)  //ilk deðer ise en tepeye ve en arkaya olacak þekilde deðer stack içerisine atandý
	{ 
        oddList->top = oddList->back = temp; 
        return; //fonksiyondan çýkýldý
    } 
    temp->next=oddList->top; 
    oddList->top = temp; //ilk deðer deðil ise yeni deðer stackin tepe noktasýna atandý 
}

void pop(struct Stack *oddList)
{
	struct Node* temp=oddList->top; //stack silme iþlemi için tepe noktasý tutuldu
    oddList->top=oddList->top->next; // tepe nokta stack içerisinden çýkarýldý
	temp=NULL; //tutulan eski tepe nokta temizlendi
}

struct Queue* createQueue() 
{ 
    struct Queue* list = (struct Queue*)malloc(sizeof(struct Queue)); //bellekte queue için alan ayrýldý
    list->front = list->rear = NULL; 
    return list; 
} 

void enQueue(struct Queue* list, int value) 
{ 
    struct Node* temp = newNode(value);  //queue içerisine konacak yeni node deðeriyle beraber oluþturuldu
  
    if (list->rear == NULL)  //liste boþ ise eðer ön ve arka tek bir deðere eþitlendi
	{ 
        list->front = list->rear = temp; 
        return; 
    } 
    list->rear->next = temp; 
    list->rear=temp; //queue mantýðýyla yeni gelen eleman en arka sýraya eklendi
}
void deque(struct Queue *list)
{
	struct Node *temp=list->front; //queue mantýðýnda listeden eleman çýkacaksa ilk sýradan çýkar
	list->front=list->front->next; //ilk sýra güncellenir
	temp=NULL; //eski ilk sýra bellekten silinir
}
struct Queue *reverseSystem(struct Queue *list, struct Stack *oddList)
{   
    struct Queue *reverseTemp=createQueue(); //ters çevirme iþlemi için yedek queue oluþturuldu
	while(list->front != NULL)
	{  
		if(list->front->key %2 == 1) //listede sýra gelen tek numara varsa
		{ 
		  enQueue(reverseTemp,oddList->top->key); //listede tek numara geldiði zaman yedek listeye stack içerisinde eleman eklenir
		  deque(list); //listeden alýnan elemanlar çýkartýlýr.
		  pop(oddList); //stackten alýnan elemanlar çýkartýlýr.
		}
		else
		{
		  enQueue(reverseTemp,list->front->key); //listedeki deðer tek numara deðilse yedek listeye olduðu gibi eklenir
		  deque(list); //yedek listeye eklenen eleman listeden silinir.
		}
	}
	return reverseTemp; //oluþturulan yani istenen yedek liste geri döndürülür
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
	    printf("%d ",temp->key); //listenin yazdýrma iþlemi 
	    temp=temp->next;
	}
	printf("\n");
	if(counter>0) //liste içerisine atanmýþ counter deðerleri yazdýrýlýr.
	{   
	    printf("Reverse Count: ");
		temp = list->front;
	    for(i=0;i<size;i++)
		{ 
		 if(temp->key%2==1) //tek sayýlý numaralarý kontrol eden if
		 {
	       if(temp->key>=10) //konsolda daha düzgün yazým için konan if else kontrolü
	        printf("%d  ",counter);
		   else
	        printf("%d ",counter);
	       counter--;
		 }
		 else if(temp->key>=10)//konsolda daha düzgün yazým için konan if else kontrolü
		  printf("   ");
		 else
		  printf("  ");
		 temp=temp->next;
		}
	}
}
void addingSystem()
{  
    struct Queue* list; //data.txt doyasýndan çekilecek verilerin ekleneceði liste
    struct Stack* oddList; //tek sayýlarýn tutulacaðý stack
    struct Node* temp; //liste ve stacklerde gezilecek düðüm
	int size=0,i=0,counter=0,value=0; //size data.txt den çekilecek veri boyutu
	//i for döngüsü için kullanýlacak. Counter tek sayýlarýn sayýsýný tutacak ve her tek sayýnýn sabit counter deðeri olacak.
	//value data dan çekilecek deðer
    FILE *fp; 
	fp = fopen("data.txt","r+" ); //data dosyamýzý okuma modunda açýyoruz. 
    fscanf(fp,"%d",&size); //her bir satýrýn boyutunu çekiyoruz.
    while(fscanf(fp,"%d",&value) !=EOF) //ilk deðerimizi alýyoruz. her satýr sonunda alacaðýmýz bu deðer dosyanýn sonuna ulaþtýðý zaman döngü bitecektir.
	{    
	    list = createQueue();  //liste oluþturuldu
	    oddList = createStack(); //stack oluþturuldu
	    for(i=0;i<size;i++) //satýr boyu deðerler alýnýyor
		{ 
	      enQueue(list,value); //listeye deðer eklendi
	      fscanf(fp,",%d",&value); //yeni deðer alýndý
		}
	    print(list,0,size); //liste yazýldý
	    temp = list->front; //temp listenin baþýna atandý	  
		  
		printf("Count:         ");
	    for(i=0;i<size;i++)
		{ 
		 if(temp->key%2==1) //tek sayýlý numaralarý kontrol eden if
		 {
	       push(oddList,temp->key); //listedeki tek sayýlar stacke atýldý
	       counter++; //her tek sayý için counter arttýrýldý
	       if(temp->key>=10) //konsolda daha düzgün yazým için kullanýlan if else kontrolü
	        printf("%d  ",counter);
		   else
	        printf("%d ",counter);
		 }
		 else if(temp->key>=10)//konsolda daha düzgün yazým için kullanýlan if else kontrolü
		 printf("   ");
		 else
		 printf("  ");
		 temp=temp->next;
		}
		
		list = reverseSystem(list,oddList); //sadece tek sayýlarýn yerleri deðiþtirilmesi için fonksiyon çaðýrýldý ve listemize atandý
        print(list,counter,size); //yeni liste yazýldý
		
		list=NULL; 
		oddList=NULL;
		counter=0;
		temp=NULL; //tüm veriler sýfýrlandý
		printf("\n");
	}
}
void main()
{
     addingSystem(); //data.txt dosyasýndan veri çekimi için fonk çaðýrýldý
}
