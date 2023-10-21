#ifndef LSTSMS_H_INCLUDED
#define LSTSMS_H_INCLUDED
#include "SMSPRIM.h"
#define LongMax 9
typedef struct
{
ELEMENT_SMS elements[LongMax];
int lg;
}laStructSMS,*LISTE_SMS;


#endif // LSTSMS_H_INCLUDED
