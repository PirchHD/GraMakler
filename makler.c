//14.12.2019/15.12.2019 Gra w maklera poczatkowo masz 100 $ i poprostu gra dopki chcesz :p
// Rozmiar konsoli ma byc 130x30 !! Musze znalezcz zamiennik windows.h na linuxie :P

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void Rysowanie();
void Wypisz();
void Rozmiar_Konsoli();
void Co_Robisz();

int x =50;
char tab[25][100];

int Dolar = 100;
int Bitcoin = 0;

int main(){
  while(x){
   system("clear");
   Rysowanie();
   Wypisz();
  // Co_Robisz();
   system("sleep 5");
   x--;
  }
return 0;
}

void Rysowanie(){
  for (int i = 0; i < 25; i++){
    for(int k = 0; k < 100; k++){
      tab[i][k] = ' ';
      if(k == 74 || k == 0 || k == 4){
         tab[i][k] = '|';
      }

      if(i == 24 || i == 21){
        tab[i][k] = '-';
      }

      if(k == 74 && i == 4){
        int i=4;
	for(k = 74; k < 100; k++){
	  tab[i][k] ='-';
	  if(k == 74 && i ==4){
	    tab[4][74] = '+';
	  }
	}
      }

      if(k == 74 && i == 9){
	int i =9;
        for(k =74; k < 100; k++){
          tab[i][k]='-';
	  if(k == 74 && i == 9){
	    tab[9][74] = '+';
	  }
	}
      }

      if( k == 74 && i == 12){
        int i = 12;
	for(k = 74;k < 100; k++){
	  tab[i][k] = '-';
          if(k == 74 && i == 12){
	    tab[12][74] = '+';
	  }
	}
      }

      if(k == 74 && i == 21){
        tab[i][k] ='+';
      }
    }  
  }
}

void Wypisz(){
  for(int i = 0; i < 25; i++){
    for(int k = 0; k < 100;k++){
      printf("%c",tab[i][k]);

      if (k == 75 && i ==0){
        printf("DANE: ");
      }

      if(k == 76 && i == 1){
        printf(" +Nazwa uzytkownika:");
      }

      if(k == 76 && i == 2){
        printf(" +Twoje saldo:");
      }

      if(k == 76 && i == 3){
        printf(" +Do miliona brakuje:");
      }

      // Wypisuje co chcesz zrobic
      if(k == 76 && i == 5){
        printf("CO CHCESZ ZROBIC ?? :D");
      }

      if(k == 76 && i == 6){
        printf(" 1. KUPUJ!! ");
      }

      if(k == 76 && i == 7){
        printf(" 2. SPRZEDAJ");
      }

      if(k == 76 && i == 8){
        printf(" 3. EXIT = Nie dales rady :D");
      }

      // ILe masz kaski $$ oraz wirtualny kasy o nazwie Bitcoin (mialem wymyslec jakis swoj ale za malo kreatywny jestem)
      if(k == 76 && i == 10){
        printf("Twoj portfel: ");
      }

      if(k == 76 && i == 11){
        printf("Dolarki: %d $  BTC: %d",Dolar,Bitcoin);
      }
   // Wybrano: 
      if(k ==76 && i == 22){
        printf("Wybrano: ");
      }

   }
  printf("\n");
  }
}

void Rozmiar_Konsoli(){
 // HANDLE okno  = GetStdHandle(STD_OUTPUT_HANDLE);
 // COORD size;
}


