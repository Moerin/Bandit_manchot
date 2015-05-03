/*
 * fonction_bandit
 *
 * Auteur: sebastien
 * Date 21/08/14
 *
 * But: definitions des fonctions utilitaire du bandit
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "fonction_bandit.h"

double drand() {
    srand(time(NULL));
    double d = (double)rand() / (double)RAND_MAX;
    printf("%f", d);
    return d; 
}


double recompense(bandit b, bras i) {
    return 0;
}


