/**
###############################################################
#   COPRS DES FONCTIONS  UTILISEES POUR GERER LE PLATEAU      #
###############################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "plateau.h"

//===================================
/**
    Cette fonction crée et retourne un plateau vide
**/
Plateau *Creation_Plateau(int nbLigne, int nbColonne)
{
    int i;
    Plateau *surface = (Plateau*)malloc(sizeof(Plateau));

    surface->hauteur = nbLigne; //Definition de la hauteur du plateau du jeu
    surface->largeur = nbColonne; //Definition de la largeur du plateau du jeu

    /**
      Allocation des cases du plateau du jeu
      On Remplir et Parcours le tableau dans le sens de la hauteur
      Tres important dans la suite du programme
    **/
    surface->tab = (Jeton**)malloc(surface->hauteur * sizeof(Jeton*));
    for(i=0 ; i<surface->hauteur ; i++){
        surface->tab[i] = (Jeton*)malloc(surface->largeur * sizeof(Jeton));
    }
    return surface;
}

//===================================
/**
    Cette fonction rempli le plateau avec un nbre de jetons fixé
**/
void Remplir_Plateau(Plateau *surface, int nb_couleur, int nb_mouvement)
{
    srand(time(NULL));
    int i,j;
    int val;

    surface->deplacement = nb_mouvement; //Initialisation du nbre de deplacements
    surface->nbcouleur = nb_couleur; //Initialisation du nbre de couleurs
    surface->score = 0; //Initialisation du score

    for(i=0 ; i<surface->hauteur ; i++){
        for(j=0 ; j<surface->largeur ; j++){
            val = rand() % nb_couleur;
            surface->tab[i][j].couleur = val;
        }
    }
}

//===================================
/**
    Cette fonction affiche une couleur
**/
void Affiche_Couleur(TypeCouleur couleur)
{
    switch(couleur){
        case 0: printf("X"); break;
        case 1: printf("O"); break;
        case 2: printf("H"); break;
        case 3: printf("J"); break;
        case 4: printf("P"); break;
        case 5: printf("A"); break;
        case 6: printf("M"); break;
        case 7: printf("T"); break;
        case 8: printf("K"); break;
        case 9: printf("S"); break;
        case 11: printf("Z"); break;
		case 12: printf("Y"); break;
		case 13: printf("x"); break;
		case 14: printf("o"); break;
		case 15: printf("h"); break;
		case 16: printf("j"); break;
		case 17: printf("p"); break;
		case 18: printf("a"); break;
		case 19: printf("m"); break;
		case 20: printf("t"); break;
		case 21: printf("k"); break;
		case 22: printf("s"); break;
        default: printf(" ");break;
    }
}

//===================================
/**
    Cette fonction affiche un plateau qui s'adapte
    à toutes les tailles
    Colonne: 0 à 10
    Ligne: 0 à 15
**/
void Affiche_Plateau(Plateau *surface)
{
    int i,j,k;
    int c=0;

    printf("\n\t\t||-");
    for(i=0 ; i<surface->largeur ; i++){
            switch(i){
                case 0: printf("a---"); break;
                case 1: printf("b---"); break;
                case 2: printf("c---"); break;
                case 3: printf("d---"); break;
                case 4: printf("e---"); break;
                case 5: printf("f---"); break;
                case 6: printf("g---"); break;
                case 7: printf("h---"); break;
                case 8: printf("i---"); break;
                case 9: printf("j---"); break;
            }
    }
    printf("--|\n\t\t|");

    for(i=0 ; i<surface->largeur ; i++)
        printf("----");
    printf("|\n\t\t");
    //On affiche un tableau special
        for(i=0 ; i<surface->hauteur ; i++){
            printf("|");
            for(j=0 ; j<surface->largeur ; j++){
               c++;
                printf("| "); Affiche_Couleur(surface->tab[i][j].couleur); printf(" ");
                if(c % surface->largeur == 0){
                    if((c/surface->largeur) < 10){
                        printf("| 0%d\n\t\t|",c/surface->largeur);
                        for(k=0 ; k<surface->largeur ; k++)
                            printf("----");
                        printf("|\n\t\t");
                    }
                    else{
                        printf("| %d\n\t\t|",c/surface->largeur);
                        for(k=0 ; k<surface->largeur ; k++)
                            printf("----");
                        printf("|\n\t\t");
                    }
                }
            }
        }
    //On affiche le pied de plateau
     printf("||-");
    for(i=0 ; i<surface->largeur ; i++){
            switch(i){
                case 0: printf("a---"); break;
                case 1: printf("b---"); break;
                case 2: printf("c---"); break;
                case 3: printf("d---"); break;
                case 4: printf("e---"); break;
                case 5: printf("f---"); break;
                case 6: printf("g---"); break;
                case 7: printf("h---"); break;
                case 8: printf("i---"); break;
                case 9: printf("j---"); break;
            }
    }
    printf("--|\n");
}


//=======================================
/**
    Cette fonction affiche la position d'un Jeton
    sur le plateau en fonction de sa position
    réelle dans la structure
**/
void afficheValeursReels(int x, int y)
{
    switch(y){
        case 0: printf("[a]"); break;
        case 1: printf("[b]"); break;
        case 2: printf("[c]"); break;
        case 3: printf("[d]"); break;
        case 4: printf("[e]"); break;
        case 5: printf("[f]"); break;
        case 6: printf("[g]"); break;
        case 7: printf("[h]"); break;
        case 8: printf("[i]"); break;
        case 9: printf("[j]"); break;
    }
    if(x<9)
        printf("[0%d] ",x+1);
    else
        printf("[%d] ",x+1);
}

//=======================================
/**
    Cette fonction clone un plateau de jeu
    et retourne le clone
**/
Plateau* clone_Plateau(Plateau *surface)
{
    Plateau *tmp = Creation_Plateau(surface->hauteur,surface->largeur);
    //On clone le contenu de notre plateau de jeu
    tmp->deplacement=surface->deplacement;
    tmp->score=surface->score;
    tmp->nbcouleur=surface->nbcouleur;
    for(int i=0 ; i<tmp->hauteur ; i++){
        for(int j=0 ; j<tmp->largeur ; j++){
            tmp->tab[i][j].couleur = surface->tab[i][j].couleur;
        }
    }
    return tmp;
}
