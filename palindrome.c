/*--------------------------------------------------------------------
Fichier: palindrome.c
Description: operation permet de trouver si la chaine de caractere
est un palindrome
----------------------------------------------------------------------
Historique des modifications
2026-09-29
	- Auteurices: Eva Desbiens, Xavier Dupuis
	- Premiere version.
--------------------------------------------------------------------*/

#include <stdio.h>

/*--------------------------------------------------------------------
Description: Determine si la chaine de caractere passee en parametre
est un palindrome ou non
Parametres:
	- chaine_caractere (tableau de char): la chaine a verifier
Retour:
	- palindrome (entier): 1 si la chaine de caractere est un
		palindrome, 0 sinon

Preconditions: la chaine de caractere doit etre moins longue que 99
	char.
	
Postconditions: une chaine vide ou d'un seul caractere est considere
	comme un palindrome.
	On ne tient pas compte des majuscules.
	La chaine de caractere n'est pas modifiee.
--------------------------------------------------------------------*/
int palindrome(char chaine_caractere[])
{
	int compteur, longueur = 0;
	int palindrome = 1;
	
	// trouver la longueur de la chaine de caractere
	while (chaine_caractere[longueur] != '\0')
	{
		++longueur;
	}
	
	for (compteur = 0; compteur < longueur/2 && palindrome; ++compteur)
	{
		palindrome = chaine_caractere[compteur] == chaine_caractere[longueur - (compteur + 1)];
	}
	
	return palindrome;
}

int main(int argc, char **argv)
{
	char palindrome_1[100] = "kayak";
	char palindrome_2[100] = "abcaa";
	char palindrome_3[100] = "wwuuww";
	char palindrome_4[100] = "gghhgl";
	char palindrome_5[100] = "a";
	char palindrome_6[100] = "";

	
	printf("Tests de validation de la fonction palindrome\n\n");
	printf("Chaine\t\tAttendu\t\tRésultat\n");
	// cas palindrome pair, reussite
	printf("%s\t\t1\t\t%d\n", palindrome_1, palindrome(palindrome_1));
	// cas palindrome pair, echec
	printf("%s\t\t0\t\t%d\n", palindrome_2, palindrome(palindrome_2));
	// cas palindrome pair, reussite
	printf("%s\t\t1\t\t%d\n", palindrome_3, palindrome(palindrome_3));
	// cas palindrome pair, echec
	printf("%s\t\t0\t\t%d\n", palindrome_4, palindrome(palindrome_4));
	// cas palindrome 1 lettre
	printf("%s\t\t1\t\t%d\n", palindrome_5, palindrome(palindrome_5));
	// cas palindrome vide
	printf("%s\t\t1\t\t%d\n", palindrome_6, palindrome(palindrome_6));


	return 0;
}

