#ifndef ANALYSE_H
#define ANALYSE_H

#include "liste.h"

/* Fonctions qui lisent la liste sans la modifier */

int rechercher (tete* liste, int nbrechercher);
int somme (tete* liste);
int maximum (tete* liste);
int obtenir (tete* liste, int indice, int* resultat);
int minimum (tete* liste);
double moyenne (tete* liste);
int occurrences (tete* liste, int nbcompter);
int egales (tete* liste1, tete* liste2);

#endif
