/*
    Inclusões
*/
#include <string>
#include "header.h"

/*
    Configurações
*/
using namespace std;



// Construtor Parametrizado: a única forma de instanciar objetos dessa classe
Cliente::Cliente(string n, string c) {
    nome = n;   // setNome(n)
    cpf = c;    // setCPF(c)
}

// Getters
string Cliente::getNome() {
    return nome;
}

string Cliente::getCPF() {
    return cpf;
}
