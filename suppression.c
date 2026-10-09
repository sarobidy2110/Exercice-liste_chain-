#include <stdlib.h>
#include "liste.h"
#include "suppression.h"

tete* supprimer  (tete* liste, int nbsupprimer)
{
    ensemble* courant = liste->premier;
    ensemble* precedent = NULL;
 
    while (courant != NULL && courant->valeur != nbsupprimer)
    {
        precedent = courant;
        courant = courant->suivant; 
    }
    if (courant == NULL)
    {
        return liste;
    }
 
    if (precedent == NULL)
    {
        liste->premier = courant->suivant;
    }
    else 
    {
    precedent->suivant = courant->suivant;
    }
    free (courant);
    return liste;
}

tete* supprimerentete (tete* liste)
{
    if (liste->premier == NULL)
    {
        return liste;
    }
    ensemble* corbeille = liste->premier;
    liste->premier = corbeille->suivant;
    free (corbeille);
    return(liste);
}

tete* supprimeralafin (tete* liste)
{
    ensemble* courant = liste->premier;
    ensemble* precedent = NULL;

    while (courant != NULL)
    {
        precedent = courant;
        courant = courant->suivant;
    }

    if (precedent == NULL)
    {
        liste->premier = NULL;
    }
    else
    {
        precedent->suivant = NULL;
    }
    free(courant);
    return liste;
}

int supprimerposition (tete* liste, int indice)
{
    if (indice < 0 || liste->premier == NULL)
    {
        return 0;
    }

    ensemble* courant = liste->premier;
    ensemble* precedent = NULL;
    int i = 0;

    while (courant != NULL && i < indice)
    {
        precedent = courant;
        courant = courant->suivant;
        i++;
    }
    if (courant == NULL)
    {
        return 0;
    }

    if (precedent == NULL)
    {
        liste->premier = courant->suivant;
    }
    else
    {
        precedent->suivant = courant->suivant;
    }
    free (courant);
    return 1;
}
int supprimerdoublons (tete* liste)
{
    int nbsupprimes = 0;
    ensemble* courant = liste->premier;

    while (courant != NULL && courant->suivant != NULL)
    {
        if (courant->valeur == courant->suivant->valeur)
        {
            ensemble* doublon = courant->suivant;
            courant->suivant = doublon->suivant;    
            free (doublon);
            nbsupprimes++;                          
        }
        else
        {
            courant = courant->suivant;
        }
    }
    return nbsupprimes;
}

int supprimertout (tete* liste, int nbsupprimer)
{
    int nbsupprimes = 0;
    ensemble* courant = liste->premier;
    ensemble* precedent = NULL;

    while (courant != NULL)
    {
        if (courant->valeur == nbsupprimer)
        {
            ensemble* suivant = courant->suivant;   
            if (precedent == NULL)
            {
                liste->premier = suivant;
            }
            else
            {
                precedent->suivant = suivant;
            }
            free (courant);
            courant = suivant;                      
            nbsupprimes++;
        }
        else
        {
            precedent = courant;
            courant = courant->suivant;
        }
    }
    return nbsupprimes;
}
tete* copier (tete* liste)
{
    tete* copie = malloc (sizeof (tete));      
    copie->premier = NULL;

    ensemble* fin = NULL;                      
    ensemble* courant = liste->premier;

    while (courant != NULL)
    {
        ensemble* nouveau = creerensemble (courant->valeur);  
        if (fin == NULL)
        {
            copie->premier = nouveau;
        }
        else
        {
            fin->suivant = nouveau;
            fin = nouveau;
            courant = courant->suivant;
        }
    }
    return copie;
}