/**
###########################################################
#         OPTIONS SPECIALES + CORPS DES FONCTIONS         #
###########################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "structures.h"
#include "plateau.h"
#include "messages.h"
#include "outils.h"
#include "jeu.h"
#include "special.h"


//         --------------------------------------------------------------
//        |                 ALIGNEMENTS SPECIAUX                         |
//         --------------------------------------------------------------

//===================================
/**
    Cette fonction teste si des jetons de meme couleur sont
    alignés diagonalement, elle renvoie
    1: s'il y a Alignement
    0: s'il n'y a pas alignement
    NB: On compare la couleur du jeton à celle de ses voisins
        selon sa position sur le plateau de jeu
**/
int Test_Alignement_Diagonal(Plateau *surface, int x, int y)
{
    /*Cas 1: x=0  et y=0 ou y=1*/
    //Nous sommes sur la 1ere ligne et dans la 1ere ou 2eme colonne
    if(x==0 && (y==0 || y==1)){
        if(Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x+2,y+2)==1)
            return 1;
        else
            return 0;
    }

    /*Cas 2: x=1 et y=0 */
    //Nous sommes sur la 1ere ligne et dans la 1ere colonne
    if(x==1 && y==0){
        if(Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x+2,y+2)==1)
            return 1;
        else
            return 0;
    }

    /*Cas 3: x=1 et y=1 */
    //Nous sommes sur la 1ere ligne et dans la 2eme colonne
    if(x==1 && y==1){
        if((Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x+2,y+2)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 4: x=0 et y=surface->largeur-1 ou y=surface->largeur-2 */
    if(x==0 && (y==surface->largeur-1 || y==surface->largeur-2)){
        if(Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x+2,y-2)==1)
            return 1;
        else
            return 0;
    }

    /*Cas 5: x=1 et y=surface->largeur-1 */
    if(x==1 && y==surface->largeur-1){
        if(Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x+2,y-2)==1)
            return 1;
        else
            return 0;
    }

    /*Cas 6: x=1 et y=surface->largeur-2 */
    //Nous sommes sur la 2eme ligne dans l'avant-derniere colonne
    if(x==1 && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x+2,y-2)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 7: x=0 et y>1 et y<surface->largeur-3 */
    //Nous sommes sur la 1ere ligne
    if(x==0 && (y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x+2,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x+2,y+2)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 8: x=1 et y>1 et y<=surface->largeur-3 */
    //Nous sommes sur la 2eme ligne
    if(x==1 && (y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x+2,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x+2,y+2)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 9: x>1 et x<surface->hauteur-3 et y=0 */
    //Nous sommes dans la premiere colonne
    if((x>=2 && x<=surface->hauteur-3) && y==0){
        if((Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x-2,y+2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x+2,y+2)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 10: x>1 et x<=surface->hauteur-3 et y=1 */
    //Nous sommes dans la 2eme colonne
    if((x>=2 && x<=surface->hauteur-3) && y==1){
        if((Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x-2,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x-1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x+2,y+2)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 11: x>1 et x<=surface->hauteur-3 et y=surface->largeur-1 */
    //Nous sommes dans la derniere colonne
    if((x>=2 && x<=surface->hauteur-3) && y==surface->largeur-1){
        if((Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x-2,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x+2,y-2)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 12: x>1 et x<=surface->hauteur-3 et y=surface->largeur-2 */
    //Nous sommes dans l'avant-derniere colonne
    if((x>=2 && x<=surface->hauteur-3) && y==1){
        if((Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x-2,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x-1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x+2,y-2)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 13: x=surface->hauteur-1 et y=0 ou y=1 */
    //Nous sommes sur la derniere ligne et dans la 1ere ou 2eme colonne
    if(x==surface->hauteur-1 && (y==0 || y==1)){
        if(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x-2,y+2)==1)
            return 1;
        else
            return 0;
    }

    /*Cas 14: x=surface->hauteur-2 et y=0 */
    //Nous sommes sur l'avant-derniere ligne et dans la 1ere colonne
    if(x==surface->hauteur-2 && y==0){
        if(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x-2,y+2)==1)
            return 1;
        else
            return 0;
    }

    /*Cas 15: x=surface->hauteur-2 et y=1 */
    //Nous sommes sur l'avant-derniere ligne et dans la 2eme colonne
    if(x==surface->hauteur-2 && y==1){
        if((Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x-2,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 16: x=surface->hauteur-1 et y=surface->largeur-1 ou y=surface->largeur-2 */
    //Nous sommes sur la derniere ligne et dans la derniere ou l'avant-derniere colonne
    if(x==surface->hauteur-1 && (y==surface->largeur-1 || y==surface->largeur-2)){
        if(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x-2,y-2)==1)
            return 1;
        else
            return 0;
    }

    /*Cas 17: x=surface->hauteur-2 et y=surface->largeur-1 */
    //Nous sommes sur l'avant-derniere ligne et dans la derniere colonne
    if(x==surface->hauteur-2 && y==surface->largeur-1){
        if(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x-2,y-2)==1)
            return 1;
        else
            return 0;
    }
    /*Cas 17: x=surface->hauteur-2 et y=surface->largeur-2 */
    //Nous sommes sur l'avant-derniere ligne et dans l'avant-derniere colonne
    if(x==surface->hauteur-2 && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x-2,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1))
            return 1;
        else
            return 0;
    }

    /*Cas 19: x=surface->hauteur-1 et y>1 et y<=surface->largeur-3 */
    //Nous sommes sur la derniere ligne
    if(x==surface->hauteur-1 && (y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x-2,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x-2,y+2)==1))
           return 1;
        else
            return 0;
    }

    /*Cas 20: x=surface->hauteur-2 et y>1 et y<=surface->largeur-3 */
    //Nous sommes sur l'avant-derniere ligne
    if(x==surface->hauteur-2 && (y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x-2,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x-2,y+2)==1))
           return 1;
        else
            return 0;
    }

    /*Cas 21: CAS GENERAL */
    //De maniere generale
    if((Compare_Forme(surface,x,y,x+1,y+1)==1 && Compare_Forme(surface,x,y,x+2,y+2)==1)
       ||(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x-2,y-2)==1)
       ||(Compare_Forme(surface,x,y,x+1,y-1)==1 && Compare_Forme(surface,x,y,x+2,y-2)==1)
       ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x-2,y+2)==1)
       ||(Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
       ||(Compare_Forme(surface,x,y,x-1,y+1)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1))
        return 1;
    else
        return 0;

    /**FIN DES TESTS DES ALIGNEMENTS DIAGONAUX**/
}

