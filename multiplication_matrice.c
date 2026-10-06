/*--------------------------------------------------------------------
Fichier: multiplication_matrice.c
Description: operation qui permet de multiplier 2 matrices carrees
----------------------------------------------------------------------
Historique des modifications
2026-09-29
	- Auteurices: Eva Desbiens, Xavier Dupuis
	- Premiere version.
2026-10-01
	- Auteurices: Eva Desbiens, Xavier Dupuis
	- Modification de la fonction afficher_matrice.
--------------------------------------------------------------------*/

#include <stdio.h>
#define N 4

/*--------------------------------------------------------------------
Description: multiplie les 2 premieres matrices passees en parametre
	et retourne	le resultat dans la troisieme matrice.
Parametres:
	- mat_1 (matrice d'entier): premiere matrice a additionner
	- mat_2 (matrice d'entier): deuxieme matrice a additionner
	- produit (matrice d'entier): matrice resultante

Preconditions: mat_1, mat_2 et produit sont des matrices distinctes.

Postconditions: mat_1 et mat_2 ne sont pas modifiees.
	produit contient le resultat du produit de matrice.
--------------------------------------------------------------------*/
void multiplication_matrice(int matrice_1[N][N], int matrice_2[N][N], int matrice_resultat[N][N])
{ 
	int ligne;
	int colonne;
	int element;
	int somme = 0;
	// Pour chaque ligne, on parcourt chaque colonne 
	for ( ligne = 0; ligne < N ; ligne++ )
	{
		for ( colonne = 0; colonne < N; colonne++ )
		{
			// On multiplie chaque elements correspondants
			for ( element = 0; element < N; element++)
			{
				somme = somme + matrice_1[ligne][element] * matrice_2[element][colonne];
			}
			// Les elements de la matrice resultat sont modifies
			matrice_resultat[ligne][colonne] = somme;
			somme = 0;
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
void afficher_matrice(int m[N][N])
{
	int ligne, colonne;
	
	for (ligne = 0; ligne < N; ++ligne)
	{
		for (colonne = 0; colonne < N; ++colonne)
		{
			printf("%d\t", m[ligne][colonne]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv)
{
	int m1[N][N] = {{1, 1, 1, 1},
					{2, 2, 2, 2},
					{3, 3, 3, 3},
					{4, 4, 4, 4}};
								
	int m2[N][N] = {{4, 4, 4, 4},
					{3, 3, 3, 3},
					{2, 2, 2, 2},
					{1, 1, 1, 1}};

	int i[N][N] =  {{1, 0, 0, 0},
					{0, 1, 0, 0},
					{0, 0, 1, 0},
					{0, 0, 0, 1}};
					
	int resultat[N][N] = {	{10, 10, 10, 10},
							{20, 20, 20, 20},
							{30, 30, 30, 30},
							{40, 40, 40, 40}};
	int m3[N][N];
	
	multiplication_matrice(m1, m2, m3);
	printf("Tests de validation de la fonction multiplication_matrice\n\n");
	// multiplication de 2 matrices
	printf("Multiplication de 2 matrices quelconques\n");
	printf("Matrice A\n");
	afficher_matrice(m1);
	printf("\nMatrice B\n");
	afficher_matrice(m2);
	printf("\nAttendue\n");
	afficher_matrice(resultat);
	printf("\nResultat\n");
	afficher_matrice(m3);
	
	multiplication_matrice(m1, i, m3);
	// multiplication de la matrice identite
	printf("\nMultiplication avec la matrice identite\n");
	printf("Matrice A\n");
	afficher_matrice(m1);
	printf("\nMatrice identite\n");
	afficher_matrice(i);
	printf("\nAttendu\n");
	afficher_matrice(m1);
	printf("\nResultat\n");
	afficher_matrice(m3);
	
	return 0;
}

