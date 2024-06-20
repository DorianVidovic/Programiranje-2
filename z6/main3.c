/*
z3: Napisati program koji definira strukturu za zapis kompleksnih brojeva: real i imagi 
	dio (float)

	i iz datoteke kompleksni_brojevi.txt čita podatke za 10 kompleksnih brojeva i 
	smješta ih u dinamički alociran memorijski prostor odgovarajuće duljine. 

	Nakon toga unosi se dodatni kompleksni broj i ispisuje onaj od učitanih kompleksnih brojeva koji je 
	od dodatnog broja najudaljeniji u kompleksnoj ravnini.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct kompleksniBr
{
	float real;
	float imagi;
};


float udaljenost(struct kompleksniBr a, struct kompleksniBr b) {
    float dx = a.real - b.real;
    float dy = a.imagi - b.imagi;
    return sqrt(pow(dx,2) +pow(dy,2));
}


int main()
{
	FILE* f = NULL;
	struct kompleksniBr* kompBrojevi = NULL;

	struct kompleksniBr temp;

	float flt;

	f = fopen("kompleksni_brojevi.txt","r");


	if (f == NULL)
	{
		printf("Greska pri otvaranju datoteke\n");
	}
	else{

		for (int i = 0; i < 10; ++i)
		{

			kompBrojevi = (struct kompleksniBr*)realloc(kompBrojevi, sizeof(struct kompleksniBr)*(i+1));
			
			if (kompBrojevi == NULL)
			{
				printf("alociranje nije uspilo\n");
				scanf("%f",&flt);

			}

			fscanf(f, "%f %f ", &temp.real, &temp.imagi);

			kompBrojevi[i] = temp;
		}

		for (int i = 0; i < 10; ++i)
		{
			printf("%.2f %.2f\n",kompBrojevi[i].real, kompBrojevi[i].imagi);
		}


		printf("\n\nUnesi jos jedan kompleksni broj:\n");
		scanf("%f %f", &temp.real, &temp.imagi);
	}

	fclose(f);

	float maxUdaljenost = 0;
	int indexMaxUdaljenosti = 0;

	for (int i = 0; i < 10; ++i)
	{
		float uda = udaljenost(kompBrojevi[i], temp);

		if (uda > maxUdaljenost)
		{
			maxUdaljenost = uda;
			indexMaxUdaljenosti = i;
		}
	}

	printf("kom. broj koji je najudaljeniji od kom. broja %.2f + %.2fi je: %.2f + %.2fi\n", 
		temp.real, temp.imagi, kompBrojevi[indexMaxUdaljenosti].real, kompBrojevi[indexMaxUdaljenosti].imagi);


		scanf("%f",&flt);

	return 0;
}