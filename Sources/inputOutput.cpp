
#include "inputOutput.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/**
 * @file inputOutput.cpp
 * @brief Implementação de leitura e gravação de arquivo
 * @date 2021-07-06
 */

/**
 * @brief Inicia o arquivo
 * 
 * @param path 
 * @return vector<string> 
 */
vector<string> inputFile(string path) {
  fstream input_txt;
  input_txt.open(path, ios::in); //abre o arquivo

  //verifica se o arquivo está aberto
  if (!input_txt.is_open()) {
    cout << "\nErro ao abrir arquivo!\n";
    exit(1);
  } else {
    //Le os dados do arquivo
    vector<string> lines = getLines(input_txt);
    cout << "\nLeitura realizada com sucesso!\n";
    input_txt.close();
    return lines;
  }
}

void OutputFile(string path, string text) {
  //declara ponteiro para os arquivos
  fstream output_txt;
  //abre o arquivo
  output_txt.open(path, ios::out | ios::trunc);

  //verifica se o arquivo está aberto
  if (!output_txt.is_open()) {
    cout << "\nErro ao abrir arquivo!\n";
    exit(1);
  } else {
    //escreve os dados no arquivo
    writeReg(output_txt, text);
    output_txt.close();
  }
}

vector<string> getLines(fstream &input_txt) {
  string lineString;
  vector<string> lines;

  while (input_txt.good()) {
    getline(input_txt, lineString);
    lines.push_back(lineString);
  }
  return lines;
}

void writeReg(fstream &output_txt, string text) {
  output_txt << text;
}