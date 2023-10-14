#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "Ponto.h"

#define PI 3.141592653589793236433932795029

using namespace std;


template <typename T>
class Segmento{

    public:
    Segmento(){}
    Segmento(Ponto<T> ponto1,Ponto<T> ponto2){

        this->start=ponto1;
        this->end=ponto2;

    }

    Ponto<T> start;
    Ponto<T> end;

    void print(){
        cout<<"Esse segmento começa em ("<<this->start.x<<", "<<this->start.y<<") e termina em ("<<this->end.x<<", "<<this->end.y<<") "<<endl;
    }

    void inverter(){
        Ponto<T> ponto;
        ponto = this->start;
        this->start = this->end;
        this->end = ponto;
    }

    bool estranho(){

        Ponto<T> ponto1=this->start;
        Ponto<T> ponto2=this->end;

        string tipo = typeid(ponto1.x).name();
            //cópia da função mesmo_ponto()
            if(&this->start.x == NULL || &this->start.y || NULL || &this->end.x == NULL || &this->end.y ==NULL){

                //cout<<endl<<endl<<"Erro, membros dos pontos são nulos!!!"<<endl<<endl;

            }

            if(tipo == "e" || tipo == "d" ){

                cout<<"não é inteiro"<<endl;
                if( (abs(ponto1.x-ponto2.x) <1e-9 )  &&( abs(ponto1.y- ponto2.y)<1e-9 ) ) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else if(tipo == "i"){

                cout<<"é inteiro"<<endl;
                if( (ponto1.x == ponto2.x) &&(ponto1.y == ponto2.y)) {
                    return true;
                }
                else {
                    return false;
                }

            }
            else{
                cout<<"tipo inapropriado"<<endl;

                cout<<typeid(ponto1.x).name()<<endl;

                return true;
            }

    }

};
