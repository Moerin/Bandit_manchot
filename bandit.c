#include "bandit.h"

double drand() {
    return ((double)rand() * (1.0 - 0.0)) / (double)RAND_MAX + 0.0;
}

double recompense(bandit b, int i) {
    printf("%s\n", "***");
    return (drand() <= b.param[i].proba_gain) ? b.param[i].gain : b.param[i].perte;
}

double esperance(double perte, double gain, double proba) {
    return perte * (1 - proba) + gain * proba;
}

int array_length(int a) {
    return sizeof(a)/sizeof(int);
}

int epsilonGlouton(bandit b, double epsilon) {
    int index;
    if (drand() >= epsilon) {
        double max_rec = 0.0;
        int i;
        for (i=0;i<b.K;i++) {
           if (max_rec < b.param[i].rec_moyenne) {
               max_rec = b.param[i].rec_moyenne;
               index = i;
           } 
        }
    } else {
        index = rand() % b.K;
    }
    return index;
}
