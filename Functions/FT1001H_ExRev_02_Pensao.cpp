#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
using namespace std;

struct Pensao {
    int numAndar;
    int numQuarto;
    string estado;
    string hospede;
    string checkIn;
};

void inicializaStruct(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE);
void menu(bool pensaoCheia);
void listarQuartos(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE);
int reservaQuarto(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE, string RESERVADO, int numQuartosOcupados, bool pensaoCheia);
int checkIn(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE, string OCUPADO, int numQuartosOcupados, bool pensaoCheia);
string currentDateTime();
int checkOut(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE, int numQuartosOcupados);
bool sairDoPrograma(bool queroSair);

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    const int NUMANDARES = 3, NUMQUARTOSPORANDAR = 5, TOTALQUARTOS = 15;
    const string LIVRE = "Livre", RESERVADO = "Reservado", OCUPADO = "Ocupado";
    Pensao  quartos[NUMANDARES][NUMQUARTOSPORANDAR];
    char  escolha = '\0';
    bool  queroSair = false;
    bool pensaoCheia = false;
    int numQuartosOcupados = 0;
    
    inicializaStruct(quartos, NUMANDARES, NUMQUARTOSPORANDAR, LIVRE);
    
    do{
       menu(pensaoCheia);
       cout<<" Qual é a sua escolha (1-5)? ";
       fflush(stdin);
       cin>>escolha;
     
         switch(escolha)
            {
               case '1':
                listarQuartos(quartos, NUMANDARES, NUMQUARTOSPORANDAR, LIVRE);break;
               case '2':
                numQuartosOcupados = reservaQuarto(quartos, NUMANDARES, NUMQUARTOSPORANDAR, LIVRE, RESERVADO, numQuartosOcupados, pensaoCheia); break;
               case '3':
                numQuartosOcupados = checkIn(quartos, NUMANDARES, NUMQUARTOSPORANDAR, LIVRE, OCUPADO, numQuartosOcupados, pensaoCheia); break;
               case '4':
                numQuartosOcupados = checkOut(quartos, NUMANDARES, NUMQUARTOSPORANDAR, LIVRE, numQuartosOcupados); break;
               case '5':
                queroSair = sairDoPrograma(queroSair);break;
               default:
                cout<<"Escolha inválida!"<<endl;
                cout<<"As escolhas vão de 1 a 5."<<endl;
                system("pause");
            }

        if (numQuartosOcupados < TOTALQUARTOS)
           pensaoCheia = false;
        else
           pensaoCheia = true;
           
    }while(!queroSair);

cout<<"Obrigado por ter utilizado o programa!";
cout<<endl;
system("pause");
return 0;
}

void inicializaStruct(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE){
     for(int cAndar = 0; cAndar < NUMANDARES; cAndar++){
       for(int cQuarto = 0; cQuarto < NUMQUARTOSPORANDAR;cQuarto++)
          {        
                 quartos[cAndar][cQuarto].numAndar = cAndar + 1;
                 quartos[cAndar][cQuarto].numQuarto = cQuarto + 1;
                 quartos[cAndar][cQuarto].estado = LIVRE;
                 quartos[cAndar][cQuarto].hospede = "";
                 quartos[cAndar][cQuarto].checkIn = "";
          }
       }
}

void menu(bool pensaoCheia){
system("cls");
cout<<"*****************************"<<endl;
cout<<"*                           *"<<endl;
cout<<"*        Pensão Gest        *"<<endl;
cout<<"*                           *"<<endl;
cout<<"*    1. Listar quartos.     *"<<endl;
cout<<"*    2. Reservar quarto.    *"<<endl;
cout<<"*    3. Check-in.           *"<<endl;
cout<<"*    4. Check-out.          *"<<endl;
cout<<"*    5. Sair do programa.   *"<<endl;
cout<<"*                           *"<<endl;
cout<<"*****************************"<<endl;
cout<<endl;

if (pensaoCheia)
        {
            cout<<"**************************************"<<endl;
            cout<<"*                                    *"<<endl;
            cout<<"*           Pensao Lotada!           *"<<endl;
            cout<<"*                                    *"<<endl;  
            cout<<"**************************************"<<endl;                 
        }
}


void listarQuartos(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE){
    cout<<"-> Listagem de quartos: "<<endl;
        for(int cAndar = 0;cAndar<NUMANDARES;cAndar++){
        cout<<"-> Andar "<<(cAndar+1)<<": "<<endl;     
            for(int cQuarto = 0; cQuarto < NUMQUARTOSPORANDAR; cQuarto++){
            
            cout<<"Quarto "<<quartos[cAndar][cQuarto].numAndar<<"."<<quartos[cAndar][cQuarto].numQuarto<<endl;
            cout<<"Estado -> "<<quartos[cAndar][cQuarto].estado<<endl;
            
            if(quartos[cAndar][cQuarto].estado != LIVRE){
            cout<<"Hospede -> "<<quartos[cAndar][cQuarto].hospede<<", "<<quartos[cAndar][cQuarto].checkIn<<endl;
            }
                          
            cout<<endl;      
            } 
            system("pause");                                      
        }
}

