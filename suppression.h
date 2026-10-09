#ifndef SUPPRESSION_H
#define SUPPRESSION_H

#include "liste.h"

/* Fonctions qui retirent des elements */

tete* supprimer (tete* liste, int nbsupprimer);
tete* supprimerentete (tete* liste);
tete* supprimeralafin (tete* liste);
int supprimerposition (tete* liste, int indice);
int supprimerdoublons (tete* liste);
int supprimertout (tete* liste, int nbsupprimer);
#endif
