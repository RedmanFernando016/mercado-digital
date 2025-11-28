#ifndef CARRINHO_H
#define CARRINHO_H
#include "produtos.h"

void adicionar(const vector<item> &produtos, vector<item> &carrinho, const string &nome);
void remover(vector<item> &carrinho, const string &nome);
void limpar(vector<item> &carrinho);
void itens(const vector<item> &produtos);
void itens_carrinho(const vector<item> &carrinho);

#endif 