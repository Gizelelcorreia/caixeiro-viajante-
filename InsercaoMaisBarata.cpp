#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <list>
#include <set>

using namespace std;

#include "InsercaoMaisBarata.h"

void InsercaoMaisBarata(const vector<vector<double >> &distance,int const &dimensao,double &custo, vector<int> &rota){

  std::list<int> naoVisitadas;
    for (int i = 0; i < dimensao; i++) {
        naoVisitadas.push_back(i);
    }

    set<int> numeros;
    srand(0);
    //srand(time(NULL));
  /*  numeros.insert(1);
    numeros.insert(8);
    numeros.insert(51);
*/
    while (numeros.size() != 3) {
        int num = rand() % dimensao;
        numeros.insert(num);
    }

    //vector<int> rota;
    for (set<int>::iterator it = numeros.begin(); it != numeros.end(); it++) {
        rota.push_back(*it);
        naoVisitadas.remove(*it);
    }
    rota.push_back(rota.front());

    //double custo = 0;
    for (int p = 0; p < rota.size() - 1; p++) {
        custo = distance[rota[p]][rota[p + 1]] + custo;
    }

    while (!naoVisitadas.empty()) {

        int melhorCandidato = -1;
        int pos = -1;
        double menorCusto = 9999999;

        for (int k: naoVisitadas) {

            for (int p = 0; p < rota.size() - 1; p++) {

                int i = rota[p];
                int j = rota[p + 1];

                double delta = distance[i][k] + distance[k][j] - distance[i][j];

                if (delta < menorCusto) {
                    menorCusto = delta;
                    melhorCandidato = k;
                    pos = p + 1;
                }
            }
        }

        rota.insert(rota.begin() + pos, melhorCandidato);
        naoVisitadas.remove(melhorCandidato);
        custo = menorCusto + custo;
    }

    cout << "melhor custo: " << custo << endl << endl;
    for (vector<int>::iterator it = rota.begin(); it != rota.end(); it++) {
        cout << *it << "\t";
    }

}
