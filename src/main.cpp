#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
#include <vector>
#include <string>
using std::to_string;
#include <memory>

#include "mesa.h"
#include "status.h"
#include "reserva.h"
#include "excecao.h"
#include "util.h"
#include "menu.h"
using namespace util;

int main( ){
    std::vector< std::shared_ptr< Mesa > > mesa;
    Menu *menu = new Menu();

    carregarDadosEmTxt( mesa );

    menu->iniciar(mesa);

    salvarDadosEmTxt( mesa.begin(), mesa.end() );

    return 0;
}
