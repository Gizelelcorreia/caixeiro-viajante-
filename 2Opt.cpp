#include "2Opt.h"

 void doisOpt (double &custo, vector<int> &rota, const vector<vector<double >> &distance){

   cout << endl;
   cout << "\naplicando o 2_Opt..." << endl;

    bool melhor = true;


    while (melhor) {


        double custoDist = 0;
        double melhorCust = 999999;
        int primeiraPos = -1;
        int ultimaPos = -1;

        for (int i = 1; i < rota.size() - 2; i++) {//primeiro

            for (int j = i + 1; j < rota.size() - 1; j++) {//ultimo


                    custoDist = custo - distance[rota[i - 1]][rota[i]] - distance[rota[j]][rota[j + 1]]
                                + distance[rota[i - 1]][rota[j]] + distance[rota[i]][rota[j+1]];

                    if (custoDist < melhorCust) {
                        melhorCust = custoDist;
                        primeiraPos = i;
                        ultimaPos = j;

                }
            }
        }


        if (melhorCust < custo) {

            melhor = true;
            custo = melhorCust;

            cout << "\n\nnovo custo: " << custo << endl;

            cout << "primeira posicao: " << rota[primeiraPos] <<"\t colocacao: " << primeiraPos << endl;
            cout << "ultima posicao: " << rota[ultimaPos] <<"\t colocacao: " << ultimaPos << endl;

            reverse (rota.begin() + primeiraPos, rota.begin() + ultimaPos + 1);

           for (vector<int>::iterator it = rota.begin(); it != rota.end(); it++) {
                cout << *it << "\t";
            }

                 } else {
                            melhor = false;

                        }
                    }

                 }