//===================================
/**
    Cette fonction teste si des jetons de meme couleur sont
    alignés de maniere torique car le plateau n'a pas de bordure.
    Elle renvoie
    1: s'il y a Alignement
    0: s'il n'y a pas alignement
    NB: On compare la couleur du jeton à celle de ses voisins
        selon sa position sur le plateau de jeu
**/
int Test_Alignement_Torique(Plateau *surface, int x, int y)
{
    //Cas basique,si le pion se trouve au milieu d'une combinaison de 3 pions
    if(y!=0 && y!=surface->largeur-1 && Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
		return 1;

    if(x!=0 && x!=surface->hauteur-1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
		return 1;

    //Cas 1: x=0 et y=0
    //Nous sommes dans la 1ere case du plateau
    if(x==0 && y==0){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,surface->hauteur-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,surface->largeur-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-2)==1))
            return 1;
        else
            return 0;
    }

    //Cas 2: x=0 et y=1
    //Nous sommes sur la 1ere ligne et dans la 2eme colonne
    if(x==0 && y==1){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-1)==1)
           ||(Compare_Forme(surface,x,y,surface->hauteur-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-2,y)==1))
           return 1;
        else
            return 0;
    }

    //Cas 3: x=0 et y=surface->largeur-1
    //Nous sur la 1ere ligne et dans la derniere colonne
    if(x==0 && y==surface->largeur-1){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x,0)==1 && Compare_Forme(surface,x,y,x,1)==1)
           ||(Compare_Forme(surface,x,y,surface->hauteur-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 4: x=0 et y=surface->largeur-2
    //Nous sommes sur la 1ere ligne et dans l'avant-derniere colonne
    if(x==0 && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,0)==1)
           ||(Compare_Forme(surface,x,y,surface->hauteur-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-2,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 5: x=1 et y=0
    //Nous sommes sur la 2eme ligne et dans la 1ere colonne
    if(x==1 && y==0){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-1,y)==1)
           ||(Compare_Forme(surface,x,y,x,surface->largeur-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-2)==1))
            return 1;
        else
            return 0;
    }

    //Cas 6: x=1 et y=1
    //Nous sommes sur la 2eme ligne et dans la 2eme colonne
    if(x==1 && y==1){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-1,y)==1))
           return 1;
        else
            return 0;
    }

    //Cas 7: x=1 et y=surface->largeur-1
    //Nous sommes sur la 2eme ligne et dans la derniere colonne
    if(x==1 && y==surface->largeur-1){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,0)==1 && Compare_Forme(surface,x,y,x,1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-1,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 8: x=1 et y=surface->largeur-2
    //Nous sommes sur la 2eme ligne dans l'avant-derniere colonne
    if(x==1 && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,0)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-1,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 9: x=0 et y>1 et y<surface->largeur-2
    //Nous sommes sur la 1ere ligne
    if(x==0 && (y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,surface->hauteur-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-2,y)==1))
           return 1;
        else
            return 0;
    }

    //Cas 10: x=1 et y>1 et y<surface->largeur-2
    //Nous sommes sur la 2eme ligne
    if(x==1 && (y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,surface->hauteur-1,y)==1))
           return 1;
        else
            return 0;
    }

    //Cas 11: x=surface->hauteur-1 et y=0
    //Nous sommes sur la derniere ligne et dans la 1ere colonne
    if(x==surface->hauteur-1 && y==0){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,0,y)==1 && Compare_Forme(surface,x,y,1,y)==1)
           ||(Compare_Forme(surface,x,y,x,surface->largeur-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-2)==1))
            return 1;
        else
            return 0;
    }

    //Cas 12: x=surface->hauteur-1 et y=1
    //Nous sommes sur la derniere ligne et dans la 2eme colonne
    if(x==surface->hauteur-1 && y==1){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,0,y)==1 && Compare_Forme(surface,x,y,1,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-1)==1))
            return 1;
        else
            return 0;
    }

    //Cas 13: x=surface->hauteur-1 et y=surface->largeur-1
    //Nous sommes dans la derniere case du plateau
    if(x==surface->hauteur-1 && y==surface->largeur-1){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,0,y)==1 && Compare_Forme(surface,x,y,1,y)==1)
           ||(Compare_Forme(surface,x,y,x,0)==1 && Compare_Forme(surface,x,y,x,1)==1))
            return 1;
        else
            return 0;
    }

    //Cas 14: x=surface->hauteur-1 et y=surface->largeur-2
    //Nous sommes sur la derniere ligne et dans la l'avant-derniere colonne
    if(x==surface->hauteur-1 && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,0,y)==1 && Compare_Forme(surface,x,y,1,y)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,0)==1))
            return 1;
        else
            return 0;
    }

    //Cas 15: x=surface->hauteur-2 et y=0
    //Nous sommes sur l'avant-derniere ligne et dans la 1ere colonne
    if(x==surface->hauteur-2 && y==0){
       if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,0,y)==1)
           ||(Compare_Forme(surface,x,y,x,surface->largeur-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-2)==1))
            return 1;
        else
            return 0;
    }

    //Cas 16: x=surface->hauteur-2 et y=1
    //Nous sommes sur l'avant-derniere ligne et dans la 2eme colonne
    if(x==surface->hauteur-2 && y==1){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,0,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-1)==1))
            return 1;
        else
            return 0;
    }

    //Cas 17: x=surface->hauteur-2 et y=surface->largeur-1
    //Nous sommes sur l'avant-derniere ligne et dans la derniere colonne
    if(x==surface->hauteur-2 && y==surface->largeur-1){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,0)==1 && Compare_Forme(surface,x,y,x,1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,0,y)==1))
            return 1;
        else
            return 0;
    }

    //Cas 18: x=surface->hauteur-2 et y=surface->largeur-2
    //Nous sommes sur l'avant-derniere ligne et dans l'avant-derniere colonne
    if(x==surface->hauteur-2 && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,0,y)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,0)==1))
            return 1;
        else
            return 0;
    }

    //Cas 19: x=surface->hauteur-1 et y>1 et y<surface->largeur-2
    //Nous sommes sur la derniere ligne
    if(x==surface->hauteur-1 &&(y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,0,y)==1 && Compare_Forme(surface,x,y,1,y)==1))
           return 1;
        else
            return 0;
    }

    //Cas 20: x=surface->hauteur-2 et y>1 et y<surface->largeur-2
    //Nous sommes sur l'avant-derniere ligne
    if(x==surface->hauteur-2 &&(y>=2 && y<=surface->largeur-3)){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,0,y)==1))
           return 1;
        else
            return 0;
    }

    //Cas 21: x>1 et x<surface->hauteur-2 et y=0
    //Nous sommes dans la 1ere colonne
    if((x>=2 && x<=surface->hauteur-3) && y==0){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,surface->largeur-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-2)==1))
            return 1;
        else
            return 0;
    }

    //Cas 22: x>1 et x<surface->hauteur-2 et y=1
    //Nous sommes dans la 2eme colonne
    if((x>=2 && x<=surface->hauteur-3) && y==1){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,surface->largeur-1)==1))
            return 1;
        else
            return 0;
    }

    //Cas 23: x>1 et x<surface->hauteur-2 et y=surface->largeur-1
    //Nous sommes dans la derniere colonne
    if((x>=2 && x<=surface->hauteur-3) && y==surface->largeur-1){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,0)==1 && Compare_Forme(surface,x,y,x,1)==1))
            return 1;
        else
            return 0;
    }

    //Cas 24: x>1 et x<surface->hauteur-2 et y=surface->largeur-2
    //Nous sommes dans l'avant-derniere colonne
    if((x>=2 && x<=surface->hauteur-3) && y==surface->largeur-2){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
           ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
           ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,0)==1))
            return 1;
        else
            return 0;
    }

    //Cas 25: CAS GENERAL
    //De maniere generale
    if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y-2)==1)
        ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x,y+2)==1)
        ||(Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+2,y)==1)
        ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-2,y)==1)
        ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x+1,y)==1)
        ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x,y+1)==1))
        return 1;
    else
        return 0;

    /**FIN DES TESTS DES ALIGNEMENTS TORIQUES**/
}

