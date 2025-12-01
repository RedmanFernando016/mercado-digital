#ifndef PRODUTOS_H
#define PRODUTOS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct item{
    string nome;
    double valor;
    int codigo;
    int quantidade = 0;
};

void carregar_csv(const string &itens_mercado_csv, vector<item> &produtos);

#endif