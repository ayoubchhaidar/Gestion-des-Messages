#include"LSTMSGPRIM.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


NOEUD_MSG noeudCreer(ELEMENT_MSG e){

NOEUD_MSG n;

n =(NOEUD_MSG)malloc(sizeof(structNoeudMSG));
if(!n)
printf ("\nPlus d'espace");
else
{
elementAffecterMSG(&n->info, e);
n->suivant = NULL;
n->precedent = NULL;
}
return n;
}

void noeudDetruireMSG(NOEUD_MSG n){
elementDetruireMSG(n->info);
free(n);
}


int estVideMSG(LISTE_MSG L) {
return (L->lg == 0);
}

int estSatureeMSG(LISTE_MSG L) {
NOEUD_MSG temp;
int saturee = 1;
temp = (NOEUD_MSG) malloc ( sizeof ( structNoeudMSG ) );
if(temp != NULL) {
saturee = 0;
free(temp);
}
return saturee;
}

int listeTailleMSG(LISTE_MSG L) {
return (L->lg);
}

int insererMSG(LISTE_MSG L, ELEMENT_MSG e, int pos){
int succee=1;
int i;
NOEUD_MSG n, p, q;
if (estSatureeMSG(L)){

printf ("\nListe saturée");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;

}
else {

n=noeudCreer(e);

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



int supprimerMSG (LISTE_MSG L, int pos ){

int i;
int succee=1;
NOEUD_MSG p, q;
if (estVideMSG(L)) {

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
noeudDetruireMSG(q);
(L->lg)--;

}
}
return succee;
}


LISTE_MSG listeCreerMSG(void) {
LISTE_MSG L;
L=(LISTE_MSG)malloc(sizeof(laStructMSG));
if (! L)
printf("\nProblème de mémoire");
else {
L->lg = 0;
L->tete = NULL;
}
return(L);
}




void listeDetruireMSG(LISTE_MSG L){
int i;
NOEUD_MSG p, q;
q= L->tete;
for(i = 1;i <= L->lg; i++)
{
p=q;
q=q->suivant;
noeudDetruireMSG(p);
}
free(L);
}

void listeAfficherMSG(LISTE_MSG L){
int i=1,k=1;
NOEUD_MSG p;
p= L->tete;

for(i=1;i<=L->lg; i++) {
       printf("\n\t-------------\n");
printf("(%i)",k);elementAfficherMSG(p->info);
k++;
p= p->suivant;
}
}
LISTE_MSG listeCopierMSG(LISTE_MSG L){
LISTE_MSG LR = listeCreerMSG();
int k=L->lg,i;
ELEMENT_MSG elt;
for(i=1;i<=L->lg;i++) {
elt=elementCreerMSG();
elementCopierMSG(&elt, recupererMSG(L,k));
printf("%i",i);
insererMSG(LR,elt, i);
k--;}
return LR;
}


ELEMENT_MSG recupererMSG(LISTE_MSG L, int pos) {

ELEMENT_MSG elt= elementCreerMSG();
int i;
NOEUD_MSG p;
if (estVideMSG(L))
printf ("\nListe vide");
else {
if ((pos < 1) || (pos > L->lg))
printf ("\nPosition invalide");

else {

p= L->tete;
for (i=1; i<pos; i++)
p = p->suivant;

elementAffecterMSG(&elt,p->info);
}

}
return(elt);
}



