//14.12.2019/15.12.2019 Gra w maklera poczatkowo masz 500 $ i poprostu gra dopki chcesz :p
// Rozmiar konsoli ma byc 130x30 !! Musze znalezcz zamiennik windows.h na linuxie :P
// Jednak Gra bedzie konczyc sie az uzytkownik zdobedzie milion $$ bo mam fajny pomysl na ekran koncowy :P

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void Rysowanie();
void Wypisz();
void Co_Robisz();
void Rysowanie1();
void Wypisz2();
void Wykres();


int Cykl = 10;
char tab[25][100];

int Dolar = 500;
int Bitcoin = 0;
int WartoscMax = 200;

int Wybor = 0;

int main(){
  while(Cykl){
   WartoscMax=200;
   system("clear");
   Rysowanie();
   Wykres();
   Wypisz();
  // Co_Robisz();
   system("sleep 1");
   Cykl--;
  }
return 0;
}

void Rysowanie(){
  for (int i = 0; i < 23; i++){
    for(int k = 0; k < 100; k++){
      tab[i][k] = ' ';
      if(k == 74 || k == 0 || k == 1){
         tab[i][k] = '|';
      }

      if( i == 21 ){
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
  for(int i = 0; i < 23; i++){
    for(int k = 0; k < 100;k++){
      printf("%c",tab[i][k]);

      if(k == 75 && i ==0){
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
        printf(" 3. EXIT ");
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
	scanf("%d", &Wybor);
      }
     // Wartosc bitcoina
      if(i != 22 && i != 21){
        if(k == 0){
          printf("%d", WartoscMax);
	}
      }
      if(i == 22 && k == 0){
        printf("$$$");
      }

      if(i == 21 && k == 0){
        printf("---");
      }
   }
    WartoscMax = WartoscMax-5;
  printf("\n");
  }
}

void Wykres(){
	// Od k =3 do k 73
   int i=10, k=3, x = 0,dodaje=0; 
   tab[i][k] = 'X';
   x = rand()%101;
   if(x <= 30 ){
     dodaje = -1;
   }
   if(x > 30 && x <=80){
     dodaje = 1;
   }
   if(x > 80){
     dodaje = 0;
   }
  i = i + dodaje;
   k++;
   tab[i][k] = 'X';
}
