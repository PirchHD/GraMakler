/*
 Zrobic animacj gdy wychodzisz/przegrywasz
 Zrobic system zapisu rankingu i by byl pokazany na koncu [Przez pliki tekstowe]
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <poll.h>

void Rysowanie(char tab[25][100],char Wybor[1]);  // Rysuje: | - i +
void Wypisz(char tab[25][100], int *Sekundy, int *Minuty, int *Godziny, char Nazwa[10], char Wybor[1], int *Saldo, int *AktualnaCena, int *Dolar, int *BTC, int *Brakuje, int *ZapiszBrakuje, int *WartoscZapis); 
void Wykres(char tab[25][100],int *Sekundy, char *Tryb, int *Kierunek, int *AktualnaCena, int *StartI, int *StartK);   
void Sprawdza(char tab[25][100],int *Sekundy,char Wybor[1], int *Kierunek, int *WartoscMax, int *WartoscZapis, int *StartI, int *StartK);
void Czyszczenie(int ZapisaneI,int ZapisaneK,char tab[25][100],char Wybor[1], int *Kierunek, int *WartoscMax, int *WartoscZapis, int *StartI, int *StartK);
void Kupuj(int *AktualnaCena, int *Dolar, int *BTC);
void Sprzedaj(int *AktualnaCena, int *Dolar, int *BTC);

//Wypisuje 1/2/
void Wypisz_1(char tab[25][100]);
void Wypisz_2(char tab[25][100]);

//funkcje Koloru
void Reset(); // ZwykĹ‚y Kolor
void Zielony();
void Niebieski();
void Zolty();
void Czerwony();

void Tutorial();

void Ustawienia_Prof(char Nazwa[10], char *Mode_Bot,char *Tryb,int *Dolar);
void Tryby(char *Tryb,int *Dolar);

void intro(char Tabintra[28][100]); // Animacja napisu $$$ i MAKLER
void WypiszIntro(char Tabintra[28][100]);

void Wygrana(char TabWygrana[28][100]);
void lose(char Tablose[28][100]);


//!!!!!!!!!!!!!!FUNKCJA MAIN:
int main(){

  puts("\x1B[8;28;100t"); // kod kotrolny xterm-a; \x1B-ESC 

  system("clear");

  char TabMain[28][100];
  char tab[25][100];

  int StartI = 10;
  int StartK = 3;

  int Dolar = 500;
  int BTC = 0;
  int WartoscMax = 200;
  int WartoscMin = 0;
  int WartoscZapis = 0;
  int Brakuje = 1000000;
  int ZapiszBrakuje = 1000000;

  int AktualnaCena = 165;
  int Saldo;
  int Kierunek = 1;

  char Nazwa[10], Mode_Bot,Tryb,Wybor[1];

  int Sekundy = 0, Minuty = 0, Godziny = 0;

  intro(TabMain);
  WypiszIntro(TabMain);

  system("clear");

  Tutorial();

  system("clear");
  puts("\x1B[8;7;76"); // ncourses.h :D

  Ustawienia_Prof(Nazwa, &Mode_Bot, &Tryb, &Dolar);

  while(Saldo <= 1000000){
   puts("\x1B[8;25;140t"); //Rozmiar okna 25 x 140
   // Zapisuje Aktualne dane do Uzytkownik.txt
     FILE *plik;
     if((plik = fopen("Uzytkownik.txt","w")) == NULL){
       printf("BĹ‚ad pliku"); exit(2);
     }

     fprintf(plik,"%s",Nazwa);
     fprintf(plik, " Wynik: %2d/%2d/%2d",Sekundy,Minuty,Godziny);
     fprintf(plik," Saldo: %d ",Saldo);
     fclose(plik);
   // Koniec funkcji plikowych
   system("clear");
   
   WartoscZapis = WartoscMax; 
   WartoscMax = WartoscZapis;
  
   Reset();

   Rysowanie(tab,Wybor);
   Wykres(tab, &Sekundy, &Tryb, &Kierunek, &AktualnaCena, &StartI, &StartK);
   WartoscMin = WartoscMax;
   Sprawdza(tab, &Sekundy, Wybor, &Kierunek, &WartoscMax, &WartoscZapis, &StartI, &StartK);
   Wypisz(tab, &Sekundy, &Minuty, &Godziny, Nazwa, Wybor, &Saldo, &AktualnaCena, &Dolar, &BTC, &Brakuje, &ZapiszBrakuje,&WartoscZapis);
   Brakuje = ZapiszBrakuje;

   //Sprawdza czy przegrales
   if(Saldo <= 0 ){
     lose(TabMain);  
   }

  }

  system("clear");

  puts("\x1B[8;29;100t");

  system("clear");

  Wygrana(TabMain);

  //Sprawdza czy jestes w top 3
  //Wypisuje Ranking 3 najlepsze wyniki 

return 0;
}

void Rysowanie(char tab[25][100],char Wybor[1]){
  for (int i = 0; i < 24; i++){
    for(int k = 0; k < 96; k++){
      
      if(Wybor[0] == '1'){
        Wypisz_1(tab);
      }
      if(Wybor[0] == '2'){
        Wypisz_2(tab);
      }

     if(tab[i][k] != '/' && tab[i][k] != '_' && tab[i][k] != '\\'){
       tab[i][k] = ' ';
     }

      if(k == 64 || k == 0 || k == 1){
         tab[i][k] = '|';
      }

      if( i == 0 ){
        if(k != 0 && k!= 1)
        tab[i][k] = '-';
      }

      if(i == 22){
        if(k >= 2 && k <= 64){
	  tab[i][k] = '-';
	}
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

void Wypisz_1(char tab[25][100]){
 for(int i = 14; i < 24; i ++){
   for(int k = 65;k < 96; k++){
     if( (i == 21 || i == 22) && (k >= 74 && k <= 85 )){
       tab[i][k] = '1';
     }
    if((k >= 79 && k <= 81) && i != 14){
      tab[i][k] = '1';
     }
      tab[16][76] = '1';
      tab[16][77] = '1';
      tab[16][78] = '1';

      tab[17][75] = '1';
      tab[17][76] = '1';
      tab[17][74] = '1';
   }
 }
}

void Wypisz_2(char tab[25][100]){
  for(int i = 14; i < 24; i++){
    for(int k = 65; k < 96; k ++){

      if( (i == 21 || i == 22) && (k >= 74 && k <= 85) ){
        tab[i][k] = '2';
      }

      if(i == 20 && k == 74){
	int j = 20;
        for(int k = 74; k <=83;k++){
	  tab[j][k] = '2';
	  tab[j][k+1] = '2';
	  tab[j][k+2] = '2';
	  k++;
	  j--;
	}
      }

       tab[16][74] = '2';
       tab[16][75] = '2';
       tab[16][76] = '2';

       if(i == 15 && (k== 75 || k == 81)){
         tab[i][k] = '2';
	 tab[i][k+1] = '2';
	 tab[i][k+2] = '2';
       }

       if(i==14 && k >= 76 && k <= 81){
         tab[i][k] = '2';
       }
     
    }
  }
}

void Wypisz(char tab[25][100],int *Sekundy,int *Minuty,int *Godziny, char Nazwa[10],char Wybor[1], int *Saldo, int *AktualnaCena,int *Dolar, int *BTC, int *Brakuje, int *ZapiszBrakuje, int *WartoscZapis){
  for(int i = 0; i < 24; i++){
    for(int k = 0; k < 96;k++){
      if(tab[i][k] == '\\'){
        Zielony();
      }
      if(tab[i][k] == '_'){
        Zolty();
      }
      if(tab[i][k] == '/'){
        Czerwony();
      }
      printf("%c",tab[i][k]);
      
      Reset();

      if(k == 65 && i ==1){
         printf("DANE: ");
      }

      if(k == 66 && i == 2){
	Niebieski();
        printf("+Nazwa uzytkownika: %s", Nazwa);
	Reset();
      }

      if(k == 66 && i == 3){
	*Saldo = *Dolar + (*BTC * (*AktualnaCena) );
	Niebieski();
        printf("+Twoje saldo: %d",*Saldo);
	Reset();
      }

      if(k == 66 && i == 4){
	Niebieski();
	*Brakuje = *ZapiszBrakuje - *Saldo;
        printf("+Do miliona brakuje: %d", *Brakuje);
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
        printf("Dolarki: %d $ ", *Dolar);
	Reset();
	printf("BTC: %d ", *BTC);
	Reset();
      }
   // Wybrano: 
      if(k == 0 && i == 23){
	int s = 1;
	Wybor[0] = '0';
	while(s){
	  struct pollfd mypoll = {STDIN_FILENO,POLLIN|POLLPRI};
	  if(poll(&mypoll,1,1000)){
	    scanf("%1s",Wybor);
	    if(Wybor[0] == '1'){
	      s = 0;
	      Kupuj(AktualnaCena, Dolar, BTC);
	    }
	    if(Wybor[0] == '2'){
	      s = 0;
	      Sprzedaj(AktualnaCena, Dolar, BTC);
	    }
	    if(Wybor[0] == '3'){
	      exit(1);
	    }
	    else s = 0;
	  }
	  else{
	    s = 0;
	  }
	  s = 0;
	}
      }
     // Wartosc bitcoina
      if(i != 23 && i != 22 && i !=0){
        if(k == 0){
          printf("%5d", *WartoscZapis);
	  *WartoscZapis = *WartoscZapis - 5;
	}
      }

      if(i == 0 && k == 0){
	  printf("$$$$$");
	 
      }

      if(i == 22 && k == 95){
	 printf("\n");
	 printf("|TIME!|TIME|TIME|");
	*Sekundy = *Sekundy + 1;
	printf("Sekundy: %2d| ",*Sekundy);
	if(*Sekundy >= 60){
          *Minuty = *Minuty + 1;
	  *Sekundy = 0;
	  printf("Minuta: %2d| ",*Minuty);
	}
	else{
	  printf("Minuta: %2d| ",*Minuty);
	}
	if(*Minuty >= 60){
	  *Minuty = 0; 
	  *Godziny = *Godziny + 1;
	  printf("Godzina: %2d|", *Godziny);
	}
	else{
          printf("Godzina: %2d|",*Godziny);
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

void Wykres(char tab[25][100],int *Sekundy, char *Tryb, int *Kierunek, int *AktualnaCena, int *StartI, int *StartK){                                           
	// Od k =3 do k 73   
   int x,dodaje,PoprzedniKierunek;
   
  PoprzedniKierunek = *Kierunek;

   x = rand()%101;
   if( *Tryb == 'n' || *Tryb == 'N'){
     if(x <=50 ){
       dodaje = -1;
       *AktualnaCena = *AktualnaCena + 5;
       *Kierunek = 1;
     }
     if(x > 50 && x <=90){
       dodaje = 1;
       *AktualnaCena = *AktualnaCena - 5;
       *Kierunek = 2;
     }
     if(x > 90){ 
       dodaje = 0;
       *Kierunek  = 3;
     }
   }
   if(*Tryb == 'H' || *Tryb == 'h'){
     if(x <= 45){
       dodaje = -1;
       *AktualnaCena = *AktualnaCena + 5;
       *Kierunek = 1;
     }
     if(x > 45 && x <= 75){
       dodaje = 1;
       *AktualnaCena = *AktualnaCena - 5;
       *Kierunek = 2;
     }
     if(x > 75){
       dodaje = 0;
       *Kierunek = 3;
     }
   }
   else{
     if(x <= 60){
       dodaje = -1;
       *AktualnaCena = *AktualnaCena +5;
       *Kierunek = 1;
     }
     if(x > 60 && x <= 90){
       dodaje = 1;
       *AktualnaCena = *AktualnaCena - 5;
       *Kierunek = 2;
     }
     if(x > 90){
       dodaje = 0;
       *Kierunek = 3;
     }
   }

   *StartI = *StartI + dodaje;
   *StartK = *StartK + 1;
// 1 - /   2 - \     3- _      
     if(*Kierunek == 1){
       if(PoprzedniKierunek == 2){ 
	*StartI = *StartI + 1;
        tab[*StartI][*StartK] = '/';
	//system("sleep 1");  Prawie bylo by super :) 
	*Sekundy = *Sekundy + 1;
	*StartI = *StartI - 1;
        *StartK = *StartK + 1; 
	tab[*StartI][*StartK] = '/';
       }
       if(PoprzedniKierunek == 3){
        *StartI = *StartI + 1;
        tab[*StartI][*StartK] = '/';
        *StartI = *StartI - 1;
	*Sekundy = *Sekundy + 1;
        *StartK = *StartK + 1;
        tab[*StartI][*StartK] = '/';	
       }
       else{
         tab[*StartI][*StartK] = '/';
       }
     }
     if(*Kierunek == 2){ 
       if(PoprzedniKierunek == 1){
	 *StartI = *StartI - 1;
         tab[*StartI][*StartK] = '\\';
	 *Sekundy = *Sekundy + 1;
	 *StartI = *StartI + 1;
	 *StartK = *StartK + 1;
	 tab[*StartI][*StartK] = '\\';
       }
       else{
         tab[*StartI][*StartK] = '\\';
       }
     }
     if(*Kierunek == 3){ 
       if(PoprzedniKierunek == 1){
         *StartI = *StartI - 1;
	 tab[*StartI][*StartK] = '_';
       }
       else{
         tab[*StartI][*StartK] = '_';
       }
     }
  
}

void Sprawdza(char tab[25][100],int *Sekundy,char Wybor[1], int *Kierunek, int *WartoscMax, int *WartoscZapis, int *StartI, int *StartK){
  int k = 64;
  for(int i = 0; i < 22; i++){
    if(tab[i][k] == '/' || tab[i][k] == '\\' || tab[i][k] =='_'){
      *Sekundy = -1;
      k = 3;
      Czyszczenie(i, k, tab, Wybor, Kierunek, WartoscMax, WartoscZapis, StartI, StartK);
    }
  }

  int i = 22;
  for(int k = 3; k < 65; k++){
    if(tab[i][k] == '/' || tab[i][k] == '\\' || tab[i][k] == '_'){
      i = 1;
      *WartoscMax = *WartoscMax - 105;
      Czyszczenie(i, k, tab, Wybor, Kierunek, WartoscMax, WartoscZapis, StartI, StartK);
    }

    int i = 0;
    if( tab[i][k] == '/' || tab[i][k] == '\\' || tab[i][k] == '_'){ 
      i = 21;
     *WartoscMax = *WartoscMax + 105;
     Czyszczenie(i, k, tab, Wybor, Kierunek, WartoscMax, WartoscZapis, StartI, StartK);
    }
  }
}

void Czyszczenie(int ZapisaneI, int ZapisaneK, char tab[25][100], char Wybor[1], int *Kierunek, int *WartoscMax, int *WartoscZapis, int *StartI, int *StartK){
  for(int i = 0; i < 25; i ++){
    for(int k = 0; k < 100; k ++){
      tab[i][k] = ' ';
    }
  }

  *StartI=ZapisaneI;
  *StartK=ZapisaneK;
  
  if(*Kierunek == 1)tab[ZapisaneI][ZapisaneK] = '/';
  if(*Kierunek == 2)tab[ZapisaneI][ZapisaneK] = '\\';
  if(*Kierunek == 3)tab[ZapisaneI][ZapisaneK] = '_';
  
  *WartoscZapis = *WartoscMax;
  Rysowanie(tab,Wybor);
}

void Kupuj(int *AktualnaCena, int *Dolar, int *BTC){
    if(*Dolar >= *AktualnaCena){
      *BTC = *BTC + 1;
      *Dolar = *Dolar - *AktualnaCena;
   }
}

void Sprzedaj(int *AktualnaCena, int *Dolar, int *BTC){
  if(*BTC > 0){
    *BTC = *BTC - 1;
    *Dolar = *Dolar + *AktualnaCena;
  }
}


// Funkcje odpowiadajace za Kolor/Intro/Koniec gry

void Reset(){
printf("%c[%dm",0x1B,0);
}

void Zielony(){
printf("%c[%dm",0x1B,32);
}

void Czerwony(){
printf("%c[%dm",0x1B,31);
}

void Niebieski(){
  printf("%c[%dm",0x1B,34);
}

void Zolty(){
  printf("%c[%dm",0x1B,33);
}

// Koniec funkcji kolorow


//############### FUNKCJE ODPOWIADAJACE ZA INTRO ###################

void intro(char Tabintra[28][100]){
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
       if(i >= 22 && i <= 26 && k == 52 ){
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

void WypiszIntro(char Tabintra[28][100]){
  for(int i = 0; i < 28; i++){
    system("sleep 0.15");
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
  system("sleep 2");
}
//Koniec funkcji odpowiadajacych za intro


//?????????????????????? TUTORIAL ?????????????????????????
void Tutorial(){
  puts("\x1B[8;7;128t");
  Zielony();

  printf("%c[%dm",0x1B,5);
  printf("%c[%dm",0x1B,4);

  printf("Tutorial\n");
  Reset();

  printf("+ Gra polega na tym by w jak najmniejszym w czasie zarobic MILION $\n");
  printf("+ By zarabiać jak najszybciej kupuj BTC w jak najniższej cenie a sprzedawaj w jak najdroższej!\n");
  printf("+ klikaj 1-By kupować BTC ! Klikaj 2 - By sprzedawać BTC\n");
  printf("+ Gra oferuje 3 tryby "); 
  Zielony(); printf("Easy"); Reset(); printf("/"); Zolty(); printf("Normaln"); Reset(); printf("/"); Czerwony(); printf("Hard\n"); Reset();
  printf("+ Pamietaj każdy tryb daje pewne ułatwienia/utrudnienia ale zarazem na zwiekszenie/zmniejszenie koncowego czasu ukonczenia Gry\n");
  printf("+ Baw się dobrze :D ! Kliknij ENTER by kontynuowac!");
    getchar(); // getch by byĹ‚ dowolny przycisk zarazem bez entera. scanf - czeka na ente. getchar - czeka na entner getch - nie czeka na enter
}

//??????????????????????/KONIEC TUTORIAL????????????????????


//$$$$$$$$$$$$$$$$$$$$$FUNKCJA WYGRANA$$$$$$$$$$$$$$$$$$$$$

void Wygrana(char TabWygrana[28][100]){
  for(int i = 0; i < 28; i++){
    for(int k = 0; k < 100; k++){
      TabWygrana[i][k] = '-';

      //W
      if( (i >= 16 && i <= 26) && (k == 2 || k == 16)){
        TabWygrana[i][k] = 'W';
      }

      if(i == 26 && k == 9 ){
	int j = 26;
	for(int h = 3; h <= 8; h++){
	  TabWygrana[j][h] = 'W';
	  j--;
	}
      }

      if(i == 26 && k == 14){
        int j = 26;
	for(int h = 14;h >= 9; h--){
	  TabWygrana[j][h] = 'W';
	  j--;
	}
      }
      //W
      
      //I
      if( (k == 19 || k == 20) &&  (i >= 16 && i <= 26 && i != 17) ){
        TabWygrana[i][k] = 'I';
      }
      //I
      
      //N
      if( (k == 23 || k == 33 || k == 36 || k == 46) && (i <= 26 && i >= 16)){
        TabWygrana[i][k] = 'N';
      }

      if(i == 26 && k == 36){
        int j = 26;
        for(int h = 46; h >= 36;h--){
          TabWygrana[j][h] = 'N';
	  j--;
        }
      }

      if(i == 26 && k == 33){
      int j = 26;
      for(int h = 33; h >= 23; h --){
        TabWygrana[j][h] = 'N';
	j--;
      }
      }
      //N

      //E
      if(i>= 16 && i <= 26 && k == 49){
        TabWygrana[i][k] = 'E';
      }

      if((i == 26 || i == 16 || i == 21) && k >= 49 && k <= 57){
        TabWygrana[i][k] = 'E';
      }
      //E

      //R
      if(k == 60 && i >= 16 && i <= 26){
        TabWygrana[i][k] = 'R';
      }

      
       int j = 16;
       for(int h = 61; h <= 68;h++){
         TabWygrana[j][h] = 'R';
	 TabWygrana[j][h+1] = 'R';
	 h++;
	 h++;
	 j++;
       }

       j = 21;
       for(int h = 61; h <= 68;h++){
         TabWygrana[j][h] = 'R';
         TabWygrana[j][h+1] = 'R';
         h++;
         h++;
         j--;
       }

       if(i == 26 && k == 68){
         int j = 26;
	 for(int h = 67; h > 60;h--){
	   TabWygrana[j][h] = 'R';
	   j--;
	 }
       }
     //R

      // $$$$$$$$$$$
      if( i >= 0 && i <15 &&( (k == 49 || k == 50 ) || (k== 16 || k == 17) || (k == 82 || k == 83) ) ){
        TabWygrana[i][k] = '$';
      }

      if( (i == 1 || i == 7 || i == 13 ) && ( (k >= 51 && k <= 52) || (k >= 47 && k <= 48) || (k >= 18 && k <= 19) || (k >= 14 && k <= 15) || (k >= 84 && k <= 85) || (k >= 80 && k <= 81) ) ){
        TabWygrana[i][k] = '$';
      }

      if( i == 6  && ( (k >= 45 && k <= 46) || (k >= 12 && k <= 13) || (k >= 78 && k <= 79) ) ){
        TabWygrana[i][k] = '$';
      }

     if( i == 8 && ( (k >= 53 && k <= 54) || (k >= 20 && k <= 21) || (k >= 86 && k <= 87) ) ){
       TabWygrana[i][k] = '$';
     }

     if( ( i == 2 || i == 12)  && ( (k>= 53 && k <= 54) || (k >= 45 && k <= 46) ||(k >= 12 && k <= 13) || (k >= 20 && k <= 21) || (k >= 86 && k <= 87) || (k >= 78 && k <= 79) )){
       TabWygrana[i][k] = '$';
     }

     if( ( (i >= 3 && i <= 5) || (i >= 9 && i <= 11) ) && ( (k >= 55 && k <= 56) || (k >= 43 && k <= 44 ) || (k>= 22 && k <= 23) || (k >= 10 && k <= 11) || (k >= 88 && k <= 89) || (k >= 76 && k <= 77))){
       TabWygrana[i][k] = '$';
     }

      //$$$$$$$$$$$$$
    }
  }
  // WYPISUJE WYGRANA
  for(int i = 0; i < 28; i++){
    system("sleep 0.2");
    for(int k = 0;k < 100;k++){
      if(TabWygrana[i][k] == '-'){
        Niebieski();
      }
      if(TabWygrana[i][k] != '-'){
        Zolty();
      }
      if(TabWygrana[i][k] == '$'){
        Zielony();
      }

      printf("%c",TabWygrana[i][k]);
      Reset();
    }
    printf("\n");
  }

  // WYPISUJE WYGRANA
}

//$$$$$$$$$$$$$$$$$$$$$KONIEC  WYGRANA$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>FUNKCJA LOSE<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void lose(char Tablose[28][100]){
  for(int i = 0; i < 28; i++){
    for(int k = 0; k < 100;k++){
      Tablose[i][k] = '-';

      //L
      if((i >= 22 && i <= 27) && k == 67){
        Tablose[i][k] = 'L';
      }
        
      //L
    }
  }

  //Wypisuje lose
  for(int i = 0; i <28; i++){
    for(int k = 0; k < 100; k ++){
      printf("%c",Tablose[i][k]);
    }
  }
}
//>>>>>>>>>>>>>>>>>>>>>>>>> Koniec funkcji lose<<<<<<<<<<<<<<<<<<<<<<<<

//Ustawienia poczatkowe 

void Ustawienia_Prof(char Nazwa[10], char *Mode_Bot,char *Tryb, int *Dolar){
  system("clear");
  printf("Czy włączyć tryb bota ? (T/N)");
  scanf("%c",&*Mode_Bot);
  
  printf("Nazwa użytkownika[max 10 znaków]: ");
  if(*Mode_Bot == 'T' || *Mode_Bot == 't'){  
    printf("Bot_");
  }

  scanf("%10s",Nazwa);
  
  getchar();
  Tryby(Tryb, Dolar);
}

void Tryby(char *Tryb, int *Dolar){
  Zielony(); printf("\t\t|EASY|\t"); Reset(); 
  Zolty();  printf("\t\t|NORMAL|\t\t"); Reset();
  Czerwony(); printf("|HARD|\n"); Reset();

  Zielony(); printf("\t\t1000$\t"); Reset();
  Zolty(); printf("\t\t  500"); Zielony(); printf("$\t\t\t"); Reset();
  Czerwony(); printf(" 250"); Zielony(); printf("$\n"); Reset();

  Zielony(); printf("         2 razy gorszy czas\t"); Reset();
  Zolty(); printf("   Rzeczywisty czas");Reset();
  Czerwony(); printf("       2 razy lepszy czas\n"); Reset();
  
  printf("Wybierz tryb: ");
  scanf("%c",&*Tryb);


  if(*Tryb == 'N' || *Tryb == 'n'){
    *Dolar = 500;
  }
  if(*Tryb == 'H' || *Tryb == 'h'){
    *Dolar = 250;
  }
  else{
    *Dolar = 1000;
  }
}

//Ustawienia poczatkowe

