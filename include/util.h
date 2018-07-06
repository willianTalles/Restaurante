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
    void carregarDadosEmTxt( std::vector< std::shared_ptr< Mesa > > &mesa );
    void salvarDadosEmTxt( std::vector< std::shared_ptr< Mesa > >::iterator inicio, std::vector< std::shared_ptr< Mesa > >::iterator fim );
}
#endif