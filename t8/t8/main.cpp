// Programa produzido por João Davi Martins Nunes em 2017/1
// Aula de Paradigmas da Programação

#include <string>
#include <stdexcept>
#include <FL/fl_ask.H>
#include <thread>
#include "window.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <sstream>

class Data{

private:
  std::string id;
  std::string label;

public:
  Data(std::string id, std::string label){
    this->id = id;
    this->label = label;
  }

  std::string getId(){
    return id;
  }

  std::string getLabel(){
    return label;
  }

  void setId(std::string id){
    this->id = id;
  }

  void setLabel(std::string label){
    this->label = label;
  }

};


class View : public UserInterface {

protected:
  std::vector<Data> data;
  std::string tituloBox;

public:

  View() {
    btnClear->callback((Fl_Callback*) cbBtnClear, (void*)(this));
    btnUpdate->callback((Fl_Callback*) cbBtnUpdate, (void*)(this)); 
    btnDelete->callback((Fl_Callback*) cbBtnDelete, (void*)(this)); 
    btnInsert->callback((Fl_Callback*) cbBtnInsert, (void*)(this)); 
    browser->callback((Fl_Callback*) cbBrowser, (void*)(this));
    importar->callback((Fl_Callback*) cbImport, (void*)(this));
    exportar->callback((Fl_Callback*) cbExport, (void*)(this));
    reset->callback((Fl_Callback*) cbReset, (void*)(this));
    gerador->callback((Fl_Callback*) cbGerador, (void*)(this));
  }

  void show() {
    // Mostra janela
    w->show();
  }

  // Funcao callback chamada quando pressionado botao 'Importar'
  static void cbImport(Fl_Widget* btn, void* userdata) {
    View *gui = static_cast<View*>(userdata);
    std::string file(gui->arquivo->value());
    std::ifstream entrada("arquivos/" + file + ".csv");
    if(entrada.is_open()){
        for(int i = gui->data.size()-1; i >= 0; i--){
	      gui->data.pop_back();
          gui->browser->remove(i+1);
        }
        gui->tituloBox = "";
        gui->titulo_aux->label("");

	    std::string linha;
        std::string splited[2];
	    getline(entrada, linha);
	    gui->tituloBox = linha;
	    while(!entrada.eof()){
	      getline(entrada,linha);
	      if(!linha.empty()){
	        std::stringstream linestream(linha);
	        getline(linestream,splited[0], ',');
	        getline(linestream,splited[1], ',');
	        gui->data.push_back(Data(splited[1], splited[0]));
	      }
	    }
	    gui->titulo_aux->label((gui->tituloBox).c_str());
	    for(int i=0 ; i < gui->data.size() ; i++){
	      gui->browser->add((gui->data[i].getId() + " | " + gui->data[i].getLabel()).c_str());
	    }
    }else{
	    fl_alert("Projeto não encontrado");
    }
  }

  // Funcao callback chamada quando pressionado botao 'Exportar'
  static void cbExport(Fl_Widget* btn, void* userdata) {
    View *gui = static_cast<View*>(userdata);
    std::string file(gui->arquivo->value());
    if(file != ""){
      std::string aux(gui->tituloBox);
      if(aux == "")
        fl_alert("Insira um titulo para seu projeto");
      else{
        std::ofstream saida("arquivos/" + file + ".csv");
        saida << gui->tituloBox << std::endl;
        for(int i = 0 ; i < gui->data.size(); i++){
          saida << gui->data[i].getId() << "," << gui->data[i].getLabel() << std::endl;
        }
      }
    }else{
      fl_alert("Insira o nome do arquivo a ser salvo");
    }
  }

  // Funcao callback chamada quando pressionado botao 'Limpar'
  static void cbReset(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    gui->titulo->value("");
    gui->id->value("");
    gui->label->value("");
    gui->browser->clear();
  }

  // Funcao callback chamada quando pressionado botao 'Limpar'
  static void cbBtnClear(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    gui->titulo->value("");
    gui->id->value("");
    gui->label->value("");
  }

  // Funcao callback chamada quando pressionado botao 'Inserir'
  static void cbBtnInsert(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    try{
        std::string id(gui->id->value());
        std::string label(gui->label->value());
        gui->titulo_aux->label(gui->titulo->value());
        gui->data.push_back(Data(id, label));
        gui->browser->add((id+" : "+label).c_str());
    }catch(std::invalid_argument&){
        fl_alert("Digite em todos os campos (Título, ID, label)!");
    }
  }

