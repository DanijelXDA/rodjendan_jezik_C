#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct osoba // Definicija strukture ucenik
	{
		int godinaRodjenja;
		int danRodjenja;
		char ime[20];
		char prezime[20];
		char mesecRodjenja[10]; // predtavlja mesec unet kao rec tj. string

	} o1, o2, o3, o4, o5, o6, o7, o8, o9, o10;

//Definicije i deklaracije slobodnih funkcija


// Funkcija kojom se korisniku dozvoljava da odabere da li da upisuje ili iscitava podatke iz datoteke "rodjendan.txt"
void funkcijaIzbor(char *n) {

    do {
        printf("\nOdaberite opciju: \n\t1. Upis u datoteku 'rodjendan.txt'\n\t2. Citanje podataka iz datoteke 'rodjendan.txt'\n\n Vas izbor je: ");
        scanf("%c", n);
        fflush(stdin);
    } while( (*n != '1' && *n != '2') );

    return; // ne vracamo nista jer je funkcija tipa void
}


void unosPodatakaUDatoteku(FILE *izlaz) {

    for(int j = 1; j < 11; ++j) {
        printf("Unos podataka za\n\t\t Osobu %d\n\n", j);

        printf("Unesite ime: ");
        gets(o1.ime);


        printf("\nUnesite prezime: ");
        gets(o1.prezime);

        do {
            printf("\nUnesite dan rodjenja(rodjenja): ");
            scanf("%d", &o1.danRodjenja);
        } while( o1.danRodjenja < 1 || o1.danRodjenja > 31); // BUG: Ako se unesete nesto sto nije broj program puca!


        printf("\nUnesite ")
    }

    for(int i = 1; i < 11; ++i) {
        fprintf(izlaz, "\t\tOsoba %d:\nIme: %s\t Prezime: %s\t Dan rodjenja: %d.\t Mesec rodjena: %s\t Godina rodjenja: %d\t\n",
                i, o1.ime, o1.prezime, o1.danRodjenja, o1.mesecRodjenja, o1.mesecRodjenja, o1.godinaRodjenja);
    }

    return;
}

bool otvaranjeDatoteke(FILE *izlaz) {


    bool uspesno = false;

    izlaz = fopen("rodjendan.txt", "a"); // Otvaranje datoteke


    if( izlaz != NULL ) {
        bool uspesno = true;
        printf("\t\tDatoteka kreirana!\n");
    }
    else {
        printf("\t\tDatoteka ne postoji!\n");
    }

    return uspesno;


}

int main(void)
{
    FILE *ulaz, *izlaz;

    izlaz = NULL;

    char izbor = -1; // Izbor jus uvek nije donet

    funkcijaIzbor(&izbor); // Pozivamo funckiju izbor

    if( izbor == '1')
        if( otvaranjeDatoteke(izlaz) == false) // Funkcija za unos podataka u datoteku 'rodjendan.txt'
            unosPodatakaUDatoteku(izlaz);
        else
            return 1;
    else {

    }

  return 0;
}
