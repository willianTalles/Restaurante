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

void Mesa::removeStatus( std::string data ){
    int tamanho = status.size();
    int contador = 0;
    bool removeu = true;  
    for(auto i = 0; i < tamanho ; i++){
        if( status[i].getData() == data ){
            if( contador+1 < (int) this->status.size() ){
                status.erase( status.begin() + contador );
            }else{
                status.pop_back();
            }
            removeu = true;
            std::cout<<"A reseva da mesa " << 
            this->numero__mesa<< " para o dia " << data <<
            " foi removida com sucesso !"<< std::endl; 
        }else removeu = false;
        contador++;
    }
    if( !removeu ) std::cout << "Essa mesa nao tem reserva para o dia "<< data << std::endl;
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
    int tamanho = (mesa).getStatus().size();
	o << "Numero da mesa: " << (mesa).getNumero() << std::endl << "Quantidade de Cadeira: " << (mesa).getQuantidadeCadeira() << std::endl;
    
    if( tamanho == 0 ){
        o << "Essa mesa nao possui nenhuma reserva." << std::endl;
    }
    
    for( auto i = 0; i < tamanho; i++){
        o << (mesa).getStatus()[i];
    }
    return o;
}

std::istream& operator>> ( std::istream &i, Mesa &mesa){
    i >> (mesa).numero__mesa >> (mesa).quantidade_cadeira;

    return i;
}