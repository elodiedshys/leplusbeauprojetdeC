/*les en-têtes des fonctions*/


void initializerMonde(Monde * monde);
int creerUnite(char type, Unite * unite);
int affichePlateau(Monde monde);
void deplacerUnite(Unite *unite, Monde *monde, int destX,
int destY);
void enleverUnite(Unite *unite, Monde *monde);
int attaquer(Unite *unite, Monde *monde, int posX, int
posY);
int deplacerOuAttaquer(Unite *unite, Monde *monde, int
destX, int destY);
void gererDemiTour(char joueur, Monde *monde);
void gererTour(Monde *monde);
void viderMonde(Monde *monde);
void gererPartie(void);
/*BRAVO*/
