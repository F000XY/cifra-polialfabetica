#ifndef CIFRA_POLIALFABETICA_H
#define CIFRA_POLIALFABETICA_H

#include <string>

class Criptografia {
public:
    std::string calcularPosicoes(const std::string& palavra);
    std::string cifraPolialfabetica(const std::string& mensagem, const std::string& chave);
    void chamada();
};

#endif // CIFRA_POLIALFABETICA_H

