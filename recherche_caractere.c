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
	// trouve
	
	// trouve + 1
	
	// pas trouve
	
	// pas trouve majuscule
	
	// chaine vide
	
	char chaine_caractere[100] = "Bonjour les amis";
	int position = recherche_caractere('a', chaine_caractere);
	printf("position : %d", position);
	return 0;
}

