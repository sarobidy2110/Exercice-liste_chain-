#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "liste.h"

/* Fonctions qui reorganisent les pointeurs (sans nouveau maillon) */

tete* inverser (tete* liste);
tete* fusionner (tete* liste1, tete* liste2);
tete* concatener (tete* liste1, tete* liste2);
void separer (tete* liste, tete* pairs, tete* impairs);
void rotation (tete* liste, int k);

#endif
