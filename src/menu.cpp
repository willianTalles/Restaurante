#include "menu.h"

Menu::Menu(){}
Menu::~Menu(){}
void Menu::iniciar( std::vector< std::shared_ptr< Mesa > > &mesa  ){
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
        cout << "------------------------------------------" << endl;
        cout << "                  MENU" << endl;
        cout << "------------------------------------------" << endl;
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
                        cout << "------------------------------------------" << endl;
                        cout << "              RESERVAR MESA" << endl;
                        cout << "------------------------------------------" << endl;
                        cout << "Digite o numero da mesa: ";
                        cin >> numero_mesa;
                        if( numero_mesa > 10 ) throw MesaInvalida();
                        cout << "Digite o dia: ";
                        cin >> dia;
                        if( dia > 31 || dia < 1 ) throw DiaInvalido();
                        cout << "Digite o mes: ";
                        cin >> mes;
                        if( mes > 12 || mes < 1 ) throw MesInvalido();
                        cout << "Digite a hora: ";
                        cin >> hora;
                        if( hora > 23 || hora < 15 ) throw HoraInvalido();
                        cout << "Digite os minutos: ";
                        cin >> minutos;
                        if( minutos > 59 || minutos < 0 ) throw MinutoInvalido();

                        system("cls");

                        cout << "------------------------------------------" << endl;
                        cout << "              RESERVAR MESA" << endl;
                        cout << "------------------------------------------" << endl;

                        status->setDia( dia );
                        status->setMes( mes );
                        status->setHora( hora );
                        status->setMinuto( minutos );

                        reserva->fazerReserva( (*mesa[numero_mesa-1]) , (*status) );
                    }catch( MesaInvalida &ex ){
                        cerr << ex.what() << endl;
                    }catch( DiaInvalido &ex ){
                        cerr << ex.what() << endl;
                    }catch( MesInvalido &ex ){
                        cerr << ex.what() << endl;
                    }catch( HoraInvalido &ex ){
                        cerr << ex.what() << endl;
                    }catch( MinutoInvalido &ex ){
                        cerr << ex.what() << endl;
                    }catch ( ... ){
                        cerr << "Erro desconhecido" << endl;
                    }
                    cout << "_________________________________________________________________________" << endl;
                    cout << "1 - Fazer outra reserva | 2 - Voltar para o menu | 5 - Sair do programa " << endl;
                    cin >> opcao;
                    system("cls");
                }
                break;
            case 2:
                while( opcao == 2 ){
                    try{
                        system("cls");
                        cout << "------------------------------------------" << endl;
                        cout << "                BUSCAR MESA" << endl;
                        cout << "------------------------------------------" << endl;

                        cout << "Digite o numero da mesa: ";
                        cin >> numero_mesa;
                        if( numero_mesa > 10 ) throw MesaInvalida();

                        system("cls");

                        cout << "------------------------------------------" << endl;
                        cout << "                BUSCAR MESA" << endl;
                        cout << "------------------------------------------" << endl;

                        reserva->buscarReservaDaMesa( (*mesa[numero_mesa-1]) );

                    }catch( MesaInvalida &ex ){
                        cerr << ex.what() << endl;
                    }catch ( ... ){
                        cerr << "Erro desconhecido" << endl;
                    }

                    cout << "_________________________________________________________________________" << endl;
                    cout << "2 - Fazer outra busca | 1 - Voltar para o menu | 5 - Sair do programa " << endl;
                    cin >> opcao;

                    system("cls");
                }
                break;
            case 3:
                while( opcao == 3 ){
                    try{
                        system("cls");

                        cout << "------------------------------------------" << endl;
                        cout << "         REMOVER RESERVA DA MESA" << endl;
                        cout << "------------------------------------------" << endl;

                        cout << "Digite o numero da mesa: ";
                        cin >> numero_mesa;
                        if( numero_mesa > 10 ) throw MesaInvalida();
                        cout << "Digite o dia: ";
                        cin >> dia;
                        if( dia > 31 || dia < 1 ) throw DiaInvalido();
                        cout << "Digite o mes: ";
                        cin >> mes;
                        if( mes > 12 || mes < 1 ) throw MesInvalido();
                        system("cls");

                        cout << "------------------------------------------" << endl;
                        cout << "         REMOVER RESERVA DA MESA" << endl;
                        cout << "------------------------------------------" << endl;

                        data = std::to_string( dia ) + "/" + std::to_string( mes );

                        reserva->removerReserva( (*mesa[numero_mesa-1]), data );

                    }catch( MesaInvalida &ex ){
                        cerr << ex.what() << endl;
                    }catch( DiaInvalido &ex ){
                        cerr << ex.what() << endl;
                    }catch( MesInvalido &ex ){
                        cerr << ex.what() << endl;
                    }catch ( ... ){
                        cerr << "Erro desconhecido" << endl;
                    }

                    cout << "_________________________________________________________________________" << endl;
                    cout << "3 - Remover outra reserva | 1 - Voltar para o menu | 5 - Sair do programa " << endl;
                    cin >> opcao;
                    system("cls");
                }
                break;
            case 4:
                while( opcao == 4 ){
                    try{
                        system("cls");

                        cout << "------------------------------------------" << endl;
                        cout << "  VERIFICAR SE MESA ESTA LIVRE NA DATA" << endl;
                        cout << "------------------------------------------" << endl;

                        cout << "Digite o numero da mesa: ";
                        cin >> numero_mesa;
                        if( numero_mesa > 10 ) throw MesaInvalida();
                        cout << "Digite o dia: ";
                        cin >> dia;
                        if( dia > 31 || dia < 1 ) throw DiaInvalido();
                        cout << "Digite o mes: ";
                        cin >> mes;
                        if( mes > 12 || mes < 1 ) throw MesInvalido();
                        system("cls");

                        cout << "------------------------------------------" << endl;
                        cout << "  VERIFICAR SE MESA ESTA LIVRE NA DATA" << endl;
                        cout << "------------------------------------------" << endl;

                        data = std::to_string( dia ) + "/" + std::to_string( mes );

                        reserva->estarReservado( (*mesa[numero_mesa-1]), data );
                    }catch( MesaInvalida &ex ){
                        cerr << ex.what() << endl;
                    }catch( DiaInvalido &ex ){
                        cerr << ex.what() << endl;
                    }catch( MesInvalido &ex ){
                        cerr << ex.what() << endl;
                    }catch ( ... ){
                        cerr << "Erro desconhecido" << endl;
                    }
                    cout << "_________________________________________________________________________" << endl;
                    cout << "4 - verificar outra data | 1 - Voltar para o menu | 5 - Sair do programa " << endl;
                    cin >> opcao;
                    system("cls");
                }
                break;

            default:
                break;
        }
    }
}