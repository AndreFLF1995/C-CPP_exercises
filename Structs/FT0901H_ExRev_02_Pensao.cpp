// 1. Bibliotecas
// 1.1 Bibliotecas do C  
#include <cstdio>  // Funções: scanf(), printf().
#include <cstdlib> // Funções: system().
#include <clocale> // Funções: setlocale().
// 1.2 Bibliotecas do C++
#include <iostream>  // cin, cout
#include <iomanip>   // setprecision()
#include <string>    // Operações com "strings". 
using namespace std;

struct Pensao {
    int numAndar;
    int numQuarto;
    string estado;
    string hospede;
    string checkIn;
};

string currentDate(){
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%y %H:%M:%S", &tstruct);
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

// 2. Programa - Função principal
int main()
{
// 2.1 Dados
const int NUMANDARES = 3, NUMQUARTOSPORANDAR = 5;
const string LIVRE = "Livre", RESERVADO = "Reservado", OCUPADO = "Ocupado";
Pensao  quartos[NUMANDARES][NUMQUARTOSPORANDAR];
char  escolha = '\0';
bool  queroSair = false;
    

// 2.2 Algoritmo 
// 2.2.0 Inicialização de Vetores
setlocale(LC_ALL, "Portuguese");
for(int cAndar = 0; cAndar < NUMANDARES; cAndar++)
   {
   for(int cQuarto = 0; cQuarto < NUMQUARTOSPORANDAR;cQuarto++)
      {        
             quartos[cAndar][cQuarto].numAndar = cAndar + 1;
             quartos[cAndar][cQuarto].numQuarto = cQuarto + 1;
             quartos[cAndar][cQuarto].estado = LIVRE;
             quartos[cAndar][cQuarto].hospede = "";
             quartos[cAndar][cQuarto].checkIn = "";
      }
   }

do {
// 2.2.1 Apresentar o menu de opções
system("cls");
system("color A");
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

// 2.2.2 Obter a escolha do utilizador
cout<<"-> Qual é a sua escolha (1-5)? ";
fflush(stdin);
cin>>escolha;
cout<<endl;        

// 2.2.3 Processar a escolha
//       Apresentação da saída de cada escolha
switch(escolha)
{
   case '1':
    {    
    cout<<"-> Listagem de quartos: "<<endl;
    for(int cAndar = 0;cAndar<NUMANDARES;cAndar++)
       {
       cout<<"-> Andar "<<(cAndar+1)<<": "<<endl;     
       for(int cQuarto = 0; cQuarto < NUMQUARTOSPORANDAR; cQuarto++)
          {
           
           cout<<"Quarto "<<quartos[cAndar][cQuarto].numAndar<<"."<<quartos[cAndar][cQuarto].numQuarto<<endl;
           cout<<"Estado -> "<<quartos[cAndar][cQuarto].estado<<endl;
           
           if(quartos[cAndar][cQuarto].estado != LIVRE){
              cout<<"Hospede -> "<<quartos[cAndar][cQuarto].hospede<<", "<<quartos[cAndar][cQuarto].checkIn;
           }
                                      
          cout<<endl;      
          } // Fim do for dos "quartos". 
       system("pause");                                      
       } // Fim do for dos "andares".      
    break;
    }
           
   case '2': 
    {   
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
    break; 
    }
    
   case '3':              
    {   
    cout<<"-> Check-in: "<<endl;    
    int numAndar = 0, numQuarto = 0;
    cout<<"Qual o andar a selecionar (1-"
        <<NUMANDARES<<")? ";
    cin>>numAndar;
    cout<<"Nesse andar, qual o quarto a ocupar (1-"
        <<NUMQUARTOSPORANDAR<<")? ";
    cin>>numQuarto;
    fflush(stdin);
    
    if (numAndar >= 1   && numAndar <= NUMANDARES)
       {
       if (numQuarto >= 1 
        && numQuarto <= NUMQUARTOSPORANDAR)
          {
          if(quartos[numAndar-1][numQuarto-1].estado
             != OCUPADO)
             {
             quartos[numAndar-1][numQuarto-1].estado = OCUPADO;
             cout<<"Nome do hóspede: ";
             getline(cin,
                   quartos[numAndar-1][numQuarto-1].hospede
                   );
             quartos[numAndar-1][numQuarto-1].checkIn = currentDate();
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
    system("pause");
    break; 
    }  
 
   case '4':              
    {   
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
    break; 
    } 
                               
   case '5':
     {   
     cout<<"-> Sair do programa: "<<endl; 
     char resposta = '\0';   
     cout<<"Tem a certeza que quer sair (S/N)? ";
     fflush(stdin);
     cin>>resposta;   
              
     if (resposta == 'S' || resposta == 's')
         queroSair = true;  
     break;    
     }  
   default:
     cout<<"Escolha inválida!"<<endl;
     cout<<"As escolhas vão de 1 a 5."<<endl;                        
     system("pause");          
}  // Fim do "switch".              

}while(!queroSair);  // queroSair == false
                     // !queroSair -> Não queroSair.
                     
// 2.2.5 Despedida                     
cout<<"Obrigado por ter utilizado o programa!";
cout<<endl;
system("pause");
return 0;
} // Fim da função "main()".
