#include "status.h"
#include <string>

Status::Status():
    livre( true ) {}
Status::Status(int dia, int mes, int hora, int minuto, bool livre):
    dia( dia ),
    mes( mes ),
    hora( hora ),
    minuto( minuto ),
    livre( livre ) {}
Status::~Status(){}

void Status::setDia( int dia ){
    if(dia < 1 || dia > 31)
        std::cout << "dia Invalido" << std::endl; 
    else
        this->dia = dia;
}
void Status::setMes( int mes ){
    if(mes < 1 || mes > 12)
        std::cout << "mes Invalida" << std::endl; 
    else
        this->mes = mes;
}
void Status::setHora( int hora ){
    if(hora < 17 || hora > 23)
        std::cout << "hora Invalida" << std::endl; 
    else
        this->hora = hora;
}
void Status::setMinuto( int minuto ){
    if(minuto < 0 || minuto > 59)
        std::cout << "minuto Invalida" << std::endl; 
    else
        this->minuto = minuto;
}
void Status::setLivre( bool Status ){
    this->livre = Status;
}

int Status::getDia(){
    return this->dia;
}
int Status::getHora(){
    return this->hora;
}
int Status::getMes(){
    return this->mes;
}
int Status::getMinuto(){
    return this->minuto;
}
bool Status::getLivre(){
    return this->livre;
}

std::string Status::getHorario(){
    return std::to_string(this->hora) + ":" + std::to_string(this->minuto);
}

std::string Status::getData(){
    return std::to_string(this->dia) + "/" + std::to_string(this->mes);
}

std::ostream& operator<< (std::ostream &o, Status &reserva){
    if((reserva).getLivre()){
        o << "Status da mesa: LIVRE"<< std::endl; 
    }else{
        o << "Data da reserva: " << (reserva).getData() << std::endl << "Hora da reserva: " << (reserva).getHorario() << std::endl;
        o << "Status da mesa: RESERVADA"<< std::endl;
    }

    return o;
}
