#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char CH[50];
printf("entrer le nom du fichier \n");
gets(CH);

void ADD_LINES (FILES*f1)
{
    int n,i;
    char c='\n',ch[50];
    printf("entrer le nombre des lignes a ajouter :\n");
    scanf("%d",&n);
   
    for(i=0;i<n;i++)
    {
        printf("entrer la chaine \n");
        gets(ch);
        
        if(strlen(ch)>0){
		
        fwrite(ch,sizeof(char),strlen(ch),f1);
        
        fwrite(&c,sizeof(char),1,f1);
    }
    
    else  fwrite(&c,sizeof(char),1,f1);
    
       
    }
   
}

void DELETE_VOID_LINES (FILES*f1)
{
    int n,i;
    char c,c1='\n';
    FILE *f2;
    
    f2=fopen("aide.txt","w");
    
    ch1[0]='\n';
    
    while(fread(&c,sizeof(char),1,f1))
   {
   	  if (c=='\n'&&c1=='\n')
   	  c1=c;
   	  
   	  else
   	  {
   	  	c1=c;
   	  	fwrite(&c1,sizeof(char),1,f1);
		 }
   }
   
   fclose(f1);
   fclose(f2);
   remove(CH);
   rename("aide.txt",CH);
}

void SHOW_N_LINES (FILES*f1)
{
	int n,i=0;cmp=0;
    char c;
    printf("entrer le nombre des lignes a afficher :\n");
    scanf("%d",&n);
    
    while(fread(&c,sizeof(char),1,f1)!=0)
    {
    	if(c=='\n')
    	cmp++;
	}
   i=0; 
   rewind(f1);
     while(fread(&c,sizeof(char),1,f1)!=0)
   {  
   
   	  if (c=='\n')
   	  i++;
   	  if(i>=cmp-n)
   	  printf("%c",c);
   }
    
    
}
