/**
#############################################################################
#    PROTOTYPE DES FONCTIONS UTILISEES POUR UNE PARTIE AVEC CARTES          #
#############################################################################
*/

//Fonction qui crée une pile et l'initialise à NULL
Pile Creer_Pile();

//Fonction qui teste si une pile est vide
int EstpileVide(Pile P);

//Fonction qui permet d'ajouter un élément dans la pile
Pile empiler(Pile p, Cartes c);

//Fonction qui permet de retirer un élément de la pile
Pile depiler(Pile p);

//Fonction qui génère une carte aléatoirement
Cartes genereCarte();

//Fonction qui remplit une pile de carte pour pouvoir jouer
Pile RemplirPile(Pile p, int nbCartes);

//Fonction qui permet de piocher une carte dans la pile
Cartes piocherCarte(Pile p);

//Fonction qui recharge le plateau de jeu
Plateau *Recharge_Plateau(Plateau *surface);

//Fonction qui multiplie le score
int *multiplieScore(int score);

//Fonction qui place aléatoirement des Jetons sur le plateau
Plateau *placePionsSpeciaux(Plateau *surface);

//Fonction qui fait disparaitre tous le Jetons de même couleur que celui avec lequel est combiné le jeton spécial
Plateau *utilisationPionSpecial(Plateau *surface, int x, int y);

//Fonction qui permet de jouer une partie avec Cartes
void Jouer_Partie_Cartes(Plateau *surface);
