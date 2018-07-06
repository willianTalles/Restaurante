#ifndef _EXCECAO_H_
#define _EXCECAO_H_

#include <stdexcept>
using std::invalid_argument;

class Excecao : public invalid_argument{
    public:
        Excecao() : invalid_argument("O valor digitado e invalido"){}
};

#endif