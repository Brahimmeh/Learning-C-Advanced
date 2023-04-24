// les chaines de caracteres 

#include<stdio.h>
#include<string.h>

main(){
	char TXT[201]; // chaîne de caractere    
	int j,i;
	char c;
	
	/* Saisie des données */
	printf("Entrer un texte : ");
	scanf("%s", TXT);
	printf("Entrer un caractere : ");
	scanf(" %c", &c);
	j=0;
	 /* Copier les caractères # de c, de i vers j et incrémenter j */
	for(i=0;TXT[i];i++){
		
		if(c!=TXT[i]){
		TXT[j]=TXT[i];
		j++;
		}
	
	}
	/* Terminer la chaîne !! */
	TXT[j]='\0';
	printf("Le texte : \n");
	puts(TXT);
}
