/*
z1: Napisati program koji od korisnika traži naziv datoteke u kojoj su zapisane izmjerene 
	dubine vodostaja Neretve na određenom mjernom mjestu tijekom vremena.

	Pročitati sve temperature, pohraniti ih u dinamički alociran memorijski prostor odgovarajuće 
	veličine i odrediti prosječnu dubinu vodostaja na tom mjernom mjestu.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char imeDatoteke[20];
	FILE* f;

	float* mjerenja = NULL;

	float dubinaVodostaja;
	float prosDubinaVodostaja;
	int kolMjerenja = 0;


	printf("Upisi ime datoteke: ");
	scanf("%s", imeDatoteke);


	printf("\n\nimeDatoteke: %s\n\n",imeDatoteke);

	f = fopen(imeDatoteke,"r");

	if (f == NULL)
	{
		printf("Greska pri otvaranju datoteke\n");
	}
	else{
		while(fscanf(f, "%f", &dubinaVodostaja) != EOF){

			mjerenja = (float*)realloc(mjerenja, sizeof(float)*kolMjerenja+1);

			mjerenja[kolMjerenja] = dubinaVodostaja;
			kolMjerenja++;
		}

		for (int i = 0; i < kolMjerenja; ++i)
		{
			prosDubinaVodostaja += mjerenja[i];
		}

		printf("prosjek vodostaja je: %.2f\n",(prosDubinaVodostaja/kolMjerenja) );
	}

	fclose(f);
	free(mjerenja);

	return 0;
}