#include<stdio.h>

int somme (int n)
{
	if (n==0)
	return 0;
	
	else
	return n+somme(n-1);
}

int search (int a,int n)
{
	int i=0;
	
	if(n==0)
	return 0;
	
	else
	{   if(a==n%10)
	    return 1+search(a,n/10);
		//n=n/10;
		else
		return 0+search(a,n/10);
	}
	
	 }

main()
{
	int a=10,b;
	
	b=search (2,27252582);
	
	printf("%d",b);
}
