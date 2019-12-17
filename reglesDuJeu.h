/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : reglesDuJeu.h
 Auteur(s)   : Melvin Merk, David Darmanger, Rébecca Tevaearai
 Date        : 17.12.2019

 But         :  Utilisation de tableaux (type C) bi-dimensionnels ou vecteurs
                Utilisation de type enuméré
                Conception et mise en oeuvre de fonctions
                Approfondissement de la notion de tests et décision
                Manipulation de chaines de caractères
                Mise en oeuvre de la compilation séparée en plusieurs fichiers.


 Remarque(s) : Ne fonctionne que avec un tablier de taille strictement inférieur à 10

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */

#ifndef REGLESDUJEU_H
#define REGLESDUJEU_H

#include <string>
#include <vector>
#include <algorithm>

const int TAILLE_TABLIER = 7;
const int CENTRE_TABLIER = TAILLE_TABLIER / 2;
const int NB_BILLE_BIEN_MIN = 2;
const int NB_BILLE_BIEN_MAX = 5;

enum class EtatCase{VIDE, BILLE, LIBRE};

/**
@brief                      Permet de voir tous les mouvements possible (help)
@param[in] tablier          tableau contenant les différents états des cases, le tableau n'est pas modifié
@return                     tous les mouvements possibles
*/
std::vector<std::string> allPossibleMoves(EtatCase tablier[][TAILLE_TABLIER]);

/**
@brief                      Permet de déplacer une bille sur le plateau
@param[in] tablier          tableau contenant les différents états des cases, le tableau est modifié si le mouvement est valide
@param[in] userinput        string qui contient le déplacement choisi par l'utilisateur
@return                     vrai si le déplacement de l'utilisateur est valide
*/
bool moveBille(EtatCase tablier[][TAILLE_TABLIER], const std::string &userinput);

/**
@brief                      Permet de vérifier si la partie est fini
@param[in] tablier          tableau contenant les différents états des cases, le tableau n'est pas modifié
@param[in] billeRestante    entier qui représente le nombre de bille restante
@param[in] centre           booléen qui est à vrai lorsque la dernière bille restante est au centre
@return                     vrai s'il n'y a plus de mouvement possible
*/
bool checkFinished(EtatCase tablier[][TAILLE_TABLIER], int &billeRestante, bool &centre);

#endif /* REGLESDUJEU_H */

