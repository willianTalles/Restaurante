/**
 * @file	status.h
 * @brief	Cabeçalho da classe status em C++
 * @author	Willian Talles M. Dantas
 * @since	10/07/2018
 * @date	05/07/2018
 */

#ifndef _STATUS_H_
#define _STATUS_H_

#include <string>
#include <iostream>

class Status{
    private:
        int dia;
        int mes;
        int hora;
        int minuto;
        bool livre;
    public:
        /**
        * @brief Método construtor padrão de status
        */
        Status();
        /**
        * @brief Método construtor parametrizado de status
        * @param int dia - recebe um int a ser processada
        * @param int mes - recebe um int a ser processada
        * @param int hora - recebe um int a ser processada
        * @param int minuto - recebe um int a ser processada
        * @param bool livre - recebe um bool a ser processada
        */
        Status(int dia, int mes, int hora, int minuto, bool livre);
        /**
        * @brief Método destrutor de status
        */
        ~Status();
        /** 
         * @brief atribui um int ao atributo da classe status
         * @param int dia - recebe um int a ser atribuida
        */
        void setDia( int dia );
        /** 
         * @brief atribui um int ao atributo da classe status
         * @param int mes - recebe um int a ser atribuida
        */
        void setMes( int mes );
        /** 
         * @brief atribui um int ao atributo da classe status
         * @param int hora - recebe um int a ser atribuida
        */
        void setHora( int hora );
        /** 
         * @brief atribui um int ao atributo da classe status
         * @param int minuto - recebe um int a ser atribuida
        */
        void setMinuto( int minuto );
        /** 
         * @brief atribui um bool ao atributo da classe status
         * @param bool livre  - recebe um bool a ser atribuida
        */
        void setLivre( bool status );
        /** 
         * @brief retorna atributo da classe
         * @return o atributo da classe - int dia
        */
        int getDia();
        /** 
         * @brief retorna atributo da classe
         * @return o atributo da classe - int hora
        */
        int getHora();
        /** 
         * @brief retorna atributo da classe
         * @return o atributo da classe - int mes
        */
        int getMes();
        /** 
         * @brief retorna atributo da classe
         * @return o atributo da classe - int minuto
        */
        int getMinuto();
        /** 
         * @brief retorna atributo da classe
         * @return o atributo da classe - bool livre
        */
        bool getLivre();
        /** 
         * @brief Fução que uni dia e mes e retorna a data
         * @return string com a data
        */
        std::string getData();
        /** 
         * @brief Fução que uni hora e minuto e retorna a horario
         * @return string com o horario
        */
        std::string getHorario();
       /**
        * @brief Sobrecarga do operador de inserção.
        * @detail imprime na saída padrão as informações do status
        * @param ostream &o operador de inserção
        * @param status reserva uma instância de status
        * @return retorna a instância do operador de inserção
        */
        friend std::ostream& operator<< ( std::ostream &o, Status &reserva);

};

#endif