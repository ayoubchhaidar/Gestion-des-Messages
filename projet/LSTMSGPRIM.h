#ifndef LSTMSGPRIM_H_INCLUDED
#define LSTMSGPRIM_H_INCLUDED
#include"LSTMSGSDD.h"

LISTE_MSG listeCreerMSG(void);
void listeDetruireMSG(LISTE_MSG);
int estVideMSG(LISTE_MSG);
int estSatureeMSG(LISTE_MSG);
int listeTailleMSG(LISTE_MSG);
ELEMENT_MSG recupererMSG(LISTE_MSG, int);
int insererMSG(LISTE_MSG, ELEMENT_MSG,int);
int supprimerMSG(LISTE_MSG, int);
void listeAfficherMSG(LISTE_MSG);
LISTE_MSG listeCopierMSG(LISTE_MSG);
int listeComparerMSG(LISTE_MSG, LISTE_MSG);
NOEUD_MSG noeudCreer(ELEMENT);
void noeudDetruire(NOEUD );

#endif // LSTMSGPRIM_H_INCLUDED
