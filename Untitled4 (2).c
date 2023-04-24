#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void SuppAppCara(char nomF[],char c);
void MintoMaj(char nomF[50]);
void MajtoMin(char nomF[50]);
int ComptMot(char nomF[50]);
main(){
	FILE *f;
	int op=0;
	char nomF[50],mot[50],c;
	do{
		printf("\n\t\t\t\t ******** MENU ********\n");
		printf("\t\t Tapez 1 pour supprimer un caractere d'un fichier\n");
		printf("\t\t Tapez 2 pour convertir de minuscule a majuscule\n");
		printf("\t\t Tapez 3 pour convertir de majuscule a minuscule\n");
		printf("\t\t Tapez 4 pour compter le nombre d'occurence d'un mot\n");
		printf("\t\t Tapez 0 pour quitter le programme\n");
		printf("\t\t => Votre choix : ");
		scanf("%d",&op);
		switch(op){
			case 1: 
			    printf("entrer le nom du fichier : ");
			    scanf("%s",&nomF);
			    SuppAppCara(nomF,c);
				break;
			case 2:
			    printf("entrer le nom du fichier : ");
			    scanf("%s",&nomF);
			    MintoMaj(nomF);
				break;
			case 3:
			    printf("entrer le nom du fichier : ");
			    scanf("%s",&nomF);
			    MajtoMin(nomF);
				break;
			case 4:
			    printf("entrer le nom du fichier : ");
			    scanf("%s",&nomF);
			    ComptMot(nomF);
				break;
			case 0:
			    printf("\n\t FIN DU PROGRAMME . AU REVOIR !!\n");
				break;
			default: printf("\n\n\t !! ERREUR DE CHOIX . REESSAYEZ !!\n\n");
		}
	}while(op!=0);
}
void SuppAppCara(char nomF[],char c){	
	FILE *f;
	FILE *f1;
	char caractere;
	int i=0,find=0;
	f=fopen(nomF,"r");
	f1=fopen("texte.txt","w");
	if(f==NULL){
		printf("! ERREUR D'OUVERTURE DU FICHIER !");
		exit(1);
	}
	else{
		printf("\t! FICHIER OUVERT AVEC SUCCES !\n");
        printf("Donner le caractere a supprimer : ");
        fflush(stdin);
        scanf("%c",&c);
        do{
        	caractere=fgetc(f);
			if(caractere!=c && !feof(f)){
				i=1;
				fputc(caractere,f1);
			}
		}while(caractere!=EOF);
	    if(i!=0){
	    	printf("Le caractere '%c' est supprime avec succes !\n\n",c);
		}
		else{
			printf("Le caractere '%c' que vou voulez supprimer n'existe pas dans le texte !!\n\n",c);
		}
	}
	fclose(f1);
    fclose(f);
    remove(nomF);
    rename("texte.txt",nomF);
}
void MintoMaj(char nomF[50]){
	FILE *f;
	FILE *f1;
	char caractere;
	int trouve=0;
	f=fopen(nomF,"r");
	f1=fopen("MintoMaj.txt","w");
	if(f==NULL){
		printf("! ERREUR D'OUVERTURE DU FICHIER !");
		exit(1);
	}
	else{
		printf("\t! FICHIER OUVERT AVEC SUCCES !\n");
		do{
			caractere=fgetc(f);
			if(!feof(f)){
				fputc(toupper(caractere),f1);
				trouve=1;
			}	
		}while(caractere!=EOF);
	    if(trouve!=0){
	    	printf("Le texte est converti de minuscule en majuscule avec succes !\n");
		}
		else if(trouve==0){
			printf("\t!!ERREUR DE CONVERSION !!\n");
		}
	}
	fclose(f1);
    fclose(f);
    remove(nomF);
    rename(" MintoMaj.txt",nomF);
}
void MajtoMin(char nomF[50]){
	FILE *f;
	FILE *f1;
	char caractere;
	int trouve=0;
	f=fopen(nomF,"r");
	f1=fopen("MajtoMin.txt","w");
	if(f==NULL){
		printf("! ERREUR D'OUVERTURE DU FICHIER !");
		exit(1);
	}
	else{
		printf("\t! FICHIER OUVERT AVEC SUCCES !\n");
		do{
			caractere=fgetc(f);
			if(!feof(f)){
				fputc(tolower(caractere),f1);
				trouve=1;
			}
		}while(caractere!=EOF);
	    if(trouve!=0){
	    	printf(" Le texte est converti de majuscule en minuscule avec succes !\n\n");
		}
		else if(trouve==0){
			printf("\t!!ERREUR DE CONVERSION !!\n");
		}
	}
	fclose(f1);
    fclose(f);
    remove(nomF);
    rename("MajtoMin.txt",nomF);
}
int ComptMot(char nomF[]){
	FILE *f;
	char mot[50],mot1[50];
	int trouve=0;
	f=fopen(nomF,"r");
	if(f==NULL){
		printf("\n\t ERREUR D'OUVERTURE DU FICHIER \n");
		exit(1);
	}
	else{
		printf("\t! FICHIER OUVERT AVEC SUCCES !\n");
		printf("entrer le mot a rechercher : ");
		scanf("%s",&mot);
		while(fscanf(f,"%s",mot1)!=EOF){
			if(strcmp(mot,mot1)==0){
				trouve++;
			}
		}
		if(trouve!=0){
			printf("Le mot '%s' existe %d fois dans le fichier !\n",mot,trouve);
		}
		else if(trouve==0){
			printf("Le mot '%s' est inrouvable dans le fichier !!\n",mot);
		}
	}
	fclose(f);
	rename("ComptMot.txt",nomF);
}
