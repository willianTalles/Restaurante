#ifndef _MESA_H_
#define _MESA_H_

#include <iostream>
#include <vector>
#include <string>
#include "status.h"

class Mesa{
    private:
        int numero__mesa;
        int quantidade_cadeira;
        std::vector<Status> status;
    public:
        Mesa();
        Mesa( int numero, int quantidade_cadeira );
        Mesa( int numero, int quantidade_cadeira, Status status );
        ~Mesa();
    // Métodos setters 
        void setNumero ( int numero );
        void setQuantidadeCadeira ( int quantidade );
        void setStatus ( Status status );

    // Métodos getters
        int getNumero ();
        int getQuantidadeCadeira ();
        std::vector<Status> getStatus();
    //Sobrecargas
        friend std::ostream& operator<< ( std::ostream &o, Mesa &mesa);
};

#endif