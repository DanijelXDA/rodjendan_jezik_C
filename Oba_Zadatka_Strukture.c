#include <stdio.h>
#include <stdlib.h>

// Definisanje strukture Osoba

int i = 0; // pomocne promenljive za kretanje kroz matricu

struct Osoba {

   int godinaRodjenja;
   int danRodjenja;
   char ime[20];
   char prezime[20];
   char mesecRodjenja[10]; // predstavlja mesec unet kao rec tj. string


} osobe[10], o;

   //Definicije i deklaracije slobodnih funkcija

   // Funkcija kojom se korisniku dozvoljava da odabere da li da upisuje ili iscitava podatke iz datoteke "rodjendan.txt"
   void funkcijaIzbor(char * n) {

      do {

         printf("\nOdaberite opciju: \n\t1. Upis u datoteku 'rodjendan.txt'\n\t2. Citanje podataka iz datoteke 'rodjendan.txt'\n\t3. Izlaz iz programa\n\n Vas izbor je: ");
         scanf(" %c", n);

      } while (( * n != '1' && * n != '2' && * n != '3'));

      return; // ne vracamo nista jer je funkcija tipa void
   }

void upisUDatoteku(FILE * izlaz) {


   izlaz = fopen("rodjendan.txt", "w"); // Otvaranje datoteke

   for (i = 0; i < 10; ++i) { // LIMIT DO DVA SVRHA BRZE TESTIRANJE PROGRAMA!
      printf("\nUnos podataka za\n\t\t Osobu %d\n", i + 1);

      printf("\nUnesite ime osobe: ");
      scanf("%s", & osobe[i].ime);

      printf("\nUnesite prezime: ");
      scanf("%s", & osobe[i].prezime[i]);

      do {
         printf("\nUnesite dan rodjenja(broj): ");
         scanf("%d", & osobe[i].danRodjenja);
      } while (osobe[i].danRodjenja < 1 || osobe[i].danRodjenja > 31); // BUG: Ako se unese nesto sto nije broj program puca!

      printf("\nUnesite mesec rodjenja(slovima): ");
      scanf("%s", & osobe[i].mesecRodjenja);

      printf("\nUnesite godinu rodjenja(broj): ");
      scanf("%d", & osobe[i].godinaRodjenja );

      fprintf(izlaz, "%s %s %d %s %d\n", osobe[i].ime, osobe[i].prezime, osobe[i].danRodjenja, osobe[i].mesecRodjenja, osobe[i].godinaRodjenja);

   }

   fclose(izlaz);

   return;

}

void citanjeIzFajla(FILE * ulaz) {

   ulaz = fopen("rodjendan.txt", "r"); // Otvaranje datoteke

   for (i = 0; i < 10; ++i) {
      printf("\n\nCitanje podataka za\n\t\t Osobu %d\n\n", i + 1);

      fscanf(ulaz, "%s", & osobe[i].ime);

      fscanf(ulaz, "%s", & osobe[i].prezime);

      fscanf(ulaz, "%d", & osobe[i].danRodjenja);

      fscanf(ulaz, "%s", & osobe[i].mesecRodjenja);

      fscanf(ulaz, "%d", & osobe[i].godinaRodjenja);

      printf("Osoba %d:\n\t Ime: %s\n\t Prezime: %s\n\t Dan rodjenja: %d.\n\t Mesec rodjena: %s\n\t Godina rodjenja: %d\n\t\n", i + 1, osobe[i].ime, osobe[i].prezime, osobe[i].danRodjenja, osobe[i].mesecRodjenja, osobe[i].godinaRodjenja);

   }

   fclose(ulaz);

   return;

}

int main(void) {

   FILE * ulaz, * izlaz;
   char izbor = 0;

   do {

      funkcijaIzbor( & izbor);

      if (izbor == '1' && izbor != '3')
         upisUDatoteku(izlaz);

      else if (izbor == '2' && izbor != '3')
      // ovde ide kod za citanje iz datoteke
         citanjeIzFajla(ulaz);

   }
   while (izbor != '3');

   return 0;
}
