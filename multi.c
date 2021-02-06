/**
#############################################################
#           MULTIJOUEURS + CORPS DES FONCTIONS              #
#############################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "structures.h"
#include "plateau.h"
#include "messages.h"
#include "outils.h"
#include "jeu.h"
#include "special.h"
#include "cartes.h"
#include "multi.h"

//         --------------------------------------------------------------
//        |                 MULTIJOUEUR CLASSIQUE                        |
//         --------------------------------------------------------------

//===================================
/**
    Cette fonction permet de jouer une partie
    normale à deux(2)
**/
void multi_joueur(Plateau *surface)
{
    srand(time(NULL));
	int xd, yd;                  //Position de départ
	int x, y;                    //Position d'arrivee
	char coup[6];               //Contiendra la chaine de caractère du coup du joueur
	int option = -1;
	int numTour = 0;              //Indique le tour de jeu
	int cptJeu = 0;               //A chaque fois quue c'est le tour d'un joueur, on l'incréménte
	char j1[100], j2[100];
	int scoreJ1, scoreJ2;
	int tourDeJeu = rand();       //Cette variable nous permettra de sélectionner le joueur a qui est le tour.
	int nbPointsMax = 3000; //Nombre de points maximum à avoir avant l'adversaire pour remporter la partie
	Jeton tmp;
	int sup1, sup2;             //Score supplémentaire des deux joueurs
	scoreJ1 = 0;
	scoreJ2 = 0;

	system("cls"); //On efface la console
	printf("\n\n\t\tBIENVENUE DANS LE MODE MULTIJOUEUR CLASSIQUE\n\n");
	system("timeout 2 >nul");
	printf("\n\tDans cette partie, le premier a atteindre %d points gagne\n", nbPointsMax);
	system("timeout 1 >nul");
	printf("\n\n\n\tJoueur 1, veuillez entrez votre nom:  ");
	scanf("%s", &j1);
	printf("\n\n\n\tJoueur 2, veuillez entrez votre nom:  ");
	scanf("%s", &j2);
	system("cls");

	//On choisit le joueur qui commence la partie en utilisant notre variable tourDeJeu
	printf("\n\n\tTirage au sort du joueur qui va debuter la partie...");
	system("timeout 1 >nul"); printf("."); system("timeout 1 >nul"); printf(".");
	if (tourDeJeu % 2 == 0) {
		printf("\n\n\n\tC'est [%s] qui a l'honneur de debuter la partie\n\n", &j1);
	}
	else {
		printf("\n\n\n\tC'est [%s] qui a l'honneur de debuter la partie\n\n", &j2);
	}
	system("timeout 4 >nul"); system("cls");

	//On teste si les scores max ne sont pas atteints
	while (scoreJ1 < nbPointsMax && scoreJ2 < nbPointsMax) {

        system("cls");
		//S'il y a toujours des combinaisons après le remplissage precedent,
		//j'affiche le plateau, attribue les points et recomplete le plateau

		while (Test_Plateau_Organiser(surface) == 0) {
			printf("\t\t\tSUPPRESSION EN CASCADE\n\n");
			Affiche_Plateau(surface);
			if (tourDeJeu % 2 != 0) {
                printf("\n\t\t[%5s] ===> SCORE: %d", j1, scoreJ1);
                printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
				int nbPionsElimines = nombreDePionsEnCombinaison(surface);
				printf("\n\t\t[%s] elimine %d Jetons supplementaires apres cascade \n", j1, nbPionsElimines);
				system("timeout 2 >nul");
				sup1 = Supprimer_Jeton(surface) * 100;

                system("cls");
                Affiche_Plateau(surface);
                printf("\n\t\t[%5s] ===> SCORE: %d", j1, scoreJ1);
                printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
				scoreJ1 = scoreJ1 + sup1;
				printf("\n\t\tScore supplementaire: +%d", sup1); system("timeout 2 >nul");
			}
			else {
                printf("\n\t\t[%5s] ===> SCORE: %d", j2, scoreJ2);
                printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
				int nbPionsElimines = nombreDePionsEnCombinaison(surface);
				printf("\n\t\t[%s] elimine %d Jetons supplementaires apres cascade \n", j2, nbPionsElimines);
                system("timeout 2 >nul");
				sup2 = Supprimer_Jeton(surface) * 100;

				system("cls");
				Affiche_Plateau(surface);
				printf("\n\t\t[%5s] ===> SCORE: %d", j2, scoreJ2);
                printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
				scoreJ2 = scoreJ2 + sup2;
				printf("\n\t\tScore supplementaire: +%d", sup2); system("timeout 2 >nul");
			}
			Completer_Plateau(surface); system("timeout 2 >nul");
			system("cls");
		}

		Affiche_Plateau(surface);

		// Mise a zero du coup precedent
		xd = yd = x = y = -1;

		//Affichage des scores
		printf("\n\t\t[%s] ===>\tSCORE: %d", j1, scoreJ1);
		printf("\n\t\t[%s] ===>\tSCORE: %d", j2, scoreJ2);
        printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);

		//Affichage du joueur qui doit jouer
		printf("\tA qui le tour: ====> ");
		if (tourDeJeu % 2 == 0) {
			printf("[%s] <====\n", j1);
		}
		else {
			printf("[%s] <====\n", j2);
		}

		//Saisie du deplacement a effectuer
		printf("\n\n\tPour revenir au menu principal, taper \"M\" \n");
		printf("\n\tPour visualiser l'aide, taper \"A\" \n");
		printf("\n\n\tQue souhaitez vous jouer? : ");
		scanf("%s", coup);

		if (strcmp(coup, "M") == 0) {
			free(surface);
			int sup1 = main();
			break;
		}
		else if(strcmp(coup, "A") == 0){
            //Help_Multi(surface,'N');
            system("cls");
            AIDE();
            system("pause >nul");
            //décrémentaion du tour de jeu et du compteur de jeu
			tourDeJeu -= 2;
			cptJeu -= 2;
			numTour -= 1;
		}
		else {
			//On recupere l'ordonnee du pion a deplacer
			if (coup[0] == 'a' || coup[0] == 'A') yd = 0;
			else if (coup[0] == 'b' || coup[0] == 'B') yd = 1;
			else if (coup[0] == 'c' || coup[0] == 'C') yd = 2;
			else if (coup[0] == 'd' || coup[0] == 'D') yd = 3;
			else if (coup[0] == 'e' || coup[0] == 'E') yd = 4;
			else if (coup[0] == 'f' || coup[0] == 'F') yd = 5;
			else if (coup[0] == 'g' || coup[0] == 'G') yd = 6;
			else if (coup[0] == 'h' || coup[0] == 'H') yd = 7;
			else if (coup[0] == 'i' || coup[0] == 'I') yd = 8;
			else if (coup[0] == 'j' || coup[0] == 'J') yd = 9;

			//48 correspond au caractere zero '0': on aurait pu faire (int)coup - '0'
			xd = ((int)coup[1] - 48) * 10 + ((int)coup[2] - 48); //On recupere l'abscisse du pion a deplacer

																 //On recupere les coordonnees de la destination
			if (coup[4] == 'h' || coup[4] == 'H') {
				y = yd;
				x = xd - 1;
			}
			else if (coup[4] == 'D' || coup[4] == 'd') {
				y = yd + 1;
				x = xd;
			}
			else if (coup[4] == 'G' || coup[4] == 'g') {
				y = yd - 1;
				x = xd;
			}
			else if (coup[4] == 'B' || coup[4] == 'b') {
				y = yd;
				x = xd + 1;
			}

			//Test sur les coordonnees entrees: xd,x €[1;15] et yd,y €[0;9]
			if (coup[3]!='-' || yd<0 || yd>surface->largeur - 1 || xd<1 || xd>surface->hauteur || y<0
				|| y>surface->largeur - 1 || x<1 || x>surface->hauteur) {
				printf("\n\n\tDeplacement pas possible!\n\n");
				system("timeout 2 >nul");
			}
			else {
				xd--; //On recupere les valeurs reelles de xd et x
				x--;  //en fonction de la structure du plateau de jeu
				Echanger_Position(surface, xd, yd, x, y); //On échange les positions des jetons
				if (Test_Combinaison(surface, x, y) == 1 || Test_Combinaison(surface, xd, yd) == 1) {
					//Attribution du score au joueur:
					if (tourDeJeu % 2 == 0) { // JOUEUR 1
						if (Test_4Jetons_Alignes(surface, x, y) == 1 || Test_4Jetons_Alignes(surface, xd, yd) == 1){
                            //si l'un des jeton ets dans un alignement de 4
                            //Si c'est le 1er jeton
							if (Test_4Jetons_Alignes(surface, x, y) == 1){
								tmp.couleur = surface->tab[x][y].couleur; //on retient la couleur du jeton (x,y)
								int nbPionsElimines = nombreDePionsEnCombinaison(surface);
								sup1 = Supprimer_Jeton(surface);
								printf("\n\t\t[%s] elimine %d pions \n", j1, nbPionsElimines);
								system("timeout 2 >nul");

								system("cls");
								Affiche_Plateau(surface);
								printf("\n\t\t[%s] ===>\tSCORE: %d", j1, scoreJ1);
                                printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
								printf("\n\t\tScore supplementaire: +%d", sup1);

								system("timeout 2 >nul");
								Completer_Plateau(surface); //on regenere le plateau
								Remplacer_Forme(surface, x, y, tmp); //on remplace le jeton en position (x,y) par un jeton special de la bonne couleur
								scoreJ1 = scoreJ1 + sup1;
							}
							//Si c'est le 2eme jeton
							if (Test_4Jetons_Alignes(surface, xd, yd) == 1) {
								tmp.couleur = surface->tab[xd][yd].couleur;//on retient la couleur du jeton (xd,yd)
								int nbPionsElimines = nombreDePionsEnCombinaison(surface);
								sup1 = Supprimer_Jeton(surface);
								printf("\n\t\t[%s] elimine %d pions \n", j1, nbPionsElimines);
								system("timeout 2 >nul");

								system("cls");
								Affiche_Plateau(surface);
								printf("\n\t\t[%s] ===>\tSCORE: %d", j1, scoreJ1);
                                printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
								printf("\n\t\tScore supplementaire: +%d", sup1);

								system("timeout 2 >nul");
								Completer_Plateau(surface); //on regenere le plateau
								Remplacer_Forme(surface, xd, yd, tmp);//on remplace le jeton en position (xd,yd) par un jeton special de la bonne couleur
								scoreJ1 = scoreJ1 + sup1;
							}
						}
						else
						{
							int nbPionsElimines = nombreDePionsEnCombinaison(surface);
							sup1 = Supprimer_Jeton(surface);
                            printf("\n\t\t[%s] elimine %d pions \n", j1, nbPionsElimines);
                            system("timeout 2 >nul");

                            system("cls");
							Affiche_Plateau(surface);
							printf("\n\t\t[%s] ===>\tSCORE: %d", j1, scoreJ1);
                            printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
							printf("\n\t\tScore supplementaire: +%d", sup1); system("timeout 2 >nul");
							scoreJ1 = scoreJ1 + sup1;
						}

					}
					else { // JOUEUR 2
						if (Test_4Jetons_Alignes(surface, x, y) == 1 || Test_4Jetons_Alignes(surface, xd, yd) == 1) {
                            //si l'un des jeton ets dans un alignement de 4
                            //Si c'est le 1er jeton
							if (Test_4Jetons_Alignes(surface, x, y) == 1) {
								tmp.couleur = surface->tab[x][y].couleur; //on retient la couleur du jeton (x,y)
								int nbPionsElimines = nombreDePionsEnCombinaison(surface);
								sup2 = Supprimer_Jeton(surface);
								printf("\n\t\t[%s] elimine %d pions \n", j2, nbPionsElimines);
								system("timeout 2 >nul");

								system("cls");
								Affiche_Plateau(surface);
								printf("\n\t\t[%s] ===>\tSCORE: %d", j2, scoreJ2);
                                printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
								printf("\n\t\tScore supplementaire: +%d", sup2);

								system("timeout 2 >nul");
								Completer_Plateau(surface); //on regenere le plateau
								Remplacer_Forme(surface, x, y, tmp); //on remplace le jeton en position (x,y) par un jeton special de la bonne couleur
								system("timeout 2 >nul");
								scoreJ2 = scoreJ2 + sup2;
							}
							//Si c'est le 2eme jeton
							if (Test_4Jetons_Alignes(surface, xd, yd) == 1) {
								tmp.couleur = surface->tab[xd][yd].couleur;//on retient la couleur du jeton (xd,yd)
								int nbPionsElimines = nombreDePionsEnCombinaison(surface);
								sup2 = Supprimer_Jeton(surface);
								printf("\n\t\t[%s] elimine %d pions \n", j2, nbPionsElimines);
								system("timeout 2 >nul");

								system("cls");
								Affiche_Plateau(surface);
								printf("\n\t\t[%s] ===>\tSCORE: %d", j2, scoreJ2);
                                printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
								printf("\n\t\tScore supplementaire: +%d", sup2);

								system("timeout 2 >nul");
								Completer_Plateau(surface); //on regenere le plateau
								Remplacer_Forme(surface, xd, yd, tmp); //on remplace le jeton en position (x,y) par un jeton special de la bonne couleur
								system("timeout 2 >nul");
								scoreJ2 = scoreJ2 + sup2;
							}
						}
						else{ //Si aucun des jetons ne crée une combinaison de 4
							int nbPionsElimines = nombreDePionsEnCombinaison(surface);
							sup2 = Supprimer_Jeton(surface);
                            printf("\n\t\t[%s] elimine %d pions \n", j2, nbPionsElimines);
                            system("timeout 2 >nul");

                            system("cls");
							Affiche_Plateau(surface);
							printf("\n\t\t[%s] ===>\tSCORE: %d", j2, scoreJ2);
                            printf("\n\n\t\tObjectif: %d\n\n", nbPointsMax);
							printf("\n\t\tScore supplementaire: +%d", sup2); system("timeout 2 >nul");
							scoreJ2 = scoreJ2 + sup2;
						}
					}
					//On complète les espaces vides
                    Completer_Plateau(surface);
                    system("timeout 2 >nul");
                    system("cls");
				}
				else {//S'il n'y a pas de combinaison possible
					printf("\n\tPas de combinaison valible! \n");
					printf("\n\tScore supplementaire: 0");
					system("timeout 2 >nul");
					Echanger_Position(surface, xd, yd, x, y); //On remet les jetons a leur position d'origine
				}
			}
			system("cls");
			//incrémentaion du tour de jeu et du compteur de jeu
			tourDeJeu += 1;
			cptJeu += 1;
		}
	}

	/*
	------------AFFICHAGE DU VAINQUEUR---------
	*/
	system("cls");
	Affiche_Plateau(surface);
	if (scoreJ1 >= nbPointsMax) {
		printf("\n\tLe grand vainqueur est: [%s], avec un score de %d", j1, scoreJ1);
	}
	else {
		printf("\n\tLe grand vainqueur est: [%s], avec un score de %d", j2, scoreJ2);
	}
	printf("\n\t\tSoit, %d points d'avance sur son adversaire direct", abs(scoreJ1 - scoreJ2));
	printf("\n\n\t\tSCORE de [%s]  :%d\n", j1, scoreJ1);
	printf("\t\tSCORE de [%s]  :%d\n\n", j2, scoreJ2);

	printf("\t\tAppuyez sur une touche pour quitter: "); system("pause >nul");
	sup1 = main();

	/** FIN DE MODE MULTIJOUEUR CLASSIQUE **/
}


