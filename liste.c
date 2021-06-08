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

bool depiler(Pile* p, double* val){

    if(p->tete == NULL){
        return false;
    }

    *val = p->tete->valeur;

    PileElement* depile = p->tete;

    p->tete = depile->suivant;
    free(depile);
    return true;
} // tmp n'existe plus

void test_pile(){
    Pile pile = {0}; 
    empiler(&pile, 12.3);
    empiler(&pile, 4.3);
    empiler(&pile, -5.67);

    double val;
    depiler(&pile, &val);
    printf("Valeur dépilée : %.2lf\n", val);
    depiler(&pile, &val);
    printf("Valeur dépilée : %.2lf\n", val);
}


typedef struct FileElement {
    int valeur;    
    struct FileElement* suivant;
}FileElement;

typedef struct{
    FileElement* tete;
    FileElement* queue;
} File;

bool enfiler(File* f, int valeur){
    if( f == NULL ){
        return false;
    }

    FileElement* elem = malloc( sizeof(FileElement) );
    if( elem == NULL ){
        return false;
    }

    elem->valeur = valeur;
    elem->suivant = NULL;

    if( f->queue == NULL ){ // liste vide
        f->tete = elem;
    }
    else {
       f->queue->suivant = elem; 
    }

    f->queue = elem;
    return true;
}

bool defiler(File* f, int* valeur){
    if( f == NULL && f->queue == NULL ){
        return false;
    }

    FileElement* current = f->tete;
    *valeur = current->valeur;

    f->tete = current->suivant;

    if( f->tete == NULL ){
        f->queue = NULL;
    }

    free(current);

    return true;    
}

void test_file(){
    File f = {0};
}


typedef struct {
    int num;
    double value;
} DataEx4;

typedef struct ElemEx4 {
    DataEx4 valeur;
    struct ElemEx4* suivant;
} ElemEx4;

typedef struct  
{
    struct ElemEx4* tete;    
} PileEx4;

bool inserer_ex4(PileEx4* p, int num, double value){
    if( p == NULL ){
        return false;
    }

    ElemEx4* elem = malloc( sizeof(ElemEx4) );
    if( elem == NULL ){
        return false;
    }

    elem->valeur.num = num;
    elem->valeur.value = value;
    elem->suivant = NULL;
    
    if( p->tete == NULL || num < p->tete->valeur.num ){
        elem->suivant = p->tete;
        p->tete = elem;
        return true;
    }

    ElemEx4* cur = p->tete;
    while ( cur->suivant != NULL && num > cur->suivant->valeur.num )
    {
        cur = cur->suivant;   
    }
    
    elem->suivant = cur->suivant;
    cur->suivant = elem;

    return true;
}

void test_ex4(){
    PileEx4 p = {0};
    inserer_ex4(&p, 2, 2.2);
    inserer_ex4(&p, 1, -1.1);
    inserer_ex4(&p, 20, 7.8);
    inserer_ex4(&p, 5, 9);

    ElemEx4* c = p.tete;
    while (c != NULL)
    {
        printf("ID : %d / Value : %.2lf\n", c->valeur.num,  c->valeur.value);
        c = c->suivant;
    }
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

    test_pile();

    test_file();

    test_ex4();
}