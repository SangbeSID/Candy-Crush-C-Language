/**
###########################################################
#       CORPS DES FONCTIONS UTILISEES COMME OUTILS        #
###########################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#include "plateau.h"
#include "messages.h"
#include "outils.h"


//============================
/**
    Cette fonction permet de lancer le jeu
*/
void Candy_Crush()
{
    system("color 2F");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tBIENVENUE DANS :\n\n\n");
    printf("\t\t _______     _______     _______     _______ \n");
    printf("\t\t|#######|   |#######|   |  _____|   |  _____|\n");
    printf("\t\t|#|         |#|         | |         | |      \n");
    printf("\t\t|#|         |#|         | |         | |       \n");
    printf("\t\t|#|         |#|         | |         | |       \n");
    printf("\t\t|#|         |#|         | |         | |       \n");
    printf("\t\t|#|         |#|         | |         | |       \n");
    printf("\t\t|#|_____    |#|_____    | |_____    | |_____ \n");
    printf("\t\t|#######|.  |#######|.  |_______|o  |_______|o\n");
    system("timeout 1 >nul");
    system("cls");

    system("color 3F");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tBIENVENUE DANS :\n\n\n");
    printf("\t\t _______     _______     _______     _______ \n");
    printf("\t\t|  _____|   |  _____|   |#######|   |#######|\n");
    printf("\t\t| |         | |         |#|         |#|      \n");
    printf("\t\t| |         | |         |#|         |#|       \n");
    printf("\t\t| |         | |         |#|         |#|       \n");
    printf("\t\t| |         | |         |#|         |#|       \n");
    printf("\t\t| |         | |         |#|         |#|       \n");
    printf("\t\t| |_____    | |_____    |#|_____    |#|_____ \n");
    printf("\t\t|_______|o  |_______|o  |#######|.  |#######|.\n");
    system("timeout 1 >nul");
    system("cls");

    system("color 71");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tBIENVENUE DANS :\n\n\n");
    printf("\t\t _______     _______     _______     _______ \n");
    printf("\t\t|#######|   |  _____|   |#######|   |  _____|\n");
    printf("\t\t|#|         | |         |#|         | |      \n");
    printf("\t\t|#|         | |         |#|         | |       \n");
    printf("\t\t|#|         | |         |#|         | |       \n");
    printf("\t\t|#|         | |         |#|         | |       \n");
    printf("\t\t|#|         | |         |#|         | |       \n");
    printf("\t\t|#|_____    | |_____    |#|_____    | |_____ \n");
    printf("\t\t|#######|.  |_______|o  |#######|.  |_______|o\n");
    system("timeout 1 >nul");
    system("cls");

    system("color 5F");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tBIENVENUE DANS :\n\n\n");
    printf("\t\t _______     _______     _______     _______ \n");
    printf("\t\t|  _____|   |#######|   |  _____|   |#######|\n");
    printf("\t\t| |         |#|         | |         |#|      \n");
    printf("\t\t| |         |#|         | |         |#|       \n");
    printf("\t\t| |         |#|         | |         |#|       \n");
    printf("\t\t| |         |#|         | |         |#|       \n");
    printf("\t\t| |         |#|         | |         |#|       \n");
    printf("\t\t| |_____    |#|_____    | |_____    |#|_____ \n");
    printf("\t\t|_______|o  |#######|.  |_______|o  |#######|.\n");
    system("timeout 1 >nul");
    system("cls");

    system("color 0A");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tBIENVENUE DANS :\n\n\n");
    printf("\t\t _______     _______     _______     _______ \n");
    printf("\t\t|#######|   |#######|   |#######|   |#######|\n");
    printf("\t\t|#|         |#|         |#|         |#|      \n");
    printf("\t\t|#|         |#|         |#|         |#|       \n");
    printf("\t\t|#|         |#|         |#|         |#|       \n");
    printf("\t\t|#|         |#|         |#|         |#|       \n");
    printf("\t\t|#|         |#|         |#|         |#|       \n");
    printf("\t\t|#|         |#|         |#|         |#|       \n");
    printf("\t\t|#|_____    |#|_____    |#|_____    |#|_____ \n");
    printf("\t\t|#######|.  |#######|.  |#######|.  |#######|.\n");
    system("timeout 3 >nul");
    return;
}
//============================
/**
    Cette fonction permet de choisir le mode de jeu:
    Solo ou MultiJoueur ou Mission Spéciale
*/
void Mode_Jeu(Plateau *surface)
{
    int choix,k;
    char vide[2];

    system("cls"); //On efface l'ecran
    system("color F9");

    printf("\n\n\t\tDIFFERENTS MODES DE JEU\n\n\n");
    printf("\t1--------------->Solo\n\n");
    printf("\t2--------------->MultiJoueur\n\n");
    printf("\t3--------------->Mission Speciale\n\n");
    printf("\t0--------------->Menu Principal\n\n");
    printf("\n\tFaites votre choix: ");
    scanf("%d",&choix);

    switch(choix){
        case 1: Type_Partie_Solo(surface);
                break;

        case 2: Type_Partie_Multi(surface);
                break;

        case 3: free(surface); //On libère la mémoire
                Niveau_Difficulte();
                break;

        case 0: k = main();
                break;

        default: printf("\n\tMauvaise saisie!\n");
                 scanf("%s",vide);
                 system("timeout 2 >nul");
                 free(vide);
                 Mode_Jeu(surface);
                 break;
    }
}


