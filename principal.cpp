#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <iomanip>
#include <set>
#include <algorithm>
#include <queue>

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

    Ponto(const Ponto<T> &ponto2){
        this->x = ponto2.x;
        this->y = ponto2.y;
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

    template <typename tipo8>
    bool operator==(Ponto<tipo8> ponto1){
        if(this->x == ponto1.x && this->y == ponto1.y){
            return true;
        }
        else{
            return false;
        }

    }


    void print(){
        cout<<"("<<this->x<<","<<this->y<<")";
    }
    void print2(){
        cout<<"Coordenadas do ponto: ("<<this->x<<", "<<this->y<<")"<<endl;
    }

};


template <typename T>
class Segmento{

    public:
    Segmento(){}
    Segmento(Ponto<T> ponto1,Ponto<T> ponto2){

        this->start=ponto1;
        this->end=ponto2;

    }

    Segmento(const Segmento<T> &segmento2){
        this->start.x = segmento2.start.x;
        this->start.y = segmento2.start.y;
        this->end.x = segmento2.end.x;
        this->end.y = segmento2.end.y;
    }

    Ponto<T> start;
    Ponto<T> end;

    void print(){
        cout<<"Seg("<<this->start.x<<","<<this->start.y<<")->("<<this->end.x<<","<<this->end.y<<")";
    }

    void print2(){
        cout<<"Esse segmento começa em ("<<this->start.x<<", "<<this->start.y<<") e termina em ("<<this->end.x<<", "<<this->end.y<<") "<<endl;
    }

    void inverter(){
        Ponto<T> ponto;
        ponto = this->start;
        this->start = this->end;
        this->end = ponto;
    }

    /*
    bool estranho(){

        Ponto<T> ponto1=this->start;
        Ponto<T> ponto2=this->end;

        string tipo = typeid(ponto1.x).name();
            //cópia da função mesmo_ponto()
            if(&this->start.x == NULL || &this->start.y || NULL || &this->end.x == NULL || &this->end.y ==NULL){

                //cout<<endl<<endl<<"Erro, membros dos pontos são nulos!!!"<<endl<<endl;

            }

            if(tipo == "e" || tipo == "d" ){

                cout<<"não é inteiro"<<endl;
                if( (abs(ponto1.x-ponto2.x) <1e-9 )  &&( abs(ponto1.y- ponto2.y)<1e-9 ) ) {
                    return true;
                }
                else {
                    return false;
                }
            }
            else if(tipo == "i"){

                cout<<"é inteiro"<<endl;
                if( (ponto1.x == ponto2.x) &&(ponto1.y == ponto2.y)) {
                    return true;
                }
                else {
                    return false;
                }

            }
            else{
                cout<<"tipo inapropriado"<<endl;

                cout<<typeid(ponto1.x).name()<<endl;

                return true;
            }

    }

    */



    //para usar o segmento no set
    template<typename tipo2>
    bool operator<(const Segmento<tipo2> segmento2) const{
        return(this->start.x < segmento2.start.x);
    }

};

template <typename T>
class Vetor{

    public:

    Vetor(){}
    Vetor(Segmento<T> segmento){

        this->x = segmento.end.x-segmento.start.x;
        this->y = segmento.end.y-segmento.start.y;

    }

    Vetor(Ponto<T> ponto){

        this->x = ponto.x;
        this->y = ponto.y;
    }

    T x;
    T y;

    long double comprimento(){
        return (  sqrt(  (abs((long double)this->x) ) *  ( abs((long double)this->x) )  + (  abs((long double)this->y) )* ( abs((long double)this->y))  ) );
    }

    Vetor normal(){

        Vetor resultado;

        resultado.x = this->y;
        resultado.y = -(this->x);

        return resultado;
    }


    Vetor<T> versor(){
        long double comprimento = this->comprimento;
        Vetor<T> versor;
        versor.x = (this->x)/comprimento;
        versor.y = (this->y)/comprimento;

        return versor;
    }

    template<typename tipo2>
    Vetor<T> operator*(const tipo2 x){

        Vetor<T> auxiliar;
        auxiliar.x = this->x* x;
        auxiliar.y = this->y* x;

        return auxiliar;

    }

    void print(){
        cout<<"Esse vetor tem módulo "<<this->comprimento()<<" e aponta para ("<<this->x<<", "<<this->y<<")"<<endl;
    }
};

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


//CLASSES ESPECÍFICAS PARA FUNÇÕES


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


//útil para a função de cruzamento de segmentos. Ele tem a informação de se é um evento de início ou de fim, e qual segmento ele faz parte

template <typename T>
class Ponto2{

    public:

    Ponto2(){}

    Ponto2(Segmento<T> segmento1,bool is_start){
        this->ponto_de_cruzamento = false;
        this->segmento = segmento1;
        this->is_start = is_start;
        this->ponto_de_cruzamento = false;
        if(is_start){
            this->x = segmento1.start.x;
        }
        else{
            this->x = segmento1.end.x;
        }
    }

    //construtor que passa a informação de que o ponto é de cruzamento
    Ponto2(Segmento<T> segmento1,bool segmento_de_cima,bool ponto_de_cruzamento,Ponto<T> ponto_cruzamento){
        this->ponto_de_cruzamento = ponto_de_cruzamento;
        this->segmento = segmento1;
        this->is_start = segmento_de_cima;
        this->ponto_cruzamento = ponto_cruzamento;
        if(segmento_de_cima){
            this->x = ponto_cruzamento.x + 0.0000001;
        }
        else{
            this->x = ponto_cruzamento.x;
        }
    }
    Ponto2(Ponto<T> ponto){
        this->ponto_de_cruzamento = true;
        Segmento<T> segmento1(ponto,ponto);
        this->segmento = segmento1;
        this->is_start = is_start;

        this->x = segmento1.start.x;

    }


