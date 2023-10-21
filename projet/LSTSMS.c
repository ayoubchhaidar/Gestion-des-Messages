#include"LSTSMSPRIM.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include"SMSPRIM.h"
#include <string.h>
LISTE_SMS listeCreersms(void) {
LISTE_SMS L;
L = (LISTE_SMS) malloc(sizeof(laStructSMS));
if(!L) {
printf(" \nProblème de mémoire") ;
exit(0) ;
}
else
{
  L->lg = 0;

return(L);
}

}


ELEMENT_SMS recuperersms(LISTE_SMS L, int pos) {
ELEMENT_SMS elt= elementCreersms();
if (estVidesms(L))
printf ("\nListe vide");
else {
if ((pos < 1) || (pos > L->lg))
printf("\nPosition invalide");
else
elt=(L->elements[pos]);
}
return(elt);
}








void listeDetruiresms(LISTE_SMS L){
int i;
for(i = 1;i <= L->lg; i++)

elementDetruiresms(L->elements[i]);

free(L);
}







int inserersms (LISTE_SMS L, ELEMENT_SMS e, int pos) {
int i;
int succee=1;

if (estSatureesms(L)){

printf ("\nListe saturée");
succee=0;}

else {

if ((pos < 1) || (pos > L->lg + 1)) {
printf ("\nPosition invalide");
succee=0;
}
else {

for(i = L->lg; i>= pos; i--)

elementAffectersms(&L->elements[i+1],

L->elements[i]);
elementAffectersms(&L->elements[pos], e);
(L->lg)++;
}

}
printf("bow");
return(succee);
}


void listeAffichersms(LISTE_SMS L){
int i;
for(i = 1; i <= L->lg; i++)

elementAffichersms(L->elements[i]);

}
int estVidesms(LISTE_SMS L){
return (L->lg == 0);
}

int estSatureesms(LISTE_SMS L) {
return (L->lg == LongMax);
}

int listeTaillesms(LISTE_SMS L) {
return (L->lg);
}

