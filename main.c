#include <time.h>
#include "bandit.h"

int main() {
    
    /* initialize random seed: */
    srand(time(NULL));

    bandit b;
    parametres p1, p2;
    /** Les parametres pour le premier bras */
    p1.perte = -1.0;
    p1.gain = 10;
    p1.proba_gain = 0.1;
    p1.active = 0;
    /** Les parametres pour le deuxieme bras */
    p2.perte = 0.0;
    p2.gain = 2;
    p2.proba_gain = 0.5;
    p2.active = 0;
    /** Les parametres pour le deuxieme bras */
    /** Parametre du bandit */
    b.K = 2;
    b.param[0] = p1;
    b.param[1] = p2;

    int i;
    int j = 1;
    int h = 1;
    double somme[2] = {0.0, 0.0};

    for (i = 0;i<1000;i++) {
        if (b.param[0].active == 1 && b.param[1].active == 1) {
            int index = epsilonGlouton(b, 0.80);
            somme[index] += recompense(b, index);
            b.param[index].rec_moyenne = somme[0]/++j;

            printf("Somme %d : %f\n", index, somme[index]);
            printf("Rec moyenne %d : %f\n", index, b.param[index].rec_moyenne);
        } else {
            int numero_bras = rand() % 2;
            if (numero_bras == 0) {
                somme[0] += recompense(b, numero_bras);
                b.param[numero_bras].rec_moyenne = somme[0]/++j;
                /** Activation des bras */
                b.param[numero_bras].active = 1;
                printf("Somme 1 : %f\n", somme[0]);
                printf("Rec moyenne 1 : %f\n", b.param[numero_bras].rec_moyenne);
            } else {
                somme[1] += recompense(b, numero_bras);
                b.param[numero_bras].rec_moyenne= somme[1]/++h;
                b.param[numero_bras].active = 1;
                printf("Somme 2 : %f\n", somme[1]);
                printf("Rec moyenne 2 : %f\n", b.param[numero_bras].rec_moyenne);
            }
        }
 
    } 
    /** Moyenne */
    somme[0] /= j;
    somme[1] /= h;

    printf("esperance0: %f ", esperance(b.param[0].perte, b.param[0].gain, b.param[0].proba_gain));
    printf("somme0: %f\n", somme[0]);

    printf("esperance1: %f ", esperance(b.param[1].perte, b.param[1].gain, b.param[1].proba_gain));
    printf("somme1: %f\n", somme[1]);

    return 0;
}
