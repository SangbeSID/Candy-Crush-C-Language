/**
###########################################################
#       OPTIONS SPECIALES + PROTOTYPES DES FONCTIONS      #
###########################################################
*/


//         --------------------------------------------------------------
//        |                 ALIGNEMENTS SPECIAUX                         |
//         --------------------------------------------------------------

//Fonction qui teste si un Jeton est dans un alignement diagonnal
int Test_Alignement_Diagonal(Plateau *surface, int x, int y);

//Fonction qui teste si un Jeton est dans un alignement torique
int Test_Alignement_Torique(Plateau *surface, int x, int y);

//Fonction qui teste si un Jeton est dans un aliignement special (en carré)
int Test_Alignement_Special(Plateau *surface, int x, int y);


//         --------------------------------------------------------------
//        |     ELIMINER + FILTRER + JOUER DANS UN PLATEAU SPECIAL       |
//         --------------------------------------------------------------

//Fonction qui élimine tous les jetons alignes(torique,diagonal,carre)
int Eliminer_Jeton(Plateau *surface);

//Fonction qui teste si le tableau contient des alignements ou pas
int Test_Filtre_Plateau(Plateau *surface);

//Fonction qui filtre (élimine tous les alignements) le Plateau
void Filtrer_Plateau(Plateau *surface);

//Fonction qui permet de jouer une partie Spéciale
void Jouer_Special(Plateau *surface);


//         --------------------------------------------------------------
//        |             FONCTIONS UTILISEES POUR LES MISSIONS            |
//         --------------------------------------------------------------

//Fonction qui permet de choisir le niveau de difficulté pour une mission
void Niveau_Difficulte();

//Fonction qui permet de jouer une mission speciale
void Jouer_Mission(Plateau *surface, char type);


//         --------------------------------------------------------------
//        |             FONCTIONS UTILISEES POUR LES AIDES               |
//         --------------------------------------------------------------


//Fonctions qui détermine tous les coups possibles.
void coups_Possibles(Plateau *surface);

//Fonction qui détermine le nbre de coups possibles qui reste à jouer
int Nbre_Coups_Possibles(Plateau *surface);

//Fonction fonction permet de débloquer le jeu
void Debloquer_Jeu(Plateau *surface, char type);

//Cette fonction affiche la direction vers laquelle dirger un pion pour supprimer k jetons
void direction_coup(Plateau *surface, int x, int y, int k);

//Fonction qui dit quel est le meilleur coup, celui pour lequel on supprime le plus de pions
void meilleur_coup(Plateau *surface);

//Fonction qui renvoie le nombre de pions dans des combinaisons
int nombreDePionsEnCombinaison(Plateau *surface);
