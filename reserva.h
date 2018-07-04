#ifndef _RESERVA_H_
#define _RESERVA_H_

#include <iostream>
#include "status.h"
#include "mesa.h"

class Reserva{
    private:
        Mesa mesa;
        Status status;

        bool estarReservado();
    public:
        Reserva(); 
        ~Reserva();
    // Métodos setters 
        void fazerReserva( Mesa mesa, Status status );
    // Métodos getters
        void printReservaDaMesa ( Mesa mesa );
        int estarReservado ( Mesa mesa, Status status );
    //Sobrecargas
        //friend std::ostream& operator<< ( std::ostream &o, Mesa &mesa);
};

#endif