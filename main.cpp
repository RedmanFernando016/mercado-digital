#include <iostream> 
#include <locale>
#include "produtos.h"
#include "carrinho.h"
#include <windows.h>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(){
    try {
        std::locale::global(std::locale("pt_BR.UTF-8")); // Linux/mac
    } catch(...) {
        try { std::locale::global(std::locale("Portuguese_Brazil")); } catch(...) {}
    }
        cout.imbue(std::locale());
    #ifdef _WIN32
        system("chcp 65001 > nul");
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    string itens_mercado_csv = "itens_mercado.csv";
    vector<item> produtos;
    vector<item> carrinho;
    carregar_csv(itens_mercado_csv, produtos);
    

    char escolha;

    cout << " ----- Bem vindo a loja virtual ----- " << endl;

    do{
        cout << "O que gostaria de realizar? " << endl;
        cout << "1 - Produtos" << endl;
        cout << "2 - Saldo" << endl;
        cout << "3 - ofertas" << endl;
        cout << "4 - carrinho" << endl;
        cin >> escolha;
        
        switch(escolha){
            case '1':{
                cout << "            ------ PRODUTOS EM ESTOQUE ------\n" << "-------------------------------------------------------------\n";
                itens(produtos);
                cout << "-------------------------------------------------------------\n";
                break;
            }

            case '2': {
                

                break;
            }

            case '3': {

                break;
            }
            case '4': {
                cout << "---- MEU CARRINHO ----" << endl;
                itens_carrinho(carrinho);

                do {
                    cout <<" 1 -  Adicionar item\n";
                    cout <<" 2 -  Remover item\n";
                    cout <<" 3 -  Limpar carrinho\n";
                    cout <<" 4 -  Voltar ao menu principal\n";
                    cin >> escolha;

                    switch(escolha){
                        case '1':{

                        }
                        case '2':{

                        }
                        case '3':{

                        }
                        case '4':{
                            
                        }
                    }
                }
            }
        }   
        
    } while (escolha <= '4' && escolha >= '1');




    return 0;
}