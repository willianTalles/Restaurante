#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

#include "mesa.h"
#include "status.h"
#include "reserva.h"

void menu(){
    int opcao = 0;

    while(opcao != 4){
        std::cout << "Digite o numero da opcao que deseja"<<
        " 1 - reservar mesa " << 
        " 2 - imprimir reservas de uma mesa " << 
        " 3 - remover reserva" << 
        " 4 - sair" << std::endl;

        std::cin >> opcao;
    }
}

void salvarDadosEmTxt(){
    std::ofstream file;
    file.open("dados.txt");
    std::string dados = "Oi qual o seu nome?\n";
    file << dados;
    file.close();
}

int main( ){
    std::vector< std::shared_ptr< Mesa > > mesa;

    mesa.push_back( std::make_shared< Mesa >( 1, 4 ) );
    mesa.push_back( std::make_shared< Mesa >( 2, 6 ) );

    Status status( 2, 1, 18, 00, false );
    Status status1( 3, 1, 18, 00, false );
    Status status2( 4, 1, 18, 00, false );

    Reserva *reserva = new Reserva();

    reserva->fazerReserva( (*mesa[0]) , status);
    reserva->fazerReserva( (*mesa[0]) , status1);
    reserva->fazerReserva( (*mesa[0]) , status2);
    
    for(auto i = mesa.begin() ; i != mesa.end() ; i++){
        std::cout << (**i);
    }

    std::string data = "2/1";
    reserva->removerReserva( (*mesa[0]), data);

    for(auto i = mesa.begin() ; i != mesa.end() ; i++){
        reserva->buscarReservaDaMesa( (**i) );
    }

    return 0;
}