//============================
/**
    Cette fonction permet de choisir une partie en SOLO:
    Normale, avec Cartes, Spéciale
*/
void Type_Partie_Solo(Plateau *surface)
{
    int choix,k;
    char vide[2];

    system("cls"); //On efface l'ecran
    system("color F9");

    printf("\n\n\t\tQUE JOUEZ-VOUS?\n\n\n");
    printf("\t1--------------->Partie Normale\n\n");
    printf("\t2--------------->Partie avec Cartes\n\n");
    printf("\t3--------------->Partie Speciale\n\n");
    printf("\t0--------------->Menu Principal\n\n");
    printf("\n\tFaites votre choix: ");
    scanf("%d",&choix);

    switch(choix){
        case 1: Remplir_Plateau(surface,NB_COULEUR,NB_DEPLACEMENTS);
                Organiser_Plateau(surface);
                system("color 0F");
                Jouer_Partie(surface);
                break;

        case 2: Remplir_Plateau(surface,NB_COULEUR,NB_DEPLACEMENTS);
                Organiser_Plateau(surface);
                system("cls");
                PARTIE_CARTE();
                system("color 5F");
                surface->tab[5][5].couleur = 11;
                Jouer_Partie_Cartes(surface);
                break;

        case 3: Remplir_Plateau(surface,NB_COULEUR,NB_DEPLACEMENTS);
                Filtrer_Plateau(surface);
                system("cls");
                PARTIE_TORIQUE();
                system("color 3F");
                Jouer_Special(surface);
                break;

        case 0: k = main();
                break;

        default: printf("\n\tMauvaise saisie!\n");
                 scanf("%s",vide);
                 system("timeout 2 >nul");
                 Type_Partie_Solo(surface);
                 break;
    }
}

//============================
/**
    Cette fonction permet de choisir une partie en MULTIJOUEUR:
    Classique, avec Couleur, avec Cartes
*/
void Type_Partie_Multi(Plateau *surface)
{
    int choix,k;
    char vide[2];

    system("cls"); //On efface l'ecran
    system("color F9");

    printf("\n\n\t\tQUE JOUEZ-VOUS?\n\n\n");
    printf("\t1--------------->Partie Classique\n\n");
    printf("\t2--------------->Chacun Sa Couleur\n\n");
    printf("\t3--------------->Avec Cartes Speciales\n\n");
    printf("\t0--------------->Menu Principal\n\n");
    printf("\n\tFaites votre choix: ");
    scanf("%d",&choix);

    switch(choix){
        case 1: Remplir_Plateau(surface,NB_COULEUR,NB_DEPLACEMENTS);
                Organiser_Plateau(surface);
                system("color 3F");
                multi_joueur(surface);
                break;

        case 2: Remplir_Plateau(surface,NB_COULEUR,NB_DEPLACEMENTS);
                Organiser_Plateau(surface);
                system("color 2F");
                multi_joueur_couleur(surface);
                break;

        case 3: Remplir_Plateau(surface,NB_COULEUR,NB_DEPLACEMENTS);
                Organiser_Plateau(surface);
                system("color 71");
                multi_joueur_carte(surface);
                break;

        case 0: k = main();
                break;

        default: printf("\n\tMauvaise saisie!\n");
                 scanf("%s",vide);
                 system("timeout 2 >nul");
                 Type_Partie_Multi(surface);
                 break;
    }
}


