#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int    MonType;
//     type  | Alias

typedef struct { int val; }  MaStructure;
//     type                 |  alias

struct NomStruct
{
    int value;
};


typedef struct Data{
    int value;
    struct Data* pointeur;
} Data;


typedef struct PileElement {
    double valeur;
    struct PileElement* suivant;
} PileElement;

typedef struct  
{
    struct PileElement* tete;    
} Pile;

void test_pile(){
    Pile pile = {0}; 
}

bool empiler(Pile* p, double valeur){
    PileElement* elem = malloc( sizeof(PileElement) );
    if( elem == NULL ){
        return false;
    }
    
    elem->valeur = valeur;
    elem->suivant = p->tete;
    p->tete = elem;    
    
    return true;
}

void liste(){
    
    MonType maVariable = 12;

    Data d1 = {.value = 1, .pointeur = NULL};
    Data d2 = {.value = 2, .pointeur = &d1};
    Data d3 = {.value = 3, .pointeur = &d2};
    Data d4 = {.value = 4, .pointeur = &d3};
    d1.pointeur = &d4;

    printf("\nHello\n");

    int val = d1.pointeur->value;
    printf("La valeur = %d\n", val);

    //          d4       d3          d2       d1        d4        d3        3
    val = d1.pointeur->pointeur->pointeur->pointeur->pointeur->pointeur->value;
    printf("La valeur = %d\n", val);
}