//===================================
/**
    Cette fonction teste si des jetons de meme couleur sont
    alignés de maniere speciale (en carre).
    Elle renvoie
    1: s'il y a Alignement
    0: s'il n'y a pas alignement
    NB: On compare la couleur du jeton à celle de ses voisins
        selon sa position sur le plateau de jeu
**/
int Test_Alignement_Special(Plateau *surface, int x, int y)
{
    //Cas 1: x=0 et y=0
    //Nous sommes sommes dans la 1ere case du plateau
    if(x==0 && y==0){
        if(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
            return 1;
        else
            return 0;
    }

    //Cas 2: x=0 et y=1 ou y=surface->largeur-2
    //Nous sommes sur la 1ere ligne et entre la 2eme et l'avant-derniere colonne
    if(x==0 && (y>=1 || y<=surface->largeur-2)){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1))
            return 1;
        else
            return 0;
    }

    //Cas 3: x=1 ou x=surface->hauteur-2 et y=0
    //Nous sommes entre la 2eme et l'avant-derniere ligne et dans la 1ere colonne
    if((x>=1 || x<=surface->hauteur-2) && y==0){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x-1,y+1)==1))
            return 1;
        else
            return 0;
    }


    //Cas 4: x=0 et y=surface->largeur-1
    //Nous sommes sur la 1ere ligne et dans la derniere colonne
    if(x==0 && y==surface->largeur-1){
       if(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
          return 1;
       else
          return 0;
    }

    //Cas 5: x=1 ou x=surface->hauteur-2 et y=surface->largeur-1
    //Nous sommes entre la 2eme et l'avant-derniere ligne ligne et dans la derniere colonne
    if((x>=1 || x<=surface->hauteur-2)&& y==surface->largeur-1){
        if((Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-1,y-1)==1))
            return 1;
        else
            return 0;
    }

    //Cas 6: x=surface->hauteur-1 et y=0
    //Nous sommes dans sur la derniere ligne et dans la 1ere colonne
    if(x==surface->hauteur-1 && y==0){
        if(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-1,y+1)==1)
            return 1;
        else
            return 0;
    }

    //Cas 7: x=surface->hauteur-1 et y=1 ou y=surface->largeur-2
    //Nous sommes sur la derniere ligne et entre la 2eme ou l'avant-derniere colonne
    if(x==surface->hauteur-1 && (y>=1 || y<=surface->largeur-2)){
        if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-1,y+1)==1)
           ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-1,y-1)==1))
            return 1;
        else
            return 0;
    }

    //Cas 8: x=surface->hauteur-2 et y=surface->largeur-1
    //Nous sommes dans la derniere case du plateau
    if(x==surface->hauteur-1 && y==surface->largeur-1){
        if(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-1,y-1)==1)
            return 1;
        else
            return 0;
    }


    // CAS GENERAL
    if((Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y+1)==1)
        ||(Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-1,y-1)==1 && Compare_Forme(surface,x,y,x,y-1)==1)
        ||(Compare_Forme(surface,x,y,x,y-1)==1 && Compare_Forme(surface,x,y,x+1,y)==1 && Compare_Forme(surface,x,y,x+1,y-1)==1)
        ||(Compare_Forme(surface,x,y,x,y+1)==1 && Compare_Forme(surface,x,y,x-1,y)==1 && Compare_Forme(surface,x,y,x-1,y+1)==1))
        return 1;
    else
        return 0;


    /**FIN DES TESTS D'ALIGNEMENTS SPECIAUX**/
}

//         --------------------------------------------------------------
//        |     ELIMINER + FILTRER + JOUER DANS UN PLATEAU SPECIAL       |
//         --------------------------------------------------------------

//=======================================
/**
    Cette fonction élimine les jetons qui sont
    alignés de manière spéciale: en carré, en
    diagonal ou de manière torique.
    E: signifie "vide
    Et retourne le score obtenu
*/

int Eliminer_Jeton(Plateau *surface)
{
    int i,j;
    int score;
    int compt = 0;

    //On cree un plateau avec les memes dimension que surface
    Plateau *tmp = Creation_Plateau(surface->hauteur,surface->largeur);

    //Clone notre plateau de jeu
    for(i=0 ; i<tmp->hauteur ; i++){
        for(j=0 ; j<tmp->largeur ; j++){
            tmp->tab[i][j].couleur = surface->tab[i][j].couleur;
        }
    }

    //On effectue les tests d'alignement sur le clone et on marque l'original
    for(i=0 ; i<surface->hauteur ; i++){
        for(j=0 ; j<surface->largeur ; j++){
            if(Test_Alignement_Torique(tmp,i,j)==1 || Test_Alignement_Diagonal(tmp,i,j)==1
               || Test_Alignement_Special(tmp,i,j)==1){
                if(surface->tab[i][j].couleur=='E') //Si le jeton a déja été marqué
                    compt++;
                else{
                    surface->tab[i][j].couleur='E';
                    compt++;
                }
            }
        }
    }

    //Calcul du score obtenu
    score = compt * compt;
    free(tmp);
    return score;
}

//============================
/** Cette fonction parcours le plateau
    Et elle renvoie
    0 : s'il y a un alignement
    1 : s'il n'y a pas d'alignement
**/
int Test_Filtre_Plateau(Plateau *surface)
{
    int i,j;

    for(i=0 ; i<surface->hauteur ; i++){
        for(j=0 ; j<surface->largeur ; j++){
            if(Test_Alignement_Torique(surface,i,j)==1 || Test_Alignement_Diagonal(surface,i,j)==1
               || Test_Alignement_Special(surface,i,j)==1)
                return 0;
        }
    }
    return 1;
}

