/*
Z3: Napisati program koji definira strukturu za zapis podataka o adresama koje unosi 
	korisnik: ulica (string), kućni broj (int), mjesto (string) i poštanski broj (int), 

	unosi podatke za 10 adresa, dodatno unosi mjesto i formira dva niza adresa, jedan u dodatno 
	unesenom mjestu i drugi izvan njega, 

	sortirane po abecedi naziva ulice, odnosno kućnom broju ako je ulica ista. 
	
	Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata u glavnom programu.
*/

//////Nemam Pojma

#include <stdio.h>

struct adresa
{
	int kucniBr;
	char ulica[16];
	char mjesto[16];
	int postanskiBr;
	
};

struct adresa unos(struct adresa *a[]){

	for (int i = 0; i < 10; ++i)
	{
		scanf("%d",a[i]->kucniBr);
		fflush(stdin);
		fgets(a[i]->ulica, sizeof(a[i]->ulica), stdin);
		fflush(stdin);
		fgets(a[i]->mjesto, sizeof(a[i]->mjesto), stdin);
		scanf("%d",a[i]->postanskiBr);

	}
}

int main()
{
	

	return 0;
}