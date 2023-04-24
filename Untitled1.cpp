#include<stdio.h>
#include<stdlib.h>

main()
{
	FILE * f;  char ch[50];
	
	
	f=fopen("fichier12.txt","r");
	
	if(!f)
	{
		printf("erreur d'ouverture \n");
		exit(1);
	}
	
	else
	
	{
		while(!feof(f))
		{
			fscanf(f,"%s",ch);
			puts(ch);
		}
	}
}
