#include <stdlib.h>
#include "liste.h"
#include "insertion.h"

tete* insererentete (tete* liste, int value)
{
 
    ensemble* ensembleentete = creerensemble (value);
    ensembleentete->suivant = liste->premier;
    liste->premier = ensembleentete;
    return liste;
}

tete* insereralafin (tete* liste, int value)
{
    ensemble* ensemblealafin = creerensemble(value);
    ensemble* courant = liste->premier;
 
    if (liste->premier == NULL)
    {
        liste->premier = ensemblealafin; 
        return liste;
    }
    while (courant->suivant != NULL)
    {
        courant = courant->suivant;
    }
    courant->suivant = ensemblealafin;
    return liste;
}

tete* inserertrie (tete* liste, int value)
{
    ensemble* valeurinserer = creerensemble (value);
    ensemble* courant = liste->premier;
    ensemble* precedent = NULL;

    while (courant != NULL && courant->valeur < value)
    {
        precedent = courant;
        courant = courant->suivant;

    }
        if (precedent == NULL)
        {
            valeurinserer->suivant = liste->premier;
            liste->premier = valeurinserer;    
        }
        else 
        {
            valeurinserer->suivant = courant;
            precedent->suivant = valeurinserer;
        }
    return liste;    
}

int insererposition (tete* liste, int indice, int value)
{
    if (indice < 0)
    {
        return 0;
    }

    if (indice == 0)
    {
        insererentete(liste, value);
        return 1;
    }

    ensemble* precedent = liste->premier;
    int i;
    while (precedent != NULL && i < indice-1)
    {
        precedent = precedent->suivant;
        i++;
    }
    if (precedent == NULL)
    {
        return 0;
    }
   
    ensemble *nouveau = creerensemble(value);
    nouveau->suivant = precedent->suivant;
    precedent->suivant = nouveau;
    return 1;
}
