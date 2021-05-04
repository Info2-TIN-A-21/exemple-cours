#include <stdio.h>
#include <limits.h>

// include, copie le contenu du fichier
#include <stdlib.h>

// define
#define SIZE 12
#define DEBUG 0

// défini un symbol sans valeur
#define PRODUCTION


// Exercice 1 bien écrit
#define EX1_MAX(x, y) ((x) > (y) ? (x) : (y))



#define MAC(p) (12 + p)

// macro, pas de ;
#define MAX(a,b)\
    (a > b ?\
     a : b)

#define PRINT_INT(a) printf("La valeur de %s : %d\n", #a, a)

//Exemple string
#define MAC_STR(a) #a

void func1(){
    printf("Bonjour\n");

    #if DEBUG == 1
        printf("Affichage de débug\n");
    #endif

    // est-ce que le symbol est défini
    #ifdef PRODUCTION        
        printf("Mode production\n");
    #endif

    #ifdef VERSION
        #if VERSION > 4
            int i = 24;
        #endif
    int i = 12;
    #else
    int i = 56;
    #endif

}

void func2(){
    printf("Hello");

    int val = MAC(3); //int val = (12 + 3);
    int res = MAC(12 * 4 + 2); // int res = (12 + 12 * 4 + 2);

}

#define AFFICHAGE func2

#define PRINT_FOO(a) printf("La valeur de foo" #a " vaut %d\n", foo##a )



void preproc(){

    int foo = SIZE;
    PRINT_INT(foo);

    char* text = MAC_STR(1234);

    int foo1 = 4;
    int foo2 = 8;
    PRINT_FOO(1);
    PRINT_FOO(2);

    int max = INT_MAX;
    

    #if DEBUG
        printf("Affichage de débug\n");
    #endif

    func1();

    // #define PRINT_INT(a) printf("La valeur de %s : %d\n", #a, a)
    // printf("La valeur de %s : %d\n", "var", 12);

    printf("max : %d\n", MAX(2,3));
    
    //max(2,3);
    

    #if DEBUG
        printf("Affichage de débug\n");
    #endif

    AFFICHAGE();

    puts("La fin des examples");
}