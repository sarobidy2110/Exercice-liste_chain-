#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "insertion.h"
#include "suppression.h"
#include "analyse.h"
#include "operations.h"

int main (void)
{
    tete* maliste = malloc (sizeof (tete));
    int valeur;
 
    if (maliste == NULL)
    {
        printf ("Erreur d'allocation memoire!\n");
        return 1;
    }
    maliste->premier = NULL;
 
    maliste = insererentete (maliste, 10);
    maliste = insererentete (maliste, 5);
    maliste = insereralafin (maliste, 20);
    maliste = insereralafin (maliste, 30);

    printf ("======LISTE====== : \n");
    afficherensemble (maliste);
    printf ("Nombre d'elements : N=[%d]\n", compterensemble (maliste));
    printf ("\n");

    preintf ("Nouvelle insertion de 15 sur la 2e position\n");
    if (insererposition (maliste, 2, 15) == 1)
    {
    printf ("Insertion reussie\n");
    }
    else
    {
        printf ("Indice invalide\n");
    }
    afficherensemble (maliste);

    printf ("La somme des elements: SOMME=[%d]\n", somme (maliste));
    printf ("\n");

    printf ("Le nombre maximal est: MAX=[%d]\n", maximum (maliste));
    printf ("\n");

    maliste = inserertrie (maliste, 25);
    maliste = inserertrie(maliste, 15);
    printf ("Nouveauliste apres insertion de 25 et 15:\n");
    afficherensemble (maliste);
    printf ("Nouveau nombre d'elements : N=[%d]\n", compterensemble (maliste));
    printf ("\n");



    printf ("Element apres inversion: ");
    maliste = inverser (maliste);
    afficherensemble(maliste);
    printf ("\n");

    printf ("Entrer la valeur a rechercher: ");
    scanf ("%d", &valeur);
    if (rechercher (maliste, valeur) == 1)
    {
        printf ("La valeur %d est presente dans la liste\n", valeur);
    }
    else
    {
        printf ("La valeur %d n'existe pas dans la liste\n", valeur);
    }
    printf ("\n");

    printf ("\nEntrer la valeur a supprimer: ");
    scanf ("%d", &valeur);
    if (rechercher (maliste, valeur) == 1)
    {
        maliste = supprimer (maliste, valeur);
        printf ("La valeur %d supprimee avec succes\n", valeur);
    }
    else
    {
        printf ("La valeur %d n'existe pas dans la liste\n", valeur);
    }
    printf ("Liste finale : ");
    afficherensemble (maliste);
    printf ("Nombre d'elements : %d\n", compterensemble (maliste));

    printf ("Liste apres suppression en tete et a la fin:");
    maliste = supprimerentete (maliste);
    maliste = supprimeralafin (maliste);
    afficherensemble (maliste);

    /*int v;
    if (obtenir (maliste, 3, &v) == 1)
    printf ("Element en position 3 : %d\n", v);
    else
    printf ("Indice invalide\n");*/

    libererliste (maliste);
    maliste = NULL;
    printf ("\n");
    printf ("\n");
    printf ("==================================================================================================================\n");

    tete* liste1 = malloc (sizeof (tete));
    tete* liste2 = malloc (sizeof (tete));
    if (liste1 == NULL || liste2 == NULL)
    {
        printf ("Erreur d'allocation memoire!\n");
        return 1;
    }
    liste1->premier = NULL;
    liste2->premier = NULL;
 
    liste1 = insereralafin (liste1, 1);
    liste1 = insereralafin (liste1, 4);
    liste1 = insereralafin (liste1, 7);
 
    liste2 = insereralafin (liste2, 2);
    liste2 = insereralafin (liste2, 3);
    liste2 = insereralafin (liste2, 9);
 
    printf ("Le premier Liste : ");
    afficherensemble (liste1);
    printf ("Le seconde Liste : ");
    afficherensemble (liste2);
 
    tete* resultat = fusionner (liste1, liste2);
 
    printf ("\n");
    printf ("\nApres fusion : ");
    afficherensemble (resultat);
    printf ("Nombre d'elements : %d\n", compterensemble (resultat));
 
    libererliste (resultat);
    libererliste (liste2);  

    return 0;
}
