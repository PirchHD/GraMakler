//14.12.2019/15.12.2019/16.12.2019 Gra w maklera poczatkowo masz 500 $ i poprostu gra dopki chcesz :p
// Rozmiar konsoli ma byc 130x30 !! Musze znalezcz zamiennik windows.h na linuxie :P
// Jednak Gra bedzie konczyc sie az uzytkownik zdobedzie milion $$ bo mam fajny pomysl na ekran koncowy :P
// 18.12.1019 ogolnie gra jest skonczona w 90% ale chce jeszcze zrobic cos w stylu intra oraz mozliwosc dania własnego Nick. 
// A takze naprawic brzydkie bugi (wizualne)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void Rysowanie();
void Wypisz();
void Wykres();
void ZapiszT1doT2();
void ZapiszT2doT1();
void Sprawdza();
void Czyszczenie(int ZapisaneI,int ZapisaneK);

char tab[25][100];
char tab2[25][100];
char Nazwa[]="PirchHD";

int Dolar = 500;
int Bitcoin = 0;
int WartoscMax = 200;
int WartoscZapis = 0;
int Brakuje = 1000000;

int Wybor = 0;
int StartI=10;
int StartK=3;
int timeStart;

int main(){
  while(Dolar != 1000000){
  // Brakuje = Brakuje - Dolar;
   system("clear");
   
   WartoscZapis = WartoscMax; // Działa ale brzydko 
   WartoscMax = WartoscZapis;

   Rysowanie();
   Wykres();
   Sprawdza();
   ZapiszT1doT2();
   Wypisz();
   ZapiszT2doT1();

   
   
  if(Wybor == 3){
     // WYPISUJE 3 
     return 0;
   }
   if(Wybor == 1){
     //Wypisuje 1
     //Kupuje btc
   }
   if(Wybor == 2){
    // system("clear");	   
      // Wypisz();
     //Sprzedaje btc
   }
  if(Wybor == '\n'){
   main();
  }

   system("sleep 1");

  }
return 0;
}

void Rysowanie(){
  for (int i = 0; i < 22; i++){
    for(int k = 0; k < 100; k++){
     
     if(tab[i][k] != 'X'){
     tab[i][k] = ' ';
     }
     
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
        printf("+Nazwa uzytkownika: %s", Nazwa);
      }

      if(k == 76 && i == 2){
        printf("+Twoje saldo: %d",Dolar);
      }

      if(k == 76 && i == 3){
        printf("+Do miliona brakuje: %d", Brakuje);
      }

      // Wypisuje co chcesz zrobic
      if(k == 75 && i == 5){
        printf("CO CHCESZ ZROBIC ?? :D");
      }

      if(k == 76 && i == 6){
        printf("1. KUPUJ!! ");
      }

      if(k == 76 && i == 7){
        printf("2. SPRZEDAJ");
      }

      if(k == 76 && i == 8){
        printf("3. EXIT ");
      }

      // ILe masz kaski $$ oraz wirtualny kasy o nazwie Bitcoin (mialem wymyslec jakis swoj ale za malo kreatywny jestem)
      if(k == 76 && i == 10){
        printf("Twoj portfel: ");
      }

      if(k == 76 && i == 11){
        printf("Dolarki: %d $  BTC: %d",Dolar,Bitcoin);
      }
   // Wybrano: 
      if(k ==2 && i == 22){
        printf("Wybrano: ");
	scanf("%d", &Wybor);
	//if((clock() - timeStart) / CLOCKS_PER_SEC >= 10)
	printf("Ladowanie...");
      }
     // Wartosc bitcoina
      if(i != 22 && i != 21){
        if(k == 0){
          printf("%d", WartoscZapis);
	}
      }
      if(i == 22 && k == 0){
        printf("|$$$|");
      }
      if(i == 22 && k ==1){
	for(int Sekundy = 0; Sekundy < 26; Sekundy++){
          printf("%d|",Sekundy);
	}
	printf("TIME|");
      }

      if(i == 21 && k == 0){
        printf("---");
      }


   }
    WartoscZapis = WartoscZapis-5;
  printf("\n");
  }
}

void Wykres(){
	// Od k =3 do k 73
   int x = 0,dodaje=0; 
   tab[StartI][StartK] = 'X';
   x = rand()%101;
   if(x <= 90 ){
     dodaje = -1;
   }
   if(x > 90 && x <=95){
     dodaje = 1;
   }
   if(x > 95){ 
     dodaje = 0;
   }
  StartI = StartI + dodaje;
   StartK++;
   tab[StartI][StartK] = 'X';
}

void ZapiszT1doT2(){
  for(int i = 0; i < 25; i ++){
    for(int k = 0; k < 100; k++){
      tab2[i][k] = tab[i][k];
    }
  }
}

void ZapiszT2doT1(){
  for(int i = 0; i < 25; i ++){
    for(int k = 0; k < 100; k++){
      tab[i][k] = tab2[i][k];
    }
  }
}

void Sprawdza(){
  int k = 73;
  for(int i = 0; i < 22; i++){
    if(tab[i][k] == 'X'){
      k = 3;
      Czyszczenie(i, k);
    }
  }

  int i = 21;

  for(int k = 3; k < 74; k++){
    if(tab[i][k]  == 'X'){
      i = 1;
      Czyszczenie(i, k);
    }

    int i = 0;
    if(tab[i][k] == 'X'){ // Naprawic ten if !! gora 
      i = 20;
     WartoscMax = WartoscMax + 105;
     Czyszczenie(i, k);
    }
  }
}

void Czyszczenie(int ZapisaneI, int ZapisaneK){
  for(int i = 0; i < 25; i ++){
    for(int k = 0; k < 100; k ++){
      tab[i][k] = ' ';
    }
  }
  StartI=ZapisaneI;
  StartK=ZapisaneK;
  tab[ZapisaneI][ZapisaneK] = 'X';
  tab2[ZapisaneI][ZapisaneK] = 'X';
  WartoscZapis = WartoscMax;
  Rysowanie();
}
