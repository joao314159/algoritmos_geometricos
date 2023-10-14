#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "Matriz2.h"

#define PI 3.141592653589793236433932795029

using namespace std;


template <typename T>
class Matriz3{

    public:

    Matriz3(){}

    Matriz3(T a, T b, T c, T d, T e, T f, T g, T h, T i){
        content[0][0] = a;
        content[0][1] = b;
        content[0][2] = c;
        content[1][0] = d;
        content[1][1] = e;
        content[1][2] = f;
        content[2][0] = g;
        content[2][1] = h;
        content[2][2] = i;
    }

    T content[3][3];

    void preencher(T a, T b,T c, T d, T e, T f, T g, T h, T i){
        content[0][0] = a;
        content[0][1] = b;
        content[0][2] = c;
        content[1][0] = d;
        content[1][1] = e;
        content[1][2] = f;
        content[2][0] = g;
        content[2][1] = h;
        content[2][2] = i;
    }

    T determinante(){

        T a1 = this->content[0][0] * this->content[1][1]* this->content[2][2];
        T b1 = this->content[0][1] * this->content[1][2] *this->content[2][0];
        T c1 = this->content[0][2] * this->content[1][0] * this->content[2][1];
        T d1 = this->content[2][0] * this->content[1][1] * this->content[0][2];
        T e1 = this->content[2][1] * this->content[1][2] * this->content[0][0];
        T f1 = this->content[2][2] * this->content[1][0] * this->content[0][1];

        return a1+b1+c1-d1-e1-f1;

    }

    void print(){
        cout<<this->content[0][0]<<" "<<this->content[0][1]<<" "<<this->content[0][2]<<endl<<this->content[1][0]<<" "<<this->content[1][1]<<" "<< this->content[1][2]<<endl<<this->content[2][0]<<" "<<this->content[2][1]<<" "<<this->content[2][2]<<endl;
    }

};
