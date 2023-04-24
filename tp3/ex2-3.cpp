#include<stdio.h>

#include<string.h>
main() {
	char ch1[30],ch2[30],c;
	int i,j,N1,N2;
	printf("Saisir un mot : ");
	gets(ch1);
	printf("Saisir un mot : ");
	gets(ch2);
	N1=strlen(ch1);
	N2=strlen(ch2);
	//trier le 1er mot
	for(i=0; i<N1; i++) {
		for(j=i+1; j<N1; j++) {
			if(ch1[j]<ch1[i]) {
				c=ch1[i];
				ch1[i]=ch1[j];
				ch1[j]=c;
			}
		}
	}
	//trier le 2eme mot
	for(i=0; i<N2; i++) {
		for(j=i+1; j<N2; j++) {
			if(ch2[j]<ch2[i]) {
				c=ch2[i];
				ch2[i]=ch2[j];
				ch2[j]=c;
			}
		}
	}

	if(strcmp(ch1,ch2)==0)
		printf("Les deux mots sont anagrammes");
	else
		printf("Les deux mots ne sont pas anagrammes");
	
}
