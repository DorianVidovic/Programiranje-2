/*
	Z1: Napisati program koji unosi tekst i formira novi string u kojem je svaki znak zamijenjen 
	    skupinom od tri znaka koji predstavljaju ASCII kod tog znaka (npr. slovo 'A' mijenja se 
	    skupinom znakova "065", a slovo 'm' skupinom znakova "109") te se formirani string 
	    ispisuje na ekran.
*/	  

#include <stdio.h>
#include <string.h>

char string1[10], string2[30];

int main()
{
	printf("Unesi tekst: ");
	fflush(stdin);
	fgets(string1, sizeof(string1), stdin);


	for (int i = 0; i < strlen(string1)-1; ++i)
	{
		printf("-----\nchar - %d\n", i+1);

		int temp = string1[i];
		printf("ascii - %d\n", temp);
		int d1[3] = {};

		for (int k = 2; k > -1; --k)
		{
			d1[k] = temp%10;
			//printf("d1[%d] = %d\n", k, temp%10);
			temp /= 10;
		}

		for (int j = 0; j < 3; ++j)
		{
				
			string2[j+i*3] = d1[j]+48;


		}
	}

	printf("\n");
	puts(string2);

	fgets(string1, sizeof(string1), stdin);
	return 0;
}

