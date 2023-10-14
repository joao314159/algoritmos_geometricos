#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "math2D.h"

#define PI 3.141592653589793236433932795029

using namespace std;




    template <typename T>
    //n�o inclui ponto sobre segmento
    //n�o vai funcionar se n�o passar um pol�gono convexo

    // -1 ponto fora do pol�gono 1 ponto dentro do pol�gono, 0 ponto sobre segmento do pol�gono
    int math2D::ponto_em_poligono_convexo(Ponto<T> ponto, Ponto<T>* poligono, int tamanho_poligono){

        int lado1;

        int a = 2;

        if(tamanho_poligono <=2){

            //cout<<"Erro, pol�gono tem dois ou menos pontos"<<endl;
        }

        if( ponto_sobre_segmento( Segmento<T>(poligono[0],poligono[1]), ponto ) ){

                //cout<<"Ponto sobre segmento"<<endl;
                //cout<<"Segmento come�a em "<<poligono[0].x<<", "<<poligono[0].y<<" e termina em "<<poligono[1].x<<", "<<poligono[1].y<<endl<<endl;
                //cout<<"O ponto � "<<ponto.x<<", "<<ponto.y<<endl<<endl;
                a = 0;
        }

        //que lado o ponto est� em rela��o a primeira reta do pol�gono
        lado1 = lado(Segmento<T>(poligono[0],poligono[1]), ponto);
        //cout<<"lado aresta 1: "<<lado1<<endl;


        for(int i = 1; i<tamanho_poligono-1; i++){

            if( ponto_sobre_segmento( Segmento<T>(poligono[i],poligono[i+1]), ponto ) ){
                //cout<<"Ponto sobre segmento"<<endl;
                //cout<<"Segmento come�a em "<<poligono[i].x<<", "<<poligono[i].y<<" e termina em "<<poligono[i+1].x<<", "<<poligono[i+1].y<<endl<<endl;
                //cout<<"O ponto � "<<ponto.x<<", "<<ponto.y<<endl<<endl;

                a = 0;
            }

            if ( (lado(Segmento<T>(poligono[i],poligono[i+1]), ponto) != lado1 ) && (a != 0) ){

               // cout<<"lado, aresta "<< i+1 <<" : "<< lado(Segmento<T>(poligono[i],poligono[i+1]), ponto) <<endl;
               // cout<<"lado, aresta "<< i+1 <<" : "<< lado1 <<endl;
                a = -1;
            }
        }

        //quando termina o loop, ainda temos que comparar o ponto com a aresta que liga o ponto do final do array
        //com o ponto do in�cio do array

        if( ponto_sobre_segmento( Segmento<T>(poligono[tamanho_poligono-1],poligono[0]), ponto ) ){
           // cout<<"Ponto sobre segmento"<<endl;
            //cout<<"Segmento come�a em "<<poligono[tamanho_poligono-1].x<<", "<<poligono[tamanho_poligono-1].y<<" e termina em "<<poligono[0].x<<", "<<poligono[0].y<<endl<<endl;

            //cout<<"O ponto � "<<ponto.x<<", "<<ponto.y<<endl<<endl;
            a = 0;
        }

        if ( (lado(Segmento<T>(poligono[tamanho_poligono-1],poligono[0]), ponto)!= lado1) && (a != 0)){

           // cout<<"lado, aresta "<< tamanho_poligono <<" : " << lado(Segmento<T>(poligono[tamanho_poligono-1],poligono[0]), ponto) <<endl;
           // cout<<"lado, aresta " <<" : "<< lado1 <<endl;
            a = -1;
        }

        if( (a != 0) && (a != -1)){
            a =1;
        }

        return a;

    }
