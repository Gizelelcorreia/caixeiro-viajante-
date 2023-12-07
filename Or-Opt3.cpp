#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

#include "Or-Opt3.h"

 void moverTresBlocos(double &custo, vector<int> &rota, const vector<vector<double >> &distance){

    cout << endl;
    cout << "\naplicando o Or-Opt3..." << endl;


    bool refinamento = true;

    while (refinamento) {


        double custoDis = 0;
        double melhorC = 99999;
        int segBloco = 0;
        int priBloco = 0;
        int terBloco = 0;
        int posMelhor;

        for (int k = 1; k < rota.size() - 3; k++) {//candidato

            for (int l = 1; l < rota.size() - 1; l++) {//posicao

                if (l != k && l != k + 1 && l != k + 2) {

                    custoDis = custo - distance[rota[l - 1]][rota[l]] - distance[rota[k - 1]][rota[k]]
                                     - distance[rota[k + 2]][rota[k + 3]] + distance[rota[l - 1]][rota[k]]
                                     + distance[rota[k + 2]][rota[l]] + distance[rota[k - 1]][rota[k+3]];


                    if (custoDis < melhorC) {
                        melhorC = custoDis;
                        priBloco = k;
                        segBloco = k + 1;
                        terBloco = k + 2;
                        posMelhor = l;
                    }
                } else {
                    break;
                }

            }
        }
        if (melhorC < custo) {

            refinamento = true;
            custo = melhorC;
            melhorC = 0;

            cout << "\n\nnovo custo: " << custo << endl;
            cout << "Or-Opt3 de: |" << rota[priBloco] << "|" << rota[segBloco] << "|" << rota[terBloco] << "|" << endl;
            cout << "entre o " << rota[posMelhor - 1] << " e o " << rota[posMelhor] << endl << endl;

            rota.insert(rota.begin() + posMelhor, rota[priBloco]);
            rota.insert(rota.begin() + posMelhor + 1, rota[priBloco + 2]);
            rota.insert(rota.begin() + posMelhor + 2, rota[priBloco + 4]);

            if (posMelhor > priBloco) {
                rota.erase(rota.begin() + priBloco);
                rota.erase(rota.begin() + priBloco);
                rota.erase(rota.begin() + priBloco);
            } else {
                rota.erase(rota.begin() + priBloco + 3);
                rota.erase(rota.begin() + priBloco + 3);
                rota.erase(rota.begin() + priBloco + 3);
            }

            for (vector<int>::iterator it = rota.begin(); it != rota.end(); it++) {
                cout << *it << "\t";
            }

        } else {
            refinamento = false;

        }
    }

 }
