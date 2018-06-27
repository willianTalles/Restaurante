#include "mesa.h"
#include "status.h"

Mesa::Mesa(){
    this->status.setLivre( true );
}

Mesa::Mesa(int numero, int quantidade_cadeira):
    numero__mesa( numero ),
    quantidade_cadeira( quantidade_cadeira ){
        this->status.setLivre( true );
}

Mesa::Mesa(int numero, int quantidade_cadeira, Status status):
    numero__mesa( numero ),
    quantidade_cadeira( quantidade_cadeira ){       
        this->status.setDia( status.getDia() );
        this->status.setMes( status.getMes() );
        this->status.setHora( status.getHora() );
        this->status.setMinuto( status.getMinuto() );
        this->status.setLivre( status.getLivre() );
}

Mesa::~Mesa(){}

void Mesa::setNumero( int numero ){
    this->numero__mesa = numero;
}

void Mesa::setQuantidadeCadeira( int quantidade ){
    this->quantidade_cadeira = quantidade;
}

void Mesa::setStatus( Status status ){
    this->status.setDia( status.getDia() );
    this->status.setMes( status.getMes() );
    this->status.setHora( status.getHora() );
    this->status.setMinuto( status.getMinuto() );
    this->status.setLivre( status.getLivre() );
}

int Mesa::getNumero(){
    return this->numero__mesa;
}

int Mesa::getQuantidadeCadeira(){
    return this->quantidade_cadeira;
}

Status Mesa::getStatus(){
    return this->status;
}

std::ostream& operator<< (std::ostream &o, Mesa &mesa) {
	o << "Numero da mesa: " << (mesa).getNumero() << std::endl << "Quantidade de Cadeira: " << (mesa).getQuantidadeCadeira() << std::endl
    <<(mesa).status;

    return o;
}