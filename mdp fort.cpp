#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

int mdpfort(char*ch)
{
	int n,i,j,k=0;
	n=strlen(ch)-1;
	
	for(i=0;i<n;i++)
	{
		if(islower(ch[i]))
		k++;
	}
	
	
	if(k>=n)
	return 0;
	
	else {
		for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(ch[i]==ch[j])
			 break;
		}
		
		if(j!=n)
		break;
		
	}
	
	if (i==n)
	return 1;
	
	else
	return 0;
		
	}
}

main()
{
	char ch1[20];
	
	
	printf("entrer le mdp :\n");
	fgets(ch1,20,stdin);
	
	if(mdpfort(ch1)==1)
	printf("valide \n");
	
	else
	printf("non valide \n");
	
	
}

