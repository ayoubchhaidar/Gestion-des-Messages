#ifndef PILEPRIM_H_INCLUDED
#define PILEPRIM_H_INCLUDED
#include "PILESDD.h"
Pile PileCreerPILE(void);
void PileDetruirePILE(Pile P);
int EstVidePILE(Pile);
int EstSatureePILE(Pile);
int PileTaillePILE(Pile);
NOEUD_PILE SommetPILE(Pile);
int EmpilerPILE(Pile, char*,int oc);
NOEUD_PILE DepilerPILE(Pile);
void PileAfficherPILE(Pile);
Pile PileCopierPILE(Pile);
int PileComparerPILE(Pile, Pile);
NOEUD_PILE NoeudCreerPILE(char *e);
void NoeudDetruirePILE(NOEUD_PILE n);


#endif // PILEPRIM_H_INCLUDED
