/*
Description
=============
L'Arduino envoie a chaque 5 ms la valeur
de l'entrée analogique 0

Le message ASCII est compose des elements suivants:
1) "A0" suivi d'un espace
2) la valeur
3) indicateur de fin de ligne (retour de chariot)

Logitheques
=============
Cet exemple utilise la logitheque Chrono

Derniere version :  Thomas Ouellet Fredericks, 11 octobre 2014
Version originale : Thomas Ouellet Fredericks, 4 novembre 2012
*/

// INCLUDE CHRONO LIBRARY
// Documentation : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/blob/master/README.md
// Download : https://github.com/thomasfredericks/Chrono-Arduino-Wiring/archive/master.zip
#include <Chrono.h>

Chrono envoiMessage;


void setup() {

        // Demarrer la communication serie a 57600 baud.
        Serial.begin(57600);
}

void loop() {
        if ( envoiMessage.metro(5) ) {

                // Envoi de la mesure de l'entree analogique 0
                Serial.print("A0 "); // "ms" suivi d'un espace
                Serial.print( analogRead(0) ); // la valeur de la mesure
                Serial.println(); // indicateur de fin de ligne

        }
}
