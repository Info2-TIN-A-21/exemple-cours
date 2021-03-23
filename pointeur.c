#include <stdio.h>

void pres()
{
    size_t s1 = sizeof(int*);
    size_t s2 = sizeof(char*);

    char c = 'a';
    int i = 0x1234;
    char* pc = NULL;
    pc = &c;
    int* pi = &i;

    // valeur int dans un pointeur de char
    char* pc1 = &i;

    char val = *pc + 2;

    printf("Val i = %d", *pi);

    int txt[] = {0x1, 0x2, 0x1234};
    int* p1 = txt;
    int* p2 = &txt[1];  // On prend l'adresse

    int v1 = *p1;  // vaut : 1
    int v2 = *p2;  // vaut : 2
    int v3 = p1[2];  // vaut : 0x1234

    p1 = p1 + 2;

    int a = 0;
}

void text_et_pointeur(){
    // tableau caractère
    char text[] = "Bonjour";

    char first = text[0];

    // complet
    char* pc = &text[0];

    // simple 
    char* pc1 = text;

    // prendre l'adresse du premier caractère
    char* pc2 = "Hello";

    puts("\nAffichage d'un caractère");
    printf("%c\n", pc2[1]);
    // interdit, on ne peut pas modifier une chaîne avec un pointeur
    //pc2[2]= 'a';
}

void pointeur() {

    text_et_pointeur();

     pres(); 
}