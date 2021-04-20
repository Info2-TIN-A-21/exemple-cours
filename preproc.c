#include <stdio.h>
#include <limits.h>

// include
#include <stdlib.h>

// define
#define SIZE 12
#define DEBUG 0

// macro, pas de ;
#define MAX(a,b)\
    (a > b ?\
     a : b)

#define PRINT_INT(a) printf("La valeur de %s : %d\n", #a, a)

void func1(){
    printf("Bonjour");

    #if DEBUG
        printf("Affichage de débug\n");
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
}

#define AFFICHAGE func2

#define PRINT_FOO(a) printf("La valeur de foo" #a " vaut %d\n", foo##a )



void preproc(){

    int foo = 12;
    PRINT_INT(foo);


    int foo1 = 4;
    int foo2 = 8;
    PRINT_FOO(1);
    PRINT_FOO(2);

    int max = INT_MAX;
    

    #if DEBUG
        printf("Affichage de débug\n");
    #endif

    // #define PRINT_INT(a) printf("La valeur de %s : %d\n", #a, a)
    // printf("La valeur de %s : %d\n", "var", 12);

    printf("max : %d", MAX(2,3));
    //max(2,3);
    

    #if DEBUG
        printf("Affichage de débug\n");
    #endif

    AFFICHAGE();

}