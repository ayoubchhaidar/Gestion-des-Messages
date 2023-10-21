#include"ELTMSGPRIM.h"
#include"LSTSMSPRIM.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <time.h>

ELEMENT_SMS elementCreerMSG(void){
ELEMENT_MSG M;
M = (ELEMENT_MSG) malloc(sizeof(MESSAGE));
if(!M)
     printf("impossible ! \n");
else
M->recpeteur[0]='\0';
M->prix=0;
return M;

}




void elementLireMSG(ELEMENT_MSG *e){
   char ch[1280];
   int ce,k=0,i=0,cs=0,j=0,nbsms,choix;
do{
printf("\ncontact existant?(1=oui/0=non)");
scanf("%i",&ce);}while((ce!=1)&&(ce!=0));
if(ce==0){
    do{
printf("\nnum recpteur:");
gets(&(*e)->recpeteur);
}while(((*e)->recpeteur[0]!='9')&&((*e)->recpeteur[0]!='2')&&((*e)->recpeteur[0]!='5')||(strlen((*e)->recpeteur)!=8));}


do{
printf("\n1 pour ecrire 2 pour importer");
   scanf("%i",&choix);
   }while((choix!=1)&&(choix!=2));
if(choix==1){
        do{
fflush(stdin);
fgets(ch,1280,stdin);
if(strlen(ch)>1224){
    system("cls");
printf("\nmessage trop long\ntaper votre message:\n");}
}while(strlen(ch)>=1224);}
else if(choix==2){
        FILE * text=fopen("msg.txt","r");
 if (text==NULL){
    printf("j peux pas aman");
exit(1);}

while(fgets(ch,sizeof(ch),text));
printf("%s\n",ch);}



for(i=0;i<strlen(ch);i++){
    if((ch[i]=='£')||(ch[i]=='$')||(ch[i]=='Π')||(ch[i]=='Θ')||(ch[i]=='¥')||(ch[i]=='É')||(ch[i]=='ù')||(ch[i]=='ì')||(ch[i]=='ò')||(ch[i]=='Ç')||(ch[i]=='Ø')||(ch[i]=='Å')||(ch[i]=='å')||(ch[i]=='ø')||(ch[i]=='Δ')||(ch[i]=='Φ')||(ch[i]=='Γ')||(ch[i]=='Ξ')||(ch[i]=='Ω')||(ch[i]=='€')||(ch[i]=='Æ')||(ch[i]=='æ')||(ch[i]=='ß')||(ch[i]=='%'))
        cs=1;

   }





   if(cs==0){
if(strlen(ch)>0)
    nbsms=1;
    if(strlen(ch)>160)
    nbsms=2;
    if(strlen(ch)>320)
    nbsms=3;
    if(strlen(ch)>480)
    nbsms=4;
    if(strlen(ch)>640)
    nbsms=5;
    if(strlen(ch)>800)
    nbsms=6;
    if(strlen(ch)>960)
    nbsms=7;
if((strlen(ch)>1120)&&(strlen(ch)<=1280))
    nbsms=8;
    if(choix==1){
      if(nbsms==1)
printf("\t \t\t \t(%i)sms (%i/160)\n",nbsms,(strlen(ch)-1));
else
    printf("\t \t\t \t(%i)sms (%i/%i)\n",nbsms,(strlen(ch)-1),(153*nbsms));
    }
   if(choix==2){
    if(nbsms==1)
printf("\t \t\t \t(%i)sms (%i/160)\n",nbsms,strlen(ch));
else
    printf("\t \t\t \t(%i)sms (%i/%i)\n",nbsms,strlen(ch),(153*nbsms));}
     (*e)->prix=(0.05*nbsms);
   printf("prix:%.3f TND",(*e)->prix);}
else{

if(strlen(ch)>0)
    nbsms=1;
    if(strlen(ch)>70)
    nbsms=2;
    if(strlen(ch)>140)
    nbsms=3;
    if(strlen(ch)>210)
    nbsms=4;
    if(strlen(ch)>280)
    nbsms=5;
    if(strlen(ch)>350)
    nbsms=6;
    if(strlen(ch)>420)
    nbsms=7;
if((strlen(ch)>490)&&(strlen(ch)<=560))
    nbsms=8;
    if(nbsms==1)
printf("\t \t\t \t(%i)sms (%i/70)\n",nbsms,(strlen(ch)-1));
else
    printf("\t \t\t \t(%i)sms (%i/%i)\n",nbsms,(strlen(ch)-1),(67*nbsms));
    (*e)->prix=(0.050*nbsms);
   printf("prix:%.3f TND",(*e)->prix);}
if((nbsms==1)&&(cs==0)){
        ELEMENT_SMS S;
        (*e)->msg=listeCreersms();
   S=elementCreersms();
S->texte =(char * )malloc(sizeof(char)*160);
    for(i=0;i<strlen(ch);i++){
        S->texte[i]=ch[i];
        }S->texte[i]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),S);
