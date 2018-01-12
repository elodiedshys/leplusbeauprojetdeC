/* dimension du monde en nombre de cases */

#define LONG 12
#define LARG 18

/* l'origine est en haut à gauche */

#define ROUGE 'R' //identifiant du premier joueur
#define BLEU 'B' // identifiant du deuxième joueur

/* les genres d'unites */

#define SERF 's'
#define GUERRIER'g'

typedef struct unite{
  int posX, posY;
  char couleur;
  char genre;
  struct unite *suiv;
} Unite;

typedef Unite* Uliste;

typedef struct monde{
  Unite *plateau[LONG][LARG];
  int tour; /* Numero du tour*/
  Uliste rouge, bleu; /* Listes des deux joueurs*/
} Monde

int creerUnite(char type, LUnite * unite) {
  type a;

}


int main {
  Monde y;
  initializerMonde (y);
}

void initializerMonde (Monde * monde) {
  int i, j;
  if (i=0 ; i<LONG; i++) {

    if (j=0 && i=LONG; j<LARG ; j ++){

    }
  }
}
