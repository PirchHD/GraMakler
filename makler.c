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
void Kupuj();
void Sprzedaj();

char tab[25][100];
char tab2[25][100];
char Nazwa[]="PirchHD";

int Dolar = 500;
int BTC = 0;
int WartoscMax = 200;
int WartoscZapis = 0;
int Brakuje = 1000000;

int Wybor = 0;
int StartI=10;
int StartK=3;
int timeStart;
int AktualnaCena = 150;
int Saldo = 0;

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
     Kupuj();
   }
   if(Wybor == 2){
    // system("clear");	   
      // Wypisz();
     Sprzedaj();
   }
  if(Wybor == '\n'){
   main();
  }

   system("sleep 1");

  }
return 0;
}

void Rysowanie(){
  for (int i = 0; i < 24; i++){
    for(int k = 0; k < 100; k++){
     
     if(tab[i][k] != 'X'){
     tab[i][k] = ' ';
     }

     if(i != 23){
      if(k == 75 || k == 0 || k == 1){
         tab[i][k] = '|';
      }
     }

      if( i == 22 || i == 0 ){
        if(k != 0 && k!= 1)
        tab[i][k] = '-';
      }

      if(k == 75 && i == 5){
        int i=5;
	for(k = 75; k < 100; k++){
	  tab[i][k] ='-';
	  if(k == 75 && i ==5){
	    tab[5][75] = '+';
	  }
	}
      }

      if(k == 75 && i == 10){
	int i =10;
        for(k =75; k < 100; k++){
          tab[i][k]='-';
	  if(k == 75 && i == 10){
	    tab[10][75] = '+';
	  }
	}
      }

      if( k == 75 && i == 13){
        int i = 13;
	for(k = 75;k < 100; k++){
	  tab[i][k] = '-';
          if(k == 75 && i == 13){
	    tab[13][75] = '+';
	  }
	}
      }

      if(k == 75 && i == 22){
        tab[i][k] ='+';
      }

      if(k == 0 && i == 23){
        tab[i][k] = '|';
      }

    }  
  }
}

void Wypisz(){
  for(int i = 0; i < 24; i++){
    for(int k = 0; k < 100;k++){
      printf("%c",tab[i][k]);
      if(k == 75 && i ==1){
         printf("DANE: ");
      }

      if(k == 76 && i == 2){
        printf("+Nazwa uzytkownika: %s", Nazwa);
      }

      if(k == 76 && i == 3){
	Saldo = Dolar + (BTC * AktualnaCena);
        printf("+Twoje saldo: %d",Saldo);
      }

      if(k == 76 && i == 4){
	Brakuje = Brakuje - Saldo;
        printf("+Do miliona brakuje: %d", Brakuje);
      }

      // Wypisuje co chcesz zrobic
      if(k == 75 && i == 6){
        printf("CO CHCESZ ZROBIC ?? :D");
      }

      if(k == 76 && i == 7){
        printf("1. KUPUJ!! ");
      }

      if(k == 76 && i == 8){
        printf("2. SPRZEDAJ");
      }

      if(k == 76 && i == 9){
        printf("3. EXIT ");
      }

      // ILe masz kaski $$ oraz wirtualny kasy o nazwie Bitcoin (mialem wymyslec jakis swoj ale za malo kreatywny jestem)
      if(k == 76 && i == 11){
        printf("Twoj portfel: ");
      }

      if(k == 76 && i == 12){
        printf("Dolarki: %d $  BTC: %d",Dolar,BTC);
      }
   // Wybrano: 
      if(k ==2 && i == 23){
        printf("Wybrano: ");
	scanf("%d", &Wybor);
	//if((clock() - timeStart) / CLOCKS_PER_SEC >= 10)
	printf("Ladowanie...");
      }
     // Wartosc bitcoina
      if(i != 23 && i != 22 && i !=0){
        if(k == 0){
          printf("%d", WartoscZapis);
	  WartoscZapis = WartoscZapis - 5;
	}
      }

      if(i == 0 && k == 0){
        printf("$$$");
      }

      if(i == 23 && k == 0){
        printf("TIME|");
	for(int Sekundy = 1; Sekundy < 51; Sekundy= Sekundy +2){
          printf("%d|",Sekundy);
	}
	printf("50|");
      }

      if(i == 22 && k == 0){
        printf("$$$");
      }


   }
   // WartoscZapis = WartoscZapis-5;
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
     	AktualnaCena = AktualnaCena + 5;
   }
   if(x > 90 && x <=95){
     dodaje = 1;
     AktualnaCena = AktualnaCena - 5;
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

  int i = 22;
  for(int k = 3; k < 75; k++){
    if(tab[i][k]  == 'X'){
      i = 1;
      Czyszczenie(i, k);
    }

    int i = 0;
    if(tab[i][k] == 'X'){ // Naprawic ten if !! gora 
      i = 21;
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

void Kupuj(){
    if(Dolar >= AktualnaCena){
       BTC++;
      Dolar = Dolar - AktualnaCena;
   }
}

void Sprzedaj(){
  if(BTC > 0){
    BTC--;
    Dolar = Dolar + AktualnaCena;
  }
}
