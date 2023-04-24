#include<stdio.h>
#include<string.h>

int main ()
{
	int i,j,n;
	char ch1[50],c;
	char*f;
	
	printf("introduiser votre chaine :\n");
	gets(ch1);
	n=strlen(ch1);
	printf("entre le caractere a supprime : \n");
	scanf("%c",&c);
	f=strchr(ch1,c);
	while(f!=NULL)
	{   for(i=f-ch1;i<n;i++)
		ch1[i]=ch1[i+1];
		f=strchr(f+1,c);
	}
	puts(ch1);
}
