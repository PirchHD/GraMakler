/*
 Dokońćzyć intro
 Zrobić koniec (KIedy wygrywasz)
 Zrobic animacj gdy wychodzisz/przegrywasz
 Zrobic system zapisu rankingu i by byl pokazany na koncu [Przez pliki tekstowe]
 Znalezc funkcje non-blocking by wykres dzialal cały czas : D.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <ncurses.h>

// Definuje kolory na linuxie nie musze używać osobnej biblioteki więc poprostu skorzystałem z tego

#define GREEN 32
#define BLACK 30
#define BLUE 34
#define YELLOW 33

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
void Zolty();


void intro(); // Animacja napisu $$$ i MAKLER
void WypiszIntro();

char tab[25][100]; // Jakbym wczesniej pomyslal na temat działaniem programu jedna tablica by wystarczyła :D
char tab2[25][100];
char Tabintra[28][100];
char Nazwa[]="PirchHD";

int Dolar = 500;
int BTC = 0;
int WartoscMax = 200;
int WartoscMin = 0;
int WartoscZapis = 0;
int Brakuje = 1000000;
int ZapiszBrakuje = 1000000;

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

  puts("\x1B[8;28;100t"); // kod kotrolny xterm-a; \x1B-ESC 

  system("clear");

  intro();
  WypiszIntro();

  while(Saldo != 1000000){
    puts("\x1B[8;25;140t");
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

   Brakuje = ZapiszBrakuje;
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
	Brakuje = ZapiszBrakuje - Saldo;
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
   if(x <= 60 ){
     dodaje = -1;
     	AktualnaCena = AktualnaCena + 5;
   }
   if(x > 60 && x <=90){
     dodaje = 1;
     AktualnaCena = AktualnaCena - 5;
   }
   if(x > 90){ 
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
    if(tab[i][k] == 'X'){ 
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

void Zolty(){
  printf("%c[%dm",0x1B,YELLOW);
}

// Koniec funkcji kolorow


//############### FUNKCJE ODPOWIADAJACE ZA INTRO ###################

void intro(){
  for(int i = 0; i < 28; i++){
    for(int k = 0; k < 100; k++){
      Tabintra[i][k] =  '-';
      
      // T
      if(i == 16 && (k >= 36 && k <= 40)){
        for(int k = 36; k <= 40; k++){
	  Tabintra[i][k] = 'T';
	}
      }

      if(k == 38 && (i >=16 && i <= 20)){
        for(int i = 16; i <= 20; i++){
	  Tabintra[i][k] = 'T';
	}
      }
     // T
     
     //H
     if((k == 45 || k == 51) && (i >=16 && i <= 20)){
       for(int i = 16; i <= 20; i++){
         Tabintra[i][k] = 'H';
       }
     }
     
     if(i == 18 &&(k >= 45 && k <= 51)){
       for(int k = 45; k <= 51; k++){
         Tabintra[i][k] = 'H';
       }
     }
     //H
     
     //E
     if(k == 56 &&(i >= 16 && i <= 20)){
       for(int i = 16; i <= 20; i++){
         Tabintra[i][k] = 'E';
       }
     }

     if((i == 16 || i == 18 || i==20) && (k >= 56 && k <= 63)){
       for(int k = 56; k <= 63; k++){
         Tabintra[i][k] = 'E';
       }
     }
     //E

     // M
     if((k == 20 || k == 32) && (i >= 21 && i <= 26)){
       for(int i =21; i <= 26; i++){
         Tabintra[i][k] = 'M';
       }
     }

     if(i == 25){
       int j = 25;
       for(int h = 26; h > 20; h--){
         Tabintra[j][h] = 'M';
	 j--;
       }

       j = 25;
       for(int h = 26; h < 32; h++){
         Tabintra[j][h] = 'M';
	 j--;
       }
     }
     // M
     
     //A
     if(k==33 && i == 27){
       int j = 26;
       for(int h = 35; h < 40;h++){
         Tabintra[j][h] = 'A';
	 j--;
       }
      j = 26;

      for(int h = 43; h >= 40;h--){
        Tabintra[j][h] = 'A';
	j--;
      }
     }

     if((k >= 36 && k<=41) && i == 25 ){
         Tabintra[i][k] = 'A';
     }
     //A

     //K
     if(k == 45 && i <= 26 && i >= 22 ){
         Tabintra[i][k] = 'K';
     }

     if(i == 25 && k == 46){
       int j = 25;
       for(int h = 45; h < 49;h++){
         Tabintra[j][h] = 'K';
	 j--;
       }
     }

     if(i == 26 && k == 50){
       int j = 26;
       for(int h = 50; h > 46;h--){
         Tabintra[j][h] = 'K';
	 j--;
       }
     }
     //K
     
     //L
       if(i >= 21 && i <= 26 && k == 52 ){
         Tabintra[i][k] = 'L';
       }

       if(i == 26 && k>= 53 && k <= 57){
         Tabintra[i][k] = 'L';
       }

     //L
     
     //E
       if(i>= 22 && i <= 26 && k == 59){
         Tabintra[i][k] = 'E';
       }
       if((i == 22 || i ==24 || i == 26) && k >= 59 && k <= 64){
         Tabintra[i][k] = 'E';
       }

     //E
     
     //R
       if(k == 67 && i >= 20 && i <= 26){
         Tabintra[i][k] = 'R';
       }

      
	 int j = 20;
	 for(int h = 68; h <= 73;h++){
           Tabintra[j][h] = 'R';
	   Tabintra[j][h+1] = 'R';
	   h++;
	   h++;
	   j++;
	 }

       j = 23;
       for(int h = 68; h <= 73;h++){
         Tabintra[j][h] = 'R';
         Tabintra[j][h+1] = 'R';
         h++;
         h++;
         j--;
       }

       if(i == 27 && k == 73){
         int j = 26;
	 for(int h = 73; h > 69;h--){
	   Tabintra[j][h] = 'R';
	   j--;
	 }
       }
     //R

      // $$$$$$$$$$$
      if( i >= 0 && i <15 &&( (k == 49 || k == 50 ) || (k== 16 || k == 17) || (k == 82 || k == 83) ) ){
        Tabintra[i][k] = '$';
      }

      if( (i == 1 || i == 7 || i == 13 ) && ( (k >= 51 && k <= 52) || (k >= 47 && k <= 48) || (k >= 18 && k <= 19) || (k >= 14 && k <= 15) || (k >= 84 && k <= 85) || (k >= 80 && k <= 81) ) ){
        Tabintra[i][k] = '$';
      }

      if( i == 6  && ( (k >= 45 && k <= 46) || (k >= 12 && k <= 13) || (k >= 78 && k <= 79) ) ){
        Tabintra[i][k] = '$';
      }

     if( i == 8 && ( (k >= 53 && k <= 54) || (k >= 20 && k <= 21) || (k >= 86 && k <= 87) ) ){
       Tabintra[i][k] = '$';
     }

     if( ( i == 2 || i == 12)  && ( (k>= 53 && k <= 54) || (k >= 45 && k <= 46) ||(k >= 12 && k <= 13) || (k >= 20 && k <= 21) || (k >= 86 && k <= 87) || (k >= 78 && k <= 79) )){
       Tabintra[i][k] = '$';
     }

     if( ( (i >= 3 && i <= 5) || (i >= 9 && i <= 11) ) && ( (k >= 55 && k <= 56) || (k >= 43 && k <= 44 ) || (k>= 22 && k <= 23) || (k >= 10 && k <= 11) || (k >= 88 && k <= 89) || (k >= 76 && k <= 77))){
       Tabintra[i][k] = '$';
     }

      //$$$$$$$$$$$$$
    }
  }
}

void WypiszIntro(){
  for(int i = 0; i < 28; i++){
    system("sleep 0.01");
    for(int k = 0; k <100; k++){
    
       if(Tabintra[i][k] == '-'){
         Niebieski();
       }

       if(Tabintra[i][k] == '$'){
         Zielony();
       }

       if(Tabintra[i][k] != '$' && Tabintra[i][k] != '-'){
         Zolty();
       }
       
      printf("%c",Tabintra[i][k]);
      Reset();
    }
    printf("\n");
  }
}
//Koniec funkcji odpowiadajacych za intro

