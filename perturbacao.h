#ifndef PERTURBACAO_H_INCLUDED
#define PERTURBACAO_H_INCLUDED
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

void disturbance(double &custo, vector<int> &rota, const vector<vector<double >> &distance,int const &dimensao);

#endif // PERTURBACAO_H_INCLUDED
