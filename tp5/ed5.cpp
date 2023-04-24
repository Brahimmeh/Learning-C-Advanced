#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
char NomV[10] ; 
int Habits ; 
} Ville ;

int Chercher_Ville (FILE *f1, char * ch)
{
	int i=0;
	Ville liste;
	
    while(fread(&liste,sizeof(Ville),1,f1)!=0)
    {  
             i++;
             
    	if (strcmp(liste.NomV,ch)==0)
    	return i;
		
	}
	
	return -1;
}

int Ajout_ville (FILE*f1)
{
	Ville liste1,liste2;
	char ch[50];
	
	printf("entrer le nom de la ville a ajouter \n");
	gets(liste1.NomV);

	
	    while(fread(&liste2,sizeof(Ville),1,f1)!=0)
    {  
           
    	if (strcmp(liste2.NomV,liste1.NomV)==0)
    	{

    		printf("le nom de cette ville deja existe \n");
    		return 0;
		}
		
	}
	printf("entrer le num d'habits de la ville \n");
	scanf("%d",&liste1.Habits);
	fwrite(&liste1,sizeof(Ville),1,f1);
	
}


void Affiche (FILE*f1)
{
	Ville liste;
	
	printf("Nom         Habits\n");
	
	while(fread(&liste,sizeof(Ville),1,f1)!=0)
	{
		printf("%s         %d\n",liste.NomV,liste.Habits);
	}
	
}

void ModifierNMBRH (FILE *f1,char *ch)
{
	Ville liste1 , liste2;
	FILE*f2;
	int a=0;
	
	f2=fopen("aide.bin","wb");
	
	printf("entrer le nom de la ville a modifier \n");
	fflush(stdin);
	gets(liste1.NomV);

	
	 while(fread(&liste2,sizeof(Ville),1,f1)!=0)
    {  
           
    	if (strcmp(liste2.NomV,liste1.NomV)==0)
    	{    	printf("entrer le nouveau num d'habits de la ville \n");
	            scanf("%d",&liste1.Habits);
	            liste2.Habits=liste1.Habits;
				a=1	;
     	}
    		
		
		
		fwrite(&liste2,sizeof(Ville),1,f2);
		
	}
	
	if(a==0)
	printf("le nom n'existe pas \n");
	
	fclose(f1);
	fclose(f2);
	remove(ch);
	rename("aide.bin",ch);
    
}

void Affiche_an (FILE *f1)
{ 
	
	Ville liste;
	
    while(fread(&liste,sizeof(Ville),1,f1)!=0)
    {  
            if(strstr(liste.NomV,"an")!=NULL)
    	
    	printf("%s         %d\n",liste.NomV,liste.Habits);	
    		
		
	}
}

main()
{
	FILE *f; 
	char ch[50],ch1[50];
	int a;
	
	printf("entrer le nom du fichier \n");
	gets(ch);
	f=fopen(ch,"rb+");
	
	if(f==NULL)
	{
		printf("erreur \n");
		exit(1);
	}
	
	
	printf("entrer le nom de la ville a rechercher : \n");
	gets(ch1);
	a=Chercher_Ville (f,ch1);
	if(a!=(-1))
	printf("la position de la ville recherche est : %d \n",a);
	else
	printf("le nom n'existe pas \n");
	
	rewind(f); 
	Ajout_ville (f);
	
	rewind(f);
	Affiche (f);
	
    rewind(f);	
    ModifierNMBRH (f,ch);
    

    f=fopen(ch,"rb+");
    rewind(f);
    Affiche_an(f);
	
	
	
	
	
}

