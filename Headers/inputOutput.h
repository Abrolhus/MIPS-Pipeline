#ifndef E7978F44_483A_40A3_9307_75393D3E6041
#define E7978F44_483A_40A3_9307_75393D3E6041

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

//Inicia o arquivo entrada
vector<string> inputFile(string path);

//Inicia o arquivo saida
void OutputFile(string path, string text);

// Faz a leitura do conteudo do arquivo
vector<string> getLines(fstream &input_txt);

// Faz a escrita no arquivo
void writeReg(fstream &output_txt, string text);

#endif /* E7978F44_483A_40A3_9307_75393D3E6041 */
