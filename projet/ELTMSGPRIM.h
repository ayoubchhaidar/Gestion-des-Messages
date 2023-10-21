#ifndef ELTMSGPRIM_H_INCLUDED
#define ELTMSGPRIM_H_INCLUDED
#include"MSGSDD.h"
void elementLireMSG(ELEMENT_MSG *);

void elementAffecterMSG(ELEMENT_MSG *, ELEMENT_MSG );

int elementCopierMSG(ELEMENT_MSG  *,ELEMENT_MSG) ;

int elementComparerMSG(ELEMENT_MSG , ELEMENT_MSG );

ELEMENT_SMS elementCreerMSG(void) ;

void elementDetruireMSG(ELEMENT_MSG );

void elementAfficherMSG(ELEMENT_MSG);



#endif // ELTMSGPRIM_H_INCLUDED