(*e)->msg->lg++;
}








if((nbsms==2)&&(cs==0)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*153);
    for(i=0;i<153;i++)
        A->texte[i]=ch[i];
        A->texte[153]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*153);
    for(i=154;i<strlen(ch);i++)
        B->texte[i-154]=ch[i];
        B->texte[strlen(ch)-1]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
}








if((nbsms==3)&&(cs==0)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*153);
    for(i=0;i<153;i++)
        A->texte[i]=ch[i];
        A->texte[153]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*153);
    for(i=154;i<306;i++)
        B->texte[i-154]=ch[i];
        B->texte[306]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*153);
    for(i=307;i<strlen(ch);i++)
        C->texte[i-307]=ch[i];
        C->texte[strlen(ch)]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
}










if((nbsms==4)&&(cs==0)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*153);
    for(i=0;i<153;i++)
        A->texte[i]=ch[i];
        A->texte[153]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*153);
    for(i=154;i<306;i++)
        B->texte[i-154]=ch[i];
        B->texte[306]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*153);
    for(i=307;i<459;i++)
        C->texte[i-307]=ch[i];
        C->texte[459]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*153);
    for(i=460;i<strlen(ch);i++)
        D->texte[i-460]=ch[i];
        D->texte[strlen(ch)]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
}





if((nbsms==5)&&(cs==0)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*153);
    for(i=0;i<153;i++)
        A->texte[i]=ch[i];
        A->texte[153]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*153);
    for(i=154;i<306;i++)
        B->texte[i-154]=ch[i];
        B->texte[306]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*153);
    for(i=307;i<459;i++)
        C->texte[i-307]=ch[i];
        C->texte[459]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*153);
    for(i=460;i<612;i++)
        D->texte[i-460]=ch[i];
        D->texte[612]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
ELEMENT_SMS E;
   E=elementCreersms();
E->texte =(char * )malloc(sizeof(char)*153);
    for(i=613;i<strlen(ch);i++)
        E->texte[i-613]=ch[i];
        E->texte[strlen(ch)]='\0';
(*e)->msg->elements[5]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[5]),E);
(*e)->msg->lg++;
}








if((nbsms==6)&&(cs==0)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*153);
    for(i=0;i<153;i++)
        A->texte[i]=ch[i];
        A->texte[153]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*153);
    for(i=154;i<306;i++)
        B->texte[i-154]=ch[i];
        B->texte[306]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*153);
    for(i=307;i<459;i++)
        C->texte[i-307]=ch[i];
        C->texte[459]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*153);
    for(i=460;i<612;i++)
        D->texte[i-460]=ch[i];
        D->texte[612]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
ELEMENT_SMS E;
   E=elementCreersms();
E->texte =(char * )malloc(sizeof(char)*153);
    for(i=613;i<765;i++)
        E->texte[i-613]=ch[i];
        E->texte[765]='\0';
(*e)->msg->elements[5]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[5]),E);
(*e)->msg->lg++;
ELEMENT_SMS F;
   F=elementCreersms();
F->texte =(char * )malloc(sizeof(char)*153);
    for(i=766;i<strlen(ch);i++)
        F->texte[i-766]=ch[i];
        F->texte[strlen(ch)]='\0';
(*e)->msg->elements[6]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[6]),F);
(*e)->msg->lg++;
}









if((nbsms==7)&&(cs==0)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*153);
    for(i=0;i<153;i++)
        A->texte[i]=ch[i];
        A->texte[153]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*153);
    for(i=154;i<306;i++)
        B->texte[i-154]=ch[i];
        B->texte[306]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*153);
    for(i=307;i<459;i++)
        C->texte[i-307]=ch[i];
        C->texte[459]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*153);
    for(i=460;i<612;i++)
        D->texte[i-460]=ch[i];
        D->texte[612]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
