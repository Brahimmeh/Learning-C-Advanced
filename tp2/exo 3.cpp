#include<stdio.h>
#include<stdbool.h>
int main (){


	int POINTS[50],n,j,i,max,min,som=0;
	float moy;
	int*pt;
	bool k=true;
do{
	
	printf("entrer le nombre des eleves : \n");
	scanf("%d",&n);
	
	
}while(n<=0 || n>20);
//lecture des notes et calcul du somme
for(pt=POINTS;pt<POINTS+n;pt++)
{ printf("entrer la note d'eleve %d: \n",pt-POINTS);
  scanf("%d",pt);
  som+=*pt;
}


//recherche de max et min 
max=min=POINTS[0];
do{
k=false;
for(pt=POINTS;pt<POINTS+n;pt++){
	if(*pt >max)
  {
  
  max=*pt;
  k=true;}
  
 if(*pt <min)
  {
  min=*pt;
  k=true;}
}
}while(k==true);

//calcul du moy et affichage des max,min,moy

moy=(float)som/n;

printf("max = %d \nmin = %d \nmoy = %.2f \n",max,min,moy);

//tableau NOTES;
int NOTES[4]={0,0,0,0};

for(pt=POINTS;pt<POINTS+n;pt++)
{
	
	if(*pt>=0 && *pt<10)
	NOTES[0]++;
	
	else if(*pt>=10 && *pt<12)
	NOTES[1]++;
	
	else if(*pt>=12 && *pt<16)
	NOTES[2]++;
	
	else 
	NOTES[3]++;
}

for(i=0;i<4;i++)
printf("NOTES[%d] = %d \n",i,NOTES[i]);

}


