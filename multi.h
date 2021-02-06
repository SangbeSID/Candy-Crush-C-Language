/**
##############################################################
#           MULTIJOUEURS +  PROTOTYPES DES FONCTIONS         #
##############################################################
*/

//         --------------------------------------------------------------
//        |                 MULTIJOUEUR CLASSIQUE                        |
//         --------------------------------------------------------------

// Fonction qui g�re le mode multi-joueur classique
void multi_joueur(Plateau *surface);

//         --------------------------------------------------------------
//        |          MULTIJOUEUR AVEC CHACUN SA COULEUR                  |
//         --------------------------------------------------------------

//Fonction qui affiche le choix des couleurs au joueurs
void choixDesCouleurs();

//Fonction qui retourne le caract�re � l'affichage en ayant le num�ro d'une couleur
char imageCouleur(int c);

//Fonction qui renvoit un nombre quelconque compris entre 0 et a except� b et c
int random(int a,int b,int c);

//Fonction qui remplit la surface avec un nbre de Jetons de c1 et de c2 d�fini
void remplitNombreEgaleDeDeuxCouleur(Plateau *surface, int c1, int c2);

//Cette fonction renvoie le nombre de fois qu'il y a une certaine couleur dans le tableau
int nombreCouleur(Plateau *surface,int coul);

//Fonction qui renvoie le nombre de pions d'une certaine couleur qui sont dans des combinaisons
int PionsDuneCouleurEnCombinaison(Plateau *surface, int coul);

//Fonction qui g�re le mode multijoueur o� chaque joueur a un Jeton sp�cifique
void multi_joueur_couleur(Plateau *surface);

//         --------------------------------------------------------------
//        |              MULTIJOUEUR AVEC CARTES SPECIALES               |
//         --------------------------------------------------------------

//Fonction qui g�re le mode multijoueur avec cartes sp�ciales
void multi_joueur_carte(Plateau *surface);
