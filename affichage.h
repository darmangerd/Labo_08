/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   affichage.h
 * Author: Melvin
 *
 * Created on December 11, 2019, 1:29 PM
 */

#ifndef AFFICHAGE_H
#define AFFICHAGE_H

const unsigned TAILLE_TABLIER = 7;

enum class EtatCase{VIDE, BILLE, LIBRE};


void afficheTablier(EtatCase tablier[][TAILLE_TABLIER]);


#endif /* AFFICHAGE_H */

