/**
###########################################################
# PROTOTYPES DES FONCTIONS UTILISEES POUR LE JEU DE BASE  #
###########################################################
*/

//Fonction qui permet de permuter deux caracteres
void Echanger_Position(Plateau *surface, int x1, int y1, int x2, int y2);

//Fonction qui compare deux formes
int Compare_Forme(Plateau *surface, int x1, int y1, int x2, int y2);

//Fonction qui permet de jouer le jeu
void Jouer_Partie(Plateau *surface);

//Fonction qui teste si un jeton est dans une combinaison
int Test_Combinaison(Plateau *surface, int x, int y);

//Fonction qui teste si un Jeton crée un alignement de 4
int Test_4Jetons_Alignes(Plateau *surface, int x, int y);

//Fonction qui modifie la couleur d'un jeton
void Remplacer_Forme(Plateau *surface, int x, int y, Jeton tmp);

//Fonction qui verifie si le plateau du jeu est trié
int Test_Plateau_Organiser(Plateau *surface);

//Fonction qui organise le plateau du jeu
void Organiser_Plateau(Plateau *surface);

//Fonction qui remplit l'espace (decalage du haut vers le bas)
void Remplir_Espace(Plateau *surface, int x, int y);

//Fonction qui remplit tous les espaces vide du plateau
void Completer_Plateau(Plateau * surface);

//Fonction qui choisi aléatoirement si on suppirme une ligne ou une colonne
int HorizontalOuVertical();

//Fonction qui elimine les jetons alignes et retourne le score obtenu
int Supprimer_Jeton(Plateau *surface);
