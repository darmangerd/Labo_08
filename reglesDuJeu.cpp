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

void moveBille() {
  
}

enum class Direction { HAUT, BAS, GAUCHE, DROITE };

void move(Direction dir) {
  switch(dir) {
    case Direction::HAUT:
      
      break;
    case Direction::BAS:
      
      break;
    case Direction::GAUCHE:
      
      break;
    case Direction::DROITE:
      
      break;
  }
}

const string DIRECTION_BAS = "d";
const string DIRECTION_HAUT = "u";
const string DIRECTION_DROITE = "r";
const string DIRECTION_GAUCHE = "l";

bool isValidIndex(int index) {
  return index >= 0 || index < TAILLE_TABLIER;
}
vector<string> possibleMoves(EtatCase tablier[][TAILLE_TABLIER], int ligne, int colonne) {
  
  
  vector<string> moves;
  moves.reserve(4); // Quatre position par mouvement
  
  // Test mouvement bas
  if(isValidIndex(ligne+1) && isValidIndex(ligne+2)) {
    if(tablier[ligne+1][colonne] == EtatCase::BILLE &&  
       tablier[ligne+2][colonne] == EtatCase::LIBRE) {
      moves.push_back(DIRECTION_BAS + to_string(ligne+1)+ to_string(colonne+1));
    }
  }
  
  // Test mouvement HAUT
  if(isValidIndex(ligne-1) && isValidIndex(ligne-2)) {
    if(tablier[ligne-1][colonne] == EtatCase::BILLE &&  
       tablier[ligne-2][colonne] == EtatCase::LIBRE) {
      moves.push_back(DIRECTION_HAUT + to_string(ligne+1)+ to_string(colonne+1));
    }
  }
  
  // Test mouvement DROITE
  if(isValidIndex(colonne+1) && isValidIndex(colonne+2)) {
    if(tablier[ligne][colonne+1] == EtatCase::BILLE &&  
       tablier[ligne][colonne+2] == EtatCase::LIBRE) {
      moves.push_back(DIRECTION_DROITE + to_string(ligne+1)+ to_string(colonne+1));
    }
  }
  
  // Test mouvement GAUCHE
  if(isValidIndex(colonne-1) && isValidIndex(colonne-2)) {
    if(tablier[ligne][colonne-1] == EtatCase::BILLE &&  
       tablier[ligne][colonne-2] == EtatCase::LIBRE) {
      moves.push_back(DIRECTION_GAUCHE + to_string(ligne+1)+ to_string(colonne+1));
    }
  }
  
  return moves;
}


vector<string> allPossibleMoves(EtatCase tablier[][TAILLE_TABLIER]) {
  
  vector<string> moves;
  moves.reserve(4 * TAILLE_TABLIER * TAILLE_TABLIER); // Quatre position par index * le nombre d'index
  
  for(unsigned i = 0; i < TAILLE_TABLIER; i++) {
    for(unsigned j = 0; j < TAILLE_TABLIER; j++) {
      switch(tablier[i][j]) {
        case EtatCase::VIDE:         
          break;
        case EtatCase::BILLE: {
          vector<string> movesAtIndex(possibleMoves(tablier, i, j));
          if(movesAtIndex.empty())
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


