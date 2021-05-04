
#include <stdio.h>

#include "saisie.h"

Data saisie()
{
    printf("\033[1;32mLa saisie\n\033[0m");
    Data d = {.value = 5, .error = 0};
    return d;
}