#include "util.h"
using std::to_string;

namespace util{
    void salvarDadosEmTxt( std::vector< std::shared_ptr< Mesa > >::iterator inicio, std::vector< std::shared_ptr< Mesa > >::iterator fim ){
        int quantidade_status = 0;
        std::ofstream file;
        file.open("dados.txt");
        std::string mesa;
        std::string status;

        for(auto i = inicio; i != fim ; i++){
            mesa = to_string((**i).getQuantidadeCadeira()) + " " + to_string((**i).getStatus().size());
            file << mesa ;
            quantidade_status = (**i).getStatus().size();
            for(auto j = 0; j < quantidade_status ; j++){
                status = " " + to_string((**i).getStatus()[j].getDia()) + " " + to_string((**i).getStatus()[j].getMes()) + " " + to_string((**i).getStatus()[j].getHora()) + " " + to_string((**i).getStatus()[j].getMinuto());
                file << status;
            }
            file << std::endl;
        }
        file.close();
    }

    void carregarDadosEmTxt( std::vector< std::shared_ptr< Mesa > > &mesa ){
        int quantidade_cadeira = 0;
        int quantidade_status = 0;
        int dia = 0;
        int mes = 0;
        int hora = 0;
        int minutos = 0;
        Status *status = new Status();
        Reserva *reserva = new Reserva();
        std::ifstream file("dados.txt");

        if(!file){
            std::cout << "Erro ao abrir o arquivo" << std::endl;
        }

        for(auto i = 1; i <= 10; i++){
            file >> quantidade_cadeira;
            
            mesa.push_back( std::make_shared< Mesa >( i, quantidade_cadeira ) );
            
            file >> quantidade_status;
            if( quantidade_status != 0 ){
                for(auto j = 0; j < quantidade_status; j++){
                    file >> dia;
                    file >> mes;
                    file >> hora;
                    file >> minutos;

                    status->setDia( dia );
                    status->setMes( mes );
                    status->setHora( hora );
                    status->setMinuto( minutos );
                    
                    reserva->fazerReserva( (*mesa[i-1]) , (*status) );
                }
            }
        }
        system("cls");
    }
}