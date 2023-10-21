#ifndef SMSPRIM_H_INCLUDED
#define SMSPRIM_H_INCLUDED
#include"SMSSDD.h"

void elementLiresms(ELEMENT_SMS* ,int );

void elementAffectersms(ELEMENT_SMS *, ELEMENT_SMS );

int elementCopiersms(ELEMENT_SMS  *, ELEMENT_SMS ) ;

int elementComparersms(ELEMENT_SMS , ELEMENT_SMS );

ELEMENT_SMS elementCreersms(void) ;

void elementDetruiresms (ELEMENT_SMS );

void elementAffichersms(ELEMENT_SMS );


#endif // SMSPRIM_H_INCLUDED
