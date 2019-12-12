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

std::vector<std::string> allPossibleMoves(EtatCase tablier[][TAILLE_TABLIER]);
bool moveBille(EtatCase tablier[][TAILLE_TABLIER], const std::string &userinput);
bool checkFinished(EtatCase tablier[][TAILLE_TABLIER], int &billeRestante, bool &centre);

#endif /* REGLESDUJEU_H */

