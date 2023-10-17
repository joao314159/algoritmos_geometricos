
#ifndef math2D_h
#define math2D_h

#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

#include "Math1.h"

#define PI 3.141592653589793236433932795029

using namespace std;



class math2D{

    public:


    template <typename T>
    static bool comparar_pontos_eixo_x(Ponto<T> ponto1, Ponto<T> ponto2){
        if(ponto1.x<=ponto2.x){
            return true;
        }
        else{
            return false;
        }
    }

     template <typename T>
    static bool comparar_pontos_eixo_y(Ponto<T> ponto1, Ponto<T> ponto2){
        if(ponto1.y<=ponto2.y){
            return true;
        }
        else{
            return false;
        }
    }

    template <typename T>
    static Ponto<T> maior_eixo_x(Ponto<T> ponto1,Ponto<T> ponto2){

        if(ponto1.x>=ponto2.x){
            return ponto1;
        }
        else{
            return ponto2;
        }

    }


    template <typename T>
    static Ponto<T> maior_eixo_y(Ponto<T> ponto1,Ponto<T> ponto2){

        if(ponto1.y>=ponto2.y){
            return ponto1;
        }
        else{
            return ponto2;
        }

    }


    template <typename T>
    static Ponto<T> menor_eixo_x(Ponto<T> ponto1,Ponto<T> ponto2){

        if(ponto1.x<ponto2.x){
            return ponto1;
        }
        else{
            return ponto2;
        }

    }


    template <typename T>
    static Ponto<T> menor_eixo_y(Ponto<T> ponto1,Ponto<T> ponto2){

        if(ponto1.y<ponto2.y){
            return ponto1;
        }
        else{
            return ponto2;
        }

    }



    static bool id_ponto(string a){

        if(a[1]=='P' && a[2] =='o' && a[3] == 'n' && a[4] =='t' && a[5] == 'o'){
            return true;
        }
        else{
            return false;
        }

    }



    ///////////////////////////////////////////////////////////////

    /////////MERGE SORT 2/////////////////////////////////////////



