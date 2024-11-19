// 1. Bibliotecas
// 1.1 Bibliotecas do C  
#include <cstdio>  // Fun��es: scanf(), printf().
#include <cstdlib> // Fun��es: system().
#include <clocale> // Fun��es: setlocale().
// 1.2 Bibliotecas do C++
#include <iostream>  // cin, cout
#include <iomanip>   // setprecision()
#include <string>    // Opera��es com "strings".
#include <time.h>
#include <conio.h>
using namespace std;

struct Lugar {
    int numLugar;
    string estado;
    string matricula;
    string dataEntrada;
    string horaEntrada;
};

string currentDate(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%y", &tstruct);
    return buf;       
}

string currentTime(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);
    return buf;         
}

// 2. Programa - Fun��o principal
int main()
{
// 2.1 Dados
const int NUMLUGARES = 7;
const string LIVRE = "Livre", OCUPADO = "Ocupado";
Lugar lugares[NUMLUGARES];
char  escolha = '\0';
bool  queroSair = false,
      parqueCheio = false;
int   numLugaresOcupados = 0;      

// 2.2 Algoritmo 
// 2.2.0 Inicializa��o de Vetores
setlocale(LC_ALL, "Portuguese");
for(int cLugar = 0; cLugar < NUMLUGARES; cLugar++)
   {
        lugares[cLugar].numLugar = cLugar + 1;
        lugares[cLugar].estado = LIVRE;
        lugares[cLugar].matricula = "";
        lugares[cLugar].dataEntrada = "";
        lugares[cLugar].horaEntrada = "";
   }

do {
// 2.2.1 Apresentar o menu de op��es
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

// 2.2.2 Obter a escolha do utilizador
cout<<" Qual � a sua escolha (A-D)? ";
fflush(stdin);
cin>>escolha;
        

// 2.2.3 Processar a escolha
//       Apresenta��o da sa�da de cada escolha
switch(escolha)
{
   case 'A': case 'a':
    {                  
    cout<<" -> Listagem de lugares: "<<endl;
    for(int cLugar = 0; cLugar < NUMLUGARES; cLugar++)
       {
        cout<<"Lugar "<<lugares[cLugar].numLugar<<" -> "<<lugares[cLugar].estado<<endl;
        cout<<"Matr�cula: "<<lugares[cLugar].matricula<<endl;
        cout<<"Data/Hora Entrada: "<<lugares[cLugar].dataEntrada<<" "<<lugares[cLugar].horaEntrada<<endl;
        cout<<endl;
       }  
    system("pause");              
    break;  
    }           
   case 'B': case 'b': 
    {   
    if (!parqueCheio) 
        {        
        int cLugar = 0;     
        cout<<" -> Marcar lugar: "<<endl;    
        cout<<"Qual � o lugar a ocupar (1-"<<NUMLUGARES<<")?"<<endl;
        fflush(stdin);
        cin>>cLugar;
        
        if (cLugar >= 1 && cLugar <= NUMLUGARES)
           {
           if (lugares[cLugar-1].estado != OCUPADO)
              {
              lugares[cLugar-1].estado = OCUPADO;
              
              cout<<"Qual � a matr�cula (00-xx-00)?"<<endl;
              fflush(stdin);
              cin>>lugares[cLugar-1].matricula;
              
              lugares[cLugar-1].dataEntrada = currentDate();
              lugares[cLugar-1].horaEntrada = currentTime();
              
              numLugaresOcupados++;
              if (numLugaresOcupados == NUMLUGARES)
                  parqueCheio = true;
              cout<<"Lugar ocupado com sucesso!"<<endl;                     
              }
           else
              {   
              cout<<"O lugar j� est� ocupado!"<<endl;
              }
           }
        else 
           {
           cout<<"N�mero de lugar inv�lido!"<<endl;
           cout<<"Os lugares v�o de 1 a "
               <<NUMLUGARES<<"."<<endl;         
           }
        } // Fim do "if(parqueCheio)".
    else
       { 
       cout<<"O parque est� cheio!"<<endl;
       }                 
    system("pause");
    break; 
    }
    
   case 'C': case 'c':              
    {   
    int cLugar = 0;     
    cout<<" -> Libertar lugar: "<<endl;    
    cout<<"Qual � o lugar a libertar (1-"<<NUMLUGARES<<")? ";
    fflush(stdin);
    cin>>cLugar;
    
    if (cLugar >= 1 && cLugar <= NUMLUGARES)
           {
           if (lugares[cLugar-1].estado != LIVRE)
              {
              lugares[cLugar-1].estado = LIVRE;
              
              lugares[cLugar-1].matricula = "";
              
              lugares[cLugar-1].dataEntrada = "";
              lugares[cLugar-1].horaEntrada = "";
              
              numLugaresOcupados--;
              
          if (numLugaresOcupados < NUMLUGARES)
                  parqueCheio = false;
          cout<<"Lugar libertado com sucesso!"<<endl;                      
          }
       else
          {   
          cout<<"O lugar j� est� livre!"<<endl;
          }
       }
    else 
       {
       cout<<"N�mero de lugar inv�lido!"<<endl;
       cout<<"Os lugares v�o de 1 a "
           <<NUMLUGARES<<"."<<endl;          
       }          
    system("pause");
    break; 
    }
                        
   case 'D': case 'd':
     {    
     char resposta = '\0';   
     cout<<"Tem a certeza que quer sair (S/N)? ";
     fflush(stdin);
     cin>>resposta;   
              
     if (resposta == 'S' || resposta == 's')
         queroSair = true;  
     break;    
     }  
   default:
     cout<<"Escolha inv�lida!"<<endl;
     cout<<"As escolhas v�o de A a D."<<endl;                        
     system("pause");          
}  // Fim do "switch".              

}while(!queroSair);  // queroSair == false
                     // !queroSair -> N�o queroSair.
                     
// 2.2.5 Despedida                     
cout<<"Obrigado por ter utilizado o programa!";
cout<<endl;
system("pause");
return 0;
} // Fim da fun��o "main()".
