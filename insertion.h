#ifndef INSERTION_H
#define INSERTION_H

#include "liste.h"

/* Fonctions qui ajoutent des elements */

tete* insererentete (tete* liste, int value);
tete* insereralafin (tete* liste, int value);
tete* inserertrie (tete* liste, int value);
int insererposition (tete* liste, int indice, int value);

#endif
