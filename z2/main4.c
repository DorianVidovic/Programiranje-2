/*
Z4:	-Napisati program koji definira strukturu za zapis podataka o životinjama: vrsta životinje, 
	broj noga, boja, očekivana dužina živoota. 
	-Program inicijalizira podatke za 10 životinja i 
	ispisuje ih sortirane po očekivanoj dužini života (uzlazno), odnosno po broju noga
	(silazno) ako je očekivana dužina života ista.
*/
#include <stdio.h>

struct zivotinje
{
	char vrsta[10];
	char boja[10];
	int brNoga;
	float ocekivanaDucinaZ;
	
};

void sortiranje(struct zivotinje Z1[10])
{
	struct zivotinje pZ;
	int i, j;
	
	for(i = 0; i < 10 - 1; i++)
		for(j = i + 1; j < 10; j++)

			if((Z1[i].ocekivanaDucinaZ > Z1[j].ocekivanaDucinaZ) || ( (Z1[i].ocekivanaDucinaZ == Z1[j].ocekivanaDucinaZ) && (Z1[i].brNoga < Z1[j].brNoga) ))
			{
				pZ = Z1[i];
				Z1[i] = Z1[j];
				Z1[j] = pZ;
			}
}

void ispisPodataka(struct zivotinje Z1[10])
{
	int i;
	puts("\nZivotinje sortirane: ");
	printf("----------\n");
	for(i = 0; i < 10; i++){
		printf("Vrssta zivotinje: %s, boja: %s, broj noga: %d, duzina zivota: %.2f\n", Z1[i].vrsta, Z1[i].boja, Z1[i].brNoga, Z1[i].ocekivanaDucinaZ);
	}
}


int main()
{
	struct zivotinje Z[10] = {
							{"Sisavci", "siva", 4, 1},
							{"Ptice", "crvena", 2, 0.25},
							{"Ptice", "zelena", 2, 0.45},
							{"Gmazovi", "ljubicasta", 0, 1.5},
							{"Vodozemci", "roza", 4, 0.25},
							{"Ribe", "blava", 0, 0.3},
							{"Rakovi", "crvena", 10, 0.25},
							{"Mekušci", "siva", 0, 0.05},
							{"Paučnjaci", "crva", 8, 0.09},
							{"Kukci", "crna", 6, 0.009}
	};

	sortiranje(Z);
	ispisPodataka(Z);

	scanf("%s",Z[0].boja);
	
	return 0;
}