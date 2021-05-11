
#include <stdio.h>
#include <string.h>
#include "tda.h"

char* getName(List* l, int pos){
    return (l->contacts[pos].name);
}

void tda(){
    printf("\033[1;33mExemple de TDA\n\033[0m");

    List list;
    list.nbrContact = 0;

    list.contacts[0].id = 1;
    strcpy(list.contacts[0].name, "Alice");
    list.nbrContact++;

    list.contacts[1].id = 2;
    strcpy(list.contacts[1].name, "Bob");
    list.nbrContact++;

    // il ne faut pas, dangereux
    //list.nbrContact += 3;

    // on remplace accès par des fonctions
    //list.contacts[1].name
    printf("name : %s\n", getName(&list, 1));

    // pas pratique car on accès directement aux champs de la structure
    for( int i=0; i<list.nbrContact; i++)
        printf("Contact # %d, name : %s / id : %d\n", i, list.contacts[i].name, list.contacts[i].id);
}