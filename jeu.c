/**
###########################################################
#    CORPS DES FONCTIONS UTILISEES POUR LE JEU DE BASE    #
###########################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "plateau.h"
#include "messages.h"
#include "outils.h"
#include "jeu.h"


//===================================
/**
    Cettte fonction permute deux jetons
**/
void Echanger_Position(Plateau *surface, int x1, int y1, int x2, int y2)
{
    Jeton tmp;

    tmp.couleur = surface->tab[x1][y1].couleur;
    surface->tab[x1][y1].couleur = surface->tab[x2][y2].couleur;
    surface->tab[x2][y2].couleur = tmp.couleur;
}

//===================================
/**
    Cette fonction compare la couleur deux jetons.
    Elle rennvoie
    1: si meme couleur
    0: si couleurs differentes
**/
int Compare_Forme(Plateau *surface, int x1, int y1, int x2, int y2)
{
    //On compare (x1,y1) à (x2,y2)
    if(surface->tab[x1][y1].couleur < NB_COULEUR){ //Si on a affaire a un jeton normal
		if (surface->tab[x1][y1].couleur == surface->tab[x2][y2].couleur
            || surface->tab[x1][y1].couleur == surface->tab[x2][y2].couleur - 13)
            return 1;
		else
            return 0;
	}
	else if (surface->tab[x1][y1].couleur > NB_COULEUR+1){ //Si c'est un jeton special
		if (surface->tab[x1][y1].couleur == surface->tab[x2][y2].couleur
            || surface->tab[x1][y1].couleur == surface->tab[x2][y2].couleur + 13)
            return 1;
		else
            return 0;
	}
}

//===================================
/**
    Cette procedure remplace la couleur d'un Jeton par
    celle d'un Jeton special correspondant a cette couleur
**/
void Remplacer_Forme(Plateau *surface, int x, int y, Jeton tmp)
{
	surface->tab[x][y].couleur = tmp.couleur + 13;
}


