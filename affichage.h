/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : affichage.h
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

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "reglesDuJeu.h"

/**
 * @brief                           Fonction qui parcourt le tableau "tablier" et affiche
 *                                  chaque case selon son état: vide, avec une bille ou libre.
 * 
 * 
 * @param[in] tablier               tableau contenant les différents états des cases, le tableau n'est pas modifié
 */  
void afficheTablier(EtatCase tablier[][TAILLE_TABLIER]);

/**
 * @brief                           Fonction qui affiche les déplacements possibles.
 * 
 * 
 * @param[in] tablier               tableau contenant les différents états des cases, le tableau n'est pas modifié
 */   
void afficheAide(EtatCase tablier[][TAILLE_TABLIER]);

/**
 * @brief                           Fonction qui affiche un message de fin différent selon le résultat final.
 *
 * @param[in] billeRestante         Le nombre de billes restantes
 * @param[in] centre                indique si la dernière bille est au centre du tablier
 */ 
void afficheFinPartie(int billeRestante, bool centre);


#endif /* AFFICHAGE_H */

