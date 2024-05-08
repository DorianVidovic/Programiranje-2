/*
Z2:	-Napisati program koji definira strukturu za zapis podataka o plovilima: proizvođač
	(string), model (string), snaga u kWh (int) i cijena (float). 
	-Program inicijalizira podatke za 10 plovila, od korisnika traži podatke 
	o maksimalnoj snazi i minimalnoj cijeni vozila koje 
	korisnik traži te mu ispisuje podatke o svim vozilima koja zadovoljavaju unesene 
	podatke.
*/
#include <stdio.h>

struct plovilo
{
	char proizvodac[32];
	char model[32];
	int snagakWh;
	float cjena;
	
};

int main()
{
	int maxSnaga;
	int minCjena;

	struct plovilo P1[10] = {
							{"Sea Ray Boats", "A", 192, 2999.99},
							{"Bayliner", 	  "Xyz", 300, 2500.25},
							{"MasterCraft",   "No. 9", 70, 700},
							{"Bertram",       "hhjt", 65, 321},
							{"Boston Whaler", "tdi", 457, 345},
							{"Chaparral",     "bd 7", 890, 890},
							{"Grady-White",   "sbr", 44, 467},
							{"Lund",          "super et", 1000, 9800.99},
							{"Tracker",       "ctz", 534, 789.99},
							{"Jeanneau",      "mn 9", 32, 250}
	};

	printf("Maksimalna snaga u kWh?: ");
	scanf("%d", &maxSnaga);
	printf("Minimalna cjena?: ");
	scanf("%d", &minCjena);

	for (int i = 0; i < 10; ++i)
	{
		if (P1[i].snagakWh <= maxSnaga && P1[i].cjena >= minCjena)
		{
			printf("- %s, %s, snaga: %d, cjena: %.2f\n", P1[i].proizvodac, P1[i].model, P1[i].snagakWh, P1[i].cjena);
		}
	}
	
	scanf("%d", &maxSnaga);

	return 0;
}