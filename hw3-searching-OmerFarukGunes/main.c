#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
#include<locale.h>
#include<string.h>

typedef struct
{
	int counter; //öðrenci sayýsý
	int number; //primary
	char *name; //secondary
	int grade; //secondary
}student; //structer oluþturuldu

void sort(int *arr,int n)//Diziler için küçükten büyüðe sýralama algoritmasý
{
	int temp,i,j;
	for(j=1;j<n;j++)
    {
        for (i=0;i<n-1;i++)
        {
           if (arr[i]>arr[i+1])
           {
               temp=arr[i]; //büyük eleman tempe
               arr[i]=arr[i+1]; //küçük eleman büyük elemanýn yerine
               arr[i+1]=temp; //tempteki büyük eleman küçük elemanýn yerine
           }
        }
    }
} 

void sortStructNumber(student *arr,int n)//struct dizileri için numaraya göre sýralama algoritmasý
{
	student temp;
	int i,j;
	for(j=1;j<n;j++)
    {
        for (i=0;i<n-1;i++)
        {
           if (arr[i].number>arr[i+1].number)
           {
               temp=arr[i];
               arr[i]=arr[i+1];
               arr[i+1]=temp;
           }
        }
   }
}

void sortStructGrade(student *arr,int n)//struct dizileri için nota göre sýralama algoritmasý
{
	student temp;
	int i,j;
	for(j=1;j<n;j++)
    {
        for (i=0;i<n-1;i++)
        {
           if (arr[i].grade>arr[i+1].grade)
           {
               temp=arr[i];
               arr[i]=arr[i+1];
               arr[i+1]=temp;
           }
        }
    }
}

void sortStructName(student *arr, int n) //struct dizileri için isme göre sýralama algoritmasý
{ 
    student temp; 
	int i,j;
	for(j=1;j<n;j++)
    {
        for (i=0;i<n-1;i++)
        {
           if (strcmp(arr[i].name, arr[j].name) > 0) //diðerlerinden farklý olarak karþýlaþtýrmak için strcmp() fonksiyonu kullanýldý.
           { 
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
           }
        }
    }
} 


void LinSearch(int *arr,int n, int x)//Diziler için doðrusal arama
{
	int i;
	for(i=0; i<n; i++)
	{
		if(arr[i]==x) //deðerler eþit ise aranan deðer bulunmuþtur.
		{
			printf("%d deðeri dizinin %d. elemanýnda bulunmaktadýr.\n",x,i+1);
			return ;
		}
	}
	printf("%d deðeri dizide bulunmamaktadýr.\n",x);
}

void LinSearchPrimary(student *stu, int n,int x)//Primary keye göre doðrusal arama
{
	int i;
	for(i=0; i<n; i++)
	{
		if(stu[i].number==x)
		{
			printf("%d %s %d\n",stu[i].number,stu[i].name,stu[i].grade); //bulunan deðere ait tüm veriler yazýldý
			return ;
		}
	}
	printf("%d degeri dizide bulunmamaktadir.\n",x);
}

void LinSearchSecondary(student *stu, int n,int x)//secondary key olan nota göre doðrusal arama
{
	int i;
	printf("%d Notu Ýçin Doðrusal Arama:\n",x);
	for(i=0; i<n; i++)
	{
		if(stu[i].grade==x)
		{
			printf("%d %s %d \n",stu[i].number,stu[i].name,stu[i].grade);//bulunan deðere ait tüm veriler yazýldý
			//baþka notlarýn olabileceði varsayýlarak return edilmedi.
		}
	}
}

void LinSearchSecondaryName(student *stu, int n,char *x)//isme göre doðrusal arama
{
	int i;
	for(i=0; i<n; i++)
	{
		if(strcmp(x,stu[i].name)==0)
		{
			printf("%d %s %d \n",stu[i].number,stu[i].name,stu[i].grade);
		}
	}
	printf("%s ismi dizide bulunmamaktadýr.\n",x);
}

