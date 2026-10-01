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
	// palindrome pair
	
	// palindrome impair
	
	// 1 lettre
	
	// 0 lettres
	char chaine_caractere[100] = "abaaba";
	int palindrome_val = palindrome(chaine_caractere);
	printf("position : %d", palindrome_val);
	return 0;
}

