#include <FL/fl_ask.H>
#include "window.h"
#include <iostream>
#include <vector>
#include <cstdbool>
#include <ctime>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

class SorteioView : public UserInterface {

protected:
  std::vector<int> vencedores;
  bool maxwin; //verifica se chegou no maximo de partipantes sorteados
  int num; //numero do vencedor

public:
  
  SorteioView() {
    num=1;
    sortear->callback((Fl_Callback*) cbSortear, (void*)(this));
    reset->callback((Fl_Callback*) cbReset, (void*)(this));
  }
  
  //mostra tela
  void show() {
    tela->show();
  }

  //funcao que preenche a sequencia de vencedores
  void preenche_vetor(int tam) {
    for(int i=1; i<= tam; i++){
      vencedores.push_back(i);
    }
    std::random_shuffle(vencedores.begin(), vencedores.end());
    maxwin = false;
  }
  
  // Funcao callback chamada quando pressionado botao 'sortear'
  static void cbSortear(Fl_Widget* btn, void* userdata) {
    SorteioView* data = static_cast<SorteioView*>(userdata);
    
    try{
      int tam = std::stoi(data->participantes->value());

      //quando o vetor esta vazio, verifica se eh para preencher ou avisar que o sorteio acabou
      if(data->vencedores.empty()){
        if(data->maxwin == false){
          data->preenche_vetor(tam);
        }else{
          data->participantes->value("");
          data->saidasorteio->label("");
          data->xganhador->label("");
          data->vencedores.clear(); //zera o vetor de sorteados tambem, caso ainda possua algo nele
          data->num = 1;
          data->maxwin == false;
        }
      }

      //verifico se a pessoa digitou um numero invalido
      if ( data->maxwin == false ) {
        if(tam <= 0){
          fl_alert("Numero invalido. Apenas numeros maiores que zero");
        }else{         
          int aux = data->vencedores.back();
          data->vencedores.pop_back();
          data->saidasorteio->copy_label(std::to_string(aux).c_str());
          std::string winner = std::to_string(data->num).c_str();
          data->num++;
          winner += "Âº ganhador";
          data->xganhador->copy_label(winner.c_str());
          if(data->num > tam) data->maxwin = true;
        }
      }else{
        fl_alert("Todos os numeros foram sorteados!");
        data->maxwin = false;
      }

    }catch (std::invalid_argument&){
      fl_alert("Digite a quantidade de participantes");
    }
  }

  // Funcao callback chamada quando pressionado botao 'reset'
  static void cbReset(Fl_Widget* btn, void* userdata) {
    SorteioView* data = static_cast<SorteioView*>(userdata);
    data->participantes->value("");
    data->saidasorteio->label("");
    data->xganhador->label("");
    data->vencedores.clear(); //zera o vetor de sorteados tambem, caso ainda possua algo nele
    data->num = 1;
    data->maxwin == false;
  }

};

int main(){
  SorteioView data;
  data.show();

  srand(time(NULL));

  return Fl::run();
}
