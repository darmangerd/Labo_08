/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : main.cpp
 Auteur(s)   : Melvin Merk
 Date        : <jj.mm.aaaa>

 But         : Bla

 Remarque(s) : Bla

 Compilateur : MinGW-g++ 6.3.0
 -----------------------------------------------------------------------------------
 */


#include <cstdlib>
#include "affichage.h"

using namespace std;

EtatCase tablier[TAILLE_TABLIER][TAILLE_TABLIER] = {
    { EtatCase::VIDE, EtatCase::VIDE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::VIDE, EtatCase::VIDE},
    { EtatCase::VIDE, EtatCase::VIDE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::VIDE, EtatCase::VIDE},
    { EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE},
    { EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::LIBRE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE},
    { EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE},
    { EtatCase::VIDE, EtatCase::VIDE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::VIDE, EtatCase::VIDE},
    { EtatCase::VIDE, EtatCase::VIDE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::BILLE, EtatCase::VIDE, EtatCase::VIDE},
                      };

int main() {
  
  
  afficheTablier(tablier);
  afficheAide(tablier);
  
  
  return EXIT_SUCCESS;
}

