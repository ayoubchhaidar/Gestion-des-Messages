#include"CONPRIM.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
ELEMENT_CONT elementCreerCON (void) {
ELEMENT_CONT L;
L = (ELEMENT_CONT) malloc(sizeof(CONTACT));
return L;
}
void elementDetruireCON (ELEMENT_CONT elt) {
free (elt);
}
void elementLireCON (ELEMENT_CONT* elt) {
int x=0,num=1,choix;
do{
printf("\n1 pour ajouter un contact 2 pour importer un ");
scanf("%i",&choix);
}while((choix!=1)&&(choix!=2));
if(choix==1){
printf(" \nDonnez un nom svp :") ;
fflush(stdin);
gets((*elt)->nom);
do{
        num=1;
printf(" \nDonnez un numero svp :") ;
gets((*elt)->numero);
for(x=0;x<8;x++){
    if(((*elt)->numero[x]!='0')&&((*elt)->numero[x]!='1')&&((*elt)->numero[x]!='2')&&((*elt)->numero[x]!='3')&&((*elt)->numero[x]!='4')&&((*elt)->numero[x]!='5')&&((*elt)->numero[x]!='6')&&((*elt)->numero[x]!='7')&&((*elt)->numero[x]!='8')&&((*elt)->numero[x]!='9'))
    num=0;}

}while(((*elt)->numero[0]!='9')&&((*elt)->numero[0]!='2')&&((*elt)->numero[0]!='5')||(strlen((*elt)->numero)!=8)||(num==0));

do{
printf(" \nDonnez un email :") ;
gets((*elt)->email);
}while((strstr((*elt)->email,"@gmail.com")==NULL)&&(strstr((*elt)->email,"@yahoo.com")==NULL)&&(strstr((*elt)->email,"@outlook.com")==NULL)&&(strstr((*elt)->email,"@hotmail.com")==NULL));
}
else
{
    FILE * text=fopen("nomcon.txt","r");
 if (text==NULL){
    printf("j peux pas aman");
exit(1);}
while(fgets((*elt)->nom,sizeof((*elt)->nom),text));
printf("%s\n",(*elt)->nom);


FILE * text0=fopen("numcon.txt","r");
 if (text0==NULL){
    printf("j peux pas aman");
exit(1);}

while(fgets((*elt)->numero,sizeof((*elt)->numero),text0));
printf("%s\n",(*elt)->numero);


FILE * text1=fopen("mailcon.txt","r");
 if (text1==NULL){
    printf("j peux pas aman");
exit(1);}

while(fgets((*elt)->email,sizeof((*elt)->email),text1));
printf("%s\n",(*elt)->email);

}
}

void elementAfficherCON(ELEMENT_CONT elt) {

printf("nom = %s , numero = %s , email= %s ",elt->nom, elt->numero, elt->email);
}

void elementAffecterCON(ELEMENT_CONT* e1, ELEMENT_CONT e2) {
*e1 = e2 ;
}

int elementCopierCON(ELEMENT_CONT *e1, ELEMENT_CONT e2) {
strcpy((*e1)->nom, e2->nom);
strcpy((*e1)->numero, e2->numero);
strcpy((*e1)->email , e2->email);
}


int elementComparerCON(ELEMENT_CONT e1, ELEMENT_CONT e2) {
return strcpy(e1->numero,e2->numero) ;
}


