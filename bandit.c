#include "bandit.h"

double drand() {
    return ((double)rand() * (1.0 - 0.0)) / (double)RAND_MAX + 0.0;
}

double recompense(bandit b, int i) {
    return (drand() <= b.param[i].proba_gain) ? b.param[i].gain : b.param[i].perte;
}

double esperance(double perte, double gain, double proba) {
    return perte * (1 - proba) + gain * proba;
}

int epsilonGlouton(bandit b, double epsilon) {
    // Creation de l'index
    int index;
    // Test de probabilite
    if (drand() >= epsilon) {
        // Initialisation de la recompense maximale
        double max_rec = 0.0;
        int i;
        for (i=0;i<b.K;i++) {
           if (max_rec < b.param[i].rec_moyenne) {
               /** Parcours des recompenses moyenne des bras
                * et recupere la valeur max entre tous les bras */
               max_rec = b.param[i].rec_moyenne;
               // Recupere index du bras avec la recompense la plus elevee
               index = i;
           } 
        }
    } else {
        // On choisi au hasard un bras
        index = rand() % b.K;
    }
    return index;
}
