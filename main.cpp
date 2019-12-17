/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : main.cpp
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

#include <cstdlib>
#include <iostream>
#include "affichage.h"

using namespace std;

/* Constantes */
const string CMD_AIDE = "h";
const string CMD_QUIT = "q";

/* Fonction principale */
int main() {

    EtatCase tablier[TAILLE_TABLIER][TAILLE_TABLIER] = {
            {EtatCase::VIDE,  EtatCase::VIDE,  EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::VIDE,  EtatCase::VIDE},
            {EtatCase::VIDE,  EtatCase::VIDE,  EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::VIDE,  EtatCase::VIDE},
            {EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE},
            {EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::LIBRE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE},
            {EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE},
            {EtatCase::VIDE,  EtatCase::VIDE,  EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::VIDE,  EtatCase::VIDE},
            {EtatCase::VIDE,  EtatCase::VIDE,  EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::VIDE,  EtatCase::VIDE},
    };

    int billeRestante = 0;
    bool centre = false;
    string input;

    // Affichage initial du tablier
    afficheTablier(tablier);

    do {

        cin >> input;

        if(input == CMD_AIDE) {
            afficheAide(tablier);
            continue;   // On ne raffiche pas le tablier après l'aide
        } else if(input == CMD_QUIT) {
            // Calcul des billes restantes
            checkFinished(tablier, billeRestante, centre);
            break;
        } else if (!moveBille(tablier, input)) {
            cout << "Mouvement invalide" << endl;
            continue;   // On ne raffiche pas le tablier après une entrée invalide
        }

        afficheTablier(tablier);

    } while (!checkFinished(tablier, billeRestante, centre));

    afficheFinPartie(billeRestante, centre);

    return EXIT_SUCCESS;
}

