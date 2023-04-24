#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define BUFFER_SIZE 1000

//Fonction de suppression d'un caractere
void SuppAppCara(char c,char nomfichier[50]){
    FILE *nouveau,*ancien;
    char L;

    ancien=fopen(nomfichier,"r");
    if (!ancien)
     {
      printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", nomfichier);
      exit(-1);
     }
    nouveau=fopen("supp.txt","w");
    if (!nouveau)
     {
      printf("\aERREUR: Impossible d'ouvrir le fichier: supp.txt.\n");
      exit(-1);
     }
    while((L=fgetc(ancien)) != EOF){
       if(L!=c)
        fputc(L,nouveau);
    }
    fclose(ancien);
    fclose(nouveau);
    remove(nomfichier);
    rename("supp.txt",nomfichier);
}

//Fonction pour convertir de minuscule en majuscule 
void MintoMaj(char nomfichier[50]){

    FILE *f, *f1;
    char c;
    f = fopen(nomfichier,"r");
    if (!f)
     {
      printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", nomfichier);
      exit(-1);
     }
     f1 = fopen("supp.txt","w");
    if (!f1)
     {
      printf("\aERREUR: Impossible d'ouvrir le fichier: supp.txt\n");
      exit(-1);
     }
     while((c=fgetc(f))!=EOF){
        if(islower(c)){
          c=c-32;
         }
         putc(c,f1);
     }
    fclose(f);
    fclose(f1);
    remove(nomfichier);
    rename("supp.txt",nomfichier);
}


//Fonction pour convertir de majuscule a minuscule 
void MajtoMin(char nomfichier[50]){

    FILE *f, *f1;
    char c;
    f = fopen(nomfichier,"r");
    if (!f)
     {
      printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", nomfichier);
      exit(-1);
     }
     f1 = fopen("supp.txt","w");
    if (!f1)
     {
      printf("\aERREUR: Impossible d'ouvrir le fichier: supp.txt\n");
      exit(-1);
     }
     while ( (c = fgetc(f)) != EOF)
    {

        c = (isupper(c))? tolower(c):toupper(c);
        fputc(c, f1);
    }
    fclose(f);
    fclose(f1);
    remove(nomfichier);
    rename("supp.txt",nomfichier);
}


//Fonction pour compter le nombre d'occurence d'un mot 
int ComptMot(char mot[50],char nomfichier[50]){

    char str[BUFFER_SIZE];
    char *pos;
    int index, count;
    FILE *f;

    f = fopen(nomfichier,"r");
    if (!f)
     {
      printf("\aERREUR: Impossible d'ouvrir le fichier: %s.\n", nomfichier);
      exit(-1);
     }
    count = 0;
    while ((fgets(str, BUFFER_SIZE, f)) != NULL)
    {
        index = 0;
        while ((pos = strstr(str + index, mot)) != NULL)
        {
            index = (pos - str) + 1;
            count++;
        }
    }
    return count;
}


int main(){
    char mot[50], nomf[50], c;
    int occ = 0;
    system("cls");
    printf("******************************** MENU ********************************\n");
    printf("Taper 1 pour supprimer l'apparition d'un caractère\n");
    printf("Taper 2 pour convertir de minuscule a majuscule\n");
    printf("Taper 3 pour convertir de majuscule a minuscule\n");
    printf("Taper 4 pour compter le nombre d'occurences d'un mot\n");
    printf("Taper 0 pour sortir du programme\n");
    printf("Votre choix: ");

    switch(getch())
    {
    case '1':
    system("cls");
    printf("\nEntrer le nom du fichier : ");
    scanf("%s", nomf);
    printf("\nEntrer le caractere a supprimer : ");
    fflush(stdin);
    scanf("%c",&c);
    SuppAppCara(c,nomf);
    printf("\nle caractere %c est supprime avec succes !", c);
    break;
    case '2':
      system("cls");
      printf("\nEntrer le nom du fichier : ");
      scanf("%s", nomf);
      MintoMaj(nomf);
      printf("\nle texte est converti de minuscule a majuscule avec succes !");
    break;
    case '3':
      system("cls");
      printf("\nEntrer le nom du fichier : ");
      scanf("%s", nomf);
      MajtoMin(nomf);
      printf("\nle texte est converti de majuscule a minuscule avec succes !");
    break;
    case '4':
      system("cls");
      printf("\nEntrer le nom du fichier : ");
      scanf("%s", nomf);
      printf("\nEntrer le mot a rechercher : ");
      scanf("%s",mot);
      occ = ComptMot(mot,nomf);
      printf("\nLe nombre d'occurence du mot est : %d", occ);
    break;
    case '0':
	  printf("\nFin du programme, au revoir !");
      break;
    }
}