//============================
/** Pour chaque jeton, cette fonction verifie s'il est dans une combinaison,
    si tel est le cas, elle modifie sa couleur.
    Enfin, si le plateau n'est toujours pas filtré, on repète l'operation
*/
void Filtrer_Plateau(Plateau *surface)
{
    int i,j;
    for(i=0 ; i<surface->hauteur ; i++){
        for(j=0 ; j<surface->largeur ; j++){
            if(Test_Alignement_Torique(surface,i,j)==1 || Test_Alignement_Diagonal(surface,i,j)==1
               || Test_Alignement_Special(surface,i,j)==1)
              surface->tab[i][j].couleur = rand() % surface->nbcouleur;
        }
    }
    if(Test_Filtre_Plateau(surface)==0)
        Filtrer_Plateau(surface);
}

//=======================================
/**
    Cette fonction permet de jouer une partie spéciale
    avec alignement torique, en carré et diagonal
*/

void Jouer_Special(Plateau *surface)
{
    char vide[2],erreur[2];
    int xd,yd; //Position de départ
    int x,y; //Position d'arrivee
    char ok[2]; //Reponse du deplacement
    Plateau *surfacePred; //Clone du plateau de jeu
    char coup[6];
    int option=-1;
    int arriere=-1;
    int sup;

    //On clone le plateau de jeu
    surfacePred = clone_Plateau(surface);

    while(surface->deplacement > 0){
        system("cls"); /* Efface l'écran */

        //Tant qu'il y a des combinaisons, on les elimine
        while(Test_Filtre_Plateau(surface)==0){
            Affiche_Plateau(surface);
            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
            printf("\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'T'); system("timeout 2 >nul");
            sup = Eliminer_Jeton(surface) * 5; //On fait un peetit bonus

            system("cls");
            Affiche_Plateau(surface);
            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
            printf("\n\n\t\tScore supplementaire: +%d",sup);

            system("timeout 3 >nul");
            surface->score += sup;
            Completer_Plateau(surface);
            system("cls");
        }

        Affiche_Plateau(surface);

        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);

        // Mise a zero du coup precedent
        xd = yd = x = y = -1;

        /** La lecture se fait en (Y,X)
           R(O,oy,ox); ==> y1=xd ; x1=yd ; y2=x et x2=y
           Plus facile a la programmation(comprehension) car Remplissage(et Parcours)
           du plateau de jeu dans le sens de la Hauteur
        **/

        printf("\n\tPour visualiser les options, taper \"O\"\n");
        printf("\tPour revenir en arriere, taper \"R\" [cout: 2 deplacement et 100pts]\n");

        //Saisie du deplacement a effectuer
        printf("\n\tQue jouez-vous? : ");
        scanf("%s",coup);

        //Test sur les valeurs saisie

        option = (strcmp(coup,"O")==0); //Si resultat vaut 0 ==> ON AFFICHE LE MENU DES OPTIONS
        arriere = (strcmp(coup,"R")==0); //Si resultat vaut 0 ==> ON REVIENT AU COUP PRECEDENT

        if(!option && !arriere){
            //On recupere l'ordonnee du pion a deplacer
            if(coup[0]=='a' || coup[0]=='A') yd = 0;
            else if(coup[0]=='b' || coup[0]=='B') yd = 1;
            else if(coup[0]=='c' || coup[0]=='C') yd = 2;
            else if(coup[0]=='d' || coup[0]=='D') yd = 3;
            else if(coup[0]=='e' || coup[0]=='E') yd = 4;
            else if(coup[0]=='f' || coup[0]=='F') yd = 5;
            else if(coup[0]=='g' || coup[0]=='G') yd = 6;
            else if(coup[0]=='h' || coup[0]=='H') yd = 7;
            else if(coup[0]=='i' || coup[0]=='I') yd = 8;
            else if(coup[0]=='j' || coup[0]=='J') yd = 9;

            //48 correspond au caractere zero '0': on aurait pu faire (int)coup - '0'
            xd = ((int)coup[1] - 48) * 10 + ((int)coup[2] - 48); //On recupere l'abscisse du pion a deplacer

            //On recupere les coordonnees de la destinationPlateau *tmp = Creation_Plateau(surface->hauteur,surface->largeur);
            if(coup[4]=='h'||coup[4]=='H'){
                y = yd;
                x = xd - 1;
            }
            else if(coup[4]=='D' || coup[4]=='d'){
                y = yd + 1;
                x = xd;
            }
            else if(coup[4]=='G' || coup[4]=='g'){
                y = yd - 1;Plateau *tmp = Creation_Plateau(surface->hauteur,surface->largeur);
                x = xd;
            }
            else if(coup[4]=='B' || coup[4]=='b'){
                y = yd;
                x = xd + 1;
            }
            //Test sur les coordonnees entrees: xd,x €[1;15] et yd,y €[0;9]
            if(coup[3]!='-' || yd<-1 || yd>surface->largeur || xd<1 || xd>surface->hauteur+1 || y<-1
               || y>surface->largeur || x<0 || x>surface->hauteur+1){
                printf("\n\tMauvaises coordonnees saisies!\n\n");
                printf("\tAppuyer sur une touche puis sur \"ENTREE\": ");
                scanf("%s",erreur);
            }
            else{

                printf("\n\tConfirmer le deplacement Y/N ? : ");
                scanf("%s",ok);//Confirmation de permutation de jetons

                if(strcmp(ok,"Y")==0 || strcmp(ok,"y")==0){//Si OUI, on effectue le deplacement
                    xd--; //On recupere les valeurs reelles de xd et x
                    x--;  //en fonction de la structure du plateau de jeu

                    if(y<0) y = surface->largeur-1; //Le tableau n'a pas de bord

                    if(y>=surface->largeur) y = 0; //Le tableau n'a pas de bord

                    if(x<0) x = surface->hauteur-1; //Le tableau n'a pas de bord

                    if(x>=surface->hauteur) x = 0; //Le tableau n'a pas de bord

                    //On clone le plateau de jeu
                    surfacePred = clone_Plateau(surface);

                    //On permute les jetons
                    Echanger_Position(surface,xd,yd,x,y);

                    //On teste les alignements des jetons
                    if(Test_Alignement_Torique(surface,x,y)==1 || Test_Alignement_Torique(surface,xd,yd)==1){
                        printf("\n\tIl y a alignement de: "); Coordonnees_Jetons_Alignes(surface,'T');
                        system("timeout 2 >nul");
                        sup = Eliminer_Jeton(surface);

                        system("cls");
                        Affiche_Plateau(surface);
                        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                        printf("\n\n\t\tScore supplementaire: +%d",sup);
                        surface->score += sup;

                        system("timeout 2 >nul");
                        Completer_Plateau(surface); //on remplit les espaces vides laissés
                        surface->deplacement--; //On resuit le nbre de deplcements
                    }
                    else if(Test_Alignement_Diagonal(surface,x,y)==1 || Test_Alignement_Diagonal(surface,xd,yd)==1){
                        printf("\n\tIl y a alignement de: "); Coordonnees_Jetons_Alignes(surface,'T');
                        system("timeout 2 >nul");
                        sup = Eliminer_Jeton(surface);

                        system("cls");
                        Affiche_Plateau(surface);
                        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                        printf("\n\n\t\tScore supplementaire: +%d",sup);
                        surface->score += sup;

                        system("timeout 2 >nul");
                        Completer_Plateau(surface); //on remplit les espaces vides laissés
                        surface->deplacement--; //On resuit le nbre de deplcements
                    }
                    else if(Test_Alignement_Special(surface,x,y)==1 || Test_Alignement_Special(surface,xd,yd)==1){
                        printf("\n\tIl y a alignement de: "); Coordonnees_Jetons_Alignes(surface,'T');
                        system("timeout 2 >nul");
                        sup = Eliminer_Jeton(surface);

                        system("cls");
                        Affiche_Plateau(surface);
                        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                        printf("\n\n\t\tScore supplementaire: +%d",sup);
                        surface->score += sup;

                        system("timeout 2 >nul");
                        Completer_Plateau(surface); //on remplit les espaces vides laissés
                        surface->deplacement--; //On resuit le nbre de deplcements
                    }
                    else{//S'il n'y a pas de combinaison possible
                        printf("\n\tPas de combinaison valide! \n");
                        printf("\n\tScore supplementaire: 0");
                        system("timeout 2 >nul");
                        Echanger_Position(surface,xd,yd,x,y); //On remet les jetons a leur position d'origine
                        surface->deplacement--; //On fait une reduction sur le nbre de deplacements
                    }
                }
                else{ //Si la reponse != Y, on ne fait rien
                    surface->deplacement--;
                    surface->deplacement++;
                }
            }
        }
        else if(arriere){
            surfacePred->score = surface->score - 100;
            surfacePred->deplacement = surface->deplacement - 2;
            printf("\n\n\t\tRETOUR EN ARRIERE ACTIVE\n");
            system("timeout 3 >nul");
            free(surface);
            Jouer_Special(surfacePred);
            break;
        }
        else if(option){
            Options(surface,'T'); //Si option=1, on affiche les options
            break;
        }
    }
    /**********************************************
        LORSQUE LE JOUEUR N'A PLUS DE DEPLACEMENTS
    ***********************************************/
    while(Test_Filtre_Plateau(surface)==0){//On vérifie s'il y a des alignements dans le plateau
        system("cls");
        Affiche_Plateau(surface);
        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
        printf("\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'T'); system("timeout 2 >nul");
        sup = Eliminer_Jeton(surface);

        system("cls");
        Affiche_Plateau(surface);
        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
        printf("\n\n\t\tScore supplementaire: +%d",sup);

        system("timeout 3 >nul");
        surface->score += sup;
        Completer_Plateau(surface);
    }

    system("cls");
    Affiche_Plateau(surface);
    printf("\n\tDeplacements Restants: %d\t\t\tScore: %d \n\n",surface->deplacement,surface->score);
    printf("\n\n\tVous n'avez plus de deplacements possibles ==> PARTIE TERMINEE\n");

    printf("\n\n\tAppuyez sur une touche pour revenir au menu principal: ");
    system("pause >nul");
    int k = main();

    /** FIN DE LA PARTIE SPECIALE **/
}

//         --------------------------------------------------------------
//        |             FONCTIONS UTILISEES POUR LES MISSIONS            |
//         --------------------------------------------------------------

//===================================
/**
    Cette fonction permet de choisir le
    niveau de difficulte pour une mission:
    FACILE, MEDIUM, HARD
    Ce qui permet d'adapter le plateau de jeu
    en conséquence
**/
void Niveau_Difficulte()
{
    int choix,k,i;
    char vide[2];
    Plateau *jeu;

    system("cls"); //On efface la console
    system("color f6");
    printf("\n\n\t\tCHOIX DU NIVEAU DE DIFFICULTE\n");
    printf("\n\t1---------------> FACILE\n");
    printf("\n\t2---------------> MEDIUM\n");
    printf("\n\t3---------------> HARD\n");
    printf("\n\t0---------------> Retour au menu principal\n");

    printf("\n\tFaites votre choix: ");
    scanf("%d",&choix);

    switch(choix){
        case 1 :    jeu = Creation_Plateau(8,8);
                    Remplir_Plateau(jeu,5,NB_DEPLACEMENTS);
                    Filtrer_Plateau(jeu);
                    printf("\n\n\tCHARGEMENT: ");
                    for(i=0 ; i<5 ; i++){
                        printf("####");
                        system("timeout 1 >nul");
                    }
                    INFO_MISSION(); system("pause >nul");
                    Jouer_Mission(jeu,'F');
                    break;

        case 2 :    jeu = Creation_Plateau(10,10);
                    Remplir_Plateau(jeu,7,10);
                    printf("\n\n\tCHARGEMENT: ");
                    Filtrer_Plateau(jeu);
                    for(i=0 ; i<5 ; i++){
                        printf("####");
                        system("timeout 1 >nul");
                    }
                    INFO_MISSION(); system("pause >nul");
                    Jouer_Mission(jeu,'M');
                    break;

        case 3 :    jeu = Creation_Plateau(NB_LIGNES,NB_COLONNES);
                    Remplir_Plateau(jeu,NB_COULEUR,8);
                    printf("\n\n\tCHARGEMENT: ");
                    for(i=0 ; i<5 ; i++){
                        printf("####");
                        system("timeout 1 >nul");
                    }
                    Filtrer_Plateau(jeu);
                    INFO_MISSION(); system("pause >nul");
                    Jouer_Mission(jeu,'H');
                    break;

        case 0 :    k = main();
                    break;

        default :   printf("\n\tCe niveau n'existe pas!\n");
                    system("timeout 2 >nul");
                    scanf("%s",vide);
                    Niveau_Difficulte();
                    break;
    }
    /** FIN DU CHOIX DE NIVEAU DE DIFFICULTE **/
}

//=======================================
/**
    Cette fonction permet de jouer une
    mission spéciale!
**/

void Jouer_Mission(Plateau *surface, char type)
{
    char vide[2],erreur[2];
    int xd,yd; //Position de départ
    int x,y; //Position d'arrivee
    char ok[2]; //Reponse du deplacement
    char coup[6];
    int sup;
    int option=-1;
    int objectif; //Score a atteindre pour la mission

    /*On defini l'objectif de la mission
        F ==> Facile
        M ==> Medium
        H ==> Hard
    */
    switch(type){
        case 'F': objectif = 800; system("color 0F"); break;
        case 'M': objectif = 1200; system("color 8F"); break;
        case 'H': objectif = 1600; system("color 0A"); break;
    }

    while(surface->deplacement > 0){
        system("cls"); /* Efface l'écran */

        //Tant qu'il y a des combinaisons, on les elimine
        while(Test_Filtre_Plateau(surface)==0){
            Affiche_Plateau(surface);
            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
            printf("\t\tOBJECTIF: %d pts\n\n",objectif);
            printf("\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'T'); system("timeout 2 >nul");

            if(type=='F') //Si niveau facile
                sup = Eliminer_Jeton(surface); //On ne fait pas de bonus
            else //Si niveau moyen ou difficile
                sup = Eliminer_Jeton(surface) * 2; //On fait un petit bonus

            system("cls");
            Affiche_Plateau(surface);
            printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
            printf("\t\tOBJECTIF: %d pts\n\n",objectif);
            printf("\n\n\t\tScore supplementaire: +%d",sup);

            system("timeout 3 >nul");
            surface->score += sup;
            Completer_Plateau(surface);
            system("cls");
        }

        Affiche_Plateau(surface);
        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
        printf("\t\tOBJECTIF: %d pts\n\n",objectif);

        // Mise a zero du coup precedent
        xd = yd = x = y = -1;

        printf("\n\tPour visualiser les options, taper \"O\"\n");

        //Saisie du deplacement a effectuer
        printf("\n\tQue jouez-vous? : ");
        scanf("%s",coup);

        //Test sur les valeurs saisie

        option = (strcmp(coup,"O")==0); //Si resultat vaut 0 ==> ON AFFICHE LE MENU DES OPTIONS

        if(!option){
            //On recupere l'ordonnee du pion a deplacer
            if(coup[0]=='a' || coup[0]=='A') yd = 0;
            else if(coup[0]=='b' || coup[0]=='B') yd = 1;
            else if(coup[0]=='c' || coup[0]=='C') yd = 2;
            else if(coup[0]=='d' || coup[0]=='D') yd = 3;
            else if(coup[0]=='e' || coup[0]=='E') yd = 4;
            else if(coup[0]=='f' || coup[0]=='F') yd = 5;
            else if(coup[0]=='g' || coup[0]=='G') yd = 6;
            else if(coup[0]=='h' || coup[0]=='H') yd = 7;
            else if(coup[0]=='i' || coup[0]=='I') yd = 8;
            else if(coup[0]=='j' || coup[0]=='J') yd = 9;

            //48 correspond au caractere zero '0': on aurait pu faire (int)coup - '0'
            xd = ((int)coup[1] - 48) * 10 + ((int)coup[2] - 48); //On recupere l'abscisse du pion a deplacer

            //On recupere les coordonnees de la destination
            if(coup[4]=='h'||coup[4]=='H'){
                y = yd;
                x = xd - 1;
            }
            else if(coup[4]=='D' || coup[4]=='d'){
                y = yd + 1;
                x = xd;
            }
            else if(coup[4]=='G' || coup[4]=='g'){
                y = yd - 1;
                x = xd;
            }
            else if(coup[4]=='B' || coup[4]=='b'){
                y = yd;
                x = xd + 1;
            }
            //Test sur les coordonnees entrees: xd,x €[1;15] et yd,y €[0;9]
            if(coup[3]!='-' || yd<-1 || yd>surface->largeur || xd<1 || xd>surface->hauteur+1 || y<-1
               || y>surface->largeur || x<0 || x>surface->hauteur+1){
                printf("\n\tMauvaises coordonnees saisies!\n\n");
                printf("\tAppuyer sur une touche puis sur \"ENTREE\": ");
                scanf("%s",erreur);
            }
            else{
                printf("\n\tConfirmer le deplacement Y/N ? : ");
                scanf("%s",ok);//Confirmation de permutation de jetons

                if(strcmp(ok,"Y")==0 || strcmp(ok,"y")==0){//Si OUI, on effectue le deplacement
                    xd--; //On recupere les valeurs reelles de xd et x
                    x--;  //en fonction de la structure du plateau de jeu

                    if(y<0) y = surface->largeur-1; //Le tableau n'a pas de bord

                    if(y>=surface->largeur) y = 0; //Le tableau n'a pas de bord

                    if(x<0) x = surface->hauteur-1; //Le tableau n'a pas de bord

                    if(x>=surface->hauteur) x = 0; //Le tableau n'a pas de bord

                    //On permute les jetons
                    Echanger_Position(surface,xd,yd,x,y);

                    //On teste les alignements des jetons
                    if(Test_Alignement_Torique(surface,x,y)==1 || Test_Alignement_Torique(surface,xd,yd)==1){
                        printf("\n\tIl y a alignement de: "); Coordonnees_Jetons_Alignes(surface,'T'); system("timeout 2 >nul");
                        sup = Eliminer_Jeton(surface);

                        system("cls");
                        Affiche_Plateau(surface);
                        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                        printf("\t\tOBJECTIF: %d pts\n\n",objectif);
                        printf("\n\n\t\tScore supplementaire: +%d",sup);
                        surface->score += sup;

                        system("timeout 2 >nul");
                        Completer_Plateau(surface); //on remplit les espaces vides laissés
                        surface->deplacement--; //On resuit le nbre de deplcements
                    }
                    else if(Test_Alignement_Diagonal(surface,x,y)==1 || Test_Alignement_Diagonal(surface,xd,yd)==1){
                        printf("\n\tIl y a alignement de: "); Coordonnees_Jetons_Alignes(surface,'T'); system("timeout 2 >nul");
                        sup = Eliminer_Jeton(surface);

                        system("cls");
                        Affiche_Plateau(surface);
                        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                        printf("\t\tOBJECTIF: %d pts\n\n",objectif);
                        printf("\n\n\t\tScore supplementaire: +%d",sup);
                        surface->score += sup;

                        system("timeout 2 >nul");
                        Completer_Plateau(surface); //on remplit les espaces vides laissés
                        surface->deplacement--; //On resuit le nbre de deplcements
                    }
                    else if(Test_Alignement_Special(surface,x,y)==1 || Test_Alignement_Special(surface,xd,yd)==1){
                        printf("\n\tIl y a alignement de: "); Coordonnees_Jetons_Alignes(surface,'T'); system("timeout 2 >nul");
                        sup = Eliminer_Jeton(surface);

                        system("cls");
                        Affiche_Plateau(surface);
                        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
                        printf("\t\tOBJECTIF: %d pts\n\n",objectif);
                        printf("\n\n\t\tScore supplementaire: +%d",sup);
                        surface->score += sup;

                        system("timeout 2 >nul");
                        Completer_Plateau(surface); //on remplit les espaces vides laissés
                        surface->deplacement--; //On resuit le nbre de deplcements
                    }
                    else{//S'il n'y a pas de combinaison possible
                        printf("\n\tPas de combinaison valide! \n");
                        printf("\n\tScore supplementaire: 0");
                        system("timeout 2 >nul");
                        Echanger_Position(surface,xd,yd,x,y); //On remet les jetons a leur position d'origine
                        surface->deplacement--; //On fait une reduction sur le nbre de deplacements
                    }
                }
                else{ //Sinon on ne fait rien
                    surface->deplacement--;
                    surface->deplacement++;
                }
            }
        }
        else{
            Options(surface,type); //On affiche les options en fonction du type de partie
            break;
        }
    }
    /**********************************************
        LORSQUE LE JOUEUR N'A PLUS DE DEPLACEMENTS
    ***********************************************/
    //On vérifie s'il y a des alignements dans le plateau
    while(Test_Filtre_Plateau(surface)==0){
        system("cls");
        Affiche_Plateau(surface);
        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
        printf("\tAlignement de: "); Coordonnees_Jetons_Alignes(surface,'T'); system("timeout 2 >nul");
        sup = Eliminer_Jeton(surface);

        system("cls");
        Affiche_Plateau(surface);
        printf("\n\t\tDEPLACEMENTS: %d  \t\tSCORE: %d \n\n",surface->deplacement,surface->score);
        printf("\n\n\t\tScore supplementaire: +%d",sup);

        system("timeout 3 >nul");
        surface->score += sup;
        Completer_Plateau(surface);
    }

    system("cls");
    Affiche_Plateau(surface);
    printf("\n\tDeplacements Restants: %d\t\t\tScore: %d \n\n",surface->deplacement,surface->score);
    printf("\tVous n'avez plus de deplacements possibles\n");

    // On verifie si l'objectif a ete atteind ou pas
    if(objectif<=surface->score)
        printf("\n\n\n\t\t +++++++++ MISSION ACCOMPLIE ! +++++++++++\n");
    else
        printf("\n\n\n\t\t ---------- ECHEC DE LA MISSION -----------\n");

    printf("\n\tAppuyez sur une touche pour revenir au menu principal: ");
    scanf("%s",vide);
    int k = main();

    /** FIN DE LA PARTIE **/
}


//         --------------------------------------------------------------
//        |             FONCTIONS UTILISEES POUR LES AIDES               |
//         --------------------------------------------------------------

//=======================================
/**
    Cette fonction affiche tous les coups possibles
    que peut effectuer le joueur.
**/
void coups_Possibles(Plateau *surface)
{
    int x,y; //pions de départs
    int xA,yA; //pions d'arrivées

    system("cls");
    printf("\n\n\t\tTOUS LES DEPLACEMENTS POSSIBLES SONT LES SUIVANTS:  \n\n\t");

    //Cas 1: on effectue les tests vers la droite
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //printf("%d  %d\n",x,y);
            //On va vers la droite:
            xA=x;
            yA=y+1;
            //Test si les coordonnees d'arrivées sont dans le tableau c-a-d yd,y €[0;9]
            if(yA>=0 && yA<surface->largeur){
                //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,xA,yA)){
                    afficheValeursReels(x,y);printf(" vers la droite\n\t");
                }
                free(tmp);
            }
        }
    }

    //Cas 2: on effectue les tests vers la gauche
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //On va vers la gauche:
            xA=x;
            yA=y-1;
            //Test si les coordonnees d'arrivées sont dans le tableau c-à-d yd,y €[0;9]
            if(yA>=0 && yA<surface->largeur){
                //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,xA,yA)){
                    afficheValeursReels(x,y);printf(" vers la gauche\n\t");
                }
                free(tmp);
            }
        }
    }

    //Cas 3: on effectue les tests vers le bas
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //On va vers le bas:
            xA=x+1;
            yA=y;
            //Test si les coordonnees d'arrivées sont dans le tableau c-à-d xd,x €[1;15]
            if(xA>=0 && xA<surface->hauteur){
                //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,xA,yA)){
                    afficheValeursReels(x,y);printf(" vers le bas\n\t");
                }
                free(tmp);
            }
        }
    }

    //Cas 4: on effectue les tests vers le haut
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //printf("%d  %d\n",x,y);
            //On va vers le haut:
            xA=x-1;
            yA=y;
            //Test si les coordonnees d'arrivées sont dans le tableau c-à-d xd,x €[1;15]
            if(xA>=0 && xA<surface->hauteur){
                //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,xA,yA)){
                    afficheValeursReels(x,y);printf(" vers le haut\n\t");
                }
                free(tmp);
            }
        }
    }
    printf("\n\t Appuyez sur une touche pour reprendre le jeu: ");
    system("pause >nul");
    Jouer_Partie(surface);

    /** FIN DE LA DERMINATION DES COUPS POSSIBLES **/
}


