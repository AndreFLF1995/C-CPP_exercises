#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
using namespace std;

struct Lugar {
    int numLugar;
    string estado;
    string matricula;
    string dataHoraEntrada;
};

void inicializaStruct(Lugar lugares[], int NUMLUGARES, string LIVRE);
void menu(bool parqueCheio);
void listarLugares(Lugar lugares[], int NUMLUGARES);
int marcarLugar(Lugar lugares[], int NUMLUGARES, string OCUPADO, bool parqueCheio, int numLugaresOcupados);
int libertarLugar(Lugar lugares[], int NUMLUGARES, string LIVRE, bool parqueCheio, int numLugaresOcupados);
bool sairDoPrograma(bool queroSair);
string currentDateTime();

int main(){
    setlocale(LC_ALL, "Portuguese");

    const int NUMLUGARES = 7;
    const string LIVRE = "Livre", OCUPADO = "Ocupado";
    Lugar lugares[NUMLUGARES];
    char  escolha = '\0';
    bool  queroSair = false,
          parqueCheio = false;
    int   numLugaresOcupados = 0;
    
    inicializaStruct(lugares, NUMLUGARES, LIVRE);
    
    do{
       menu(parqueCheio);
       cout<<" Qual é a sua escolha (A-D)? ";
       fflush(stdin);
       cin>>escolha;
     
         switch(escolha)
            {
               case 'A': case 'a':
                listarLugares(lugares, NUMLUGARES);break;
               case 'B': case 'b':
                numLugaresOcupados = marcarLugar(lugares, NUMLUGARES, OCUPADO, parqueCheio, numLugaresOcupados); break;
               case 'C': case 'c':
                numLugaresOcupados = libertarLugar(lugares, NUMLUGARES, LIVRE, parqueCheio, numLugaresOcupados); break;
               case 'D': case 'd':
                queroSair = sairDoPrograma(queroSair);break;
               default:
                cout<<"Escolha inválida!"<<endl;
                cout<<"As escolhas vão de A a D."<<endl;                        
                system("pause");
            }

        if (numLugaresOcupados < NUMLUGARES)
           parqueCheio = false;
        else
           parqueCheio = true;
           
    }while(!queroSair);

cout<<"Obrigado por ter utilizado o programa!";
cout<<endl;
system("pause");
return 0;
}

string currentDateTime(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%y %H:%M:%S", &tstruct);
    return buf;       
}

void inicializaStruct(Lugar lugares[], int NUMLUGARES, string LIVRE){
    for(int cLugar = 0; cLugar < NUMLUGARES; cLugar++){
        lugares[cLugar].numLugar = cLugar + 1;
        lugares[cLugar].estado = LIVRE;
        lugares[cLugar].matricula = "";
        lugares[cLugar].dataHoraEntrada = "";
    }
}

void menu(bool parqueCheio){
    system("cls");
    cout<<"**************************************"<<endl;
    cout<<"*                                    *"<<endl;
    cout<<"*          Gest Parque               *"<<endl;
    cout<<"*                                    *"<<endl;
    cout<<"*      A. Listar lugares.            *"<<endl;
    cout<<"*      B. Marcar lugar.              *"<<endl;
    cout<<"*      C. Libertar lugar.            *"<<endl;
    cout<<"*      D. Sair do programa.          *"<<endl;
    cout<<"*                                    *"<<endl;  
    cout<<"**************************************"<<endl;  
    cout<<endl;
    if (parqueCheio)
        {
            cout<<"**************************************"<<endl;
            cout<<"*                                    *"<<endl;
            cout<<"*         Parque Completo!           *"<<endl;
            cout<<"*                                    *"<<endl;  
            cout<<"**************************************"<<endl;                 
        }
}


void listarLugares(Lugar lugares[], int NUMLUGARES){
     for(int cLugar = 0; cLugar < NUMLUGARES; cLugar++)
       {
        cout<<"Lugar "<<lugares[cLugar].numLugar<<" -> "<<lugares[cLugar].estado<<endl;
        cout<<"Matrícula: "<<lugares[cLugar].matricula<<endl;
        cout<<"Data/Hora Entrada: "<<lugares[cLugar].dataHoraEntrada<<endl;
        cout<<endl;
       }
       system("pause");
}

int marcarLugar(Lugar lugares[], int NUMLUGARES, string OCUPADO, bool parqueCheio, int numLugaresOcupados){
    if (!parqueCheio) 
            {        
            int cLugar = 0;     
            cout<<" -> Marcar lugar: "<<endl;    
            cout<<"Qual é o lugar a ocupar (1-"<<NUMLUGARES<<")?"<<endl;
            fflush(stdin);
            cin>>cLugar;
            
            if (cLugar >= 1 && cLugar <= NUMLUGARES)
               {
               if (lugares[cLugar-1].estado != OCUPADO)
                  {
                  lugares[cLugar-1].estado = OCUPADO;
                  
                  cout<<"Qual é a matrícula (00-xx-00)?"<<endl;
                  fflush(stdin);
                  cin>>lugares[cLugar-1].matricula;
                  
                  lugares[cLugar-1].dataHoraEntrada = currentDateTime();
                  
                  numLugaresOcupados++;
                  
                  cout<<"Lugar ocupado com sucesso!"<<endl;                     
                  }
               else
                  {   
                  cout<<"O lugar já está ocupado!"<<endl;
                  }
               }
            else 
               {
               cout<<"Número de lugar inválido!"<<endl;
               cout<<"Os lugares vão de 1 a "
                   <<NUMLUGARES<<"."<<endl;         
               }
            }
        else
           { 
           cout<<"O parque está cheio!"<<endl;
           }
system("pause");
return numLugaresOcupados;
}
  
int libertarLugar(Lugar lugares[], int NUMLUGARES, string LIVRE, bool parqueCheio, int numLugaresOcupados){
int cLugar = 0;     
    cout<<" -> Libertar lugar: "<<endl;    
    cout<<"Qual é o lugar a libertar (1-"<<NUMLUGARES<<")? ";
    fflush(stdin);
    cin>>cLugar;
    
    if (cLugar >= 1 && cLugar <= NUMLUGARES)
           {
           if (lugares[cLugar-1].estado != LIVRE)
              {
              lugares[cLugar-1].estado = LIVRE;
              
              lugares[cLugar-1].matricula = "";
              
              lugares[cLugar-1].dataHoraEntrada = "";
              
              numLugaresOcupados--;
              
          cout<<"Lugar libertado com sucesso!"<<endl;                      
          }
       else
          {   
          cout<<"O lugar já está livre!"<<endl;
          }
       }
    else 
       {
       cout<<"Número de lugar inválido!"<<endl;
       cout<<"Os lugares vão de 1 a "
           <<NUMLUGARES<<"."<<endl;          
       }
system("pause");
return numLugaresOcupados;
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
