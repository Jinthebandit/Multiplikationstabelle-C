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
 *      5. Funktion fuer Multiplikationstabelle ausgeben
 * 
 * Created on 02. October, 11:21
 */

// Benötigte Bibliotheken importieren
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // strcspn()
#include <math.h>       // log10

// Globale Variablen
int Number;

// Forward Declarations
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
    
    printf("Bitte geben sie eine Zahl ein: ");
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
    
    if (Number > 0 && Number <= 50){
        return Number;
    } else {
        puts("Ihre Eingabe war ungueltig");
        checkNumber();
    }
}

/*
 * Ausgabe der Tabelle
 * Maximalwert: Number * Number
 */
void showTable(int Number) {
    
    printf("\nTabelle mit Maximalwert %i*%i:\n\n", Number, Number);
    
    int Length = 2;
    for (int a=1; a<=Number; a++) {
        if(a == 1){
                printf("%c[4m%.*i  ", 27, Length, 0);
                for (int b=1; b<=Number; b++){
                    printf("%.*i ", Length, b);
                }
                printf("%c[0m\n", 27);
            }
        printf("%.*i| ", Length, a);
        for (int b=1; b<=Number; b++){
            printf("%.*i ", Length, a*b);
        }
        printf("\n");
    }
}