#ifndef LSTPRIMCON_H_INCLUDED
#define LSTPRIMCON_H_INCLUDED

#include"LSTCONSDD.h"
LISTE_CONT listeCreerCON(void);
void listeDetruireCON(LISTE_CONT);
int estVideCON(LISTE_CONT);
int estSatureeCON(LISTE_CONT);
int listeTailleCON(LISTE_CONT);
ELEMENT_CONT recupererCON(LISTE_CONT, int);
int insererCON(LISTE_CONT, ELEMENT_CONT,int);
int supprimerCON(LISTE_CONT, int);
void listeAfficherCON(LISTE_CONT);
LISTE_CONT listeCopierCON(LISTE_CONT);
int listeComparerCON(LISTE_CONT, LISTE_CONT);
NOEUD_CONT noeudCreerCON(ELEMENT_CONT);
void noeudDetruireCON(NOEUD_CONT );



#endif // LSTPRIMCON_H_INCLUDED
