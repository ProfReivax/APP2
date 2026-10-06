/*--------------------------------------------------------------------
Fichier: addition_matrice.c
Description: operation qui permet d'additionner 2 matrices
----------------------------------------------------------------------
Historique des modifications
2026-09-29
	- Auteurices: Eva Desbiens, Xavier Dupuis
	- Premiere version.
--------------------------------------------------------------------*/

#include <stdio.h>
#define LIGNES 3
#define COLONNES 2

/*--------------------------------------------------------------------
Description: Additionne les 2 premieres matrices passees en parametre
	et retourne	le resultat dans la troisieme matrice.
Parametres:
	- mat_1 (matrice d'entier): premiere matrice a additionner
	- mat_2 (matrice d'entier): deuxieme matrice a additionner
	- somme (matrice d'entier): matrice resultante

Preconditions: pour toute valeur de i et j, mat_1[i][j] + mat_2[i][j]
	doit etre plus petit que la valeur maximale d'un int:
	(environ 2 * 10^9).
	mat_1, mat_2 et somme sont des matrices distinctes.
	
Postconditions: mat_1 et mat_2 ne sont pas modifiees.
	somme contient le resultat de l'addition.
--------------------------------------------------------------------*/
void addition_matrice(int mat_1[LIGNES][COLONNES], int mat_2[LIGNES][COLONNES], int somme[LIGNES][COLONNES])
{
	int m, n;
	
	for (m = 0; m < LIGNES; ++m)
	{
		for (n = 0; n < COLONNES; ++n) 
		{
			somme[m][n] = mat_1[m][n] + mat_2[m][n];
		}
	}
}

/*--------------------------------------------------------------------
Description: affiche une matrice a l'ecran

Parametres:
	- m (matrice d'entier): matrice a afficher

Preconditions: aucune
	
Postconditions: m n'est pas modifiee.
--------------------------------------------------------------------*/
void afficher_matrice(int m[LIGNES][COLONNES])
{
	int ligne, colonne;
	
	for (ligne = 0; ligne < LIGNES; ++ligne)
	{
		for (colonne = 0; colonne < COLONNES; ++colonne)
		{
			printf("%d\t", m[ligne][colonne]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	
	int m1[LIGNES][COLONNES] = {{1, 2},
								{3, 4},
								{5, 6}};
								
	int m2[LIGNES][COLONNES] = {{6, 5},
								{4, 3},
								{2, 1}};

	int m3[LIGNES][COLONNES];

	addition_matrice(m1, m2, m3);
	
	printf("Tests de validation de la fonction additionner_matrice\n\n");
	printf("Matrice A\n");
	afficher_matrice(m1);
	printf("\nMatrice B\n");
	afficher_matrice(m2);	
	printf("\nResultat\n");
	afficher_matrice(m3);
	
	return 0;
}

