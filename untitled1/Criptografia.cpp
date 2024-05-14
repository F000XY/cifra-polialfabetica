#include <iostream>
#include <cctype>
#include "Criptografia.h"

std::string Criptografia::calcularPosicoes(const std::string& palavra) {
    std::string posicoes;
    for (char c : palavra) {
        if (std::isalpha(c)) {
            int posicao = std::toupper(c) - 'A' + 1;
            posicoes += std::to_string(posicao) + " ";
        }
    }
    return posicoes;
}

std::string Criptografia::cifraPolialfabetica(const std::string& mensagem, const std::string& chave) {
    std::string mensagemCifrada;
    int chaveIndex = 0;

    for (char c : mensagem) {
        if (std::isalpha(c)) {
            char chaveAtual = chave[chaveIndex++ % chave.length()];
            int deslocamento;
            if (std::islower(chaveAtual)) {
                deslocamento = chaveAtual - 'a';
            } else {
                deslocamento = chaveAtual - 'A';
            }

            char cifra = c;
            if (std::islower(c)) {
                cifra = 'a' + (c - 'a' + deslocamento) % 26;
            } else {
                cifra = 'A' + (c - 'A' + deslocamento) % 26;
            }

            mensagemCifrada += cifra;
        } else {
            mensagemCifrada += c;
        }
    }

    return mensagemCifrada;
}

void Criptografia::chamada() {
    std::string palavra;
    std::cout << "Digite a chave: ";
    std::getline(std::cin, palavra);

    std::string posicoes = calcularPosicoes(palavra);
    std::cout << "Posicoes das letras na palavra: " << posicoes << std::endl;

    std::string mensagem;
    std::cout << "Digite uma palavra para ser criptografada: ";
    std::getline(std::cin, mensagem);

    std::string mensagemCifrada = cifraPolialfabetica(mensagem, palavra);
    std::cout << "Mensagem cifrada: " << mensagemCifrada << std::endl;
}