void BinSearch(int *arr,int n, int x)
{
	int low= 0;
	n=n-1; //high deðer olarak n ele alýndý
	while(low <= n)
	{
		int index = low+(n-low)/2; //dizinin ortasýndan aramaya baþlamak için iþlem yapýldý
		if(arr[index] == x) 
		{
			printf("%d deðeri dizinin %d. elemanýnda bulunmaktadýr.\n",x,index+1); 
		    return;
		}
		else if(arr[index] < x)
		{
			low   = index+1; //bulunduðumuz yer x ten küçükse saða hareket ediyoruz
		}
		else
		{
			n = index-1; //bulunduðumuz yer x ten büyükse sola hareket ediyoruz
		}
	}
	printf("%d deðeri dizide bulunmamaktadýr.\n",x); //bulunamazsa hata mesajý dönecektir
} //Diziler için binary aramasý


void BinSearchPrimary(student *arr,int n, int x)//struct dizileri için primary keye göre binary aramasý
{
	int low= 0;
	n=n-1;
	while(low <= n)
	{
		int index = low+(n-low)/2;
		if(arr[index].number == x)
		{
	     	printf("%d %s %d \n",arr[index].number,arr[index].name,arr[index].grade); //bulunan deðer tüm verileriyle yazýldý
		    return; 
		}
		else if(arr[index].number < x)
		{
			low   = index+1;
		}
		else
		{
			n = index-1;
		}
	}
	printf("%d deðeri dizide bulunmamaktadýr.\n",x);
}

void BinSearchSecondary(student *arr,int n, int x)//ikincil deðere göre binary arama algoritmasý
{
	int low= 0;
	n=n-1;
	printf("%d Notu Ýçin Ýkili Arama:\n",x);
	while(low <= n)
	{
		int index = low+(n-low)/2;
		if(arr[index].grade == x)
		{
	     	printf("%d %s %d \n",arr[index].number,arr[index].name,arr[index].grade);
		    return;
		}
		else if(arr[index].grade < x)
		{
			low   = index+1;
		}
		else
		{
			n = index-1;
		}
	}
	printf("%d notu dizide bulunmamaktadýr.\n",x);
}