ELEMENT_SMS E;
   E=elementCreersms();
E->texte =(char * )malloc(sizeof(char)*153);
    for(i=613;i<765;i++)
        E->texte[i-613]=ch[i];
        E->texte[765]='\0';
(*e)->msg->elements[5]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[5]),E);
(*e)->msg->lg++;
ELEMENT_SMS F;
   F=elementCreersms();
F->texte =(char * )malloc(sizeof(char)*153);
    for(i=766;i<918;i++)
        F->texte[i-766]=ch[i];
        F->texte[918]='\0';
(*e)->msg->elements[6]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[6]),F);
(*e)->msg->lg++;
ELEMENT_SMS J;
   J=elementCreersms();
J->texte =(char * )malloc(sizeof(char)*153);
    for(i=919;i<strlen(ch);i++)
        J->texte[i-919]=ch[i];
        J->texte[strlen(ch)]='\0';
(*e)->msg->elements[7]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[7]),J);
(*e)->msg->lg++;
}




if((nbsms==8)&&(cs==0)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*153);
    for(i=0;i<153;i++)
        A->texte[i]=ch[i];
        A->texte[153]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*153);
    for(i=154;i<306;i++)
        B->texte[i-154]=ch[i];
        B->texte[306]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*153);
    for(i=307;i<459;i++)
        C->texte[i-307]=ch[i];
        C->texte[459]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*153);
    for(i=460;i<612;i++)
        D->texte[i-460]=ch[i];
        D->texte[612]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
ELEMENT_SMS E;
   E=elementCreersms();
E->texte =(char * )malloc(sizeof(char)*153);
    for(i=613;i<765;i++)
        E->texte[i-613]=ch[i];
        E->texte[765]='\0';
(*e)->msg->elements[5]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[5]),E);
(*e)->msg->lg++;
ELEMENT_SMS F;
   F=elementCreersms();
F->texte =(char * )malloc(sizeof(char)*153);
    for(i=766;i<918;i++)
        F->texte[i-766]=ch[i];
        F->texte[918]='\0';
(*e)->msg->elements[6]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[6]),F);
(*e)->msg->lg++;
ELEMENT_SMS J;
   J=elementCreersms();
J->texte =(char * )malloc(sizeof(char)*153);
    for(i=919;i<1071;i++)
        J->texte[i-919]=ch[i];
        J->texte[1071]='\0';
(*e)->msg->elements[7]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[7]),J);
(*e)->msg->lg++;
ELEMENT_SMS H;
   H=elementCreersms();
H->texte =(char * )malloc(sizeof(char)*153);
    for(i=1072;i<strlen(ch);i++)
        H->texte[i-1072]=ch[i];
        H->texte[strlen(ch)]='\0';
(*e)->msg->elements[8]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[8]),H);
(*e)->msg->lg++;
}




if((nbsms==1)&&(cs==1)){
        ELEMENT_SMS S;
        (*e)->msg=listeCreersms();
   S=elementCreersms();
S->texte =(char * )malloc(sizeof(char)*70);
    for(i=0;i<strlen(ch);i++){
        S->texte[i]=ch[i];
        }S->texte[i]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),S);
(*e)->msg->lg++;
}








if((nbsms==2)&&(cs==1)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*67);
    for(i=0;i<67;i++)
        A->texte[i]=ch[i];
        A->texte[67]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*67);
    for(i=68;i<strlen(ch);i++)
        B->texte[i-68]=ch[i];
        B->texte[strlen(ch)-1]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
}








if((nbsms==3)&&(cs==1)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*67);
    for(i=0;i<67;i++)
        A->texte[i]=ch[i];
        A->texte[67]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*67);
    for(i=68;i<134;i++)
        B->texte[i-68]=ch[i];
        B->texte[134]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*67);
    for(i=135;i<strlen(ch);i++)
        C->texte[i-135]=ch[i];
        C->texte[strlen(ch)]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
}










