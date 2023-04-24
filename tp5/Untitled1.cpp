#include<stdio.h>
#include<stdlib.h>

typedef struct {
    char NomV[10];
    int Habits;
}Ville;


Ville* read (FILE *f)
{  
    int i=0;
   Ville *p;
    p=(Ville*)malloc(sizeof(Ville)*20);
    
	 
	while((fread(&p[i],sizeof(Ville),1,f))!=0)
	{
		printf("%s  %d \n",p[i].NomV,p[i].Habits);
		i++;
	}
	
	return p;
}

main()
{
	FILE *f1;
	Ville *p;
	int i;
	
	f1=fopen("ville.bin","rb");
	
	p=(Ville*)malloc(sizeof(Ville)*20);
	
	p=read (f1);
	
	for(i=0;i<10;i++)
	{
		printf("%s  %d \n",p[i].NomV,p[i].Habits);
	}
}
