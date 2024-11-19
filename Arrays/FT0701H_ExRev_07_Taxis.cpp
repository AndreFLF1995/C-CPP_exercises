#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    string taxis[10];
    bool sair = false;
    char opcao = '\0';
    bool taxisOcupados = false;
    int numTaxisOcupados = 0;
    
    for (int i = 0; i < 10; i++){
        taxis[i] = "Livre";    
    }


do {
    system ("cls");
    cout<<"********************************************"<<endl;
    cout<<"*            T�xis 'Levo-te � Lua'         *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*            1 - Listar T�xis.             *"<<endl;
    cout<<"*            2 - Reservar T�xi.            *"<<endl;
    cout<<"*            3 - Chamar T�xi.              *"<<endl;
    cout<<"*            4 - Libertar T�xi.            *"<<endl;
    cout<<"*            0 - Sair.                     *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    if (taxisOcupados)
	   {
	   cout<<"**************************************"<<endl;
	   cout<<"*                                    *"<<endl;
	   cout<<"*      N�o h� T�xis Dispon�veis      *"<<endl;
	   cout<<"*                                    *"<<endl;  
	   cout<<"**************************************"<<endl;                 
	   };
    
    cout<<"Insira a opcao que quer: "<<endl;
    cin>>opcao;
    
    switch (opcao){
           
           case '1':	
	   			for (int i = 0; i < 10; i++){
					cout<<"Taxi "<<i+1<<" -> "<<taxis[i]<<endl;    
				}
				system("pause");
	            break;
           
           case '2':
           		if (!taxisOcupados){
					int numTaxi = 0;
        			cout<<" -> Marcar taxi: "<<endl;    
        			cout<<"Qual � o taxi a reservar (1 - 10)?"<<endl;
        			cin>>numTaxi;
        			
        			if (numTaxi >= 1 && numTaxi <= 10){
        				if (taxis[numTaxi-1] == "Livre"){
        					taxis[numTaxi-1] = "Reservado";
        					cout<<"O taxi foi reservado com sucesso!"<<endl;
        					numTaxisOcupados++;
        					if (numTaxisOcupados == 10){
        						taxisOcupados = true;
							}
						}
						else{
							cout<<"O taxi j� est� reservado ou foi chamado!"<<endl;
						}
					}
					else 
		           {
			           cout<<"N�mero de taxi inv�lido!"<<endl;
			           cout<<"Os taxis v�o de 1 a 10"<<endl;          
		           }
				cout<<endl;
				system("pause");
                break;
        		}
                    
           case '3':
				if (!taxisOcupados){
					int numTaxi = 0;
        			cout<<" -> Marcar taxi: "<<endl;    
        			cout<<"Qual � o taxi a chamar (1 - 10)?"<<endl;
        			cin>>numTaxi;
        			
        			if (numTaxi >= 1 && numTaxi <= 10){
        				
        				if (taxis[numTaxi-1] == "Livre"){
        					taxis[numTaxi-1] = "Chamado";
        					cout<<"O taxi foi chamado com sucesso!"<<endl;
        					numTaxisOcupados++;
						}
						else{
							cout<<"O taxi j� est� reservado ou foi chamado!"<<endl;
						}
					}
					else 
		           {
			           cout<<"N�mero de taxi inv�lido!"<<endl;
			           cout<<"Os taxis v�o de 1 a 10"<<endl;          
		           }
				cout<<endl;
				system("pause");
                break;
        		}
           
           case '4':
				if (!taxisOcupados){
					int numTaxi = 0;
        			cout<<" -> Marcar taxi: "<<endl;    
        			cout<<"Qual � o taxi a libertar (1 - 10)?"<<endl;
        			cin>>numTaxi;
        			
        			if (numTaxi >= 1 && numTaxi <= 10){
        				
        				if (taxis[numTaxi-1] != "Livre"){
        					taxis[numTaxi-1] = "Livre";
        					numTaxisOcupados--;
        					cout<<"O taxi foi libertado com sucesso!"<<endl;
						}
						else{
							cout<<"O taxi j� est� livre!"<<endl;
						}
					}
					else 
		           {
			           cout<<"N�mero de taxi inv�lido!"<<endl;
			           cout<<"Os taxis v�o de 1 a 10"<<endl;          
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