//===================================
/**
    Cette fonction permet de jouer une partie Solo normale
**/
void Jouer_Partie(Plateau *surface)
{
    int i,j,sup;
    char vide[2],erreur[2]; //Variables qui contiendrons les erreurs
    int xd,yd; //Position de départ
    int x,y; //Position d'arrivee
    char ok[2]; //Reponse du deplacement
    char coup[6]; //Contiendra le deplacement
    Plateau* surfacePred; //Pointeur qui contient la surface précédente
    char nom[10]; //Nom du joueur
    int option=-1;
    int help=-1;
    int arriere=-1;
    Jeton tmp;

    //On clone notre plateau de jeu
    surfacePred = clone_Plateau(surface);

    while(surface->deplacement > 0){
        system("cls"); /* Efface l'écran */

        //Tant qu'il y a des combinaisons, on les élimine les jetons alignés
        //Et on remplit les espaces vides créés
        while(Test_Plateau_Organiser(surface)==0){
            Affiche_Plateau(surface);
            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
            printf("\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'N'); system("timeout 2 >nul");

            sup = Supprimer_Jeton(surface) * 5; //On fait un bonus car c'est une suppression due à une cascade
            system("cls"); Affiche_Plateau(surface);
            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
            printf("\n\n\t\tScore supplementaire: +%d",sup);
            surface->score += sup;

            system("timeout 3 >nul");
            Completer_Plateau(surface);
            system("cls");
        }

        Affiche_Plateau(surface);

        //On verifie s'il y a des coups jouables dans le plateau
        //Si ce n'est pas le cas on reorganise le plateau de jeu
        if(Nbre_Coups_Possibles(surface)==0){
            printf("\n\n\tIl n'y a plus de coups jouables!\n");
            printf("\tOn fait -2 sur vos deplacements restants\n");
            printf("\n\tReorganisation du plateau en cours.....\n");
            system("timeout 3 >nul");
            Debloquer_Jeu(surface,'N'); //N ==> pour Partie Normale
            surface->deplacement -= 2; //On fait
        }

        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
        printf("\t\tCoups jouables: %d\n", Nbre_Coups_Possibles(surface));

        // Mise a zero du coup precedent
        xd = yd = x = y = -1;

        /** La lecture se fait en (Y,X)
           R(O,oy,ox); ==> y1=xd ; x1=yd ; y2=x et x2=y
           Plus facile a la programmation(comprehension) car Remplissage(et Parcours)
           du plateau de jeu dans le sens de la Hauteur
        **/

        printf("\n\tPour visualiser les options, taper \"O\"\n");
        printf("\tPour visualiser les aides, taper \"A\"\n");
        printf("\tPour revenir en arriere, taper \"R\" [cout: 2 deplacement et 100pts]\n");

        //Saisie du deplacement a effectuer
        printf("\n\tQue jouez-vous? : ");
        scanf("%s",coup);

        //Test sur les valeurs saisie

        option = (strcmp(coup,"O")==0); //Si resultat vaut 0 ==> ON AFFICHE LE MENU DES OPTIONS
        help = (strcmp(coup,"A")==0); //Si resultat vaut 0 ==> ON AFFICHE LE MENU DES AIDES
        arriere = (strcmp(coup,"R")==0); //Si resultat vaut 0 ==> ON REVIENT AU COUP PRECEDENT

        if(!option && !help && !arriere){
            //On recupere l'ordonnée du pion a deplacer
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

            //Test sur les coordonnees entrées: xd,x €[1;15] et yd,y €[0;9]
            if(coup[3]!='-' || yd<0 || yd>=surface->largeur || xd<1 || xd>surface->hauteur || y<0
               || y>=surface->largeur || x<1 || x>surface->hauteur){
                printf("\n\tMauvaises coordonnees saisies!\n\n");
                printf("\tAppuyer sur une touche puis sur \"ENTREE\": ");
                scanf("%s",erreur);
            }
            else{
                xd--; //On recupere les valeurs reelles de xd et x
                x--;  //en fonction de la structure du plateau de jeu

                printf("\n\tConfirmer le deplacement Y/N ? : ");
                scanf("%s",ok);//Confirmation de permutation de jetons

                if(strcmp(ok,"Y")==0 || strcmp(ok,"y")==0){//Si OUI, on effectue le deplacement
                    //On clone le plateau de jeu
                    surfacePred = clone_Plateau(surface);

                    Echanger_Position(surface,xd,yd,x,y); //On échange les positions des jetons
                    //Si les jetons sont dans une combinaison
                    if(Test_Combinaison(surface,x,y)==1 || Test_Combinaison(surface,xd,yd)==1){
                        if (Test_4Jetons_Alignes(surface, x, y) == 1 || Test_4Jetons_Alignes(surface, xd, yd) == 1) {
                            //si l'un des jeton ets dans un alignement de 4
                            //Si c'est le 1er jeton
							if (Test_4Jetons_Alignes(surface, x, y) == 1) {
								tmp.couleur = surface->tab[x][y].couleur; //on retient la couleur du jeton (x,y)
                                printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'N');
                                system("timeout 2 >nul");
                                sup = Supprimer_Jeton(surface);

                                system("cls");
                                Affiche_Plateau(surface); //On affiche le plateau apres suppression des jetons alignés
                                printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                                printf("\n\n\t\tScore supplementaire: +%d",sup); //On affiche le score obtenu
								surface->score += sup;

                                system("timeout 2 >nul");
								Remplacer_Forme(surface, x, y, tmp); //on remplace le jeton en position (x,y) par un jeton special de la bonne couleur
								Completer_Plateau(surface); //on complète le plateau
								surface->deplacement--;
							}
							//Si c'est le 2eme jeton
							if (Test_4Jetons_Alignes(surface, xd, yd) == 1) {
								tmp.couleur = surface->tab[xd][yd].couleur;//on retient la couleur du jeton (xd,yd)
                                printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'N');
                                system("timeout 2 >nul");
                                sup = Supprimer_Jeton(surface);

                                system("cls");
                                Affiche_Plateau(surface);
                                printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                                printf("\n\n\t\tScore supplementaire: +%d",sup);
								surface->score += sup;

                                system("timeout 2 >nul");
								Remplacer_Forme(surface, xd, yd, tmp);//on remplace le jeton en position (xd,yd) par un jeton special de la bonne couleur
								Completer_Plateau(surface); //On complète le plateau
								surface->deplacement--;
							}
						}
                        else{ //Si aucun des jetons ne crée une combinaison de 4
                            sup = Supprimer_Jeton(surface);
                            printf("\n\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'N');
                            system("timeout 2 >nul");

                            system("cls");
                            Affiche_Plateau(surface);
                            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                            printf("\n\n\t\tScore supplementaire: +%d",sup);
                            surface->score += sup;

                            system("timeout 2 >nul");
                            Completer_Plateau(surface);
                            surface->deplacement--;
                        }
                    }
                    else{//S'il n'y a pas de combinaison possible
                        printf("\n\tPas de combinaison valide! \n");
                        printf("\n\tScore supplementaire: 0");
                        system("timeout 2 >nul");
                        Echanger_Position(surface,xd,yd,x,y); //On remet les jetons a leur position d'origine
                        surface->deplacement--; //On fait une reduction sur le nbre de deplacements
                    }
                }
                else{//Sinon on ne fait rien
                    surface->deplacement--;
                    surface->deplacement++;
                }
            }
        }
        else if(arriere){
            surfacePred->score = surface->score - 100;
            surfacePred->deplacement = surface->deplacement - 2;
            printf("\n\n\t\tRETOUR EN ARRIERE ACTIVE\n");
            system("timeout 3 >nul");
            free(surface);
            Jouer_Partie(surfacePred);
            break;
        }
        else if(option){
            Options(surface,'N'); //Si coup='O', on affiche les options
            break;
        }
        else if(help){ //Si coup='A'
            Need_Help(surface); break;
        }
    }

    /** LORSQUE LE JOUEUR N'A PLUS DE DEPLACEMENTS  **/

    //On vérifie s'il y a des alignements dans le plateau
    while(Test_Plateau_Organiser(surface)==0){
            system("cls");
            Affiche_Plateau(surface);
            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
            printf("\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'N'); system("timeout 2 >nul");

            sup = Supprimer_Jeton(surface);
            system("cls"); Affiche_Plateau(surface);
            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
            printf("\n\n\t\tScore supplementaire: +%d",sup);
            surface->score += sup;

            system("timeout 3 >nul");
            Completer_Plateau(surface);
    }

    system("cls");
    Affiche_Plateau(surface);
    printf("\n\tDeplacements Restants: %d\t\t\tScore: %d \n\n",surface->deplacement,surface->score);

    printf("\n\n\tVeuillez entrer votre nom: ");
    scanf("%s",nom);
    if(Best_Score(surface,nom)==1){
        printf("\n\n\tFELICITATION: vous faites partir des meilleurs joueurs\n");
        printf("\n\n\tAppuyer sur une touche pour afficher les meilleurs scores: ");
        system("pause >nul");
        Affiche_Score();
    }
    else{
        printf("\n\n\tRessayez, vous y etiez presque!\n");
        system("timeout 5 >nul");
        Affiche_Score();
    }
    /** FIN DE LA PARTIE DE JEU NORMALE **/
}

//===================================
/** Cette fonction permet de tester si un jeton est
    dans une combinaison (3,4 ou 5). Elle renvoie
    1: s'il y a alignement
    0: s'il n'y a pas d'alignement
    NB: On compare la couleur du jeton à celle de ses voisins
        selon sa position sur le plateau de jeu
**/
int Test_Combinaison(Plateau *surface, int x, int y)
{
    //Cas basique,si le pion se trouve au milieu d'une combinaison de 3 pions

    if(y!=0 && y!=surface->largeur-1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
		return 1;

    if(x!=0 && x!=surface->hauteur-1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
		return 1;

    //Cas où x=0 ou x=1 et y>=2 et y<=surface->largeur-3
    //Nous sommes sur la premiere ou deuxieme ligne
    if((x==0 || x==1) && y>=2 && y<=surface->largeur-3){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
            || (Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
			|| (Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1))
				return 1;
        else
			return 0;
    }

    //Cas où x=surface->hauteur-1 ou x=surface->hauteur-2
    //Nous sommes sur la derniere ou avant-derniere ligne
    if ((x==surface->hauteur-1 || x==surface->hauteur-2) && y<2){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
			||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1))
			return 1;
        else
			return 0;
    }

    //Cas où x=surface->hauteur-1 ou x=surface->hauteur-2
    //Nous sommes sur la derniere ou avant-derniere ligne et
    //y>= a la deuxieme colonne et < a l'avant derniere colonne
    if (((x==surface->hauteur-1)||(x==surface->hauteur-2)) && y>=2 && y<=surface->largeur-3){
		if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
			||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
            || (Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1))
            return 1;
		else
			return 0;
    }

    //Cas y=0 ou y=1 et x=0 ou x=1
    //Nous sommes dans la premiere ou deuxieme colonne
    if(((y==0)||(y==1)) && x<2){
        //On effectue le test vers le bas et la droite
        if((Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           || (Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1))
            return 1;
        else
            return 0;
    }

    //Cas y=0 ou y=1 et x<= avant-derniere ligne
    //Nous sommes dans la premiere ou deuxieme colonne
    if((y==0 || y==1) && x>=2 && x<=surface->hauteur-3){
        //On effectue le test vers la droite, le haut et le bas
        if((Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           || (Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           || (Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas: y=surface->largeur-1 ou y=surface->largeur-2 et x=0 ou x=1
    //Nous sommes dans la derniere ou l'avant derniere colonne
    if(((y==surface->largeur-1)||(y==surface->largeur-2)) && x<2){
        //On effetcue le test vers la gauche et le bas
       if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,-2)==1)
       ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1))
        return 1;
    else
        return 0;
    }
    //Nous sommes dans la derniere ou l'avant derniere colonne et
    //sur la derniere ou l'avant derniere ligne
    if(((y==surface->largeur-1)||(y==surface->largeur-2)) && x>surface->hauteur-3){
	//On effectue le test vers la gauche et le haut
        if((Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1))
            return 1;
        else
			return 0;
    }

    //Nous sommes dans la derniere ou l'avant derniere colonne et
    //sur la derniere ou l'avant derniere ligne
    if(((y==surface->largeur-1)||(y==surface->largeur-2)) && x>surface->hauteur-3){
	//On effectue le test vers le bas jusqu'a la limite fixée
        if((Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1))
            return 1;
        else
			return 0;
    }

    //On teste tous les autres cas
    //On effectue le test en haut, en bas, à gauche et à droite
    if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
       ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
       ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
       ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1))
       return 1;
    else
        return 0;

}

