/*
 * Fonction_bandit.h
 * ----------------
 *  auteur: sebastien
 *  date : 21/08/14
 *
 *  But : fonction qui permettent utilitaire pour les calculs des resultats
 */

#include "struct_bandit_param.h"

/** Fonction qui renvoie un double compris entre 0 et 1 */
double drand();

/** Renvoie la valeur de la recompense (gain ou perte) */
/** lorsqu'on tire sur le bras i du bandit b */
double recompense(bandit b, bras i);
