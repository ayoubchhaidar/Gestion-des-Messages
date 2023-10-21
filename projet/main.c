#include <stdio.h>
#include <stdlib.h>
#include"SMSPRIM.h"
#include"LSTSMSPRIM.h"
#include"ELTMSGPRIM.h"
#include"LSTMSGPRIM.h"
#include"LSTPRIMCON.h"
#include"CONPRIM.h"
#include"PILEPRIM.h"
#define taillemax 100
#define maxi 10000


int nboccurrences(char * str, char * toSearch)
{
    int i, j, found, count;
    int stringLen, searchLen;

    stringLen = strlen(str);
    searchLen = strlen(toSearch);

    count = 0;

    for(i=0; i <= stringLen-searchLen; i++)
    {
        found = 1;
        for(j=0; j<searchLen; j++)
        {
            if(str[i + j] != toSearch[j])
            {
                found = 0;
                break;
         }
        }
        if(found == 1)
        {
           count++;
        }
    }
    return count;
}





Pile unigrammes(LISTE_MSG L,int M){
char msg[taillemax],ext[maxi];
int i=0,j=1,k=1,y=1,nbocc=0,a=0,c,x,max,sel,esp=0;

Pile p;

p=PileCreerPILE();
for(y=1;y<=L->lg;y++){
               for(c=1;c<=recupererMSG(L,y)->msg->lg;c++){

            strcat(ext,recupererMSG(L,y)->msg->elements[c]->texte);
              strcat(ext," ");
        }}






ext[strlen(ext)]='\0';


while(i<strlen(ext)&&(ext[i]!='\0')){
nbocc=0;
a=0;

while(esp==1){
if((ext[i]==' ')||(ext[i]=='.')||(ext[i]==','))
    i++;
else esp=0;}


while((ext[i]!=' ')&&(i<strlen(ext))){
if(ext[i]!=' ')
msg[a]=ext[i];
    i++;a++;}





 if(ext[i]==' '){esp=1;}
else esp=0;




if(nboccurrences(ext,msg)>1){
    EmpilerPILE(p,msg,nboccurrences(ext,msg));
}


memset(msg,0,strlen(msg)+50);

}

Pile p1=PileCreerPILE();
Pile p2=PileCreerPILE();
NOEUD_PILE q,r,s;
for(j=0;j<M;j++){
        max=0;
        sel=0;
    q=p->tete;
    while(q!=NULL){
        if((q->occ)>max)

        max=q->occ;

            q=q->suivant;
        }
    r=p->tete;
     while((r!=NULL)&&(sel==0)){
            if (r->occ==max){
            EmpilerPILE(p1,r->hoba,r->occ);
            sel=1;}
        else r=r->suivant;
        }

       s=p->tete;
     while(s!=NULL){
            if (strcmp(s->hoba,SommetPILE(p1)->hoba)==0){
            s->occ=0;
             }
         s=s->suivant;
        }


}


r=p1->tete;
     while(r!=NULL){
  if(r->occ!=0)
        EmpilerPILE(p2,r->hoba,r->occ);
        r=r->suivant;
        }

PileAfficherPILE(p2);
memset(ext,0,strlen(ext)+1200);
return p2;
}


