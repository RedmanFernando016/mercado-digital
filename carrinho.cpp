#include "carrinho.h"
#include <locale>
#include <cwctype>
#include <cctype>
#include <limits>


static string normalize_text(const string &s) {
    string out;
    out.reserve(s.size());
    for (size_t i = 0; i < s.size(); ) {
        unsigned char c = (unsigned char)s[i];
        if (c < 0x80) {
            out.push_back((char)std::tolower(c));
            i++;
        } else if (c == 0xC3 && i + 1 < s.size()) {
            unsigned char d = (unsigned char)s[i+1];
            char mapped = 0;
            // A/a com acento
            if (d==0x81||d==0x80||d==0x82||d==0x83||d==0x84|| d==0xA1||d==0xA0||d==0xA2||d==0xA3||d==0xA4) mapped='a';
            // E/e com acento
            else if (d==0x89||d==0x88||d==0x8A||d==0x8B|| d==0xA9||d==0xA8||d==0xAA||d==0xAB) mapped='e';
            // I/i com acento
            else if (d==0x8D||d==0x8C||d==0x8E||d==0x8F|| d==0xAD||d==0xAC||d==0xAE||d==0xAF) mapped='i';
            // O/o com acento
            else if (d==0x93||d==0x92||d==0x94||d==0x95||d==0x96|| d==0xB3||d==0xB2||d==0xB4||d==0xB5||d==0xB6) mapped='o';
            // U/u com acento
            else if (d==0x9A||d==0x99||d==0x9B||d==0x9C|| d==0xBA||d==0xB9||d==0xBB||d==0xBC) mapped='u';
            // C/ç
            else if (d==0x87 || d==0xA7) mapped='c';

            if (mapped) out.push_back(mapped);
            i += 2; // consumir os dois bytes da letra acentuada
        } else if (c >= 0xC2 && c <= 0xDF) {
            i += 2; // ignora outros dois-bytes
        } else if (c >= 0xE0 && c <= 0xEF) {
            i += 3; // ignora três-bytes
        } else if (c >= 0xF0 && c <= 0xF4) {
            i += 4; // ignora quatro-bytes
        } else {
            i++; // byte inválido
        }
    }
    return out;
}

void adicionar(const vector<item> &produtos, vector<item> &carrinho, const string &nome){
    bool encontrado = false;
    string nomes;
    int quantidade;

    cout << "Digite o nome do produto que deseja adicionar ao carrinho: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nomes);

    for(int i = 0; i < produtos.size(); i++){
        if(normalize_text(produtos[i].nome) == normalize_text(nomes)){
            cout << "Digite a quantidade que deseja: " << endl;
            cin >> quantidade;
            if(quantidade <= 0){
                cout << "Quantidade inválida! Adição cancelada! \n" << endl;
                return;
            }
            carrinho.push_back(produtos[i]);
            carrinho.back().quantidade = quantidade;
            cout << "Produto: " << produtos[i].nome << ", " << quantidade << " adicionado ao carrinho com sucesso! \n" << endl;
            encontrado = true;
            break;
        }
    }

    if(!encontrado){
        cout << "Produto " << nomes << " não encontrado! verifique a ortografia e tente novamente! \n" << endl;
        return;
    }
}

void remover(vector<item> &carrinho, const string &nome){
    bool encontrado = false;
    string nomes;
    int indice = 0;
    char escolha; 
    cout << "Digite o nome do produto que deseja remover do carrinho: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nomes);

    for(int i = 0; i < carrinho.size(); i++){
        if(normalize_text(carrinho[i].nome) == normalize_text(nomes)){
            encontrado = true;
            indice = i;
            break;
        }
    }

    if(!encontrado){
        cout << "Produto " << nomes << " não encontrado, verifique se o mesmo se encontra em seu carrinho! " << endl;
        return;
    }

    cout << "Deseja remover todas as quantidades do " << nomes << "? (s/n) " << endl;
    cin >> escolha; 
    
    if(escolha == 's' || escolha == 'S'){
        cout << "Produto: " << nomes << " Removido do carrinho! " << endl;
        carrinho.erase(carrinho.begin() + indice);
        return;
    } else if(escolha == 'n' || escolha == 'N'){
        int remocao;

        cout << "Digite a quantidade que deseja remover do seu carrinho: " << endl;
        cin >> remocao;

        if(remocao > carrinho[indice].quantidade){
            cout << "Quantidade maior do que a disponivel no carrinho! Remoção cancelada" << endl;
            return;
        } else {
            carrinho[indice].quantidade -= remocao;
            cout << "Quantidade removida!" << endl;
            
            if(carrinho[indice].quantidade == 0){
                carrinho.erase(carrinho.begin() + indice);
            }
        }
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
        cout << "Valor: R$" << produtos[i].valor << endl;
    }
}

//função para itens do carrinho
void itens_carrinho(const vector<item> &carrinho){
    string nome;
    if(carrinho.size() == 0){
        cout << "Carrinho vazio! " << endl;
        return;
    }

    for(int i = 0; i <= carrinho.size() - 1; i++){
        cout << "| Produto: " << carrinho[i].nome << ", " << carrinho[i].quantidade << " Unidades" << " --> " << "Valor porm item R$" << carrinho[i].valor << " |" << endl;
    }
}