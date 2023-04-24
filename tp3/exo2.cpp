#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main ()
{   
	int i,j,n,n2;
	char ch1[50],ch2[50],aide;
	void trialphab(char[],int);
	
	printf("introduiser la chaine 1 :\n");
	gets(ch1);
	n=strlen(ch1);
	printf("introduiser la chaine 2 :\n");
	gets(ch2);
	n2=strlen(ch2);	
	trialphab(ch1,n);
	trialphab(ch2,n2);
	
if(strcmp(ch1,ch2)==0 && n==n2)
printf("les chaines sont anagrammes \n");
else
printf("les chaines ne sont pas anagrammes \n");

return 0;
}

//fonction//

void trialphab(char ch1[],int n)
{
	char aide;
	int i,j;
	
	n=strlen(ch1);
	
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{ if(ch1[j]<ch1[i])
		  {
		  	aide=ch1[i];
		  	ch1[i]=ch1[j];
		  	ch1[j]=aide;
		  }
			
		}
	}
}
