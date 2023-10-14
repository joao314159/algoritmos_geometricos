#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>


#include "Segmento.h"

#define PI 3.141592653589793236433932795029

using namespace std;



template <typename T>
class Vetor{

    public:

    Vetor(){}
    Vetor(Segmento<T> segmento){

        this->x = segmento.end.x-segmento.start.x;
        this->y = segmento.end.y-segmento.start.y;

    }

    Vetor(Ponto<T> ponto){

        this->x = ponto.x;
        this->y = ponto.y;
    }

    T x;
    T y;

    long double comprimento(){
        return (  sqrt(  (abs((long double)this->x) ) *  ( abs((long double)this->x) )  + (  abs((long double)this->y) )* ( abs((long double)this->y))  ) );
    }

    Vetor normal(){

        Vetor resultado;

        resultado.x = this->y;
        resultado.y = -(this->x);

        return resultado;
    }

    void print(){
        cout<<"Esse vetor tem módulo "<<this->comprimento()<<" e aponta para ("<<this->x<<", "<<this->y<<")"<<endl;
    }
};
