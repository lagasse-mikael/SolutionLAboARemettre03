//But : Développez un programme qui entre les ventes brutes hebdomadaires de chaque représentant et qui calcule et
//		affiche son salaire.Entrez - 1 à la valeur des ventes pour quitter le programme
//Nom : Mikael Lagasse
//Date : 03 Octobre 2020


#include<iostream>		//Pour l'utilisation de cin et cout

using namespace std;		//Pour de ne pas avoir a faire std::


int main()
{

	//Declaration des constantes

	const int SEMAINE = 250;		//Vue que le 250$ par semaine changera jamais , on indique que c'est une constante. 

	//Declaration des variables

	int ventes = 0;		//Le total des ventes que l'utilisateur entrera sera stocker ici.
	float total;		//Ou l'on stockera le salaire total qui sera calculer a la toute fin.
						//En float , car on ne veux pas que sa arrondise si jamais il y a des chiffres apres la virgule dans notre total.

	cout << "Veuillez entrer votre total en vente brute : ";		//On demande le total en vente brute a l'utilisateur.
	
	cin >> ventes;			//Il nous le donne et le nombre entrer sera stocker dans "ventes"

	while (ventes != -1)		//Tant qu'on a pas entrer -1 , on continue d'executer le programme
	{

		total = SEMAINE + (ventes * 0.075);			//Ici , on calcul le salaire total selon le total des ventes hebdomadaire.
		cout << endl <<"Votre salaire est de : " << total << endl;		//On lui montre le salaire total.
		
		cout << endl <<"Veuillez entrer votre total en vente brute ( ou -1 pour quitter ): ";		//On redemande a l'utilisateur si il souhaite effectuer un autre calcul. Si celui-ci entre -1 , on quitte le loop.
		cin >> ventes;		//Il nous le donne et le nombre entrer sera stocker dans "ventes" OU -1 pour quitter.

	}		//Fin du loop While()

	cout << endl << "Merci et a la prochaine!";		//Petit message cool avant la fermeture du programme

	return 0;		//On arrete tout et on retourne 0 pour indiquer que tout c'est bien passer.
}

/* Plan de test
1:

En une semaine on fait 5000$ de ventes.

ventes = 5000;

On fait donc 7.5% de ses ventes PLUS 250$

On aurait donc au total 

625$ , car 250$ + ( 5000 * 7.5% )

*/
/*
2:

On a accrocher le programme et il s'ouvre par accident.

ventes = -1.

On quitte donc le programme.

*/