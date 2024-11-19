#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    string videoProjetores[4];
    string salas [10];
    
    bool sair = false;
    char opcao = '\0';
    bool videoProjetoresOcupados = false;
    int numEspacosOcupados = 0;
    
    videoProjetores[0] = "VideoA";
    videoProjetores[1] = "VideoB";
    videoProjetores[2] = "VideoC";
    videoProjetores[3] = "VideoD";
	
	for (int i = 0; i < 10; i++){
		salas[i] = "Vazia";
    }

do {
    system ("cls");
    cout<<"********************************************"<<endl;
    cout<<"*             Sala Audiovisual             *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*        1 - Listar Videoprojetor.         *"<<endl;
    cout<<"*        2 - Requisitar Videoprojetor.     *"<<endl;
    cout<<"*        3 - Devolver Videoprojetor.       *"<<endl;
    cout<<"*        0 - Sair.                         *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    if (videoProjetoresOcupados)
	   {
	   cout<<"***************************************"<<endl;
	   cout<<"*                                     *"<<endl;
	   cout<<"* Não há Videoprojetores Disponíveis! *"<<endl;
	   cout<<"*                                     *"<<endl;  
	   cout<<"***************************************"<<endl;                 
	   };
    
    cout<<"Insira a opcao que quer: "<<endl;
    cin>>opcao;
    
    switch (opcao){
           
            case '1':	
	   			for (int i = 0; i < 10; i++){
			        cout<<"Sala "<<i+1<<" -> "<<salas[i]<<endl;
    			}
				system("pause");
	            break;
				
           
            case '2':{
            	int escolha1 = 0;
            	int escolha2 = 0;
            	
            	cout<<"-> Requisitar Videoprojetor: "<<endl; 
            	cout<<"Qual o videoprojetor que quer requisitar (1, 2, 3, 4)?"<<endl;
            	cin>>escolha1;
            	cout<<"Qual a sala para colocar o projetor (1-10)?"<<endl;
            	cin>>escolha2;
            	
            	
            	if (escolha2 >= 1 && escolha2 <= 4 || escolha2 >= 1 && escolha2 <= 10){
					if (salas[escolha2-1] == "Vazia"){
						salas[escolha2-1] = videoProjetores[escolha1-1];
					}
					else if(salas[escolha2-1] != "Vazia"){
						cout<<"Videoprojetor já requisitado"<<endl;
					}
					else{
						cout<<"Sala já tem um videoprojetor!"<<endl;
					}
				}
				else{
					cout<<"Insira uma opção correta."<<endl;
				}
				
			cout<<endl;
			system("pause");
			break;
			}
			
        	case '3':{
            int escolha = 0;

            cout << "-> Devolver Videoprojetor: " << endl;
            cout << "Qual a sala a que pertence o videoprojetor? (1-10)?" << endl;
            cin >> escolha;

            if (escolha >= 1 && escolha <= 10) {
                if (salas[escolha - 1] != "Vazia") {
                    cout << "Videoprojetor " << salas[escolha - 1] << " devolvido." << endl;
                    salas[escolha - 1] = "Vazia";
                    numEspacosOcupados--;
                    videoProjetoresOcupados = false;
                } else {
                    cout << "Não há videoprojetor nesta sala." << endl;
                }
            } else {
                cout << "Opção inválida!" << endl;
            }

            cout << endl;
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
