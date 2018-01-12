#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* dimension du monde en nombre de cases */
#define LONG 12
#define LARG 18
/* l’origine est en haut a gauche */
#define ROUGE ’R’ //identifiant du premier joueur
#define BLEU ’B’ //identifiant du deuxieme joueur
/* les genres d’unites */
#define SERF ’s’
#define GUERRIER ’g’

typedef struct unite{
	int posX, posY; /*pour stocker les coordonn´ees de l’unit´e*/
	char couleur; /* ROUGE ou BLEU */
	char genre; /* GUERRIER ou SERF*/
	struct unite *suiv; /* liste des unit´et suivantes*/
} Unite;

typedef Unite* UListe{
	int nombre;
}

typedef struct monde{
	Unite *plateau[LONG][LARG];
	int tour; /* Numero du tour */
	UListe rouge;
	UListe bleu; /*Listes des deux joueurs*/
} Monde;


void initializerMonde(Monde *monde){
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

int creerUnite(char type, Unite * unite){

	Unite *nulf=malloc(sizeof(Unite));
	if(nulf==NULL){
		return 0;
	}
	nulf->genre=type;

	return 1;
}

void ajoutUniteListe(Uliste liste, Unite *unite){
	Uliste liste;
	liste==malloc(sizeof(liste));
	if(!liste){
		printf("Memory runs out\n");
		exit(1);
	}
	else{
		liste->nombre+=1;
	}
}

int placerAuMonde (Unite *unite, Monde *monde, int posX, int posY, char couleur){
	unite->posX = posX;
	unite->posY = posY;
	unite->couleur = couleur;
	monde->plateau[posY][posX]=unite;

	if(strcmp(&couleur, "ROUGE")){
		monde->rouge = unite;//ajout dans une liste chainée joueur
		unite->suiv = NULL;//pointe sur l'ancien premier élément
	}
	else{
		monde->bleu = unite;
		unite->suiv = NULL;
	}



	return 1;

}

void affichePlateau(Monde monde){
	int i, j;
	for(i=0;i<LONG;i++){
		for(j=0;j<LARG;j++){
			printf("------");
		}
		printf("-\n");
		for(j=0;j<LARG;j++){
			printf("|");
			if(monde.plateau[i][j]!=NULL){
				printf(" * * ");
			}
			else{
				printf("     ");
			}
		}
		printf("|\n");
	}
	for(j=0;j<LARG;j++){
		printf("------");
	}
	printf("-");
}	


void deplacerUnite(Unite * unite, Monde *monde, int destX, int destY){

		int tempX,tempY;
		tempX=unite->posX;
		tempY=unite->posY;

		unite->posX = destX;
		unite->posY = destY;
		monde->plateau[tempY][tempX]=NULL;
		monde->plateau[destY][destX]=unite;
}


int main(int argc, char const *argv[]){
	Monde monde1;
	Unite unite1;
	Unite unite2;


	initializerMonde(&monde1);
	creerUnite('s',&unite1);
	
	creerUnite('s',&unite1);

	printf("%d\n",placerAuMonde(&unite1, &monde1, 0, 0, 'R'));
	printf("%d\n",placerAuMonde(&unite2, &monde1, 12, 8, 'R'));

	affichePlateau(monde1);

	deplacerUnite(&unite1, &monde1, 2,2);
	deplacerUnite(&unite2, &monde1, 13,10);

	affichePlateau(monde1);

	deplacerUnite(&unite2, &monde1, 13,10);





	return 0;
}