#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nosfonctions.h"


void initializerMonde (Monde * monde){
  int i,j;
  
  for(i=0;i<LARG;i++){
    for(j=0;j<LONG;j++){
      monde->plateau[i][j]=NULL;
    }
  }
  monde->rouge=NULL;
  monde->bleu=NULL;
  monde->tour=0;
}

int creerUnite (char type, Unite * unite){
  Unite *new_unite = malloc(sizeof(Unite));
  // unite=malloc(sizeof(Unite));
  if(new_unite==NULL){
    return 0;
  }
  else{
     new_unite->genre = type;
     *unite= *new_unite;
     return 1;
  }
}


int placerAuMonde(Unite * unite, Monde * monde, int posX, int posY, char couleur){
  
  if(monde->plateau[posX][posY]!= NULL){
    printf("PAS PLACE\n");
    return 0;
  }

  else{ 
  monde->plateau[posX][posY]=unite; 
  unite->posX=posX;
  unite->posY=posY;
  unite->couleur=couleur;
    if(couleur==ROUGE){
      unite->suiv = monde->rouge;
      monde->rouge = unite;
    }
    else{
      unite->suiv = monde->bleu;
      monde->bleu = unite;
    }
    return 1;
  }
}

void affichePlateau(Monde monde) {
  int i, j;
  for(j=0;j<LONG;j++){
    for(i=0;i<LARG;i++){
      printf("----");
    }
    printf("-\n");
    for(i=0;i<LARG;i++){
      printf("|");
      if(monde.plateau[i][j]!=NULL){
        if((monde.plateau[i][j])->genre==SERF)
          printf(" s ");
        else
          printf(" g ");
      }
      else{
        printf("   ");
      }
    }
    printf("|\n");
  }
  for(i=0;i<LARG;i++){
    printf("----");
  }
  printf("-\n");
}


void deplacerUnite(Unite *unite, Monde *monde, int destX, int destY){
  int tempX,tempY;
  tempX=unite->posX;
  tempY=unite->posY;

  unite->posX = destX;
  unite->posY = destY;
  monde->plateau[tempX][tempY]=NULL;
  monde->plateau[destX][destY]=unite;
}

void enleverUnite(Unite *unite, Monde *monde) {
  int posX,posY;
  

  posX = unite->posX;
  posY = unite->posY;

  monde->plateau[posX][posY]=NULL;

      if(unite->couleur==ROUGE){

        if(monde->rouge==unite){
          // free(unite);
          monde->rouge=unite->suiv;
          unite->suiv=NULL;
          
        }
        else{
          Unite *reste=malloc(sizeof(Unite));
          reste=monde->rouge;
          while(reste->suiv!=unite){
            reste=reste->suiv;
          }
          reste->suiv=unite->suiv;
          unite->suiv=NULL;
          // free(unite);

        }
      }

      else{
        if(monde->bleu==unite){
          // free(unite);
          monde->rouge=unite->suiv;
          unite->suiv=NULL;
          
        }
        else{
          Unite *reste=malloc(sizeof(Unite));
          reste=monde->bleu;
          while(reste->suiv!=unite){
            reste=reste->suiv;
          }
          reste->suiv=unite->suiv;
          unite->suiv=NULL;
          // free(unite);

        }
      }
}


int attaquer(Unite *unite, Monde *monde, int posX, int posY) {

  Unite *cible= monde->plateau[posX][posY];

    if (cible->genre == unite->genre){
      enleverUnite(cible, monde);
      printf("Tu as gagné le combat\n");
      return 1;
    }
    else if(cible->genre == SERF && unite->genre == GUERRIER){
      enleverUnite(cible, monde);
      printf("Tu as gagné le combat\n");
      return 1;
    }
    else{
      enleverUnite(unite, monde);
      printf("Tu as perdu le combat\n");
      return 0;
    }
}


