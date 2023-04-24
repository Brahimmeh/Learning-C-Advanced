#include<stdio.h>
#include<string.h>


// nbr d'pparition d'un caractere
int nbrAp(char c, char ch[50]){
	int i,cp=0;

	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]==c)
		{
			cp++;		
		}
	}	
	return cp;
}
// Nombre des mots
int nbrMot(char ch[50]){
	int i,c=0;

	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i]==' ' || ch[i]=='\t' || ch[i]=='\n')
		{
			c++;		
		}
	}	
	return c+1;
}
// Convertir en Maj
void Maj(char ch[50]){
	int i,c=0;

	for(i=0;i<strlen(ch);i++)
	{
		if(ch[i] >= 'a' && ch[i] <= 'z') {
         ch[i] = ch[i] -32;

	}	
	
}}

// Compression

main()
{

	int n;
	char c;
	char ch[50];
	printf("entrez la chaine :	");
	gets(ch);
	printf("Entrer le caractere : ");
	scanf("%c",&c);
	n=nbrAp(c,ch);
	printf("le nombre des apparitions de %c est : %d \n",c,n);
	n=nbrMot(ch);
	printf("le nombre des mots est : %d \n",n);
	Maj(ch);
	puts(ch);

	
}
