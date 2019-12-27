//14.12.2019/15.12.2019/16.12.2019 Gra w maklera poczatkowo masz 500 $ i poprostu gra dopki chcesz :p
// Rozmiar konsoli ma byc 130x30 !! Musze znalezcz zamiennik windows.h na linuxie :P
// Jednak Gra bedzie konczyc sie az uzytkownik zdobedzie milion $$ bo mam fajny pomysl na ekran koncowy :P
// 18.12.1019 ogolnie gra jest skonczona w 90% ale chce jeszcze zrobic cos w stylu intra oraz mozliwosc dania własnego Nick. 
// A takze naprawic brzydkie bugi (wizualne)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <curses.h>

// Definuje kolory na linuxie nie musze używać osobnej biblioteki więc poprostu skorzystałem z tego

#define GREEN 32
#define BLACK 30
#define BLUE 34

//Koniec Definiowania Kolorow
void Rysowanie();  // Rysuje: | - i +
void Wypisz();    // wypisuje tablice oraz w danym punkcie wypisuje takie rzeczy jak np. DANE:
void Wykres();   
void ZapiszT1doT2();
void ZapiszT2doT1();
void Sprawdza();
void Czyszczenie(int ZapisaneI,int ZapisaneK);
void Kupuj();
void Sprzedaj();

//funkcje Koloru
void Reset(); // Zwykły Kolor
void Zielony();
void Niebieski();

void intro(); // Animacja napisu $$$ i MAKLER
void WypiszIntro();

char tab[25][100]; // Jakbym wczesniej pomyslal na temat działaniem programu jedna tablica by wystarczyła :D
char tab2[25][100];
char Tabintra[25][100];
char Nazwa[]="PirchHD";

int Dolar = 500;
int BTC = 0;
int WartoscMax = 200;
int WartoscMin = 0;
int WartoscZapis = 0;
int Brakuje = 1000000;
int timeStart;

//Zmienne do liczenia czasu (Time)
int Sekundy = -1; 
int Minuty = 0;
int Godziny = 0;

int Wybor = 0; // WYBOR CO ZROBISZ KUPISZ - 1 SPRZEDASZ- 2 EXIT - 3 NIC - DALEJ WYKONUJE FUNKCJE MAIN
int StartI=10; //  OD TEGO ZACZYNA RYSOWAC FUNKCJA
int StartK=3;  // OD TEGO ZACZYNA RYSOWAC FUNKCJA
int AktualnaCena = 150; // Aktualna cena 1 bit
int Saldo = 0; // Saldo jest liczone co cykl wykonujacy main

int main(){
  system("clear");
  intro();
  WypiszIntro();

  while(Dolar != 1000000){

   system("clear");
   
   WartoscZapis = WartoscMax; 
   WartoscMax = WartoscZapis;
  
   Reset();
   

   Rysowanie();
   Wykres();
   WartoscMin = WartoscMax;
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
    // Wypisuje 2
     Sprzedaj();
   }

   system("sleep 1");

  }
return 0;
}

