#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "nosfonctions.h"


void initializerMonde (Monde * monde){
  int i,j;
  
  for(i=0;i<LONG;i++){
    for(j=0;j<LARG;j++){
      monde->plateau[i][j]=NULL;
    }
  }
  monde->rouge=NULL;
  monde->bleu=NULL;
  monde->tour=0;
}

int creerUnite (char type, Unite * unite){
  Unite *new_unite = malloc(sizeof(Unite));
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
  monde->plateau[posY][posX]=unite; 
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
  for(i=0;i<LONG;i++){
    for(j=0;j<LARG;j++){
      printf("----");
    }
    printf("-\n");
    for(j=0;j<LARG;j++){
      printf("|");
      if(monde.plateau[i][j]!=NULL){
        printf(" * ");
      }
      else{
        printf("   ");
      }
    }
    printf("|\n");
  }
  for(j=0;j<LARG;j++){
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
  monde->plateau[tempY][tempX]=NULL;
  monde->plateau[destY][destX]=unite;
}

// void enleverUnite(Unite *unite, Monde *monde) {
//   /*contenu de la fonction*/
// }

// int attaquer(Unite *unite, Monde *monde, int posX, int
// posY) {
//   /*contenu de la fonction*/
// }

// int deplacerOuAttaquer(Unite *unite, Monde *monde, int
// destX, int destY) {
//   /*contenu de la fonction*/
// }

// void gererDemiTour(char joueur, Monde *monde) {
//   /*contenu de la fonction*/
// }

// void gererTour(Monde *monde) {
//   /*contenu de la fonction*/
// }

// void viderMonde(Monde *monde) {
//   /*contenu de la fonction*/
// }

// void gererPartie(void) {
//   /*contenu de la fonction*/
// }

// /*BRAVO*/