if((nbsms==4)&&(cs==1)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*67);
    for(i=0;i<67;i++)
        A->texte[i]=ch[i];
        A->texte[67]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*67);
    for(i=68;i<134;i++)
        B->texte[i-68]=ch[i];
        B->texte[134]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*67);
    for(i=135;i<201;i++)
        C->texte[i-135]=ch[i];
        C->texte[201]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*67);
    for(i=202;i<strlen(ch);i++)
        D->texte[i-202]=ch[i];
        D->texte[strlen(ch)]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
}





if((nbsms==5)&&(cs==1)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*67);
    for(i=0;i<67;i++)
        A->texte[i]=ch[i];
        A->texte[67]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*67);
    for(i=68;i<134;i++)
        B->texte[i-68]=ch[i];
        B->texte[134]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*67);
    for(i=135;i<201;i++)
        C->texte[i-135]=ch[i];
        C->texte[201]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*67);
    for(i=202;i<268;i++)
        D->texte[i-202]=ch[i];
        D->texte[268]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
ELEMENT_SMS E;
   E=elementCreersms();
E->texte =(char * )malloc(sizeof(char)*67);
    for(i=269;i<strlen(ch);i++)
        E->texte[i-269]=ch[i];
        E->texte[strlen(ch)]='\0';
(*e)->msg->elements[5]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[5]),E);
(*e)->msg->lg++;
}








if((nbsms==6)&&(cs==1)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*67);
    for(i=0;i<67;i++)
        A->texte[i]=ch[i];
        A->texte[67]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*67);
    for(i=68;i<134;i++)
        B->texte[i-68]=ch[i];
        B->texte[134]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*67);
    for(i=135;i<201;i++)
        C->texte[i-135]=ch[i];
        C->texte[201]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*67);
    for(i=202;i<268;i++)
        D->texte[i-202]=ch[i];
        D->texte[268]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
ELEMENT_SMS E;
   E=elementCreersms();
E->texte =(char * )malloc(sizeof(char)*67);
    for(i=269;i<335;i++)
        E->texte[i-269]=ch[i];
        E->texte[335]='\0';
(*e)->msg->elements[5]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[5]),E);
(*e)->msg->lg++;
ELEMENT_SMS F;
   F=elementCreersms();
F->texte =(char * )malloc(sizeof(char)*67);
    for(i=336;i<strlen(ch);i++)
        F->texte[i-336]=ch[i];
        F->texte[strlen(ch)]='\0';
(*e)->msg->elements[6]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[6]),F);
(*e)->msg->lg++;
}









if((nbsms==7)&&(cs==1)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*67);
    for(i=0;i<67;i++)
        A->texte[i]=ch[i];
        A->texte[67]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*67);
    for(i=68;i<134;i++)
        B->texte[i-68]=ch[i];
        B->texte[134]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*67);
    for(i=135;i<201;i++)
        C->texte[i-135]=ch[i];
        C->texte[201]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*67);
    for(i=202;i<268;i++)
        D->texte[i-202]=ch[i];
        D->texte[268]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
ELEMENT_SMS E;
   E=elementCreersms();
E->texte =(char * )malloc(sizeof(char)*67);
    for(i=269;i<335;i++)
        E->texte[i-269]=ch[i];
        E->texte[335]='\0';
(*e)->msg->elements[5]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[5]),E);
(*e)->msg->lg++;
ELEMENT_SMS F;
   F=elementCreersms();
F->texte =(char * )malloc(sizeof(char)*67);
    for(i=336;i<402;i++)
        F->texte[i-336]=ch[i];
        F->texte[402]='\0';
(*e)->msg->elements[6]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[6]),F);
(*e)->msg->lg++;
ELEMENT_SMS J;
   J=elementCreersms();
J->texte =(char * )malloc(sizeof(char)*67);
    for(i=403;i<strlen(ch);i++)
        J->texte[i-403]=ch[i];
        J->texte[strlen(ch)]='\0';
(*e)->msg->elements[7]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[7]),J);
(*e)->msg->lg++;
}



if((nbsms==7)&&(cs==1)){
      ELEMENT_SMS A;
        (*e)->msg=listeCreersms();
   A=elementCreersms();
A->texte =(char * )malloc(sizeof(char)*67);
    for(i=0;i<67;i++)
        A->texte[i]=ch[i];
        A->texte[67]='\0';
(*e)->msg->elements[1]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[1]),A);
(*e)->msg->lg++;
 ELEMENT_SMS B;
   B=elementCreersms();
