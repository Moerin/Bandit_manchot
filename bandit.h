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
    /** Somme des recompenses */
    double som_recompense;
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
double drand ();

/** Renvoie la valeur de la recompense ( gain ou perte ) */
/** lorsqu’on tire sur le bras i du bandit b */
double recompense(bandit b, int i);

/** Calcule l'esperance selon des parametres passe en signature */
double esperance(double perte, double gain, double proba);

/** Cette methode prend en parametre un bandit 
 * et une valeur de probabilite
 *
 * Dans le cas ou epsilon est inferieur ou egale au rand
 * le bras ayant la recompense moyenne la plus eleve est recupere
 * Sinon on selection un bras selon une loi de probabilite uniforme
 *
 * Retourne l'index d'un bras du bandit*/
int epsilonGlouton(bandit b, double epsilon);

#endif
