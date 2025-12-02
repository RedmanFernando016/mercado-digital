#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <vector>
using namespace std;

struct usuario{
    string nome;
    string senha;
    string endereco;
};

void cadastro(string &nome, string &senha, string &endereco, vector<usuario> &usuarios);
bool login(vector<usuario> &usuarios, string &nome, string &senha);

#endif