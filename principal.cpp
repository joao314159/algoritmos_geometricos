


#include <iostream>
#include <vector>
#include <typeinfo>
#include <ctime>
#include <cstdlib>
#include <math.h>

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
    
    void print(){
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

    Ponto<T> start;
    Ponto<T> end;
    
    void print(){
        cout<<"Esse segmento começa em ("<<this->start.x<<", "<<this->start.y<<") e termina em ("<<this->end.x<<", "<<this->end.y<<") "<<endl;
    }
    
    void inverter(){
        Ponto<T> ponto;
        ponto = this->start;
        this->start = this->end;
        this->end = ponto;
    }

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
        static void merge05(T vetor[], int esquerda,int meio, int direita, int tamanho, int y){
            
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
                
                if((auxiliar[i].end.x - auxiliar[i].start.x) == 0){
                    //reta vertical
                    x1 = auxiliar[i].end.x;
                }
                else if((auxiliar[i2].end.x - auxiliar[i2].start.x) == 0){
                    //reta vertical
                    x2 = auxiliar[i2].end.x;
                }
                else{
                    o1 = abs(auxiliar[i].end.y - auxiliar[i].start.y)/abs(auxiliar[i].end.x - auxiliar[i].start.x);
                    o2 = abs(auxiliar[i2].end.y - auxiliar[i2].start.y)/abs(auxiliar[i2].end.x - auxiliar[i2].start.x);
                
                
                    if((auxiliar[i].end.y - auxiliar[i].start.y) == 0 || (auxiliar[i2].end.y - auxiliar[i2].start.y)==0){
                        cout<<"erro"<<endl;
                    }
                    else{
                      
                        if(auxiliar[i].start.x<auxiliar[i].end.x){
                            x1 = auxiliar[i].start.x - (auxiliar[i].start.y - y)/o1;
                        }
                        else if(auxiliar[i].start.x>auxiliar[i].end.x){
                            x1 = auxiliar[i].start.x +(auxiliar[i].start.y - y)/o1;
                        }
                        
                        if(auxiliar[i2].start.x<auxiliar[i2].end.x){
                            x2 = auxiliar[i2].start.x - (auxiliar[i2].start.y - y)/o1;
                        }
                        else if(auxiliar[i2].start.x>auxiliar[i2].end.x){
                            x2 = auxiliar[i2].start.x +(auxiliar[i2].start.y - y)/o1;
                        }
                        
                    }
                
                }
          
                
                if(x1 <= x2 ){
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
        static void merge_sort205(T vetor[],int tamanho, int esquerda,int direita, int y){
            
            if (esquerda>=direita){
                return;
            }
            
            int meio = (esquerda + direita)/2;
            
            merge_sort205(vetor,tamanho,esquerda,meio,y);
            merge_sort205(vetor,tamanho,meio+1,direita,y);
            
            merge05(vetor, esquerda, meio, direita, tamanho,y);
            
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
    static void ordena_segmentos(Segmento<T>* segmentos, int tamanho,int y){
        merge_sort205(segmentos,tamanho,0,tamanho-1,y);
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
    //não funciona(funciona sim, confia)
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
    
    //funciona para polígonos não convexos
    static void ponto_em_poligono3(){
        
        //math2D Math2D;
         
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
        
        for(int i = 0;i<quantidade_de_trechos;i++){
            
            trechos[i].print();
            cout<<endl;
        }
        
        int quantidade_de_segmentos =0;
       
        //para cada vetor de segmentos adicionar os segmentos que cruzam a reta horizontal
        
        for(int i = 0;i<quantidade_de_trechos;i++){
            
            
            quantidade_de_segmentos = 0;
            
            Segmento<long double> horizontal(Ponto<long double>(menor_x-2.0,trechos[i].y1),Ponto<long double>(maior_x+2.0,trechos[i].y2));
            
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
            math2D::ordena_segmentos(&trechos[i].vetor[0],quantidade_de_segmentos,trechos[i].y1);
            
        }
        
        for(int i =0;i<quantidade_de_trechos;i++){
            trechos[i].print();
        }
       
        
        //fazer a busca binária para encontrar o trecho, depois fazer a busca binária para encontrar o segmento
        
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
        9
        6.0 9.0 
        8.0 7.0 
        6.0 6.5 
        5.5 5.5 
        8.0 4.5 
        4.0 3.0 
        2.8 2.8 
        3.0 2.0 
        10.0 5.0 
        
        fora 
        dentro
        dentro 
        em cima 
        fora 
        dentro 
        dentro 
        em cima 
        dentro 
        
        
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

};


int main(){
    
    math2D Math2D;
    
  
    math2D::ponto_em_poligono3();
   
    
    return 0;
}
