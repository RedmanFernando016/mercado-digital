#include "produtos.h"

void carregar_csv(const string &itens_mercado_csv, vector<item> &produtos){
    ifstream arquivo(itens_mercado_csv);
    if (!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo! Reinicie o programa! " << endl;
        return;
    };

    string linha;
    getline(arquivo, linha);

    while(getline(arquivo, linha)){
        stringstream ss(linha);
        string nome, valor_str, codigo_str;

        getline(ss, nome, ';');
        getline(ss, valor_str, ';');
        getline(ss, codigo_str, ';');

        item produto;
        produto.nome = nome;
        produto.valor = stof(valor_str);
        produto.codigo = stoi(codigo_str);

        produtos.push_back(produto);
    }

    arquivo.close();
};