//===================================
/**
    Cette fonction teste si un jeton crée une combinaison
    de 4 jetons de meme couleur.
    Elle renvoie
    1: si c'est le cas
    0: si ce n'est pas le cas
    NB: On compare la couleur du jeton à celle de ses voisins
        selon sa position sur le plateau de jeu
**/
int Test_4Jetons_Alignes(Plateau *surface, int x, int y)
{
	//Cas où nous sommes au coin du plateau
	if((x==0 || x==surface->hauteur-1) && (y==0 || y==surface->largeur-1))
		return 0;

    //Cas 1: x=0 ou x=surface->hauteur-1 et y=1
    //Nous sommes sur la 1ere ou derniere ligne et dans la 2eme colonne
    if((x==0 || x==surface->hauteur-1) && y==1){
        if(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
            return 1;
        else
            return 0;
    }

    //Cas 2: x=0 ou x= surface->hauteur-1 et y=surface->largeur-2
    //Nous sommes sur la 1ere ou derniere ligne et dans l'avant-derniere colonne
    if((x==0 || x==surface->hauteur-1) && y==surface->largeur-2){
        if(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
            return 1;
        else
            return 0;
    }

    //Cas 3: x=0 ou x= surface->hauteur-1 et y > 1 et y < surface->largeur-2
    //Nous sommes sur la 1ere ou derniere ligne et entre la 3eme et avant avant dernier colonne
    if((x==0 || x==surface->hauteur-1) && (y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1))
            return 1;
        else
            return 0;
    }

    //Cas 4: x=1 et y=0 ou y=surface->largeur-1
    //Nous sommes sur la 2eme ligne et dans la 1ere ou derniere colonne
    if(x==1 && (y==0 || y==surface->largeur-1)){
        if(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
            return 1;
        else
            return 0;
    }

    //Cas 5: x=surface->hauteur-2 et y=0 ou y=surface->largeur-1
    //Nous sommes sur l'avant-derniere ligne et dans la 1ere ou derniere colonne
    if(x==surface->hauteur-2 && (y==0 || y==surface->largeur-1)){
        if(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
            return 1;
        else
            return 0;
    }

    //Cas 6: x>1 et x<surface->hauteur-2 et y=0 ou y=surface->largeur-1
    //Nous sommes entre la 3eme et l'avant avant-derniere ligne et dans la 1ere ou derniere colonne
    if((x>=2 && x<=surface->hauteur-3) && (y==0 && y==surface->largeur-1)){
        if((Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 7: x=1 et y=1
    //Nous sommes sur la 2eme ligne et dans la 2eme colonne
    if(x==1 && y==1){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 8: x=1 et y=suface->largeur-2
    //Nous sommes sur la 2eme ligne et dans l'avant-derniere colonne
    if(x==1 && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 9: x=1 et y>1 et y<surface->largeur-2
    //Nous sommes sur la 2eme ligne et entre la 3eme et l'avant avant-derniere colonne
    if(x==1 && (y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 10: x=surface->hauteur-2 et y=1
    //Nous sommes sur l'avant-derniere ligne et dans la 2eme colonne
    if(x==surface->hauteur-2 && y==1){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 11: x=sureface->hauteur-2 et y=surface->largeur-2
    //Nous sommes sur l'avant-derniere ligne et dans l'avant-derniere colonne
    if(x==surface->hauteur-2 && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 12: x=surface->hauteur-2 et y > 1 et y < surface->largeur-2
    //Nous sommes sur l'avant-derniere ligne et entre la 3eme et l'avant avant-derniere colonne
    if(x==surface->hauteur-2 &&(y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 13: x > 1 et x < surface->hauteur-2 et y=1
    //Nous sommes entre la 3eme et l'avant avant-derniere ligne et dans la 2eme colonne
    if((x>=2 && x<=surface->hauteur-3) && y==1){
        if((Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1))
            return 1;
        else
            return 0;
    }


    //Cas 14: x > 1 et x < surface->hauteur-2 et y=surface->largeur-2
    //Nous sommes entre la 3eme et l'avant avant-derniere ligne et dans l'avant-derniere colonne
    if((x>=2 && x<=surface->hauteur-3) && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1))
            return 1;
        else
            return 0;
    }

    //CAS GENERAL

    if((Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
        ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
        ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
        ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1))
        return 1;
    else
        return 0;

    /**FIN DES TESTS DE 4 JETONS DE MEME COULEUR ALIGNES**/
}


//============================
/** Cette fonction permet de tester si le plateau
    est bien organisé( pas d'alignement). Elle renvoie
    0 : s'il y a au moins un alignement
    1 : s'il n'y a pas d'alignement
**/
int Test_Plateau_Organiser(Plateau *surface)
{
    int i,j;

    for(i=0 ; i<surface->hauteur ; i++){
        for(j=0 ; j<surface->largeur ; j++){
            if(Test_Combinaison(surface,i,j)==1)
                return 0;
        }
    }
    return 1;
}

//============================
/** Pour chaque jeton, cette fonction verifie s'il est dans une combinaison,
    si tel est le cas, elle modifie sa couleur.
    Enfin, si le plateau n'est toujours pas organisé, on reittère l'operation
*/
void Organiser_Plateau(Plateau *surface)
{
    int i,j;
    for(i=0 ; i<surface->hauteur ; i++){
        for(j=0 ; j<surface->largeur ; j++){
            if(Test_Combinaison(surface,i,j)==1)
              surface->tab[i][j].couleur = rand() % surface->nbcouleur;
        }
    }
    if(Test_Plateau_Organiser(surface)==0)
        Organiser_Plateau(surface);
}

//===================================
/** Cette fonction rempli un espace vide avec
    l'element se trouvant sur la ligne du dessus
    et ainsi de suite jusqu'a la 1ere ligne qui
    elle est remplie de maniere aleatoire
**/
void Remplir_Espace(Plateau *surface, int x, int y)
{
    int a,b;

    if(x==0){
        a = rand() % surface->nbcouleur;
        surface->tab[x][y].couleur = a;
    }
    else{
        Echanger_Position(surface,x,y,x-1,y);
        Remplir_Espace(surface,x-1,y); //On rappelle la fonction
    }
}


//===================================
/**
    Cette fonction permet de remplir tous les
    jetons marqués par de nouvelles couleurs
*/
void Completer_Plateau(Plateau *surface)
{
    int i,j;
    for(i=0 ; i<surface->hauteur ; i++){
        for(j=0 ; j<surface->largeur ; j++){
            if(surface->tab[i][j].couleur=='E')
                Remplir_Espace(surface,i,j);
        }
    }
}

//======================================
/**
    Cette fonction tire une direction au hasard.
    Elle renvoie:
    1 : pour horizontal
    0 : pour vertical
**/
int HorizontalOuVertical()
{
	int direction = rand() % 2;
	return direction;
}


//===================================
/**
    Cette fonction marque tous les jetons
    qui sont dans une combinaison par
    E : qui signifie "vide"
    Et elle retourne le score obtenu
*/
int Supprimer_Jeton(Plateau *surface)
{
    int i, j;
	int x, y;
	int score;
	int compt = 0;
	int rand = 0;
	Plateau *tmp = Creation_Plateau(surface->hauteur, surface->largeur);

	//On clone notre plateau de jeu
	for (i = 0; i<tmp->hauteur; i++) {
		for (j = 0; j<tmp->largeur; j++) {
			tmp->tab[i][j].couleur = surface->tab[i][j].couleur;
		}
	}

    //On effectue les tests d'alignement sur le clone et on marque l'original
	for (i = 0; i<surface->hauteur; i++) {
		for (j = 0; j<surface->largeur; j++) {
			if (tmp->tab[i][j].couleur > 12 && tmp->tab[i][j].couleur < 23 && Test_Combinaison(tmp, i, j) == 1) {
				//si le jeton est special et est dans une combinaison
				//on tire une direction au hasard
				rand = HorizontalOuVertical();

				if (rand == 0) {
                    // 0=vertical
					printf("\n\n\tElimination de la ligne entiere!\n");
					system("timeout 2 >nul");
					for (x = 0; x < surface->largeur; x++) {
						surface->tab[i][x].couleur = 'E'; //on marque tous les jetons de la colonne
						compt++; //on incremente le compteur pour chaque jeton
					}
				}
				else {
				// 1=horizontal
					printf("\n\n\tElimination de la colonne entiere!\n");
					system("timeout 2 >nul");
					for (y = 0; y <surface->hauteur; y++) {
						surface->tab[y][j].couleur = 'E'; //on marque tous les jetons de la ligne
						compt++;
					}
				}
			}
			if (Test_Combinaison(tmp, i, j) == 1 && (tmp->tab[i][j].couleur >= 0 && tmp->tab[i][j].couleur < 10)) {
				//On effectue les tests sur le clone, si le jeton est dans une
				//combinaison, on marque l'original
				surface->tab[i][j].couleur = 'E';
				compt++;
			}
		}
	}

	//Calcul du score
	score = compt * compt;
	free(tmp);
	return score;
}
