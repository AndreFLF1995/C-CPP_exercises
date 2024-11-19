#include <iostream>
#include <string>
#include <stdlib.h>
#include <locale.h>
#include <iomanip>
using namespace std;

namespace Classes
{
 namespace ClassePrincipal
 {
        class Produto
        {
              int codigoProduto;
              string designacao;
              float quantidade;
              int nrUnidades;
              float precoAtual;
              string dataValidade;
              string seccao;
              float precoIVA;
              static int produto;
              
              public:
                 Produto()
                 {
                    produto++;
                    cout<<endl<<endl<<"Produto "<<produto<< " construido!"<<endl<<endl;         
                    codigoProduto = 0;
                    designacao = "";
                    quantidade = 0;
                    nrUnidades = 0;
                    precoAtual = 0;        
                    dataValidade = "";
                    seccao = "";
                    precoIVA = 0;
                 }
                 
                 ~Produto()
                 {
                    cout<<endl<<"Produto "<<produto<<" descontruido"<<endl;
                    produto--;
                 }
                 
                           
        // ---------------------------------------------
              void set_codigoProduto (int cp)
              {
                   codigoProduto = cp;
              }
              
              void set_designacao (string des)
              {
                   designacao = des;
              }
              
              void set_quantidade (float qtd)
              {
                   quantidade = qtd;
              }
              
              void set_nrUnidades (int nrU)
              {
                   nrUnidades = nrU;
              }
              
              void set_precoAtual (float prA)
              {
                   precoAtual = prA;
              }
              
              void set_dataValidade (string dataV)
              {
                   dataValidade = dataV;
              }
              
              void set_seccao (string sc)
              {
                   seccao = sc;
              }
              
              void set_produto(int prod)
              {
                   produto = prod;
              }
        //------------------------------------------
              
              int get_codigoProduto ()
              {
                   return codigoProduto;
              }
              
              string get_designacao ()
              {
                   return designacao;
              }
              
              float get_quantidade ()
              {
                   return quantidade;
              }
              
              int get_nrUnidades ()
              {
                   return nrUnidades;
              }
              
              float get_precoAtual ()
              {
                   return precoAtual;
              }
              
              string get_dataValidade ()
              {
                   return dataValidade;
              }
              
              string get_seccao ()
              {
                   return seccao;
              }
              
              int get_produto ()
              {
                   return produto; 
              }
              
              static int get_produto2 ()
              {
                   return produto; 
              }
        // --------------------------------------
              
              void le_codigoProduto ()
              {
                   int cp = 0;
                   cout<<"Insira o código do produto: ";
                   cin>>cp;
                   set_codigoProduto(cp);
              }
              
              void le_designacao ()
              {
                   string des = "";
                   cout<<"Insira a designação do produto: ";
                   cin>>des;
                   set_designacao(des);
              }
              
              void le_quantidade ()
              {
                   float qtd = 0;
                   cout<<"Insira a quantidade que deseja: ";
                   cin>>qtd;
                   set_quantidade(qtd);
              }
              
              void le_nrUnidades ()
              {
                   int nrU = 0;
                   cout<<"Insira o numero de unidades que deseja: ";
                   cin>>nrU;
                   set_nrUnidades(nrU);
              }
              
              void le_precoAtual ()
              {
                   float prA = 0;
                   cout<<"Insira o preço atual do produto: ";
                   cin>>prA;
                   set_precoAtual(prA);
              }
              
              void le_dataValidade ()
              {
                   string dataV = "";
                   cout<<"Insira a data de validade do produto: ";
                   cin>>dataV;
                   set_dataValidade(dataV);
              }
              
              void le_seccao ()
              {
                   string sc = "";
                   cout<<"Insira a secção cujo produto pertence: ";
                   cin>>sc;
                   set_seccao(sc);
              }
              
        // -------------------------------------------------
        
              void mostra_codigoProduto()
              {
                   cout<<"Código             : "<<get_codigoProduto()<<endl;
              }
              
              void mostra_designacao()
              {
                   cout<<"Designação         : "<<get_designacao()<<endl;
              }
              
              void mostra_quantidade()
              {
                   cout<<"Quantidade         : "<<fixed<<setprecision(2)<<get_quantidade()<<endl;
              }
              
              void mostra_nrUnidades()
              {
                   cout<<"Número de Unidades : "<<get_nrUnidades()<<endl;
              }
              
              void mostra_precoAtual()
              {
                   cout<<"Preço atual        : "<<fixed<<setprecision(2)<<get_precoAtual()<<endl;
              }
              
              void mostra_dataValidade()
              {
                   cout<<"Data de Validade   : "<<get_dataValidade()<<endl;
              }
              
              void mostra_seccao()
              {
                   cout<<"Secção             : "<<get_seccao()<<endl;
              }
              
              void mostra_produto()
              {
                   cout<<"Produto nº         : "<<get_produto()<<endl;
              }
              
              Produto operator-(const Produto& p) 
                {
                    Produto produtoResultante;
                       	
                    produtoResultante.nrUnidades = this->nrUnidades - p.nrUnidades;	
                    produtoResultante.precoAtual = this->precoAtual - p.precoAtual;
                    return produtoResultante;	
                }
                