B->texte =(char * )malloc(sizeof(char)*67);
    for(i=68;i<134;i++)
        B->texte[i-68]=ch[i];
        B->texte[134]='\0';
(*e)->msg->elements[2]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[2]),B);
(*e)->msg->lg++;
 ELEMENT_SMS C;
   C=elementCreersms();
C->texte =(char * )malloc(sizeof(char)*67);
    for(i=135;i<201;i++)
        C->texte[i-135]=ch[i];
        C->texte[201]='\0';
(*e)->msg->elements[3]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[3]),C);
(*e)->msg->lg++;
ELEMENT_SMS D;
   D=elementCreersms();
D->texte =(char * )malloc(sizeof(char)*67);
    for(i=202;i<268;i++)
        D->texte[i-202]=ch[i];
        D->texte[268]='\0';
(*e)->msg->elements[4]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[4]),D);
(*e)->msg->lg++;
ELEMENT_SMS E;
   E=elementCreersms();
E->texte =(char * )malloc(sizeof(char)*67);
    for(i=269;i<335;i++)
        E->texte[i-269]=ch[i];
        E->texte[335]='\0';
(*e)->msg->elements[5]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[5]),E);
(*e)->msg->lg++;
ELEMENT_SMS F;
   F=elementCreersms();
F->texte =(char * )malloc(sizeof(char)*67);
    for(i=336;i<402;i++)
        F->texte[i-336]=ch[i];
        F->texte[402]='\0';
(*e)->msg->elements[6]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[6]),F);
(*e)->msg->lg++;
ELEMENT_SMS J;
   J=elementCreersms();
J->texte =(char * )malloc(sizeof(char)*67);
    for(i=403;i<469;i++)
        J->texte[i-403]=ch[i];
        J->texte[strlen(ch)]='\0';
(*e)->msg->elements[7]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[7]),J);
(*e)->msg->lg++;
ELEMENT_SMS H;
   H=elementCreersms();
H->texte =(char * )malloc(sizeof(char)*67);
    for(i=470;i<strlen(ch);i++)
        H->texte[i-470]=ch[i];
        H->texte[strlen(ch)]='\0';
(*e)->msg->elements[8]=elementCreersms();
elementAffectersms((&(*e)->msg->elements[8]),H);
(*e)->msg->lg++;

}






    time_t t = time(NULL);
struct tm tm = *localtime(&t);

  (*e)->date_envoi.jour=tm.tm_mday;
  (*e)->date_envoi.mois = tm.tm_mon + 1;
  (*e)->date_envoi.annee = tm.tm_year + 1900;

(*e)->heure_envoi.heure=tm.tm_hour;
 (*e)->heure_envoi.minute =tm.tm_min;
 (*e)->heure_envoi.seconde=tm.tm_sec;

printf("\nheure d'envoi: %i:%i:%i   \ndate d'envoi: %i/%i/%i",(*e)->heure_envoi.heure,(*e)->heure_envoi.minute,(*e)->heure_envoi.seconde,(*e)->date_envoi.jour,(*e)->date_envoi.mois,(*e)->date_envoi.annee);
}










void elementAffecterMSG(ELEMENT_MSG *e1, ELEMENT_MSG e2 ){
    *e1 = e2 ;
}

int elementCopierMSG(ELEMENT_MSG  *e1,ELEMENT_MSG e2){
strcpy((*e1)->recpeteur,e2->recpeteur);
(*e1)->msg=e2->msg;
(*e1)->prix=e2->prix;
(*e1)->date_envoi=e2->date_envoi;
(*e1)->heure_envoi=e2->heure_envoi;

}





void elementDetruireMSG(ELEMENT_MSG e ){
free(e);
}

void elementAfficherMSG(ELEMENT_MSG e){
printf("\n");
listeAffichersms(e->msg);
printf("\nrecpteur:%s",e->recpeteur);
printf("\nheure d'envoi: %i:%i:%i   \ndate d'envoi: %i/%i/%i",e->heure_envoi.heure,e->heure_envoi.minute,e->heure_envoi.seconde,e->date_envoi.jour,e->date_envoi.mois,e->date_envoi.annee);
}
