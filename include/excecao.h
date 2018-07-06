/**
 * @file	exececao.h
 * @author	Willian Talles M. Dantas
 * @since	10/07/2018
 * @date	05/07/2018
 */
#ifndef _EXCECAO_H_
#define _EXCECAO_H_

#include <stdexcept>
using std::invalid_argument;

class MesaInvalida : public invalid_argument{
    public:
        /**
        * @brief Método construtor padrão de status
        */
        MesaInvalida() : invalid_argument("O numero da mesa digitado e invalido. So temos mesa de 1 ate 10"){}
};

class DiaInvalido : public invalid_argument{
    public:
        /**
        * @brief Método construtor padrão de status
        */
        DiaInvalido() : invalid_argument("O dia digitado e invalido. So valores de 1 ate 31"){}
};

class MesInvalido : public invalid_argument{
    public:
        /**
        * @brief Método construtor padrão de status
        */
        MesInvalido() : invalid_argument("O mes digitado e invalido. So valores de 1 ate 12"){}
};

class HoraInvalido : public invalid_argument{
    public:
        /**
        * @brief Método construtor padrão de status
        */
        HoraInvalido() : invalid_argument("A hora digitada e invalida. So valores de 15 ate 23"){}
};

class MinutoInvalido : public invalid_argument{
    public:
        /**
        * @brief Método construtor padrão de status
        */
        MinutoInvalido() : invalid_argument("O dia minuto e invalido. So valores de 1 ate 59"){}
};
#endif