  // Funcao callback chamada quando selecionada uma linha no Fl_Browser
  static void cbBrowser(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    gui->id->value(gui->data[index-1].getId().c_str());
    gui->label->value(gui->data[index-1].getLabel().c_str());
  }

  // Funcao callback chamada quando pressionado botao 'Atualizar'
  static void cbBtnUpdate(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    if (index > 0) {
      std::string id(gui->id->value());
      std::string label(gui->label->value());
      gui->data[index-1].setId(id);
      gui->data[index-1].setLabel(label);
      gui->browser->text(index,(id+" : "+label).c_str());
    }
  }

  // Funcao callback chamada quando pressionado botao 'Deletar'
  static void cbBtnDelete(Fl_Widget* btn, void* userdata) {
    View* gui = static_cast<View*>(userdata);
    int index = gui->browser->value(); // 1-based index
    std::cout << index << std::endl;
    if (index > 0) {
      std::string id(gui->id->value());
      std::string label(gui->label->value());
      gui->data.erase(gui->data.begin() + index-1);
      gui->browser->remove(index);
    }
  }

  void cbGerador3(std::ofstream &saida){
    for(int i = 0; i < data.size(); i++){
      saida << "<div class=\"form-group\">\n" << "<label for=\"" << data[i].getId() << "\" class=\"col-sm-2 control-label\">" << data[i].getLabel() << "</label>\n" << "<div class=\"col-sm-6\">\n" << "<input type=\"text\" class=\"form-control validate[required]\" id=\"" << data[i].getId() << "\" placeholder=\"" << data[i].getLabel() << "\">\n" << "</div>\n" << "</div>\n";
    }
  }

  void cbGerador4(std::ofstream &saida){
    saida << "dataSet[seq]=[index,icons";
    for(int i = 0; i < data.size(); i++){
      saida << ", " << data[i].getId();
    }
    saida << "];\n";
  }

  void cbGerador5(std::ofstream &saida){
    saida << "oTable=$('#table').dataTable({\n" <<"\"data\": dataSet,\n" <<"\"columns\": [\n" <<"{ \"title\": \"Seq\", \"class\": \"center\" },\n" <<"{ \"title\": \"\", \"class\": \"center\" },\n";
    for(int i = 0; i < data.size(); i++){
	    saida << "{\"title\": \"" << data[i].getLabel() << "\"},\n";
    }
    saida << "]\n" << "});\n";
  }

  void cbGerador6(std::ofstream &saida){
    saida << "$('#table tbody').on( 'click', '.glyphicon-edit', function () {\n" << "$('#list').hide();\n" << "var rows = $(this).parents('tr').children();\n" << "$('#seq').text(rows[0].innerHTML);\n";
    for(int i = 0; i < data.size(); i++){
      saida << "$('#" << data[i].getId() << "').val(rows[" << i+2 << "].innerHTML);\n";
    }
    saida << "$('#formID').show()\n;" << "} );";
  }

  void cbGerador7(std::ofstream &saida){
    saida << "function save() {\n" << "var seq=$('#seq').text();\n" << "if ( isNaN(seq) ) { seq=0; }\n" << "var key=formId+\"_\"+seq;\n" << "var object={\n";
    for(int i = 0; i < data.size(); i++){
      saida <<  "\"" << data[i].getId() << "\": $(\"#" << data[i].getId() << "\").val(),\n";
    }
    saida <<"}\n"<< "localStorage.setItem(key, JSON.stringify(object));\n" << "}\n";
  }

  static void cbGerador(Fl_Widget* btn, void* userdata){
    View* gui = static_cast<View*>(userdata);
    std::ifstream entrada("template.html");
    std::ofstream saida("index.html");
    if(entrada.is_open()){
        std::string linha;
        while(!entrada.eof()){
	        getline(entrada,linha);
	        if(linha == ">>>1<<<")
                saida << "<title>" << gui->tituloBox << "</title>" << std::endl;
	        else if(linha == ">>>2<<<")
                saida << "<h1>" << gui->tituloBox << "</h1>" << std::endl;
	        else if(linha == ">>>3<<<")
                gui->cbGerador3(saida);
	        else if(linha == ">>>4<<<")
                gui->cbGerador4(saida);
	        else if(linha == ">>>5<<<")
                gui->cbGerador5(saida);
	        else if(linha == ">>>6<<<")
                gui->cbGerador6(saida);
	        else if(linha == ">>>7<<<")
                gui->cbGerador7(saida);
	        else
                saida << linha << std::endl;
        }
    }
  }

};


int main() {
  View gui;
  gui.show();
  return Fl::run();
}
