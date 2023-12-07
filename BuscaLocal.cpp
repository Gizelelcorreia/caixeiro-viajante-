#include <iostream>
#include <vector>

using namespace std;

#include "BuscaLocal.h"

void troca(double &custo, vector<int> &rota, const vector<vector<double >> &distance){

    cout << "\nAplicando busca local..." << endl;
    bool melhorou = true;
        while (melhorou) {

            double novoCusto = 0;
            double mCusto = 99999999;
            int melhorL = -1;
            int melhorK = -1;

           for (int k = 1; k < rota.size() - 2; k ++){
                for (int l = k+1; l < rota.size() - 1; l++){
                    if (l != k+1){
                       novoCusto = custo - distance[rota[k-1]][rota[k]] - distance[rota[k]][rota[k+1]]
                                  - distance[rota[l-1]][rota[l]] - distance[rota[l]][rota[l+1]]
                                  + distance[rota[k-1]][rota[l]] + distance[rota[l]][rota[k+1]]
                                  + distance[rota[l-1]][rota[k]] + distance[rota[k]][rota[l+1]];

                        if (novoCusto < mCusto){
                            mCusto = novoCusto;
                            melhorL = l;
                            melhorK = k;
                        }
                    } else {
                       novoCusto = custo - distance[rota[k-1]][rota[k]]
                                  - distance[rota[l]][rota[l+1]]
                                  + distance[rota[k-1]][rota[l]]
                                  + distance[rota[k]][rota[l+1]];

                        if (novoCusto < mCusto){
                            mCusto = novoCusto;
                            melhorL = l;
                            melhorK = k;
                        }
                    }
                }
            }

        if (mCusto < custo) {
            melhorou = true;
            int vda = rota[melhorK];

            rota[melhorK] = rota[melhorL];
            rota [melhorL] = vda;
            custo = mCusto;

            cout << "\n\nnovo custo: " << custo << endl;
            cout << "troca feita entre:" << rota[melhorL]
                << " e " << rota[melhorK] << endl << endl;

            for (vector <int>::iterator it = rota.begin(); it != rota.end(); it++ ){
                cout << *it << "\t";
            }
        } else {
            melhorou = false;

        }
   }
    cout << endl;

}
