#ifndef PILEPTR_H_INCLUDED
#define PILEPTR_H_INCLUDED
#define LongMax 100
typedef struct structNoeud_PILE {
char hoba[LongMax];
int occ;
struct structNoeud_PILE * suivant;
} structNoeud, * NOEUD_PILE;

typedef struct {
NOEUD_PILE tete;
} laStruct,*Pile;


#endif // PILEPTR_H_INCLUDED
