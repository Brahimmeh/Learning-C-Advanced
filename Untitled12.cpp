#include<stdio.h>



int Calcul(int n,int b)
{
	if(n==0)
	return 0;
	
	
	if (n%10==b)
	return(1+Calcul(n/10,b));
	
	else
	return(0+Calcul(n/10,b));

	
	
}




main()
{
	int n=12424252,b=2,m;
	
	m=Calcul(n,b);
	
	printf("%d",m);
}
