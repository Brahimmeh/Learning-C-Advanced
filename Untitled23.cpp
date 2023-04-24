#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
char NomV[10] ; // Nom de la ville
int Habits ; //Nombre d’habitants
} Ville ;


int chercher(FILE *f,Ville a)
{
	Ville v;
	int i=0;
	
	while(i<=40)
	{ 
	   fscanf(f,"%s %d",v.NomV,&v.Habits);
	   
	
		if(strcmp(v.NomV,a.NomV)==0 )
		return i;  
		
		i++;
	}
	
	return 0;
}

int AJOUT (FILE *f,Ville a)
{
	int i=0;
	FILE*f2;
	Ville v;
	
	f2=fopen("aide.txt","w");
	
	while(!feof(f))
	{   
	    fscanf(f,"%s %d",v.NomV,&v.Habits);
		fprintf(f2,"%s %d\n",v.NomV,v.Habits);
		
		if (strcmp(v.NomV,a.NomV)==0)
		{
			printf("deja exist \n");
			fclose(f2);
			remove("aide.txt");
			return 0;
		}
		
		
	}
	
	fprintf(f2,"%s %d\n",a.NomV,a.Habits);
	fclose(f);
	fclose(f2);
	
	remove("fichier.txt");
	rename("aide.txt","fichier.txt");
}

void AFFICHE (FILE*F)
{
	rewind(F);
	Ville v;
	
	while(!feof(F))
	{
		fscanf(F,"%s %d",v.NomV,&v.Habits);
		printf("%s %d\n",v.NomV,v.Habits);
	}
}
main()
{    FILE *f;
    Ville *p,a;
    int v1;
    
    p=(Ville*)malloc(40*sizeof(Ville));

	f=fopen("fichier.txt","r");
	
	printf("entrer le nom de la ville a cher: \n");
    gets(a.NomV);
    printf("entrer le num d HBT de la ville a cher: \n");
    fscanf(stdin,"%d",&a.Habits);
  
    
    v1=chercher(f,a);
	fprintf(stdout,"la position est : %d \n",v1);
	
	printf("entrer le nom de la ville a add: \n");
	fflush(stdin);
    gets(a.NomV);
    printf("entrer le num d HBT de la ville a add: \n");
    fscanf(stdin,"%d",&a.Habits);
    rewind(f);
	AJOUT (f,a);
	
	AFFICHE (f);
	
	
}
