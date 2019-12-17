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
\brief Permet de voir tous les mouvements possible (help)
\param[in] tablier tableau contenant les différents états des cases
\return retourne tous les mouvements possibles
*/
std::vector<std::string> allPossibleMoves(EtatCase tablier[][TAILLE_TABLIER]);

/**
\brief Permet de déplacer une bille sur le plateau
\param[in] tablier tableau contenant les différents états des cases
\param[in] userinput string qui contient le déplacement choisi par l'utilisateur
\return retourne vrai si l'index se trouve dans les intervalles valides, false s'il ne s'y trouve pas
*/
bool moveBille(EtatCase tablier[][TAILLE_TABLIER], const std::string &userinput);

/**
\brief Permet de vérifier si la partie est fini
\param[in] tablier tableau contenant les différents états des cases
\param[in] billeRestante entier qui représente le nombre de bille restante
\param[in] centre booléen qui est à vrai lorsque la dernière bille restante est au centre
\return retourne vrai s'il n'y a plus de mouvement possible
*/
bool checkFinished(EtatCase tablier[][TAILLE_TABLIER], int &billeRestante, bool &centre);

#endif /* REGLESDUJEU_H */

