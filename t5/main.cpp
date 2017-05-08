#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

class Atividade{
    private:
        std::string name, atividade;
        int pontos;

    public:
        Atividade(){
            name = " ";
            atividade = " ";
            pontos = 0;
        }

        Atividade(std::string nome2, int pontos2, std::string at2){
            name = nome2;
            pontos = pontos2;
            atividade = at2;
        }

        std::string get_name(){
            return name;
        }

        std::string get_atividade(){
            return atividade;
        }

        int get_pontos(){
            return pontos;
        }

        bool operator<(Atividade& a) {
            return pontos < a.pontos;
        }

};

//pontuacao em cada atividade
class Pontuacao{
    private:
        int diiab, diib, dtab, dtt;

    public:
        Pontuacao(){
            diiab = diib = dtab = dtt = 0;
        }

        Pontuacao(int diiab2, int diib2, int dtab2, int dtt2){
            diiab = diiab2;
            diib = diib2;
            dtab = dtab2;
            dtt = dtt2;
        }

        int get_diiab_aux(){
            return diiab;
        }

        int get_diib_aux(){
            return diib;
        }

        int get_dtab_aux(){
            return dtab;
        }

        int get_dtt_aux(){
            return dtt;
        }

        int get_soma_aux(){
            return (diiab+diib-dtab-dtt);
        }

};

//pontuacao no total
class Personagem{
    private:
        std::string nome;
        Pontuacao p;
        int soma;

    public:
        Personagem(){
            nome = " ";
            Pontuacao();
            soma = 0;
        }

        Personagem(std::string nome2, int diiab2, int diib2, int dtab2, int dtt2){
            nome = nome2;
            p = Pontuacao(diiab2, diib2, dtab2, dtt2);
            soma = p.get_soma_aux();
        }

        std::string get_nome(){
            return nome;
        }

        int get_diiab(){
            return p.get_diiab_aux();
        }

        int get_diib(){
            return p.get_diib_aux();
        }

        int get_dtab(){
            return p.get_dtab_aux();
        }

        int get_dtt(){
            return p.get_dtt_aux();
        }

        int get_soma(){
            return soma;
        }

};


//auxiliar para a comparacao entre nomes
bool cmpPersonagemName(Personagem& p1, Personagem& p2) {
   return p1.get_nome() < p2.get_nome();
}

//auxiliar para a comparacao entre pontos
bool cmpPersonagemSoma(Personagem& p1, Personagem& p2) {
   return p1.get_soma() < p2.get_soma();
}

int main(){
    std::ifstream entrada ("score.csv");           //abro um arquivo e declaro um nome a ele

    if(entrada.is_open() == false){                  //verifico se o arquivo está aberto
        std::cout << "Erro na abertura do arquivo" << std::endl;
        return -1;
    }

    std::string auxiliar;
    std::vector<Personagem> v;
    std::vector<Atividade> ato;

    while(!entrada.eof()){
        std::string u[2];
        int point;
        for(auto i=0; i<40; i++){
            std::getline(entrada, auxiliar, '|');
            u[0] = auxiliar;

            std::getline(entrada, auxiliar, '|');
            point = atoi(auxiliar.c_str());

            std::getline(entrada, auxiliar);
            u[1] = auxiliar;

            ato.push_back(Atividade(u[0], point, u[1]));
        }



        std::string nick;
        int d1, d2, d3, d4;

        for(auto i=0; i<10; i++){
            std::getline(entrada, auxiliar, '|');
            nick = auxiliar;

            std::getline(entrada, auxiliar, '|');
            d1 = atoi(auxiliar.c_str());

            std::getline(entrada, auxiliar, '|');
            d2 = atoi(auxiliar.c_str());

            std::getline(entrada, auxiliar, '|');
            d3 = atoi(auxiliar.c_str());

            std::getline(entrada, auxiliar);
            d4 = atoi(auxiliar.c_str());

            v.push_back(Personagem(nick, d1, d2, d3, d4));
        }
    }


    //ordena o vetor de atividades
    sort(ato.begin(), ato.end());
    //printando do maior pro menor
    std::cout << "##### LISTA POR ORDEM DE PONTOS EM ATIVIDADES #####" << std::endl;
    for(auto i = ato.size()-1 ; i != -1; i--){
        std::cout << ato[i].get_name() << " -> " << ato[i].get_atividade() << " -> " << ato[i].get_pontos() << std::endl;
    }
    std::cout << std::endl;


    std::vector<Personagem>::iterator it;
    std::sort(v.begin(), v.end(), cmpPersonagemName);
    std::cout << "##### LISTA POR ORDEM ALFABETICA #####" << std::endl;
    for(it= v.begin(); it != v.end(); it++){
        std::cout << it->get_nome() << std::endl;
        std::cout << "-> Pontuacao total: " << it->get_soma() << std::endl;
    }
    std::cout << std::endl;

    std::sort(v.begin(), v.end(), cmpPersonagemSoma);
    std::cout << "##### LISTA POR ORDEM DE PONTUACAO FINAL #####" << std::endl;
    for(it= v.begin(); it != v.end(); it++){
        std::cout << it->get_nome() << std::endl;
        std::cout << "-> Pontuacao total: " << it->get_soma() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
