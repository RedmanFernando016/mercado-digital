#include "carrinho.h"

void adicionar(const vector<item> &produtos, vector<item> &carrinho, const string &nome){
    bool encontrado = false;

    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].nome == nome){
            carrinho.push_back(produtos[i]);
            cout << "Produto: " << produtos[i].nome << " adicionado ao carrinho com sucesso! " << endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        cout << "Produto " << nome << " não encontrado! verifique a ortografia e tente novamente! " << endl;
        return;
    }
}

void remover(vector<item> &carrinho, const string &nome){
    bool encontrado = false;
    
    for(int i = 0; i < carrinho.size(); i++){
        if(carrinho[i].nome == nome){
            cout << "Produto: " << nome << " Removido do carrinho! " << endl;
            carrinho.erase(carrinho.begin() + i);
            encontrado = true;
            break; 
        }
    }
    if(!encontrado){
        cout << "Produto " << nome << " não encontrado, verifique se o mesmo se encontra em seu carrinho! " << endl;
        return;
    }
}

void limpar(vector<item> &carrinho){
    while(carrinho.size() > 0){
        carrinho.erase(carrinho.begin());
    }
    cout << "Itens removidos do carrinho!" << endl;
    return;
}

//função para lista dos itens da loja 
void itens(const vector<item> &produtos){
    for(int i = 0; i < produtos.size(); i++){
        cout << "| Nome: " << produtos[i].nome << " --> ";
        cout << "Valor: R$" << produtos[i].valor << " --> ";
        cout << "Código: " << produtos[i].codigo << endl; 
    }
}

//função para itens do carrinho
void itens_carrinho(const vector<item> &carrinho){
    string nome;
    if(carrinho.size() == 0){
        cout << "Carrinho vazio! " << endl;
        return;
    }

    while(carrinho.size() != 0){
        cout << "| Nome: " << carrinho[0].nome << " --> " << "Valor R$" << carrinho[0].valor << " |\n";
    }
}