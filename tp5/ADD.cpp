#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
char NomV[10] ; 
int Habits ; 
} Ville ;


main()
{
	FILE *f; 
	char ch[50],ch1[50];
	int a,i;
	Ville liste1[5];
	
	printf("entrer le nom du fichier \n");
	gets(ch);
	f=fopen(ch,"ab+");
	
	while(fread(&liste1[0],sizeof(Ville),1,f)!=0)
	printf("%s         %d\n",liste1[0].NomV,liste1[0].Habits);
	
	for(i=0;i<5;i++){
	
	printf("entrer le nom de la ville a ajouter \n");
	fflush(stdin);
	gets(liste1[i].NomV);
	printf("entrer le num d'habits de la ville \n");
	scanf("%d",&liste1[i].Habits);
	
	fwrite(&liste1[i],sizeof(Ville),1,f);
     }
 }
