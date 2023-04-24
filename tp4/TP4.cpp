#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Une fonction pour calculer le nombre des apparitions d’un caractère dans une chaines de caractères//
int NMBRAPPR (char T[],char c)
{
	int i=0,cmpt=0;
	while (T[i])
	{
		if (T[i]==c)
		cmpt++;
		
		i++;
	}
	
	return cmpt;
}
//Une fonction pour calculer le nombre des mots dans une chaines de caractères.//
int NMBRMOTS (char T[])
{
	int i=0; int cmpt=1;
	
	while (T[i]!='\0')
	{
		if (T[i]==' ' || T[i]=='\t'  || T[i]=='\n' )
		cmpt++;
		i++;
	}

return cmpt;
}
//Une fonction pour convertir les lettres de minuscules à majuscules.//
void CONVR (char T[])
{  int i;
 
 for(i=0;T[i];i++)
  {
  
		if (T[i]>='a' && T[i]<='z')
		T[i]-= 'a' -'A';
		 
  }
  
  puts(T);
	
 } 
//fonction de compression
void COMPRESS(char T[])
{
  int i,n=strlen(T),cmpt=1;
  
  for(i=0;i<n;i++)
  { cmpt=1;
  	 while(i<n-1 && T[i]==T[i+1])
  	 { i++;cmpt++;}
  	 
  	 printf("%c%d",T[i],cmpt);
}	 
printf("\n");}
//fonction de decompression
void Decompress (char T[])
{
	int i,n,cmpt;
	n=strlen(T);
	for(i=0;i<n;i++)
	{
		if (T[i]>=49 && T[i]<58)
		cmpt=T[i]-48;
		
		while(cmpt!=0)
		{ printf("%c",T[i-1]); cmpt--;
		}
	}
printf("\n");}

main()
{    int n;
	char T[50];
//calculer le nombre des apparitions d’un caractère dans une chaines de caractères//	
	printf("entrer la chaine des caracteres : \n");
	gets(T);
	n=NMBRAPPR(T,'a');
	printf("le nombre d'apparition de 'a' est %d \n",n);
//calculer le nombre des mots dans une chaines de caractères.//	
	printf("entrer la chaine des caracteres : \n");
	gets(T);
	n=NMBRMOTS(T);
	printf("le nombre d'apparition des mots est %d \n",n);
//convertir les lettres de minuscules à majuscules.//	
	printf("entrer la chaine des caracteres : \n");
	gets(T);
	printf("la chaine en majuscule est : \n");
	CONVR (T);
//compression//
	printf("entrer la chaine des caracteres : \n");
	gets(T);
	printf("la chaine compressee est : \n");
	COMPRESS(T);
//decompression//	
	printf("entrer la chaine des caracteres : \n");
	gets(T);
	printf("la chaine decompressee est : \n");
	Decompress(T);
	
		  }          
	          

  

		

 
 

