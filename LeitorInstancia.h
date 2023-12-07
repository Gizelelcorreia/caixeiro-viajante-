#ifndef LEITORINSTANCIA_H_INCLUDED
#define LEITORINSTANCIA_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Declaracoes.h"

void lerDados(string nomeInstancia, vector<vector<double >> &distance, vector<Localidade> &localidades);

#endif // LEITORINSTANCIA_H_INCLUDED
