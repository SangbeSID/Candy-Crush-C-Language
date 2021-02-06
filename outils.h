/**
###########################################################
#     PROTOTYPES DES FONCTIONS UTILISEES COMME OUTILS     #
###########################################################
*/

//Fonction qui lance le menu
void Candy_Crush();

//Fonction qui permet de choisir le type de jeu
void Mode_Jeu(Plateau *surface);

//Fonction qui permet de chosir entre jouer en SOLO
void Type_Partie_Solo(Plateau *surface);

//Fonction qui permet de chosir entre jouer en MULTIJOUEUR
void Type_Partie_Multi(Plateau *surface);

//Fonction qui affiche les options du jeu
void Options(Plateau *Jeu, char type);

//Fonction qui affiche des aides pendant une partie normale
void Need_Help(Plateau *Jeu);

//Fonction qui affiche les coordonnées des jetons alignés
void Coordonnees_Jetons_Alignes(Plateau *surface, char type);

//Fonction qui sauvegarde un jeu en cours
void Sauvegarde(Plateau *jeu, char type);

//Fonction qui charge une partie sauvegardée
void Chargement();

//Fonction qui affiche les 10 meilleurs scores
void Affiche_Score();

//Fonction qui enregistre un score
int Best_Score(Plateau *surface, char *joueur);

//Fonction qui trie les scores
void Tri_Score(T_Score *tab, int taille);
