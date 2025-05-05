#ifndef HEADER_H
#define HEADER_H

/*
    Inclusões
*/
#include <string>

/*
    Configurações
*/
using namespace std;

/*
    Classe Cliente
*/
/**
 * @class Cliente
 * @brief Representa um cliente que possui Nome e CPF.
 */
class Cliente {
    private:
        string nome;
        string cpf;
    
    public:
        /**
         * @brief Declaração do Construtor da classe.
         * @param n Nome.
         * @param c CPF.
         */
        Cliente(string n, string c);

        /**
         * @brief Obtém o Nome do cliente (Getter).
         * @return Nome.
         */
        string getNome();

        /**
         * @brief Obtém o CPF do cliente (Getter).
         * @return CPF.
         */
        string getCPF();
};

/*
    Classe ContaBancaria
*/
/**
 * @class ContaBancaria
 * @brief Representa uma conta bancária que possui Número, Titular e Saldo.
 */
class ContaBancaria {
    private:
        int numero;
        Cliente titular;
        double saldo;
    
    public:
        /**
         * @brief Declaração do Construtor da classe.
         * @param n Número.
         * @param t Cliente Titular.
         * @param s Saldo.
         */
        ContaBancaria(int n, Cliente t, double s = 0);

        /**
         * @brief Obtém o Número da conta (Getter).
         * @return Número.
         */
        int getNumero();
        
        /**
         * @brief Obtém o Titular da conta (Getter).
         * @return Titular.
         */
        Cliente getTitular();

        /**
         * @brief Obtém o Saldo da conta (Getter).
         * @return Saldo.
         */
        double getSaldo();

        /**
         * @brief Exibe o Saldo da conta.
         */
        void exibirSaldo();

        /**
         * @brief Exibe as Informações da conta.
         */
        void exibirInformacoes();

        /**
         * @brief Realiza um Depósito na conta.
         * @param valor Valor a ser depositado.
         */
        void depositar(double valor);

        /**
         * @brief Realiza um Saque da conta.
         * @param valor Valor a ser sacado.
         */
        void sacar(double valor);

        /**
         * @brief Transfere um valor para outra conta.
         * @param valor Valor a ser transferido.
         * @param destino Conta de destino.
         */
        void transferir(double valor, ContaBancaria &destino);
        
        /**
         * @brief Transfere um valor dividido entre duas contas de destino.
         * @param valor Valor total a ser transferido.
         * @param destino1 Primeira conta de destino.
         * @param destino2 Segunda conta de destino.
         */
        void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2);
};

#endif