//=======================================
/**
    Cette fonction calcule le nbre de coups
    possibles à jouer et retourne le résultat
**/
int Nbre_Coups_Possibles(Plateau *surface)
{
    int x,y; //pions de départs
    int xA,yA; //pions d'arrivées
    int cpt=0; //nombre de coups possibles


    //Cas 1: on effectue les tests vers la droite
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //printf("%d  %d\n",x,y);
            //On va vers la droite:
            xA=x;
            yA=y+1;
            //Test si les coordonnees d'arrivées sont dans le tableau c-a-d yd,y €[0;9]
            if(yA>=0 && yA<surface->largeur){
                //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,xA,yA))
                    cpt++;
                free(tmp);
            }
        }
    }

    //Cas 2: on effectue les tests vers la gauche
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //On va vers la gauche:
            xA=x;
            yA=y-1;
            //Test si les coordonnees d'arrivées sont dans le tableau c-à-d yd,y €[0;9]
            if(yA>=0 && yA<surface->largeur){
                //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,xA,yA))
                    cpt++;
                free(tmp);
            }
        }
    }

    //Cas 3: on effectue les tests vers le bas
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //On va vers le bas:
            xA=x+1;
            yA=y;
            //Test si les coordonnees d'arrivées sont dans le tableau c-à-d xd,x €[1;15]
            if(xA>=0 && xA<surface->hauteur){
                //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,xA,yA))
                    cpt++;
                free(tmp);
            }
        }
    }

    //Cas 4: on effectue les tests vers le haut
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //printf("%d  %d\n",x,y);
            //On va vers le haut:
            xA=x-1;
            yA=y;
            //Test si les coordonnees d'arrivées sont dans le tableau c-à-d xd,x €[1;15]
            if(xA>=0 && xA<surface->hauteur){
                //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,xA,yA))
                    cpt++;
                free(tmp);
            }
        }
    }

    //On retourne le nbre de coups disponibles
    return cpt;

    /** FIN DU CALCUL DU NOMBRE DE COUPS POSSIBLES **/
}


