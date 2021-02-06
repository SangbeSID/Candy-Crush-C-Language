/**
###########################################################
#      DEFINITION DES MESSAGES A AFFICHER DANS LE JEU     #
###########################################################
*/

/**  MENU D'ACCUEIL **/
#define MENU() printf("\n\n\t\t##################################################\n");\
               printf("\t\t#         BIENVENUE DANS  CANDY CRUSH            #\n");\
               printf("\t\t##################################################\n\n\n"); system("timeout 1 >nul");\
               printf("\t1---------------------->Nouvelle Partie\n\n");\
               printf("\t2---------------------->Charger Partie\n\n");\
               printf("\t3---------------------->Aide pour le Jeu\n\n");\
               printf("\t4---------------------->Afficher les meilleurs scores\n\n");\
               printf("\t5---------------------->A Propos\n\n");\
               printf("\t0---------------------->Quitter\n\n"); system("timeout 1 >nul");

/**AIDE POUR JOUER UN COUP **/
#define AIDE() printf("\n\tPour effectuer un deplacement :\n\n");\
               printf("\tOn saisi le numero de la colonne et celui de la ligne\n");\
               printf("\tdu pion a deplacer, puis un tiret \"-\" ensuite,\n");\
               printf("\tla destination: Haut, Bas, Gauche, Droite.\n");\
               printf("\tPour valider le deplacement, on appuie sur la touche \"entree\"\n\n");\
               printf("\t-->a gauche; Ex: c05-g ou c10-G\n");\
               printf("\t-->vers le bas; Ex: f10-b ou a01-B\n");\
               printf("\tEnsuite appuyer sur la touche \"Entree\"\n");\
               printf("\n\tAppuyer sur une touche pour reprendre la partie: ");

/**  OPTIONS POUR LE JEU DE BASE ET TORIQUE **/
#define OPTION_BASE() printf("\n\t\tOPTIONS\n\n");\
                      printf("\t1-------->Reprendre la partie\n\n");\
                      printf("\t2-------->Sauvegarder la partie\n\n");\
                      printf("\t3-------->Aide pour le Jeu\n\n");\
                      printf("\t0-------->Retour au menu principal\n\n");

/**  OPTIONS POUR LES MISSIONS **/
#define OPTION_MISSION() printf("\n\n\t\tOPTIONS\n\n");\
                         printf("\n\t1-------->Reprendre la partie\n");\
                         printf("\n\t2-------->Aide pour le Jeu\n");\
                         printf("\n\t0-------->Retour au menu principal\n");

/** GUIDE POUR PROGRESSER DANS LA PARTIE **/
#define COUP() printf("\n\t\tBESOIN D'AIDE:\n\n");\
               printf("\n\t1----------->Coups Possibles\n");\
               printf("\n\t2----------->Meilleur Coup\n");\
               printf("\n\tFaites votre choix: ");

/** MESSAGE POUR UNE PARTIE TORIQUE **/
#define PARTIE_TORIQUE() printf("\n\n\t\tBIENVENUE DANS LA PARTIE SPECIALE\n");\
                         printf("\n\tDans cette partie le plateau n'a pas de bordure:\n");\
                         printf("\t-->Vous pouvez donc passer de la 1ere a la derniere ligne\n\t   et vice-versa\n\n");\
                         printf("\t-->Idem pour les colonnes\n\n");\
                         printf("\t-->Les alignements se font aussi comme cela!\n");\
                         printf("\n\tNB: Les alignements en DIAGONAL et en CARREE sont autorises!\n");\
                         printf("\n\n\tAppuyer sur une touche pour lancer la partie: ");\
                         system("pause >nul");

/** INFO POUR JOUER UNE MISSION **/
#define INFO_MISSION() system("cls");\
                       printf("\n\n\t\tINFORMATIONS POUR LA MISSION");\
                       printf("\n\n\tVous devez atteindre l'objectif qui vous est demande");\
                       printf("\n\tavant la fin de tous vos deplacements");\
                       printf("\n\n\t Pour mener a bien votre mission vous diSposez: \n");\
                       printf("\n\t--> des alignements de base(horizontal et vertical)\n");\
                       printf("\n\t--> des alignements en carre\n");\
                       printf("\n\t--> des alignements en diagonal\n");\
                       printf("\n\t--> des alignements torique\n");\
                       printf("\n\tNB: le plateau n'a pas de bordure\n\n");\
                       printf("\n\tAppuyez sur une touche pour commencer: ");

/** INFO POUR UNE PARTIE SOLO AVEC CARTES **/
#define PARTIE_CARTE() printf("\n\n\t\tBIENVENUE DANS LA PARTIE AVEC CARTES\n");\
                       printf("\n\tDans cette partie vous disposez de cartes speciales\n");\
                       printf("\tqui vous permettent d'avoir des supprises(bonnes, mauvaises)\n");\
                       printf("\n\tNB: Tout le reste est comme dans une partie normale!\n");\
                       printf("\n\n\tAppuyez sur une touche pour lancer la partie: ");\
                       system("pause >nul");

/** INFORMATIONS SUR LES DEVELOPPEURS **/
#define A_PROPOS() system("cls");\
                   printf("\n\n\n\t\t\t A PROPOS DU JEU:");\
                   printf("\n\n\n\tLa realisation de ce JEU s'inscrit dans le cadre du projet");\
                   printf("\n\n\tdu Semestre 2 des etudiants de la L2INFO de l'Universite de POITIERS.");\
                   printf("\n\n\n\tRealisation par:\n");\
                   printf("\n\t  ===> Sangbe SIDIBE");\
                   printf("\n\t       mail: sangbe.narcisse.sidibe@etu.univ-poitiers.fr");\
                   printf("\n\n\t  ===> William FLEURQUIN");\
                   printf("\n\t       mail: william.fleurqui@etu.univ-poitiers.fr");\
                   printf("\n\n\t  ===> Mahamadou DIABATE");\
                   printf("\n\t       mail: mahamadou.diabate@etu.univ-poitiers.fr");\
                   printf("\n\n\n\tCopyright: Avril 2017");\
                   printf("\n\n\n\tAppuyez sur une touche, puis sur \"ENTREE\" pour revenir: ");
