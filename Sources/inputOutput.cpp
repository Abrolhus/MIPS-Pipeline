#include "inputOutput.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <string>

#define MAX_STR_MEM 128

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
vector<string> inputFile(string path)
{
  fstream input_txt;
  input_txt.open(path, ios::in); //abre o arquivo

  //verifica se o arquivo está aberto
  if (!input_txt.is_open())
  {
    cout << "\nErro ao abrir arquivo!\n";
    exit(1);
  }
  else
  {
    //Le os dados do arquivo
    vector<string> lines = getLines(input_txt);
    cout << "\nLeitura realizada com sucesso!\n";
    input_txt.close();
    return lines;
  }
}

/**
 * @brief abre o arquivo e limpa o conteudo
 * 
 * @param path 
 */
void OutputClear(string path)
{
  //declara ponteiro para os arquivos
  fstream output_txt;
  //abre o arquivo e limpa o conteudo
  output_txt.open(path, ios::out | ios::trunc);
  output_txt.close();
}

/**
 * @brief 
 * 
 * @param path 
 * @param text 
 */
void OutputFile(string path, string text)
{
  //declara ponteiro para os arquivos
  fstream output_txt;
  //abre o arquivo
  output_txt.open(path, ios::out | ios::app);

  //verifica se o arquivo está aberto
  if (!output_txt.is_open())
  {
    cout << "\nErro ao abrir arquivo!\n";
    exit(1);
  }
  else
  {
    //escreve os dados no arquivo
    output_txt << text << endl;
    output_txt.close();
  }
}

/**
 * @brief Get the Lines object
 * 
 * @param input_txt 
 * @return vector<string> 
 */
vector<string> getLines(fstream &input_txt)
{
  string lineString;
  vector<string> lines;

  while (input_txt.good())
  {
    getline(input_txt, lineString);
    lines.push_back(lineString);
  }
  return lines;
}

/**
 * @brief Copia os dados do arquivo txt para memória de instrução.
 * 
 */
int memorInstrucInput(int *memInst, int j)
{

  string fileIn = "input.txt";
  vector<string> lines = inputFile(fileIn);

  for (size_t i = 0; i < lines.size(); i++)
  {
    memInst[i] = stol(lines[i], nullptr, 2);
  }

  //copia os dados da memória de instrução para o arqquivo (temporário)
  string fileOut = "output.txt";
  OutputClear(fileOut);
  for (size_t i = 0; i < 11; i++)
    OutputFile(fileOut, to_string(memInst[i]));
  return memInst[j];

  //delete[] mem_Instrucao;
}