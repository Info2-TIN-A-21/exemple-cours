#include <stdio.h>
#include <stdlib.h>

void ex4(){
    printf("Ex 4 allocation\n");
    int size = 7;
    int* tab = (int*)malloc(sizeof(int) * size);


    for(int i = 0; i<20; i++){
        if( i < size )
            tab[i] = i;
        else{

            //printf("La nouvelle taille du tableau vaut : %d\n", size );

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