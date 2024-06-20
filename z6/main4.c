/*
z4: Napisati program koji učitava sva slova iz datoteke tekst.txt i nakon svakog učitanog 
	pohranjuje ih u dinamički alociran memorijski prostor odgovarajuće duljine. 

	Nakon što su svi znakovi pročitani, ispisuje se onaj znak koji se ponovio najviše puta, kao i broj 
	njegovih ponavljanja
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE* f = NULL;
	char* slova = NULL;

	int index = 0;
	int brPonavljanja[256] = {0};
	int maxPonavljanja = 0;
	char zn;

	f = fopen("tekst.txt", "r");

	if (f == NULL)
	{
		printf("Greska pri otvaranju datoteke\n");
	}
	else{

		while(1){

			if (!feof(f))
			{
				slova = (char*)realloc(slova,sizeof(char)*(index+1));
				slova[index] = fgetc(f);
				index++;
			}
			else{break;}

		}


		for (int i = 0; i < index; ++i)
		{
			printf(" znak[%d]: %c\n",i, slova[i]);
			brPonavljanja[slova[i]]++;
		}

		for (int i = 0; i < 256; ++i)
		{
			if (maxPonavljanja<brPonavljanja[i])
			{
				maxPonavljanja = brPonavljanja[i];
				zn = i;
			}
		}

	}

	int t;
	printf("znak koji se ponavlja najvise puta je: %c, ponavlja se %d puta\n", zn, brPonavljanja[zn]);
	scanf("%d", &t);
	

	return 0;
}