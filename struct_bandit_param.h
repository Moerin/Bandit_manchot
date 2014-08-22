#define MAX_BRAS 10

/** Des declarations anticipees des types           */
/** Ces renommages permettent d'alleger le code     */
typedef struct bandit bandit;
typedef struct parametres parametres;


struct parametres {
    /** Le montant de la perte */
    double perte;
    /** Le montant d'un gain */
    double gain;
    /** La probabilite d;un gain */ 
    double proba_gain;
};

struct bandit {
    /** Nombre de bras */
    int k;
    /** Un tableau de parametres: l'entree i correspond */
    /** aux parametre du bras i                         */
    parametres param[MAX_BRAS];
};