int reservaQuarto(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE, string RESERVADO, int numQuartosOcupados, bool pensaoCheia){
    if (!pensaoCheia){
        cout<<"-> Reservar quarto: "<<endl;    
        int numAndar = 0, numQuarto = 0;
        cout<<"Qual o andar a selecionar (1-"<<NUMANDARES<<")? ";
        cin>>numAndar;
        cout<<"Nesse andar, qual o quarto a reservar (1-"<<NUMQUARTOSPORANDAR<<")? ";
        cin>>numQuarto;
        fflush(stdin);
        
        if (numAndar >= 1   && numAndar <= NUMANDARES)
           {
           if (numQuarto >= 1 
            && numQuarto <= NUMQUARTOSPORANDAR)
              {
              if(quartos[numAndar-1][numQuarto-1].estado
                 == LIVRE)
                 {
                 quartos[numAndar-1][numQuarto-1].estado = RESERVADO;
                 cout<<"Em que nome fica a reserva? ";
                 getline(cin, quartos[numAndar-1][numQuarto-1].hospede); 
                 cout<<"Quarto reservado com sucesso!"<<endl;
                 
                 numQuartosOcupados++;
                 }                    
              else
                 {
                 cout<<"Quarto não está livre!"
                     <<endl;                     
                 }
              }   
            else
              {
              cout<<"Número de quarto inválido!"<<endl;                       
              } 
           }                                
         else
           {
            cout<<"Número de andar inválido!"<<endl;            
           }                                
        system("pause");
    }
    else{
         cout<<"A pensao está lotada!"<<endl;
    }
    
    system("pause");
    return numQuartosOcupados;
}

int checkIn(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE, string OCUPADO, int numQuartosOcupados, bool pensaoCheia){
    if (!pensaoCheia){
        cout<<"-> Check-in: "<<endl;    
        int numAndar = 0, numQuarto = 0;
        cout<<"Qual o andar a selecionar (1-"<<NUMANDARES<<")? ";
        fflush(stdin);
        cin>>numAndar;
        cout<<"Nesse andar, qual o quarto a ocupar (1-"<<NUMQUARTOSPORANDAR<<")? ";
        fflush(stdin);
        cin>>numQuarto;
        
        
        if (numAndar >= 1   && numAndar <= NUMANDARES)
           {
           if (numQuarto >= 1 
            && numQuarto <= NUMQUARTOSPORANDAR)
              {
              if(quartos[numAndar-1][numQuarto-1].estado
                 != OCUPADO)
                 {
                 quartos[numAndar-1][numQuarto-1].estado = OCUPADO;
                 fflush(stdin);
                 cout<<"Nome do hóspede: ";
                 getline(cin,
                       quartos[numAndar-1][numQuarto-1].hospede
                       );
                 quartos[numAndar-1][numQuarto-1].checkIn = currentDateTime();
                 
                 numQuartosOcupados++;
                 cout<<"Quarto ocupado com sucesso!"
                     <<endl;         
                 }                    
              else
                 {
                 cout<<"Quarto já está ocupado!"
                     <<endl;                     
                 }
                 }
            else
              {
              cout<<"Número de quarto inválido!"<<endl;                       
              }
           }                                    
         else
           {
            cout<<"Número de andar inválido!"<<endl;            
           }  
        }
    else{
         cout<<"A pensao está lotada!"<<endl; 
    }
    
    system("pause");
    return numQuartosOcupados;
}

string currentDateTime(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%y %H:%M:%S", &tstruct);
    return buf;       
}

int checkOut(Pensao quartos[3][5], int NUMANDARES, int NUMQUARTOSPORANDAR, string LIVRE, int numQuartosOcupados){
    cout<<"-> Check-out: "<<endl;    
    int numAndar = 0, numQuarto = 0;
    cout<<"Qual o andar a selecionar (1-"
        <<NUMANDARES<<")? ";
    cin>>numAndar;
    cout<<"Nesse andar, qual o quarto a libertar (1-"
        <<NUMQUARTOSPORANDAR<<")? ";
    cin>>numQuarto;
    fflush(stdin);
    
    if (numAndar >= 1   && numAndar <= NUMANDARES)
       {
       if (numQuarto >= 1 
        && numQuarto <= NUMQUARTOSPORANDAR)
          {
          if(quartos[numAndar-1][numQuarto-1].estado
             != LIVRE)
             {
             quartos[numAndar-1][numQuarto-1].estado = LIVRE;
             quartos[numAndar-1][numQuarto-1].hospede = "";
             quartos[numAndar-1][numQuarto-1].checkIn = "";
             cout<<"Quarto libertado com sucesso!"
                 <<endl;         
             }                    
          else
             {
             cout<<"Quarto já está livre!"
                 <<endl;                     
          }
          }
        else
          {
          cout<<"Número de quarto inválido!"<<endl;                       
          } 
          
       }    
     else
       {
        cout<<"Número de andar inválido!"<<endl;            
       }         
    system("pause");
    
    return numQuartosOcupados;
}

bool sairDoPrograma(bool queroSair){
     char resposta = '\0';   
     cout<<"Tem a certeza que quer sair (S/N)? ";
     fflush(stdin);
     cin>>resposta;   
              
     if (resposta == 'S' || resposta == 's')
         queroSair = true;
return queroSair;     
}
