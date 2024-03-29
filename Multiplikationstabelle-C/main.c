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
 * REQUIREMENTS HW-05:
 * + Ask the user for a number and save it in a variable.
 * + Filter out wrong inputs.
 * + Display a multiplication table between 1 and the submitted number.
 * + Make it possible to switch from decimal to hexadecimal.
 * + Make it possible to display tables smaller than 128 as character c.
 * + Display the tables in a orderly fashion.
 * 
 * 
 * Created on 02. October, 11:21
 */

// Benötigte Bibliotheken importieren
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // strcspn()
#include <math.h>       // log10

// Switch Print Type to display the table as symbols(%*c), decimals(%*d), or hexadecimals(%*x)
#define PrntType "%*d"

// Global variables
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
 * Input of a number by the user
 */
int inputNumber(void) {
    char input[2];
    
    printf("Bitte geben sie eine Zahl ein: ");
     if (fgets(input, 4, stdin)) {
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
    if (inputNumber() > 0 && Number <= 45){
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
    
    // get length of Number*Number
    int LEN = (int)log10(Number*Number)+2;
    
    printf("\n%c[1mTabelle mit Maximalwert %i*%i:%c[0m\n\n", 27, Number, Number, 27);
    
    for (int a=1; a <= Number; a++) {
        if(a == 1){
                printf("%c[1m%c[4m x|", 27,27);
                for (int b=1; b <= Number; b++)
                {
                    printf(PrntType, LEN, b);
                }
                printf("%c[0m\n", 27);
            }
        printf("%c[1m%2d|%c[0m", 27, a, 27);
        for (int b=1; b <= Number; b++)
        {
            printf(PrntType, LEN, a*b);
        }
        printf("\n");
    }
}