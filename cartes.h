/**
#############################################################################
#    PROTOTYPE DES FONCTIONS UTILISEES POUR UNE PARTIE AVEC CARTES          #
#############################################################################
*/

//Fonction qui cr�e une pile et l'initialise � NULL
Pile Creer_Pile();

//Fonction qui teste si une pile est vide
int EstpileVide(Pile P);

//Fonction qui permet d'ajouter un �l�ment dans la pile
Pile empiler(Pile p, Cartes c);

//Fonction qui permet de retirer un �l�ment de la pile
Pile depiler(Pile p);

//Fonction qui g�n�re une carte al�atoirement
Cartes genereCarte();

//Fonction qui remplit une pile de carte pour pouvoir jouer
Pile RemplirPile(Pile p, int nbCartes);

//Fonction qui permet de piocher une carte dans la pile
Cartes piocherCarte(Pile p);

//Fonction qui recharge le plateau de jeu
Plateau *Recharge_Plateau(Plateau *surface);

//Fonction qui multiplie le score
int *multiplieScore(int score);

//Fonction qui place al�atoirement des Jetons sur le plateau
Plateau *placePionsSpeciaux(Plateau *surface);

//Fonction qui fait disparaitre tous le Jetons de m�me couleur que celui avec lequel est combin� le jeton sp�cial
Plateau *utilisationPionSpecial(Plateau *surface, int x, int y);

//Fonction qui permet de jouer une partie avec Cartes
void Jouer_Partie_Cartes(Plateau *surface);
