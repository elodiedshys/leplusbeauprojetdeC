/*les en-têtes des fonctions*/

/* dimension du monde en nombre de cases */
#define LONG 12
#define LARG 18
/* l’origine est en haut a gauche */
#define ROUGE 'R' //identifiant du premier joueur
#define BLEU 'B' //identifiant du deuxieme joueur
/* les genres d’unites */
#define SERF 's'
#define GUERRIER 'g'

typedef struct unite{
	int posX, posY; /*pour stocker les coordonn´ees de l’unit´e*/
	char couleur; /* ROUGE ou BLEU */
	char genre; /* GUERRIER ou SERF*/
	struct unite * suiv; /* liste des unit´et suivantes*/
} Unite;

typedef Unite * UListe;

typedef struct monde{
	Unite *plateau[LARG][LONG];
	int tour; /* Numero du tour */
	UListe rouge;
	UListe bleu; /*Listes des deux joueurs*/
} Monde;

void initializerMonde(Monde * monde);
int creerUnite(char type, UListe *nvListe);
int placerAuMonde (Unite *unite, Monde *monde, int posX, int posY, char couleur);
void affichePlateau(Monde monde);
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
void afficherInfosUnite(Unite unite);
void afficherListe(UListe liste);
void creerEtPlacer(Monde *monde, UListe *liste);
int testListeVide(UListe liste);
void gererPartie(void);
/*BRAVO*/