//         --------------------------------------------------------------
//        |          MULTIJOUEUR AVEC CHACUN SA COULEUR                  |
//         --------------------------------------------------------------

//===================================
/**
    Cette fonction permet de choisir une couleur
    parmi celles proposées
**/
void choixDesCouleurs()
{
    printf("\t\t0 -----> X\n");
    printf("\t\t1 -----> O\n");
    printf("\t\t2 -----> H\n");
    printf("\t\t3 -----> J\n");
    printf("\t\t4 -----> P\n");
    printf("\t\t5 -----> A\n");
    printf("\t\t6 -----> M\n");
    printf("\t\t7 -----> T\n");
    printf("\t\t8 -----> K\n");
    printf("\t\t9 -----> S\n");
}

//===================================
/**
    Cette fonction retourne le caractère d'une
    couleur en fonction de son numero (typedef enum)
**/
char imageCouleur(int c)
{
    char car;
    switch(c){
        case 0: car='X'; return(car); break;
        case 1: car='O'; return(car); break;
        case 2: car='H'; return(car); break;
        case 3: car='J'; return(car); break;
        case 4: car='P'; return(car); break;
        case 5: car='A'; return(car); break;
        case 6: car='M'; return(car); break;
        case 7: car='T'; return(car); break;
        case 8: car='K'; return(car); break;
        case 9: car='S'; return(car); break;
    }
}


