#ifndef LSTSMSPRIM_H_INCLUDED
#define LSTSMSPRIM_H_INCLUDED
#include"LSTSMSSDD.h"
LISTE_SMS listeCreersms(void);
void listeDetruiresms(LISTE_SMS);
int estVidesms(LISTE_SMS);
int estSatureesms(LISTE_SMS);
int listeTaillesms(LISTE_SMS);
ELEMENT_SMS recuperersms(LISTE_SMS, int);
int inserersms(LISTE_SMS, ELEMENT_SMS,int);
int supprimersms(LISTE_SMS, int);
void listeAffichersms(LISTE_SMS);
LISTE_SMS listeCopiersms(LISTE_SMS);
int listeComparersms(LISTE_SMS, LISTE_SMS);


#endif // LSTSMSPRIM_H_INCLUDED
