#include "reserva.h"

Reserva::Reserva(){}
Reserva::~Reserva(){}

void Reserva::fazerReserva( Mesa & mesa, Status status ){
    if( estarReservado( mesa, status ) ){
        std::cout << "A mesa de numero " << mesa.getNumero() << 
        " ja estar reservada para o dia " << status.getData() << std::endl;
    }else{
        mesa.setStatus( status );
        std::cout << " reserva para " << status.getData() << " as "
        << status.getHorario() << " foi realizado com sucesso! " 
        << std::endl; 
    }
}

void Reserva::removerReserva( Mesa & mesa, std::string data ){
    mesa.removeStatus( data );
}

void Reserva::buscarReservaDaMesa ( Mesa mesa ){
    std::cout << mesa;
}
bool Reserva::estarReservado ( Mesa mesa, Status status ){
    int contador = 0;
    for(auto i = mesa.getStatus().begin(); i != mesa.getStatus().end() ; i++){
        if ( mesa.getStatus()[contador].getData() == status.getData() ){
            return true;
        }
        contador++;
    }
    
    return false;
}