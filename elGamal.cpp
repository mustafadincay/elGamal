#include <stdio.h>
#include<time.h>
#include <string.h>
#include <stdlib.h>

int usIsle( int taban,int us,int mod){
	int temp;
	temp=taban;
	for(int i=1;i<us;i++){
		temp=(temp*taban) % mod;
	}	
	return temp;
}
int main(){
	printf("\t\t\t\t\tMustafa Dincay 2016210206005\n\n\n");
	int p,alfa,a,acik[3],b,m,gama,kapali[2],sonuc,temp;
	int delta;
	srand(time(NULL));
	printf("\np asal sayisi giriniz\t:");
	scanf("%d",&p);
	printf("\nalfa sayisi giriniz\t:");
	scanf("%d",&alfa);
	printf("\na sayisi giriniz :"); 
	scanf("%d",&a);	
	acik[0]=p; 
	acik[1]=alfa;
    acik[2]=usIsle(alfa,a,acik[0]);
	printf("A kisisinin acik anahtarlari: %d %d %d\n",acik[0],acik[1],acik[2]);
	printf("A kisisinin gizli anahtari: %d",a);
	printf("\n\n\t\tSiflereme kismi\n");
	printf("B kisisi sifreleme yapmak icin A kisisinin acik anahtarlarini (%d %d %d) kullanir\n",acik[0],acik[1],acik[2]);
	printf("b sayisini giriniz: \n");
	scanf("%d",&b);
	int bSifre=usIsle(alfa,b,acik[0]);
	printf("B sifrelendi: %d",bSifre);
	printf("\nmetni giriniz: ");
	scanf("%d",&m);
	temp=m*(usIsle(acik[2],b,acik[0]));
	delta=temp%acik[0];
	printf("Delta sayisi %d\n",delta);
    printf("\n\n\t\t Desifreleme kismi\n");
	gama=usIsle(bSifre,p-1-a,p);
	printf("gama: %d\n",gama);
	sonuc=(gama*delta)%acik[0];
	printf("sonuc: %d",sonuc);
	
	
	return 0;
}
