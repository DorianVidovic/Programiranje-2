/*
Z4: Napisati program koji definira strukturu za zapis podataka o gradovima: ime grada
	(string), država u kojoj se nalazi (string), broj stanovnika (int), najbliža rijeka (string) i 
	najbliža planina (string). 

	Program inicijalizira podatke za 10 gradova, unosi ime rijeke i 
	planine i pronalazi onaj grad kojima je to najbliža rijeka, odnosno planina (po jedan grad 
	za svaki zemljopisni pojam), 

	a ako ima više takvih gradova ispisuje se onaj koji ima 
	najveći broj stanovnika. Sve radnje se obavljaju u zasebnim funkcijama, a ispis rezultata 
	u glavnom programu.
*/

#include <stdio.h>
#include <string.h>

struct grad
{
	char ime[16];
	char drzava[32];
	int brStanovnika;
	char rijeka[16];
	char planina[16];
	
};

struct gradovi
{
	struct grad gradNajbliziRijeci;
	struct grad gradNajbliziPlanini;
};

void unos(char ri[], char pl[]){

	printf("Unesi ime rijeke: ");
	fgets(ri, 16, stdin);
	ri[ strlen(ri) - 1 ] = '\0';// makne \n sa kraja stringa

	printf("Unesi ime planine: ");
	fgets(pl, 16, stdin);
	pl[ strlen(pl) - 1 ] = '\0'; // makne \n sa kraja stringa

}

struct gradovi najbliziGrad(char ri[], char pl[], struct grad gr[]){

	struct gradovi najBlGradovi;
	int brSta1 = 0,brSta2 = 0;

	for (int i = 0; i < 10; ++i)
	{
		if ((strcmpi(gr[i].rijeka, ri) == 0) && (gr[i].brStanovnika >= brSta1))
		{
			najBlGradovi.gradNajbliziRijeci = gr[i];
			brSta1 = gr[i].brStanovnika;
		}

		if ((strcmpi(gr[i].planina, pl) == 0) && gr[i].brStanovnika >= brSta2)
		{
			najBlGradovi.gradNajbliziPlanini = gr[i];
			brSta2 = gr[i].brStanovnika;
		}
		printf("->%s\n", najBlGradovi.gradNajbliziRijeci.ime);
	}

	return najBlGradovi;
}


int main()
{
	char rijeka[16], planina[16];
	struct gradovi Gradovi;
	struct grad a[10] = {

		{"Mostar","BiH",60195 ,"Neretva","Planina A"},
		{"Sarajevo","BiH",274879 ,"Bijela rijeka","Planina B"},
		{"Banja Luka","BiH",185042 ,"Vrbas","Planina C"},
		{"Jajce","BiH",7889 ,"Pliva","Planina D"},
		{"Vitez","BiH",25836 ,"Lasva","Planina E"},
		{"Tuzla","BiH",110979 ,"Jala","Planina E"},
		{"Neum","BiH",5000 ,"Neretva","Planina A"},
		{"Bugojno","BiH",31470 ,"Vrbas","Planina F"},
		{"Gradiška","BiH",62000 ,"Sava","Planina G"},
		{"Nova Gradiska","RH",14229 ,"Sava","Planina G"},
		
	};

	unos(rijeka, planina);
	Gradovi = najbliziGrad(rijeka, planina, a);
	printf("Najblizi grad rijeci -%s- je %s, a najblizi grad planini -%s- je %s\n", rijeka, Gradovi.gradNajbliziRijeci.ime, planina, Gradovi.gradNajbliziPlanini.ime);


	unos(rijeka, planina);

	return 0;
}