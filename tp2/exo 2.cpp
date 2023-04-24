#include<stdio.h>
int main (){


	int T[20],n;
	int*pt;
	int*pt2,AIDE;
do{
	
	printf("entrer N : \n");
	scanf("%d",&n);
	
	
}while(n<0 || n>20);

pt=T;

for(pt=T;pt<T+n;pt++)
{ printf("entrer T[%d]: \n",pt-T);
 scanf("%d",pt);
}

for(pt=T;pt<T+n;pt++)
{ printf("T[%d]= %d \n",pt-T,*pt);
 
}

for(pt=T,pt2=T+n-1;pt<T+n/2;pt++,pt2--)
{
    AIDE = *pt;
	*pt=*pt2;
	*pt2=AIDE;	
}

printf("\n tableau inverse : \n");
for(pt=T;pt<T+n;pt++)
{ printf("T[%d]= %d \n",pt-T,*pt);
 
}

}
