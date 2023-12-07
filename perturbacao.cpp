#include "perturbacao.h"

void disturbance(double &custo, vector<int> &rota, const vector<vector<double >> &distance, int const &dimensao){

     cout << "\n\nperturbacao" << endl;


      int pertub = 0;
      srand(0);
      int posUm,posDois;

     while (pertub < 4) {
         posUm = rand() % dimensao;
         posDois = rand() % dimensao;

        if (posUm == posDois){
            continue;
        }

        pertub++;
    }
       if (posDois != posUm + 1){
            custo = custo - distance[rota[posUm -1]][rota[posUm]] - distance[rota[posUm]][rota[posUm+1]]
                      - distance[rota[posDois-1]][rota[posDois]] - distance[rota[posDois]][rota[posDois+1]]
                      + distance[rota[posUm-1]][rota[posDois]] + distance[rota[posDois]][rota[posUm+1]]
                      + distance[rota[posDois-1]][rota[posUm]] + distance[rota[posUm]][rota[posDois+1]];

              }else {
                   custo = custo - distance[rota[posUm-1]][rota[posUm]]
                              - distance[rota[posDois]][rota[posDois+1]]
                              + distance[rota[posUm-1]][rota[posDois]]
                              + distance[rota[posUm]][rota[posDois+1]];
              }
    int vda = rota[posUm];

    rota[posUm] = rota[posDois];
    rota [posDois] = vda;

    cout << "\nnovo custo:" << custo << endl;

     for (vector<int>::iterator it = rota.begin(); it != rota.end(); it++) {
            cout << *it << "\t";

     }
}
