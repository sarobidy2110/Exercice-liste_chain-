#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

ensemble* creerensemble (int value)
{
    ensemble* ensembleacreer = malloc (sizeof (ensemble));
    if (ensembleacreer == NULL)
    {
        printf ("Erreur d'allocation memoire!\n");
        exit (1);
    }
    ensembleacreer->valeur = value;
    ensembleacreer->suivant = NULL;
    return ensembleacreer;
}

void afficherensemble (tete* liste)
{
    ensemble* courant = liste->premier;
    while (courant != NULL)
    {
        printf ("[%d]->", courant->valeur);
        courant = courant->suivant;
    }
    printf ("NULL\n");
}

int compterensemble (tete* liste)
{
    int compteur = 0;
    ensemble* courant = liste->premier;
    while (courant != NULL)
    {
        compteur ++;
        courant = courant->suivant;
    }
    return compteur;
}

void libererliste (tete* liste)
{
    ensemble* courant = liste->premier;
    while (courant != NULL)
    {
        ensemble* corbeille = courant;
        courant = courant->suivant;
        free (corbeille);
    }
    free (liste);
}
