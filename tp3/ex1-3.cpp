// les chaines de caracteres 

#include<stdio.h>
#include<string.h>

main(){
	char TXT[201]; // cha�ne de caractere    
	int j,i;
	char c;
	
	/* Saisie des donn�es */
	printf("Entrer un texte : ");
	scanf("%s", TXT);
	printf("Entrer un caractere : ");
	scanf(" %c", &c);
	j=0;
	 /* Copier les caract�res # de c, de i vers j et incr�menter j */
	for(i=0;TXT[i];i++){
		
		if(c!=TXT[i]){
		TXT[j]=TXT[i];
		j++;
		}
	
	}
	/* Terminer la cha�ne !! */
	TXT[j]='\0';
	printf("Le texte : \n");
	puts(TXT);
}