Pile bigrammes(LISTE_MSG L,int M){
char msg[taillemax],ext[maxi];
int i=0,j=1,k=1,y=1,nbocc=0,a=0,c,x,max,sel,esp=0,ix;
//tansech fazet el pongtuation fel bigramme wel unigramme yooooooooooooooooooooooooo
Pile p;

p=PileCreerPILE();
for(y=1;y<=L->lg;y++){
               for(c=1;c<=recupererMSG(L,y)->msg->lg;c++){

            strcat(ext,recupererMSG(L,y)->msg->elements[c]->texte);
              strcat(ext," ");
        }}





ext[strlen(ext)]='\0';


while(i<strlen(ext)&&(ext[i]!='\0')){
nbocc=0;
a=0;



while((ext[i]!=' ')&&(i<strlen(ext))){
if(ext[i]!=' ')
msg[a]=ext[i];
    i++;a++;}


while((ext[i]==' ')&&(i<strlen(ext))){
      msg[a]=ext[i];
i++;a++;}
ix=i;

while((ext[ix]!=' ')&&(ix<strlen(ext))){

if(ext[ix]!=' ')
msg[a]=ext[ix];
    ix++;a++;}






if(nboccurrences(ext,msg)>1){
    EmpilerPILE(p,msg,nboccurrences(ext,msg));
}


memset(msg,0,strlen(msg)+50);

}


Pile p1=PileCreerPILE();
Pile p2=PileCreerPILE();
NOEUD_PILE q,r,s;
for(j=0;j<M;j++){
        max=0;
        sel=0;
    q=p->tete;
    while(q!=NULL){
        if((q->occ)>max)

        max=q->occ;

            q=q->suivant;
        }
    r=p->tete;
     while((r!=NULL)&&(sel==0)){
            if ((r->occ==max)){
            EmpilerPILE(p1,r->hoba,r->occ);
            sel=1;}
        else r=r->suivant;
        }

       s=p->tete;
     while(s!=NULL){
            if (strcmp(s->hoba,SommetPILE(p1)->hoba)==0){
            s->occ=0;
             }
         s=s->suivant;
        }


}



      r=p1->tete;
      while(r!=NULL){
      if(r->occ!=0)
      EmpilerPILE(p2,r->hoba,r->occ);
      r=r->suivant;
        }
PileAfficherPILE(p2);
memset(ext,0,strlen(ext)+1200);
return p2;
}























LISTE_MSG trimsg(LISTE_MSG L){
LISTE_MSG LMSG;
LMSG=listeCreerMSG();
int j=1,k=0;

for(j=L->lg;j>=1;j--){
k++;
ELEMENT_MSG M=elementCreerMSG();
elementAffecterMSG(&M,recupererMSG(L,j));
insererMSG(LMSG,M,k);
}
return (LMSG);
}

ELEMENT_CONT lePlusContacte(LISTE_MSG L1, LISTE_CONT L2){
ELEMENT_CONT cnt=elementCreerCON();
int i,j,max=0,t=0;
for(i=1;i<L2->lg+1;i++){

ELEMENT_CONT C=elementCreerCON();
elementAffecterCON(&C,recupererCON(L2,i));


for(j=1;j<L1->lg+1;j++){
ELEMENT_MSG M=elementCreerMSG();
elementAffecterMSG(&M,recupererMSG(L1,j));
if(strcmp(C->numero,M->recpeteur)==0)
    t++;}


if(t>max){
       max=t;
    elementAffecterCON(&cnt,C);
    }
else if(t==max){
    if(C->nom[0]<cnt->nom[0])
    elementAffecterCON(&cnt,C);}
t=0;}
return cnt;}



LISTE_CONT jamaisContactes(LISTE_MSG L1, LISTE_CONT L2){
LISTE_CONT jc=listeCreerCON();
int i=1,j=1,t=0,k=1;
for(i=1;i<L2->lg+1;i++){
ELEMENT_CONT C=elementCreerCON();
elementAffecterCON(&C,recupererCON(L2,i));
while((j<L1->lg+1)&&(t==0)){
ELEMENT_MSG M=elementCreerMSG();
elementAffecterMSG(&M,recupererMSG(L1,j));
if(strcmp(C->numero,M->recpeteur)==0)
t=1;
 j++;
}
j=1;
if(t==0){
insererCON(jc,C,k);
 k++;}
 t=0;

}
return jc;}






