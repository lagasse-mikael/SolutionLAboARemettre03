//But :  Le programme vérifie que l’utilisateur a bien entré un nombre entre 0 et
//		100 et lui indique s’il gagne ou dans le cas contraire lui indique le nombre d’essais restant et lui redemande un
//		nombre.
//
//Défi : Le programme pourrait indiquer si la valeur à trouver est plus grande ou plus petite que la dernière proposition
//		que l'utilisateur a faite.
//
//Nom : Mikael Lagasse
//Date : 03 Octobre 2020


#include<iostream>			//Pour cin et cout
#include<time.h>			//Pour le nombre random

using namespace std;		//Pour ne pas avoir a faire std:: tout le temps.

int main()
{
	//Declaration constante
	
	
	//Declaration des variables
	
	int random;					// permet de mémoriser le nombre choisi aléatoirement par l’ordinateur
	int chances = 5;			//Le nombre de chance.
	int input;					//Reponse de l'utilisateur
	int old_input = -1;			//Input qui a ete entrer juste avant. J'expliquerais un peu plus tard pourquoi on commence a -1.
	int win = 0;				//Variable qui indiquera si on a gagner ou non vers la fin.

	
	srand(time(0));				// pour activer l’aléatoire dans le programme
	random = rand() % 101;		// l’ordinateur calcule un nombre aléatoire entre 0 et 100 et le stocke dans iRandom

	while (chances > 0)			//Le loop arrete pas "tant qu'on a encore des chances" (Je met ceci entre guillement , car j'y reviendrais plus tard.)
	{
		system("CLS");			//Pour rendre le tout plus propre , on clear l'ecran apres chaque essai.
		
		cout << "Vous avez presentement : " << chances << " chances!" << endl;			//On indique a l'utilisateur son nombre de chances.
		
		
		//La section de code qui suivera est executer apres un premiere essai.
		
		if (old_input == -1)			//old_input est initialiser a  -1 , car il faut bien l'initialiser 
										//et on sait que la reponse est entre 0 et 100 , 
										//donc avoir -1 comme reponse est simplement impossible , c'est pourquoi on l'utilise
		{
			//On fait absolument rien.
		}
		else {							//Suivant ce que j'ai ecris plus haut , on peut voir que apres un essais , le if(.. == -1) ne ce re-executera jamais.
			if (old_input > random)		//Si mon ancienne reponse etait plus grande que le chiffre a deviner , on lui dit
			{
				cout << endl <<"Votre reponse d'avant etait plus grande que le chiffre a deviner." << endl;
			}
			else                        //Sinon :
			{
				cout << endl << "Votre reponse d'avant etait plus petite que le chiffre a deviner." << endl;	//On lui indique qu sa reponse etait plus petite que le chiffre a deviner.
			}
		}
		
		cout << endl << "Selon vous , que pourrait etre le numero random qui se situe entre 0 et 100? ";		//On demande a l'utilisateur de deviner le nombre.
		
		cin >> input;			//On stock la reponse dans "input"

		if (input != random)		//Si la reponse n'est pas egale au nombre a deviner :
		{
			chances -= 1;			//On lui enleve une chance ET
			old_input = input;		//On met sa reponse dans "l'historique" , ou elle sera "analyser" dans la section de code au debut du loop.
		}							
		else						//Et si la reponse est bonne :
		{
			win = 1;				//Win ce met a 1 , ce qui voudrait dire qu'on a gagner.
			break;					//On on force le programme a sortir du loop.
		}

		//Et le loop recommence...

	}
	
	//Ici on veut savoir si on est sorti du loop , car il nous restait 0 chance ou si on est sortis du loop , car nous avons gagner.
	
	if (win == 1)					//Donc si on a gagner :
	{
		cout << endl << "Tu as gagner!" << endl;		//On le felicite.
		return 0;										//Et on quitte.
	}
	else                            //Et ici c'est si on a perdu.
	{
		cout << endl << "Il te reste aucune chance.." << endl << "Tu as perdu!" << endl << "Le nombre a trouver etait " << random << endl;		//On le felicite PAS.
		return 0;					//Et on quitte.
	}
}

/* Plan de test.
1:
le chiffre random est 50.

On donne au programme 49

donc :

chance -= 1
old_input = 49;

ET si on recommence la boucle :

On aurait comme message : "Votre reponse d'avant etait plus petite que le chiffre a deviner."

Et si on perd encore 4 fois :

On aurait comme message :
Il te reste aucune chance..
Tu as perdu!
Le nombre a trouver etait 50.

*/
/*
2:

le chiffre random est 2.

On donne au programme 2

donc :

win = 1
break; -> on sort du while(

On aurait comme message :
Tu as gagner!

*/
