/*
z2: Napisati program koji sa tastature unosi cijele brojeve sve dok se ne unese prost.

	Nakon svakog unosa, brojevi se smještaju u dinamički alociran memorijski prostor odgovarajuće 
	veličine. 

	Nakon završetka unosa, brojevi se spremaju u datoteku sortirani_brojevi.txt, 
	sortirani po veličini silazno.
*/

#include <stdio.h>
#include <stdlib.h>



int prost(int br){

	if ( br <= 1)
	{
		return 0;
	}

	for (int i = 2; i < br; ++i)
	{
		if (br % i == 0 )
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int broj = 0, index = 0;

	int* brojevi = NULL;

	FILE* f = NULL;

	while(1){

		brojevi = (int*)realloc(brojevi, sizeof(int)*(index+1));

		scanf("%d", &broj);

		brojevi[index] = broj;
		index++;

		if (prost(broj) == 1)
		{
			break;
		}
	}


	f = fopen("sortirani_brojevi.txt", "w");

	if (f==NULL)
	{
		printf("Greska pri otvaranju datoteke\n");
	}
	else{

		for (int i = 0; i < index-1; ++i)
		{
			for (int j = i+1; j < index; ++j)
			{
				if (brojevi[i] > brojevi[j])
				{
					int temp = brojevi[i];
					brojevi[i] = brojevi[j];
					brojevi[j] = temp;
				}				
			}
		}

		for (int i = 0; i < index; ++i)
		{

			fprintf(f, "%d\n", brojevi[i]);
		}
	}

	fclose(f);
	free(brojevi);

	return 0;
}