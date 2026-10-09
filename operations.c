#include <stdlib.h>
#include "liste.h"
#include "operations.h"

tete* inverser (tete* liste)
{
    ensemble* courant = liste->premier;
    ensemble* suivant = NULL;
    ensemble* precedent = NULL;

    while (courant != NULL)
    {
        suivant = courant->suivant;
        courant->suivant = precedent;
        precedent = courant;
        courant = suivant;
    }
    liste->premier = precedent;
    return liste;
}

tete* fusionner (tete* liste1, tete* liste2)
{
    ensemble* A = liste1->premier;
    ensemble* B = liste2->premier;
    ensemble* debut = NULL;
    ensemble* fin = NULL;
    ensemble* choisi = NULL;
    ensemble* reste = NULL;

    while (A != NULL && B != NULL)
    {
        if (A->valeur <= B->valeur)
        {
            choisi = A;
            A = A->suivant;
        }
        else 
        {
            choisi = B;
            B = B->suivant;
        }
    
    if (fin == NULL)
    {
        debut = choisi;
    }
    else
    {
        fin->suivant = choisi;
    }
    fin = choisi;
    }
    if (A != NULL)
    {
        reste = A;
    }
    else 
    {
        reste = B;
    }
    if (fin == NULL)
    {
        debut = reste;
    }
    else 
    {
        fin->suivant = reste;
    }
    liste1->premier = debut;
    liste2->premier = NULL;
    return liste1;
}

tete* concatener (tete* liste1, tete* liste2)
{
    if (liste1 == liste2 || liste2->premier == NULL)
    {
        return liste1;                         
    }

    if (liste1->premier == NULL)
    {
        liste1->premier = liste2->premier;     
    }
    else
    {
        ensemble* courant = liste1->premier;
        while (courant->suivant != NULL)
        {       /* aller au dernier maillon */
            courant = courant->suivant;
            courant->suivant = liste2->premier;   
        }
    }
    liste2->premier = NULL;                    
    return liste1;
}

void separer (tete* liste, tete* pairs, tete* impairs)
{
    ensemble* courant = liste->premier;
    ensemble* finpairs = NULL;
    ensemble* finimpairs = NULL;

    while (courant != NULL)
    {
        ensemble* suivant = courant->suivant;  
        courant->suivant = NULL;                

        if (courant->valeur % 2 == 0)
        {
            if (finpairs == NULL)
            {
                pairs->premier = courant;
            }
            else
            {
                finpairs->suivant = courant;
                finpairs = courant;
            }
        }
        else
        {
            if (finimpairs == NULL)
            {
                impairs->premier = courant;
            }
            else
            {
                finimpairs->suivant = courant;
                finimpairs = courant;
            }
        }
        courant = suivant;
    }
    liste->premier = NULL;                     
}

void rotation (tete* liste, int k)
{
    int n = compterensemble (liste);
    int i;
    if (n < 2)
    {
        return;
    }
    k = k % n;                          
    if (k < 0)
    {
        k = k + n;
    }
    if (k == 0)
    {
        return;
    }
    ensemble* courant = liste->premier;
    for (i = 1; i < k; i++)        
    {
        courant = courant->suivant;
    }

    ensemble* nouveaupremier = courant->suivant;
    courant->suivant = NULL;            

    ensemble* fin = nouveaupremier;
    while (fin->suivant != NULL)
    {
        fin = fin->suivant;
    }        
    fin->suivant = liste->premier;      
    liste->premier = nouveaupremier;
}