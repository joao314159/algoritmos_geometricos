#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "Matriz3.h"

#define PI 3.141592653589793236433932795029

using namespace std;



//útil na função ponto em polígono 3
template <typename T>
class Vetor_de_segmentos{

    public:

    Vetor_de_segmentos(){}

    T y1;
    T y2;
    vector<Segmento<long double>> vetor;

    void print(){
        cout<<endl;
        cout<<"y inicial: "<<y1<<endl;
        cout<<"y final: "<<y2<<endl;

        if(vetor.empty()){
            cout<<"O vector de segmentos está vazio."<<endl;
        }
        else{
            cout<<"O vector de segmentos possui os seguintes segmentos: "<<endl;
            for(int i =0;i<vetor.size();i++){
                cout<<"Segmento "<<i<<": "<<endl;
                vetor[i].print();
            }
        }
    }

};
