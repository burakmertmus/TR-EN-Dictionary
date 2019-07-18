#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
void entr(char aran[],int sBoyut);
void tren(char aran[],int sBoyut);
int dosyaAyir();
	int main(int argc, char *argv[]){
		
	
		int sBoyut=dosyaAyir();
		
	char aranan[20];
	int secim=0;
	a:
	printf(" Ingilizce Turkce Ýcin 1\n Turkce Ingilizce icin 2 giriþini yapýnýz.\n ");
	scanf("%d",&secim);
	
	while(secim!=3){
	system("cls");
	
	switch(secim){
		case 1 :{
			printf("Ceviri yapilacak kelimeyi giriniz.\n");
			scanf("%s",&aranan);
			entr(aranan,sBoyut);
			break;
		}
		case 2 :{
			printf("Ceviri yapilacak kelimeyi giriniz.\n");
			scanf("%s",&aranan);
			tren(aranan,sBoyut);
			break;
		}
		default :{
			printf("Sen");goto d;
			break;
		}
	}
	
	printf(" EN-TR---1\n TR-EN---2 \n Cikis---3 Lutfen bir secim yapiniz.\n ");
		scanf("%d",&secim);
	d:
		
		
		getch();
		goto a;
	
}

return 0;
getch();
	
}
int dosyaAyir(){
			
	FILE *dosya,*turkce,*ingilizce;
	
	dosya=fopen("sozluk.txt","r");
	turkce=fopen("turkce.txt","w");
	ingilizce=fopen("ingilizce.txt","w");
	
	
	char tr[20],en[20],aranan[10];
	char harf;
	int satirSay=0,i=0,j=0;
	bool durum=true;
	
		for(int k=0;k<sizeof(tr)+1;k++){
				tr[k]=NULL;
			}
			for(int k=0;k<sizeof(en)+1;k++)
			{	
				en[k]=NULL;
			}
			
	char dene;
	dene=fgetc(dosya);
	satirSay++;
	while(!feof(dosya)){
			if(isspace(dene))
			{
			satirSay++;
			//printf("%d\n%c\n",satirSay,dene);
			
			}
		
		dene=fgetc(dosya);
		
	}
	fclose(dosya);
	/*printf("Aranacak kelime");
	gets(aranan);
	printf("%d",strlen(aranan));
	*/
	dosya=fopen("sozluk.txt","r");
	//printf("%d\n%c\n",satirSay,dene);
		 satirSay=(satirSay/2)+1;
		int sayac=1;
		while(sayac<satirSay){
			harf=fgetc(dosya);
			if(isalpha(harf)){
				tr[0]=harf;	
			}
			durum=true;
			i=0;
			j=0;
				while(isspace(harf)||isalpha(harf))
			 {			
					harf=fgetc(dosya);
					
					if(isspace(harf))
					{
					durum=false;
					}
					else if(isalpha(harf))
					{	
						if(!isspace(harf) && durum){
							i++;
							tr[i]=harf;
							
						}else if(!isspace(harf) && !durum){
							en[j]=harf;
							j++;		
						}
					}
				if(harf=='\n')
				{
					break;
				}
			}
			
			//dizileri Ekrana yazdýrma
			/*for(int k=0;k<sizeof(tr)+1;k++){
			printf("%c",tr[k]);
			}
			for(int k=0;k<sizeof(en)+1;k++){
			printf("%c",en[k]);
			}*/
			sayac++;		
			//dizileri dosyaya yazdýrma
			for(int i=0;i<sizeof(tr)+1;i++){
				if(isalpha(tr[i])){
					fprintf(turkce,"%c",tr[i]);
				}
			}
	
			for(int i=0;i<sizeof(en)+1;i++){
				if(isalpha(en[i]))
				{
					fprintf(ingilizce,"%c",en[i]);
				}
			}
		
			fprintf(ingilizce,"\n");
			fprintf(turkce,"\n");
			
			//Dizileri Null yapma
			for(int k=0;k<sizeof(tr)+1;k++){
				//printf("%c",tr[k]);
				tr[k]=NULL;
			}
		
			for(int k=0;k<sizeof(en)+1;k++)
			{	
				//printf("%c",en[k]);
				en[k]=NULL;
			}
			
		}
	fclose(turkce);
	fclose(ingilizce);
	fclose(dosya);
	return satirSay;
}
void entr(char aran[],int sBoyut){
	FILE *turkce,*ingilizce;
	turkce=fopen("turkce.txt","r");
	ingilizce=fopen("ingilizce.txt","r");
		int i=0,sayac=0;
		char str[10];
	bool durum =true;
	fscanf(ingilizce,"%s",str);
	while(sayac<sBoyut){
	
		if(strcmp(str,aran)==0){
		 printf("%d satirinda buldu\n",sayac+1);
		 break;	 
		}else  {
			for(int a=0;a<strlen(str)+1;a++){
				str[a]=NULL;
			}
			
			sayac++;
			fscanf(ingilizce,"%s",str);	
		}
		if(sayac==sBoyut)
		{
			durum=false;
			printf("Kelime bulunamadi!!!\n\n\n\n");
			break;
		}
	}
	
	char bulun[10];
	
if(durum){

	do{
		for(int a=0;a<strlen(str)+1;a++){
			str[a]=NULL;
		}
		fscanf(turkce,"%s",bulun);
		sayac--;
	}while(sayac+1!=0);
	printf("%s - %s dir.\n",aran,bulun);
}else{
	
}
	fclose(ingilizce);
	fclose(turkce);
}
void tren(char aran[],int sBoyut){
	
	FILE *turkce,*ingilizce;
	turkce=fopen("turkce.txt","r");
	ingilizce=fopen("ingilizce.txt","r");
	char str[10];
	int sayac=0;
	bool durum =true;
	fscanf(turkce,"%s",str);
	while(sayac<sBoyut){
		
	
		if(strcmp(str,aran)==0){
		 printf("%d satirinda buldu\n",sayac+1);
		 break;	 
		}else{
			
			for(int a=0;a<strlen(str)+1;a++){
				str[a]=NULL;
			}
			
			sayac++;
			fscanf(turkce,"%s",str);	
		}
		
		
		if(sayac==sBoyut)
		{
			durum=false;
			printf("Kelime bulunamadi!!!\n\n\n\n");
			break;
		}
	}
	
	
	if(durum){
			
		char bulun[10];
		while(sayac+1!=0)
		{
			for(int a=0;a<strlen(str)+1;a++){
				str[a]=NULL;
			}
			fscanf(ingilizce,"%s",bulun);
			sayac--;
		}
		printf("%s - %s dir.\n",aran,bulun);
	}
	
	fclose(ingilizce);
	fclose(turkce);
	
}
