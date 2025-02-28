#include <iostream>
#include <conio.h>    //necessaria per getch()
#include <math.h>
#include <windows.h>

using namespace std;

const int MAX = 3+1;  //Grado del polinomio + termine noto

//Queste funzioni sono qui solo per sempificare la lettura del codice;
//Servono solo per cambiare il colore degli output futuri.
//Preso da https://stackoverflow.com/a/63679499 e https://learn.microsoft.com/en-us/windows/console/console-screen-buffers#character-attributes
//ALL = FOREGROUND_BLUE FOREGROUND_GREEN FOREGROUND_RED FOREGROUND_INTENSITY BACKGROUND_BLUE BACKGROUND_GREEN BACKGROUND_RED BACKGROUND_INTENSITY
//FOREGROUND testo, INTENSITY più luminoso
//usare '|' perr combinare
void resetColor(){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void titleColor(){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void errorColor(){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
}

void printTitle(string title) {
  system("cls");
  titleColor();
  cout<<title<<"\n\n";
  resetColor();
}

int main() {
  int p1[MAX]; //Primo polinomio
  int p2[MAX]; //Secondo polinomio
  int g1, g2;  //Gradi dei polinomi
  
  system("title Progetto polinomi");
  
  //Welcome screen
  cout<<"Premere un tasto per iniziare l'inserimento ";
  system("pause >nul");
  
  printTitle("Inserimento polinomi");
  
  //lettura 1° grado
  while(true) { //lo so che si può usare una do-while, ma preferisco così .
    cout<<"Grado del 1^ polinomio: ";
    cin>>g1;
    if(g1 > 0 && g1 < MAX) break;
    errorColor();
    cout<<g1<<" non e' incluso tra 1 e "<<MAX-1<<"\n";
    resetColor();
  }
  
  for(int i = g1; i>=0; i--){
    cout<<"\nInserisci il ";
    if(i == 0) cout<<"termine noto: ";
    else cout<<i<<"^ coefficente: ";
    cin>>p1[i];
    if(i == g1 && p1[i] == 0) { //Se il primo termine è 0 lo richiedo poiché è impossibile
      errorColor();
      cout<<"Il primo termine non puo' essere 0, reinseriscilo\n";
      resetColor();
      i++;
    }
  }
  
  //Stampa polinomio
  for(int i = g1; i>=0; i--) {
    int n = p1[i];
    if(n == 0) continue;          //Non stampiamo gli zeri
    if(n>0 && i != g1) cout<<"+"; //Aggiungo il + se è >0 e non è il primo termine
    cout<<n;                      //Stampo il coefficente
    if(i!=0) cout<<"x^"<<i;       //Se è il termine noto non serve aggiungere x^0
    cout<<" ";                    //Aggiungo uno spazio per separare i vari termini
  }
  
  cout<<"\n\n"; //separo
  //lettura 2° grado
  while(true) { //lo so che si può usare una do-while, ma preferisco così .
    cout<<"Grado del 2^ polinomio: ";
    cin>>g2;
    if(g2 > 0 && g2 < MAX) break;
    errorColor();
    cout<<g2<<" non e' incluso tra 1 e "<<MAX-1<<"\n";
    resetColor();
  }
  
  for(int i = g2; i>=0; i--){
    cout<<"\nInserisci il ";
    if(i == 0) cout<<"termine noto: ";
    else cout<<i<<"^ coefficente: ";
    cin>>p2[i];
    if(i == g2 && p2[i] == 0) { //Se il primo termine è 0 lo richiedo poiché è impossibile
      errorColor();
      cout<<"Il primo termine non puo' essere 0, reinseriscilo\n";
      resetColor();
      i++;
    }
  }
  
  //Stampa polinomio
  for(int i = g2; i>=0; i--) {
    int n = p2[i];
    if(n == 0) continue;          //Non stampiamo gli zeri
    if(n>0 && i != g2) cout<<"+"; //Aggiungo il + se è >0 e non è il primo termine
    cout<<n;                      //Stampo il coefficente
    if(i!=0) cout<<"x^"<<i;       //Se è il termine noto non serve aggiungere x^0
    cout<<" ";                    //Aggiungo uno spazio per separare i vari termini
  }
  
  cout<<"\n\nPremere un tasto per confermare...";
  system("pause >nul");
  
  //ciclo principale
  while(1) {
    system("cls");
    system("title Progetto polinomi - Menu");
    char opt;
    cout<<"0: Reinserisci i polinomi"<<endl;
    cout<<"1: Somma tra polinomi"<<endl;
    cout<<"2: Differenza tra polinomi"<<endl;
    cout<<"3: Prodotto tra polinomi"<<endl;
    cout<<"4: Ricerca degli zeri dei polinomi"<<endl;
    cout<<"5: Intersezione"<<endl;
    cout<<"6: Grafico"<<endl;
    cout<<"9: Esci"<<endl;
    cout<<"Scegli: ";
    opt=getch();
    
    //LE GRAFFE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
    switch(opt) {
      case '0':
        //TODO CTRL+C,V;
        //Aggiungere più testo, è ancora troppo scarno (titolo, spaziature,title)
        break;
      case '1': {
        printTitle("Somma tra polinomi");
        system("title Progetto polinomi - Somma");
        cout<<"Il risultato di (";
        for(int i = g1; i>=0; i--) {  //Stampa polinomio 1
          int n = p1[i];
          if(n == 0) continue;          //Non stampiamo gli zeri
          if(n>0 && i != g1) cout<<"+"; //Aggiungo il + se è >0 e non è il primo termine
          cout<<n;                      //Stampo il coefficente
          if(i!=0) cout<<"x^"<<i;       //Se è il termine noto non serve aggiungere x^0
          cout<<" ";                    //Aggiungo uno spazio per separare i vari termini
        }
        cout<<") + (";
        for(int i = g2; i>=0; i--) {  //Stampa polinomio 2
          int n = p2[i];
          if(n == 0) continue;          //Non stampiamo gli zeri
          if(n>0 && i != g2) cout<<"+"; //Aggiungo il + se è >0 e non è il primo termine
          cout<<n;                      //Stampo il coefficente
          if(i!=0) cout<<"x^"<<i;       //Se è il termine noto non serve aggiungere x^0
          cout<<" ";                    //Aggiungo uno spazio per separare i vari termini
        }
        cout<<") e': ";
        for(int i = max(g1, g2); i>=0; i--) {
          int n;
          if(i>g1) n= p2[i];            //Se p1 non ha il grado i la somma è il termine di p2
          else if(i>g2) n= p1[i];       //Opposto di quello sopra
          else n=p1[i] + p2[i];         //Altrimenti la somma è la somma dei termini dei due polinomi
          if(n == 0) continue;          //Non stampiamo gli zeri
          if(n>0 && i != g2) cout<<"+"; //Aggiungo il + se è >0 e non è il primo termine
          cout<<n;                      //Stampo il coefficente
          if(i!=0) cout<<"x^"<<i;       //Se è il termine noto non serve aggiungere x^0
          cout<<" ";                    //Aggiungo uno spazio per separare i vari termini
        }
        break;
      }
      case '2': {
        printTitle("Differenza tra polinomi");
        system("title Progetto polinomi - Differenza");
        cout<<"Il risultato di (";
        for(int i = g1; i>=0; i--) {  //Stampa polinomio 1
          int n = p1[i];
          if(n == 0) continue;          //Non stampiamo gli zeri
          if(n>0 && i != g1) cout<<"+"; //Aggiungo il + se è >0 e non è il primo termine
          cout<<n;                      //Stampo il coefficente
          if(i!=0) cout<<"x^"<<i;       //Se è il termine noto non serve aggiungere x^0
          cout<<" ";                    //Aggiungo uno spazio per separare i vari termini
        }
        cout<<") - (";
        for(int i = g2; i>=0; i--) {  //Stampa polinomio 2
          int n = p2[i];
          if(n == 0) continue;          //Non stampiamo gli zeri
          if(n>0 && i != g2) cout<<"+"; //Aggiungo il + se è >0 e non è il primo termine
          cout<<n;                      //Stampo il coefficente
          if(i!=0) cout<<"x^"<<i;       //Se è il termine noto non serve aggiungere x^0
          cout<<" ";                    //Aggiungo uno spazio per separare i vari termini
        }
        cout<<") e': ";
        for(int i = max(g1, g2); i>=0; i--) {
          int n;
          if(i>g1) n= -p2[i];           //Se p1 non ha il grado i la differenza è il termine di p2
          else if(i>g2) n= p1[i];       //Opposto di quello sopra
          else n=p1[i] - p2[i];         //Altrimenti la differenza è la differenza dei termini dei due polinomi
          if(n == 0) continue;          //Non stampiamo gli zeri
          if(n>0 && i != g2) cout<<"+"; //Aggiungo il + se è >0 e non è il primo termine
          cout<<n;                      //Stampo il coefficente
          if(i!=0) cout<<"x^"<<i;       //Se è il termine noto non serve aggiungere x^0
          cout<<" ";                    //Aggiungo uno spazio per separare i vari termini
        }
        break;
      }
      case '9':
        return 0;
      default:
        cout<<opt<<" non e' una valida opzione, riprova\n\n";
    }
    cout<<"\n\n";
    system("pause");
  }
}