                Produto operator+(const Produto& p) 
                {
                    Produto produtoResultante;
                       	
                    produtoResultante.nrUnidades = this->nrUnidades + p.nrUnidades;	
                    produtoResultante.precoAtual = this->precoAtual + p.precoAtual;
                    return produtoResultante;	
                }
                
                 
                bool operator> (const Produto& p) 
                {
                       return (this->precoAtual > p.precoAtual);
                }	 
                
                bool operator< (const Produto& p) 
                {
                       return (this->precoAtual < p.precoAtual);
                }	
                
                bool operator== (const Produto& p) 
                {
                       return (this->precoAtual == p.precoAtual);
                }
        };
    }
    
    namespace ClassesDerivadas
    {
    
        class ProdutoElectrodomestico: public Classes::ClassePrincipal::Produto
        {
              int potencia, garantia;
              string classe;
              bool temPilhas;
              float autonomia;
              
              public:
              ProdutoElectrodomestico(): Produto()
              {
               potencia = 0;
               garantia = 0;
               classe = "";
               temPilhas = false;
               autonomia = 0;
               cout<<"Eletrodoméstico Criado!"<<endl;
              }
              
              ~ProdutoElectrodomestico()
              {
               cout<<"Electrodoméstico eliminado.";
              }
              
        // ---------------------------------------------
              void set_potencia (int pt)
              {
                   potencia = pt;
              }
              
              void set_garantia (int grt)
              {
                   garantia = grt;
              }
              
              void set_classe (string cls)
              {
                   classe = cls;
              }
              
              void set_temPilhas (bool tp)
              {
                   temPilhas = tp;
              }
              
              void set_autonomia (float at)
              {
                   autonomia = at;
              }
              
        //------------------------------------------
              
              int get_potencia()
              {
                   return potencia;
              }
              
              string get_classe ()
              {
                   return classe;
              }
              
              bool get_temPilhas ()
              {
                   return temPilhas;
              }
              
              int get_garantia ()
              {
                   return garantia;
              }
              
              float get_autonomia ()
              {
                   return autonomia;
              }
        
        // --------------------------------------
              
              void le_potencia()
              {
                   int pt = 0;
                   cout<<"Insira a potência do produto: ";
                   cin>>pt;
                   set_potencia(pt);
              }
              
              void le_classe()
              {
                   string cls = "";
                   cout<<"Insira a classe do produto: ";
                   cin>>cls;
                   set_classe(cls);
              }
              
              void le_temPilhas()
              {
                   bool tp = false;
                   char escolha = '\0';
                   cout<<"O produto vem com pilhas? (S/N): ";
                   cin>>escolha;
                   
                   if (escolha == 'S' || escolha == 's')
                   {
                      tp = true;
                   }
                   set_temPilhas(tp);
              }
              
              void le_garantia()
              {
                   int grt = 0;
                   cout<<"Insira o numero de unidades que deseja: ";
                   cin>>grt;
                   set_garantia(grt);
              }
              
              void le_autonomia()
              {
                   float at = 0;
                   cout<<"Insira a autonomia do produto: ";
                   cin>>at;
                   set_autonomia(at);
              }
              
        // -------------------------------------------------
        
              void mostra_potencia()
              {
                   cout<<"Potência    : "<<get_potencia()<<" watts."<<endl;
              }
              
              void mostra_classe()
              {
                   cout<<"Classe      : "<<get_classe()<<endl;
              }
              
              void mostra_autonomia()
              {
                   cout<<"Autonomia   : "<<fixed<<setprecision(2)<<get_autonomia()<<" horas."<<endl;
              }
              
              void mostra_temPilhas()
              {
                   cout<<"Tem pilhas? : ";
                   if(get_temPilhas()) cout<<" Sim."<<endl;
                   else cout<<" Não."<<endl;
              }
              
              void mostra_garantia()
              {
                   cout<<"Garantia    : "<<get_garantia()<<" meses."<<endl;
              }
        };
    }
}

int Classes::ClassePrincipal::Produto::produto = 0;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    Classes::ClassesDerivadas::ProdutoElectrodomestico produto;
    
    produto.le_potencia();
    produto.le_classe();
    produto.le_temPilhas();
    produto.le_garantia();
    produto.le_autonomia();
    
    produto.mostra_potencia();
    produto.mostra_classe();
    produto.mostra_temPilhas();
    produto.mostra_garantia();
    produto.mostra_autonomia();
    
    
    system("pause");
    return 0;
}

void precoIVA(float prA)
{
    float precoIVA = 0;
    string IVA = "";
    bool ok = false;
    
    do{
        cout<<endl<<"Insira o IVA a aplicar (6, 13, 23): ";
        cin>>IVA;
    
        if (IVA == "6")
        {
         precoIVA = prA * 1.06;
         ok = true;
        }
        else if (IVA == "13")
        {
         precoIVA = prA * 1.13;
         ok = true;
        }
        else if (IVA == "23")
        {
         precoIVA = prA * 1.23;
         ok = true;
        }
        else
        {
         cout<<"Insira um valor correto: 6, 13, 23"<<endl<<endl;
        }
    }while (ok = false);
    
    cout<<"Preço com IVA      : "<<precoIVA<<endl;
}
