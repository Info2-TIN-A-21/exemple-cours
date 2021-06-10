
#include <stdio.h>

#define ROUGE_D 0

// les valeurs enum sont des int
typedef enum {
    ROUGE, // 0
    BLEU, // 1
    VERT // 2
} Couleur;

typedef enum {
    INDICATEUR_VERT, // 0
    INDICATEUR_ROUGE // 1
} Indicateur;

typedef enum {
    IDLE,           // 0
    POWER_ON = 4,   // 4
    FOO,            // 5
    POWER_OFF = 6,  // 6    
    IN_PROGRESS = 3,// 3
    WAITING,        // 4  ATTENTION car il y a deux fois le 4
    ERROR = 10,     // 10
    ERROR_SENSOR    // 11
} State;

typedef struct {
    State state;
    Couleur coul;
    int value;
} Data;

void funcStruct(State c){
    switch (c)
    {
    case IDLE :
        printf("Idle");        
        break;

    case ERROR :
        printf("Error");        
        break;
    
    default:
        break;
    }
}

void test_enum(){

    printf("Test enum\n");

    Couleur c1;
    c1 = ROUGE;

    Couleur c2 = VERT;

    if( c1 == ROUGE ){
        printf("C'est rouge\n");
    }

    // on test si c1 est rouge
    if( c1 == 0 ){
        printf("C'est rouge\n");
    }

    // si pas d'énum on doit utiliser une variable int, donc moins lisible
    int c_def = ROUGE_D;
    if( c_def == ROUGE_D ){
        printf("C'est rouge\n");
    }

    
    State s1 = POWER_ON;
    State s2 = WAITING;

    if( s1 == s2 ){
        printf("Le même état\n");
    }

    if( s1 >= ERROR ){
        printf("Il y a une erreur\n");
    }
}