#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "Vetor_de_segmentos.h"

#define PI 3.141592653589793236433932795029

using namespace std;


//funções que não envolvem geometria
class Math1{

    public:

    template <typename T>
    static T menor(T a,T b){

        if(a<b){
            return a;
        }
        else{
            return b;
        }
    }

    template <typename T>
    static T maior(T a,T b){

        if(a>b){
            return a;
        }
        else{
            return b;
        }
    }




    //////MERGE SORT//////////////////////////////////

    template <typename T>
    static void merge(T vetor[], int esquerda,int meio, int direita, int tamanho){

        T auxiliar[tamanho];

        for(int i = 0; i<tamanho ;i++){
            auxiliar[i] =vetor[i];
        }

        int i = esquerda;
        int i2 = meio +1;
        int i3 = esquerda;


        while(i <= meio && i2 <= direita){
            if(func(auxiliar[i], auxiliar[i2])){
                vetor[i3] = auxiliar[i];
                i++;
            }
            else{
                vetor[i3] = auxiliar[i2];
                i2++;
            }
            i3++;
        }

        while(i<=meio){
            vetor[i3] = auxiliar[i];
            i++;
            i3++;
        }

        while(i2<=direita){
            vetor[i3] = auxiliar[i2];
            i2++;
            i3++;
        }
    }

    template <typename T>
    static void merge_sort2(T vetor[],int tamanho, int esquerda,int direita){

        if (esquerda>=direita){
            return;
        }

        int meio = (esquerda + direita)/2;

        merge_sort2(vetor,tamanho,esquerda,meio);
        merge_sort2(vetor,tamanho,meio+1,direita);

        merge(vetor, esquerda, meio, direita, tamanho);

    }

    template <typename T>
    static void merge_sort(T vetor[], int tamanho){
        merge_sort2(vetor,tamanho,0,tamanho-1);
    }




    template<typename T>
    static T* inverter(T* array,int tamanho){

        T* auxiliar = new T[tamanho];

        for(int i = 0,i2 = tamanho-1;i<tamanho;i++, i2--){

            auxiliar[i] = array[i2];

        }

        return auxiliar;

    }

};
