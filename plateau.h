/**
###############################################################
#  PROTOTYPES DES FONCTIONS  UTILISEES POUR GERER LE PLATEAU  #
###############################################################
*/

//=====================================

//Fonction qui cree le plateau du jeu
Plateau *Creation_Plateau(int nbLigne, int nbColonne);

//Fonction qui remplie le plateau du jeu
void Remplir_Plateau(Plateau *surface, int nb_couleur, int nb_mouvement);

//Fonction qui affiche une couleur
void Affiche_Couleur(TypeCouleur couleur);

//Fonction qui affiche le plateau du jeu
void Affiche_Plateau(Plateau *surface);

//Fonction qui affiche les vraies coordonées du tableau.
void afficheValeursReels(int x,int y);

//Fonction qui clone un plateau de jeu
Plateau* clone_Plateau(Plateau *surface);