//===================================
/**
    Cette fonction renvoie une valeur entre
    0 et a sauf b et c
**/
int random(int a,int b,int c)
{
    int res=rand()%a;
    res=rand()%a;
    while(res==b || res==c){
        res=rand()%a;
    }
    return res;
}


//===================================
/**
    Cette fonction remplit le plateau avec 20 Jetons
    de couleurs c1 et 20 Jetons de couleur c2
**/
void remplitNombreEgaleDeDeuxCouleur(Plateau *surface, int c1, int c2)
{
    int i, j;       //Coordonnées d'un jeton dans le plateau
    int couleurAct; //Couleur actuelle d'un jeton à une certain x et un certain y
    int cpt;        //Nombre des couleurs des deux joueurs à repartir de manière égale.
                    //Je choisis de donner 20 couleurs à chacun.

    //Je remplis avec une couleur ne faisant partie de la liste des couleurs
    //Pour eviter qu'une couleur existante se trouve dans le plateau
    for(int x=0 ; x<surface->hauteur ; x++){
        for(int y=0 ; y<surface->largeur ; y++){
            surface->tab[x][y].couleur = 15;
        }
    }

    //Je remplis les pions avec des couleurs autres que celles des deux joueurs
    //Je remplis avec une couleur ne faisant partie de la liste des couleurs
    //Pour eviter qu'une couleur existante se trouve dans le plateau
    while(Test_Plateau_Organiser(surface)==0){
        for(int x=0 ; x<surface->hauteur ; x++){
            for(int y=0 ; y<surface->largeur ; y++){
                surface->tab[x][y].couleur = random(surface->nbcouleur,c1,c2);
            }
        }
    }

    //On met les 20 pions c1
    cpt=20;   //Je choisis de donner 20 couleurs au joueur.
    while(cpt>0){
        i=rand()%surface->hauteur;
        j=rand()%surface->largeur;
        couleurAct=surface->tab[i][j].couleur;
        if(couleurAct!=c1){
            surface->tab[i][j].couleur=c1;
            if(Test_Combinaison(surface,i,j)==0){
                //Si le pion n'est pas dans une combinaison on le positionne
                cpt--;
            }
            else{//Sinon, on l'enleve de la combinaison
                surface->tab[i][j].couleur=surface->tab[i][j].couleur;
            }
        }
    }

    //On met les 20 pions c2
    cpt=20;                 //Je choisis de donner 20 couleurs au joueur.
    while(cpt>0){
        i=rand()%surface->hauteur;
        j=rand()%surface->largeur;
        couleurAct=surface->tab[i][j].couleur;
        if(couleurAct!=c1 && couleurAct!=c2){
            surface->tab[i][j].couleur=c2;
            if(Test_Combinaison(surface,i,j)==0){
                //Si le pion n'est pas dans une combinaison on le positionne
                cpt--;
            }
            else{//Sinon, on l'enleve de la combinaison
                surface->tab[i][j].couleur=couleurAct;
            }
        }
    }
}


//===================================
/**
    Cette fonction renvoie le nbre de fois
    qu'un jeton est présent sur le plateau de jeu
**/
int nombreCouleur(Plateau *surface, int coul)
{
    int cpt=0;

    for(int i=0 ; i<surface->hauteur ; i++){
        for(int j=0 ; j<surface->largeur ; j++){
            if(surface->tab[i][j].couleur==coul){
                cpt++;
            }
        }
    }
    return cpt;
}

//===================================
/**
    Cette fonction renvoie le nbre de de Jetons
    d'une certaine couleur qui sont dans une combinaison
**/
int PionsDuneCouleurEnCombinaison(Plateau *surface, int coul)
{
    int cpt=0;
     for(int i=0 ; i<NB_LIGNES ; i++){
        for(int j=0 ; j<NB_COLONNES ; j++){
            if(Test_Combinaison(surface,i,j) && surface->tab[i][j].couleur==coul){
               cpt+=1;
            }
        }
     }
     return cpt;
}


