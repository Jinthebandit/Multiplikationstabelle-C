/* 
 * File:   main.c
 * Author: Lukas Fischer
 * GitHub: https://github.com/Jinthebandit/Multiplikationstabelle-C.git
 * 
 * REQUIREMENTS HW-03:
 * + Benutzer nach einer Zahl fragen.
 * + Die Zahl in eine Variable speicher.
 * + Zahl ueberpruefen -> nur positive Werte erlaubt.
 * + Multiplikationstabelle erstellen: 1 bis Zahl.* 
 * 
 * DEVELOPMENT CYCLE:
 * Gesucht: Multiplikationstabelle
 * Gegeben: Eingabe eines Max-Wertes durch den Benutzer
 * Vorgehen:
 *      1. Globale Variable erstellen
 *      2. Funktion fuer Eingabe
 *      3. Funktion fuer Ueberpruefung der Eingabe
 *      4. Array fuer Multiplikationstabelle
 *      5. Funktion fuer Multiplikationstabelle ausgeben
 * 
 * Created on 02. October, 11:21
 */

// Benötigte Bibliotheken importieren
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>    // um true/false verwenden zu koennen
//#include <math.h>       // Mathematische Funktionen
//#include <time.h>       // time()
#include <string.h>     // strcspn()

// Globale Variablen
int Number;
int multTable[10][10] = { 0 }; 

// Forward Funktions
int inputNumber(void);

/*
 * Magic happens
 */
int main(int argc, char** argv) {
    
    printf("Ihre Eingabe: %i", inputNumber());

    return (EXIT_SUCCESS);

}

int inputNumber(void) {
    char input[2];
    
    printf("Bitte geben sie eine Zahl von 1-10 ein: ");
     if (fgets(input, 40, stdin)) {
        input[strcspn(input, "\n")+1] = 0;
        sscanf(input, "%i", &Number);
    }
    
    return Number;
}