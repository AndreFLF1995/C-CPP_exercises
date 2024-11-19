#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    string lugares[7][5];
    bool sair = false;
    char opcao = '\0';
    bool lugaresOcupados = false;
    int numLugaresOcupados = 0;
    
    for (int i = 0; i < 7; i++){
        for (int j = 0; j < 5; j++){
        lugares[i][j] = "Livre";    
    	}   
    }


do {
    system ("cls");
    cout<<"********************************************"<<endl;
    cout<<"*                 Cinemacity               *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*            1 - Listar Lugares.           *"<<endl;
    cout<<"*            2 - Reservar Lugar.           *"<<endl;
    cout<<"*            3 - Marcar Lugar.             *"<<endl;
    cout<<"*            4 - Libertar Lugar.           *"<<endl;
    cout<<"*            0 - Fim de Sessão.            *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    if (lugaresOcupados)
	   {
	   cout<<"**************************************"<<endl;
	   cout<<"*                                    *"<<endl;
	   cout<<"*      Não há Lugares Disponíveis    *"<<endl;
	   cout<<"*                                    *"<<endl;  
	   cout<<"**************************************"<<endl;                 
	   };
    
    cout<<"Insira a opcao que quer: "<<endl;
    cin>>opcao;
    
    switch (opcao){
           
           case '1':	
	   			for (int i = 0; i < 7; i++){
					for (int j = 0; j < 5; j++){
					cout<<"Lugar "<<i+1<<j+1<<" -> "<<lugares[i][j]<<endl;
					}
				}
				system("pause");
	            break;
				
           
            case '2':
           		if (!lugaresOcupados){
					int numFila = 0;
					int numLugar = 0;
        			cout<<" -> Reservar lugar: "<<endl;    
        			cout<<"Qual é o lugar a reservar? Fila de 1 a 7, lugar de 1 a 5."<<endl<<"Ex. 15"<<endl;
        			cout<<"Fila: ";
        			cin>>numFila;
        			cout<<"Lugar: ";
					cin>>numLugar;
        			
        			if (numFila >= 1 && numFila <= 7 || numLugar >= 1 && numLugar <= 5){
        				if (lugares[numFila-1][numLugar-1] == "Livre"){
        					lugares[numFila-1][numLugar-1] = "Reservado";
        					cout<<"O lugar foi reservado com sucesso!"<<endl;
        					numLugaresOcupados++;
        					if (numLugaresOcupados == 10){
        						lugaresOcupados = true;
							}
						}
						else{
							cout<<"O lugar já está reservado ou foi marcado!"<<endl;
						}
					}
					else 
		           {
			           cout<<"Número de lugar inválido!"<<endl;
			           cout<<"Os lugares vão de 1 a 10"<<endl;          
		           }
				cout<<endl;
				system("pause");
                break;
        		}
                    
           case '3':
				if (!lugaresOcupados){
					int numFila = 0;
					int numLugar = 0;
        			cout<<" -> Marcar lugar: "<<endl;    
        			cout<<"Qual é o lugar a marcar? Fila de 1 a 7, lugar de 1 a 5."<<endl<<"Ex. 15"<<endl;
        			cout<<"Fila: ";
        			cin>>numFila;
        			cout<<"Lugar: ";
					cin>>numLugar;
        			
        			if (numFila >= 1 && numFila <= 7 || numLugar >= 1 && numLugar <= 5){
        				
        				if (lugares[numFila-1][numLugar-1] == "Livre"){
        					lugares[numFila-1][numLugar-1] = "Marcado";
        					cout<<"O lugar foi marcado com sucesso!"<<endl;
        					numLugaresOcupados++;
						}
						else{
							cout<<"O lugar já está reservado ou foi marcado!"<<endl;
						}
					}
					else 
		           {
			           cout<<"Número de lugar inválido!"<<endl;
			           cout<<"Os lugares vão de 1 a 10"<<endl;          
		           }
				cout<<endl;
				system("pause");
                break;
        		}
           
           case '4':
				if (!lugaresOcupados){
					int numFila = 0;
					int numLugar = 0;
        			cout<<" -> Libertar lugar: "<<endl;    
        			cout<<"Qual é o lugar a libertar? Fila de 1 a 7, lugar de 1 a 5."<<endl<<"Ex. 15"<<endl;
        			cout<<"Fila: ";
        			cin>>numFila;
        			cout<<"Lugar: ";
					cin>>numLugar;
        			
        			if (numFila >= 1 && numFila <= 7 || numLugar >= 1 && numLugar <= 5){
        				
        				if (lugares[numFila-1][numLugar-1] != "Livre"){
        					lugares[numFila-1][numLugar-1] = "Livre";
        					numLugaresOcupados--;
        					cout<<"O lugar foi libertado com sucesso!"<<endl;
						}
						else{
							cout<<"O lugar já está livre!"<<endl;
						}
					}
					else 
		           {
			           cout<<"Número de lugar inválido!"<<endl;
			           cout<<"Os lugares vão de 1 a 10"<<endl;          
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