int deplacerOuAttaquer(Unite *unite, Monde *monde, int destX, int destY) {

  Unite *cible= monde->plateau[destX][destY];

  int posX=unite->posX;
  int posY=unite->posY;



  if(destX>LARG || destY>LONG || destX<0 || destY<0){
    printf("Case hors du plateau\n");
    return -1;
  }
 

  else { 
    if(destX == posX-1 || destX == posX+1 || destX == posX ){
      if(destY == posY || destY == posY-1 || destY == posY+1){
        printf("La case est voisine\n");
        if(cible!=NULL){
          if(cible->couleur != unite->couleur){
            if(attaquer(unite, monde, destX, destY)==1){
              return 2;
            }
            else{
              return 3;
            }
          }
          else{
            printf("Vous ne pouvez pas attaquer ou aller sur une case occupée par vos propres unités\n");
            return -3;
          }
        }
        else{
          deplacerUnite(unite, monde, destX, destY);
          return 1;
       }
      }
      else{
        printf("La case n'est pas voisine\n");
        return -2;
      }
    }
    else{
      printf("La case n'est pas voisine\n");
      return -2;
    }
  }
}


void gererDemiTour(char joueur, Monde *monde) {
  Unite *liste;
  int reponse,destX,destY,finTour;
  if(joueur == ROUGE){
    liste=monde->rouge;
    while(liste!=NULL){
      affichePlateau(*monde);
      printf("Type : %c\n", liste->genre);
      printf("Position : posX : %d , posY :%d\n", liste->posX, liste->posY);
      printf("Que souhaitez vous faire avec cette unité ?\n");
      printf("1 : Déplacer; 2 : Attaquer; 3 : Ne rien faire\n");
      scanf("%d",&reponse);

      switch(reponse){

        case 1 : 
          printf("Entrez les coordonnées X et Y de la case où vous souhaitez déplacer l'unité\n");
          scanf("%d %d", &destX,&destY);
          printf("Cellule à atteindre : (%d;%d)\n",destX,destY);
          deplacerOuAttaquer(liste,monde,destX,destY);
        break;

        case 2 : 
          printf("Entrez les coordonnées X et Y de la case que vous souhaitez attaquer\n");
          scanf("%d%d", &destX,&destY);
          if(deplacerOuAttaquer(liste,monde,destX,destY)<0){
            printf("action impossible\n");
          }
          else{
            deplacerOuAttaquer(liste,monde,destX,destY);
          }
          break;

        case 3 : printf("Très bien, vous ne faites rien pour cette unité !\n");
      }
      liste=liste->suiv;
    }
  }
  else{
    liste=monde->bleu;
    while(liste!=NULL){
      printf("Type : %c\n", liste->genre);
      printf("Position : posX : %d , posY : %d\n", liste->posX, liste->posY);
      printf("Que souhaitez vous faire avec cette unité ?\n");
      printf("1 : Déplacer; 2 : Attaquer; 3 : Ne rien faire\n");
      scanf("%d",&reponse);

      switch(reponse){

        case 1 : 
          printf("Entrez les coordonnées X et Y de la case où vous souhaitez déplacer l'unité\n");
          scanf("%d%d", &destX,&destY);
          if(deplacerOuAttaquer(liste,monde,destX,destY)<0){
            printf("Action impossible\n");
          }
          else{
            printf("L'unite s'est déplacé en (%d,%d)\n",destX,destY);
          }
        break;

        case 2 : 
          printf("Entrez les coordonnées X et Y de la case que vous souhaitez attaquer\n");
          scanf("%d%d", &destX,&destY);
          if(deplacerOuAttaquer(liste,monde,destX,destY)<0){
            printf("action impossible\n");
          }
          else{
            deplacerOuAttaquer(liste,monde,destX,destY);
          }
          break;

        case 3 : printf("Très bien, vous ne faites rien pour cette unité !\n");
      }
    }
  }
  while(finTour!=0){
    printf("Confirmer la fin de votre tour en entrant 0\n");
    scanf("%d",&finTour);
  }
}

void gererTour(Monde *monde) {
  gererDemiTour(ROUGE,monde);
  gererDemiTour(BLEU, monde);
  monde->tour++;
}

void viderMonde(Monde *monde) {
  Unite *listeRouge = monde->rouge;
  Unite *listeBleu = monde->bleu;
  while(listeRouge!=NULL){
    enleverUnite(listeRouge,monde);
    listeRouge=listeRouge->suiv;
  }
  while(listeBleu!=NULL){
    enleverUnite(listeBleu,monde);
    listeBleu=listeBleu->suiv;
  }
  initializerMonde(monde);
}

// void gererPartie(void) {
//   initializerMonde(monde);
// }

// /*BRAVO*/
