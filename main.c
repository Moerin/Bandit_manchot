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
    p1.som_recompense = 0.0;
    /** Les parametres pour le deuxieme bras */
    p2.perte = 0.0;
    p2.gain = 2;
    p2.proba_gain = 0.5;
    p2.active = 0;
    p2.som_recompense = 0.0;
    /** Les parametres pour le deuxieme bras */
    /** Parametre du bandit */
    b.K = 2;
    b.param[0] = p1;
    b.param[1] = p2;

    int i;
    // Nombre total d'appel a un bras
    int j = 1; // premier bras
    int h = 1; // deuxieme bras

    for (i = 0;i<1000;i++) {
        // Si les bras on deja ete appele au moins une fois on appel la fonction
        // e-glouton
        if (b.param[0].active == 1 && b.param[1].active == 1) {
            int index = epsilonGlouton(b, 0.80);
            b.param[index].som_recompense += recompense(b, index);
            b.param[index].rec_moyenne = b.param[index].som_recompense/j++;

            printf("Somme %d : %f\n", index, b.param[index].som_recompense);
            printf("Rec moyenne %d : %f\n", index, b.param[index].rec_moyenne);
        } else {
            // Premier appel des bras
            int numero_bras = rand() % 2;
            if (numero_bras == 0) {
                b.param[numero_bras].som_recompense += recompense(b, numero_bras);
                b.param[numero_bras].rec_moyenne = b.param[numero_bras].som_recompense/j++;
                /** Activation des bras */
                b.param[numero_bras].active = 1;
                printf("Somme 1 : %f\n", b.param[numero_bras].som_recompense);
                printf("Rec moyenne 1 : %f\n", b.param[numero_bras].rec_moyenne);
            } else {
                b.param[numero_bras].som_recompense += recompense(b, numero_bras);
                b.param[numero_bras].rec_moyenne = b.param[numero_bras].som_recompense/h++;
                /** Activation des bras */
                b.param[numero_bras].active = 1;
                printf("Somme 2 : %f\n", b.param[numero_bras].som_recompense);
                printf("Rec moyenne 2 : %f\n", b.param[numero_bras].rec_moyenne);
            }
        }
 
    } 

    printf("esperance0: %f ", esperance(b.param[0].perte, b.param[0].gain, b.param[0].proba_gain));
    printf("somme0: %f\n", b.param[0].som_recompense);

    printf("esperance1: %f ", esperance(b.param[1].perte, b.param[1].gain, b.param[1].proba_gain));
    printf("somme1: %f\n", b.param[1].som_recompense);

    return 0;
}
