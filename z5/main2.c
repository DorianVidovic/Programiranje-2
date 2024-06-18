/*
z2: Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese broj 0. 
    
    Nakon svakog unosa broj se smješta u datoteku uneseni_brojevi.txt. 

    Nakon toga u datoteku sortirani_parni_brojevi.txt pohranjuju se uneseni parni brojevi sortirani po veličini.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int broj;
    FILE *uneseniBrojevi, *sortiraniBrojevi;

    // Otvaranje datoteke za unos brojeva
    uneseniBrojevi = fopen("uneseni_brojevi.txt", "w");

    if (uneseniBrojevi == NULL) {
        printf("Greška pri otvaranju datoteke za unos!\n");
        
    }
    else{


        // Unos brojeva sve dok se ne unese 0
        do {
            printf("Unesite cijeli broj (0 za kraj unosa): ");
            scanf("%d", &broj);
            fprintf(uneseniBrojevi, "%d\n", broj);
        } while (broj != 0);

        fclose(uneseniBrojevi);

    }

    // Otvaranje datoteke za čitanje unesenih brojeva
    uneseniBrojevi = fopen("uneseni_brojevi.txt", "r");

    if (uneseniBrojevi == NULL) {
        printf("Greška pri otvaranju datoteke za čitanje unesenih brojeva!\n");
    
    }
    else{
    
        // Otvaranje datoteke za pohranu sortiranih parnih brojeva
        sortiraniBrojevi = fopen("sortirani_parni_brojevi.txt", "w");

        if (sortiraniBrojevi == NULL) {
            printf("Greška pri otvaranju datoteke za pohranu sortiranih brojeva!\n");
            
        }
        else{

            // Čitanje unesenih brojeva i pohranjivanje parnih brojeva
            int parni_brojevi[100]; // Pretpostavljamo da neće biti više od 100 parnih brojeva
            int broj_parnih = 0;

            while (fscanf(uneseniBrojevi, "%d", &broj) != EOF) {
                if (broj % 2 == 0) {
                    parni_brojevi[broj_parnih] = broj;
                    broj_parnih++;
                }
            }

            // Sortiranje parnih brojeva (npr. bubble sort)
            for (int i = 0; i < broj_parnih - 1; i++) {
                for (int j = 0; j < broj_parnih - i - 1; j++) {

                    if (parni_brojevi[j] > parni_brojevi[j + 1]) {
                        
                        int temp = parni_brojevi[j];
                        parni_brojevi[j] = parni_brojevi[j + 1];
                        parni_brojevi[j + 1] = temp;
                    }
                }
            }

            // Pohranjivanje sortiranih parnih brojeva
            for (int i = 0; i < broj_parnih; i++) {
                fprintf(sortiraniBrojevi, "%d\n", parni_brojevi[i]);
            }

            fclose(uneseniBrojevi);
            fclose(sortiraniBrojevi);

            printf("Uneseni brojevi su pohranjeni u datoteku 'uneseni_brojevi.txt'.\n");
            printf("Sortirani parni brojevi su pohranjeni u datoteku 'sortirani_parni_brojevi.txt'.\n");
        }
    }

    return 0;
}