//===================================
/**
    Cette fonction affiche les options
    du jeu en fonction du type de la partie.
**/
void Options(Plateau *Jeu, char type)
{
    int choix,k;
    char vide[2], retour[2];

    system("cls"); //On efface la console
    switch(type){
        case 'T':
        case 'N': OPTION_BASE();break;
        default: OPTION_MISSION(); break;
    }

    printf("\n\tFaites votre choix: ");
    scanf("%d",&choix);

    switch(choix){
        case 1 : if(type=='N'){
                    Jouer_Partie(Jeu); break;
                 }
                 else if(type=='T'){
                    Jouer_Special(Jeu); break;
                 }
                 else if(type=='C'){
                    Jouer_Partie_Cartes(Jeu); break;
                 }
                 else{
                    Jouer_Mission(Jeu,type); break;
                 }

        case 2 : if(type=='N'){
                    Sauvegarde(Jeu,'N'); //N pour Normal
                    break;
                 }
                 else if(type=='T'){
                    Sauvegarde(Jeu,'T'); //T pour Torique/Spécial
                    break;
                 }
                 else{
                    system("cls");
                    AIDE();
                    system("pause >nul");
                    if(type=='C'){
                        Jouer_Partie_Cartes(Jeu); break;
                    }
                    else{
                    Jouer_Mission(Jeu,type); break;
                    }
                 }

        case 3 : if(type=='N'){
                    system("cls"); //On efface la console
                    AIDE();
                    scanf("%s",retour);
                    Jouer_Partie(Jeu);
                    break;
                 }
                 else if(type=='T'){
                        system("cls"); //On efface la console
                        AIDE();
                        scanf("%s",retour);
                        Jouer_Special(Jeu);
                        break;
                 }
                 else{
                    printf("\n\tErreur de saisie! \n");
                    printf("\n\tAppuyer sur une touche : ");
                    system("pause >nul");
                    if(type=='C'){
                        Jouer_Partie_Cartes(Jeu); break;
                    }
                    else{
                    Jouer_Mission(Jeu,type); break;
                    }
                 }

        case 0 : free(Jeu);
                 k = main();
                 break;

        default : printf("\n\tErreur de saisie! \n");
                  printf("\n\tAppuyer sur une touche : "); system("timeout 2 >nul");
                  scanf("%s",vide);
                  if(type=='N'){
                    Jouer_Partie(Jeu); break;
                  }
                  else if(type=='T'){
                    Jouer_Special(Jeu); break;
                  }
                  else if(type=='C'){
                        Jouer_Partie_Cartes(Jeu); break;
                  }
                  else{
                    Jouer_Mission(Jeu,type); break;
                  }
    }
}


//===================================
/** Cette fonction affiche les aides
    pour progresser dans le jeu
**/
void Need_Help(Plateau *Jeu)
{
    int choix;
    char vide[2];

    system("cls"); //On efface la console
    COUP(); //On affiche le menu d'aide
    scanf("%d",&choix);
    switch(choix){
        case 1 : coups_Possibles(Jeu);
                 break;

        case 2 : meilleur_coup(Jeu); break;

        default : printf("\n\tChoix inexistant!");
                  system("timeout 2 >nul");
                  scanf("%s",vide);
                  Jouer_Partie(Jeu);
                  break;
    }
}

//===================================
/**
    Cette fonction affiche les coordonnées
    des jetons qui sont dans une combinaison
    les tests sont effectués en fonction du type de jeu
*/
void Coordonnees_Jetons_Alignes(Plateau *surface, char type)
{
    int i,j;

    if(type=='N'){//Si nous jouons une partie normale (avec/sans carte, multijoueur)
        for(i=0 ; i<surface->hauteur ; i++){
            for(j=0 ; j<surface->largeur ; j++){
                if(Test_Combinaison(surface,i,j)==1)
                    afficheValeursReels(i,j);
            }
        }
    }
    else{ //Si ce n'est pas une partie normale (mission, torique)
        for(i=0 ; i<surface->hauteur ; i++){
            for(j=0 ; j<surface->largeur ; j++){
                if(Test_Alignement_Torique(surface,i,j)==1 || Test_Alignement_Diagonal(surface,i,j)==1
                   || Test_Alignement_Special(surface,i,j)==1)
                    afficheValeursReels(i,j);
            }
        }
    }
}


