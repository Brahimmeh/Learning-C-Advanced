#include<stdio.h>
int main (){


	int a,b,c,i;
do{
	
	printf("entrer a : \n");
	scanf("%d",&a);
	printf("entrer b : \n");
	scanf("%d",&b);
	
}while(a<0 || b<0);

printf(" a= %d \n",a);
//avec for
for(i=1,c=1;i<b;i++)
{
	c*=a;
}
printf("a^(b)=%d \n",c);
//avec while
c=1;i=0;
while(i<b)
{ c*=a;
  i++;
}
printf("a^(b)=%d \n",c);}
