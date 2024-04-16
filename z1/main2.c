/*
	Z2: -Napisati program koji unosi riječi sve dok se ne unese riječ u kojoj se neko slovo ponavlja 
		barem tri puta i,
		
		-nakon toga, ispisuje sve unesene riječi koje počinju i završavaju itim 
		slovom, ne vodeći računa o razlici velikih i malih slova, sortirane silazno po abecedi.
*/

// Dorian Vidović 2273

#include <stdio.h>
#include <string.h>


int slovoSePonavlja(char rijec[]){

	for (int i = 0; i < strlen(rijec); ++i)
	{
		int brojPonavljanja = 0;

		for (int j = 0; j < strlen(rijec); ++j)
		{
			if (rijec[i] == rijec[j])
			{
				brojPonavljanja++;
			}
		}
		if (brojPonavljanja > 2)
		{
			return 1;
		}
	}
	return 0;
}

//10 stringova po 20 znakova
char rijeci[10][20];
int n = 0;

int main()
{
	while(1)
	{
		
		printf("Unesi tekst: ");
		fflush(stdin);
		fgets(rijeci[n], sizeof(rijeci[n]), stdin);

		if(slovoSePonavlja(rijeci[n])){
			printf("\n---break--\n");
			break;
		}

		n++;
	}

	puts(rijeci[n]);

	//sortiranje

	char temp[20];
	
	  for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strcmp(rijeci[j], rijeci[j+1]) > 0) {

    			strcpy(temp, rijeci[j]);
				strcpy(rijeci[j], rijeci[j+1]);
				strcpy(rijeci[j+1], temp);
            }
        }
        for (int l = 0; l < n; ++l)
		{
			puts(rijeci[l]);
		}
		puts("--------");
    }

	for (int i = 0; i < n; ++i)
	{
		puts(rijeci[i]);
	}

	fgets(rijeci[n], sizeof(rijeci[n]), stdin);

	return 0;
}