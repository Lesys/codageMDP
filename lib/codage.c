﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/fonctions.h"

void codage()
{
    char phraseEntiere[255] = ""; //Initialisation d'un tableau de 255 caractères "phraseEntiere"
    char phraseCodee[255] = ""; //Initialisation d'un tableau de 255 caractères "phraseCodee"
    char lettreCodee; //Initialisation d'un caractère "lettreCodee"

    char lettreCle, lettre; //Initialisation de caractères "lettreCle" et "lettre"
    char cle[64]; //Initialisation d'un tableau de 64 caractères "cle"
    int nombreLettres = 0, nombreCle = 0, i = 0, j = 0; //Initialisation de "nombreLettres", "nombreCle", "i" et "j"

    printf("Tout le programme se passe en majuscule, veuillez donc rester en \"CAPSLOCK\"."); //Indications

    printf("\n\nEntrez votre clé: "); //Demande la clé pour coder la phrase
    lire(cle, 64); //Prends la saisie et la met dans "cle"
    nombreCle = strlen(cle); //Taille de la clé saisie

    printf("Entrez le message (TOUJOURS en majuscule): "); //Demande la phrase à coder
    lire(phraseEntiere, 255); //Saisie de la phrase a coder dans "phraseEntiere"
    nombreLettres = strlen(phraseEntiere); //Taille de la phrase

    do //Pour toutes les lettres de "phraseEntiere"
    {
        i %= nombreCle; //i modulo "nombreCle" pour avoir toujours un nombre entre 0 et le maximum de "nombreCle"
        lettreCle = cle[i]; //Sélectionne la lettre à l'emplacement [i] de "cle"
        int lettreCodageNum = codageNum(lettreCle); //Code la lettre de la clé en numéro

        lettre = phraseEntiere[j]; //Sélectionne la lettre à l'emplacement [j] de "phraseEntiere"

        if (lettre != ' ') { //Si "lettre" n'est pas un espace

            int lettreCodeeNum = codageNum(lettre); //Code la lettre de la phrase à coder en numéro

            lettreCodeeNum += lettreCodageNum; //Ajoute la lettre
            lettreCodeeNum %= 26; //Si l'addition est >= 26 (donc plus que "z"), remet a 0 (modulo 26)

            lettreCodee = codageLettre(lettreCodeeNum); //Décode le numéro qui a été codé plus haut, en lettre
        }

        else { //Si la lettre n'est pas une lettre mais un espace
            lettreCodee = ' '; //La lettre n'est pas a coder et prend directement la valeur espace ' '
        }
        phraseCodee[j] += lettreCodee; //Ajoute la lettre codée (ou l'espace) à la phrase codée en entière

        i++; //+1 sur i
        j++; //+1 sur j
    }
    while (j < nombreLettres); //Tant que le nombre de lettre traitée n'a pas atteind le nombre de lettre de la "phraseEntiere"

    printf("\n\nVotre phrase une fois codée donne: %s", phraseCodee); //Affiche "phraseCodee" en entière
}






//Liens pour codage http://villemin.gerard.free.fr/Crypto/RSA.htm#top
//http://villemin.gerard.free.fr/Crypto/ClasLett.htm