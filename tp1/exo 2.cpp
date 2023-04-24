#include<stdio.h>
int main (){


	int a,b,c,m,n,max,min,i;
	
	printf("entrer a et b et c : \n");
	scanf("%d%d%d",&a,&b,&c);
	
	m=(a<b)?b:a;
	n=(a<b)?a:b;
	max=(c>m)?c:m;
	min=(c<n)?c:n;
	
	i= (min==c)?n : (max==c)?m:c;
	
	
	printf("l ordre est: %d,%d,%d \n",min,i,max);}
