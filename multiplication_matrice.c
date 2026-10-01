/*--------------------------------------------------------------------
Fichier: multiplication_matrice.c
Description: operation qui permet de multiplier 2 matrices carrees
----------------------------------------------------------------------
Historique des modifications
2026-09-29
	- Auteurices: Eva Desbiens, Xavier Dupuis
	- Première version.
--------------------------------------------------------------------*/

#include <stdio.h>
#define DIMENSION 4

/*--------------------------------------------------------------------
Description: multiplie les 2 premieres matrices passees en parametre
	et retourne	le resultat dans la troisieme matrice.
Paramètres:
	- mat_1 (matrice d'entier): premiere matrice a additionner
	- mat_2 (matrice d'entier): deuxieme matrice a additionner
	- produit (matrice d'entier): matrice resultante

Préconditions: mat_1, mat_2 et produit sont des matrices distinctes.

Postconditions: mat_1 et mat_2 ne sont pas modifiees.
	produit contient le resultat du produit de matrice.
--------------------------------------------------------------------*/
void multiplication_matrice(int mat_1[DIMENSION][DIMENSION], int mat_2[DIMENSION][DIMENSION], int produit[DIMENSION][DIMENSION])
{
	int m, n, compteur;
	
	// initialiser la matrice de somme à 0 pour se débarasser du garbage en mémoire
	for (m = 0; m < DIMENSION; ++m)
	{
		for (n = 0; n < DIMENSION; ++n) 
		{
			produit[m][n] = 0;
		}
	}
	
	for (m = 0; m < DIMENSION; ++m)
	{
		for (n = 0; n < DIMENSION; ++n) 
		{
			for (compteur = 0; compteur < DIMENSION; ++compteur)
			{
				produit[m][n] = produit[m][n] + mat_1[m][compteur] * mat_2[compteur][n];
			}
		}
	}
}

/*--------------------------------------------------------------------
Description: affiche une matrice a l'ecran

Paramètres:
	- m (matrice d'entier): matrice a afficher

Préconditions: aucune
	
Postconditions: m n'est pas modifiee.
--------------------------------------------------------------------*/
void afficher_matrice(int m[DIMENSION][DIMENSION])
{
	int ligne, colonne;
	
	for (ligne = 0; ligne < DIMENSION; ++ligne)
	{
		for (colonne = 0; colonne < DIMENSION; ++colonne)
		{
			printf("%d\t", m[ligne][colonne]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	int m1[DIMENSION][DIMENSION] = {{1, 1, 1, 1},
									{2, 2, 2, 2},
									{3, 3, 3, 3},
									{4, 4, 4, 4}};
								
	int m2[DIMENSION][DIMENSION] = {{1, 1, 1, 1},
									{2, 2, 2, 2},
									{3, 3, 3, 3},
									{4, 4, 4, 4}};
	int m3[DIMENSION][DIMENSION];
	
	multiplication_matrice(m1, m2, m3);
	afficher_matrice(m3);
	
	return 0;
}

