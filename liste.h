#ifndef LISTE_H
#define LISTE_H

typedef struct ensemble
{
    int valeur;
    struct ensemble* suivant;
} ensemble;

typedef struct tete
{
    struct ensemble* premier;
} tete;

ensemble* creerensemble (int value);
void afficherensemble (tete* liste);
int compterensemble (tete* liste);
void libererliste (tete* liste);

#endif
