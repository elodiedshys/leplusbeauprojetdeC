#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nosfonctions.h"



int main(int argc, char const *argv[]){
	Monde monde1;
	Unite unite1;
	Unite unite2;
	Unite unite3;
	Unite unite4;


	initializerMonde(&monde1);
	creerUnite(SERF,&unite1);
	creerUnite(GUERRIER,&unite2);
	creerUnite(SERF,&unite3);
	creerUnite(GUERRIER,&unite4);

	placerAuMonde(&unite1, &monde1, 1, 0, 'R');
	placerAuMonde(&unite2, &monde1, 0, 1, 'R');
	placerAuMonde(&unite3, &monde1, 0, 0, 'B');
	placerAuMonde(&unite4, &monde1, 1, 1, 'B');
	// printf("%c\n",unite1.genre);
	// printf("%d\n",placerAuMonde(&unite1, &monde1, 0, 0, 'R'));
	// printf("%d\n",placerAuMonde(&unite2, &monde1, 10, 0, 'R'));
	// affichePlateau(monde1);

	// printf("%d\n",deplacerOuAttaquer(&unite1, &monde1, 0, 0));

	gererDemiTour(ROUGE, &monde1);
	// affichePlateau(monde1);
	

	// deplacerUnite(&unite1, &monde1, 2,2);
	// deplacerUnite(&unite2, &monde1, 13,10);

	// affichePlateau(monde1);
	// printf("Genre de unite1 : %c\n", unite1.genre);

	// enleverUnite(&unite2, &monde1);

	affichePlateau(monde1);
	printf("\n");
	printf("On vide le plateau\n");
	viderMonde(&monde1);
	affichePlateau(monde1);

	// deplacerUnite(&unite2, &monde1, 13,10);




	return 0;
}