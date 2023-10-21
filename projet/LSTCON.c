#include"LSTCON.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

NOEUD_CONT noeudCreerCON(ELEMENT_CONT e){
NOEUD_CONT n;
n =(NOEUD_CONT)malloc(sizeof(structNoeudCONT));
if(!n)
printf ("\nPlus d'espace");
else
{
elementAffecterCON(&n->info, e);
n->suivant = NULL;
}
return n;
}

void noeudDetruireCON(NOEUD_CONT n){
elementDetruireCON(n->info);
free(n);
}


int estVideCON(LISTE_CONT L) {
return (L->lg == 0);
}

int estSatureeCON(LISTE_CONT L) {
NOEUD_CONT temp;
int saturee = 1;
temp = (NOEUD_CONT) malloc ( sizeof (structNoeudCONT) );
if(temp != NULL) {
saturee = 0;
free(temp);
}
return saturee;
}

int listeTailleCON(LISTE_CONT L) {
return (L->lg);
}






int insererCON(LISTE_CONT L, ELEMENT_CONT e, int pos){
int succee=1;
int i;
NOEUD_CONT n, p, q;

if (estSatureeCON(L)){

printf ("\nListe saturée");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;

}
else {

n=noeudCreerCON (e);

if (pos == 1)

{
n->suivant=L->tete;
L->tete = n;
}
else
{
q= L->tete;
for (i=1; i<pos; i++) {

p = q;
q = q->suivant;

}
p->suivant=n;
n->suivant=q;
}
(L->lg)++;
}
}
return succee;
}

int supprimerCON(LISTE_CONT L, int pos ){

int i;
int succee=1;
NOEUD_CONT p, q;
if (estVideCON(L)) {

printf ("\nListe vide");
succee=0;
}
else {

if ((pos < 1) || (pos > L->lg))

{
printf ("\nPosition invalide");
succee=0;
}

else
{
q = L->tete;
if (pos == 1)
L->tete=L->tete->suivant;


else {
for (i=1; i<pos; i++) {
p = q;
q = q->suivant;
}
p->suivant=q->suivant;
}
noeudDetruireCON(q);
(L->lg)--;

}
}
return succee;
}


ELEMENT_CONT recupererCON(LISTE_CONT L, int pos) {
ELEMENT_CONT elt= elementCreerCON();
int i;
NOEUD_CONT p;
if (estVideCON(L))
printf ("\nListe vide");
else {
if ((pos < 1) || (pos > L->lg))
printf ("\nPosition invalide");

else {

p= L->tete;
for (i=1; i<pos; i++)
p = p->suivant;

elementAffecterCON(&elt,p->info);
}

}
return(elt);
}
LISTE_CONT listeCreerCON(void) {
LISTE_CONT L;
L=(LISTE_CONT)malloc(sizeof(laStructCONT));
if (! L)
printf("\nProblème de mémoire");
else {
L->lg = 0;
L->tete = NULL;
}
return(L);
}

void listeDetruireCON(LISTE_CONT L){
int i;
NOEUD_CONT p, q;
q= L->tete;
for(i = 1;i <= L->lg; i++)
{
p=q;
q=q->suivant;
noeudDetruireCON(p);
}
free(L);
}

void listeAfficherCON(LISTE_CONT L){
int i=1,k=1;
NOEUD_CONT p;
p= L->tete;
if(estVideCON(L))
    printf("repertoire vide\n");
else
for(i = 1;i <= L->lg; i++) {
printf("\n(%i)",k);elementAfficherCON(p->info);k++;
p= p->suivant;
}
}

LISTE_CONT listeCopierCON(LISTE_CONT L){
LISTE_CONT LR = listeCreerCON();
int i;
ELEMENT_CONT elt;
for(i = 1;i <= L->lg; i++) {
elt=elementCreerCON();
elementCopierCON(&elt, recupererCON(L,i));
insererCON(LR,elt, i);
}
return LR;
}

int listeComparerCON(LISTE_CONT L1,LISTE_CONT L2 )
{
int test= 1;
int i=1;
if (listeTailleCON(L1) != listeTailleCON(L2)) test= 0;
while ((i<=listeTailleCON(L1)) && (test)) {
if
(elementComparerCON(recupererCON(L1,i),recupererCON(L2,i))!=0)
test=0;
i++;
}
return test;
}
