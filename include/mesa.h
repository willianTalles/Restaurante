/**
 * @file	mesa.h
 * @brief	Cabeçalho da classe mesa em C++
 * @author	Willian Talles M. Dantas
 * @since	10/07/2018
 * @date	05/07/2018
 */

#ifndef _MESA_H_
#define _MESA_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "status.h"

class Mesa{
    private:
        int numero__mesa;
        int quantidade_cadeira;
        std::vector<Status> status;
    public:
        /**
        * @brief Método construtor padrão de mesa
        */
        Mesa();
        /**
        * @brief Método construtor parametrizado de mesa
        * @param int numero - recebe um int a ser processada
        * @param int quantidade_cadeira - recebe um int a ser processada
        */
        Mesa( int numero, int quantidade_cadeira );
        /**
        * @brief Método construtor parametrizado de mesa
        * @param int numero - recebe um int a ser processada
        * @param int quantidade_cadeira - recebe um int a ser processada
        * @param int Status status - recebe um Status a ser processada
        */
        Mesa( int numero, int quantidade_cadeira, Status status );
        /**
        * @brief Método destrutor de mesa
        */
        ~Mesa();
        /** 
         * @brief atribui um int ao atributo da classe mesa
         * @param int numero - recebe um int a ser atribuida
        */ 
        void setNumero ( int numero );
        /** 
         * @brief atribui um int ao atributo da classe mesa
         * @param int quantidade - recebe um int a ser atribuida
        */
        void setQuantidadeCadeira ( int quantidade );
        /** 
         * @brief atribui um Status ao atributo da classe mesa
         * @param Status status - recebe um int a ser atribuida
        */
        void setStatus ( Status status );
        /** 
         * @brief remove um elemento do vector status
         * @param string data  - recebe uma string com a data do status a ser removida
        */
        void removeStatus( std::string data );
        /** 
         * @brief retorna atributo da classe
         * @return o atributo da classe - int numero_mesa
        */
        int getNumero ();
        /** 
         * @brief retorna atributo da classe
         * @return o atributo da classe - int quantidade_cadeira
        */
        int getQuantidadeCadeira ();
        /** 
         * @brief retorna atributo da classe
         * @return o atributo da classe - vector status;
        */
        std::vector<Status> getStatus();
        /**
        * @brief Sobrecarga do operador de inserção.
        * @detail imprime na saída padrão as informações da mesa
        * @param ostream &o operador de inserção
        * @param Mesa mesa uma instância de Mesa
        * @return retorna a instância do operador de inserção
        */
        friend std::ostream& operator<< ( std::ostream &o, Mesa &mesa);
        /**
        * @brief Sobrecarga do operador de extreção.
        * @detail imprime na saída padrão as informações da mesa
        * @param ostream &o operador de extreção
        * @param Mesa mesa uma instância de Mesa
        * @return retorna a instância do operador de extreção
        */
        friend std::istream& operator>> ( std::istream &i, Mesa &mesa);
};

#endif