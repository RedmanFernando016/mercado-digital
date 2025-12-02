#include <iostream> 
#include <locale>
#include "produtos.h"
#include "carrinho.h"
#include "login.h"
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
    vector<usuario> usuarios;
    carregar_csv(itens_mercado_csv, produtos);
    

    char escolha;
    bool autenticado = false;

    cout << "\n ----- Bem vindo a loja virtual ----- \n" << endl;
    do{
        cout << "1 - Cadastrar" << endl;
        cout << "2 - Login" << endl;
        cout << "3 - Visitante" << endl;
        cin >> escolha;

        switch(escolha){
            case '1': {
                string nomea, senhaa, enderecoa;
                cadastro(nomea, senhaa, enderecoa, usuarios);
                break;
            }

            case '2':{
                string nomea, senhaa;
                if(login(usuarios, nomea, senhaa)){
                    autenticado = true;
                }
                break;
            }

            case '3':{
                cout << "Acessando como visitante! " << endl;
                autenticado = true;
                break;
            }

            default:{
                cout << "Opção inválida! Tente novamente. " << endl;
                break;
            }
        }
    } while(autenticado == false);

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
                do {
                    cout << "---- MEU CARRINHO ----" << endl;
                    itens_carrinho(carrinho);
                    cout << "----------------------\n" << endl;
                    cout <<" 1 -  Adicionar item\n";
                    cout <<" 2 -  Remover item\n";
                    cout <<" 3 -  Limpar carrinho\n";
                    cout <<" 4 -  Voltar ao menu principal\n";
                    cin >> escolha;

                    switch(escolha){
                        case '1':{
                            string produto;
                            adicionar(produtos, carrinho, produto);  
                            break;
                        }
                        case '2':{
                            string produto;
                            remover(carrinho, produto);
                            break;
                        }
                        case '3':{
                            limpar(carrinho);
                            break;
                        }
                        case '4':{
                            break;
                        }
                    }
                } while(escolha <= '3');
            }
        }   
    } while (escolha <= '4' && escolha >= '1');

    return 0;
}