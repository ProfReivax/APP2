/*--------------------------------------------------------------------
Fichier: cosinus.c
Description: operation qui permet de calculer le cosinus
----------------------------------------------------------------------
Historique des modifications
2026-09-29
	- Auteurices: Eva Desbiens, Xavier Dupuis
	- Première version.
--------------------------------------------------------------------*/

#include <stdio.h>
#include <math.h>
#define ITERATIONS 5

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*--------------------------------------------------------------------
Description: Calcule la puissance n du nombre x passe en parametre.
Paramètres:
	- x (reel): nombre dont on veut trouver la puissance
	- n (entier): la puissance appliquee au nombre
Retour:
	- total (reel): le resultat de l'operation

Préconditions: La valeur de la puissance doit etre plus grande ou
	egale a 0.
	le resultat de l'operation ne peut pas etre superieur a la
	valeur maximale d'un double (environ 1.8 * 10^308).
	
Postconditions: retourne x^n
--------------------------------------------------------------------*/
double puissance(double x, int n)
{
	double total = 1;
	int compteur;
	
	for(compteur = 0; compteur < n; ++compteur)
	{
		total *= x;
	}
	
	return total;
}

/*--------------------------------------------------------------------
Description: Calcule la factorielle du nombre n passe en parametre
Paramètres:
	- n (entier): la factorielle a trouver
Retour:
	- total (entier): le resultat de la factorielle

Préconditions: la valeur de n doit se situer entre 0 et 20
	
Postconditions: retourne n!
--------------------------------------------------------------------*/
long long factorielle(int n)
{
	int compteur;
	long long total = 1;
	
	for(compteur = 1; compteur <= n; ++compteur)
	{
		total = total * compteur;
	}
	
	return total;
}

/*--------------------------------------------------------------------
Description: Approxime la valeur d'un cosinus d'un angle en radian 
	avec la serie de Taylor correspondante.
Paramètres:
	- angle (reel): angle dont on cherche le cosinus
Retour:
	- resultat (reel): le resultat de l'approximation du cosinus

Préconditions: la valeur fournie a l'equation doit se trouver entre
	-pi et pi
	
Postconditions: retourne une approximation cos(angle)
--------------------------------------------------------------------*/
double cosinus(float angle)
{
	double resultat = 0;
	int compteur;
	
	for (compteur = 0; compteur < ITERATIONS; ++compteur)
	{
		resultat = resultat + puissance(-1, compteur) * puissance(angle, (compteur * 2)) / (double) factorielle(compteur * 2);
	}
	
	return resultat;
}

int main(int argc, char **argv)
{
	printf("Tests de validation de la fonction cosinus\nCalcule fait avec %d termes\n\n", ITERATIONS);
	
	printf("Valeur\t\t\tValeur exacte\t\tResultat\n");
	// cosinus(1)
	printf("1\t\t\t0.5403\t\t\t%f\n", cosinus(1));
	// cosinus(0)
	printf("0\t\t\t1.00\t\t\t%f\n", cosinus(0));
	// cosinus(pi/4)
	printf("pi/4\t\t\t0.7071\t\t\t%f\n", cosinus(M_PI/4));
	// cosinus(pi/2)
	printf("pi/2\t\t\t0.00\t\t\t%f\n", cosinus(M_PI/2));
	// cosinus(-pi/2)
	printf("pi/2\t\t\t0.00\t\t\t%f\n", cosinus(-M_PI/2));
	// cosinus(-pi)
	printf("-pi\t\t\t-1.00\t\t\t%f\n", cosinus(-M_PI));
	// cosinus(pi)
	printf("pi\t\t\t-1.00\t\t\t%f\n", cosinus(M_PI));

	return 0;
}

