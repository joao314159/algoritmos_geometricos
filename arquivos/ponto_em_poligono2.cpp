#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>


#include "math2D.h"

#define PI 3.141592653589793236433932795029

using namespace std;

void math2D::ponto_em_poligono2(){

        math2D Math2D;

        //quantos pontos tem o polígono
        int N;


        //quantos pontos dentro ou fora do polígono
        int Q;

        //cout<<"Digite o tamanho do polígono:"<<endl;

        cin>>N;

        //onde vão ficar os pontos do polígono
        Ponto<long double>* forma = new Ponto<long double>[N];


        for(int i = 0; i<N;i++){

            //cout<<"Digite as coordenadas de um vértice: "<<endl;

            cin>>forma[i].x;
            cin>>forma[i].y;

            //cout<<endl;

        }

        N = Math2D.tira_pontos_colineares(forma,N);



        //cout<<"Digite quantos pontos vai ter:"<<endl<<endl;
        cin>>Q;

        Ponto<long double>* pontos1 = new Ponto<long double>[Q];

        for(int i = 0; i<Q;i++){

            //cout<<"Digite as coordenadas de um ponto: "<<endl;
            cin>>pontos1[i].x;
            cin>>pontos1[i].y;
            //cout<<endl;
        }


        bool* dentro = new bool[Q];
        bool* sobre = new bool[Q];



        //crio um ponto dentro po polígono
        Ponto<long double> ponto_do_meio = Math2D.criar_ponto2(forma,N);

        if( Math2D.ponto_em_poligono_convexo(ponto_do_meio, forma, N) == 1 ){
            //cout<<"o ponto está dentro"<<endl;
        }
        else{
            //cout<<"o ponto não está dentro"<<endl;
        }




        /*
        Segmento<long double> segmento1(Ponto<long double>(0.0,0.0), Ponto<long double>(2.43984,2.43984));
        Segmento<long double> segmento2(Ponto<long double>(2.449657,2.449657), Ponto<long double>(3.5424,3.5424));

        if(Math2D.paralelos_e_sobrepostos(segmento1,segmento2)){
            cout<<"teste"<<endl;
        }

        */

        int lado;

         //inverter o polígono caso ele esteja no outro sentido
        if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma[0]), forma[1]) == -1){
            forma = Math1::inverter(forma,N);
        }


        Segmento<long double> meio(ponto_do_meio,forma[0]);

        //cout<<"meio: ("<<forma[0].x<<", "<<forma[0].y<<") "<<endl;

        lado = Math2D.lado(meio,forma[1]);

        bool direita = false;




        //enquanto o lado não mudar

        int x1 =2;

        //cout<<"Meio vai do ponto ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") até o ponto ("<<forma[0].x<<", "<<forma[0].y<<")";

        while( (Math2D.lado(meio,forma[x1])== lado) && (Math2D.lado(meio,forma[x1]) != 0) ){
            x1++;
            //cout<<"("<<forma[x1].x<<", "<<forma[x1].y<<")"<<endl;
        }

        //o trecho entre o segmento final e o segmento inicial é analisado em separado e é feita a busca binária na parte entre o segmento inicial e o segmento final

        Segmento<long double> segmento_inicial(ponto_do_meio, forma[x1-1]);
        Segmento<long double> segmento_final(ponto_do_meio, forma[x1]);



        //trecho analisado em separado
        Ponto<long double>* trecho  = new Ponto<long double>[3];
        trecho[0] = forma[x1-1];
        trecho[1] = ponto_do_meio;
        trecho[2] = forma[x1];

        //cout<<"O trecho vai do ponto ("<<trecho[0].x<<", "<<trecho[0].y<<") até o ponto ("<<trecho[2].x<<", "<<trecho[2].y<<")"<<endl;



        //todo o intervalo atual a ser buscado na busca binária. Começa com todo o polígono menos o trecho

        //começa em trecho[2] e vai até o trecho[0]

        //percorrer no sentido horário

        //refazer o polígono de modo que as coordenadas fiquem na ordem
        Ponto<long double>* forma2 = new Ponto<long double>[N];





        int i0 = 0;
        int i02 =0;

        //coordenada do meio

        int i3;

        while(x1+i0<N){

            forma2[i0] = forma[x1+i0];
            i0++;
        }

        while(i02<x1){

            forma2[i0] = forma[i02];
            i0++;
            i02++;
        }

        for(int i4 = 0;i4<N;i4++){
            //mudo o ponto o meio
            if(Math2D.mesmo_ponto(forma2[i4],meio.end)){
                i3 = i4;
            }
        }


        //teste se o polígono forma2 está correto (funciona eu acho)

        //cout<<"Forma 1 vértices: "<<endl<<endl;

        for(int i = 0;i<N;i++){
           //cout<<"Vértice "<<i+1<<" :("<<forma[i].x<<", "<<forma[i].y<<")"<<endl;
        }

        //cout<<"Forma2 vértices: "<<endl<<endl;
        for(int i = 0;i<N;i++){
           //cout<<"Vértice "<<i+1<<" :("<<forma2[i].x<<", "<<forma2[i].y<<")"<<endl;
        }

        //cout<<"lado 1: "<< Math2D.lado(Segmento<long double>(ponto_do_meio,trecho[0]),pontos1[0])<<endl;

        //cout<<"lado 2: "<< Math2D.lado(Segmento<long double>(ponto_do_meio,trecho[1]),pontos1[0])<<endl;






        for(int i10 = 0; i10<Q; i10++){

                sobre[i10] = false;


                //caso do ponto estar sobre segmento do trecho
                if( ( (Math2D.ponto_sobre_segmento(Segmento<long double>(trecho[0],trecho[2]), pontos1[i10]))) || ( Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,trecho[0]), pontos1[i10])) || ( (Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,trecho[2]),pontos1[i10])) ) ) {

                   //cout<<"Ponto está sobre o segmento do trecho: "<<endl;

                   //cout<<"coordenadas do segmento: ("<<trecho[0].x<<", "<<trecho[0].y<<"), ("<<trecho[2].x<<", "<<trecho[2].y<<") ,("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") "<<endl<<endl;
                   dentro[i10] = true;

                   if(Math2D.ponto_sobre_segmento(Segmento<long double>(trecho[0],trecho[2]),pontos1[i10])){
                       //cout<<"O ponto está sobre o segmento do polígono."<<endl;
                       sobre[i10] = true;
                   }

                   goto exit1;
                }

                //caso do ponto estar dentro do trecho

                else if( (Math2D.lado(Segmento<long double>(ponto_do_meio,trecho[0]),pontos1[i10]) == 1) &&  (Math2D.lado(Segmento<long double>(ponto_do_meio,trecho[2]),pontos1[i10]) == -1) ){

                    //cout<<"ponto está no trecho"<<endl;

                    if(Math2D.lado(Segmento<long double>(trecho[0],trecho[2]),pontos1[i10]) == 1){

                        //cout<<"O ponto está dentro."<<endl;
                        dentro[i10] = true;
                        goto exit1;
                    }
                    else if( Math2D.lado(Segmento<long double>(trecho[0],trecho[2]),pontos1[i10]) == 0 ){
                        //cout<<"O ponto está sobre o segmento do polígono."<<endl;
                        sobre[i10] = true;
                        goto exit1;
                    }

                    else {
                        //cout<<"O ponto não está dentro"<<endl;
                        dentro[i10] = false;
                        goto exit1;
                    }

                }


                else{
                   //fazer a busca binária para encontrar o trecho
                   //a busca binária para quando um dos índices menos a média dos índices for menor ou igual a 1
                   //cout<<"Comparando o o ponto com o segmento meio"<<endl;

                   //se estiver sobre o meio
                   //forma2[i3] é o ponto correspondente ao meio

                   if(Math2D.lado(meio,pontos1[i10]) == 0){
                       //cout<<"ponto está sobre a reta meio"<<endl;

                       if(Math2D.mesmo_ponto(meio.end,pontos1[i10])){
                            //cout<<"Ponto está sobre segmento do polígono"<<endl;
                            sobre[i10] = true;
                       }

                       if(Math2D.ponto_sobre_segmento(meio,pontos1[i10]))  {
                            //cout<<"O ponto está sobre o segmento meio"<<endl<<endl;
                            dentro[i10] = true;
                            goto exit1;
                       }
                   }








                   //se estiver a direita
                   else if(Math2D.lado(meio,pontos1[i10]) ==1){


                       //cout<<"ponto está a direita do segmento meio"<<endl;
                       //mudo o início para o meio, limitando o trecho à parte a direita


                       direita = true;

                       //índice do início
                       int start = i3;
                       //cout<<"coordenada do meio: ("<<forma2[i3].x<<", "<<forma2[i3].y<<")"<<endl;

                       //índice do fim
                       int end = N-1;

                       if(start == end){
                        //cout<<"teste 1"<<endl;
                       }

                       //a busca binária termina quando (início +fim)/2 é no máximo 1 de distância do fim
                       while( (abs((double)(start + end)/2.0)- (double)start) >= 1.0 ){
                            //fazer a busca binária na esquerda

                            //compara o ponto com o segmento na média do trecho

                            //caso o ponto está sobre a reta
                            if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == 0){

                                //cout<<"O ponto está sobre a reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;

                                //ver se o ponto está sobre o segmento
                                if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10])){
                                    //cout<<"O ponto está sobre o segmento."<<endl;

                                    if(Math2D.mesmo_ponto(forma2[(int)((start+end)/2)] , pontos1[i10])){
                                        //cout<<"O ponto está sobre o segmento do polígono."<<endl;
                                        sobre[i10] = true;
                                    }

                                    dentro[i10] = true;
                                    goto exit1;
                                }
                                else{
                                    //o ponto não está sobre o segmento
                                    dentro[i10] = false;
                                    goto exit1;
                                }

                            }
                            //fim caso ponto está sobre a reta

                            //caso ponto está a direita
                            else if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == 1){
                                //cout<<"O ponto está a direita da reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;
                                direita = true;
                                start = (int)((double)(start+end)/2.0);

                            }
                            else if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == -1 ){
                                //cout<<"O ponto está a esquerda da reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;
                                direita = false;


                                end =(int)((double(start+end)/2.0)) ;

                            }

                       }
                       //fim do while


                       if( (end - start) != 1){
                           //cout<<"Erro!! trecho encontrado não é válido!"<<endl<<endl;
                           //cout<<"start: "<<start<<endl;
                           //cout<<"end :"<<end<<endl;

                       }
                       else{
                            //encontramos o trecho que é delimitado pelos vértices ponto_do_meio, forma2[start] e forma2[end]

                            //estamos a esquerda do último segmento
                            //if(! direita){
                            //    end = start;
                            //    start = end-1;
                            //}

                            //cout<<"start: "<<start<<endl;
                            //cout<<"end: "<<end<<endl;

                            //cout<<"trecho encontrado, vértices: ("<<forma2[start].x<<", "<<forma2[start].y<<") e ("<<forma2[end].x<<", "<<forma2[end].y<<")"<<endl<<endl;

                            //verificar se o ponto está sobre um dos segmentos do trecho
                            if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[start]), pontos1[i10])){
                                //cout<<"O ponto está sobre o segmento do trecho"<<endl;

                                if(Math2D.mesmo_ponto(forma2[start],pontos1[i10])){
                                    //cout<<"O ponto está sobre o segmento do polígono."<<endl;
                                    sobre[i10] = true;
                                }

                                dentro[i10] = true;
                                goto exit1;
                            }
                            else if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[end]), pontos1[i10])){
                                //cout<<"O ponto está sobre o segmento do trecho"<<endl;

                                 if(Math2D.mesmo_ponto(forma2[end],pontos1[i10])){
                                    //cout<<"O ponto está sobre o segmento do polígono."<<endl;
                                    sobre[i10] = true;
                                }

                                dentro[i10] = true;
                                goto exit1;
                            }

                            else{
                                if(Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 0 || Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 1){
                                    //cout<<"O ponto está dentro do polígono!"<<endl<<endl;

                                    if(Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 0){
                                        //cout<<"O ponto está sobre o segmento do polígono"<<endl;
                                        sobre[i10] = true;
                                    }

                                    dentro[i10] = true;
                                }
                                else{
                                    //cout<<"O ponto está fora do polígono!"<<endl<<endl;
                                    dentro[i10] = false;
                                }

                            }

                       }

                   }













                   //se estiver a esquerda
                   else if(Math2D.lado(meio,pontos1[i10]) == -1){
                       //cout<<"ponto está a esquerda do segmento meio"<<endl;
                       //mudo o final do segmento para o meio, limitando o trecho à parte à esquerda


                       direita = false;

                       //índice do início
                       int start = 0;

                       //índice do fim
                       int end = i3;


                       //cout<<"coordenada do início: ("<<forma2[start].x<<", "<<forma2[start].y<<")"<<endl;

                       //cout<<"coordenada do meio: ("<<forma2[i3].x<<", "<<forma[i3].y<<")"<<endl;

                       //cout<<i3<<endl;

                       if(start == end){

                           dentro[i10] = false;
                           //cout<< "O ponto está a esquerda do segmento meio, mas a esquerda do meio é o trecho"<<endl;
                           //cout<<"O ponto está fora"<<endl;
                           goto exit1;

                       }

                       //a busca binária termina quando (início +fim)/2 é no máximo 1 de distância do fim
                       while( (abs((double)(start + end)/2.0)-(double)start) >= 1.0){
                            //fazer a busca binária na esquerda

                            //compara o ponto com o segmento na média do trecho

                            //caso o ponto está sobre a reta
                            if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == 0){

                                //cout<<"O ponto está sobre a reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;

                                //ver se o ponto está sobre o segmento
                                if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10])){
                                    //cout<<"O ponto está sobre o segmento."<<endl;

                                    if(Math2D.mesmo_ponto(forma2[(int)((start+end)/2)],pontos1[i10])){
                                        //cout<<"O ponto está sobre o segmento do polígono, e"<<endl;
                                        sobre[i10] = true;
                                    }

                                    dentro[i10] = true;
                                    goto exit1;
                                }
                                else{
                                    //o ponto não está sobre o segmento
                                    dentro[i10] = false;
                                    goto exit1;
                                }

                            }
                            //fim caso ponto está sobre a reta

                            //caso ponto está a direita
                            else if( Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == 1){
                                //cout<<"O ponto está a direita da reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;

                                direita = true;

                                start = (int)((double)(start+end)/2.0);

                            }
                            else if( Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == -1 ){
                                //cout<<"O ponto está a esquerda da reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;

                                direita = false;

                                end =(int)((double)(start+end)/2.0) ;
                            }

                       }
                       //fim do while


                       if( (end - start) != 1){
                           //cout<<"Erro!! trecho encontrado não é válido!"<<endl<<endl;

                           //cout<<"start: "<<start<<endl;
                           //cout<<"end :"<<end<<endl;
                       }
                       else{
                            //encontramos o trecho que é delimitado pelos vértices ponto_do_meio, forma2[start] e forma2[end]

                            //estamos a esquerda do último segmento
                            //if(! direita){
                            //    //cout<<"teste"<<endl;
                            //    end = start;
                            //    start = end-1;
                            //}
                            //cout<<"start: "<<start<<endl;
                            //cout<<"end: "<<end<<endl;

                            //cout<<"trecho encontrado, vértices: ("<<forma2[start].x<<", "<<forma2[start].y<<") e ("<<forma2[end].x<<", "<<forma2[end].y<<")"<<endl<<endl;

                            //verificar se o ponto está sobre um dos segmentos do trecho
                            if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[start]), pontos1[i10])){
                                //cout<<"O ponto está sobre o segmento do trecho"<<endl;

                                if(Math2D.mesmo_ponto(forma2[start],pontos1[i10])){
                                    //cout<<"O ponto está sobre o segmento do polígono."<<endl;
                                    sobre[i10]  =true;
                                }
                                dentro[i10] = true;
                            }
                            else if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[end]), pontos1[i10])){
                                //cout<<"O ponto está sobre o segmento do trecho"<<endl;

                                if(Math2D.mesmo_ponto(forma2[end],pontos1[i10])){
                                    //cout<<"O ponto está sobre o segmento do polígono."<<endl;
                                    sobre[i10]  =true;
                                }

                                dentro[i10] = true;
                            }

                            else{
                                if(Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 0 || Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 1){
                                    //cout<<"O ponto está dentro do polígono!"<<endl<<endl;

                                    if(Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 0 ){
                                        //cout<<"O ponto está sobre o segmento do polígono."<<endl;
                                        sobre[i10] = true;
                                    }

                                    dentro[i10] = true;
                                }
                                else{
                                    //cout<<"O ponto está fora do polígono!"<<endl<<endl;
                                    dentro[i10] = false;
                                }
                            }
                        }
                    }
                }

            exit1:
            ;

        }


        //cout<<endl<<endl;

        //cout<<"resultado: "<<endl;

        for(int i = 0;i<Q;i++){

                if(sobre[i]){
                    cout<<"EMCIMA"<<endl;
                }
                else if(dentro[i]){

                    cout<<"DENTRO"<<endl;
                }
                else{
                    cout<<"FORA"<<endl;
                }
        }


        /*

        exemplos de casos de teste

        teste 5

        8
        0.0 20.0
        11.0 21.0
        20.0 20.0
        21.0 10.0
        20.0 0.0
        13.0 0.0
        7.4284 0.0
        0.0 0.0
        13
        1.2 3.2
        0.02 0.14
        7.4 18.3
        9.975 19.9993
        0.363 7.34
        9.45 0.62
        0.0 2.634
        14.0 0.0
        -0.236 2.54
        30.23 5.76
        0.0 -3.54
        23.4 20.0
        0.0 33.4


        teste 4

        6
        0.0 20.0
        11.0 21.0
        20.0 20.0
        21.0 10.0
        20.0 0.0
        0.0 0.0
        13
        1.2 3.2
        0.02 0.14
        7.4 18.3
        9.975 19.9993
        0.363 7.34
        9.45 0.62
        0.0 2.634
        14.0 0.0
        -0.236 2.54
        30.23 5.76
        0.0 -3.54
        23.4 20.0
        0.0 33.4

        DENTRO
        DENTRO
        DENTRO
        DENTRO
        DENTRO
        DENTRO
        sobre
        sobre
        FORA
        FORA
        FORA
        FORA
        FORA



        teste 3

        4
        0.0 10.0
        10.0 10.0
        10.0 0.0
        0.0 0.0
        13
        1.2 3.2
        0.02 0.14
        7.4 8.3
        9.975 9.9993
        0.363 7.34
        9.45 0.62
        0.0 2.634
        10.0 10.0
        -0.236 2.54
        10.23 5.76
        0.0 -3.54
        13.4 0.0
        0.0 33.4

        DENTRO
        DENTRO
        DENTRO
        DENTRO
        DENTRO
        DENTRO
        sobre
        sobre
        FORA
        FORA
        FORA
        FORA
        FORA







        teste 2

        4
        100 0
        0 100
        -100 0
        0 -100
        4
        0 0
        50 -50
        -10 -70
        -20 99

        DENTRO
        EMCIMA
        DENTRO
        FORA


        teste 1

        3
        0.0 0.0
        10.0 0.0
        0.0 10.0
        7
        0.0 0.0
        0.0 2.5
        4.6 0.0
        -2.64 0.0
        13.53 27.9
        9.8 11.4
        1.3 2.375

        sobre
        sobre
        sobre
        FORA
        FORA
        FORA
        dentro

        */

    }
