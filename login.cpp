#include "login.h"
#include <iostream>
#include <vector>
using namespace std;

void cadastro(string &nome, string &senha, string &endereco, vector<usuario> &usuarios){
    char escolha;

    cout << "\n----- CADASTRO DE USUARIO -----\n" << endl;
    cin.ignore();
    cout << "Digite seu Nome: " << endl;
    getline(cin, nome);
    cout << "Digite uma senha: " << endl;
    getline(cin, senha);
    cout << "Digite seu endereço: " << endl;
    getline(cin, endereco);
    cout << "Verifique as informações.\nNome:" << nome << "\nSenha:" << senha << "\nEndereço: " << endereco << endl;
    cout << "Deseja alterar alguma informação? (S/N)";
    cin >> escolha;

    if(escolha == 's' || escolha == 'S'){
        cout << "Qual?\n1- Nome.\n2- Senha\n3- Endereço";
        cin >> escolha;

        switch(escolha){
            case '1':
                cout << "Digite o nome: " << endl;
                cin >> nome;
                break;
            case '2':
                cout << "Digite a senha: " << endl;
                cin >> senha;
                break;
            case '3':
                cout << "Digite o endereço: " << endl;
                cin >> endereco;
                break;
            default:{
                cout << "Opção inválida! " << endl;
                return;
            }
        }
    } else if (escolha == 'n' || escolha == 'N'){
        cout << "Cadastro realizado com sucesso! " << endl;
    } else {
        cout << "Opção inválida! " << endl;
        return;
    }

    usuario novousuario = {nome, senha, endereco};
    usuarios.push_back(novousuario);
    return;
}

bool login(vector<usuario> &usuarios, string &nome, string &senha){
    
    cout << "Digite o seu nome: " << endl;
    cin >> nome;
    cout << "Digite a sua senha: " << endl;
    cin >> senha;

    for(int i = 0; i < usuarios.size(); i++){
        if(nome == usuarios[i].nome && senha == usuarios[i].senha){

            cout << "Bem vindo " << nome << endl;
            return true;
        }
    }
    cout << "Usuário ou senha incorreto! Tente novamente. " << endl;
    return false; 
}