#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    string mesas[10];
    bool sair = false;
    char opcao = '\0';
    bool mesasOcupadas = false;
    int numMesasOcupadas = 0;
    
    for (int i = 0; i < 10; i++){
        mesas[i] = "Livre";    
    }


do {
    system ("cls");
    cout<<"********************************************"<<endl;
    cout<<"*            Restaurante 'O Patudo'        *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*            1 - Listar Mesas.             *"<<endl;
    cout<<"*            2 - Reservar Mesas.           *"<<endl;
    cout<<"*            3 - Ocupar Mesa.              *"<<endl;
    cout<<"*            4 - Desocupar Mesa.           *"<<endl;
    cout<<"*            0 - Sair.                     *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    if (mesasOcupadas)
	   {
	   cout<<"**************************************"<<endl;
	   cout<<"*                                    *"<<endl;
	   cout<<"*        Restaurante Cheio!          *"<<endl;
	   cout<<"*                                    *"<<endl;  
	   cout<<"**************************************"<<endl;                 
	   };
    
    cout<<"Insira a opcao que quer: "<<endl;
    cin>>opcao;
    
    switch (opcao){
           
           case '1':	
	   			for (int i = 0; i < 10; i++){
					cout<<"Mesa "<<i+1<<" -> "<<mesas[i]<<endl;    
				}
				system("pause");
	            break;
           
           case '2':
           		if (!mesasOcupadas){
					int numMesa = 0;
        			cout<<" -> Marcar mesa: "<<endl;    
        			cout<<"Qual é a mesa a reservar (1 - 10)?"<<endl;
        			cin>>numMesa;
        			
        			if (numMesa >= 1 && numMesa <= 10){
        				if (mesas[numMesa-1] == "Livre"){
        					mesas[numMesa-1] = "Reservado";
        					cout<<"A mesa foi reservada com sucesso!"<<endl;
        					numMesasOcupadas++;
        					if (numMesasOcupadas == 10){
        						mesasOcupadas = true;
							}
						}
						else{
							cout<<"A mesa já está ocupada ou reservada!"<<endl;
						}
					}
					else 
		           {
			           cout<<"Número de mesa inválido!"<<endl;
			           cout<<"As mesas vão de 1 a 10"<<endl;          
		           }
				cout<<endl;
				system("pause");
                break;
        		}
                    
           case '3':
				if (!mesasOcupadas){
					int numMesa = 0;
        			cout<<" -> Marcar mesa: "<<endl;    
        			cout<<"Qual é a mesa a ocupar (1 - 10)?"<<endl;
        			cin>>numMesa;
        			
        			if (numMesa >= 1 && numMesa <= 10){
        				
        				if (mesas[numMesa-1] == "Livre"){
        					mesas[numMesa-1] = "Ocupado";
        					cout<<"A mesa foi Ocupada com sucesso!"<<endl;
        					numMesasOcupadas++;
						}
						else{
							cout<<"A mesa já está ocupada!"<<endl;
						}
					}
					else 
		           {
			           cout<<"Número de mesa inválido!"<<endl;
			           cout<<"As mesas vão de 1 a 10"<<endl;          
		           }
				cout<<endl;
				system("pause");
                break;
        		}
           
           case '4':
				if (!mesasOcupadas){
					int numMesa = 0;
        			cout<<" -> Marcar mesa: "<<endl;    
        			cout<<"Qual é a mesa a desocupar (1 - 10)?"<<endl;
        			cin>>numMesa;
        			
        			if (numMesa >= 1 && numMesa <= 10){
        				
        				if (mesas[numMesa-1] != "Livre"){
        					mesas[numMesa-1] = "Livre";
        					numMesasOcupadas--;
        					cout<<"A mesa foi Desocupada com sucesso!"<<endl;
						}
						else{
							cout<<"A mesa já está livre!"<<endl;
						}
					}
					else 
		           {
			           cout<<"Número de mesa inválido!"<<endl;
			           cout<<"As mesas vão de 1 a 10"<<endl;          
		           }
				cout<<endl;
				system("pause");
                break;
        		}

           case '0':
					cout<<"Tem a certeza que quer sair? (s/n)"<<endl;
                    cin>>opcao;
                        if (opcao == 's' || opcao == 'S'){
                             sair = true;
                        }
                        else{
                             sair = false;
                        }
                    break;
        }
}while (!sair);
    
    cout<<endl;
    cout<<"Obrigado por usar o programa! Adeus!!"<<endl;
    system("pause");
}
