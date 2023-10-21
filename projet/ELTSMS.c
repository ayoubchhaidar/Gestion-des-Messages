#include"SMSPRIM.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include"LSTSMSSDD.h"
ELEMENT_SMS elementCreersms(void) {
ELEMENT_SMS L;

L = (ELEMENT_SMS) malloc(sizeof(SMS));

if(!L){
    printf("impossible ! \n");
}else{
L->taille = 0;
return L;
}
}
void elementDetruiresms(ELEMENT_SMS elt){
free (elt);
}
void elementLiresms(ELEMENT_SMS* elt,int ts) {

(*elt)->texte = (char * )malloc(sizeof(char)*ts);
}


void elementAffichersms(ELEMENT_SMS elt){

printf("%s",(elt)->texte);

}

void elementAffectersms(ELEMENT_SMS* e1, ELEMENT_SMS e2) {
*e1 = e2 ;
}

int elementCopiersms(ELEMENT_SMS *e1, ELEMENT_SMS e2) {
strcpy((*e1)->texte,e2->texte);}

int elementComparersms(ELEMENT_SMS e1, ELEMENT_SMS e2) {

return strcmp(e1->texte,e2->texte) ;
}
