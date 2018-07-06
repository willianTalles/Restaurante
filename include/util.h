/**
 * @file	util.h
 * @brief	Cabeçalho da classe util em C++
 * @author	Willian Talles M. Dantas
 * @since	10/07/2018
 * @date	05/07/2018
 */

#ifndef _UTIL_H_
#define _UTIL_H_

#include <vector>
#include <memory>
#include <fstream>
#include <string>

#include "mesa.h"
#include "status.h"
#include "reserva.h"

namespace util{
    /** 
     * @brief carrega todos os dados de uma arquivo txt a serem manipulados no programa
     * @param vector< shared_ptr< Mesa > > &mesa - recebe uma referenvia de vector a ser atribuida
    */
    void carregarDadosEmTxt( std::vector< std::shared_ptr< Mesa > > &mesa );
    /** 
     * @brief salva todos os dados em uma arquivo txt que foram manipulados no programa
     * @param vector< shared_ptr< Mesa > > &mesa - recebe uma referenvia de vector a ser atribuida
    */
    void salvarDadosEmTxt( std::vector< std::shared_ptr< Mesa > >::iterator inicio, std::vector< std::shared_ptr< Mesa > >::iterator fim );
}
#endif