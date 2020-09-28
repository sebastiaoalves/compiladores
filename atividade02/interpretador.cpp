// Exemplo: -+-1235
// GRAMÁTICA:
// expressao <-- [+-] expressao expressao | numero
// numero <-- [0-9]

#include <iostream>

using namespace std;

string comando;
int pos;

// Consome o próximo símbolo da entrada
char consome(){
    char proximo = comando[pos];
    pos++;
    return proximo;
}

// Testa se é um sinal
bool ehSinal(char ch){
	return ch=='+' || ch=='-';
}

//Testa se é um número
bool ehNumero(char ch){
	return ch>='0' && ch<='9';
}

// Retorna o valor da expressão reconhecida
int EXPRESSAO(){
	char proximo = consome();
	if(ehSinal(proximo)){  // Se for um sinal retorna o resultado da operação das próximas expressões
		int exp1=EXPRESSAO();
		int exp2=EXPRESSAO();
		return proximo=='+' ? exp1+exp2 : exp1-exp2; 
	}else if(ehNumero(proximo)){  // Se for um número retorna seu valor
		return proximo-'0';
	}else{ // Senão é um erro
		cerr << "Expressão não reconhecida!" << endl;
	}
	return -1;
}

int main(){
    pos = 0;
    cin >> comando;
    cout << EXPRESSAO() << endl;
    return 0;
}