    T x;
    Segmento<T> segmento;
    bool is_start;




    template <typename tipo2>
    bool operator<(const Ponto2<tipo2> ponto2) const{


            bool a = this->x < ponto2.x;


        return a;
    }


    template <typename tipo3>
    bool operator>(const Ponto2<tipo3> ponto2) const{
        bool a = this->x > ponto2.x;
        return a;
    }

    template <typename tipo4>
    bool mesmo_ponto(Ponto2<tipo4> ponto22){

        Ponto<tipo4> ponto1;
        Ponto<tipo4> ponto2;

        if(this->is_start){
            ponto1 = this->segmento.start;
        }
        else if(not this->is_start){
            ponto1 = this->segmento.end;
        }

        if(ponto22.is_start){
            ponto2 = ponto22.segmento.start;
        }
        else if(not ponto22.is_start){
            ponto2 = ponto22.segmento.end;
        }

        if((ponto1.x == ponto2.x) && (ponto1.y == ponto2.y)){

            //cout<<"pontos iguais.";
            //ponto1.print();
            //ponto2.print();

            return true;
        }
        else {

            //cout<<"pontos diferentes.";
            //ponto1.print();
            //ponto2.print();

            return false;
        }
        //cout<<"teste"<<endl;

    }


    void print2(){

        if(is_start){
            cout<<"Esse é o ponto do início do segmento"<<endl;
            segmento.start.print();
        }
        else{
            cout<<"Esse é o ponto do final do segmento"<<endl;
            segmento.end.print();
        }

        cout<<"Esse ponto faz parte do segmento:"<<endl;
        this->segmento.print();

    }

    void print(){
        if(is_start){
            cout << "Inicio:";
            segmento.start.print();
        }
        else{
            cout<<"Fim";
            segmento.end.print();
        }

        cout<<"->:";
        this->segmento.print();

        cout<<endl;

    }


    //para tratar cruzamentos
    bool ponto_de_cruzamento;

    Ponto<T> ponto_cruzamento;

    private:
    Segmento<T> segmento_que_cruzou;

    public:
    Segmento<T> get_segmento_que_cruzou(){

        try{
            if(! ponto_de_cruzamento){
                throw(0);
            }
        }
        catch(int a){
            cout<<"Esse ponto não é de cruzamento"<<endl;
        }

        return segmento_que_cruzou;

    }

    void set_segmento_que_cruzou(Segmento<int> segmento){
        this->segmento_que_cruzou = segmento;
    }


};




template <typename T>
long double y_em_um_determinado_x(Segmento<T> segmento1, long double x){

    //x = x1 + (x2-x1)*((y-y1)/(y2-y1))

    //(x-x1)/(x2-x1)=((y-y1)/(y2-y1))

    //((x-x1)*(y2-y1))/(x2-x1) = y-y1

    // (((x-x1)*(y2-y1))/(x2-x1)) - y1 = y

    long double y = ( ((x - segmento1.start.x) * (segmento1.end.y - segmento1.start.y))/(segmento1.end.x - segmento1.start.x)   )  + segmento1.start.y;

    return y;
}

//Classe usada para comparar dois segmentos e informar qual está acima e qual está abaixo no x atual

//Ela vai funcionar da seguinte forma:

//haverá uma variável bool para determinar se o segmento já passou por um cruzamento, nesse caso a comparação vai ficar invertida

//haverá um apontador para o X atual e comparamos segmentos a e b tendo em conta o x atual, que podemos alterar

//passamos essa classe no construtor do set
template <typename T>
class Comparator{

public:

    bool acabou_de_cruzar;

    bool operator()(const Ponto2<T> &a, const Ponto2<T> &b){
        //comparamos os segmentos a e b baseado no x atual apontado por x_atual.

        //a é o ponto adicionado no set, por isso o x atual é o x do ponto a

        //se os segmentos ainda não se cruzaram
        long double y_atual1 = y_em_um_determinado_x(a.segmento,a.x);
        long double y_atual2 = y_em_um_determinado_x(b.segmento,a.x);

        return (y_atual1 <y_atual2);

        /*if(!(acabou_de_cruzar)){
            //comparo o y dos segmentos para o x atual
            return (y_atual1 < y_atual2);
        }
        else{
            //caso em que os segmentos já cruzou
            return (y_atual1 >= y_atual2);
        }
        */
    }
};

template <typename T>
class Cruzamentos_salvos{

public:

    Cruzamentos_salvos(Segmento<T> segmento1, Segmento<T> segmento2){

        this->segmento1 = segmento1;
        this->segmento2 = segmento2;

    }

    Segmento<T> segmento1;
    Segmento<T> segmento2;

    long double Ponto_de_cruzamento;

