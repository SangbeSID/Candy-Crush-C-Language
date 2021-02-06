
/**
###########################################################
#       STRUCTURES DE DONNEES UTILIS�ES POUR LE JEU       #
###########################################################
*/

#define NB_LIGNES 15 //Nbre de lignes du plateau de jeu (par d�faut)
#define NB_COLONNES 10 //Nbre de colonnes du plateau de jeu (par d�faut)
#define NB_COULEUR 10 //Nbre de couleurs possible pour un jeton (par d�faut)
#define NB_DEPLACEMENTS 15 //Nbre de deplacements du joueur (par d�faut)
#define TOP 10 //On ne conserve que les 10 meilleurs scores
#define NB_TYPE_CARTES 5 //Nbre de type de cartes existant dans le jeu
#define NB_CARTE 3  //Nbre de carte qu'un joueur peut tirer au cours d'une partie
#define NB_CARTE_MULTI 6 //Nbre de cartes pouvant �tre tir�es dans une partie multijoueur
                         //(chaque joueur peut en piocher la moiti� au max)


//=====================================
//Jetons a utiliser dans le jeu
typedef enum{X,O,H,J,P,A,M,T,K,S,E,Z,Y,x,o,h,j,p,a,m,t,k,s}TypeCouleur;
/**
    de X � S ===> Jetons utilis�s pour jouer le jeu (par d�faut)
    E et Y ===> utilis� pour repr�senter les jetons supprim�s
    Z ===> Le Jeton sp�cial qui explose tous le jetons qui sont combin�s avec lui
	de x � s ===> Jetons sp�ciaux cr��s par l'alignement de 4 jetons de meme couleur
**/

//On definit le type Jeton
typedef struct{
    TypeCouleur couleur;
}Jeton;

//=====================================
//Plateau de jeu
typedef struct{
    Jeton **tab;  //Tableau � 2 dimensions de Jetons
    int hauteur; //Hauteur du plateau (Nbre de Lignes)
    int largeur; //Largeur du plateau (Nbre de Colonnes)
    int deplacement; //Nbre de deplacements du joueur
    int nbcouleur; //Nbre de Jetons dans plateau
    int score; //Score du joueur
}Plateau;

//=====================================
//Structure utilis�e pour la gestion du score
typedef struct{
    char nom[10];
    int valeur;
}T_Score;

//=====================================
//Cartes sp�ciales � utiliser dans une partie avec "cartes"
typedef enum { UN = 1, DEUX = 2, TROIS = 3, QUATRE = 4, CINQ = 5 }Cartes;

//=====================================
//Structure de Cellule et de Pile utilis�es pour la partie avec carte
struct Cellule
{
	Cartes val;
	struct Cellule *suiv;
};

typedef struct Cellule *Pile;
