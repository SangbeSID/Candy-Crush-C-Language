
/**
###########################################################
#       STRUCTURES DE DONNEES UTILISÉES POUR LE JEU       #
###########################################################
*/

#define NB_LIGNES 15 //Nbre de lignes du plateau de jeu (par défaut)
#define NB_COLONNES 10 //Nbre de colonnes du plateau de jeu (par défaut)
#define NB_COULEUR 10 //Nbre de couleurs possible pour un jeton (par défaut)
#define NB_DEPLACEMENTS 15 //Nbre de deplacements du joueur (par défaut)
#define TOP 10 //On ne conserve que les 10 meilleurs scores
#define NB_TYPE_CARTES 5 //Nbre de type de cartes existant dans le jeu
#define NB_CARTE 3  //Nbre de carte qu'un joueur peut tirer au cours d'une partie
#define NB_CARTE_MULTI 6 //Nbre de cartes pouvant être tirées dans une partie multijoueur
                         //(chaque joueur peut en piocher la moitié au max)


//=====================================
//Jetons a utiliser dans le jeu
typedef enum{X,O,H,J,P,A,M,T,K,S,E,Z,Y,x,o,h,j,p,a,m,t,k,s}TypeCouleur;
/**
    de X à S ===> Jetons utilisés pour jouer le jeu (par défaut)
    E et Y ===> utilisé pour représenter les jetons supprimés
    Z ===> Le Jeton spécial qui explose tous le jetons qui sont combinés avec lui
	de x à s ===> Jetons spéciaux créés par l'alignement de 4 jetons de meme couleur
**/

//On definit le type Jeton
typedef struct{
    TypeCouleur couleur;
}Jeton;

//=====================================
//Plateau de jeu
typedef struct{
    Jeton **tab;  //Tableau à 2 dimensions de Jetons
    int hauteur; //Hauteur du plateau (Nbre de Lignes)
    int largeur; //Largeur du plateau (Nbre de Colonnes)
    int deplacement; //Nbre de deplacements du joueur
    int nbcouleur; //Nbre de Jetons dans plateau
    int score; //Score du joueur
}Plateau;

//=====================================
//Structure utilisée pour la gestion du score
typedef struct{
    char nom[10];
    int valeur;
}T_Score;

//=====================================
//Cartes spéciales à utiliser dans une partie avec "cartes"
typedef enum { UN = 1, DEUX = 2, TROIS = 3, QUATRE = 4, CINQ = 5 }Cartes;

//=====================================
//Structure de Cellule et de Pile utilisées pour la partie avec carte
struct Cellule
{
	Cartes val;
	struct Cellule *suiv;
};

typedef struct Cellule *Pile;
