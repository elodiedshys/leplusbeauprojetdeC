#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nosfonctions.h"



int main(int argc, char const *argv[]){
	Monde monde1;
	Unite unite1;
	Unite unite2;


	initializerMonde(&monde1);
	printf("%d\n",creerUnite(SERF,&unite1));
	printf("%d\n",creerUnite(SERF,&unite2));
	// printf("%c\n",unite1.genre);
	printf("%d\n",placerAuMonde(&unite1, &monde1, 0, 0, 'R'));
	printf("%d\n",placerAuMonde(&unite2, &monde1, 10, 0, 'R'));



	affichePlateau(monde1);

	deplacerUnite(&unite1, &monde1, 2,2);
	deplacerUnite(&unite2, &monde1, 13,10);

	affichePlateau(monde1);
	printf("Genre de unite1 : %c\n", unite1.genre);

	// deplacerUnite(&unite2, &monde1, 13,10);




	return 0;
}