#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "PILEPRIM.h"
NOEUD_PILE NoeudCreerPILE(char *e) {
NOEUD_PILE n;
n=(NOEUD_PILE) malloc(sizeof(structNoeud));
if(!n)
printf ("\n Plus d'espace");
else {
strcpy(n->hoba, e);
n->suivant = NULL;
n->occ=0;
}
return n;
}
void NoeudDetruirePILE(NOEUD_PILE n){
free(n);
}
Pile PileCreerPILE(void) {

Pile P;
P = (Pile) malloc(sizeof(laStruct));
if(!P)

printf(" \nProblème de mémoire") ;

else

P->tete = NULL;


return(P);

}
void PileDetruirePILE(Pile P){
NOEUD_PILE n = P->tete;
while (n!= NULL)

{
P->tete=n->suivant;
NoeudDetruirePILE(n);
n = P->tete;
}
free(P);
}

int EstVidePILE(Pile P) {
return (P->tete == NULL);
}

int EstSatureePILE(Pile P) {
NOEUD_PILE temp;
int saturee = 1;
temp = (NOEUD_PILE) malloc ( sizeof ( structNoeud ) );
if(temp != NULL) {
saturee = 0;
free(temp);
}
return saturee;
}
void PileAfficherPILE(Pile P) {
NOEUD_PILE n;
n= P->tete;
while (n != NULL)
{
    printf("\n %s",n->hoba,n->occ);
      printf("\n %i",n->occ);
n = n->suivant;}
}

int PileTaillePILE(Pile P) {
int taille = 0;
NOEUD_PILE n;
n = P->tete;
while (n != NULL)
{ taille++;
n = n->suivant ;}
return(taille);
}


int EmpilerPILE(Pile P, char *e,int oc) {
int succes=1,ps,pasmot=1;
NOEUD_PILE n;

 for(ps=0;ps<strlen(e);ps++){
   if(((e[ps]>='a')&&(e[ps]<='z'))||((e[ps]>='A')&&(e[ps]<='Z')))
   pasmot=0;}


if (EstSatureePILE(P)){

printf ("\n Pile saturée");
succes=0;}



else if (pasmot==0)
{

n=NoeudCreerPILE(e);
n->suivant = P->tete;
P->tete = n;
P->tete->occ=oc;

}

return(succes);
}

NOEUD_PILE DepilerPILE(Pile P) {
NOEUD_PILE elt=NoeudCreerPILE(P->tete);

if (EstVidePILE(P)) {

printf ("\n Pile vide");
}

else {
strcpy(elt->hoba,P->tete->hoba);
P->tete= P->tete->suivant;
}
return (elt);}




NOEUD_PILE SommetPILE(Pile P) {

NOEUD_PILE elt;
if (EstVidePILE(P))
printf (" \n Pile vide");
else{

elt=NoeudCreerPILE(P->tete);
}
return(elt);
}

Pile PileCopierPILE(Pile P){

Pile PR = PileCreerPILE();

char *elt;
NOEUD_PILE n1, n2, n3;
n1 = P->tete;
while (n1 != NULL) {


strcpy(elt, n1->hoba);
n2 = NoeudCreerPILE(elt);
if (n1 == P->tete)

{PR->tete = n2;
n3 = n2;}

else

{ n3->suivant = n2;
n3 = n2;}
n1 = n1->suivant;
}
return PR;
}
int PileComparerPILE(Pile P1, Pile P2 )
{
int test= 1;
NOEUD_PILE n1 = P1->tete;
NOEUD_PILE n2 = P2->tete;
if (PileTaillePILE(P1) != PileTaillePILE(P2)) test= 0;

while ((n1!=NULL) && (test)) {
if (strcmp(n1->hoba, n2->hoba)!=0)
test=0;
else
{n1 = n1->suivant;
n2 = n2->suivant;
}
}
return test;
}


