#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main()
{
    char stored[MAX] = {' '};
    int lengthCheck = 0;
    int storedLetters[MAX] = {0};
    int finalTemp = 0;
    int finalLetters[MAX] = {0};
    int letindex = 0;
    int tempSort = 0;
    int ergebnis[MAX] = {0};
    int ergebnisIndex = 0;
    int ergebnisCount = 1;
    int printIndex = 0;


            //Initialisierung des Arrays "stored" mit Whitespace
            for(int i = 0; i < 80; i++){
            stored[i] = ' ';
            }

//===========================================================================================================================
            //Scanen des Satzes
            printf(": ");

            scanf("%[^\n]s", stored);

//===========================================================================================================================
             //NOT VALID Überprüfung
            //Eingabe auf "." prüfen
            for(int i = 0; i < MAX; i++){
                if(stored[i] == '\0' && stored[strlen(stored)-1] != '.'){
                    printf("NOT VALID\n");
                    return 0;
                }
            }
//===========================================================================================================================
             //NOT VALID Überprüfung
            //Eingabe auf Länge prüfen
            for(int i = 0; i < MAX; i++){
                if(stored[i] != '\0'){
                    lengthCheck++;
                }
                    if(lengthCheck > 80){
                        printf("NOT VALID\n");
                        return 0;
                    }
            }
//===========================================================================================================================
             //NOT VALID Überprüfung
            //Eingabe auf Sonderzeichen untersuchen
            for(int i = 0; i < MAX; i++){
                if((stored[i] <= 64 && stored[i] != 32 && stored[i] != '\0' && stored[i] != 46) || (stored[i] >= 91 && stored[i] <= 96 && stored[i] != 32 && stored[i] != '\0' && stored[i] != 46) || (stored[i] >= 123 && stored[i] <= 127 && stored[i] != 32 && stored[i] != '\0' && stored[i] != 46)) {
                    printf("NOT VALID\n");
                    return 0;
                }
            }
//===========================================================================================================================
            //In Array nach Chars suchen und als 1er Abspeichern
            for(int i = 0; i < MAX; i++){
                if(stored[i] == '.'){
                    break;
                }else if(stored[i] != ' '){
                    storedLetters[i] = 1;
                }
            }
//===========================================================================================================================
            //Einser zusammenzählen und die Anzahl der Buchstaben in neuen Array speichern
            for(int t = 0; t < MAX; t++){
                if(storedLetters[t] == 1){
                    finalTemp++;
                }else{
                    finalLetters[letindex] = finalTemp;
                    finalTemp = 0;
                    letindex++;
                }
            }
//===========================================================================================================================
            //Sortieren des Arrays nach Größen
            for(int i = 0; i < 10; i++){
                for(int z = 0; z < MAX; z++){
                    if(finalLetters[z] > finalLetters[z+1] && finalLetters[z] != 0 && finalLetters[z+1] != 0){
                        tempSort = finalLetters[z];
                        finalLetters[z] = finalLetters[z+1];
                        finalLetters[z+1] = tempSort;
                    }
                }
            }
//===========================================================================================================================
            //Sortiertes Array in Ergebnis eintragen, Zahlenwerte und wie oft Zahl vorkommt
            for(int y = 0; y < MAX; y++){
                if(finalLetters[y] == 0){
                    break;
                }
                    ergebnis[ergebnisIndex] = finalLetters[y];
                        if(finalLetters[y] == finalLetters[y+1]){
                            ergebnisCount++;
                        }else{
                            ergebnisIndex++;
                            ergebnis[ergebnisIndex] = ergebnisCount;
                            ergebnisIndex++;
                            ergebnisCount = 1;
                        }
            }
//===========================================================================================================================
            //Print
            for(int i = 0; i < MAX; i++){
                    if(ergebnis[printIndex] == 0){
                        break;
                    }else{
                     printf("Length %d: %d\n", ergebnis[printIndex], ergebnis[printIndex+1]);
                     printIndex++;
                     printIndex++;
                    }
            }

return 0;

}

