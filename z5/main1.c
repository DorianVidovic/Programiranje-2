/*
Z1: Napisati program koji od korisnika traži naziv datoteke u kojoj su zapisane izmjereni
	vodostaji (realni brojevi) na određenom mjernom mjestu tijekom vremena. Pročitati sve 
	vodostaje i odrediti prosječan vodostaj na tom mjernom mjestu. 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    char ime_datoteke[100];
    FILE *f;

    float vodostaj, suma_vodostaja = 0;
    int broj_vodostaja = 0;

    printf("Unesite ime datoteke: ");
    scanf("%s", ime_datoteke);

    f = fopen(ime_datoteke, "r");
    if (f == NULL) {
        printf("Greska pri otvaranju datoteke!\n");
        
    }
    else{

	    while (fscanf(f, "%f", &vodostaj) != EOF) {
	        suma_vodostaja += vodostaj;
	        broj_vodostaja++;
	    }

	    fclose(f);

	    if (broj_vodostaja > 0) {
	        float prosjecni_vodostaj = suma_vodostaja / broj_vodostaja;
	        printf("Prosjcan vodostaj: %.2f\n", prosjecni_vodostaj);
	    } 
	    else {
	        printf("Datoteka je prazna ili ne sadrzi validne vodostaje.\n");
	    }

    }

    scanf("%s",ime_datoteke);
    return 0;
}