//=======================================
/**
    Cette fonction permet de débloquer un jeu
    en cours lorsque lorsqu'il n'y a plus de
    coups possibles à jouer
**/
void Debloquer_Jeu(Plateau *surface, char type)
{
    int tmp;

    //On écrase le contenu du plateau avec de nouveaux jetons
    //En conservant les autres données.
    tmp = surface->score; //On sauvegarde le score
    Remplir_Plateau(surface,surface->nbcouleur,surface->deplacement);
    surface->score = tmp; //On recupere le score

    //On reorganise le plateau en fonction du type de jeu
    //Et on relance la partie comme ci de rien était
    switch(type){
        case 'N' : Organiser_Plateau(surface);
                   Jouer_Partie(surface);
                   break;

        case 'T' : Filtrer_Plateau(surface);
                   Jouer_Special(surface);
                   break;

        default : Filtrer_Plateau(surface);
                  Jouer_Mission(surface,type);
                  break;
    }
    /** FIN DU DEBLOQUAGE DE LA PARTIE **/
}


//=======================================
/**
    Cette fonction affiche dans quelle direction
    pour supprimer k jetons
**/
void direction_coup(Plateau *surface, int x, int y, int k)
{
    int xA,yA; //pions d'arrivées

    /*------Cas 1: On teste vers la droite **/
    xA=x;
    yA=y+1;
    //Test si les coordonnees d'arrivées sont dans le tableau c-a-d yd,y €[0;9]
    if(yA>=0 && yA<surface->largeur){
    //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
        Plateau* tmp=clone_Plateau(surface);
        Echanger_Position(tmp, x, y, xA, yA);
        if((Test_Combinaison(tmp,xA,yA) || (Test_Combinaison(tmp,x,y))) && nombreDePionsEnCombinaison(tmp)==k){
            printf(" vers la droite\n\t");
            free(tmp);
            //exit(0);
        }
    }

    /*------Cas 2: On teste vers la gauche: */
    xA=x;
    yA=y-1;
    //Test si les coordonnees d'arrivées sont dans le tableau c-à-d yd,y €[0;9]
    if(yA>=0 && yA<surface->largeur){
        //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
        Plateau* tmp=clone_Plateau(surface);
        Echanger_Position(tmp, x, y, xA, yA);
        if((Test_Combinaison(tmp,xA,yA) || (Test_Combinaison(tmp,x,y))) && nombreDePionsEnCombinaison(tmp)==k){
            printf(" vers la gauche\n\t");
            free(tmp);
            //exit(0);
        }
    }

    /*-------Cas 3: On teste vers le bas: */
    xA=x+1;
    yA=y;
    //Test si les coordonnees d'arrivées sont dans le tableau c-à-d xd,x €[0;14]
    if(xA>=0 && xA<surface->hauteur){
        //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
        Plateau* tmp=clone_Plateau(surface);
        Echanger_Position(tmp, x, y, xA, yA);
        if((Test_Combinaison(tmp,xA,yA) || (Test_Combinaison(tmp,x,y))) && nombreDePionsEnCombinaison(tmp)==k){
            printf(" vers le bas\n\t");
            free(tmp);
           // exit(0);
        }
    }

    /*--------Cas 4: On teste vers le haut: */
    xA=x-1;
    yA=y;
    //Test si les coordonnees d'arrivées sont dans le tableau c-à-d xd,x €[0;14]
    if(xA>=0 && xA<surface->hauteur){
        //Je déplace dans le plateau temporaire et je teste si ça forme une combinaison
        Plateau* tmp=clone_Plateau(surface);
        Echanger_Position(tmp, x, y, xA, yA);
        if((Test_Combinaison(tmp,xA,yA) || (Test_Combinaison(tmp,x,y))) && nombreDePionsEnCombinaison(tmp)==k){
            printf(" vers le haut\n\t");
            free(tmp);
            //exit(0);
        }
    }
    /** FIN DE DETECTION DE LA BONNE DIRECTION **/
}