        template <typename T>
        static void merge02(T vetor[], int esquerda,int meio, int direita, int tamanho){

            T auxiliar[tamanho];

            for(int i = 0; i<tamanho ;i++){
                auxiliar[i] =vetor[i];
            }

            int i = esquerda;
            int i2 = meio +1;
            int i3 = esquerda;


            while(i <= meio && i2 <= direita){
                if(auxiliar[i].x <= auxiliar[i2].x){
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
        static void merge_sort202(T vetor[],int tamanho, int esquerda,int direita){

            if (esquerda>=direita){
                return;
            }

            int meio = (esquerda + direita)/2;

            merge_sort202(vetor,tamanho,esquerda,meio);
            merge_sort202(vetor,tamanho,meio+1,direita);

            merge02(vetor, esquerda, meio, direita, tamanho);

        }


        ///////////////////////////////////////////////////////////////

        //////////MERGE SORT 3/////////////////////////////////////////


        template <typename T>
        static void merge03(T vetor[], int esquerda,int meio, int direita, int tamanho){

            T auxiliar[tamanho];

            for(int i = 0; i<tamanho ;i++){
                auxiliar[i] =vetor[i];
            }

            int i = esquerda;
            int i2 = meio +1;
            int i3 = esquerda;


            while(i <= meio && i2 <= direita){
                if(auxiliar[i].y <= auxiliar[i2].y){
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
        static void merge_sort203(T vetor[],int tamanho, int esquerda,int direita){

            if (esquerda>=direita){
                return;
            }

            int meio = (esquerda + direita)/2;

            merge_sort203(vetor,tamanho,esquerda,meio);
            merge_sort203(vetor,tamanho,meio+1,direita);

            merge03(vetor, esquerda, meio, direita, tamanho);

        }


        ///////////////////////////////////////////////////////////////

        /////////MERGE_SORT 4//////////////////////////////////////////



        template <typename T>
        static void merge04(T vetor[], int esquerda,int meio, int direita, int tamanho){

            T auxiliar[tamanho];

            for(int i = 0; i<tamanho ;i++){
                auxiliar[i] = vetor[i];
            }

            int i = esquerda;
            int i2 = meio +1;
            int i3 = esquerda;


            while(i <= meio && i2 <= direita){
                if(auxiliar[i].y1 <= auxiliar[i2].y1){
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
        static void merge_sort204(T vetor[],int tamanho, int esquerda,int direita){

            if (esquerda>=direita){
                return;
            }

            int meio = (esquerda + direita)/2;

            merge_sort204(vetor,tamanho,esquerda,meio);
            merge_sort204(vetor,tamanho,meio+1,direita);

            merge04(vetor, esquerda, meio, direita, tamanho);

        }

        ////////////////////////////////////////////////////////////////////////////

        ////////////////MERGE SORT 5////////////////////////////////////////////////

    static void merge05(T vetor[], int esquerda,int meio, int direita, int tamanho, long double y11,long double y12){
            
            T auxiliar[tamanho];
            
            for(int i = 0; i<tamanho ;i++){
                auxiliar[i] = vetor[i];
            }
            
            int i = esquerda;
            int i2 = meio +1;
            int i3 = esquerda;
            
            
            while(i <= meio && i2 <= direita){
                
                //encontrar o cruzamento
                
                // y/x = a;
                //y1= 4;
                //x = y/a
                //y1/x1 = a;
                
                long double x1;
                long double x2;
                long double o1;
                long double o2;
                
                
                long double x12;
                long double x22;
                
                
                if((auxiliar[i].end.x - auxiliar[i].start.x) == 0){
                    //reta vertical
                    x1 = auxiliar[i].end.x;
                }
                else{
                    o1 = abs(auxiliar[i].end.x - auxiliar[i].start.x)/abs(auxiliar[i].end.y - auxiliar[i].start.y);
                    
                    if((auxiliar[i].end.y - auxiliar[i].start.y) == 0){
                        cout<<"erro"<<endl;
                    }
                    else{
                      
                        if(auxiliar[i].start.x<auxiliar[i].end.x){
                            x1 = auxiliar[i].start.x + abs(auxiliar[i].start.y - y11)*o1;
                        }
                        else if(auxiliar[i].start.x>auxiliar[i].end.x){
                            x1 = auxiliar[i].end.x + abs(auxiliar[i].end.y - y11)*o1;
                        }
                    }
                }
                
                if((auxiliar[i2].end.x - auxiliar[i2].start.x) == 0){
                    //reta vertical
                    x2 = auxiliar[i2].end.x;
                }
                
                else{
                   
                    o2 = abs(auxiliar[i2].end.x - auxiliar[i2].start.x)/abs(auxiliar[i2].end.y - auxiliar[i2].start.y);

                    if((auxiliar[i2].end.y - auxiliar[i2].start.y)==0){
                        cout<<"erro"<<endl;
                    }
                    else{
                       
                        if(auxiliar[i2].start.x<auxiliar[i2].end.x){
                            x2 = auxiliar[i2].start.x + abs(auxiliar[i2].start.y - y11)*o2;
                        }
                        else if(auxiliar[i2].start.x>auxiliar[i2].end.x){
                            x2 = auxiliar[i2].end.x + abs(auxiliar[i2].end.y - y11)*o2;
                        }
                    }
                }
                
                
                ///////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////
                
                if((auxiliar[i].end.x - auxiliar[i].start.x) == 0){
                    //reta vertical
                    x12 = auxiliar[i].end.x;
                }
                else{
                    if(auxiliar[i].start.x<auxiliar[i].end.x){
                        x12 = auxiliar[i].start.x + abs(auxiliar[i].start.y - y12)*o1;
                    }
                    else if(auxiliar[i].start.x>auxiliar[i].end.x){
                        x12 = auxiliar[i].end.x + abs(auxiliar[i].end.y - y12)*o1;
                    }
                }
                
                if((auxiliar[i2].end.x - auxiliar[i2].start.x) == 0){
                    //reta vertical
                    x22 = auxiliar[i2].end.x;
                }
                else{
                    if(auxiliar[i2].start.x<auxiliar[i2].end.x){
                        x22 = auxiliar[i2].start.x + abs(auxiliar[i2].start.y - y12)*o2;
                    }
                    else if(auxiliar[i2].start.x>auxiliar[i2].end.x){
                        x22 = auxiliar[i2].end.x + abs(auxiliar[i2].end.y - y12)*o2;
                    }
                }    
                    
                
                
                
                ///////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////
                ///////////////////////////////////////////////////////////////////////////
               
                
                if( (Math1::menor(x1,x12) == Math1::menor(x2,x22)) &&( Math1::maior(x1,x12) <= Math1::maior(x2,x22)) ){
                    
                    vetor[i3] = auxiliar[i];
                    i++;
                }
                else if(Math1::menor(x1,x12) < Math1::menor(x2,x22) ){
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
        static void merge_sort205(T vetor[],int tamanho, int esquerda,int direita, long double y,long double y2){

            if (esquerda>=direita){
                return;
            }

            int meio = (esquerda + direita)/2;

            merge_sort205(vetor,tamanho,esquerda,meio,y,y2);
            merge_sort205(vetor,tamanho,meio+1,direita,y,y2);

            merge05(vetor, esquerda, meio, direita, tamanho,y,y2);

        }


    /////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////


    template <typename T>
    static void ordena_pontos_pelo_eixo_x(Ponto<T>* pontos, int tamanho){
        merge_sort202(pontos,tamanho,0,tamanho-1);
    }

    template <typename T>
    static void ordena_pontos_pelo_eixo_y(Ponto<T>* pontos, int tamanho){
        merge_sort203(pontos,tamanho,0,tamanho-1);
    }

    template <typename T>
    static void ordena_vetor_de_segmentos(Vetor_de_segmentos<T>* vetor_de_segmentos, int tamanho){
        merge_sort204(vetor_de_segmentos,tamanho,0,tamanho-1);
    }

    template <typename T>
    static void ordena_segmentos(Segmento<T>* segmentos, int tamanho,long double y,long double y2){
        merge_sort205(segmentos,tamanho,0,tamanho-1,y,y2);
    }

    template <typename T>
    static void criar_pontos(int quantidade, Ponto<T>* &pontos){
        unsigned seed = time(0);
        srand(seed);

        Ponto<T>* ponto1 = new Ponto<T>[quantidade];

        for(int i =0;i<quantidade;i++){
            ponto1[i].x = rand()%1000;
            ponto1[i].y = rand()%1000;
        }

        pontos = ponto1;


    }

    template <typename T>
    static Ponto<T> somar_pontos(Ponto<T> ponto1,Ponto<T> ponto2){

        Ponto<T> ponto3;
        ponto3.x = ponto1.x + ponto2.x;
        ponto3.y = ponto1.y + ponto2.y;

        return ponto3;

    }

    template <typename T,typename tipo2>
    static Ponto<T> multiplicar_pontos(Ponto<T> ponto1, tipo2 a){

       Ponto<T> ponto3;

       ponto3.x =  ponto1.x*a;
       ponto3.y =  ponto1.y*a;

       return ponto3;

    }

    template <typename T>
    static Ponto<T> ponto_do_meio_do_segmento(Segmento<T> segmento1){

        double a = 0.5;

        Ponto<T> ponto3;

        ponto3 = somar_pontos(multiplicar_pontos(segmento1.start,a),multiplicar_pontos(segmento1.end,(1.0-a)));

        return ponto3;

    }

    template <typename T>
	static T produto_escalar(Vetor<T> vetor1,Vetor<T> vetor2){

   		 T resultado = vetor1.x * vetor2.x + vetor1.y * vetor2.y;

    return resultado;
    }



    //1 = direita -1 = esquerda 0 = em cima
    template <typename T>
    //MANTER RETORNO COMO INT
    static int lado(Segmento<T> segmento1,Ponto<T> alvo){

   		Vetor<T> vetor1(segmento1);
   		Vetor<T> vetor2(Segmento<T>(segmento1.start,alvo));
   		T resultado = produto_escalar(vetor1.normal(),vetor2);
        int a;

        if(resultado<0){a= -1;}
        else if(resultado>0){a = 1;}
        else{a = 0;}

        return a;
    }


    template <typename T>
    static bool mesmo_ponto(Ponto<T> ponto1, Ponto<T> ponto2){

        if(&ponto1.x == NULL || &ponto1.y || NULL || &ponto2.x == NULL || &ponto2.y ==NULL){

           // cout<<endl<<endl<<"Erro, membros dos pontos são nulos!!!"<<endl<<endl;

        }


        string a = typeid(ponto1.x).name();

        if(a == "e" || a == "d"){

            if( (abs(ponto1.x- ponto2.x)<1e-9 ) &&(abs(ponto1.y- ponto2.y)<1e-9 )) {
                return true;
            }
            else {
                return false;
            }

        }
        else if(a == "i"){

            if( (ponto1.x == ponto2.x) &&(ponto1.y == ponto2.y)) {
                return true;
            }
            else {
                return false;
            }
        }
        else{
            cout<<"tipo inadequado"<<endl;
            return false;
        }
    }

    template <typename T>
    static bool mesmo_segmento(Segmento<T> segmento1, Segmento<T> segmento2){

        if((mesmo_ponto(segmento1.start,segmento2.start) && mesmo_ponto(segmento1.end,segmento2.end)) || (mesmo_ponto(segmento1.start,segmento2.end)&&mesmo_ponto(segmento1.end,segmento2.start))){
            return true;
        }

    }

    template <typename T>
    static bool mesmo_vetor(Vetor<T> vetor1,Vetor<T> vetor2){


        string a = typeid(vetor1.x).name();

        if(a == "e" || a == "d"){

            if( (abs(vetor1.x-vetor2.x)<1e-9 )&&( abs(vetor1.y-vetor2.y)<1e-9 )){
                return true;
            }
            else{
                return false;
            }

        }
        else if(a == "i"){

            if( (vetor1.x == vetor2.x)&&(vetor1.y == vetor2.y)){
                return true;
            }
            else{
                return false;
            }

        }
        else{
            cout<<"tipo inadequado"<<endl;
            return false;
        }

    }


    template <typename T>
    //se um ponto de um segmento estiver sobre a reta correspondente ao outro retorna 0(se os segmentos forem colineares retorna 0)
    //USAR FUNÇÃO CRUZA2!!!
    static int cruza(Segmento<T> segmento1, Segmento<T> segmento2){

        //caso 0 (útil para comparar retas, mas pode confundir, CUIDADO)
        //ver se um ponto está sobre a reta correspondente ao outro ponto
        if(lado(segmento1,segmento2.start) == 0 || (lado(segmento1,segmento2.end) == 0) || lado(segmento2,segmento1.start) ==0 ||  lado(segmento2,segmento1.end) ==0){
            return 0;
        }

        //caso 1
        //ver se os dois pontos de um segmento estão, cada um, em um lado diferente do outro segmento( caso em que os segmentos cruzam)
        if( (lado(segmento1,segmento2.start) != lado(segmento1,segmento2.end)) && (lado(segmento2,segmento1.start) != lado(segmento2,segmento1.end)) )  {

            return 1;
        }

        //caso -1
        //caso não ocorra nenhuma das situações anteriores, os segmentos não se encontram de qualquer forma
        else{return -1;}
    }


    template <typename T>
    static bool paralelos(Segmento<T> segmento1, Segmento<T> segmento2){

        T delta_x1 = segmento1.end.x - segmento1.start.x;
        T delta_y1 = segmento1.end.y - segmento1.start.y;

        T delta_x2 = segmento2.end.x - segmento2.start.x;
        T delta_y2 = segmento2.end.y - segmento2.start.y;





        string a = typeid(delta_x1).name();

        if(a == "e" || a == "d"){

            //caso de alguma reta ser vertical
            if(abs(delta_x1) < 1e-9 || abs(delta_x2) < 1e-9){

                if( (abs(delta_x1) < 1e-9) && (abs(delta_x2) <1e-9) ){
                    return true;
                }
                else{
                    return false;
                }

            }
            else{

                if( ((long double)delta_y1/delta_x1) == ((long double)delta_y2/delta_x2) ){
                    return true;
                }
                else{
                    return false;
                }

            }

        }
        else if(a == "i"){

           //caso de alguma reta ser vertical
            if(delta_x1 == 0 || delta_x2 == 0){

                if(delta_x1 == 0 && delta_x2 == 0){
                    return true;
                }
                else{
                    return false;
                }

            }
            else{

                if( ((long double)delta_y1/delta_x1) == ((long double)delta_y2/delta_x2) ){
                    return true;
                }
                else{
                    return false;
                }

            }

        }
        else{
            cout<<"tipo inadequado"<<endl;
            return false;
        }
    }


    template <typename T>
    //CONFERIR SE FUNCIONA PARA O CASO DO FINAL ESTAR NA FRENTE DO COMEÇO
    static bool ponto_sobre_segmento(Segmento<T> segmento1,Ponto<T> ponto1){

        if(mesmo_ponto(segmento1.start,ponto1)){

            return true;
        }
        else{
            if(paralelos(segmento1,Segmento<T>(segmento1.start,ponto1))){

                if( (ponto1.x >= Math1::menor(segmento1.start.x,segmento1.end.x) && ponto1.x <= Math1::maior(segmento1.start.x,segmento1.end.x) ) && (ponto1.y >= Math1::menor(segmento1.start.y,segmento1.end.y) && ponto1.y <= Math1::maior(segmento1.start.y,segmento1.end.y) ) ){
                    return true;
                }
                else{
                    return false;
                }


            }
            else{
                return false;
            }

        }



    }



    template <typename T>
    //não funciona
    //inclui o caso que apenas um ponto pertence aos dois segmentos
    //essa função trata de segmentos, não aborda retas. Um segmento (1,1) e (2,2) não é sobreposto a um segmento (5,5) e (10,10);
    static bool paralelos_e_sobrepostos(Segmento<T> segmento1, Segmento<T> segmento2){

        if(paralelos(segmento1,segmento2)){

            if(ponto_sobre_segmento(segmento1,segmento2.start) || ponto_sobre_segmento(segmento1,segmento2.end)){
                return true;
            }
            else{
                return false;
            }

        }
        else{
            return false;
        }

    }

    template <typename T>
    static bool extremidade_equivalente(Segmento<T> segmento1, Segmento<T> segmento2){

        if(mesmo_ponto(segmento1.start,segmento2.start) || mesmo_ponto(segmento1.end,segmento2.start) || mesmo_ponto(segmento1.start,segmento2.end) || mesmo_ponto(segmento1.end,segmento2.end)){
            return true;
        }
        else{
            return false;
        }

    }



    template <typename T>
    //se os segmentos cruzarem retorna 1, retorna 0 nos casos particulares e retorna -1 se não se cruzam
    static int cruza2(Segmento<T> segmento1, Segmento<T> segmento2){

        //caso 0
        if(lado(segmento1,segmento2.start) == 0 || (lado(segmento1,segmento2.end) == 0) ||lado(segmento2,segmento1.start) ==0 || lado(segmento2,segmento1.end) ==0){

            if(ponto_sobre_segmento(segmento1,segmento2.start) || ponto_sobre_segmento(segmento1,segmento2.end) || ponto_sobre_segmento(segmento2,segmento1.start) || ponto_sobre_segmento(segmento2,segmento1.end) ){
                return 0;
            }
            else{
                if(paralelos_e_sobrepostos(segmento1,segmento2)){
                    return 0;
                }
                else if(paralelos(segmento1,segmento2)){
                    return -1;
                }
            }

        }

        //caso 1
        //ver se os dois pontos de um segmento estão, cada um, em um lado diferente do outro segmento( caso em que os segmentos cruzam)
        if( (lado(segmento1,segmento2.start) != lado(segmento1,segmento2.end)) && (lado(segmento2,segmento1.start) != lado(segmento2,segmento1.end)) )  {

            return 1;
        }

        //caso -1
        //caso não ocorra nenhuma das situações anteriores, os segmentos não se encontram de qualquer forma
        else{return -1;}
    }

    template <typename T>
    static Ponto<T> ponto_de_cruzamento(Segmento<T> segmento1,Segmento<T> segmento2){
        Ponto<T> ponto1;


    }



    template <typename T>
    //não inclui ponto sobre segmento
    //não vai funcionar se não passar um polígono convexo

    // -1 ponto fora do polígono 1 ponto dentro do polígono, 0 ponto sobre segmento do polígono
    int ponto_em_poligono_convexo(Ponto<T> ponto, Ponto<T>* poligono, int tamanho_poligono);


    template <typename T>

    Ponto<T> criar_ponto(Ponto<T>* pontos){

        T x = ((long double)(pontos[0].x+pontos[1].x+pontos[2].x))/3.0;
        T y = ((long double)(pontos[0].y + pontos[1].y) + pontos[2].y)/3.0;

        Ponto<T> ponto1(x,y);

        return ponto1;

    }

    template <typename T>
    Ponto<T> criar_ponto2(Ponto<T>* pontos, int tamanho){

        T x = ((long double)(pontos[0].x + pontos[(int)(tamanho/3)].x +pontos[(int)(tamanho/2)+1].x))/3.0;
        T y = ((long double)(pontos[0].y + pontos[(int)(tamanho/3)].y + pontos[(int)(tamanho/2)+1].y))/3.0;

        Ponto<T> ponto1(x,y);

        return ponto1;

    }

    template <typename T>
    static int tira_pontos_colineares(Ponto<T>* &forma, int tamanho){

        //sem os pontos colineares
        int tamanho2 = tamanho;


        bool* tira = new bool[tamanho];

        for(int i = 0;i < tamanho-2; i++){
            if(paralelos( Segmento<T>(Ponto<T>(forma[i].x,forma[i].y),Ponto<T>(forma[i+1].x,forma[i+1].y)), Segmento<T>(Ponto<T>(forma[i+1].x,forma[i+1].y),Ponto<T>(forma[i+2].x,forma[i+2].y)))){
                tira[i+1] = true;
                tamanho2--;
            }
            else{
                tira[i+1] = false;
            }
        }
        if(paralelos( Segmento<T>(Ponto<T>(forma[tamanho-2].x,forma[tamanho-2].y),Ponto<T>(forma[tamanho-1].x,forma[tamanho-1].y)), Segmento<T>(Ponto<T>(forma[tamanho-1].x,forma[tamanho-1].y),Ponto<T>(forma[0].x,forma[0].y)))){
            tira[tamanho-1] = true;
            tamanho2--;
        }

        Ponto<T>* forma2 = new Ponto<T>[tamanho2];

        int i2 =0;

        for(int i =0;i<tamanho;i++){

            if(tira[i] ==false){
                forma2[i2] = forma[i];
                i2++;
            }

        }

        forma = new Ponto<long double>[tamanho2];
        forma = forma2;
        return tamanho2;

    }





    static void ponto_em_poligono2();



    //função para ponto_em_poligono3()

    //true = goto exit2 false = não goto exit2
    bool busca_binaria1(int a,int start,int end,int meio,Vetor_de_segmentos<long double>* trechos, bool* dentro, bool* sobre, int i,Ponto<long double>* pontos1);

    //funciona para polígonos não convexos
    static void ponto_em_poligono3();

};

#endif // math2D

