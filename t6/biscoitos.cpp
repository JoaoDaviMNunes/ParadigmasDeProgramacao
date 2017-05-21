#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <algorithm>

#define PI 3.141592
#define TAM_G 100
#define TAM_M 64
#define VALOR_G 10
#define VALOR_M 5
#define VALOR_P 2


class Biscoitos{
protected:
    float dimensao;

public:
    float get_dimensao(){
        return dimensao;
    }
};

class Circulo : public Biscoitos{
private:
    int raio;
    float areaC;

public:
    Circulo(){
        raio= 0;
        areaC= 0.0;
    }

    Circulo(int r){
        raio = r;
        areaC = PI*raio*raio;
        this->dimensao = areaC;
    }

};

class Retangulo : public Biscoitos{
private:
    int bR, hR, areaR;

public:
    Retangulo(){
        bR = hR = areaR = 0;
    }

    Retangulo(int base, int altura){
        bR = base;
        hR = altura;
        areaR = bR*hR;
        this->dimensao = areaR;
    }

};

class Triangulo : public Biscoitos{
private:
    int bT, hT;
    float areaT;

public:
    Triangulo(){
        bT = hT = 0;
        areaT = 0.0;
    }

    Triangulo(int bas, int alt){
        bT = bas;
        hT = alt;
        areaT = (bT*hT)/2;
        this->dimensao = areaT;
    }
};


int comparaDimensao(Biscoitos b1, Biscoitos b2){
    return (b1.get_dimensao() > b2.get_dimensao());
}

void imprimeBiscoitos(std::vector<Biscoitos> b1){
    std::vector<Biscoitos>::iterator it = b1.begin();
    std::cout << "Biscoitos (tamanhos em ordem decrescente):" << std::endl;
    while(it != b1.end()){
        std::cout << " " << it->get_dimensao() << " cm2" << std::endl;
        it++;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void imprimeQntd_ValorF(std::vector<Biscoitos> b1){
    int valorF, qntdP, qntdM, qntdG;
    valorF = qntdG = qntdM = qntdP = 0;

    std::vector<Biscoitos>::iterator it = b1.begin();
    while(it != b1.end()){
        if(it->get_dimensao() > TAM_G){
            valorF += VALOR_G;
            qntdG++;
        }else if(it->get_dimensao() <= TAM_G && it->get_dimensao() > TAM_M){
            valorF += VALOR_M;
            qntdM++;
        }else if(it->get_dimensao() <= TAM_M){
            valorF += VALOR_P;
            qntdP++;
        }

        it++;
    }

    std::cout << "Quantidade de biscoitos pequenos = " << qntdP << std::endl;
    std::cout << "Valor arrecadado com os biscoitos pequenos = " << (qntdP*VALOR_P) << " reais" << std::endl;
    std::cout << std::endl;
    std::cout << "Quantidade de biscoitos medios = " << qntdM << std::endl;
    std::cout << "Valor arrecadado com os biscoitos medios = " << (qntdM*VALOR_M) << " reais" << std::endl;
    std::cout << std::endl;
    std::cout << "Quantidade de biscoitos grandes = " << qntdG << std::endl;
    std::cout << "Valor arrecadado com os biscoitos grandes = " << (qntdG*VALOR_G) << " reais" << std::endl;
    std::cout << std::endl;

    std::cout << "Valor total acumulado da venda dos biscoitos = " << valorF << std::endl;
}


int main(){
    int N;
    std::cout << "Quantos biscoitos deseja fazer no total: ";
    std::cin >> N;
    std::cout << std::endl;

    std::vector<Biscoitos> bis;
    int i=0, tipo;
    srand(time(0));
    while(i<N){
        tipo = rand()%3;
        if(tipo == 0){
            auto raio = rand() % 7 + 2;
            bis.push_back(Circulo(raio));
        }else if(tipo == 1){
            auto r1 = rand() % 10 + 6;
            auto r2 = rand() % 10 + 6;
            bis.push_back(Retangulo(r1, r2));
        }else if (tipo == 2){
            auto t1 = rand() % 13 + 9;
            auto t2 = rand() % 13 + 9;
            bis.push_back(Triangulo(t1, t2));
        }
        i++;
    }

    sort(bis.begin(), bis.end(), comparaDimensao);
    imprimeBiscoitos(bis);
    imprimeQntd_ValorF(bis);

    return 0;
}
