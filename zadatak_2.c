
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

  ulaz = fopen("rodjendan.txt", "r"); // Otvaranje datoteke
  
  for ( i = 0; i < 10; ++i) {
    printf("\n\Citanje podataka za\n\t\t Osobu %d\n\n\n", i + 1);

    fscanf(ulaz, "%s", &ime[i]);

    fscanf(ulaz, "%s", &prezime[i]);

    fscanf(ulaz, "%d", &danRodjenja[i]);
   
    fscanf(ulaz, "%s", &mesecRodjenja[i]);
    
    fscanf(ulaz, "%d", &godinaRodjenja[i]);
    
    

    printf("Osoba %d:\n\t Ime: %s\n\t Prezime: %s\n\t Dan rodjenja: %d.\n\t Mesec rodjena: %s\n\t Godina rodjenja: %d\n\t\n\n\n",
      i + 1, ime[i], prezime[i], danRodjenja[i], mesecRodjenja[i], godinaRodjenja[i]);
    
    }
    
    fclose(izlaz);
    
    
  return 0;
}
