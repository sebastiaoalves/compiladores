// GRAMÁTICA A SER IMPLEMENTADA
// PROGRAMA := EXPRESSAO
// EXPRESSAO := TERMO + EXPRESSAO | TERMO - EXPRESSAO | TERMO
// TERMO := 0 | 1 | 2 ... | 9

// INFIXA --> PREFIXA
// INFIXA => 1+2*5+6/2
// PREFIXA => ++1*25/62

// 1-2+3-5
// -+- (LIFO-PILHA) 1235 (FIFO - LISTA)

// EXPRESSAO := + EXPRESSAO EXPRESSAO | - EXPRESSAO EXPRESSAO | TERMO
// TERMO := 0 | 1 | 2 ... | 9

#include <iostream>
#include <stack>
#include <list>

using namespace std;

string comando;
size_t pos;
stack<char> operadores;
list<char> numeros;

char consome(){
    char proximo = comando[pos];
    pos++;
    return proximo;
}

void TERMO(){
    // NÚMERO DE 0 A 9
    char termo = consome();
    if (termo>='0' && termo<='9'){
        // cout << "Reconheceu um termo: " << termo << endl;
        numeros.push_back(termo);
    }
    else
        cerr << "TERMO INVÁLIDO: " << termo << endl;
    
}

void EXPRESSAO(){
    TERMO();
    char proximo = consome();
    switch(proximo){
        case '+':
            // cout << "Reconheceu um operador: +" << endl;
            operadores.push(proximo);
            EXPRESSAO();
            break;
        case '-':
            // cout << "Reconheceu um operador: -" << endl;
            operadores.push(proximo);
            EXPRESSAO();
            break;
        case '\0':
            // cout << "Reconheceu uma expressão." << endl;
            return;
        default:
            cerr << "EXPRESSÃO INVÁLIDA: " << proximo << endl;
    }
}

void gera_codigo(){
    while(!operadores.empty()){
        cout << operadores.top();
        operadores.pop();
    }
    for(char n:numeros)
        cout << n;
    cout << endl;
}

int main(){
    pos = 0;
    cin >> comando;
    EXPRESSAO();
    gera_codigo();
    return 0;
}