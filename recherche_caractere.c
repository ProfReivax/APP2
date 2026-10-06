/*--------------------------------------------------------------------
Fichier: recherche_caractere.c
Description: trouver la position d'un caractere dans une chaine de
caractere
----------------------------------------------------------------------
Historique des modifications
2026-09-29
	- Auteurices: Eva Desbiens, Xavier Dupuis
	- Premiere version.
--------------------------------------------------------------------*/

#include <stdio.h>

/*--------------------------------------------------------------------
Description: Trouve la premiere position d'un caractere dans une 
chaine de caractere
Parametres:
	- charactere (char)	: le caractere a trouver
	- chaine_caractere (tableau de char): la chaine a chercher
Retour:
	- position (entier): la premiere position du caractere

Preconditions: la chaine de caractere doit contenir un caractere de
	fin de chaine.
	On ne doit pas chercher le caractere de fin de chaine '\0'.
	
Postconditions: la position retournee va toujours etre plus grande
	ou egale a 0 si le caractere est present dans la chaine.
	la position retournee va etre -1 si le caractere est absent dans
	la chaine.
	La chaine de caractere passee en parametre n'est pas modifiee
--------------------------------------------------------------------*/
int recherche_caractere(char caractere, char chaine_caractere[])
{
	int compteur = 0, position = -1;
	int trouve = 0;
	
	// on cherche soit le caractere de fin de chaine, soit si on a trouve la valeur
	while(chaine_caractere[compteur] != '\0' && !trouve)
	{
		if (chaine_caractere[compteur] == caractere)
		{
			position = compteur;
			trouve = 1;
		}
		++compteur;
	}
	
	return position;
}

int main(int argc, char **argv)
{
	char chaine_caractere_1[100] = "anticonstitutionnellement";
	char chaine_caractere_2[100] = "bonjour";
	char chaine_caractere_3[100] = "allocommentcava";
	char chaine_caractere_4[100] = "";
	char chaine_caractere_5[100] = "majUscUle";

	printf("Tests de validation de la fonction recherche_caractere\n\n");
	printf("Chaine\t\t\t\tCaractère\tAttendu\t\tRésultat\n");
	// cas anticonstitutionnellement, plusieurs fois la meme lettre
	printf("%s\t%c\t\t1\t\t%d\n", chaine_caractere_1, 'n', recherche_caractere('n', chaine_caractere_1));
	// cas bonjour, aucune lettre trouvee
	printf("%s\t\t\t\t%c\t\t-1\t\t%d\n", chaine_caractere_2, 'e', recherche_caractere('e', chaine_caractere_2));
	// cas bonjour, lettre trouvee a la fin de la chaine (6)
	printf("%s\t\t\t\t%c\t\t6\t\t%d\n", chaine_caractere_2, 'r', recherche_caractere('r', chaine_caractere_2));
	// cas allocommentcava, lettre trouvee a la pos 0
	printf("%s\t\t\t%c\t\t0\t\t%d\n", chaine_caractere_3, 'a', recherche_caractere('a', chaine_caractere_3));
	// cas chaine vide, trouve rien
	printf("%s\t\t\t\t%c\t\t-1\t\t%d\n", chaine_caractere_4, 'z', recherche_caractere('z', chaine_caractere_3));
	// cas recherche de majuscule
	printf("%s\t\t\t%c\t\t3\t\t%d\n", chaine_caractere_5, 'U', recherche_caractere('U', chaine_caractere_5));
	// cas recherche de majuscule
	printf("%s\t\t\t%c\t\t-1\t\t%d\n", chaine_caractere_5, 'u', recherche_caractere('u', chaine_caractere_5));

	return 0;
}