    void print(){
        cout<<segmento1.start.x<<" "<<segmento1.start.y<<" "<<segmento1.end.x<<" "<<segmento1.end.y;
        cout<<" "<<segmento2.start.x<<" "<<segmento2.start.y<<" "<<segmento2.end.x<<" "<<segmento2.end.y<<endl;
    }


};

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

    template <typename T>
    static long double distancia_entre_pontos(Ponto<T> ponto1, Ponto<T> ponto2){

        if(ponto1.y == ponto2.y){
            return (long double)maior_eixo_x(ponto1,ponto2).x - (long double)menor_eixo_x(ponto1,ponto2).x;
        }
        if(ponto1.x == ponto2.x){
            return (long double)maior_eixo_y(ponto1,ponto2).y -(long double)menor_eixo_y(ponto1,ponto2).y;
        }
        else{

            long double delta_x = maior_eixo_x(ponto1,ponto2).x - menor_eixo_x(ponto1,ponto2).x;
            long double delta_y = maior_eixo_y(ponto1,ponto2).y - menor_eixo_y(ponto1,ponto2).y;
            return sqrt( delta_x*delta_x + delta_y*delta_y);

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


        template <typename T>
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
                        cout<<"erro na linha "<<__LINE__<<endl;
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
                        cout<<"erro na linha "<<__LINE__<<endl;
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
    static Ponto<long double> ponto_de_cruzamento_function(Segmento<T> segmento1,Segmento<T> segmento2){
        Ponto<long double> ponto;

        long double d;
        long double h;

        Segmento<long double> segmento_auxiliar1(segmento1.start,segmento2.start);

        Vetor<long double> vetor1(segmento1);
        Vetor<long double> vetor2(segmento2);

        Segmento<long double> segmento22 = segmento2;
        segmento22.inverter();
        Vetor<long double> vetor22(segmento22);

        Vetor<long double> vetor_auxiliar(segmento_auxiliar1);

        d = produto_escalar(vetor1.normal(),vetor_auxiliar);

        h = produto_escalar(vetor1.normal(),vetor22);

        //somar ponto com d/h vezes vector2

        if(h == 0){
            cout<<"divisão por zero!"<<endl;
        }
        else{
            vetor2 = vetor2*(d/h);

            vetor2.x = vetor2.x +segmento2.start.x;
            vetor2.y = vetor2.y +segmento2.start.y;
        }

        Ponto<long double> a(vetor2.x,vetor2.y);

        return a;

    }



    template <typename T>
    //não inclui ponto sobre segmento
    //não vai funcionar se não passar um polígono convexo

    // -1 ponto fora do polígono 1 ponto dentro do polígono, 0 ponto sobre segmento do polígono
    int ponto_em_poligono_convexo(Ponto<T> ponto, Ponto<T>* poligono, int tamanho_poligono){

        int lado1;

        int a = 2;

        if(tamanho_poligono <=2){

            //cout<<"Erro, polígono tem dois ou menos pontos"<<endl;
        }

        if( ponto_sobre_segmento( Segmento<T>(poligono[0],poligono[1]), ponto ) ){

                //cout<<"Ponto sobre segmento"<<endl;
                //cout<<"Segmento começa em "<<poligono[0].x<<", "<<poligono[0].y<<" e termina em "<<poligono[1].x<<", "<<poligono[1].y<<endl<<endl;
                //cout<<"O ponto é "<<ponto.x<<", "<<ponto.y<<endl<<endl;
                a = 0;
        }

        //que lado o ponto está em relação a primeira reta do polígono
        lado1 = lado(Segmento<T>(poligono[0],poligono[1]), ponto);
        //cout<<"lado aresta 1: "<<lado1<<endl;


        for(int i = 1; i<tamanho_poligono-1; i++){

            if( ponto_sobre_segmento( Segmento<T>(poligono[i],poligono[i+1]), ponto ) ){
                //cout<<"Ponto sobre segmento"<<endl;
                //cout<<"Segmento começa em "<<poligono[i].x<<", "<<poligono[i].y<<" e termina em "<<poligono[i+1].x<<", "<<poligono[i+1].y<<endl<<endl;
                //cout<<"O ponto é "<<ponto.x<<", "<<ponto.y<<endl<<endl;

                a = 0;
            }

            if ( (lado(Segmento<T>(poligono[i],poligono[i+1]), ponto) != lado1 ) && (a != 0) ){

               // cout<<"lado, aresta "<< i+1 <<" : "<< lado(Segmento<T>(poligono[i],poligono[i+1]), ponto) <<endl;
               // cout<<"lado, aresta "<< i+1 <<" : "<< lado1 <<endl;
                a = -1;
            }
        }

        //quando termina o loop, ainda temos que comparar o ponto com a aresta que liga o ponto do final do array
        //com o ponto do início do array

        if( ponto_sobre_segmento( Segmento<T>(poligono[tamanho_poligono-1],poligono[0]), ponto ) ){
           // cout<<"Ponto sobre segmento"<<endl;
            //cout<<"Segmento começa em "<<poligono[tamanho_poligono-1].x<<", "<<poligono[tamanho_poligono-1].y<<" e termina em "<<poligono[0].x<<", "<<poligono[0].y<<endl<<endl;

            //cout<<"O ponto é "<<ponto.x<<", "<<ponto.y<<endl<<endl;
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





    static void ponto_em_poligono2(){

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



    //função para ponto_em_poligono3()

    //true = goto exit2 false = não goto exit2
    bool busca_binaria1(int a,int start,int end,int meio,Vetor_de_segmentos<long double>* trechos, bool* dentro, bool* sobre, int i,Ponto<long double>* pontos1){

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

            dentro[i] =true;
        }
        else{

            dentro[i]=false;
        }
        return false;

    }


    //funciona para polígonos não convexos
    static void ponto_em_poligono3(){

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
        //bool* sobre2 = new bool[Q];

        for(int i =0; i<Q;i++){
            sobre[i] = false;
            //sobre2[i] = false;
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
                    cout<<"DENTRO"<<endl;
                }
                else{
                    cout<<"FORA"<<endl;
                }
            }
            else{
                cout<<"EMCIMA"<<endl;
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

    //////////////////////////////////////////////////////////////////////
    //algoritmo menor distância entre pontos /////////////////////////////
    //////////////////////////////////////////////////////////////////////

    //início e fim delimitam esse trecho da busca recursiva. início e fim são índices. portanto início é 0 e fim é tamanho do vetor-1
    long double menor_distancia(Ponto<long double>* pontos_ordenados_por_x, Ponto<long double>* pontos_ordenados_por_y,int inicio, int fim){

        cout<<"teste"<<endl;
        //se trecho tem mais do que 3 elementos
        if(fim - 2 > inicio){

            cout<<"teste2"<<endl;
            cout<<"fim: "<< fim<<endl;
            cout<<"início: "<<inicio<<endl;


            Ponto<long double>* pontos_ordenados_por_y_esquerda = new Ponto<long double>[fim + 1];
            Ponto<long double>* pontos_ordenados_por_y_direita= new Ponto<long double>[fim + 1];

            //extrair pontos do vetor ordenado por x que estão no trecho da esquerda, e os que estão no trecho da direita

            int i_esquerda = 0;
            int i_direita = 0;

            int tamanho_esquerda = 0;
            int tamanho_direita = 0;

            int i4 = 0;

            for(int i = inicio; i < (fim + 1); i++){
                //eu comparo cada ponto do vetor ordenado por y com o ponto de corte(o ponto do meio do vetor ordenado por x)

                //por padrão o ponto do x do meio fica do lado esquerdo
                if((pontos_ordenados_por_x[(fim+inicio)/2].y == pontos_ordenados_por_y[i4].y) && (pontos_ordenados_por_x[(fim+inicio)/2].x == pontos_ordenados_por_y[i4].x)){
                    pontos_ordenados_por_y_esquerda[i_esquerda] = pontos_ordenados_por_y[i4];
                    if(i_esquerda > fim){
                        cout<<"Erro!!!"<<endl;
                        exit(1);
                    }
                    i_esquerda++;
                    tamanho_esquerda++;
                }

                //em um vetor ficam os pontos à esquerda do ponto de corte, ordenados por y
                else if(pontos_ordenados_por_x[(fim+inicio)/2].x > pontos_ordenados_por_y[i4].x){
                    pontos_ordenados_por_y_esquerda[i_esquerda] = pontos_ordenados_por_y[i4];
                    if(i_esquerda > fim){
                        cout<<"Erro!!!"<<endl;
                        exit(1);
                    }
                    i_esquerda++;
                    tamanho_esquerda++;
                }
                //em outro vetor ficam os pontos à direita do ponto de corte, ordenador por y
                else if(pontos_ordenados_por_x[(fim+inicio)/2].x < pontos_ordenados_por_y[i4].x){
                    pontos_ordenados_por_y_direita[i_direita] = pontos_ordenados_por_y[i4];
                    if(i_direita > fim){
                        cout<<"Erro!!!"<<endl;
                        exit(1);
                    }
                    i_direita++;
                    tamanho_direita++;
                }
                else{
                    //quando os pontos estão no mesmo eixo x distribuímos balanceadamente dos dois lados
                    if(tamanho_esquerda<tamanho_direita){
                         pontos_ordenados_por_y_esquerda[i_esquerda] = pontos_ordenados_por_y[i4];
                        i_esquerda++;
                        tamanho_esquerda++;
                        cout<<"teste6"<<endl;
                    }
                    else{

                        pontos_ordenados_por_y_direita[i_direita] = pontos_ordenados_por_y[i4];
                        i_direita++;
                        tamanho_direita++;
                        cout<<"teste5"<<endl;
                    }
                }
                i4++;
            }

            for(int i = 0; i <tamanho_esquerda; i++){
                cout<<"tamanho da esquerda: "<<tamanho_esquerda<<endl;
                cout<<"pontos da esquerda: "<<endl;
                pontos_ordenados_por_y_esquerda[i].print();
                cout<<endl;
            }
            for(int i = 0; i <tamanho_direita; i++){
                cout<<"tamanho da direita: "<<tamanho_direita<<endl;
                cout<<"pontos da direita: "<<endl;
                pontos_ordenados_por_y_direita[i].print();
                cout<<endl;
            }

            long double a1;
            long double a2;

            if(tamanho_esquerda >0){
                a1 = menor_distancia(pontos_ordenados_por_x,pontos_ordenados_por_y_esquerda , inicio,inicio + tamanho_esquerda-1);
                cout<<a1<<endl;
            }

            else{
                //não há elementos do lado esquerdo
                a1 = menor_distancia(pontos_ordenados_por_x, pontos_ordenados_por_y_direita ,inicio + tamanho_esquerda,inicio + tamanho_esquerda  +tamanho_direita - 1);
            }

            if(tamanho_direita > 0){
                cout<<"teste7"<<endl;
                a2 = menor_distancia(pontos_ordenados_por_x, pontos_ordenados_por_y_direita ,inicio + tamanho_esquerda,inicio + tamanho_esquerda +tamanho_direita - 1  );
            }
            else{
                //não há elementos do lado direito
                a2 = menor_distancia(pontos_ordenados_por_x,pontos_ordenados_por_y_esquerda , inicio,inicio + tamanho_esquerda-1);
            }

            long double a3 = Math1::menor(a1, a2);
            cout<<"menor: "<<a3<<endl<<endl;
            int i2 = 0;
            int tamanho_vetor_do_meio = 0;

            Ponto<long double>* pontos_ordenados_por_y_vetor_trecho = new Ponto<long double>[fim + 1];

            //gerar vetor com pontos do trecho, pontos cuja distância do meio é menor ou igual à menor distância
            for(int i = 0; i < fim + 1 - inicio;i++){
                if(abs(pontos_ordenados_por_y[i].x - pontos_ordenados_por_x[(fim+inicio)/2].x) <= a3){
                    pontos_ordenados_por_y_vetor_trecho[i2] = pontos_ordenados_por_y[i];
                    i2++;
                    tamanho_vetor_do_meio++;
                }
            }

            long double menor_distancia_trecho = menor_distancia2(pontos_ordenados_por_y_vetor_trecho, a3, pontos_ordenados_por_x[((fim+inicio)/2)].x, tamanho_vetor_do_meio);

            return Math1::menor(a3, menor_distancia_trecho);
        }
        //caso só tenha 3 ou menos pontos no vetor
        else{

            //se tem 3 elementos no vetor
            if( (fim - inicio) == 2 ){

                cout<<"teste3"<<endl;

                long double x1 = math2D::distancia_entre_pontos( pontos_ordenados_por_x[inicio],pontos_ordenados_por_x[inicio + 1]);
                long double x2 = math2D::distancia_entre_pontos( pontos_ordenados_por_x[inicio + 1],pontos_ordenados_por_x[inicio + 2]);
                long double x3 = math2D::distancia_entre_pontos( pontos_ordenados_por_x[inicio],pontos_ordenados_por_x[inicio + 2]);
                long double x4 = Math1::menor(x2,x3);

                cout<<x2<<endl;
                cout<<x3<<endl;
                cout<<x4<<endl;

                return Math1::menor(x1,x4);
            }
            //se tem 2 elementos no vetor
            else if((fim - inicio) == 1){
                cout<<"teste5"<<endl;
                return math2D::distancia_entre_pontos( pontos_ordenados_por_x[inicio],pontos_ordenados_por_x[inicio+1]);
            }
            else{
                cout<<"erro!!!!!!"<<__LINE__<< endl;
                cout<<fim - inicio<<endl;
                exit(1);
                return 0;
            }

        }

    }

    //menor_distancia é a menor distância encontrada entre a menor distância de cada um dos dois trechos
    long double menor_distancia2(Ponto<long double>* pontos_ordenados_por_y,long double menor_distancia,long double x_do_ponto_do_meio, int tamanho){

        cout<<"teste menor_distancia2" <<endl;
        cout<<tamanho<<endl;
        if(tamanho == 0){
            return menor_distancia;
        }

        cout<<"pontos do vetor do trecho: "<<endl<<endl;

        for(int i =0;i< tamanho; i++){
            pontos_ordenados_por_y[i].print();
        }
        cout<<endl<<endl;
        Ponto<long double>* pontos_ordenados_por_y_esquerda = new Ponto<long double>[tamanho];
        Ponto<long double>* pontos_ordenados_por_y_direita = new Ponto<long double>[tamanho];

        int tamanho_lado_esquerdo = 0;
        int tamanho_lado_direito = 0;

        int i_esquerda = 0;
        int i_direita = 0;

        //separar os pontos nos pontos à esquerda e à direita

        for(int i = 0; i<tamanho;i++){
            if(pontos_ordenados_por_y[i].x <= x_do_ponto_do_meio){
                pontos_ordenados_por_y[i].print();
                pontos_ordenados_por_y_esquerda[i_esquerda] = pontos_ordenados_por_y[i];

                tamanho_lado_esquerdo++;
                i_esquerda++;
            }
            else{
                pontos_ordenados_por_y_direita[i_direita] = pontos_ordenados_por_y[i];

                tamanho_lado_direito++;
                i_direita++;
            }
        }

        cout<<"lado esquerdo: "<<endl;
        for(int i =0; i <tamanho_lado_esquerdo;i++){
            pontos_ordenados_por_y_esquerda[i].print();
        }
        cout<<"lado direito: "<<endl;
        for(int i =0; i <tamanho_lado_direito;i++){
            pontos_ordenados_por_y_direita[i].print();
        }


        if(tamanho_lado_esquerdo == 0 || tamanho_lado_direito == 0){
            cout<<"um dos lados é 0, menor distância: "<<menor_distancia<<endl;
            return menor_distancia;
        }
        cout<<"teste"<<endl;
        //comparar cada ponto de um lado com os pontos do outro dentro do retângulo no outro lado

        long double menor_distancia2 = menor_distancia;

        long double distancia;
        long double distancia2;

        //i2 corresponde ao índice do vetor do lado esquerdo.
        int i2 = 0;
        int i =0;
        int i3 = 0;

        i3 = i;
        while(i2<tamanho_lado_esquerdo){
            cout<<"teste "<<i <<endl;
            //se tiver passado por todos os pontos do lado direito
            if(i3>=tamanho_lado_direito){
                break;
            }

            //salva onde começou a subir
            i = i3;
            //subindo
            while(i3<tamanho_lado_direito){
                //quando a distância passar de menor_distancia(quando passa do retângulo por cima)
                if( (abs(pontos_ordenados_por_y_esquerda[i2].y - pontos_ordenados_por_y_direita[i3].y) >= menor_distancia) && (pontos_ordenados_por_y_esquerda[i2].y < pontos_ordenados_por_y_direita[i3].y) ){
                    break;
                }
                else{

                    //se a distância entre os pontos for menor que a menor distância2
                    if(math2D::distancia_entre_pontos(pontos_ordenados_por_y_direita[i3],pontos_ordenados_por_y_esquerda[i2]) < menor_distancia2){

                       pontos_ordenados_por_y_direita[i3].print();
                       pontos_ordenados_por_y_esquerda[i2].print();


                       menor_distancia2 = math2D::distancia_entre_pontos(pontos_ordenados_por_y_direita[i3],pontos_ordenados_por_y_esquerda[i2]);

                       cout<<"menor distância: "<<endl;
                       cout<<menor_distancia2<<endl<<endl;

                    }
                    i3++;
                    cout<<" teste2 :"<<i3<<endl;

                }
            }
            //descendo
            i3 = i;
            while(i3>=0){
                //quando a distância passar de menor_distancia (quando passa do retângulo por baixo)
                if( (abs(pontos_ordenados_por_y_esquerda[i2].y - pontos_ordenados_por_y_direita[i3].y) >= menor_distancia) && (pontos_ordenados_por_y_esquerda[i2].y > pontos_ordenados_por_y[i3].y) ){
                    break;
                }
                else{
                    //se a distância entre os pontos for menor que a menor distância2
                    if(math2D::distancia_entre_pontos(pontos_ordenados_por_y_direita[i3],pontos_ordenados_por_y_esquerda[i2]) < menor_distancia2){
                        menor_distancia2 = math2D::distancia_entre_pontos(pontos_ordenados_por_y_direita[i3],pontos_ordenados_por_y_esquerda[i2]);
                    }
                    i3--;
                }
            }
            i2++;
            i3++;
            cout<<endl<<endl<<i<<endl<<endl;

        }
        cout<< "menor distância do trecho: "<<menor_distancia2<<endl<<endl;
        return menor_distancia2;
    }

    static void menor_distancia_entre_pontos(){

        math2D Math2D;
        //Quantidade de pontos
        int N;
        cin>>N;

        Ponto<long double>* pontos = new Ponto<long double>[N];
        Ponto<long double>* pontos_ordenados_por_x = new Ponto<long double>[N];
        Ponto<long double>* pontos_ordenados_por_y = new Ponto<long double>[N];

        for(int i = 0;i<N;i++){
            cin>>pontos[i].x;
            cin>>pontos[i].y;
        }

        for(int i = 0;i<N;i++){

            pontos_ordenados_por_x[i].x = pontos[i].x;
            pontos_ordenados_por_x[i].y = pontos[i].y;

            pontos_ordenados_por_y[i].x = pontos[i].x;
            pontos_ordenados_por_y[i].y = pontos[i].y;

        }

        math2D::ordena_pontos_pelo_eixo_x(pontos_ordenados_por_x, N);
        math2D::ordena_pontos_pelo_eixo_y(pontos_ordenados_por_y, N);

        long double resposta =Math2D.menor_distancia(pontos_ordenados_por_x,pontos_ordenados_por_y,0,N-1);
        cout<<endl<<endl;

        cout<<std::fixed;
        cout<< std::setprecision(3);
        cout<<resposta<<endl;

        /*caso de teste

        22
        4 2
        5 3
        10 6
        14 4
        -2 6
        2 10
        20 15
        35 10
        -20 20
        -10 20
        -10 10
        -10 -10
        30 -30
        60 0
        50 10
        70 -20
        -60 40
        -40 80
        -40 -40
        -40 -80
        -120 20
        -100 60

        saída: raiz de dois

        */



    }

    void cruzamento_de_segmentos(){

        int N;

        int K = 0;

        vector<Cruzamentos_salvos<long double>> cruzamentos_salvos;

        cin>>N;

        Segmento<long double>* segmentos = new Segmento<long double>[N];

        for(int i = 0; i<N;i++){

            cin>>segmentos[i].start.x;
            cin>>segmentos[i].start.y;

            cin>>segmentos[i].end.x;
            cin>>segmentos[i].end.y;

        }

        //há k cruzamentos

        /*
        set<Segmento<int>> segmentos2;

        //padronizar os segmentos com o ponto do início com o menor x
        for(int i =0; i<N; i++){

            if(segmentos[i].start.x >segmentos[i].end.x){
                segmentos[i].inverter();
            }

            //insere no set
            segmentos2.insert(segmentos[i]);

        }

        set<Segmento<int>>::iterator i;

        for(i = segmentos2.begin();i != segmentos2.end();i++){
            cout<<"teste"<<endl;
            Segmento<int> a = (*i);
            a.print();

        }

        */

        //mantém o menor x como início do segmento
        for(int i = 0; i<N;i++){
            if(segmentos[i].start.x>segmentos[i].end.x){
                segmentos[i].inverter();
            }
        }

        //os pontos dos segmentos
        Ponto2<long double>* pontos = new Ponto2<long double>[N*2];

        //passo os pontos para o array

        int i2=0;
        for(int i =0;i<N;i++){
            pontos[i2] = Ponto2<long double>(segmentos[i],true);
            i2++;
            pontos[i2] = Ponto2<long double>(segmentos[i],false);
            i2++;
        }

        for(int i = 0; i<N*2;i++){

            cout<<endl;
            pontos[i].print();
            cout<<endl;

        }

        //ordenamos os pontos
        sort(&pontos[0],&pontos[(N*2)]);

        cout<<"pontos ordenados: "<<endl<<endl;

        for(int i = 0; i<N*2;i++){

            cout<<endl;
            pontos[i].print();
            cout<<endl;

        }

        priority_queue<Ponto2<long double>,vector<Ponto2<long double>>,greater<Ponto2<long double>>> fila_de_prioridade_pontos;

        cout<<endl;
        cout<<"Colocando os pontos numa fila de prioridade."<<endl;

        for(int i = 0 ;i < N*2; i++){
            fila_de_prioridade_pontos.push(pontos[i]);
        }
        Ponto2<long double> auxiliar;

        /*
        cout<<"Pontos da fila de prioridade: "<<endl;

        for(int i =0;i<N*2;i++){
            auxiliar = fila_de_prioridade_pontos.top();
            auxiliar.print();

            fila_de_prioridade_pontos.pop();
        }

        cout<<endl;
        cout<<"...................................................."<<endl;
        cout<<"...................................................."<<endl;
        cout<<endl;

        */

        //ATENÇÃO, pontos é um ponteiro para Ponto2, ou seja, corresponde a eventos

        //nesse set inserimos os pontos à medida que percorremos o vetor ordenado por x.(o vetor é ordenado em O(log n))

        set<Ponto2<long double>,Comparator<long double>> pontos2_set;

        set<Ponto2<long double>,Comparator<long double>>::iterator i_set;
        set<Ponto2<long double>,Comparator<long double>>::iterator i_set2;

        set<Ponto2<long double>,Comparator<long double>>::iterator i_set3;
        set<Ponto2<long double>,Comparator<long double>>::iterator i_set4;

        cout<<"Adicionando pontos no set (eventos):"<<endl<<endl;

        Ponto2<long double> ponto_anterior;
        Ponto2<long double> ponto_seguinte;


        //N é a quantidade de segmentos.
        for(int i = 0; i < (2*N); i++){
            //adicionamos os eventos no set percorrendo os pontos na ordem de x

            auxiliar = fila_de_prioridade_pontos.top();


            if(auxiliar.is_start && auxiliar.ponto_de_cruzamento == false){
                //se o ponto é evento do início do segmento
                auxiliar.print();
                cout<<"Evento de início do segmento."<<endl;
                cout<<endl<<endl;

                //adiciona o ponto no set
                pontos2_set.insert(auxiliar);

                //verifica o cruzamento desse segmento com o acima, e desse segmento com o abaixo

                //encontra a posição do ponto inserido no set
                i_set2 =  pontos2_set.find(auxiliar);

                i_set3 = pontos2_set.begin();
                i_set4 = pontos2_set.end();
                i_set4--;

                Ponto2<long double> i_set2_ponto = *i_set2;
                Ponto2<long double> i_set3_ponto = *i_set3;
                Ponto2<long double> i_set4_ponto = *i_set4;

                bool first = false;
                bool last = false;

                if( i_set2_ponto.mesmo_ponto(i_set3_ponto)){
                    cout<<"Primeiro elemento do set"<<endl;
                    first = true;


                }
                if( i_set2_ponto.mesmo_ponto(i_set4_ponto)){
                    cout<<"Último elemento do set"<<endl;
                    last = true;


                }



                    //cout<<"Não é primeiro elemento do set, nem último."<<endl;

                    Ponto2<long double> teste;
                    teste = *i_set3;
                    teste.print();
                    cout<<endl;
                    teste = *i_set3;
                    teste.print();
                    cout<<endl;
                    teste = *i_set2;
                    teste.print();
                    cout<<endl;

                     i_set2--;
                     ponto_anterior = *i_set2;

                     i_set2++;
                     i_set2++;

                     ponto_seguinte = *i_set2;



                     if( (cruza2(ponto_anterior.segmento,auxiliar.segmento) == 1) && (first == false) ){

                        cout<<"O segmento adicionado cruza com o segmento abaixo."<<endl;




                        //para fazer fazer o cruzamento de segmento com pontos em double

                        Segmento<long double> segmento1;

                        segmento1.start.x = ponto_anterior.segmento.start.x;
                        segmento1.start.y = ponto_anterior.segmento.start.y;

                        segmento1.end.x = ponto_anterior.segmento.end.x;
                        segmento1.end.y = ponto_anterior.segmento.end.y;

                        Segmento<long double> segmento2;

                        segmento2.start.x = auxiliar.segmento.start.x;
                        segmento2.start.y = auxiliar.segmento.start.y;

                        segmento2.end.x = auxiliar.segmento.end.x;
                        segmento2.end.y = auxiliar.segmento.end.y;



                        Ponto<long double> ponto_de_cruzamento = ponto_de_cruzamento_function(segmento1,segmento2);

                        cout<<"Ponto de cruzamento: ";
                        ponto_de_cruzamento.print();

                        Ponto2<long double> ponto_de_cruzamento2(ponto_de_cruzamento);

                        pontos2_set.insert(ponto_de_cruzamento2);


                        K++;
                        Cruzamentos_salvos<long double> cruzamento(segmento1,segmento2);
                        cruzamentos_salvos.push_back(cruzamento);

                        cout<<endl<<endl;



                     }
                     if( (cruza2(ponto_seguinte.segmento,auxiliar.segmento) == 1) && last == false ){
                        cout<<"O segmento adicionado cruza com o segmento acima."<<endl;


                        //para fazer fazer o cruzamento de segmento com pontos em double

                        Segmento<long double> segmento1;

                        segmento1.start.x = auxiliar.segmento.start.x;
                        segmento1.start.y = auxiliar.segmento.start.y;

                        segmento1.end.x = auxiliar.segmento.end.x;
                        segmento1.end.y = auxiliar.segmento.end.y;

                        Segmento<long double> segmento2;

                        segmento2.start.x = ponto_seguinte.segmento.start.x;
                        segmento2.start.y = ponto_seguinte.segmento.start.y;

                        segmento2.end.x = ponto_seguinte.segmento.end.x;
                        segmento2.end.y = ponto_seguinte.segmento.end.y;

                        Ponto<long double> ponto_de_cruzamento = ponto_de_cruzamento_function(segmento1, segmento2);

                        cout<<"Ponto de cruzamento: "<<endl;

                        ponto_de_cruzamento.print();


                        Ponto2<long double> ponto_de_cruzamento2(ponto_de_cruzamento);

                        pontos2_set.insert(ponto_de_cruzamento2);


                        K++;
                        Cruzamentos_salvos<long double> cruzamento(segmento1,segmento2);
                        cruzamentos_salvos.push_back(cruzamento);


                     }
                     else{
                        cout<<"Os segmentos não cruzam."<<endl;
                     }


            }
            else if(auxiliar.ponto_de_cruzamento == false){
                //se o ponto é evento do final do segmento
                auxiliar.print();
                cout<<"Evento de final do segmento.";
                cout<<endl<<endl;

                //remove o elemento do set
                auto ponteiro = pontos2_set.find(auxiliar);


                //veriifica o cruzamento do segmento acima com o segmento abaixo.

                i_set2 =  pontos2_set.find(auxiliar);

                i_set3 = pontos2_set.begin();
                i_set4 = pontos2_set.end();
                i_set4--;

                Ponto2<long double> i_set2_ponto2 = *i_set2;
                Ponto2<long double> i_set3_ponto2 = *i_set3;
                Ponto2<long double> i_set4_ponto2 = *i_set4;

                if(i_set2_ponto2.mesmo_ponto(i_set3_ponto2) || i_set2_ponto2.mesmo_ponto(i_set4_ponto2)){
                    cout<<"Primeiro elemento do set, ou último."<<endl;
                    Ponto2<long double> teste;
                    teste = *i_set3;
                    teste.print();
                    cout<<endl;
                    teste = *i_set3;
                    teste.print();
                    cout<<endl;
                    teste = *i_set2;
                    teste.print();
                    cout<<endl;

                }
                else{

                    cout<<"Não é primeiro elemento do set, nem último."<<endl;
                    Ponto2<long double> teste;
                    teste = *i_set3;
                    teste.print();
                    cout<<endl;
                    teste = *i_set3;
                    teste.print();
                    cout<<endl;
                    teste = *i_set2;
                    teste.print();
                    cout<<endl;


                    i_set2++;
                    ponto_anterior = *i_set2;
                    i_set2--;
                    i_set2--;
                    ponto_seguinte = *i_set2;

                    if(cruza2(ponto_anterior.segmento,ponto_seguinte.segmento) == 1){

                        cout<<"Os segmento abaixo e acima se cruzam."<<endl;

                        //criar ponto de cruzamento
                        //colocar ponto de cruzamento no set



                        //para fazer fazer o cruzamento de segmento com pontos em double

                        Segmento<long double> segmento1;

                        segmento1.start.x = ponto_anterior.segmento.start.x;
                        segmento1.start.y = ponto_anterior.segmento.start.y;

                        segmento1.end.x = ponto_anterior.segmento.end.x;
                        segmento1.end.y = ponto_anterior.segmento.end.y;

                        Segmento<long double> segmento2;

                        segmento2.start.x = ponto_seguinte.segmento.start.x;
                        segmento2.start.y = ponto_seguinte.segmento.start.y;

                        segmento2.end.x = ponto_seguinte.segmento.end.x;
                        segmento2.end.y = ponto_seguinte.segmento.end.y;

                        Ponto<long double> ponto_de_cruzamento = ponto_de_cruzamento_function(segmento1,segmento2);

                        cout<<"Ponto de cruzamento: "<<endl;
                        ponto_de_cruzamento.print();


                        Ponto2<long double> ponto_de_cruzamento2(ponto_de_cruzamento);

                        pontos2_set.insert(ponto_de_cruzamento2);


                        K++;
                        Cruzamentos_salvos<long double> cruzamento(segmento1,segmento2);
                        cruzamentos_salvos.push_back(cruzamento);

                    }
                    else{
                        cout<<"Os segmentos abaixo e acima não se cruzam."<<endl;
                    }

                }



                pontos2_set.erase(ponteiro);

            }
            else{




                i_set2 =  pontos2_set.find(auxiliar);

                i_set3 = i_set2;
                i_set4 = i_set2;

                i_set3--;

                i_set4++;

                //pegar cada segmento do cruzamento e inserir de novo

                Ponto2<long double> ponto_anterior = *i_set3;
                Ponto2<long double> ponto_seguinte = *i_set4;

                pontos2_set.erase(i_set3);
                pontos2_set.erase(i_set4);


                pontos2_set.insert(Ponto2<long double>(ponto_anterior.segmento,true,true,auxiliar.segmento.start));

                pontos2_set.insert(Ponto2<long double>(ponto_seguinte.segmento,false,true,auxiliar.segmento.start));




            }

            cout<<endl<<endl;
            cout<<"........................."<<endl;
            cout<<"Elementos no set nesse momento: "<<endl;

            for (i_set = pontos2_set.begin(); i_set != pontos2_set.end(); i_set++){

                Ponto2<long double> a;
                a = *i_set;
                a.print();

            }

            fila_de_prioridade_pontos.pop();

            cout<<endl<<"........................."<<endl<<endl;

        }






        //exemplo de entrada

        /*
        4
        3 4
        6 7
        8 7
        3 5
        1 6
        9 5
        5 1
        7 8
        */


    }
};

int main(){

    math2D Math2D;

    Math2D.cruzamento_de_segmentos();




/*
    Segmento<long double> segmento1(Ponto<long double>(1.0,1.0),Ponto<long double>(10.0,10.0));

    Segmento<long double> segmento2(Ponto<long double>(1.0,3.0),Ponto<long double>(7.0,5.0));


    Ponto<long double> ponto1 = Math2D.ponto_de_cruzamento(segmento1,segmento2);

    ponto1.print();

*/







    /*
    Segmento<long double> segmento1(Ponto<long double>(4,6),Ponto<long double>(7,3));
    Segmento<long double> segmento2(Ponto<long double>(8,3),Ponto<long double>(2,8));
    Segmento<long double> segmento3(Ponto<long double>(4,6),Ponto<long double>(2,3));
    Segmento<long double> segmento4(Ponto<long double>(5,3),Ponto<long double>(2,8));
    Segmento<long double> segmento5(Ponto<long double>(76,6),Ponto<long double>(3,3));
    Segmento<long double> segmento6(Ponto<long double>(8,3),Ponto<long double>(9,8));

    set<Segmento<long double>> segmentos;
    segmentos.insert(segmento1);
    segmentos.insert(segmento2);
    segmentos.insert(segmento4);
    segmentos.insert(segmento6);
    segmentos.insert(segmento3);
    segmentos.insert(segmento5);

    set<Segmento<long double>>::iterator i;

    for(i = segmentos.begin(); i != segmentos.end(); i++){
        cout<<(*i).start.x<<endl;
        Segmento<long double> (*i).print();
    }
    */

    //Segmento<long double> teste(Ponto<long double>(0.0,0.0),Ponto<long double>(8.0,2.0));

    //long double a = y_em_um_determinado_x(teste,4.0);

    //teste.print();

    //cout<<"teste" << a<<endl;

    return 0;

}
