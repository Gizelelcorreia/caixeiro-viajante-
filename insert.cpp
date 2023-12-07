#include <iostream>
#include <vector>

using namespace std;

#include "insert.h"

void inserir(double &custo, vector<int> &rota, const vector<vector<double >> &distance){

    cout << endl;
    cout << "aplicando insert..." << endl;

    bool melhoro = true;
     while (melhoro) {

         double custoDistance = 0;
         double melhorCusto = 99999999;
         int melhorEscolha = 0;
         int melhorPos = 0;
         int posK = 0;

         for (int k = 1; k < rota.size()-1; k ++){//candidato
             int rk = rota[k];
             for (int l = 1; l < rota.size()-1; l++){//posi��o
                 int rl = rota[l];
                 if (k!=l && l!= k+1){

                    custoDistance = custo - distance[rota[k-1]][rk] - distance[rk][rota[k+1]]
                                     - distance[rota[l-1]][rl] + distance[rota[l-1]][rk]
                                     + distance[rk][rl] + distance[rota[k-1]][rota[k+1]];

                     if (custoDistance < melhorCusto){
                         melhorCusto = custoDistance;
                         melhorEscolha = rk;
                         melhorPos = l;
                         posK = k;
                     }
                 }
             }
         }

         if (melhorCusto < custo) {

             melhoro = true;
             custo = melhorCusto;


             cout << "\n\nnovo custo: " << custo << endl;
             cout << "insert: " << rota[posK] << endl;
             cout << "entre o " << rota[melhorPos-1] << " e o " << rota[melhorPos] << endl << endl;


             rota.insert (rota.begin() + melhorPos, rota[posK]);

             if (melhorPos > posK ){
                 rota.erase(rota.begin() + posK);
             }else {
                 rota.erase(rota.begin() + posK+1);

             }

             for (vector <int>::iterator it = rota.begin(); it != rota.end(); it++ ){
                 cout << *it << "\t";
             }
         } else {
             melhoro = false;

         }
     }
}