//===================================
/** Cette fonction permet de sauvegarder
    une partie en cours en fonction de son type
**/
void Sauvegarde(Plateau *jeu, char type)
{
    char nom[30];
    int i,j;
    FILE *fd;

    printf("\n\tEcrivez le nom de la sauvegarde sans extension: ");
    scanf("%s",nom);

    if(strcmp(nom," ")==0){
        printf("\n\tNom obligatoire!\n");
        system("timeout 2 >nul");
        Jouer_Partie(jeu);
    }
    else{
        fd = fopen(nom,"w");
        //On enregistre le type de la partie
        fprintf(fd,"%c\n",type);
        //On sauvegarde la hauteur et la largeur de la surface de jeu
        fprintf(fd,"%d %d\n",jeu->hauteur,jeu->largeur);
        //On sauvegarde le nbre de deplacements
        fprintf(fd,"%d\n",jeu->deplacement);
        //On enregistre le nbre de couleurs
        fprintf(fd,"%d\n",jeu->nbcouleur);
        //On sauvegarde le score
        fprintf(fd,"%d\n",jeu->score);
        //On sauvegarde le tableau de jeton
        for(i=0 ; i<jeu->hauteur ; i++){
            for(j=0 ; j<jeu->largeur ; j++){
                fprintf(fd,"%d",jeu->tab[i][j].couleur);
            }
        fprintf(fd,"\n"); //On fait retour a la ligne
        }
        printf("\n\tSauvegarde effectuee avec succes!\n");
        system("timeout 2 >nul");
        fclose(fd); //On ferme le fichier
        Options(jeu,type);
        //Jouer_Partie(jeu);
    }

}

//===================================
/** Cette fonction permet de charger une partie
    qui a deja ete sauvegardée afin de la continuer
**/
void Chargement()
{
    int i,j,k;
    char type; //Type de la partie
    Plateau *jeu = (Plateau*)malloc(sizeof(Plateau));
    char nom[30];
    FILE *fd;
    char couleur[2];

    printf("\n\tVeuillez entrer le nom du fichier sans extension: ");
    scanf("%s",nom);

    //Ouverture du fichier
    fd = fopen(nom,"r");

    if(fd==NULL){
        printf("\n\tCe fichier n'existe pas\n");
        system("timeout 2 >nul");
        k = main();
    }
    else{
        /** Recuperation du contenu du fichier **/

        //On recupere le type de la partie
        fscanf(fd,"%c",&type);
        //Recuperation de la hauteur et la largeur de la surface de jeu
        fscanf(fd,"%d %d",&(jeu->hauteur),&(jeu->largeur));
        //Recuperation du nbre de deplacments
        fscanf(fd,"%d",&(jeu->deplacement));
        //Recuperation du nbre de couleurs
        fscanf(fd,"%d",&(jeu->nbcouleur));
        //Recuperation du score
        fscanf(fd,"%d",&(jeu->score));

        //Allocation du tableau
        jeu->tab = (Jeton**)malloc(jeu->hauteur * sizeof(Jeton*));
        for(i=0 ; i<jeu->hauteur ; i++){
            jeu->tab[i] = (Jeton*)malloc(jeu->largeur * sizeof(Jeton));
        }

        //On rempli le tableau
        for(i=0 ; i<jeu->hauteur ; i++){
            for(j=0 ; j<jeu->largeur ; j++){
                //Ne surtout pas oublier la tabulation pour l'affichage sur le plateau de jeu
                fscanf(fd,"\t%c",couleur);
                jeu->tab[i][j].couleur = (int)couleur[0] - 48;
            }
        }
        fclose(fd);
        printf("\n\tChargement reussi\n");
        system("timeout 2 >nul");
        if(type=='N'){ //Si partie normale
            system("color 0F");
            Jouer_Partie(jeu);
        }
        else if(type=='T'){ //Si partie spéciale
            system("color 3F");
            Jouer_Special(jeu);
        }
        else{
            printf("\n\tFichier corrompu!\n"); system("timeout 2 >nul");
            k = main();
        }
    }
}

//===============================
/**
    Cette fonction trie la liste
    des scores:

*/
void Tri_Score(T_Score *tab, int taille)
{
    int i;
    int j;
    T_Score tmp;
    for(i=0 ; i<taille-1 ; i++){
        for(j=i+1 ; j<taille ; j++){
            if(tab[i].valeur<tab[j].valeur){
                strcpy(tmp.nom,tab[i].nom);
                tmp.valeur = tab[i].valeur;
                strcpy(tab[i].nom,tab[j].nom);
                tab[i].valeur = tab[j].valeur;
                strcpy(tab[j].nom,tmp.nom);
                tab[j].valeur = tmp.valeur;
            }
        }
    }
}


