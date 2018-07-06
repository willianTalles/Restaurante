/**
 * @file	menu.h
 * @brief	Cabeçalho da classe menu em C++
 * @author	Willian Talles M. Dantas
 * @since	10/07/2018
 * @date	05/07/2018
 */

#ifndef _MENU_H_
#define _MENU_H_
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
#include <vector>
#include <memory>

#include "mesa.h"
#include "status.h"
#include "reserva.h"
#include "excecao.h"
class Menu{
    public:
        /**
        * @brief Método construtor padrão de Menu
        */
        Menu();
        /**
        * @brief Método destrutor de Menu
        */
        ~Menu();
        /**
        * @brief Método para executar o programa.
        * @param vector< shared_ptr< Mesa > > &mesa - recebe uma referenvia de vector a ser manipulada
        * @detail exibi o menu do programa, chamas as funções que 
        * programa necessita .
        */
        void iniciar( std::vector< std::shared_ptr< Mesa > > &mesa  );
}; 
#endif