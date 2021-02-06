/**
#############################################################################
#    PROTOTYPE DES FONCTIONS UTILISEES POUR UNE PARTIE AVEC CARTES          #
#############################################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "plateau.h"
#include "messages.h"
#include "outils.h"
#include "jeu.h"
#include "cartes.h"

//===================================
/**
    Cette fonction crée et retourne une pile vide
**/
Pile Creer_Pile()
{
	Pile P = NULL;
	P = malloc(sizeof(struct Cellule));
	return P;
}


//===================================
/**
    Cette fonction teste si une pile est vide
    Elle renvoie
    1 : si elle est vide
    0 : si elle n'est pas vide
*/
int EstpileVide(Pile P)
{
	if (P == NULL) return 1;
	else return 0;
}


//===================================
/**
    Cette fonction permet d'ajouter une carte
    dans la pile (ajout en tête de pile)
**/
Pile empiler(Pile p, Cartes c)
{
	Pile nvlleCell = (struct Cellule*)malloc(sizeof(struct Cellule));
	nvlleCell->val = c;
	nvlleCell->suiv = p;
	return nvlleCell;
}


//===================================
/**
    Cette fonction permet de retirer un élément
    de la pile (retrait en tête de pile)
**/
Pile depiler(Pile P)
{
    Pile eltEnleve = P;
    if(!EstpileVide(P)){
        P = P->suiv;
        free(eltEnleve);
    }
	return P;
}


//===================================
/**
    Cette fonction génère une carte de
    manière alèatoire
**/
Cartes genereCarte()
{
	Cartes c;
	c = rand() % (NB_TYPE_CARTES) + 1;
	return c;
}


//===================================
/**
    Cette fonction remplit la pile de cartes
    avec NB_CARTE cartes aléatoirement
**/
Pile RemplirPile(Pile p, int nbCartes)
{
	int i=0;
	Cartes c;
    while (i < nbCartes)
    {
        c=genereCarte();
        p=empiler(p,c);
        i++;
    }
	return p;
}


//===================================
/**
    Cette fonction permet de piocher une
    carte dans la pile de cartes
**/
Cartes piocherCarte(Pile p)
{
	return p->val;
}


//===================================
/**
    Cette fonction permet de recharger le plateau de jeu
    en conservant toutes les autres données (score, deplacements restants,...)
**/
Plateau *Recharge_Plateau(Plateau *surface)
{
	Plateau *PlateauRecharge;
	printf("\n\n\t\tRECHARGEMENT DU PLATEAU\n");
	system("timeout 3 >nul");

	PlateauRecharge = Creation_Plateau(surface->hauteur,surface->largeur);
	Remplir_Plateau(PlateauRecharge, surface->nbcouleur, surface->deplacement);
	Organiser_Plateau(PlateauRecharge);
	surface->tab = PlateauRecharge->tab;
	free(PlateauRecharge);

	return surface;
}


//===================================
/**
    Cette fonction multiplie le score par 1 + une valeur tirée aléatoirement
    entre 0 et 99 divisée par 100 (on multiplie par une valeur comprise entre 1.00 et 1.99)
**/
int *multiplieScore(int score)
{
	float multiplicateur = 0.0;
	float pourcentageMult = 0.0;

	pourcentageMult = rand() % 100;
	multiplicateur = (1 + (pourcentageMult / 100));
	printf("\tMULTIPLICATEUR x%f !!!\n", multiplicateur);
	system("timeout 3 >nul");
	score = score * multiplicateur;

	return score;
}

//===================================
/**
    Cette fonction place des jetons de manière
    aléatoire sur le plateau de jeu
**/
Plateau *placePionsSpeciaux(Plateau *surface)
{
	int nbPionsRemplace=5;
	int i, j;
	while (nbPionsRemplace > 0)
	{
		i = rand() % surface->hauteur;
		j = rand() % surface->largeur;
		surface->tab[i][j].couleur = 11;
		nbPionsRemplace--;
	}
	return surface;
}

