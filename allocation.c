#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ex4(){
    printf("Ex 4 allocation\n");
    int size = 7;
    int* tab = (int*)malloc( size * sizeof(int) );
    if( tab == NULL )
        exit(EXIT_FAILURE);

    for(int i = 0; i<20; i++){
        if( i < size )
            tab[i] = i;
        else{
            int* tmp = (int*)malloc( size * sizeof(int) );
            if( tmp == NULL ){
                free(tab);
                exit(EXIT_FAILURE);
            }

            memcpy(tmp, tab, size);
            size *= 2;
            printf("La nouvelle taille du tableau vaut : %d\n", size );

            free(tab);
            tab = tmp;
            //lien = "google.fr";
        }
    }

    free(tab);
}

void ex4_bis()
{
    printf("Ex 4 bis allocation\n");
    int size = 7;
    int* tab = (int*)malloc(sizeof(int) * size);
    if( tab == NULL )
        exit(EXIT_FAILURE);

    for(int i = 0; i<20; i++){
        if( i < size )
            tab[i] = i;
        else{
            int* tmp = (int*)realloc(tab, sizeof(int) * size * 2);
            if( tmp == NULL )
            {
                free(tab);
                exit(EXIT_FAILURE);
            }

            size = size * 2;
            printf("La nouvelle taille du tableau vaut : %d\n", size );

            tab = tmp;            
        }
    }

    free(tab);
}

void example(){
    // Ex 2
    char* text = "Bonjour";
    char txt[] = "Bonjour";

    char c1 = text[1];
    char c2 = txt[1];

    int size = strlen(text) + 1; // 7
    char* tmp = (char*)malloc( size * sizeof(char) );

    // 'B o n j o u r \0'
    printf("%s", tmp);


    int taille = 12;

    int* p = (int*)malloc( taille * sizeof(int) );

    if( p == NULL )
        exit(EXIT_FAILURE);

    p[2] = 435;

    free(p);
    p = NULL;
}

void allocation(){
    printf("Exemple d'allocation\n");

    //example();

    ex4();
}