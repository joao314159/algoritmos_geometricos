#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "Vetor.h"

#define PI 3.141592653589793236433932795029

using namespace std;




template <typename T>
class Matriz2{

    public:

    Matriz2(){ }

    Matriz2(T a, T b, T c, T d){
        content[0][0] = a;
        content[0][1] = b;
        content[1][0] = c;
        content[1][1] = d;
    }

    T content[2][2];

    void preencher(T a,T b, T c, T d){
        content[0][0] = a;
        content[0][1] = b;
        content[1][0] = c;
        content[1][1] = d;
    }

    T determinante(){

        return content[0][0]*content[1][1] - content[0][1]*content[1][0];

    }

    void print(){
        cout<<this->content[0][0]<<" "<<this->content[0][1]<<endl<<this->content[1][0]<<" "<<this->content[1][1]<<endl;
    }

};
