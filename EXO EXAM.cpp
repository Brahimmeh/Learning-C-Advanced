#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct {
	
	char Nom[50],Password[50],Role[30];
	
}utilisateur;

int i=0;
utilisateur U[30];


int rechercher (char Nm[50])
{  int j=0;

	while(i)
	{
	if (strcmp(U[j].Nom,Nm)==0)
	return j+1;
	
	j++;
	i--;
	}
	
	return -1;
}

void Ajout(utilisateur a,FILE *f)
{  i=0;

	while(fread(&U[i],sizeof(utilisateur),1,f))
	{
		i++;
	}
	
	if((rechercher(a.Nom)==-1))
	printf("already exist\n");
	
	else
	{
		strcpy(U[i+1].Nom,a.Nom);
		strcpy(U[i+1].Password,a.Password);
		strcpy(U[i+1].Role,a.Role);
		
	}
}

int mdpfort(char*ch)
{
	int n,i,j,k=0;
	n=strlen(ch);
	
	for(i=0;i<n;i++)
	{  if(isalpha(ch[i]))
	   {
	   
		if(islower(ch[i]))
		k++;}
	}
	
	
	if(k>=n)
	return 0;
	
	else {
		for(i=0;i<n;i++)
	{
	     if(isalpha(ch[i]))
	    {
		
		for(j=i+1;j<n;j++)
		{  
			if(ch[i]==ch[j])
			 break;
		}
		
		if(j!=n)
		break;
		}
		
	}
	
	if (i==n)
	return 1;
	
	else
	return 0;
		
	}
}

