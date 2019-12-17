/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : reglesDuJeu.cpp
 Auteur(s)   : Melvin Merk
 Date        : <jj.mm.aaaa>

 But         : Bla

 Remarque(s) : Bla

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */
#include "reglesDuJeu.h"

using namespace std;

int char2int(char c) {
    return c - '0';
}

const char DIRECTION_BAS = 'd';
const char DIRECTION_HAUT = 'u';
const char DIRECTION_DROITE = 'r';
const char DIRECTION_GAUCHE = 'l';
// Position du caractère indiquant le déplacement. p.ex: 32u --> u ou 45d --> d
const int POSITION_DEPLACEMENT_STRING = 2;

bool isValidMove(EtatCase tablier[][TAILLE_TABLIER], const string &userinput) {
    vector<string> moves = allPossibleMoves(tablier);

    // test si le déplacement est égal à un des déplacement possible
    return any_of(moves.cbegin(), moves.cend(), [&userinput](const string &str) { return userinput == str; });
}

bool isValidIndex(int index) {
    return index >= 0 && index < TAILLE_TABLIER;
}

bool moveBille(EtatCase tablier[][TAILLE_TABLIER], const string &userinput) {
    int ligne, colonne;
    if (!isValidMove(tablier, userinput))
        return false;

    ligne = char2int(userinput[0]) - 1;
    colonne = char2int(userinput[1]) - 1;

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

vector<string> possibleMoves(EtatCase tablier[][TAILLE_TABLIER], int ligne, int colonne) {


    vector<string> moves;
    moves.reserve(4); // Quatre position par mouvement

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


vector<string> allPossibleMoves(EtatCase tablier[][TAILLE_TABLIER]) {

    vector<string> moves;
    moves.reserve(4 * TAILLE_TABLIER * TAILLE_TABLIER); // Quatre position par index * le nombre d'index

    for (int i = 0; i < TAILLE_TABLIER; i++) {
        for (int j = 0; j < TAILLE_TABLIER; j++) {
            switch (tablier[i][j]) {
                case EtatCase::VIDE:
                    break;
                case EtatCase::BILLE: {
                    vector<string> movesAtIndex(possibleMoves(tablier, i, j));
                    if (movesAtIndex.empty())
                        break;

                    copy(movesAtIndex.begin(), movesAtIndex.end(), back_inserter(moves));
                    break;
                }

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

    for(int i = 0; i < TAILLE_TABLIER; i++) {
        for(int j = 0; j < TAILLE_TABLIER; j++) {
            if(tablier[i][j] == EtatCase::BILLE) {
                billeRestante++;
            }
        }
    }

    if(billeRestante == 1) {
        centre = tablier[CENTRE_TABLIER][CENTRE_TABLIER] == EtatCase::BILLE;
    }

    // Puis on indique si il n'y as plus de mouvement
    return allPossibleMoves(tablier).empty();
}

