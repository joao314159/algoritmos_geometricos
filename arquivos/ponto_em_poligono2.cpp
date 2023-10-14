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

        //quantos pontos tem o pol�gono
        int N;


        //quantos pontos dentro ou fora do pol�gono
        int Q;

        //cout<<"Digite o tamanho do pol�gono:"<<endl;

        cin>>N;

        //onde v�o ficar os pontos do pol�gono
        Ponto<long double>* forma = new Ponto<long double>[N];


        for(int i = 0; i<N;i++){

            //cout<<"Digite as coordenadas de um v�rtice: "<<endl;

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



        //crio um ponto dentro po pol�gono
        Ponto<long double> ponto_do_meio = Math2D.criar_ponto2(forma,N);

        if( Math2D.ponto_em_poligono_convexo(ponto_do_meio, forma, N) == 1 ){
            //cout<<"o ponto est� dentro"<<endl;
        }
        else{
            //cout<<"o ponto n�o est� dentro"<<endl;
        }




        /*
        Segmento<long double> segmento1(Ponto<long double>(0.0,0.0), Ponto<long double>(2.43984,2.43984));
        Segmento<long double> segmento2(Ponto<long double>(2.449657,2.449657), Ponto<long double>(3.5424,3.5424));

        if(Math2D.paralelos_e_sobrepostos(segmento1,segmento2)){
            cout<<"teste"<<endl;
        }

        */

        int lado;

         //inverter o pol�gono caso ele esteja no outro sentido
        if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma[0]), forma[1]) == -1){
            forma = Math1::inverter(forma,N);
        }


        Segmento<long double> meio(ponto_do_meio,forma[0]);

        //cout<<"meio: ("<<forma[0].x<<", "<<forma[0].y<<") "<<endl;

        lado = Math2D.lado(meio,forma[1]);

        bool direita = false;




        //enquanto o lado n�o mudar

        int x1 =2;

        //cout<<"Meio vai do ponto ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") at� o ponto ("<<forma[0].x<<", "<<forma[0].y<<")";

        while( (Math2D.lado(meio,forma[x1])== lado) && (Math2D.lado(meio,forma[x1]) != 0) ){
            x1++;
            //cout<<"("<<forma[x1].x<<", "<<forma[x1].y<<")"<<endl;
        }

        //o trecho entre o segmento final e o segmento inicial � analisado em separado e � feita a busca bin�ria na parte entre o segmento inicial e o segmento final

        Segmento<long double> segmento_inicial(ponto_do_meio, forma[x1-1]);
        Segmento<long double> segmento_final(ponto_do_meio, forma[x1]);



        //trecho analisado em separado
        Ponto<long double>* trecho  = new Ponto<long double>[3];
        trecho[0] = forma[x1-1];
        trecho[1] = ponto_do_meio;
        trecho[2] = forma[x1];

        //cout<<"O trecho vai do ponto ("<<trecho[0].x<<", "<<trecho[0].y<<") at� o ponto ("<<trecho[2].x<<", "<<trecho[2].y<<")"<<endl;



        //todo o intervalo atual a ser buscado na busca bin�ria. Come�a com todo o pol�gono menos o trecho

        //come�a em trecho[2] e vai at� o trecho[0]

        //percorrer no sentido hor�rio

        //refazer o pol�gono de modo que as coordenadas fiquem na ordem
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


        //teste se o pol�gono forma2 est� correto (funciona eu acho)

        //cout<<"Forma 1 v�rtices: "<<endl<<endl;

        for(int i = 0;i<N;i++){
           //cout<<"V�rtice "<<i+1<<" :("<<forma[i].x<<", "<<forma[i].y<<")"<<endl;
        }

        //cout<<"Forma2 v�rtices: "<<endl<<endl;
        for(int i = 0;i<N;i++){
           //cout<<"V�rtice "<<i+1<<" :("<<forma2[i].x<<", "<<forma2[i].y<<")"<<endl;
        }

        //cout<<"lado 1: "<< Math2D.lado(Segmento<long double>(ponto_do_meio,trecho[0]),pontos1[0])<<endl;

        //cout<<"lado 2: "<< Math2D.lado(Segmento<long double>(ponto_do_meio,trecho[1]),pontos1[0])<<endl;






        for(int i10 = 0; i10<Q; i10++){

                sobre[i10] = false;


                //caso do ponto estar sobre segmento do trecho
                if( ( (Math2D.ponto_sobre_segmento(Segmento<long double>(trecho[0],trecho[2]), pontos1[i10]))) || ( Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,trecho[0]), pontos1[i10])) || ( (Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,trecho[2]),pontos1[i10])) ) ) {

                   //cout<<"Ponto est� sobre o segmento do trecho: "<<endl;

                   //cout<<"coordenadas do segmento: ("<<trecho[0].x<<", "<<trecho[0].y<<"), ("<<trecho[2].x<<", "<<trecho[2].y<<") ,("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") "<<endl<<endl;
                   dentro[i10] = true;

                   if(Math2D.ponto_sobre_segmento(Segmento<long double>(trecho[0],trecho[2]),pontos1[i10])){
                       //cout<<"O ponto est� sobre o segmento do pol�gono."<<endl;
                       sobre[i10] = true;
                   }

                   goto exit1;
                }

                //caso do ponto estar dentro do trecho

                else if( (Math2D.lado(Segmento<long double>(ponto_do_meio,trecho[0]),pontos1[i10]) == 1) &&  (Math2D.lado(Segmento<long double>(ponto_do_meio,trecho[2]),pontos1[i10]) == -1) ){

                    //cout<<"ponto est� no trecho"<<endl;

                    if(Math2D.lado(Segmento<long double>(trecho[0],trecho[2]),pontos1[i10]) == 1){

                        //cout<<"O ponto est� dentro."<<endl;
                        dentro[i10] = true;
                        goto exit1;
                    }
                    else if( Math2D.lado(Segmento<long double>(trecho[0],trecho[2]),pontos1[i10]) == 0 ){
                        //cout<<"O ponto est� sobre o segmento do pol�gono."<<endl;
                        sobre[i10] = true;
                        goto exit1;
                    }

                    else {
                        //cout<<"O ponto n�o est� dentro"<<endl;
                        dentro[i10] = false;
                        goto exit1;
                    }

                }


                else{
                   //fazer a busca bin�ria para encontrar o trecho
                   //a busca bin�ria para quando um dos �ndices menos a m�dia dos �ndices for menor ou igual a 1
                   //cout<<"Comparando o o ponto com o segmento meio"<<endl;

                   //se estiver sobre o meio
                   //forma2[i3] � o ponto correspondente ao meio

                   if(Math2D.lado(meio,pontos1[i10]) == 0){
                       //cout<<"ponto est� sobre a reta meio"<<endl;

                       if(Math2D.mesmo_ponto(meio.end,pontos1[i10])){
                            //cout<<"Ponto est� sobre segmento do pol�gono"<<endl;
                            sobre[i10] = true;
                       }

                       if(Math2D.ponto_sobre_segmento(meio,pontos1[i10]))  {
                            //cout<<"O ponto est� sobre o segmento meio"<<endl<<endl;
                            dentro[i10] = true;
                            goto exit1;
                       }
                   }








                   //se estiver a direita
                   else if(Math2D.lado(meio,pontos1[i10]) ==1){


                       //cout<<"ponto est� a direita do segmento meio"<<endl;
                       //mudo o in�cio para o meio, limitando o trecho � parte a direita


                       direita = true;

                       //�ndice do in�cio
                       int start = i3;
                       //cout<<"coordenada do meio: ("<<forma2[i3].x<<", "<<forma2[i3].y<<")"<<endl;

                       //�ndice do fim
                       int end = N-1;

                       if(start == end){
                        //cout<<"teste 1"<<endl;
                       }

                       //a busca bin�ria termina quando (in�cio +fim)/2 � no m�ximo 1 de dist�ncia do fim
                       while( (abs((double)(start + end)/2.0)- (double)start) >= 1.0 ){
                            //fazer a busca bin�ria na esquerda

                            //compara o ponto com o segmento na m�dia do trecho

                            //caso o ponto est� sobre a reta
                            if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == 0){

                                //cout<<"O ponto est� sobre a reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;

                                //ver se o ponto est� sobre o segmento
                                if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10])){
                                    //cout<<"O ponto est� sobre o segmento."<<endl;

                                    if(Math2D.mesmo_ponto(forma2[(int)((start+end)/2)] , pontos1[i10])){
                                        //cout<<"O ponto est� sobre o segmento do pol�gono."<<endl;
                                        sobre[i10] = true;
                                    }

                                    dentro[i10] = true;
                                    goto exit1;
                                }
                                else{
                                    //o ponto n�o est� sobre o segmento
                                    dentro[i10] = false;
                                    goto exit1;
                                }

                            }
                            //fim caso ponto est� sobre a reta

                            //caso ponto est� a direita
                            else if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == 1){
                                //cout<<"O ponto est� a direita da reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;
                                direita = true;
                                start = (int)((double)(start+end)/2.0);

                            }
                            else if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == -1 ){
                                //cout<<"O ponto est� a esquerda da reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;
                                direita = false;


                                end =(int)((double(start+end)/2.0)) ;

                            }

                       }
                       //fim do while


                       if( (end - start) != 1){
                           //cout<<"Erro!! trecho encontrado n�o � v�lido!"<<endl<<endl;
                           //cout<<"start: "<<start<<endl;
                           //cout<<"end :"<<end<<endl;

                       }
                       else{
                            //encontramos o trecho que � delimitado pelos v�rtices ponto_do_meio, forma2[start] e forma2[end]

                            //estamos a esquerda do �ltimo segmento
                            //if(! direita){
                            //    end = start;
                            //    start = end-1;
                            //}

                            //cout<<"start: "<<start<<endl;
                            //cout<<"end: "<<end<<endl;

                            //cout<<"trecho encontrado, v�rtices: ("<<forma2[start].x<<", "<<forma2[start].y<<") e ("<<forma2[end].x<<", "<<forma2[end].y<<")"<<endl<<endl;

                            //verificar se o ponto est� sobre um dos segmentos do trecho
                            if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[start]), pontos1[i10])){
                                //cout<<"O ponto est� sobre o segmento do trecho"<<endl;

                                if(Math2D.mesmo_ponto(forma2[start],pontos1[i10])){
                                    //cout<<"O ponto est� sobre o segmento do pol�gono."<<endl;
                                    sobre[i10] = true;
                                }

                                dentro[i10] = true;
                                goto exit1;
                            }
                            else if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[end]), pontos1[i10])){
                                //cout<<"O ponto est� sobre o segmento do trecho"<<endl;

                                 if(Math2D.mesmo_ponto(forma2[end],pontos1[i10])){
                                    //cout<<"O ponto est� sobre o segmento do pol�gono."<<endl;
                                    sobre[i10] = true;
                                }

                                dentro[i10] = true;
                                goto exit1;
                            }

                            else{
                                if(Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 0 || Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 1){
                                    //cout<<"O ponto est� dentro do pol�gono!"<<endl<<endl;

                                    if(Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 0){
                                        //cout<<"O ponto est� sobre o segmento do pol�gono"<<endl;
                                        sobre[i10] = true;
                                    }

                                    dentro[i10] = true;
                                }
                                else{
                                    //cout<<"O ponto est� fora do pol�gono!"<<endl<<endl;
                                    dentro[i10] = false;
                                }

                            }

                       }

                   }













                   //se estiver a esquerda
                   else if(Math2D.lado(meio,pontos1[i10]) == -1){
                       //cout<<"ponto est� a esquerda do segmento meio"<<endl;
                       //mudo o final do segmento para o meio, limitando o trecho � parte � esquerda


                       direita = false;

                       //�ndice do in�cio
                       int start = 0;

                       //�ndice do fim
                       int end = i3;


                       //cout<<"coordenada do in�cio: ("<<forma2[start].x<<", "<<forma2[start].y<<")"<<endl;

                       //cout<<"coordenada do meio: ("<<forma2[i3].x<<", "<<forma[i3].y<<")"<<endl;

                       //cout<<i3<<endl;

                       if(start == end){

                           dentro[i10] = false;
                           //cout<< "O ponto est� a esquerda do segmento meio, mas a esquerda do meio � o trecho"<<endl;
                           //cout<<"O ponto est� fora"<<endl;
                           goto exit1;

                       }

                       //a busca bin�ria termina quando (in�cio +fim)/2 � no m�ximo 1 de dist�ncia do fim
                       while( (abs((double)(start + end)/2.0)-(double)start) >= 1.0){
                            //fazer a busca bin�ria na esquerda

                            //compara o ponto com o segmento na m�dia do trecho

                            //caso o ponto est� sobre a reta
                            if(Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == 0){

                                //cout<<"O ponto est� sobre a reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;

                                //ver se o ponto est� sobre o segmento
                                if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10])){
                                    //cout<<"O ponto est� sobre o segmento."<<endl;

                                    if(Math2D.mesmo_ponto(forma2[(int)((start+end)/2)],pontos1[i10])){
                                        //cout<<"O ponto est� sobre o segmento do pol�gono, e"<<endl;
                                        sobre[i10] = true;
                                    }

                                    dentro[i10] = true;
                                    goto exit1;
                                }
                                else{
                                    //o ponto n�o est� sobre o segmento
                                    dentro[i10] = false;
                                    goto exit1;
                                }

                            }
                            //fim caso ponto est� sobre a reta

                            //caso ponto est� a direita
                            else if( Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == 1){
                                //cout<<"O ponto est� a direita da reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;

                                direita = true;

                                start = (int)((double)(start+end)/2.0);

                            }
                            else if( Math2D.lado(Segmento<long double>(ponto_do_meio,forma2[(int)((start+end)/2)]),pontos1[i10]) == -1 ){
                                //cout<<"O ponto est� a esquerda da reta que vai do ponto: ("<<ponto_do_meio.x<<", "<<ponto_do_meio.y<<") ao ponto ("<<forma2[(int)((start+end)/2)].x<<", "<<forma2[(int)((start+end)/2)].y<<")"<<endl<<endl;

                                direita = false;

                                end =(int)((double)(start+end)/2.0) ;
                            }

                       }
                       //fim do while


                       if( (end - start) != 1){
                           //cout<<"Erro!! trecho encontrado n�o � v�lido!"<<endl<<endl;

                           //cout<<"start: "<<start<<endl;
                           //cout<<"end :"<<end<<endl;
                       }
                       else{
                            //encontramos o trecho que � delimitado pelos v�rtices ponto_do_meio, forma2[start] e forma2[end]

                            //estamos a esquerda do �ltimo segmento
                            //if(! direita){
                            //    //cout<<"teste"<<endl;
                            //    end = start;
                            //    start = end-1;
                            //}
                            //cout<<"start: "<<start<<endl;
                            //cout<<"end: "<<end<<endl;

                            //cout<<"trecho encontrado, v�rtices: ("<<forma2[start].x<<", "<<forma2[start].y<<") e ("<<forma2[end].x<<", "<<forma2[end].y<<")"<<endl<<endl;

                            //verificar se o ponto est� sobre um dos segmentos do trecho
                            if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[start]), pontos1[i10])){
                                //cout<<"O ponto est� sobre o segmento do trecho"<<endl;

                                if(Math2D.mesmo_ponto(forma2[start],pontos1[i10])){
                                    //cout<<"O ponto est� sobre o segmento do pol�gono."<<endl;
                                    sobre[i10]  =true;
                                }
                                dentro[i10] = true;
                            }
                            else if(Math2D.ponto_sobre_segmento(Segmento<long double>(ponto_do_meio,forma2[end]), pontos1[i10])){
                                //cout<<"O ponto est� sobre o segmento do trecho"<<endl;

                                if(Math2D.mesmo_ponto(forma2[end],pontos1[i10])){
                                    //cout<<"O ponto est� sobre o segmento do pol�gono."<<endl;
                                    sobre[i10]  =true;
                                }

                                dentro[i10] = true;
                            }

                            else{
                                if(Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 0 || Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 1){
                                    //cout<<"O ponto est� dentro do pol�gono!"<<endl<<endl;

                                    if(Math2D.lado(Segmento<long double>(forma2[start],forma2[end]),pontos1[i10]) == 0 ){
                                        //cout<<"O ponto est� sobre o segmento do pol�gono."<<endl;
                                        sobre[i10] = true;
                                    }

                                    dentro[i10] = true;
                                }
                                else{
                                    //cout<<"O ponto est� fora do pol�gono!"<<endl<<endl;
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