//===================================
/**
    Cette fonction fait disparaitre tous les jetons de même couleur
    que celui avec lequel est combiné le jeton special
**/
Plateau *utilisationPionSpecial(Plateau *surface, int x, int y)
{
	int compteurNbPionDisparu = 0;
	int i, j;
	Jeton tmp;

	tmp.couleur = surface->tab[x][y].couleur;

	for (i = 0; i < surface->hauteur; i++) {
		for (j = 0; j < surface->largeur; j++) {
			if (surface->tab[i][j].couleur == tmp.couleur) {
				//si le Jeton courant est de la meme couleur que le jeton
				//combiné avec le jeton special, on l'élimine (marque)
				surface->tab[i][j].couleur = 'E';
				compteurNbPionDisparu++;
			}
		}
	}
	surface->score += 10 * compteurNbPionDisparu;
	return surface;
}

//===================================
/**
    Cette fonction permet de jouer une partie
    en solo avec des cartes spéciales
**/
void Jouer_Partie_Cartes(Plateau *surface)
{
    int i, j, sup;
	char erreur[2];
	int xd, yd;                 //Position de départ
	int x, y;                   //Position d'arrivee
	char ok[2];                 //Reponse du deplacement
	char coup[6];               //Deplacement à effectuer
	Plateau *surfacePred;       //clone du plateau de jeu
	int option = -1;
	int arriere = -1;
	Jeton tmp;
	Pile PileCarte;
	Cartes cartePiochee;
	int nbCarte = 3;

	//On crée la pile de cartes et on la remplit
	PileCarte = Creer_Pile();
	PileCarte = RemplirPile(PileCarte, NB_CARTE);

    //On clone notre plateau de jeu
    surfacePred = clone_Plateau(surface);

	while (surface->deplacement > 0) {
		system("cls"); /* Efface l'écran */
		while (Test_Plateau_Organiser(surface) == 0) {
			Affiche_Plateau(surface);
			printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n\n", surface->deplacement, surface->score, nbCarte);
			printf("\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
			system("timeout 2 >nul");

			system("cls");
			Affiche_Plateau(surface);
			printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n\n", surface->deplacement, surface->score, nbCarte);
			sup = Supprimer_Jeton(surface);
			printf("\n\t\tScore supplementaire: +%d", sup);

			system("timeout 2 >nul");
			surface->score += sup;
			Completer_Plateau(surface);
			system("cls");
		}

		Affiche_Plateau(surface);
		printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);

		// Mise a zero du coup precedent
		xd = yd = x = y = -1;

		printf("\n\n\tPour visualiser les options, taper \"O\"\n");
		printf("\n\tPour tirer une carte, taper \"T\" [cout: 2 deplacements]\n");
		printf("\tPour revenir en arriere, taper \"R\" [cout: 2 deplacements et 100pts]\n");

		//Saisie du deplacement a effectuer
		printf("\n\n\tQue jouez-vous? : ");
		scanf("%s", coup);

		//Test sur les valeurs saisie

		option = (strcmp(coup, "O") == 0); //Si resultat vaut 0 ==> ON AFFICHE LE MENU DES OPTIONS
        arriere = (strcmp(coup,"R")==0); //Si resultat vaut 0 ==> ON REVIENT AU COUP PRECEDENT

		if (strcmp(coup, "T") == 0) //Si resultat vaut 0 ==> ON PIOCHE UNE CARTE
		{
			if ((nbCarte == 0) || (surface->deplacement < 2)) //s'il n'y a plus de cartes, passe directement au tour supplémentaire
			{
				printf("\n\tVous n'avez plus assez de carte ou de deplacement.\n");
				system("timeout 2 >nul");
			}
			else
			{
				//on pioche la carte dans la pile
				cartePiochee = piocherCarte(PileCarte);
				PileCarte = depiler(PileCarte);
				printf("\n\n");

				switch (cartePiochee) //selon la carte piochée
				{
                    case UN: //rechargement du plateau
                             surface = Recharge_Plateau(surface);
                             break;
                    case DEUX: //score multiplié par X
                                surface->score = multiplieScore(surface->score);
                                break;
                    case TROIS: //pions spéciaux
                                printf("\n\n\t\tAPPARITION DE PIONS SPECIAUX\n");
                                system("timeout 3 >nul");
                                surface = placePionsSpeciaux(surface);
                                break;
                    case QUATRE: // déplacements supplémentaires
                                printf("\n\n\t\tDEPLACEMENTS SUPPLEMENTAIRES\n");
                                system("timeout 3 >nul");
                                surface->deplacement = surface->deplacement + 5;
                                break;
                    case CINQ: // + 100 points
                                printf("\n\n\t\t+100 POINTS\n");
                                system("timeout 3 >nul");
                                surface->score = surface->score + 100;
                                break;
                    default: break;
				}
				surface->deplacement = surface->deplacement - 2; //Cout du tirage d'une carte : 2 déplacements
				nbCarte--;
			}
		}

		if ((!option) && (strcmp(coup, "T") != 0) && !arriere) {
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

			//Test sur les coordonnees entrées: xd,x €[1;15] et yd,y €[0;9]
			if (coup[3]!='-' || yd<0 || yd>surface->largeur - 1 || xd<1 || xd>surface->hauteur
				|| y<0 || y>surface->largeur - 1 || x<1 || x>surface->hauteur) {
				printf("\n\tMauvaises coordonnees saisies!\n\n");
				printf("\tAppuyer sur une touche: ");
				scanf("%s", erreur);
			}
			else {
				xd--; //On recupere les valeurs reelles de xd et x
				x--;  //en fonction de la structure du plateau de jeu

					  //On verifie si le deplacement est possible
				if ((xd == x && yd == y + 1) || (xd == x && yd == y - 1) || (xd == x - 1 && yd == y)
					|| (xd == x + 1 && yd == y) || (xd == x && y == y)) {
					printf("\n\tConfirmer le deplacement Y/N ? : ");
					scanf("%s", ok);//Confirmation de permutation de jetons

					if (strcmp(ok, "Y") == 0 || strcmp(ok, "y") == 0) {//Si OUI, on effectue le deplacement
                        //On clone notre plateau de jeu
                        surfacePred = clone_Plateau(surface);

						if (surface->tab[x][y].couleur == 11 || surface->tab[xd][yd].couleur == 11) //1er tri: l'un des pions est un pion special
						{
							if (surface->tab[x][y].couleur == 11 && surface->tab[xd][yd].couleur != 11) {
								//le premier Jeton est un jeton special, le second est un jeton normal
								int scoretmp = surface->score; //On sauvegarde le score avant utilisation de jeton special
								surface = utilisationPionSpecial(surface, xd, yd);
								surface->tab[x][y].couleur = 'E';

								system("cls");
                                Affiche_Plateau(surface);
                                printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);
                                printf("\n\n\t\tScore supplementaire: %d", surface->score - scoretmp);
                                system("timeout 2 >nul");

								Completer_Plateau(surface);
								surface->deplacement--;
							}
							else if (surface->tab[x][y].couleur != 11 && surface->tab[xd][yd].couleur == 11) {
								//le second pion est un pion special, le premier est un pion normal
								int scoretmp = surface->score;
								surface = utilisationPionSpecial(surface, x, y);
								surface->tab[xd][yd].couleur = 'E';

								system("cls");
                                Affiche_Plateau(surface);
                                printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);
                                printf("\n\n\t\tScore supplementaire: %d", surface->score - scoretmp);
                                system("timeout 2 >nul");

								Completer_Plateau(surface);
								surface->deplacement--;
							}
							if (surface->tab[x][y].couleur == 11 && surface->tab[xd][yd].couleur == 11) { //cas du melange de 2 pions speciaux
								surface->score += 500; //on rajoute 500 points au score
								printf("\n\t\t+500\n");
								surface = Recharge_Plateau(surface); //on recharge le plateau complet
								surface->deplacement--;
							}
						}
						else {
							Echanger_Position(surface, xd, yd, x, y);
							if (Test_Combinaison(surface, x, y) == 1 || Test_Combinaison(surface, xd, yd) == 1) {

								if (Test_4Jetons_Alignes(surface, x, y) == 1 || Test_4Jetons_Alignes(surface, xd, yd) == 1) {
									//si l'un des jeton ets dans un alignement de 4
									//Si c'est le 1er jeton
									if (Test_4Jetons_Alignes(surface, x, y) == 1) {
										tmp.couleur = surface->tab[x][y].couleur; //on retient la couleur du jeton (x,y)
										printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
										system("timeout 2 >nul");
										sup = Supprimer_Jeton(surface);

										system("cls");
										Affiche_Plateau(surface);
										printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);
										surface->score += sup;
										printf("\n\n\t\tScore supplementaire: +%d", sup);

										system("timeout 2 >nul");
										Remplacer_Forme(surface, x, y, tmp); //on remplace le jeton en position (x,y) par un jeton special de la bonne couleur
										Completer_Plateau(surface); //on regenere le plateau
										surface->deplacement--;
									}
									//Si c'est le 2eme jeton
									if (Test_4Jetons_Alignes(surface, xd, yd) == 1) {
										tmp.couleur = surface->tab[xd][yd].couleur;//on retient la couleur du jeton (xd,yd)
										printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
										system("timeout 2 >nul");
										sup = Supprimer_Jeton(surface);

										system("cls");
										Affiche_Plateau(surface);
										printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);
										surface->score += sup;
										printf("\n\n\t\tScore supplementaire: +%d", sup);

										system("timeout 2 >nul");
										Remplacer_Forme(surface, xd, yd, tmp);//on remplace le jeton en position (xd,yd) par un jeton special de la bonne couleur
										Completer_Plateau(surface);
										surface->deplacement--;
									}
								}
								else { //Si aucun des jetons ne crée une combinaison de 4
									printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface, 'N');
									system("timeout 2 >nul");
									sup = Supprimer_Jeton(surface);

									system("cls");
									Affiche_Plateau(surface);
									printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);
									surface->score += sup;
									printf("\n\n\t\tScore supplementaire: +%d", sup);

									system("timeout 2 >nul");
									Completer_Plateau(surface);
									surface->deplacement--;
								}
							}
							else {//S'il n'y a pas de combinaison possible
                                printf("\n\tPas de combinaison valide! \n");
                                printf("\n\tScore supplementaire: 0");
                                system("timeout 2 >nul");
								Echanger_Position(surface, xd, yd, x, y); //On remet les jetons a leur position d'origine
								surface->deplacement--; //On fait une reduction sur le nbre de deplacements
							}
						}
					}
					else { //Sinon on ne fait rien
						surface->deplacement--;
						surface->deplacement++;
					}
				}
				else { //Si le deplacement est impossible, on fait une reduction sur le nbre de deplacement restant
					surface->deplacement--;
					printf("\n\tDeplacement impossible! \n");
					system("timeout 2 >nul");
				}
			}
		}
		else if(arriere){
            surfacePred->score = surface->score - 100;
            surfacePred->deplacement = surface->deplacement - 2;
            printf("\n\n\t\tRETOUR EN ARRIERE ACTIVE\n");
            system("timeout 3 >nul");
            free(surface);
            Jouer_Partie_Cartes(surfacePred);
            break;
        }
		else if (option) {
			Options(surface, 'C'); //Si option=1, on affiche les options
			break;
		}
	}
	/**
        --- LORSQUE LE JOUEUR N'A PLUS DE DEPLACEMENTS ---
    **/
	//On vérifie s'il y a des alignements dans le plateau
    while(Test_Plateau_Organiser(surface)==0){
        system("cls");
        Affiche_Plateau(surface);
        printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);
        printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'N'); system("timeout 2 >nul");

        sup = Supprimer_Jeton(surface);
        system("cls"); Affiche_Plateau(surface);
        printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);
        printf("\n\n\t\tScore supplementaire: +%d",sup);
        surface->score += sup;

        system("timeout 3 >nul");
        Completer_Plateau(surface);
    }

    system("cls");
    Affiche_Plateau(surface);
    printf("\n\t\tDEPLACEMENTS: %d \tSCORE: %d \tCARTES: %d \n", surface->deplacement, surface->score, nbCarte);
    printf("\n\n\t\tAppuyez sur une touche pour quitter: "); system("pause >nul");
	sup = main();
}
