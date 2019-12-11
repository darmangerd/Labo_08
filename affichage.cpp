
#include "affichage.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string CASE_LIBRE = "..";
const int LARGEUR_COLONNE = 4;
        
void afficheTablier(EtatCase tablier[][TAILLE_TABLIER]) {
  
  for(unsigned i = 0; i < TAILLE_TABLIER; i++) {
    for(unsigned j = 0; j < TAILLE_TABLIER; j++) {
      switch(tablier[i][j]) {
        case EtatCase::VIDE:
          cout << setw(LARGEUR_COLONNE) << " ";
          break;
        case EtatCase::BILLE:
          cout << setw(LARGEUR_COLONNE-1) << (i + 1) << (j + 1);
          break;
          
        case EtatCase::LIBRE:
          cout << setw(LARGEUR_COLONNE) << CASE_LIBRE;
          break;
      }
    }
    cout << endl;
  }
  
}