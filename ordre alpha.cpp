#include<stdio.h>
#include<string.h>

main()
{
	char nom[5][30],ch1[30];
	int i,j;
	
	for(i=0;i<5;i++){
	
	printf("entrer le nom %d \n",i);
	fgets(nom[i],sizeof(nom[i]),stdin);
	
	}
	
	for(i=0;i<5;i++)
	{
		for(j=i+1;j<5;j++)
		{
			if(strcmp(nom[i],nom[j])>0)
			{
				strcpy(ch1,nom[i]);
				strcpy(nom[i],nom[j]);
				strcpy(nom[j],ch1);
			}
		}
	}
	
	for(i=0;i<5;i++)
	puts(nom[i]);
}

