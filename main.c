
#include <stdio.h> 
#include <stdlib.h> 
    
int main(void) {
	
  int godinaRodjenja[10];
  int danRodjenja[10];
  char ime[20][10];
  char prezime[20][10];
  char mesecRodjenja[10][10]; // predstavlja mesec unet kao rec tj. string    
  int i, j; // pomocne promenljive za kretanje kroz matricu
  
  FILE * ulaz, * izlaz;

  izlaz = fopen("rodjendan.txt", "w"); // Otvaranje datoteke
  
  for ( i = 0; i < 2; ++i) {
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
    
    

    fprintf(izlaz, "Osoba %d:\n\t Ime: %s\n\t Prezime: %s\n\t Dan rodjenja: %d.\n\t Mesec rodjena: %s\n\t Godina rodjenja: %d\n\t\n\n\n",
      i + 1, ime[i], prezime[i], danRodjenja[i], mesecRodjenja[i], godinaRodjenja[i]);
    
    }
    
    fclose(izlaz);
    
    
  return 0;
}
