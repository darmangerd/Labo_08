#ifndef REGLESDUJEU_H
#define REGLESDUJEU_H

#include <string>
#include <vector>
#include <algorithm>

const int TAILLE_TABLIER = 7;

enum class EtatCase{VIDE, BILLE, LIBRE};

std::vector<std::string> allPossibleMoves(EtatCase tablier[][TAILLE_TABLIER]);

#endif /* REGLESDUJEU_H */

