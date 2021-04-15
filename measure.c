#include <stdio.h>
#include <stdlib.h>

#define START_DAY 20
#define NBR_MEASURE 10
#define NBR_DAY 20
#define NBR_READ_MEASURES 5

typedef struct
{
    int x;
    double value;
} Measure;

typedef struct
{
    int day;
    Measure measure[NBR_MEASURE];
} Data;

// Fonction pour faire le reset d'une structure
// ....

Data readMeasure(int day, char* filename) {}

void readMeasures(int day, char* filename, size_t nbrMeasure, Data tab[]) {}

void ex_measure()
{
    // On simule une mesure par jour
    for (int i = 0; i < NBR_DAY; i++)
    {
        // init de la structure
        // init du numéro du jour

        // Boucle pour remplir le tableau de mesure
        for (int m = 0; m < NBR_MEASURE; m++)
        {}
    }

    // Partie lecture

    // Affiche la taille

    // Le numéro du jour que l'on veut lire
    const int NumDayToRead = 30;

    // Lecture d'une mesure
    Data res = {0};

    // Lecture de plusieurs mesures
    Data res_tab[NBR_READ_MEASURES] = {0};

    // Test si le programme fonctionne

    printf("\nTest de la lecture\n");

    if (NumDayToRead == res.day)
    {
        printf("\033[1;32mLecture d'un résultat ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture d'un résultat pas bon\n\033[0m");
    }

    if (res.measure[0].x == 0)
    {
        printf("\033[1;32mLecture mesure 1 ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture mesure 1 pas bon\n\033[0m");
    }

    // Test de la lecture en tableau
    if ((NumDayToRead + 1) == res_tab[1].day)
    {
        printf("\033[1;32mLecture d'un résultat ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture d'un résultat pas bon\n\033[0m");
    }

    if (res_tab[1].measure[0].x == 0)
    {
        printf("\033[1;32mLecture mesure tab 1 ok\n\033[0m");
    }
    else
    {
        printf("\032[1;32mLecture mesure tab 1 pas bon\n\033[0m");
    }
}