void BinSearchSecondaryName(student *arr,int n, char *x) //name e göre binary arama algoritmasý
{   

	int low= 0;
	n=n-1;
	while(low <= n)
	{
		int index = low+(n-low)/2;
		if(strcmp(x,arr[index].name)==0)
		{
	     	printf("%d %s %d \n",arr[index].number,arr[index].name,arr[index].grade);
		    return;
		}
		else if(strcmp(x,arr[index].name)>0)
		{
			low   = index+1;
		}
		else
		{
			n = index-1;
		}
	}
	printf("%s ismi dizide bulunmamaktadýr.\n",x);
}
void FileOperation()//txt dosyasý üzerindeki iþlemler
{
     int counter; 
     int i=0;
	 FILE *fp; 
	 fp=fopen("data.txt","r+"); //data dosyamýz açýlýyor
	 char *temp=(char*)malloc(1 * sizeof(char)); //geçici bellek tanýmlanýp alan ayýrýlýyor.
	 while((fscanf(fp, "%c", &temp[i])) != EOF)
	 { //data.txt dosyasýnda bulunan tüm veriler char by char çekiliyor.
		 if(temp[i]==',') //data dosyasýndan virgülleri kaldýrmayý hedefliyoruz.
		 {
		   temp[i]=' ';
		 }
		 else if(temp[i]==' ')//ayný þekilde isim girdisi tek bir string olsun diye bulunan boþluklar yerine _ koyuyoruz
		 {
		 	temp[i]='_';
		 }
		temp = realloc(temp, (i+1) * sizeof(int)); //her bir char girdisi için ramdeki alanýmýzý büyütüyoruz.
		i++;//temp dizisini ilerliyor
	 }
	 fclose(fp);
	 //dosyadan tüm verileri temp dizisine istediðimiz þekilde aktardýk ve kapattýk.
	 
	 //-----------------------------------------
	 fp=fopen("data_temp.txt","w+");
	 fwrite(temp, sizeof(char), i, fp); //data_temp.txt diye oluþturulan text dosyasýna temp dizimizi yerleþtirdik. böylece ana data bozulmamýþ oldu.
	 fclose(fp); //dosya kapandý.
	 //-----------------------------------------
	 
	 i=0;
     fp = fopen("data_temp.txt","r+" ); //þimdi ise verilerimizi struct arrayde tutmak için geçici dosyamýzý tekrardan okuma modunda açýyoruz.
     fscanf(fp,"%d",&counter); //text dosyasýnda bulunan öðrenci sayýsý bilgisi okunuyor
     student stu[counter]; //struct dizimiz öðrenci sayýsýna göre açýlýyor
     while(!feof(fp)) 
     {  
	    stu[i].name=(char*)malloc(33 * sizeof(char)); //struct dizisinde bulunan isim dizisi için bellekte yer açýlýyor.
        fscanf(fp,"%d %s %d \n",&stu[i].number,stu[i].name,&stu[i].grade); //text dosyasý numara isim not formatýnda olduðu için okuma iþlemi istediðimiz gibi oluyor
        int j=0;
        for(j=0;j<33;j++) 
		{ //öncesinde yerleþtirdiðimiz _ leri kaldýrmak için yazýlan algoritma
        	if(stu[i].name[j]=='_')
			{
        		stu[i].name[j]=' ';
			}
		}
        i++; //struct dizimizde ilerlemeye devam ediyoruz.
	 }
     printf("2019556465 Numarasý Ýçin Doðrusal Arama:\n");
     LinSearchPrimary(stu,counter,2019556465);
     printf("------------------------------------\n\n");
     
     printf("MEHMET ÝPEK Ýsmi Ýçin Doðrusal Arama:\n");
     LinSearchSecondaryName(stu,273,"MEHMET ÝPEK"); //windows-1452 encoderýnda çalýþmaktadýr ve veriyi bulmaktadýr. kendi derleyicimde maalesef onun ayarýný yapamadým.
     printf("------------------------------------\n\n");
     
     printf("SILA BALLI Ýsmi Ýçin Doðrusal Arama:\n");
     LinSearchSecondaryName(stu,counter,"SILA BALLI");
     printf("------------------------------------\n\n");
     
     LinSearchSecondary(stu,counter,100);
     printf("------------------------------------\n\n");
     
     LinSearchSecondary(stu,counter,0);
     printf("------------------------------------\n\n");
    
     sortStructNumber(stu,counter);
     
     printf("2018556011 Numarasý Ýçin Ýkili Arama:\n");
     BinSearchPrimary(stu,counter,2018556011);
     printf("------------------------------------\n\n");
     
     sortStructGrade(stu,counter);
     BinSearchSecondary(stu,counter,73);
     printf("------------------------------------\n\n");
     
     sortStructName(stu,counter);
     printf("DENÝZ UÐUR Ýsmi Ýçin Ýkili Arama:\n");  
     BinSearchSecondaryName(stu,273,"DENÝZ UÐUR"); //windows-1452 encoderýnda çalýþmakta ve veriyi bulmaktadýr. kendi derleyicimde maalesef onun ayarýný yapamadým.
     printf("------------------------------------\n\n");
     
     printf("SILA BALLI Ýsmi Ýçin Ýkili Arama:\n");
     BinSearchSecondaryName(stu,counter,"SILA BALLI");
     printf("------------------------------------\n\n");
     
     fclose(fp);
}

int main()
{
	setlocale(LC_ALL, "Turkish"); //tr karakterler tanýmlandý
	
	int array1[]={3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	int array2[]={3,44,48,5,47,15,36,26,27,2,48,5,19,50,48}; //arrayler oluþturuldu
	
	sort(array1,15);
	sort(array2,15); //arayler sýralandý.
	printf("1.Dizi Ýçin 3,5,48 Deðerleriyle Doðrusal Arama:\n");
	LinSearch(array1,15,3);
	LinSearch(array1,15,5);
	LinSearch(array1,15,48);
	printf("------------------------------------\n\n");
	
	printf("2.Dizi Ýçin 3,5,48 Deðerleriyle Doðrusal Arama:\n");
	LinSearch(array2,15,3);
	LinSearch(array2,15,5);
	LinSearch(array2,15,48);
	printf("------------------------------------\n\n");
	
	printf("1.Dizi Ýçin 3,5,48 Deðerleriyle Ýkili Arama:\n");
	printf("------------------------------------\n");
	BinSearch(array1,15,3);
	BinSearch(array1,15,5);
	BinSearch(array1,15,48);
	printf("------------------------------------\n\n");
	
	printf("2.Dizi Ýçin 3,5,48 Deðerleriyle Ýkili Arama:\n");
	BinSearch(array2,15,3);
	BinSearch(array2,15,5);
	BinSearch(array2,15,48);
	printf("------------------------------------\n\n");
	
	FileOperation();
}
