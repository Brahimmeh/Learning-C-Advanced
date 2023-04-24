#include<stdio.h>
#include<string.h>
 
void printRLE(char T[])
{
    int n = strlen(T);
    for (int i = 0; i < n; i++) {
 
        // Count occurrences of current character
        int cmpt = 1;
        while (i < n - 1 && T[i] == T[i + 1]) {
            cmpt++;
            i++;
        }
 
        // Print character and its count
        printf("%c%d",T[i],cmpt);
    }
}
 
int main()
{  char T[50];
    gets(T);
    printRLE(T);
    
}
