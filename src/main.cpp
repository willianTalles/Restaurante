#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;    
#include <fstream>
#include <vector>
#include <string>
using std::to_string;
#include <memory>

#include "mesa.h"
#include "status.h"
#include "reserva.h"
#include "excecao.h"
#include "util.h"
using namespace util;

void menu( std::vector< std::shared_ptr< Mesa > > &mesa  ){
    int opcao = 0;
    int numero_mesa = 0;
    int dia = 0;
    int mes = 0;
    int hora = 0;
    int minutos = 0;
    std::string data;
    Status *status = new Status();
    Reserva *reserva = new Reserva();

    while( opcao != 5 ){
        cout << "Digite o numero da opcao que deseja"<< endl <<
        " 1 - Reservar mesa " << endl <<
        " 2 - Buscar reservas de uma mesa " << endl <<
        " 3 - Remover reserva" << endl <<
        " 4 - Verificar se mesa esta livre na data " << endl << 
        " 5 - sair" << endl;

        cin >> opcao;

        
        switch ( opcao ){
            case 1:
                while( opcao == 1 ){
                    try{
                        system("cls");
                        cout << "Digite o numero da mesa: ";
                        cin >> numero_mesa;
                        if( numero_mesa > 10 ) throw Excecao();
                        cout << "Digite o dia: ";
                        cin >> dia;
                        if( dia > 31 || dia < 1 ) throw Excecao();
                        cout << "Digite o mes: ";
                        cin >> mes;
                        if( mes > 12 || mes < 1 ) throw Excecao();
                        cout << "Digite a hora: ";
                        cin >> hora;
                        if( hora > 23 || hora < 15 ) throw Excecao();
                        cout << "Digite os minutos: ";
                        cin >> minutos;
                        if( minutos > 59 || minutos < 0 ) throw Excecao();

                        system("cls");
                        
                        status->setDia( dia );
                        status->setMes( mes );
                        status->setHora( hora );
                        status->setMinuto( minutos );

                        reserva->fazerReserva( (*mesa[numero_mesa-1]) , (*status) );
                    }catch( Excecao &ex ){
                        cerr << ex.what() << endl;
                    }catch ( ... ){
                        cerr << "Erro desconhecido" << endl;
                    }
                    
                    cout << "1 - Fazer outra reserva " << endl <<
                    "2 - Voltar para o menu " << endl <<
                    "5 - Sair do programa " << endl;
                    cin >> opcao;
                    system("cls");
                }
                break;
            case 2:
                while( opcao == 2 ){
                    try{
                        system("cls");
                        cout << "Digite o numero da mesa: ";
                        cin >> numero_mesa;
                        if( numero_mesa > 10 ) throw Excecao();
                        system("cls");
                        reserva->buscarReservaDaMesa( (*mesa[numero_mesa-1]) );
                    }catch( Excecao &ex ){
                        cerr << ex.what() << endl;
                    }catch ( ... ){
                        cerr << "Erro desconhecido" << endl;
                    }
                    cout << "2 - Fazer outra busca " << endl <<
                    "1 - Voltar para o menu " << endl <<
                    "5 - Sair do programa " << endl;
                    cin >> opcao;
                    system("cls");
                }
                break;
            case 3:
                while( opcao == 3 ){
                    try{
                        system("cls");
                        cout << "Digite o numero da mesa: ";
                        cin >> numero_mesa;
                        if( numero_mesa > 10 ) throw Excecao();
                        cout << "Digite o dia: ";
                        cin >> dia;
                        if( dia > 31 || dia < 1 ) throw Excecao();
                        cout << "Digite o mes: ";
                        cin >> mes;
                        if( mes > 12 || mes < 1 ) throw Excecao();
                        system("cls");
                        data = std::to_string( dia ) + "/" + std::to_string( mes );

                        reserva->removerReserva( (*mesa[numero_mesa-1]), data );
                    }catch( Excecao &ex ){
                        cerr << ex.what() << endl;
                    }catch ( ... ){
                        cerr << "Erro desconhecido" << endl;
                    }
                    cout << "3 - Remover outra reserva " << endl <<
                    "1 - Voltar para o menu " << endl <<
                    "5 - Sair do programa " << endl;
                    cin >> opcao;
                    system("cls");
                }
                break;
            case 4:
                while( opcao == 4 ){
                    try{
                        system("cls");
                        cout << "Digite o numero da mesa: ";
                        cin >> numero_mesa;
                        if( numero_mesa > 10 ) throw Excecao();
                        cout << "Digite o dia: ";
                        cin >> dia;
                        if( dia > 31 || dia < 1 ) throw Excecao();
                        cout << "Digite o mes: ";
                        cin >> mes;
                        if( mes > 12 || mes < 1 ) throw Excecao();
                        system("cls");
                        data = std::to_string( dia ) + "/" + std::to_string( mes );

                        reserva->estarReservado( (*mesa[numero_mesa-1]), data );
                    }catch( Excecao &ex ){
                        cerr << ex.what() << endl;
                    }catch ( ... ){
                        cerr << "Erro desconhecido" << endl;
                    }
                    cout << "4 - verificar outra data " << endl <<
                    "1 - Voltar para o menu " << endl <<
                    "5 - Sair do programa " << endl;
                    cin >> opcao;
                    system("cls");
                }
                break;

            default:
                break;
        }
    }
}

int main( ){
    std::vector< std::shared_ptr< Mesa > > mesa;

    carregarDadosEmTxt( mesa );

    menu(mesa);

    salvarDadosEmTxt( mesa.begin(), mesa.end() );

    return 0;
}