//===============================
/**
    Cette fonction affiche la liste
    des meilleurs scores
*/
void Affiche_Score()
{
    int i;
    char joueur[10];
    int valeur;
    int nbre;
    FILE *fd = NULL;

    system("cls"); //On efface l'ecran
    fd = fopen("best_score.bak","r"); //Ouverture du fichier

    if(fd==NULL){
        printf("\n\tLISTE DES SCORES VIDE!\n");
        printf("\n\tAppuyez sur une touche pour revenir au menu: ");
        system("pause >nul");
        int k = main();
    }
    else{
        //On recupere le nombre d'enregistrements
        fscanf(fd,"%d",&nbre);
        if(nbre<=0){
            printf("\n\n\n\tLISTE VIDE\n\n");
            fclose(fd);
            system("timeout 3 >nul");
            int k = main();
        }
        printf("\n\n\t\t\t LISTE DES MEILLEURS SCORES");
        printf("\n\n\n");
        printf("\t    -------------------------------------------------\n");
        printf("\t   |       Nom du joueur       |        Score        |\n");
        printf("\t    -------------------------------------------------\n");

        for(i=0 ; i<nbre; i++){
            fscanf(fd,"%9s %d",joueur,&valeur);
            printf("\t   |\t%9s\t       |     %7d\t     |\n",joueur,valeur);
            printf("\t    -------------------------------------------------\n");
        }
    }
    fclose(fd); //On ferme le fichier
    printf("\n\tAppuyez sur une touche pour revenir au menu: ");
    system("pause >nul");
    int k = main();
}


//===============================
/**
    Sauvegarde du score.
    Retourne:
    1: si sauvegarde effectuee
    0: sinon
**/

int Best_Score(Plateau *surface, char *joueur)
{
    int i;
    int nouveau_score = 0; //etat du score a enregistrer
    FILE *fd = NULL;
    int nbre = 0; //Utiliser pour calculer le nbre d'enregistrements
    int compte; //variable qui recupere le nbre d'enregistrement
    int valeur; //variable qui recupere le score d'un joueur
    char tmp[10]; //variable qui recupere le nom d'un joueur
    T_Score tab[10]; //tableau qui sert a recuperer tous les enregistrements de score

    fd = fopen("best_score.bak","r"); //Ouverture du ichier en lecture

    if(fd==NULL){ //SI le fichier n'existe pas
        //On le cree
        fd = fopen("best_score.bak","w");
        if(fd==NULL) return 0;
        else{ //S'il est ouvert, on le remplit
            nbre++;
            fprintf(fd,"%d\n",nbre); //On enregistre le nbre d'elements
            fprintf(fd,"%9s %d\n",joueur,surface->score);
            fclose(fd);
            return 1;
        }
    }
    else{//Si le fichier existe
         //On recupere le nbre d'enregistrements
         fscanf(fd,"%d",&compte);
         //On recupere les infos
         for(i=0 ; i<compte ; i++){
            fscanf(fd,"%9s %d",tmp,&valeur);
            strcpy(tab[i].nom,tmp); //On recupere le nom du joueur
            tab[i].valeur = valeur; //On recupere son score
         }
         fclose(fd);//On ferme le fichier

         if(compte<TOP){ //S'il y a de la place pour enregistrer des scores

            fd = fopen("best_score.bak","w");
            if(fd==NULL)
                return 0;
            else{
                strcpy(tab[compte].nom,joueur);
                tab[compte].valeur = surface->score;
                compte++;
                //On trie la liste
                Tri_Score(tab,compte);
                //On sauvegarde le nbre d'elements
                fprintf(fd,"%d\n",compte);
                for(i=0 ; i<compte ; i++){
                    fprintf(fd,"%9s %d\n",tab[i].nom,tab[i].valeur);
                }
                fclose(fd); //On ferme le fichier
                return 1;
            }
         }
         else{ //S'il n'y a plus de place dans la liste
            //On trie la liste
            Tri_Score(tab,compte);

            //On compare le score du joueur aux enregistrements
            for(i=compte ; i>0 ; i--){
                if(surface->score >= tab[i].valeur){
                    nouveau_score = 1; //on a un nveau score
                    if(i>0){ //On decale les infos de la liste
                        strcpy(tab[i-1].nom,tab[i].nom);
                        tab[i-1].valeur = tab[i].valeur;
                    }
                    //On insere les nouvelles donnees
                    strcpy(tab[i].nom,joueur);
                    tab[i].valeur = surface->score;
                    break; //On sort de la boucle
                }
            }
            //Si on a un nouveau meilleur score
            if(nouveau_score==1){
                fd = fopen("best_score.bak","w");
                if(fd==NULL) return 0;
                else{
                    //On trie la liste
                    Tri_Score(tab,compte);
                    //On enregistre le nbre d'elements
                    fprintf(fd,"%d\n",compte);
                    for(i=0 ; i<compte ; i++){
                        fprintf(fd,"%9s %d\n",tab[i].nom,tab[i].valeur);
                    }
                    fclose(fd);
                    return 1;
                }
            } //Si on a pas un nouveau score
            else return 0;
         }
    }
}
