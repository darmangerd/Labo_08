/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : main.cpp
 Auteur(s)   : Melvin Merk
 Date        : <jj.mm.aaaa>

 But         : Bla

 Remarque(s) : Ne fonctionne que avec un tablier de taille strictement inférieur à 10

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#include <cstdlib>
#include <iostream>
#include "affichage.h"

using namespace std;

const string AIDE = "h";
const string QUIT = "q";


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
    string input = "";
    afficheTablier(tablier);

    do {

        cin >> input;

        if(input == AIDE) {
            afficheAide(tablier);
            continue;
        } else if(input == QUIT) {
            // Calcul des billes restantes
            checkFinished(tablier, billeRestante, centre);
            break;
        } else if (!moveBille(tablier, input)) {
            cout << "Mouvement invalide" << endl;
            continue;
        }

        afficheTablier(tablier);

    } while (!checkFinished(tablier, billeRestante, centre));

    afficheFinPartie(billeRestante, centre);

    return EXIT_SUCCESS;
}