void Rysowanie(){
  for (int i = 0; i < 24; i++){
    for(int k = 0; k < 96; k++){
  
     if(tab[i][k] != 'X'){
     tab[i][k] = ' ';
     }

     if(i != 23){
      if(k == 64 || k == 0 || k == 1){
         tab[i][k] = '|';
      }
     }

      if( i == 22 || i == 0 ){
        if(k != 0 && k!= 1)
        tab[i][k] = '-';
      }

      if(k == 64 && i == 5){
        int i=5;
	for(k = 64; k < 100; k++){
	  tab[i][k] ='-';
	  if(k == 64 && i ==5){
	    tab[5][64] = '+';
	  }
	}
      }

      if(k == 64 && i == 10){
	int i =10;
        for(k = 64; k < 100; k++){
          tab[i][k]='-';
	  if(k == 64 && i == 10){
	    tab[10][64] = '+';
	  }
	}
      }

      if( k == 64 && i == 13){
        int i = 13;
	for(k = 64;k < 100; k++){
	  tab[i][k] = '-';
          if(k == 64 && i == 13){
	    tab[13][64] = '+';
	  }
	}
      }

      if(k == 64 && i == 22){
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
    for(int k = 0; k < 96;k++){
      printf("%c",tab[i][k]);
      if(k == 65 && i ==1){
         printf("DANE: ");
      }

      if(k == 66 && i == 2){
	Niebieski();
        printf("+Nazwa uzytkownika: %s", Nazwa);
	Reset();
      }

      if(k == 66 && i == 3){
	Saldo = Dolar + (BTC * AktualnaCena);
	Niebieski();
        printf("+Twoje saldo: %d",Saldo);
	Reset();
      }

      if(k == 66 && i == 4){
	Niebieski();
	Brakuje = Brakuje - Saldo;
        printf("+Do miliona brakuje: %d", Brakuje);
	Reset();
      }

      // Wypisuje co chcesz zrobic
      if(k == 65 && i == 6){
        printf("CO CHCESZ ZROBIC ?? :D");
      }

      if(k == 66 && i == 7){
	Niebieski();
        printf("1. KUPUJ!! ");
	Reset();
      }

      if(k == 66 && i == 8){
	Niebieski();
        printf("2. SPRZEDAJ");
	Reset();
      }

      if(k == 66 && i == 9){
	Niebieski();
        printf("3. EXIT ");
	Reset();
      }

      // ILe masz kaski $$ oraz wirtualny kasy o nazwie Bitcoin (mialem wymyslec jakis swoj ale za malo kreatywny jestem)
      if(k == 65 && i == 11){
        printf("Twoj portfel: ");
      }

      if(k == 65 && i == 12){
	Zielony();
        printf("Dolarki: %d $ ",Dolar);
	Reset();
	printf("BTC: %d ",BTC);
	Reset();
      }
   // Wybrano: 
      if(k ==1 && i == 23){
        printf("Wybrano: ");
 	  scanf("%d", &Wybor);
	printf("Ladowanie...");
      }
     // Wartosc bitcoina
      if(i != 23 && i != 22 && i !=0){
        if(k == 0){
          printf("%5d", WartoscZapis);
	  WartoscZapis = WartoscZapis - 5;
	}
      }

      if(i == 0 && k == 0){
	  printf("$$$$$");
	 
      }

      if(i == 23 && k == 0){
        printf("TIME!|TIME|TIME|");
	Sekundy++;
	printf("Sekundy: %2d| ",Sekundy);
	if(Sekundy == 60){
          Minuty++;
	  Sekundy = 0;
	  printf("Minuta: %2d| ",Minuty);
	}
	else{
	  printf("Minuta: %2d| ",Minuty);
	}
	if(Minuty == 60){
	  Minuty = 0; 
	  Godziny++;
	  printf("Godzina: %2d|", Godziny);
	}
	else{
          printf("Godzina: %2d|",Godziny);
	}

	printf("TIME|TIME|TIME!|");

      }

      if(i == 22 && k == 0){
	  printf("$$$$$");
      }


   }
  printf("\n");
  }
}

void Wykres(){
	// Od k =3 do k 73
   int x = 0,dodaje=0; 
   tab[StartI][StartK] = 'X';
   x = rand()%101;
   if(x <= 0 ){
     dodaje = -1;
     	AktualnaCena = AktualnaCena + 5;
   }
   if(x > 1 && x <=2){
     dodaje = 1;
     AktualnaCena = AktualnaCena - 5;
   }
   if(x > 2){ 
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
  int k = 64;
  for(int i = 0; i < 22; i++){
    if(tab[i][k] == 'X'){
      Sekundy = -1;
      k = 3;
      Czyszczenie(i, k);
    }
  }

  int i = 22;
  for(int k = 3; k < 65; k++){
    if(tab[i][k]  == 'X'){
      i = 1;
      WartoscMax=WartoscMax - 105;
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

// Funkcje odpowiadajace za Kolor/Intro/Koniec gry

void Reset(){
printf("%c[%dm",0x1B,0);
}

void Zielony(){
printf("%c[%dm",0x1B,GREEN);
}

void Niebieski(){
  printf("%c[%dm",0x1B,BLUE);
}
// Koniec funkcji kolorow


//############### FUNKCJE ODPOWIADAJACE ZA INTRO ###################

void intro(){
  for(int i = 0; i < 25; i++){
    for(int k = 0; k < 100; k++){
      Tabintra[i][k] = '-';
      
      if(i == 12){
       Tabintra[i][k] = '*';
      }
      // T
      if(i == 13 && (k >= 36 && k <= 40)){
        for(int k = 36; k <= 40; k++){
	  Tabintra[i][k] = 'T';
	}
      }

      if(k == 38 && (i >=13 && i <= 17)){
        for(int i = 13; i <= 17; i++){
	  Tabintra[i][k] = 'T';
	}
      }
     // T
     
     //H
     if((k == 45 || k == 51) && (i >=13 && i <= 17)){
       for(int i = 13; i <= 17; i++){
         Tabintra[i][k] = 'H';
       }
     }
     
     if(i == 15 &&(k >= 45 && k <= 51)){
       for(int k = 45; k <= 51; k++){
         Tabintra[i][k] = 'H';
       }
     }
     //H
     
     //E
     if(k == 56 &&(i >= 13 && i <= 17)){
       for(int i = 13; i <= 17; i++){
         Tabintra[i][k] = 'E';
       }
     }

     if((i == 13 || i == 15 || i==17) && (k >= 56 && k <= 63)){
       for(int k = 56; k <= 63; k++){
         Tabintra[i][k] = 'E';
       }
     }
     //E

     // M
     if((k == 16 || k == 32) && (i >= 13 && i <= 23)){
       for(int i =13; i <= 23; i++){
         Tabintra[i][k] = 'M';
       }
     }

     if(i == 13 && k == 17){
         for(int j = 13; j < 20;j++){
           for(int h = 17; h < 24;h++){
             Tabintra[j][h] = 'M';
	   }
	 }
     }
     // M

      if(k == 0 || k == 33 || k==66 || k == 99){
        Tabintra[i][k] = '|';
      }

      if( i >= 0 && i <12 &&( (k == 49 || k == 50 ) || (k== 16 || k == 17) || (k == 82 || k == 83) ) ){
        Tabintra[i][k] = '$';
      }

    }
  }
}

void WypiszIntro(){
  for(int i = 0; i < 25; i++){
   // system("sleep 0.25");
    for(int k = 0; k <100; k++){
    
       if(Tabintra[i][k] == '-'){
         Niebieski();
       }

       if(Tabintra[i][k] == '$'){
         Zielony();
       }
       
      printf("%c",Tabintra[i][k]);
      Reset();
    }
    printf("\n");
  }
  scanf("%d",&Wybor);
}
//Koniec funkcji odpowiadajacych za intro