//===================================
/**
    Cette fonction permet de jouer une partie en
    multijoueur où chaque joueur a un Jeton spécifique
**/
void multi_joueur_couleur(Plateau *surface)
{
    srand(time(NULL));
    char coup[6];           //Contiendra la chaine de caractère du coup du joueur
    int xd,yd;              //Position de départ
    int x,y;                //Position d'arrivee
    char j1[100],j2[100];   //nom des joueurs
    int c1,c2;              //couleur des joueurs
    char im1,im2;           //Images des couleurs des joueurs
    int numTour=0;          //Indique le tour de jeu
    int cptJeu=0;           //A chaque fois que c'est le tour d'un joueur, on l'incréménte
    int tourDeJeu=rand();   //Cette variable nous permettra de sélectionner le joueur a qui est le tour.
    int nbPointsMax=3000;    //Nombre de points maximum à avoir avant l'adversaire pour remporter la partie
    int score1, score2;     //Scores des deux joueurs
    int sup1, sup2;         //Score supplémentaire des deux joueurs
    char vide[2];
    int nbPionsElimines;
    int PionsAdversesElimines;
    int k;
    score1=0;
    score2=0;

    system("cls"); //On efface la console
    //On enregistre les joueurs
    printf("\n\n\t\tBIENVENUE DANS LE MODE MULTIJOUEUR COULEUR\n\n");
    system("timeout 2 >nul");
    printf("\n\tDans cette partie, le premier a atteindre %d points \n\tou a supprimer tous les pions adverses gagne\n",nbPointsMax);
    system("timeout 1 >nul");

    printf("\n\n\n\tJoueur 1, veuillez entrez votre nom:  ");
    scanf("%s",&j1);
    printf("\n\n\n\tJoueur 2, veuillez entrez votre nom:  ");
    scanf("%s",&j2);

    system("cls");

    //Joueur 1 choisi sa couleur
    printf("\n\tVoici la liste des couleurs: \n\n");
    choixDesCouleurs();
    printf("\n\t[%s], veuillez choisir votre couleur: ",j1);
    scanf("%d",&c1);
    //Test sur la valeur entrée
    while(c1>surface->nbcouleur-1 || c1<0){
        printf("\n\n\tAppuyez sur une touche, puis sur ENTREE: ");
        scanf("%s",vide); //Cette variable recupere l'erreur produite
        system("cls");
        printf("\n\tVoici la liste des couleurs: \n\n");
        choixDesCouleurs();
        printf("\n\t[%s], veuillez entrer une valeur parmi celle ci-dessus: ",j1);
        scanf("%d",&c1);
    }
    im1=imageCouleur(c1);
    printf("\n\t[%s] vous avez chosisi la couleur [%c]\n",j1,im1);
    system("timeout 2 >nul");

    system("cls");

    //Joueur 2 choisi sa couleur
    printf("\n\tVoici la liste des couleurs: \n\n");
    choixDesCouleurs();
    printf("\n\t[%s] a chosisi la couleur [%c]\n",j1,im1);
    printf("\n\t[%s], Veuillez choisir votre couleur, \n\tcelle-ci doit etre differente de celle de [%s]: ",j2,j1);
    scanf("%d",&c2);
    //Test sur la valeur entrée
    while(c2>surface->nbcouleur-1 || c2<0 || c2==c1){
        printf("\n\n\tAppuyez sur une touche, puis sur ENTREE: ");
        scanf("%s",vide);
        system("cls");
        printf("\n\tVoici la liste des couleurs: \n\n");
        choixDesCouleurs();
        printf("\n\t[%s] a chosisi la couleur [%c]\n",j1,im1);
        printf("\n\n\tVeuillez entrer une valeur parmi celle ci-dessus \n\tet differente de celle de [%s]: ",j1);
        scanf("%d",&c2);
    }
    im2=imageCouleur(c2);
    printf("\n\t[%s] vous avez chosisi la couleur [%c]\n",j2,im2);
    system("timeout 2 >nul");

    system("cls");

    //On choisit le joueur qui commence la partie en utilisant notre variable tourDeJeu
    printf("\n\tTirage au sort du joueur qui va debuter la partie...");
    system("timeout 1 >nul"); printf("."); system("timeout 1 >nul"); printf(".\n\n\n\n");

    //On partage les couleurs des deux joueurs de manière égale dans le plateau.
    //Nombre de couleur fixé à 20.
    remplitNombreEgaleDeDeuxCouleur(surface, c1, c2 );
    Organiser_Plateau(surface); //On reorganise le plateau après remplissage

    if(tourDeJeu%2==0){
        printf("\tC'est [%s] qui a l'honneur de debuter la partie\n\n",&j1);
    }
    else{
        printf("\tC'est [%s] qui a l'honneur de debuter la partie\n\n",&j2);
    }
    system("timeout 3 >nul"); system("cls");

            /* DEBUT DE LA PARTIE */

    //On teste si les scores max sont atteints ou si tous les pions adverses sont supprimés
    while((nombreCouleur(surface,c1)!=0) && nombreCouleur(surface,c2)!=0 && score1<nbPointsMax && score2<nbPointsMax){
        system("cls");

        //S'il y a toujours des combinaisons après le remplissage precedent,
        //j'affiche le plateau, attribue les points et recomplete le plateau
        while(Test_Plateau_Organiser(surface)==0){
            printf("\n\n\t\t\tSUPPRESSION EN CASCADE\n\n");
            Affiche_Plateau(surface);
            if(tourDeJeu%2!=0){ //Si c'est le JOUEUR 1 qui vient de jouer
                printf("\n\n\t\t[%s] ===> SCORE: %d   LA CIBLE: [%c]   NBRE: %d\n",j1,score1,im2,nombreCouleur(surface,c2));
				printf("\n\t\tObjectif: %d\n", nbPointsMax);
				printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
				system("timeout 2 >nul");

				nbPionsElimines=nombreDePionsEnCombinaison(surface); //On recupère le nbre de jetons éliminés
                PionsAdversesElimines=PionsDuneCouleurEnCombinaison(surface,c2); //On recupère le nbre de jetons adverses éliminés
                k = Supprimer_Jeton(surface); //suppression des jetons
                system("cls");

                Affiche_Plateau(surface);
                printf("\n\n\t\t[%s] ===> SCORE: %d   LA CIBLE: [%c]   NBRE: %d\n",j1,score1,im2,nombreCouleur(surface,c2));
				printf("\n\t\tObjectif: %d\n", nbPointsMax);
                printf("\n\n\t\tApres cascade, [%s] elimine %d Jetons dont %d [%c]\n",j1,nbPionsElimines,PionsAdversesElimines,im2);
                sup1 = 100 * (nbPionsElimines - PionsAdversesElimines) + (PionsAdversesElimines * 2 * 100);
                printf("\n\n\t\tScore supplementaire: +%d",sup1);
                score1 = score1 + sup1;
            }
            else{ //Si c'est le JOUEUR 2 qui vient de jouer
                printf("\n\n\t\t[%s] ===> SCORE: %d   LA CIBLE: [%c]   NBRE: %d\n",j2,score2,im1,nombreCouleur(surface,c1));
                printf("\n\t\tObjectif: %d\n", nbPointsMax);
                printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
				system("timeout 2 >nul");

                nbPionsElimines=nombreDePionsEnCombinaison(surface);
                PionsAdversesElimines=PionsDuneCouleurEnCombinaison(surface,c1);
                k=Supprimer_Jeton(surface); //suppression des jetons
                system("cls");

                Affiche_Plateau(surface);
                printf("\n\n\t\t[%s] ===> SCORE: %d   LA CIBLE: [%c]   NBRE: %d\n",j2,score2,im1,nombreCouleur(surface,c1));
                printf("\n\t\tObjectif: %d\n", nbPointsMax);
                printf("\n\n\t\tApres cascade, [%s] elimine %d Jetons dont %d [%c]\n",j2,nbPionsElimines,PionsAdversesElimines,im1);
                sup2 = 100 * (nbPionsElimines - PionsAdversesElimines) + (PionsAdversesElimines * 2 * 100);
                printf("\n\n\t\tScore supplementaire: +%d",sup2);
                score2 = score2 + sup2;
            }
            Completer_Plateau(surface);
            system("timeout 3 >nul");
            system("cls");
        }

        Affiche_Plateau(surface);

        // Mise a zero du coup precedent
        xd = yd = x = y = -1;

        //Affichage des données des joueurs
        printf("\n\t\t[%s] ===> SCORE: %d   LA CIBLE: [%c]   NBRE: %d",j1,score1,im2,nombreCouleur(surface,c2));
		printf("\n\t\t[%s] ===> SCORE: %d   LA CIBLE: [%c]   NBRE: %d\n",j2,score2,im1,nombreCouleur(surface,c1));
		printf("\n\t\tObjectif: %d\n", nbPointsMax);

        printf("\n\tNB: Eliminer toutes vos cibles ==> VICTOIRE\n");
        printf("\tEliminer vos cibles vous donne le double du score obtenu\n");
        //Affichage du joueur qui doit jouer
        printf("\n\t\tA qui le tour: ====> ");
        if(tourDeJeu%2==0){
            printf("%s <====\n",j1);
        }
        else {
            printf("%s <====\n",j2);
        }

        //Saisie du deplacement a effectuer
        printf("\n\tPour revenir au menu principal, taper \"M\"");
        printf("\n\tPour visualiser l'aide, taper \"A\" \n");
        printf("\n\tQue souhaitez vous jouer? : ");
        scanf("%s",coup);

        if(strcmp(coup,"M")==0){
            free(surface);
            int sup1 = main();
            break;
        }
        else if(strcmp(coup, "A") == 0){
            //Help_Multi(surface,'N');
            system("cls");
            AIDE();
            system("pause >nul");
            //décrémentaion du tour de jeu et du compteur de jeu
			tourDeJeu -= 1;
			cptJeu -= 2;
			numTour -= 1;
		}
        else{
            //On recupere l'ordonnee du pion a deplacer
            if(coup[0]=='a' || coup[0]=='A') yd = 0;
            else if(coup[0]=='b' || coup[0]=='B') yd = 1;
            else if(coup[0]=='c' || coup[0]=='C') yd = 2;
            else if(coup[0]=='d' || coup[0]=='D') yd = 3;
            else if(coup[0]=='e' || coup[0]=='E') yd = 4;
            else if(coup[0]=='f' || coup[0]=='F') yd = 5;
            else if(coup[0]=='g' || coup[0]=='G') yd = 6;
            else if(coup[0]=='h' || coup[0]=='H') yd = 7;
            else if(coup[0]=='i' || coup[0]=='I') yd = 8;
            else if(coup[0]=='j' || coup[0]=='J') yd = 9;

            //48 correspond au caractere zero '0': on aurait pu faire (int)coup - '0'
            xd = ((int)coup[1] - 48) * 10 + ((int)coup[2] - 48); //On recupere l'abscisse du pion a deplacer

            //On recupere les coordonnees de la destination
            if(coup[4]=='h'||coup[4]=='H'){
                y = yd;
                x = xd - 1;
            }
            else if(coup[4]=='D' || coup[4]=='d'){
                y = yd + 1;
                x = xd;
            }
            else if(coup[4]=='G' || coup[4]=='g'){
                y = yd - 1;
                x = xd;
            }
            else if(coup[4]=='B' || coup[4]=='b'){
                y = yd;
                x = xd + 1;
            }

            //Test sur les coordonnees entrees: xd,x €[1;15] et yd,y €[0;9]
            if(coup[3]!='-' || yd<0 || yd>surface->largeur-1 || xd<1 || xd>surface->hauteur
               || y<0 || y>surface->largeur-1 || x<1 || x>surface->hauteur){
                printf("\n\n\tDeplacement Impossible!\n\n");
                system("timeout 2 >nul");
            }
            else{
                xd--; //On recupere les valeurs reelles de xd et x
                x--;  //en fonction de la structure du plateau de jeu
                Echanger_Position(surface,xd,yd,x,y); //On échange les positions des jetons
                if(Test_Combinaison(surface,x,y)==1 || Test_Combinaison(surface,xd,yd)==1){
                    if(tourDeJeu%2==0){
                        printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
                        system("timeout 2 >nul");

                        nbPionsElimines=nombreDePionsEnCombinaison(surface);
                        PionsAdversesElimines=PionsDuneCouleurEnCombinaison(surface,c2);
                        k = Supprimer_Jeton(surface); //suppression des jetons
                        system("cls");
                        Affiche_Plateau(surface);

                        printf("\n\n\t\t[%s] ===> SCORE: %d    LA CIBLE: [%c]   NBRE: %d\n",j1,score1,im2,nombreCouleur(surface,c2));
                        printf("\n\t\tObjectif: %d\n", nbPointsMax);
                        printf("\n\n\t\t[%s] elimine %d Jetons dont %d [%c]\n",j1,nbPionsElimines,PionsAdversesElimines,im2);
                        sup1 = 100 * (nbPionsElimines - PionsAdversesElimines) + (PionsAdversesElimines * 2 * 100);
                        printf("\n\n\t\tScore supplementaire: +%d",sup1);
                        score1 = score1 + sup1;
                    }
                    else{
                         printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
                         system("timeout 2 >nul");

                         nbPionsElimines=nombreDePionsEnCombinaison(surface);
                         PionsAdversesElimines=PionsDuneCouleurEnCombinaison(surface,c1);
                         k=Supprimer_Jeton(surface); //suppression des jetons
                         system("cls");
                         Affiche_Plateau(surface);

                         printf("\n\n\t\t[%s] ===> SCORE: %d    LA CIBLE: [%c]   NBRE: %d\n",j2,score2,im1,nombreCouleur(surface,c1));
                         printf("\n\t\tObjectif: %d\n", nbPointsMax);
                         printf("\n\n\t\t[%s] elimine %d Jetons dont %d [%c]\n",j2,nbPionsElimines,PionsAdversesElimines,im1);
                         sup2 = 100 * (nbPionsElimines - PionsAdversesElimines) + (PionsAdversesElimines * 2 * 100);
                         printf("\n\n\t\tScore supplementaire: +%d",sup2);
                         score2 = score2 + sup2;
                    }
                    //ON COMPLETE LE PLATEAU A CE STADE APRES SUPRESSION
                    Completer_Plateau(surface);
                    system("timeout 4 >nul");
                    system("cls");
                }
                else{//S'il n'y a pas de combinaison possible
                    printf("\n\tPas de combinaison valide! \n");
                    printf("\n\tScore supplementaire: 0");
                    system("timeout 2 >nul");
                    Echanger_Position(surface,xd,yd,x,y); //On remet les jetons a leur position d'origine
                }
            }
        }
            system("cls");
            //incrémentaion du tour de jeu et du compteur de jeu
            tourDeJeu+=1;
            cptJeu+=1;
    }

    /*
        ------------AFFICHAGE DU VAINQUEUR---------
    */

    system("cls");
    if(score1>=nbPointsMax){
        Affiche_Plateau(surface);
        printf("\n\n\t\tLe grand vainqueur est: [%s].",j1);
        printf("\n\t\tSoit, %d points d'avance sur son adversaire direct",abs(score1-score2));
        printf("\n\n\t\tSCORE de [%s]  :%d\n",j1,score1);
        printf("\t\tSCORE de [%s]  :%d\n\n",j2,score2);
    }
    if(score2>=nbPointsMax){
        Affiche_Plateau(surface);
        printf("\n\n\t\tLe grand vainqueur est: [%s].",j2);
        printf("\n\t\tSoit, %d points d'avance sur son adversaire direct",abs(score1-score2));
        printf("\n\n\t\tSCORE de [%s]  :%d\n",j1,score1);
        printf("\t\tSCORE de [%s]  :%d\n\n",j2,score2);
    }
    if(nombreCouleur(surface,c2)==0){
        printf("\n\n\t\tLe grand vainqueur est: [%s].\n",j1);
        printf("Il a pu supprimer tous les Jetons [%c] adverses.\n",im2);
        printf("Regardez ce magnifique tableau ne contenant aucun Jeton [%c]\n\n",im2);
        Affiche_Plateau(surface);
    }
    if(nombreCouleur(surface,c1)==0){
        printf("\n\n\t\tLe grand vainqueur est: [%s].\n",j2);
        printf("Il a pu supprimer tous les Jetons [%c] adverses.\n",im1);
        printf("Regardez ce magnifique tableau ne contenant aucun Jeton [%c]\n\n",im1);
        Affiche_Plateau(surface);
    }

    printf("\t\tAppuyez sur une touche pour quitter: "); system("pause >nul");
	sup1 = main();
        /** FIN MULTIJOUEUR AVEC COULEUR **/
}