LISTE_MSG messages_D1_D2(LISTE_MSG L, DATE D1, DATE D2){
LISTE_MSG ls=listeCreerMSG();

int j=1;
    for(j=1;j<L->lg+1;j++){
    ELEMENT_MSG M=elementCreerMSG();
elementAffecterMSG(&M,recupererMSG(L,j));

    if(((M->date_envoi.annee==D1.annee)&&(M->date_envoi.mois==D1.mois)&&(M->date_envoi.jour>=D1.jour))&&((M->date_envoi.annee==D2.annee)&&(M->date_envoi.mois==D2.mois)&&(M->date_envoi.jour<=D2.jour))){
        insererMSG(ls,M,ls->lg+1);}



    else if(((M->date_envoi.annee==D1.annee)&&(M->date_envoi.mois>D1.mois))&&((M->date_envoi.annee==D2.annee)&&(M->date_envoi.mois==D2.mois)))
        {
            if((M->date_envoi.jour<=D2.jour))
         insererMSG(ls,M,ls->lg+1);
       }



    else if(((M->date_envoi.annee==D1.annee)&&(M->date_envoi.mois==D1.mois))&&((M->date_envoi.annee==D2.annee)&&(M->date_envoi.mois<D2.mois)))
        {
            if(M->date_envoi.jour>=D1.jour)
         insererMSG(ls,M,ls->lg+1);
    }
    else if(((M->date_envoi.annee==D1.annee)&&(M->date_envoi.mois>D1.mois))&&((M->date_envoi.annee==D2.annee)&&(M->date_envoi.mois<D2.mois)))
    {
         insererMSG(ls,M,ls->lg+1);
        }

    else if((M->date_envoi.annee>D1.annee)&&(M->date_envoi.annee<D2.annee))
    {
         insererMSG(ls,M,ls->lg+1);
        }





          else if((M->date_envoi.annee>D1.annee)&&(M->date_envoi.annee==D2.annee)){
              if(M->date_envoi.mois==D2.mois){
                if(M->date_envoi.jour<=D2.jour)
            insererMSG(ls,M,ls->lg+1);}
            else if(M->date_envoi.mois<D2.mois)
                 insererMSG(ls,M,ls->lg+1);
            }

          else if((M->date_envoi.annee==D1.annee)&&(M->date_envoi.annee<D2.annee)){
              if(M->date_envoi.mois==D1.mois){
                if(M->date_envoi.jour>=D1.jour)
            insererMSG(ls,M,ls->lg+1);}
            else if(M->date_envoi.mois>D1.mois)
                 insererMSG(ls,M,ls->lg+1);
            }

    }
    return ls;
}

ELEMENT_MSG messageLePlusLong(LISTE_MSG L){
    int i=1,max=0,j=1,k=0,taille=0;
    ELEMENT_MSG MSG=elementCreerMSG();
for(j=1;j<L->lg+1;j++){
        taille=0;
    ELEMENT_MSG M=elementCreerMSG();
elementAffecterMSG(&M,recupererMSG(L,j));
for(i=1;i<=M->msg->lg;i++){
        ELEMENT_SMS S=elementCreersms();
    elementAffectersms(&S,recuperersms(M->msg,i));
for(k=0;k<strlen(S->texte);k++){
    if(S->texte[k]!=' ')
    taille++;}}
   if(taille>max){
        max=taille;
   elementAffecterMSG(&MSG,M);}
}
return MSG;}



LISTE_CONT tri(LISTE_CONT L){
    int i=1,j=1;
    char k='a';
    LISTE_CONT L1=listeCreerCON();
    for(k='a';k<='z';k++){
    for(i=1;i<L->lg+1;i++){
        ELEMENT_CONT C=elementCreerCON();
    elementAffecterCON(&C,recupererCON(L,i));
    if(C->nom[0]==k){
    insererCON(L1,C,j);
    j++;}
    }}
   return L1;
    }



void liredate(DATE *d){
do{
    printf("annee:");
scanf("%i",&(*d).annee);
}while(((*d).annee>=9999)||((*d).annee<999));



   do{
        printf("mois:");
scanf("%i",&(*d).mois);
}while(((*d).mois>12)||((*d).mois<1));

      if((((*d).mois)%2==0)&&((*d).mois!=2)){
        do{
            printf("jour:");
scanf("%i",&(*d).jour);
}while(((*d).jour>30)||((*d).jour<1));}

  if(((*d).mois)%2!=0){
        do{
            printf("jour:");
scanf("%i",&(*d).jour);
}while(((*d).jour>31)||((*d).jour<1));}
  if((*d).mois==2){
         do{
                printf("jour:");
scanf("%i",&(*d).jour);
}while(((*d).jour>28)||((*d).jour<1));}
}


void dateAfficher(DATE d){
printf("%i,%i,%i",d.annee,d.mois,d.jour);
}





