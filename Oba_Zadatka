#include <stdio.h>
#include <stdlib.h>


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

void upisUDatoteku(FILE *izlaz) {

    int godinaRodjenja[10];
    int danRodjenja[10];
    char ime[20][10];
    char prezime[20][10];
    char mesecRodjenja[10][10]; // predstavlja mesec unet kao rec tj. string
    int i, j; // pomocne promenljive za kretanje kroz matricu

    izlaz = fopen("rodjendan.txt", "w"); // Otvaranje datoteke

      for ( i = 0; i < 2; ++i) { //+ LIMIT DO DVA SVRHA VRZE TESTIRANJE PROGRAMA!
        printf("\n\nUnos podataka za\n\t\t Osobu %d\n\n\n", i + 1);

        printf("\nUnesite ime osobe: ");
        scanf("%s", &ime[i]);

        printf("\nUnesite prezime: ");
        scanf("%s", &prezime[i]);

        do {
          printf("\nUnesite dan rodjenja(broj): ");
          scanf("%d", &danRodjenja[i]);
        } while (danRodjenja[i] < 1 || danRodjenja[i] > 31); // BUG: Ako se unese nesto sto nije broj program puca!

        printf("\nUnesite mesec rodjenja(slovima): ");
        scanf("%s", &mesecRodjenja[i]);

        printf("\nUnesite godinu rodjenja(broj): ");
        scanf("%d", &godinaRodjenja[i]);



        fprintf(izlaz, "%d %s %s %d. %s\n\n", ime[i], prezime[i], danRodjenja[i], mesecRodjenja[i], godinaRodjenja[i]);

        }

        fclose(izlaz);


}

void citanjeIzFajla(FILE *ulaz) {


    int godinaRodjenja[10];
  int danRodjenja[10];
  char ime[20][10];
  char prezime[20][10];
  char mesecRodjenja[10][10]; // predstavlja mesec unet kao rec tj. string
  int i, j; // pomocne promenljive za kretanje kroz matricu


  ulaz = fopen("rodjendan.txt", "r"); // Otvaranje datoteke

  for ( i = 0; i < 10; ++i) {
    printf("\n\nCitanje podataka za\n\t\t Osobu %d\n\n\n", i + 1);

    fscanf(ulaz, "%s", &ime[i]);

    fscanf(ulaz, "%s", &prezime[i]);

    fscanf(ulaz, "%d", &danRodjenja[i]);

    fscanf(ulaz, "%s", &mesecRodjenja[i]);

    fscanf(ulaz, "%d", &godinaRodjenja[i]);



    printf("Osoba %d:\n\t Ime: %s\n\t Prezime: %s\n\t Dan rodjenja: %d.\n\t Mesec rodjena: %s\n\t Godina rodjenja: %d\n\t\n\n\n",
      i + 1, ime[i], prezime[i], danRodjenja[i], mesecRodjenja[i], godinaRodjenja[i]);

    }

    fclose(ulaz);


}

int main(void) {




  FILE * ulaz, * izlaz;
  char izbor = 0;

funkcijaIzbor(&izbor);

if(izbor == '1') {

    upisUDatoteku(izlaz);

    return 0;
}
else {
    // ovde ide kod za citanje iz datoteke
    citanjeIzFajla(ulaz);
}


  return 0;
}
