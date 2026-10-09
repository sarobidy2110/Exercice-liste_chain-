#include <stdlib.h>
#include "liste.h"
#include "analyse.h"

int rechercher (tete* liste, int nbrechercher)
{
    ensemble* courant = liste->premier;
    while (courant != NULL)
    {
        if (courant->valeur == nbrechercher)
        {
            return 1;
        }
        courant = courant->suivant;
    }
    return 0;
}

int somme (tete* liste)
{
    int somme = 0;
    ensemble* courant = liste ->premier;
    while (courant != NULL)
    {
        somme = somme + courant->valeur;
        courant = courant->suivant;
    }
    return somme;
}

int maximum (tete* liste)
{
    if (liste->premier == NULL)
    {
        return 0;
    }
    ensemble* courant = liste->premier;
    int max = courant->valeur;
    while (courant != NULL)
    {
        if (max < courant->valeur)
        {
            max = courant->valeur;
        }
        courant = courant->suivant;
    }
    return max;
}

int obtenir (tete* liste, int indice, int* resultat)
{
    if (indice < 0)
    {
        return 0;
    }
    
    ensemble* courant = liste->premier;
    int i = 0;
    while (courant != NULL && i < indice)
    {
        courant = courant->suivant;
        i++;
    }
    if (courant == NULL)
    {
        return 0;
    }
        
    *resultat = courant->valeur;       /* ecrit la valeur a l'adresse donnee */
    return 1;
}

int minimum (tete* liste)
{
    if (liste->premier == NULL)
    {
        return 0;
    }
    ensemble* courant = liste->premier;
    int min = courant->valeur;          /* pas 0 : cela fausserait les negatifs */
    while (courant != NULL)
    {
        if (courant->valeur < min)
        {
            min = courant->valeur;
        }   
        courant = courant->suivant;
    }
    return min;
}

double moyenne (tete* liste)
{
    int n = compterensemble (liste);
    if (n == 0)                         
    {
        return 0;
    }
    return (double) somme (liste) / n;  
}

int occurrences (tete* liste, int nbcompter)
{
    int compteur = 0;
    ensemble* courant = liste->premier;
    while (courant != NULL)
    {
        if (courant->valeur == nbcompter)
        {
            compteur++;
        }
        courant = courant->suivant;
    }
    return compteur;
}

int egales (tete* liste1, tete* liste2)
{
    ensemble* a = liste1->premier;
    ensemble* b = liste2->premier;

    while (a != NULL && b != NULL)
    {
        if (a->valeur != b->valeur)
        {
            return 0;
        }                          
        a = a->suivant;
        b = b->suivant;
    }
    return (a == NULL && b == NULL);           
}