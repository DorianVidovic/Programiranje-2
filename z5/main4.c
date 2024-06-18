/*
z4  Napisati program koji učitava sva slova iz datoteke tekst.txt i nakon svakog učitanog znaka ispisuje,

	sortirane po abecedi sva do tada učitana slova. 

	Na kraju se ispisuje broj ponavljanja svakog od samoglasnika (ne vodeći računa radi li se o velikim i malim slovima).
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define Slova 100

void sortiraj(char slova[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (slova[j] > slova[j + 1]) {
                char temp = slova[j];
                slova[j] = slova[j + 1];
                slova[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *datoteka;
    char znak;
    char slova[Slova];
    int indeks = 0;
    int broj_a = 0, broj_e = 0, broj_i = 0, broj_o = 0, broj_u = 0;

    datoteka = fopen("tekst.txt", "r");
    if (datoteka == NULL) {
        printf("Pogreška pri otvaranju datoteke!\n");
    } else {
        while ((znak = fgetc(datoteka)) != EOF && indeks < Slova) {
            if (isalpha(znak)) {
                znak = tolower(znak);
                slova[indeks++] = znak;

                switch (znak) {
                    case 'a': broj_a++; break;
                    case 'e': broj_e++; break;
                    case 'i': broj_i++; break;
                    case 'o': broj_o++; break;
                    case 'u': broj_u++; break;
                }

                sortiraj(slova, indeks);
                printf("Slova sortirana po abecedi: ");
                for (int i = 0; i < indeks; i++) {
                    printf("%c", slova[i]);
                }
                printf("\n");
            }
        }

        fclose(datoteka);

        printf("Broj 'a': %d\n", broj_a);
        printf("Broj 'e': %d\n", broj_e);
        printf("Broj 'i': %d\n", broj_i);
        printf("Broj 'o': %d\n", broj_o);
        printf("Broj 'u': %d\n", broj_u);
    }

    return 0;
}
