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
 *      1. Globale Variable erstellen: "Number"
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
int checkNumber(void);
void showTable(int Number);

/*
 * Magic happens
 */
int main(int argc, char** argv) {
    
    
    if (checkNumber()) {
        showTable(Number);
    }

    return (EXIT_SUCCESS);

}

/*
 * Eingabe einer Zahl durch den Benutzer
 */
int inputNumber(void) {
    char input[2];
    
    printf("Bitte geben sie eine Zahl von 1-10 ein: ");
     if (fgets(input, 40, stdin)) {
        input[strcspn(input, "\n")+1] = 0;
        sscanf(input, "%i", &Number);
    }
    
    return Number;
}

/*
 * Rekursive Funktion
 * Ueberpruefen, ob der Eingegeben Wert eine Zahl zwischen 1 und 10 ist
 * 
 * Returns: int Number
 */
int checkNumber(void) {
    inputNumber();
    
    if (Number > 0 && Number <= 10){
        return Number;
    } else {
        puts("Ihre Eingabe war ungueltig");
        checkNumber();
    }
}

void showTable(int Number) {
    int a;
    int b;
    
    printf("\nTabelle: %i\n", Number);
    
    for (a=1; a<=Number; a++) {
        for (b=1; b<=Number; b++){
            if (a*b < 10) {
                printf(" %i ", a*b);
            } else {
                printf("%i ", a*b);
            }
        }
        printf("\n");
    }
}