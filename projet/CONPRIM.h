#ifndef CONPRIM_H_INCLUDED
#define CONPRIM_H_INCLUDED
#include"ELTCONSDD.h"

void elementLireCON(ELEMENT_CONT *);

void elementAffecterCON (ELEMENT_CONT *, ELEMENT_CONT );

int elementCopierCON(ELEMENT_CONT  *, ELEMENT_CONT) ;

int elementComparerCON(ELEMENT_CONT , ELEMENT_CONT );

ELEMENT_CONT elementCreerCON(void) ;

void elementDetruireCON (ELEMENT_CONT );

void elementAfficherCON(ELEMENT_CONT );


#endif
