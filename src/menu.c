#include <stdlib.h>
#include <stdio.h>
#include "../header/menu.h"
#include "../header/TP3.h"

void Pause(void) {
    printf("taper une touche pour continuer >");
    getchar();getchar();
}
int main_Exercice()
{
    //Déclare les variables.
	short exec = 1,choiceEx ;
	do
	{
		//Vide la console.
		system("cls");
		//Demande à l'utilisateur de choisir un exercice.
		printf("Quelle Exercice voulez vous executer ?\n(1-2 : Exercice) (0 : Return)\n");
        while(scanf("%hu", &choiceEx) != 1) {
            // Afficher un message d'erreur
            printf("Veuillez entrer un chiffre : ");
            // Scanner n'importe quoi pour vider le buffer
            scanf("%*s");
        }
		//Vide la console.
		system("cls");

		//Switch en fonction du choix de l'utilisateur
		switch (choiceEx)
		{
			case 0:
				//Retour en arrière.
				break;
			case 1:
				//Lance la fonction de l'exercice 1.
				exo1();
				break;

			case 2:
				//Lance la fonction de l'exercice 2.
				exo2();
				break;

			default:
				//Affiche un message d'erreur.
				printf("Choix invalide.\n");
				break;
		}

		//Message d'attente.
		printf("\n\n\nAppuyez sur une touche pour continuer...");
		//Pause.
		Pause();
		//Vide la console.
		system("cls");
		//Demande à l'utilisateur s'il veut continuer.
		printf("Voulez vous rester sur le main Exercice?\nOui (1), Non (0)\n");
        while(scanf("%hu", &exec) != 1) {
            // Afficher un message d'erreur
            printf("Veuillez entrer un chiffre : ");
            // Scanner n'importe quoi pour vider le buffer
            scanf("%*s");
        }
	} while (exec == 1);
	return(0);
}