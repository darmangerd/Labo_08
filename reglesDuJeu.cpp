/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : reglesDuJeu.cpp
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

#include "reglesDuJeu.h"

using namespace std;

/* Constantes */
const char DIRECTION_BAS = 'd';
const char DIRECTION_HAUT = 'u';
const char DIRECTION_DROITE = 'r';
const char DIRECTION_GAUCHE = 'l';
// Position du caractère indiquant le déplacement. p.ex: 32u --> u ou 45d --> d
const int POSITION_DEPLACEMENT_STRING = 2;

/**
@brief                  Conversion d'un char en int
@param[in] c            le caractère à convertir en int
@return                 le caractère convertit en int
*/
int char2int(char c) {
    return c - '0';
}

/**
@brief                  Permet de vérifier si le déplacement choisi par l'utilisateur est possible
@param[in] tablier      tableau contenant les différents états des cases, le tableau n'est pas modifié
@param[in] userinput    string qui contient le déplacement choisi par l'utilisateur
@return                 vrai si le déplacement est possible, false s'il ne l'est pas
*/
bool isValidMove(EtatCase tablier[][TAILLE_TABLIER], const string &userinput) {
    vector<string> moves = allPossibleMoves(tablier);

    // Test si le déplacement est égal à un des déplacement possible
    return any_of(moves.cbegin(), moves.cend(), [&userinput](const string &str) { return userinput == str; });
}

/**
@brief              Permet de vérifier si l'index est valide
@param[in] index    entier qui contient l'index
@return             vrai si l'index se trouve dans les intervalles valides, false s'il ne s'y trouve pas
*/
bool isValidIndex(int index) {
    return index >= 0 && index < TAILLE_TABLIER;
}

/**
@brief                  Permet de voir si un mouvement est possible
@param[in] tablier      tableau contenant les différents états des cases, le tableau n'est pas modifié
@param[in] ligne        entier qui représente les différentes lignes
@param[in] colonne      entier qui représente les différentes colonnes
@return                 les mouvements possibles
*/
vector<string> possibleMoves(EtatCase tablier[][TAILLE_TABLIER], int ligne, int colonne) {

    vector<string> moves;
    // Quatre position par mouvement
    moves.reserve(4);

    // Test mouvement bas
    if (isValidIndex(ligne + 1) && isValidIndex(ligne + 2)) {
        if (tablier[ligne + 1][colonne] == EtatCase::BILLE &&
            tablier[ligne + 2][colonne] == EtatCase::LIBRE) {
            moves.push_back(to_string(ligne + 1) + to_string(colonne + 1) + DIRECTION_BAS);
        }
    }

    // Test mouvement HAUT
    if (isValidIndex(ligne - 1) && isValidIndex(ligne - 2)) {
        if (tablier[ligne - 1][colonne] == EtatCase::BILLE &&
            tablier[ligne - 2][colonne] == EtatCase::LIBRE) {
            moves.push_back(to_string(ligne + 1) + to_string(colonne + 1) + DIRECTION_HAUT);
        }
    }

    // Test mouvement DROITE
    if (isValidIndex(colonne + 1) && isValidIndex(colonne + 2)) {
        if (tablier[ligne][colonne + 1] == EtatCase::BILLE &&
            tablier[ligne][colonne + 2] == EtatCase::LIBRE) {
            moves.push_back(to_string(ligne + 1) + to_string(colonne + 1) + DIRECTION_DROITE);
        }
    }

    // Test mouvement GAUCHE
    if (isValidIndex(colonne - 1) && isValidIndex(colonne - 2)) {
        if (tablier[ligne][colonne - 1] == EtatCase::BILLE &&
            tablier[ligne][colonne - 2] == EtatCase::LIBRE) {
            moves.push_back(to_string(ligne + 1) + to_string(colonne + 1) + DIRECTION_GAUCHE);
        }
    }

    return moves;
}

bool moveBille(EtatCase tablier[][TAILLE_TABLIER], const string &userinput) {
    int ligne, colonne;
    if (!isValidMove(tablier, userinput))
        return false;

    ligne = char2int(userinput[0]) - 1;
    colonne = char2int(userinput[1]) - 1;

    //Différents déplacement de la boule
    switch (userinput[POSITION_DEPLACEMENT_STRING]) {
        case DIRECTION_BAS:
            tablier[ligne + 1][colonne] = EtatCase::LIBRE;
            tablier[ligne + 2][colonne] = EtatCase::BILLE;
            break;
        case DIRECTION_HAUT:
            tablier[ligne - 1][colonne] = EtatCase::LIBRE;
            tablier[ligne - 2][colonne] = EtatCase::BILLE;
            break;
        case DIRECTION_DROITE:
            tablier[ligne][colonne + 1] = EtatCase::LIBRE;
            tablier[ligne][colonne + 2] = EtatCase::BILLE;
            break;
        case DIRECTION_GAUCHE:
            tablier[ligne][colonne - 1] = EtatCase::LIBRE;
            tablier[ligne][colonne - 2] = EtatCase::BILLE;
            break;
        default:
            return false;
    }

    tablier[ligne][colonne] = EtatCase::LIBRE;

    return true;
}

vector<string> allPossibleMoves(EtatCase tablier[][TAILLE_TABLIER]) {

    vector<string> moves;
    // Quatre position par index * le nombre d'index
    moves.reserve(4 * TAILLE_TABLIER * TAILLE_TABLIER);

    for (int i = 0; i < TAILLE_TABLIER; i++) {
        for (int j = 0; j < TAILLE_TABLIER; j++) {
            switch (tablier[i][j]) {
                //Si la case est vide on passe à la suivante
                case EtatCase::VIDE:
                    break;
                //Si la case contient une bille on regarde les mouvements possible
                case EtatCase::BILLE: {
                    //Contient les différents mouvements possible à l'index [i][j]
                    vector<string> movesAtIndex(possibleMoves(tablier, i, j));
                    //S'il n'y a pas de mouvements possible on passe à la case suivante
                    if (movesAtIndex.empty())
                        break;

                    copy(movesAtIndex.begin(), movesAtIndex.end(), back_inserter(moves));
                    break;
                }
                //Si la case est libre on passe à la suivante
                case EtatCase::LIBRE:
                    break;
            }
        }
    }
    return moves;
}

bool checkFinished(EtatCase tablier[][TAILLE_TABLIER], int &billeRestante, bool &centre) {

    billeRestante = 0;
    centre = false;

    //Comptage des bille restante
    for(int i = 0; i < TAILLE_TABLIER; i++) {
        for(int j = 0; j < TAILLE_TABLIER; j++) {
            if(tablier[i][j] == EtatCase::BILLE) {
                billeRestante++;
            }
        }
    }

    if(billeRestante == 1) {
        // Test si la bille restante est au centre
        centre = tablier[CENTRE_TABLIER][CENTRE_TABLIER] == EtatCase::BILLE;
    }

    // Puis on indique si il n'y as plus de mouvement
    return allPossibleMoves(tablier).empty();
}

