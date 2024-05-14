/*
Z1:	Napisati program koji definira strukturu za zapis podataka o kompleksnim brojevima: 
	realni i imaginarni dio (float),

	unosi podatke za dva kompleksna broja i u posebnim 
	funkcijama računa njihov zbroj, razliku, umnožak i količnik (sve funkcije imaju dva 
	kompleksna broja kao ulazne parametre i vraćaju kompleksni broj koji predstavlja 
	rezultat računske operacije). 

	Svi rezultati se ispisuju u glavnom programu.
*/
#include <stdio.h>

struct kompleksanBr
{
	float realni;
	float imaginarni;	
};

struct kompleksanBr unos(){
	struct kompleksanBr br;

	printf("Unesi realni dio kompleksnog broja: ");
	scanf("%f", &br.realni);
	printf("Unesi imaginarni dio kompleksnog broja: ");
	scanf("%f", &br.imaginarni);

	return br;
}

void ispis(char poruka[], struct kompleksanBr br){
	printf("%s - %.2f + %.2fi\n", poruka, br.realni, br.imaginarni);
}

struct kompleksanBr zbroj(struct kompleksanBr a, struct kompleksanBr b){
	struct kompleksanBr p;
	p.realni = a.realni + b.realni;
	p.imaginarni = a.imaginarni + b.imaginarni;
	return p;
}

struct kompleksanBr razlika(struct kompleksanBr a, struct kompleksanBr b){
	struct kompleksanBr p;
	p.realni = a.realni - b.realni;
	p.imaginarni = a.imaginarni - b.imaginarni;
	return p;
}

struct kompleksanBr umnozak(struct kompleksanBr a, struct kompleksanBr b){
	//(a + bi) * (c + di) = (ac - bd) + (ad + bc)i
	struct kompleksanBr p;
	p.realni = (a.realni * b.realni) - (a.imaginarni * b.imaginarni);
	p.imaginarni = (a.realni * b.imaginarni) + (a.imaginarni * b.realni);
	return p;
}
/*
struct kompleksanBr kolicnik(struct kompleksanBr a, struct kompleksanBr b){
	//
	struct kompleksanBr p;
	p.realni = ;
	p.imaginarni = ;
	return p;
}
*/

// Function to divide two complex numbers
struct kompleksanBr kolicnik(struct kompleksanBr a, struct kompleksanBr b) {
    struct kompleksanBr p;
    float nazivnik = b.realni * b.realni + b.imaginarni * b.imaginarni;
    
    // Check for division by zero
    if(nazivnik == 0) {
        printf("Djeljenje nije dopusteno.\n");
        p.realni = 0;
        p.imaginarni = 0;
        return p;
    }

    p.realni = (a.realni * b.realni + a.imaginarni * b.imaginarni) / nazivnik;
    p.imaginarni = (a.imaginarni * b.realni - a.realni * b.imaginarni) / nazivnik;

    return p;
}

int main()
{
	struct kompleksanBr a, b, rez, z, d;

	a = unos();
	b = unos();
	/**/
	ispis("\n a- ",a);
	ispis("\n b- ",b);

	rez = zbroj(a, b);
	ispis("\nzbroj",rez);
	rez = razlika(a, b);
	ispis("razlika",rez);
	rez = umnozak(a, b);
	ispis("umnozak",rez);
	rez = kolicnik(a, b);
	ispis("kolicnik",rez);

	a = unos();
	
	return 0;
}