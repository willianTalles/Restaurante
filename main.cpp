#include <iostream>

#include "mesa.h"
#include "status.h"


int main( ){
    Status reserva(02, 05, 17, 45, false );
    Mesa mesa( 1, 4 );
    std::cout << mesa;
    mesa.setStatus(reserva);
    std::cout << mesa;
    return 0;
}
