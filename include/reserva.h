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
        Reserva(); 
        ~Reserva();
    // Métodos setters 
        void fazerReserva( Mesa & mesa, Status status );
        void removerReserva( Mesa & mesa, std::string data );
    // Métodos getters
        void buscarReservaDaMesa ( Mesa mesa );
        bool estarReservado ( Mesa mesa, Status status );
        void estarReservado ( Mesa mesa, std::string data );
    //Sobrecargas
        //friend std::ostream& operator<< ( std::ostream &o, Mesa &mesa);
};

#endif