void main()
{
  int M,N,choix,choix1,choix2,k=1,x=1,l=1;
  LISTE_CONT repertoire=listeCreerCON();
  LISTE_MSG boite=listeCreerMSG();

          do{
printf("|----------------------------bienvenu--------------------------------|\n");
printf("|-------------------------|^1 repertoire^|---------------------------|\n");
printf("|----------------------|^2 boite de messages^|-----------------------|\n");
printf("|----------------------------|^0 exit^|------------------------------|\n");
    scanf("%i",&choix);
    system("cls");
    }while((choix!=1)&&(choix!=2)&&(choix!=0));
       do{
switch(choix){
case 1:
    do{
    listeAfficherCON(tri(repertoire));
    printf("\n---------------------1-pour retourner au menu---------------------");
    printf("\n---------------------2-pour ajouter un contact---------------------");
    printf("\n---------------------3-pour supprimer un contact-------------------");
    printf("\n---------------------4-le contact le Plus Contacte-----------------");
    printf("\n---------------------5-le contact jamis Contacte-------------------");
    scanf("%i",&choix1);
    system("cls");
    }while((choix1!=1)&&(choix1!=2)&&(choix1!=3)&&(choix1!=4)&&(choix1!=5));
    ELEMENT_CONT cont=elementCreerCON();



    switch(choix1){
     case 1:
        do{
printf("|----------------------------bienvenu--------------------------------|\n");
printf("|-------------------------|^1 repertoire^|---------------------------|\n");
printf("|----------------------|^2 boite des messages^|-----------------------|\n");
printf("|--------------------------|^0 quitter^|-----------------------------|\n");
    scanf("%i",&choix);
    system("cls");
    }while((choix!=1)&&(choix!=2)&&(choix!=0));
    break;
    case 2:
        elementLireCON(&cont);
        insererCON(repertoire,cont,k);
        k++;
system("cls");
    break;
    case 3:
        listeAfficherCON(repertoire);
        printf("\nl'indice de contact:");
        scanf("%i",&k);
        supprimerCON(repertoire,k);
system("cls");
k--;
break;
    case 4:
        elementAfficherCON(lePlusContacte(boite,repertoire));
        break;
    case 5:
       listeAfficherCON(jamaisContactes(boite,repertoire));
       break;

}
break;
    case 2:
listeAfficherMSG(trimsg(boite));
     do{
    printf("\n---------------------1-pour retourner au menu----------------------");
    printf("\n---------------------2-pour envoyer un message---------------------");
    printf("\n---------------------3-pour supprimer un message-------------------");
    printf("\n---------------------4-chercher entre 2 dates----------------------");
    printf("\n---------------------5-le message le plus long---------------------");
    printf("\n---------------------6-pour voir les unigrammes--------------------");
    printf("\n---------------------7-pour voir les bigrammes---------------------");
    scanf("%i",&choix2);
    system("cls");
    }while((choix2!=1)&&(choix2!=2)&&(choix2!=3)&&(choix2!=4)&&(choix2!=5)&&(choix2!=6)&&(choix2!=7));
         ELEMENT_MSG msg=elementCreerMSG();
            DATE d1,d2;
        switch(choix2){
    case 1:
            do{
printf("|----------------------------bienvenu--------------------------------|\n");
printf("|-------------------------|^1 repertoire^|---------------------------|\n");
printf("|----------------------|^2 boite des messages^|----------------------|\n");
printf("|--------------------------|^0 quitter^|-----------------------------|\n");
    scanf("%i",&choix);
    system("cls");
    }while((choix!=1)&&(choix!=2)&&(choix!=0));
        break;
        case 2:
        elementLireMSG(&msg);
        if(msg->recpeteur[0]=='\0'){
        printf("\nrepertoire:");
        listeAfficherCON(tri(repertoire));
        do{
        printf("\nl'indice de contact:");
        scanf("%i",&l);}while((l>repertoire->lg)||(l<=0));
        strcpy(msg->recpeteur,recupererCON(tri(repertoire),l)->numero);}
        insererMSG(boite,msg,x);
        x++;
        break;
        case 3:
            listeAfficherMSG(boite);
            printf("\nl'indice de message:");
         scanf("%i",&k);
         supprimerMSG(boite,k);
         system("cls");
         x--;
break;
        case 4:
            printf("\ndate min\n");
            liredate(&d1);
              printf("\ndate max\n");
            liredate(&d2);
            listeAfficherMSG(messages_D1_D2(boite,d1,d2));

            break;
        case 5:
            printf("\nle message le plus long:\n");
            elementAfficherMSG(messageLePlusLong(boite));

            break;
        case 6:
            printf("\nle nombre des unigrammes");
            scanf("%i",&M);
            unigrammes(boite,M);
           break;
            case 7:
            printf("\nle nombre des bigrammes");
            scanf("%i",&N);
            bigrammes(boite,N);
           break;
            }
        break;
         }


}while(choix!=0);}





