#include<stdio.h>
#include<string.h>

typedef struct {
    char NomV[10];
    int Habits;
}Ville;

int  rechercheVille(FILE *f, char nomVille[10]){
    Ville v;
    int i=0;
    rewind(f);
    while(fread(&v,sizeof(Ville),1,f)!=0){
        i++;
        if(strcmp(v.NomV,nomVille)==0)
        return i;
    }
    return -1;
}

void AjoutVille(FILE *f, char nomville[10]){
    rewind(f);
    if(rechercheVille(f,nomville)==-1){
        Ville v;
        strcpy(v.NomV,nomville);
        printf("entrer le nombre d'habitants: ");
        scanf("%d",&v.Habits);
        fwrite(&v,sizeof(Ville),1,f);
    }
    else
    {
        printf("la ville %s existe deja \n",nomville);
    }
    
}

void AffVille(FILE *f){
    rewind(f);
    Ville v;
    while(fread(&v,sizeof(Ville),1,f)!=0){
        printf("Nom de la ville : %s\n",v.NomV);
        printf("Nombre d'habits: %d\n",v.Habits);
    }
}

void ModifVille(FILE *f, char nomville[10]){
    if(rechercheVille(f,nomville)==-1){
        printf("la ville %s est introuvable \n",nomville);
    }
    else
    {
        rewind(f);
        Ville v;
        FILE *f2;
        f2=fopen("inter.bin","wb");
        while(fread(&v,sizeof(Ville),1,f)!=0){
            if(strcmp(v.NomV,nomville)==0){
                printf("entrer le nouveau nbr d'habits: ");
                scanf("%d",&v.Habits);
            }

            fwrite(&v,sizeof(Ville),1,f2);
        }

        fclose(f2);
        fclose(f);
        remove("villes.bin");
        rename("inter.bin","villes.bin");


    }
    
}

void AffVilleAn(FILE *f){
    rewind(f);
    Ville v;
    while(fread(&v,sizeof(Ville),1,f)!=0){
        if(strstr(v.NomV,"an")!=NULL)
        {
            printf("Nom de la ville : %s\n",v.NomV);
        printf("Nombre d'habits: %d\n",v.Habits);
        }
    }
}

int main(){
FILE *f;
char nomville[10];
f=fopen("villes.bin","a+b");
printf("entrer le nom de la ville recherche: ");
scanf("%s",nomville);
int r=rechercheVille(f,nomville);
if(r==-1){
    printf("la ville %s introuvable \n",nomville);
}
else
printf("la ville %s existe a la position %d \n",nomville,r);



printf("entrer le nom de la ville a ajouter: ");
scanf("%s",nomville);
AjoutVille(f,nomville);

AffVille(f);

printf("entrer le nom de la ville a modifier: ");
scanf("%s",nomville);
ModifVille(f,nomville);

f=fopen("villes.bin","a+b");
AffVille(f);


printf(" les villes dont le nom contient le mot an sont : \n");
AffVilleAn(f);



    return 0;
}