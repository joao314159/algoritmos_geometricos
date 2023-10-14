#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "math2D.h"

#define PI 3.141592653589793236433932795029

using namespace std;

    //função para ponto_em_poligono3()

    //true = goto exit2 false = não goto exit2
    bool math2D::busca_binaria1(int a,int start,int end,int meio,Vetor_de_segmentos<long double>* trechos, bool* dentro, bool* sobre, int i,Ponto<long double>* pontos1){

        //índice do início do trecho
        a = start;

        start = 0;
        end = trechos[a].vetor.size()- 1;
        meio = (start+end)/2;

        //se o ponto estiver à esquerda do primeiro segmento
        if(math2D::lado(trechos[a].vetor[0],pontos1[i]) == -1){
            dentro[i] = false;
            return true;
        }

        if(math2D::lado(trechos[a].vetor[trechos[a].vetor.size()- 1],pontos1[i]) == 1){
            dentro[i] = false;
            return true;
        }
        //se o ponto estiver sobre um desses segmentos
         if( (math2D::lado(trechos[a].vetor[0],pontos1[i]) == 0 ) || (math2D::lado(trechos[a].vetor[trechos[a].vetor.size()- 1],pontos1[i]) == 0) ){
            sobre[i] = true;
            return true;
        }

        while((meio-start) >=1){
             if(math2D::lado(trechos[a].vetor[meio],pontos1[i]) == 1){
                start = meio;
                meio = (start+end)/2;
            }
            else if(math2D::lado(trechos[a].vetor[meio],pontos1[i]) == -1){
                end = meio;
                meio = (start+end)/2;
            }
            else if(math2D::lado(trechos[a].vetor[meio],pontos1[i]) == 0){
                sobre[i] = true;
                return true;
            }
        }

        if( (start+1) %2 == 1){
            cout<<start<<endl;
            dentro[i] =true;
        }
        else{
            cout<<start<<endl;
            dentro[i]=false;
        }
        return false;

    }


    //funciona para polígonos não convexos
    void math2D::ponto_em_poligono3(){

        math2D Math2D;

        //quantos pontos tem o polígono
        int N;

        //quantos pontos dentro ou fora do polígono
        int Q;

        //cout<<"Digite o tamanho do polígono:"<<endl;

        cin>>N;

        bool do_goto_exit2;

        //onde vão ficar os pontos do polígono
        Ponto<long double>* forma = new Ponto<long double>[N];

        for(int i = 0; i<N;i++){

            //cout<<"Digite as coordenadas de um vértice: "<<endl;

            cin>>forma[i].x;
            cin>>forma[i].y;

            //cout<<endl;

        }

        N = math2D::tira_pontos_colineares(forma,N);

        //cout<<"Digite quantos pontos vai ter:"<<endl<<endl;
        cin>>Q;

        Ponto<long double>* pontos1 = new Ponto<long double>[Q];

        for(int i = 0; i<Q;i++){

            //cout<<"Digite as coordenadas de um ponto: "<<endl;
            cin>>pontos1[i].x;
            cin>>pontos1[i].y;
            //cout<<endl;

        }

        vector<Vetor_de_segmentos<long double>> trechos;

        long double* y = new long double[N];

        bool* dentro = new bool[Q];
        bool* sobre = new bool[Q];
        bool* sobre2 = new bool[Q];

        for(int i =0; i<Q;i++){
            sobre[i] = false;
            sobre2[i] = false;
        }


        //os pontos de forma3 ficarão ordenados pelo y
        Ponto<long double>* forma3 = new Ponto<long double>[N];

        for(int i = 0; i<N; i++){
            forma3[i] = forma[i];
        }

        //os pontos de forma4 ficarão ordenados pelo x;
        Ponto<long double>* forma4 = new Ponto<long double>[N];

        for(int i = 0; i<N; i++){
            forma4[i] = forma[i];
        }

        math2D::ordena_pontos_pelo_eixo_x(forma4,N);
        long double menor_x = forma4[0].x;
        long double maior_x = forma4[N-1].x;

        math2D::ordena_pontos_pelo_eixo_y(forma3,N);

        int contador = 0;
        int quantidade_de_trechos = 0;

        while(true){

            while(forma3[contador+1].y == forma3[contador].y && contador<(N-2)){
                contador++;
            }


            if(contador >= (N-1) ){break;}

            else{

                if(forma3[contador].y != forma3[contador+1].y){
                    Vetor_de_segmentos<long double> a;
                    a.y1 = forma3[contador].y;
                    a.y2 = forma3[contador+1].y;

                    trechos.push_back(a);
                    contador++;
                    quantidade_de_trechos++;
                }
                else{
                    break;
                }
            }

        }

        int quantidade_de_segmentos =0;

        //para cada vetor de segmentos adicionar os segmentos que cruzam a reta horizontal

        for(int i = 0;i<quantidade_de_trechos;i++){


            quantidade_de_segmentos = 0;

            Segmento<long double> horizontal(Ponto<long double>(menor_x - 2.0,trechos[i].y1),Ponto<long double>(maior_x + 2.0,trechos[i].y2));

            //verificar cada par de pontos
            for(int i2 = 0;i2<(N-1);i2++){
                if(!math2D::paralelos(Segmento<long double>(forma[i2],forma[i2+1]),horizontal) && (math2D::cruza2(Segmento<long double>(forma[i2],forma[i2+1]),horizontal)==1) ){
                    //os segmentos cruzam
                    trechos[i].vetor.push_back(Segmento<long double>(forma[i2],forma[i2+1]));
                    quantidade_de_segmentos++;
                }
                //caso em que só um ponto da extremidade de um segmento coincide com o outro
                else if(!math2D::paralelos(Segmento<long double>(forma[i2],forma[i2+1]),horizontal) && (math2D::cruza2(Segmento<long double>(forma[i2],forma[i2+1]),horizontal)==0)){

                    if(forma[i2].y >horizontal.start.y || forma[i2+1].y >horizontal.start.y){
                        trechos[i].vetor.push_back(Segmento<long double>(forma[i2],forma[i2+1]));
                        quantidade_de_segmentos++;
                    }
                }
            }

            //comparar o último par de pontos
            if(!math2D::paralelos(Segmento<long double>(forma[N-1],forma[0]),horizontal) && (math2D::cruza2(Segmento<long double>(forma[N-1],forma[0]),horizontal)==1) ){
                //os segmentos cruzam
                trechos[i].vetor.push_back(Segmento<long double>(forma[N-1],forma[0]));
                quantidade_de_segmentos++;

            }
            //caso em que só um ponto da extremidade de um segmento coincide com o outro
            else if(!math2D::paralelos(Segmento<long double>(forma[N-1],forma[0]),horizontal) && (math2D::cruza2(Segmento<long double>(forma[N-1],forma[0]),horizontal)==0)){

                if(forma[N-1].y >horizontal.start.y || forma[0].y > horizontal.start.y){
                    trechos[i].vetor.push_back(Segmento<long double>(forma[N-1],forma[0]));
                    quantidade_de_segmentos++;
                }
            }


            for(int i2 = 0;i2<trechos[i].vetor.size();i2++){

                //se o y do início do segmento for maior que o y do final do segmento
                if(trechos[i].vetor[i2].start.y > trechos[i].vetor[i2].end.y){
                    trechos[i].vetor[i2].inverter();
                }

            }


            //ordenar os segmentos
            math2D::ordena_segmentos(&trechos[i].vetor[0],quantidade_de_segmentos,trechos[i].y1,trechos[i].y2);

        }

        cout<<Q<<endl;
        for(int i =0;i<Q;i++){


            //fazer a busca binária para encontrar o trecho, depois fazer a busca binária para encontrar o segmento

            Segmento<long double> final1(Ponto<long double>(1,trechos[trechos.size()-1].y2),Ponto<long double>(2,trechos[trechos.size()-1].y2));
            Segmento<long double> inicial1(Ponto<long double>(1,trechos[0].y1),Ponto<long double>(2,trechos[0].y1));

            int lado;

            int start;
            int end;
            int meio;
            int a;

            lado = math2D::lado(final1,pontos1[i]);

            /////////////////////////////////////////////
            //se estiver acima do último y
            /////////////////////////////////////////////
            if(lado == -1){
                dentro[i] = false;
                goto exit2;
            }

            lado = math2D::lado(inicial1,pontos1[i]);
            /////////////////////////////////////////////
            //se estiver abaixo do primeiro
            /////////////////////////////////////////////
            if(lado == 1){
                dentro[i] = false;
                goto exit2;

            }
            /////////////////////////////////////////////
            //se estiver no último trecho
            /////////////////////////////////////////////
            if(math2D::lado(Segmento<long double>(Ponto<long double>(1,trechos[trechos.size()-1].y1),Ponto<long double>(2,trechos[trechos.size()-1].y1)),pontos1[i]) == -1){

                Math2D.busca_binaria1(0,trechos.size()-1,0,0,&trechos[0],dentro,sobre,i,pontos1);

                //se o ponto está sobre a reta no último y do último trecho
                if( (math2D::lado(Segmento<long double>(Ponto<long double>(1,trechos[trechos.size()-1].y1),Ponto<long double>(2,trechos[trechos.size()-1].y1)),pontos1[i]) ) == 0){

                    //o lado no trecho e acima dele são diferentes, portanto o ponto está sobre o segmento
                    if(dentro[i] == true){
                        sobre[i] = true;
                        goto exit2;
                    }
                    else{
                        if(dentro[i]==true){
                            dentro[i] = true;
                            goto exit2;
                        }
                        if(dentro[i] == false){
                            dentro[i] = false;
                            goto exit2;
                        }
                    }
                }

                if(sobre[i] == true){
                    sobre[i] = true;
                    goto exit2;
                }
                if(dentro[i] == false){
                    dentro[i] = false;
                    goto exit2;
                }
                else{
                    dentro[i] = true;
                    goto exit2;
                }
            }

            start = 0;
            end = trechos.size()- 1;
            meio = (end+start)/2;


            while( (meio-start) >= 1 ){



                if(math2D::lado(Segmento<long double>(Ponto<long double>(1,trechos[meio].y1),Ponto<long double>(2,trechos[meio].y1)),pontos1[i]) == 1){

                    end = meio;
                    meio = (start+end)/2;
                }

                else if(math2D::lado(Segmento<long double>(Ponto<long double>(1,trechos[meio].y1),Ponto<long double>(2,trechos[meio].y1)),pontos1[i]) == -1){

                    start = meio;
                    meio = (start+end)/2;
                }

                else if(math2D::lado(Segmento<long double>(Ponto<long double>(1,trechos[meio].y1),Ponto<long double>(2,trechos[meio].y1)),pontos1[i]) == 0){

                    //fazer a busca binária no trecho acima e abaixo

                    //no trecho acima
                    Math2D.busca_binaria1(0,meio-1,0,0,&trechos[0],dentro,sobre,i,pontos1);

                    if(sobre[i] == true){
                        sobre[i] = true;
                        goto exit2;
                    }

                    bool valor_da_busca_binaria = dentro[i];

                    //no trecho abaixo
                    Math2D.busca_binaria1(0,meio,0,0,&trechos[0],dentro,sobre,i,pontos1);

                    if(sobre[i] == true){
                        sobre[i] = true;
                        goto exit2;
                    }

                    if(valor_da_busca_binaria == dentro[i]){
                        //os valores em cima e em baixo do trecho são os mesmos
                        goto exit2;
                    }
                    else{
                        //os valores em cima e embaixo são diferentes
                        sobre[i] = true;
                        goto exit2;
                    }

                }


                meio = (end+start)/2;


            }

            //start = meio
            if(math2D::lado(Segmento<long double>(Ponto<long double>(1,trechos[start].y1),Ponto<long double>(2,trechos[start].y1)),pontos1[i]) == 0){

                Math2D.busca_binaria1(0,start,0,0,&trechos[0],dentro,sobre,i,pontos1);

                if(sobre[i] == true){
                    sobre[i] = true;
                    goto exit2;
                }
                //caso em que o ponto está sobre segmento
                if(dentro[i] == true){
                    sobre[i] = true;
                    goto exit2;
                }
                if(dentro[i] = false){
                    dentro[i] = false;
                    goto exit2;
                }

            }


            //trecho

            do_goto_exit2 = Math2D.busca_binaria1(a,start,end,meio,&trechos[0],dentro,sobre,i,pontos1);

            if(do_goto_exit2){
                goto exit2;
            }



            exit2:
            ;
        }

        for(int i =0; i <Q;i++){


            if(sobre[i]==false){
                if(dentro[i]){
                    cout<<"dentro"<<endl;
                }
                else{
                    cout<<"fora"<<endl;
                }
            }
            else{
                cout<<"Em cima"<<endl;
            }

        }
        /*

        exemplos de casos de teste

        teste 6

        25
        1.0 7.0
        3.0 8.0
        5.0 9.0
        5.0 8.0
        8.0 9.0
        10.0 7.0
        10.0 6.0
        11.0 5.0
        9.0 3.0
        7.0 4.0
        7.0 5.0
        8.0 4.0
        9.0 4.0
        9.0 5.0
        9.0 6.0
        6.0 6.0
        6.0 5.0
        5.0 6.0
        4.0 5.0
        5.0 4.0
        5.0 3.0
        6.0 2.0
        2.0 2.0
        2.0 4.0
        4.0 8.0
        20
        6.0 9.0
        8.0 7.0
        6.0 6.5
        5.5 5.5
        8.0 4.5
        4.0 3.0
        2.8 2.8
        3.0 2.0
        10.0 5.0
        -2.0 10.0
        0.0 0.0
        10.0 0.0
        20.0 20.0
        1.0 7.0
        5.0 7.5
        2.0 2.0
        10.5 7.0
        10.5 5.5
        3.0 3.0
        4.0 2.0





        fora
        dentro
        dentro
        em cima
        fora
        dentro
        dentro
        em cima
        dentro
        fora
        fora
        fora
        fora
        Em cima
        dentro
        Em cima
        fora
        Em cima
        dentro
        Em cima


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
