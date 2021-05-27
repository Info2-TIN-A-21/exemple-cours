#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include "tda.h"

// jamais de .c
//#include "saisie.c"

// ajouter prototype de saisie
// déclare la fonction saisie
// déplace dans saisie.h
//void saisie();
#include "saisie.h"

#include "algo.h"

// déclare la fonction test
void test();

int main(void)
{
    // fichier();
    // pointeur();
    // allocation();
    // ex_measure();
    // preproc();

    test();
    Data d = saisie();
    d.value;

    Data d1 = algo();

    tda();

    FILE* ff = fopen("test.txt", "w");

    int* a = malloc(1000);
    free(a);

    

    // ici l'os va contrôler la mémoire et la fermeture des fichiers
}

void test(){
    printf("Dans la fonction test\n");
}