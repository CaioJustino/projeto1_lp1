/*
    Inclusões
*/
#include <iostream>
#include <cmath>       
#include <iomanip>     
#include "header.h"

/*
    Configurações
*/
using namespace std;



// Construtor Parametrizado: a única forma de instanciar objetos dessa classe
ContaBancaria::ContaBancaria(int n, Cliente t, double s) : numero (n), titular(t) {
    if (s < 0) {
        cout << "O Valor do Saldo Inicial deve ser igual ou maior do que 0!" << endl;
        saldo = 0;
    } else {
        saldo = round(s * 100.0) / 100.0; // Fórmula aplicada na função round para arredondar o valor do saldo para até 2 casas decimais
    }
}

// Getters
int ContaBancaria::getNumero() {
    return numero;
}

Cliente ContaBancaria::getTitular() {
    return titular;
}

double ContaBancaria::getSaldo() {
    return saldo;
}

// Métodos Principais

void ContaBancaria::exibirSaldo() {
    cout << fixed << setprecision(2); // Limitar a saída para mostrar até duas casas decimais
    cout << "Saldo atual da conta " << this->getNumero() << ": R$ " << this->getSaldo() << "\n" << endl;
}

void ContaBancaria::exibirInformacoes() {
    cout << fixed << setprecision(2);
    cout << "Titular: " << this->getTitular().getNome() << ", CPF: " << this->getTitular().getCPF() << endl;
    cout << "Número da Conta: " << this->getNumero() << ", Saldo: R$ " << this->getSaldo() << endl;
}

void ContaBancaria::depositar(double valor) {
    if (valor <= 0) {
        cout << "\n\nO Valor do Depósito deve ser maior do que 0!" << endl;
    } else {
        cout << "\n\nDepósito realizado com sucesso!" << endl;
        this->saldo += valor;
    }
}

void ContaBancaria::sacar(double valor) {
    if (valor <= 0) {
        cout << "\nO Valor do Saque deve ser maior do que 0!" << endl;
    } else if (this->getSaldo() < valor) {
        cout << "\nSaldo Insuficiente!" << endl;
    } else {
        cout << "\nSaque realizado com sucesso!" << endl;
        this->saldo -= valor;
    }
}

// Sobrecarga do Método Transferir
void ContaBancaria::transferir(double valor, ContaBancaria &destino) {
    if (valor <= 0) {
        cout << "O Valor da Transferência deve ser maior do que 0!" << endl;
    } else if (this->getSaldo() < valor) {
        cout << "Saldo Insuficiente!" << endl;
    } else if (this->getNumero() == destino.getNumero()) {
        cout << "Não é possível realizar transferências para a mesma conta!" << endl;    
    } else {
        this->saldo -= valor;
        destino.saldo += valor;
        cout << "Transferido: R$ " << fixed << setprecision(2) << valor << " da conta " << this->getNumero() << " para a conta " << destino.getNumero() << endl;
    }
}

void ContaBancaria::transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
    double valor_dividido = valor/2;

    if (valor <= 0) {
        cout << "O Valor da Transferência deve ser maior do que 0!\n" << endl;
    } else if (this->getSaldo() < valor) {
        cout << "Saldo Insuficiente!\n" << endl;
    } else if (this->getNumero() == destino1.getNumero() || this->getNumero() == destino2.getNumero()) {
        cout << "Não é possível realizar transferências para a mesma conta!" << endl;    
    } else {
        this->saldo -= valor;
        destino1.saldo += valor_dividido;
        destino2.saldo += valor_dividido;
        cout << "Transferido: R$ " << fixed << setprecision(2) << valor_dividido << " para cada conta (" << destino1.getNumero() << " e " << destino2.getNumero() << ") da conta " << this->getNumero() << "\n" << endl;
    }
}