//=======================================
/**
    Cette fonction indique quel est le meilleur coup
    à jouer, celui pour lequel on supprime le plus de jetons
**/
void meilleur_coup(Plateau *surface)
{
int x,y; //pions de départs
    int xA,yA; //pions d'arrivées
    int cpt;
    int max=0; //le nbre de pions que supprimera le meilleur coup.
    int xOk,yOk;

    /*-------Cas 1: On fait des tests dur les déplacements horizontaux */
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //On va vers la droite:
            xA=x;
            yA=y+1;
            cpt=0; //On initialise le compteur à 0;
            if(yA>=0 && yA<surface->largeur){ //Test si les coordonnees d'arrivées sont dans le tableau c-à-d yA €[0;9]
                //s'ils sont corrects, Je fais un déplacement dans le plateau temporaire
                //et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,x,y)==1 || Test_Combinaison(tmp,xA,yA)==1){
                        cpt=nombreDePionsEnCombinaison(tmp);//cpt récupère le nombre de pions qui seront éliminés
                        if(cpt>max){
                            max=cpt;
                            xOk=x;
                            yOk=y;
                        }
                }
                free(tmp); //On libère le pointeur
            }
        }
    }

    /*--------Cas 2: On fait des tests sur les déplacements verticaux */
    for(x=0 ; x<surface->hauteur ; x++){
        for(y=0 ; y<surface->largeur ; y++){
            //On va vers la droite:
            xA=x+1;
            yA=y;
            cpt=0; //On initialise le compteur à 0;
            if(xA>=0 && xA<surface->hauteur){  //Test si les coordonnees d'arrivées sont dans le tableau c-à-d xA €[0;14]
                //s'ils ne sont pas dans le plateau.Je fais un déplacement dans le plateau temporaire
                //et je teste si ça forme une combinaison
                Plateau* tmp=clone_Plateau(surface);
                Echanger_Position(tmp, x, y, xA, yA);
                if(Test_Combinaison(tmp,x,y)==1 || Test_Combinaison(tmp,xA,yA)==1){
                    cpt=nombreDePionsEnCombinaison(tmp); //cpt récupère le nombre de pions qui seront éliminés
                    if(cpt>max){
                        max=cpt;
                        xOk=x;
                        yOk=y;
                    }
                }
            free(tmp);
            }
        }
    }

    //A ce stade du test, le pion à l'origine du déplacement est déjà repéré. ses coordonnées: xOk, yOk
    //Le plus grand nombre de pions qui sera supprimé se trouve dans max
    //Il ne reste qu'à déterminer la direction de son déplacement.
    //Je complète l'affichage plus bas avec la direction
    //Détermination de la direction de déplacement du pion trouvé afin qu'il puisse entrer dans sa combinaison
    printf("\n\t============>");
    printf("\n\n\t Le meilleur coup elimine %d Jetons: \n",max);
    printf("\t Pour le jouer, vous devez deplacer le ");afficheValeursReels(xOk,yOk);
    direction_coup(surface,xOk,yOk,max);
    printf("\n\t============>\n");

    //On continue le jeu
    printf("\n\tAppuyez sur une touche pour reprendre le jeu: ");
    system("pause >nul");
    Jouer_Partie(surface);

    /** FIN DETECTION DU MEILLEUR COUP A JOUER **/
}

//=======================================
/**
    Cette fonction renvoie le nbre de Jetons
    dans une combinaison
**/
int nombreDePionsEnCombinaison(Plateau *surface)
{
int cpt=0;
     for(int i=0 ; i<surface->hauteur ; i++){
        for(int j=0 ; j<surface->largeur ; j++){
            if(Test_Combinaison(surface,i,j)==1){
               cpt+=1;
            }
        }
     }
     return cpt;
}
