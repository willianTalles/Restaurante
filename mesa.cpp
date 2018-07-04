#include "mesa.h"
#include "status.h"

Mesa::Mesa(){}


Mesa::Mesa(int numero, int quantidade_cadeira):
    numero__mesa( numero ),
    quantidade_cadeira( quantidade_cadeira ){}

Mesa::Mesa(int numero, int quantidade_cadeira, Status status):
    numero__mesa( numero ),
    quantidade_cadeira( quantidade_cadeira ){       
        this->status.push_back( status );
}

Mesa::~Mesa(){}

void Mesa::setNumero( int numero ){
    this->numero__mesa = numero;
}

void Mesa::setQuantidadeCadeira( int quantidade ){
    this->quantidade_cadeira = quantidade;
}

void Mesa::setStatus( Status status ){
    this->status.push_back( status );
}

int Mesa::getNumero(){
    return this->numero__mesa;
}

int Mesa::getQuantidadeCadeira(){
    return this->quantidade_cadeira;
}

std::vector<Status> Mesa::getStatus(){
    return this->status;
}

std::ostream& operator<< (std::ostream &o, Mesa &mesa) {
	o << "Numero da mesa: " << (mesa).getNumero() << std::endl << "Quantidade de Cadeira: " << (mesa).getQuantidadeCadeira() << std::endl;
    
    for(auto status = (mesa).getStatus().begin() ; status != (mesa).getStatus().end() ; status++){
        o << (*status);
    }
    return o;
}