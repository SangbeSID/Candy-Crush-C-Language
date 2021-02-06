#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "plateau.h"
#include "messages.h"
#include "outils.h"
#include "jeu.h"
#include "special.h"

//===================================
int main()
{
    int choix,k;
    char retour[2];
    Plateau *jeu = NULL;

    system("TITLE=CANDY CRUSH C"); //On defini le titre de la fenetre
    system("mode con LINES=55 COLS=80"); //On fixe la hauteur et la largeur de la fenetre

    Candy_Crush(); //Animation d'accueil

    system("cls"); //On efface la console
    system("color 0A"); //Background color: Noir ; Text Color: Vert-Clair

    MENU();

    printf("\n\n\tFaites votre choix: ");
    scanf("%d", &choix);

    switch(choix){
        case 1 : jeu = Creation_Plateau(NB_LIGNES,NB_COLONNES);
                 Mode_Jeu(jeu);
                 break;

        case 2 : Chargement();
                 break;

        case 3 : system("cls"); //On efface la console
                 AIDE();
                 scanf("%s",retour);
                 k = main();
                 break;

        case 4 : Affiche_Score();
                 break;

        case 5 : A_PROPOS();
                 scanf("%s",retour);
                 k = main();
                 break;

        case 0 : printf("\n\n\tA bientot!\n\t");
                 exit(0);

        default: printf("\n\n\tMauvais choix!\n");
                 printf("\n\tAppuyez sur une touche: "); system("timeout 2 >nul");
                 scanf("%s",retour);
                 free(jeu);
                 k = main();
                 break;
    }
    return 0;
}
