#ifndef __BANDIT__
#define __BANDIT__ 
#define MAX_BRAS 10

#include <stdio.h>
#include <stdlib.h>

/** Des declarations anticipees des types */
/*Ces renommages permettent d ’alleger le code */
typedef struct bandit bandit;
typedef struct parametres parametres;

struct parametres {
    /** Le montant de la perte */
    double perte;
    /** Le montant d’un gain */
    double gain;
    /** La probabilite d’un gain */    
    double proba_gain;
    /** Booleen activation bras */
    int active;
    /** Recompense moyenne */
    double rec_moyenne;
};

struct bandit {
    /**Nombre de bras */
    int K;
    /**Un tableau de parametres : l ’entree i correspond */
    /** aux parametres du bras i */
    parametres param[MAX_BRAS];
};

/** Fonction qui renvoie un double compris entre 0 et 1 */
double drand () ;

/** Renvoie la valeur de la recompense ( gain ou perte ) */
/** lorsqu’on tire sur le bras i du bandit b */
double recompense(bandit b, int i);

double esperance(double perte, double gain, double proba);

int array_length(int a);

int epsilonGlouton(bandit b, double epsilon);

#endif
