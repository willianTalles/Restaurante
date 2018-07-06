/**
 * @file	reserva.h
 * @brief	Cabeçalho da classe reserva em C++
 * @author	Willian Talles M. Dantas
 * @since	10/07/2018
 * @date	05/07/2018
 */

#ifndef _RESERVA_H_
#define _RESERVA_H_

#include <iostream>
#include <string>

#include "status.h"
#include "mesa.h"

class Reserva{
    private:
        Mesa mesa;
        Status status;
    public:
        /**
        * @brief Método construtor padrão de Reserva
        */
        Reserva();
        /**
        * @brief Método destrutor de Reserva
        */ 
        ~Reserva();
        /** 
         * @brief adiciona um status no vetor status da classe mesa
         * @param Mesa &mesa - recebe uma referencia de Mesa para ser adiocionada o status
         * @param Status status - recebe um status para ser adiocionada na mesa
        */
        void fazerReserva( Mesa & mesa, Status status );
        /** 
         * @brief remove um status no vetor status da classe mesa
         * @param Mesa &mesa - recebe uma referencia de Mesa para ser removido o status
         * @param Status status - recebe um status para ser removido na mesa
        */
        void removerReserva( Mesa & mesa, std::string data );
        /** 
         * @brief imprimi na tela todas reserva de uma mesa
         * @param Mesa mesa - recebe Mesa para ser buscar os status
        */
        void buscarReservaDaMesa ( Mesa mesa );
        /** 
         * @brief retorna se true a mesa não tem reserva caso contrario false
         * @param Mesa mesa - recebe Mesa para ser buscar os status
         * @param Status status - recebe Status para verificação
        */
        bool estarReservado ( Mesa mesa, Status status );
        /** 
         * @brief retorna se true a mesa não tem reserva caso contrario false
         * @param Mesa mesa - recebe Mesa para ser buscar os status
         * @param string data - recebe data para verificação
        */
        void estarReservado ( Mesa mesa, std::string data );
};

#endif