//         --------------------------------------------------------------
//        |              MULTIJOUEUR AVEC CARTES SPECIALES               |
//         --------------------------------------------------------------

//===================================
/**
    Cette fonction permet de jouer une partie en
    multijoueur avec des cartes spéciales
**/
void multi_joueur_carte(Plateau *surface)
{
    int i, j;
	int xd, yd;                  //Position de départ
	int x, y;                    //Position d'arrivee
	char coup[6];               //Contiendra la chaine de caractère du coup du joueur
	int option = -1;
	int numTour = 0;              //Indique le tour de jeu
	int cptJeu = 0;               //A chaque fois quue c'est le tour d'un joueur, on l'incréménte
	char j1[100], j2[100];
	int tourDeJeu = rand();       //Cette variable nous permettra de sélectionner le joueur a qui est le tour.
	int nbPointsMax = 800;            //Nombre de points maximum à avoir avant l'adversaire pour remporter la partie
	int sup1, sup2;             //Score supplémentaire des deux joueurs
	int scoreJ1 = 0;			//score du joueur1
	int scoreJ2 = 0;			//score du joueur 2
	Pile PileCarte = NULL;
	Cartes cartePiochee;
	int nbCarteJ1 = 3;			//nombre carte que le joueur 1 a le droit de piocher
	int nbCarteJ2 = 3;			//nombre carte que le joueur 2 a le droit de piocher
	int tour = 0;
	Jeton tmp;

	//On crée une pile de cartes puis on la remplit
	PileCarte = Creer_Pile();
	PileCarte = RemplirPile(PileCarte, NB_CARTE_MULTI);

	system("cls");
	printf("\n\n\t  BIENVENUE DANS LE MODE MULTIJOUEUR AVEC CARTES SPECIALES\n");
	system("timeout 2 >nul");
	printf("\n\n\n\tJoueur 1, veuillez entrez votre nom:  ");
	scanf("%s", &j1);
	printf("\n\n\n\tJoueur 2, veuillez entrez votre nom:  ");
	scanf("%s", &j2);

	system("cls");

	//On choisit le joueur qui commence la partie en utilisant notre variable tourDeJeu
	printf("\n\n\tTirage au sort du joueur qui va debuter la partie...");
	system("timeout 1 >nul"); printf(".");
	if (tourDeJeu % 2 == 0) {
		printf("\n\n\n\n\n\tC'est [%s] qui a l'honneur de debuter la partie la partie", &j1);
	}
	else {
		printf("\n\n\n\n\n\tC'est [%s] qui a l'honneur de debuter la partie la partie", &j2);
	}
	system("timeout 4 >nul"); system("cls");

            /*  DEBUT DE LA PARTIE */

	//On teste si les scores max ne sont pas atteints
	while (scoreJ1 < nbPointsMax && scoreJ2 < nbPointsMax) {
		system("cls"); /* On efface la console */

        //Tant que le plateau contient des alignements on les élimine
		while (Test_Plateau_Organiser(surface) == 0) {
			printf("\t\t\tSUPPRESSION EN CASCADE\n\n");
			Affiche_Plateau(surface);
			if (tourDeJeu % 2 != 0) {
				printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j1, scoreJ1, nbCarteJ1);
				printf("\n\t\tObjectif: %d\n", nbPointsMax);
				printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
				system("timeout 2 >nul");
				sup1 = Supprimer_Jeton(surface);

				system("cls");
				Affiche_Plateau(surface);
				printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j1, scoreJ1, nbCarteJ1);
				printf("\n\t\tObjectif: %d\n", nbPointsMax);
				scoreJ1 = scoreJ1 + sup1;
				printf("\n\n\t\tScore supplementaire: +%d", sup1);
			}
			else {
				printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j2, scoreJ2, nbCarteJ2);
				printf("\n\t\tObjectif: %d\n", nbPointsMax);
				printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
				system("timeout 2 >nul");
				sup2 = Supprimer_Jeton(surface);

				system("cls");
				Affiche_Plateau(surface);
				printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j2, scoreJ2, nbCarteJ2);
				printf("\n\t\tObjectif: %d\n", nbPointsMax);
				scoreJ2 = scoreJ2 + sup2;
				printf("\n\n\t\tScore supplementaire: +%d", sup2);
			}
			system("timeout 3 >nul");
			Completer_Plateau(surface);
			system("cls");
		}

		Affiche_Plateau(surface);

		// Mise a zero du coup precedent
		xd = yd = x = y = -1;

		//Affichage des données des joueurs
		printf("\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j1, scoreJ1, nbCarteJ1);
		printf("\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j2, scoreJ2, nbCarteJ2);
		printf("\n\t\tObjectif: %d\n", nbPointsMax);

		//Affichage du joueur qui doit jouer
		printf("\n\t\tA qui le tour: ====> ");
		if (tourDeJeu % 2 == 0) {
			printf("%s <====\n", j1);
		}
		else {
			printf("%s <====\n", j2);
		}

		//Saisie du deplacement a effectuer
		printf("\n\tPour revenir au Menu Principal, taper \"M\"\n");
		printf("\tPour visualiser l'aide, taper \"A\" \n");
		printf("\tPour tirer une Carte, taper \"T\" (cout: 2 deplacements)\n");

		//On saisit le deplacement a effectuer
		printf("\n\tQue souhaitez vous jouer? : ");
		scanf("%s", coup);

		if ((strcmp(coup, "T") == 0) || (strcmp(coup, "t") == 0)) //Si resultat vaut 0 ==> ON PIOCHE UNE CARTE
		{
			if (tourDeJeu % 2 == 0) {
				tour = 0;
			}
			else {
				tour = 1;
			}

            //s'il n'y a plus de cartes, passe directement au tour supplémentaire
			if ((tour == 0) && (nbCarteJ1 == 0) || (tour == 1) && (nbCarteJ2 == 0))
			{
				printf("\n\tVous n'avez plus assez de carte ou de deplacement.\n");
				system("timeout 2 >nul");
			}
			else{ //on pioche la carte dans la pile
				cartePiochee = piocherCarte(PileCarte);
				PileCarte = depiler(PileCarte);
				printf("\n\n");

				switch (cartePiochee) {	//selon la carte piochée
                    case UN: //rechargement du plateau
                             surface = Recharge_Plateau(surface);
                             break;
                    case DEUX: //score multiplié par X
                               if (tourDeJeu % 2 == 0)
                                   scoreJ1 = multiplieScore(scoreJ1);
                               else
                                   scoreJ2 = multiplieScore(scoreJ2);
                               break;
                    case TROIS: //pions spéciaux
                                printf("\tAPPARITION DE PIONS SPECIAUX\n");
                                system("timeout 3 >nul");
                                surface = placePionsSpeciaux(surface);
                                break;
                    case QUATRE: // MALUS -100 points
                                 printf("\tMALUS -100 POINTS\n");
                                 system("timeout 3 >nul");
                                 if (tourDeJeu % 2 == 0)
                                     scoreJ1 -= 100;
                                 else
                                     scoreJ2 -= 100;
                                 break;
                    case CINQ: // + 100 points
                               printf("\t+100 POINTS\n");
                               system("timeout 3 >nul");
                               if (tourDeJeu % 2 == 0)
                                   scoreJ1 += 100;
                               else
                                   scoreJ2 += 100;
                               break;
                    default: break;
				}

				if (tourDeJeu % 2 == 0)
					nbCarteJ1--;
				else
					nbCarteJ2--;
			}
		}

		if (strcmp(coup, "M") == 0) { //On retourne au menu principal
			free(surface);
			int sup1 = main();
			break;
		}
		else if(strcmp(coup, "A") == 0){
            //Help_Multi(surface,'N');
            system("cls");
            AIDE();
            system("pause >nul");
            //décrémentaion du tour de jeu et du compteur de jeu
			tourDeJeu -= 2;
			cptJeu -= 2;
			numTour -= 1;
		}
		else if ((strcmp(coup, "T") != 0) && (strcmp(coup, "t") != 0)) {
			//On recupere l'ordonnee du pion a deplacer
			if (coup[0] == 'a' || coup[0] == 'A') yd = 0;
			else if (coup[0] == 'b' || coup[0] == 'B') yd = 1;
			else if (coup[0] == 'c' || coup[0] == 'C') yd = 2;
			else if (coup[0] == 'd' || coup[0] == 'D') yd = 3;
			else if (coup[0] == 'e' || coup[0] == 'E') yd = 4;
			else if (coup[0] == 'f' || coup[0] == 'F') yd = 5;
			else if (coup[0] == 'g' || coup[0] == 'G') yd = 6;
			else if (coup[0] == 'h' || coup[0] == 'H') yd = 7;
			else if (coup[0] == 'i' || coup[0] == 'I') yd = 8;
			else if (coup[0] == 'j' || coup[0] == 'J') yd = 9;


			//48 correspond au caractere zero '0': on aurait pu faire (int)coup - '0'
			xd = ((int)coup[1] - 48) * 10 + ((int)coup[2] - 48); //On recupere l'abscisse du pion a deplacer

            //On recupere les coordonnees de la destination
			if (coup[4] == 'h' || coup[4] == 'H') {
				y = yd;
				x = xd - 1;
			}
			else if (coup[4] == 'D' || coup[4] == 'd') {
				y = yd + 1;
				x = xd;
			}
			else if (coup[4] == 'G' || coup[4] == 'g') {
				y = yd - 1;
				x = xd;
			}
			else if (coup[4] == 'B' || coup[4] == 'b') {
				y = yd;
				x = xd + 1;
			}

			//Test sur les coordonnees entrees: xd,x €[1;15] et yd,y €[0;9]
			if (coup[3]!='-' || yd<0 || yd>surface->largeur - 1 || xd<1 || xd>surface->hauteur
				|| y<0 || y>surface->largeur - 1 || x<1 || x>surface->hauteur) {
				printf("\n\n\tDeplacement impossible!\n\n");
				system("timeout 2 >nul");
			}
			else {
				xd--; //On recupere les valeurs reelles de xd et x
				x--;  //en fonction de la structure du plateau de jeu
				Echanger_Position(surface, xd, yd, x, y); //On échange les positions des jetons

				if (surface->tab[x][y].couleur == 11 || surface->tab[xd][yd].couleur == 11) //1er tri: l'un des pions est un pion special
				{
					if (surface->tab[x][y].couleur == 11 && surface->tab[xd][yd].couleur != 11) {
						//le premier Jeton est un jeton special, le second est un jeton normal
						surface = utilisationPionSpecial(surface, xd, yd);
						if (tourDeJeu % 2 == 0) { //JOUEUR 1
							scoreJ1 += surface->score;
							surface->score = 0;
						}
						else
						{
							scoreJ2 += surface->score;
							surface->score = 0;
						}
						surface->tab[x][y].couleur = 'E'; //E: signifie espace vide
						Completer_Plateau(surface);
					}
					else if (surface->tab[x][y].couleur != 11 && surface->tab[xd][yd].couleur == 11) {
						//le second pion est un pion special, le premier est un pion normal
						surface = utilisationPionSpecial(surface, x, y);
						if (tourDeJeu % 2 == 0) { //JOUEUR 1
							scoreJ1 += surface->score;
							surface->score = 0;
						}
						else
						{
							scoreJ2 += surface->score;
							surface->score = 0;
						}
						surface->tab[xd][yd].couleur = 'E';
						Completer_Plateau(surface);
					}
					if (surface->tab[x][y].couleur == 11 && surface->tab[xd][yd].couleur == 11) { //cas du melange de 2 pions speciaux
						if (tourDeJeu % 2 == 0) //JOUEUR 1
							scoreJ1 += 500;
						else
							scoreJ2 += 500;

						surface = Recharge_Plateau(surface); //on recharge le plateau complet
					}
				}

				if (Test_Combinaison(surface, x, y) == 1 || Test_Combinaison(surface, xd, yd) == 1) {
					//Attribution du score au joueur:
					if (tourDeJeu % 2 == 0) { //JOUEUR 1
						if (Test_4Jetons_Alignes(surface, x, y) == 1 || Test_4Jetons_Alignes(surface, xd, yd) == 1) {
							//si l'un des jeton ets dans un alignement de 4
							if (Test_4Jetons_Alignes(surface, x, y) == 1) { // si c'est le premier jeton
								tmp.couleur = surface->tab[x][y].couleur; //on enregistre la couleur du jeton (x,y)
								int nbPionsElimines = nombreDePionsEnCombinaison(surface);
                                printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
								sup1 = Supprimer_Jeton(surface);
								system("timeout 2 >nul");

                                system("cls");
                                Affiche_Plateau(surface);
                                printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j1, scoreJ1, nbCarteJ1);
                                printf("\n\t\tObjectif: %d\n", nbPointsMax);
								printf("\n\t\t[%s] elimine %d Jetons \n", j1, nbPionsElimines);
								printf("\n\n\t\tScore supplementaire: +%d", sup1);

								system("timeout 2 >nul");
								Remplacer_Forme(surface, x, y, tmp); //on remplace le jeton en position (x,y) par un jeton special de la bonne couleur
								Completer_Plateau(surface); //on regenere le plateau
								scoreJ1 = scoreJ1 + sup1;
							}
							//Si c'est le 2eme jeton
							if (Test_4Jetons_Alignes(surface, xd, yd) == 1) {
								tmp.couleur = surface->tab[xd][yd].couleur;//on sauve la couleur du jeton (xd,yd)
								int nbPionsElimines = nombreDePionsEnCombinaison(surface);
                                printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
								sup1 = Supprimer_Jeton(surface);
								system("timeout 2 >nul");

                                system("cls");
                                Affiche_Plateau(surface);
                                printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j1, scoreJ1, nbCarteJ1);
                                printf("\n\t\tObjectif: %d\n", nbPointsMax);
								printf("\n\t\t[%s] elimine %d Jetons \n", j1, nbPionsElimines);
								printf("\n\n\t\tScore supplementaire: +%d", sup1);

								system("timeout 2 >nul");
								Remplacer_Forme(surface, xd, yd, tmp);//on remplace le jeton en position (xd,yd) par un jeton special de la bonne couleur
								Completer_Plateau(surface);
								scoreJ1 = scoreJ1 + sup1;
							}
						}
						else { //Si aucun des jetons ne crée une combinaison de 4
							int nbPionsElimines = nombreDePionsEnCombinaison(surface);
                            printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
							sup1 = Supprimer_Jeton(surface);
							system("timeout 2 >nul");

                            system("cls");
                            Affiche_Plateau(surface);
                            printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j1, scoreJ1, nbCarteJ1);
                            printf("\n\t\tObjectif: %d\n", nbPointsMax);
							printf("\n\t\t[%s] elimine %d pions \n", j1, nbPionsElimines);
							printf("\n\n\t\tScore supplementaire: +%d", sup1);

							system("timeout 2 >nul");
							Completer_Plateau(surface);
							scoreJ1 = scoreJ1 + sup1;
						}

					}
					else { // JOUEUR 2
						if (Test_4Jetons_Alignes(surface, x, y) == 1 || Test_4Jetons_Alignes(surface, xd, yd) == 1) {
							//si l'un des jeton est dans un alignement de 4 :
							//Si c'est le 1er jeton
							if (Test_4Jetons_Alignes(surface, x, y) == 1) {
								tmp.couleur = surface->tab[x][y].couleur; //on retient la couleur du jeton (x,y)
								int nbPionsElimines = nombreDePionsEnCombinaison(surface);
                                printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
								sup2 = Supprimer_Jeton(surface);
								system("timeout 2 >nul");

								system("cls");
								Affiche_Plateau(surface);
								printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j2, scoreJ2, nbCarteJ2);
								printf("\n\t\tObjectif: %d\n", nbPointsMax);
								printf("\n\t\t[%s] elimine %d pions \n", j2, nbPionsElimines);
								printf("\n\n\t\tScore supplementaire: +%d", sup2);

								system("timeout 2 >nul");
								Remplacer_Forme(surface, x, y, tmp); //on remplace le jeton en position (x,y) par un jeton special de la bonne couleur
								Completer_Plateau(surface); //on regenere le plateau
								scoreJ2 = scoreJ2 + sup2;
							}
							//Si c'est le 2eme jeton
							if (Test_4Jetons_Alignes(surface, xd, yd) == 1) {
								tmp.couleur = surface->tab[xd][yd].couleur;//on retient la couleur du jeton (xd,yd)
								int nbPionsElimines = nombreDePionsEnCombinaison(surface);
                                printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
								sup2 = Supprimer_Jeton(surface);
								system("timeout 2 >nul");

								system("cls");
								Affiche_Plateau(surface);
								printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j2, scoreJ2, nbCarteJ2);
								printf("\n\t\tObjectif: %d\n", nbPointsMax);
								printf("\n\t\t[%s] elimine %d pions \n", j2, nbPionsElimines);
								printf("\n\n\t\tScore supplementaire: +%d", sup2);

								system("timeout 2 >nul");
								Remplacer_Forme(surface, xd, yd, tmp);//on remplace le jeton en position (xd,yd) par un jeton special de la bonne couleur
								Completer_Plateau(surface);
								scoreJ2 = scoreJ2 + sup2;
							}
						}
						else { // Si aucun des jetons ne crée une combinaison de 4
							int nbPionsElimines = nombreDePionsEnCombinaison(surface);
                            printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
							sup2 = Supprimer_Jeton(surface);
							system("timeout 2 >nul");

							system("cls");
							Affiche_Plateau(surface);
							printf("\n\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j2, scoreJ2, nbCarteJ2);
							printf("\n\t\tObjectif: %d\n", nbPointsMax);
							printf("\n\t\t[%s] elimine %d pions \n", j2, nbPionsElimines);
							printf("\n\n\t\tScore supplementaire: +%d", sup2);

							system("timeout 2 >nul");
							Completer_Plateau(surface);
							scoreJ2 = scoreJ2 + sup2;
						}
					}

				}
				else {//S'il n'y a pas de combinaison possible
					printf("\n\tPas de combinaison valide! \n");
					printf("\n\tScore supplementaire: 0");
					system("timeout 2 >nul");
					Echanger_Position(surface, xd, yd, x, y); //On remet les jetons a leur position d'origine
				}
			}
		}
		//incrémentaion du tour de jeu et du compteur de jeu
		tourDeJeu += 1;
		system("cls");
	}

	/*
	------------AFFICHAGE DU VAINQUEUR---------
	*/
	system("cls");
	printf("\n\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j1, scoreJ1, nbCarteJ1);
    printf("\t\t[%s] ===>\tSCORE:%d \tCARTES:%d\n", j2, scoreJ2, nbCarteJ2);
    printf("\n\t\tObjectif: %d\n", nbPointsMax);

	if (scoreJ1 >= nbPointsMax) {
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tLe grand vainqueur est: [%s], avec un score de %d", j1, scoreJ1);
	}
	else {
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tLe grand vainqueur est: [%s], avec un score de %d", j2, scoreJ2);
	}
	printf("\n\t\t\t\tSoit, %d points d'avance sur son adversaire direct\n\n", abs(scoreJ1 - scoreJ2));

	printf("\t\tAppuyez sur une touche pour quitter: "); system("pause >nul");
	sup1 = main();

        /** FIN MULTIJOUEUR AVEC CARTES **/
}
