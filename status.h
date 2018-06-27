#ifndef _STATUS_H_
#define _STATUS_H_

#include <string>
#include <iostream>

class Status{
    private:
        int dia;
        int mes;
        int hora;
        int minuto;
        bool livre;
    public:
        Status();
        Status(int dia, int mes, int hora, int minuto, bool livre);
        ~Status();
        // Métodos setters
        void setDia( int dia );
        void setMes( int mes );
        void setHora( int hora );
        void setMinuto( int minuto );
        void setLivre( bool status );
        // Métodos getters
        int getDia();
        int getHora();
        int getMes();
        int getMinuto();
        bool getLivre();
        std::string getData();
        std::string getHorario();
        // Sobrecarga
        friend std::ostream& operator<< ( std::ostream &o, Status &reserva);

};

#endif