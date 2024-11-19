#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    const int NUMPRODUTOS = 10;
    
    string nomeProduto[NUMPRODUTOS];
    int qtdProduto[NUMPRODUTOS];
    float precoProduto[NUMPRODUTOS];
    
    bool sair = false;
    char opcao = '\0';
    bool espacosOcupados = false;
    int numEspacosOcupados = 0;
    
    for (int i = 0; i < 10; i++){
        nomeProduto[i] = "Vazio";
		qtdProduto[i] = 0;
		precoProduto[i] = 0;
    }


do {
    system ("cls");
    cout<<"********************************************"<<endl;
    cout<<"*                 Armazém CTT              *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    cout<<"********************************************"<<endl;
    cout<<"*            1 - Listar Produto.           *"<<endl;
    cout<<"*            2 - Inserir Produto.          *"<<endl;
    cout<<"*            3 - Alterar Preço.            *"<<endl;
    cout<<"*            4 - Registar Venda.           *"<<endl;
    cout<<"*            5 - Registar Reposição.       *"<<endl;
    cout<<"*            6 - Eliminar Produto.         *"<<endl;
    cout<<"*            0 - Sair.                     *"<<endl;
    cout<<"********************************************"<<endl;
    cout<<endl;
    if (espacosOcupados)
	   {
	   cout<<"**************************************"<<endl;
	   cout<<"*                                    *"<<endl;
	   cout<<"*      Não há Espaco Disponível!     *"<<endl;
	   cout<<"*                                    *"<<endl;  
	   cout<<"**************************************"<<endl;                 
	   };
    
    cout<<"Insira a opcao que quer: "<<endl;
    cin>>opcao;
    
    switch (opcao){
           
            case '1':	
	   			for (int i = 0; i < 10; i++){
			        cout<<i+1<<" |Produto: "<<nomeProduto[i]<<endl;
					cout<<"  |Quantidade: "<<qtdProduto[i]<<endl;
					cout<<"  |Preço: "<<precoProduto[i]<<endl;
					cout<<endl;
    			}
				system("pause");
	            break;
				
           
            case '2':
           		if (!espacosOcupados){
					string produto = "";
					int quantidade = 0;
					float preco = 0;
					bool saida = true;
					char s_n = 'n';
					int posicao = 0;
					
					do{
						cout<<"-> Inserir produto: "<<endl;    
	        			cout<<"Qual é o produto a inserir?"<<endl;
	        			cin>>produto;
	        			cout<<"Qual é quantidade a guardar (em unidades)?"<<endl;
	        			cin>>quantidade;
	        			cout<<"Qual é o preço por unidade (em euros)?"<<endl;
						cin>>preco;
						cout<<"Em que espaco quer inserir (1-10)?"<<endl;
						cin>>posicao;
						numEspacosOcupados++;
						
						
						if (posicao < 1 || posicao > 10){
							cout<<"Espaço fora de limites! De 1 a 10 por favor."<<endl;
						}
						else{
							if (nomeProduto[posicao-1] == "Vazio"){
								nomeProduto[posicao-1] = produto;
							}
							else{
								cout<<"Espaço já utilizado. Use a função certa para eliminar!"<<endl;
								break;
							}
							if (qtdProduto[posicao-1] == 0){
								qtdProduto[posicao-1] = quantidade;
							}
							else{
								cout<<"Espaço já utilizado. Use a função certa para eliminar!"<<endl;
								break;
							}
							if (precoProduto[posicao-1] == 0){
								precoProduto[posicao-1] = preco;
							}
							else{
								cout<<"Espaço já utilizado. Use a função certa para eliminar!"<<endl;
								break;
							}
						}
						
						
						if (numEspacosOcupados == 10){
        						espacosOcupados = true;
        						break;
							}
	        			
	        			cout<<"Quer inserir mais um produto?"<<endl;
	        			cin>>s_n;
        				
	        				if (s_n == 's'){
	        					saida = false;
							}
							else{
								saida = true;
							}
							
					} while (!saida);
        			
					cout<<endl;
					system("pause");
	                break;
        		}
        		else{
					   cout<<"**************************************"<<endl;
					   cout<<"*                                    *"<<endl;
					   cout<<"*      Não há Espaco Disponível!     *"<<endl;
					   cout<<"*                                    *"<<endl;
					   cout<<"**************************************"<<endl;        
					}
        
        	case '3':{
        		int posicao = 0;
        		float preco = 0;
        		
	           	cout<<"-> Alterar Preço: "<<endl;
	           	cout<<"Em que espaco quer fazer a alteração (1-10)?"<<endl;
				cin>>posicao;
			
				if (posicao < 1 || posicao > 10){
					cout<<"Espaço fora de limites! De 1 a 10 por favor."<<endl;
					break;
				}
				else if (nomeProduto[posicao-1] == "Vazio") {
					cout<<"Este espaço não tem produto."<<endl;
				}
				else{
					cout<<"Qual é o novo preço por unidade (em euros)?"<<endl;
					cin>>preco;
					precoProduto[posicao-1] = preco;
				}
			cout<<endl;
			system("pause");
            break;
        	}
        	
        	case '4':{
        		int quantidade = 0;
        		int posicao = 0;
        		
        		cout<<"-> Registar venda: "<<endl;
        		
        		for (int i = 0; i < 10; i++){
			        cout<<i+1<<" |Produto: "<<nomeProduto[i]<<endl;
					cout<<"  |Quantidade: "<<qtdProduto[i]<<endl;
					cout<<"  |Preço: "<<precoProduto[i]<<endl;
					cout<<endl;
    			}
    			
    			cout<<"Qual o produto quer vender (1-10)?"<<endl;
    			cin>>posicao;
    			cout<<"Qual a quantidade que quer vender?"<<endl;
    			cin>>quantidade;
    			
    			if (nomeProduto[posicao-1] == "Vazio") {
					cout<<"Este espaço não tem produto."<<endl;
				}
    			else if (quantidade < qtdProduto[posicao-1]){
    				qtdProduto[posicao] -= quantidade;
    				cout<<"Vendeu "<<quantidade<<" do produto "<< nomeProduto[posicao-1]<<" e lucrou "<<precoProduto[posicao-1]*quantidade<<endl;
				}
				else{
					cout<<"Infelizmente não temos essa quantidade."<<endl;
				}
			cout<<endl;
			system("pause");
            break;
			}
			
			case '5':{
        		int quantidade = 0;
        		int posicao = 0;
        		
        		cout<<"-> Registar Reposição: "<<endl;
        		
        		for (int i = 0; i < 10; i++){
			        cout<<i+1<<" |Produto: "<<nomeProduto[i]<<endl;
					cout<<"  |Quantidade: "<<qtdProduto[i]<<endl;
					cout<<"  |Preço: "<<precoProduto[i]<<endl;
					cout<<endl;
    			}
    			
    			cout<<"Qual o produto quer repor (1-10)?"<<endl;
    			cin>>posicao;
    			cout<<"Qual a quantidade que quer repor?"<<endl;
    			cin>>quantidade;
    			
    			if (nomeProduto[posicao-1] == "Vazio") {
					cout<<"Este espaço não tem produto."<<endl;
				}
				else{
					qtdProduto[posicao-1] += quantidade;
					cout<<"Repos "<<quantidade<<" do produto "<< nomeProduto[posicao-1]<<endl;
				}
			cout<<endl;
			system("pause");
            break;
			}
			
			case '6':{
        		int posicao = 0;
        		
        		cout<<"-> Eliminar Produto: "<<endl;
        		
        		for (int i = 0; i < 10; i++){
			        cout<<i+1<<" |Produto: "<<nomeProduto[i]<<endl;
					cout<<"  |Quantidade: "<<qtdProduto[i]<<endl;
					cout<<"  |Preço: "<<precoProduto[i]<<endl;
					cout<<endl;
    			}
    			
    			cout<<"Qual o produto que quer eliminar (1-10)?"<<endl;
    			cin>>posicao;
    			
    			cout<<"Eliminou o produto "<<nomeProduto[posicao-1]<<" com sucesso."<<endl;
    			
    			nomeProduto[posicao-1] = "Vazio";
				qtdProduto[posicao-1] = 0;
				precoProduto[posicao-1] = 0;
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

