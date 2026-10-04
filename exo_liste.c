#include <stdio.h>
#include <stdlib.h>
 
typedef struct ensemble 
{
    int valeur;
    struct ensemble* suivant;
}ensemble;
 
typedef struct tete
{
    struct ensemble* premier;
}tete;
 
ensemble* creerensemble (int value);
tete* insererentete (tete* liste, int value);
tete* insereralafin (tete* liste, int value);
int rechercher (tete* liste, int nbrechercher);
void afficherensemble (tete* liste);
int compterensemble (tete* liste);
tete* supprimer  (tete* liste, int nbsupprimer);
void libererliste (tete* liste);
int somme (tete* liste);
int maximum (tete* liste); 
tete* inserertrie (tete* liste, int value);
tete* inverser (tete* liste);
tete* fusionner (tete* liste1, tete* liste2);

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
 
    /* Insertions */
    maliste = insererentete (maliste, 10);
    maliste = insererentete (maliste, 5);
    maliste = insereralafin (maliste, 20);
    maliste = insereralafin (maliste, 30);
    
    /* Affichage et comptage */
    printf ("======LISTE====== : \n");
    afficherensemble (maliste);
    printf ("Nombre d'elements : %d\n", compterensemble (maliste));
    printf ("La somme des elements: %d\n", somme (maliste));
    printf ("Le nombre maximal est: %d\n", maximum (maliste));
    maliste = inserertrie (maliste, 25);
    maliste = inserertrie(maliste, 15);
    printf ("Nouveauliste : ");
    afficherensemble (maliste);
    printf ("Nouveau nombre d'elements : %d\n", compterensemble (maliste));
    printf ("Element apres inversion: ");
    maliste = inverser (maliste);
    afficherensemble(maliste);

 
    /* Recherche : valeur saisie au clavier */
    printf ("\nEntrer la valeur a rechercher: ");
    scanf ("%d", &valeur);
    if (rechercher (maliste, valeur) == 1)
        printf ("La valeur %d est presente dans la liste\n", valeur);
    else
        printf ("La valeur %d n'existe pas dans la liste\n", valeur);
 
    /* Suppression : valeur saisie au clavier */
    printf ("\nEntrer la valeur a supprimer: ");
    scanf ("%d", &valeur);
    if (rechercher (maliste, valeur) == 1)
    {
        maliste = supprimer (maliste, valeur);
        printf ("La valeur %d supprimee avec succes\n", valeur);
    }
    else
        printf ("La valeur %d n'existe pas dans la liste\n", valeur);
 
    printf ("Liste finale : ");
    afficherensemble (maliste);
    printf ("Nombre d'elements : %d\n", compterensemble (maliste));
    /* Liberation de la memoire */
    libererliste (maliste);
    maliste = NULL;

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
 
    printf ("\nApres fusion : ");
    afficherensemble (resultat);
    printf ("Nombre d'elements : %d\n", compterensemble (resultat));
 
    libererliste (resultat);
    libererliste (liste2);  

    return 0;
}
 
 
 
