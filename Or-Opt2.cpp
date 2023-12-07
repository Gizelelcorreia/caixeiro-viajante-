#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

#include "Or-Opt2.h"

 void moverDoisBlocos (double &custo, vector<int> &rota, const vector<vector<double >> &distance){

   cout << endl;
   cout << "\naplicando o Or-Opt2..." << endl;

    bool melhor = true;
    while (melhor) {

        double custoDist = 0;
        double melhorCust = 999999;
        int segundoBloco = 0;
        int primeiroBloco = 0;
        int melhorPos;

        for (int k = 1; k < rota.size() - 2; k++) {//candidato

            for (int l = 1; l < rota.size() - 1; l++) {//posi��o

                if (k != l) {

                    custoDist = custo - distance[rota[k - 1]][rota[k]] - distance[rota[k + 1]][rota[k + 2]]
                                - distance[rota[l - 1]][rota[l]] + distance[rota[k - 1]][rota[k + 2]]
                                + distance[rota[l - 1]][rota[k]] + distance[rota[k + 1]][rota[l]];


                    if (custoDist < melhorCust) {
                        melhorCust = custoDist;
                        primeiroBloco = k;
                        segundoBloco = k + 1;
                        melhorPos = l;

                    }
                } else {
                    break;
                }

            }
        }

        if (melhorCust < custo) {

            melhor = true;
            custo = melhorCust;

            cout << "\n\nnovo custo: " << custo << endl;
            cout << "Or-Opt2 de: " << rota[primeiroBloco] << " e " << rota[segundoBloco] << endl;
            cout << "entre o " << rota[melhorPos - 1] << " e o " << rota[melhorPos] << endl << endl;

            rota.insert(rota.begin() + melhorPos, rota[primeiroBloco]);
            rota.insert(rota.begin() + melhorPos + 1, rota[primeiroBloco + 2]);

            if (melhorPos > primeiroBloco) {
                rota.erase(rota.begin() + primeiroBloco);
                rota.erase(rota.begin() + primeiroBloco);
            } else {
                rota.erase(rota.begin() + primeiroBloco + 2);
                rota.erase(rota.begin() + primeiroBloco + 2);
            }

            for (vector<int>::iterator it = rota.begin(); it != rota.end(); it++) {
                cout << *it << "\t";
            }

        } else {
            melhor = false;

        }
    }
 }
