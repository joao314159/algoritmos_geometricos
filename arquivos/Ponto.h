
#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#define PI 3.141592653589793236433932795029

using namespace std;


template <typename T>
class Ponto{

    public:

    Ponto(){}
    Ponto(T a,T b){

        this->x=a;
        this->y=b;

    }

    T x;
    T y;

    void somar(Ponto<T> ponto1){
        this->x = this->x +ponto1.x;
        this->y = this->y +ponto1.y;
    }

    template <typename tipo2>
    void multiplicar(tipo2 a){

        this->x = (this->x)*a;
        this->y = (this->y)*a;
    }

    template <typename tipo3>
    Ponto<T> operator+(Ponto<tipo3> ponto1){
        Ponto<T> ponto2;
        ponto2.x = this->x+ponto1.x;
        ponto2.y = this->y+ponto1.y;

        return ponto2;
    }

    template <typename tipo5>
    Ponto<T> operator*(tipo5 number){

        Ponto<T> ponto2;

        ponto2.x = (this->x) *number;
        ponto2.y = (this->y) *number;

        return ponto2;
    }

    template <typename tipo6>
    Ponto<T> operator-(Ponto<tipo6> ponto1){
        Ponto<T> ponto2;
        ponto2.x = this->x - ponto1.x;
        ponto2.y = this->y - ponto1.y;

        return ponto2;

    }

    template <typename tipo7>
    Ponto<T> operator/(Ponto<tipo7> ponto1){
        Ponto<T> ponto2;
        ponto2.x = this->x/ponto1.x;
        ponto2.y = this->y/ponto1.y;

        return ponto2;
    }

    void print(){
        cout<<"Coordenadas do ponto: ("<<this->x<<", "<<this->y<<")"<<endl;
    }

};
