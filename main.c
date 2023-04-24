#include <stdio.h>
#include<FctsTd1.h>

 main() {
 	int n,p;
 	//Exercice 1
 	printf("entrer un nombre : ");
	 scanf("%d", &n);
	 
	 p=Premier(n);
	 
	if(p==0)
	printf("%d n'est pas premier \n",n);
	else
	printf("%d est premier \n",n);	
	//Exercice 2
	Goldbach(n);
	
	//Exercice 3
	
	int n2;
	float s;
	printf("entrer un nombre : ");
	scanf("%d", &n2);
	s=SommeInvCarr(n2);
	printf("la somme est : %f\n", s);
	 

	// Exercice 4
	int n3;
	printf("entrer un nombre : ");
	scanf("%d", &n3);
	printf("Fibonacci(%d)= %d \n", n3, Fibo(n3));

}


