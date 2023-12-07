#include <iostream>
#include <fstream>
#include <cstdlib>// exit();
#include <string>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

#include "vizinhanca.h"

void vizinhoMaisProximo(const vector<vector<double >> &distance,int const &dimensao,double &custo, vector<int> &rota){

  //heuristica do vizinho mais proximo
   std::list <int> naoVisitadas;


     int origem = 0;

     for (int i = 0; i < dimensao; i++ ){

        naoVisitadas.push_back(i);

     }

        naoVisitadas.remove(origem);

        // vector <int> rota;
        rota.push_back (origem);
       // double custo = 0;

    while (!naoVisitadas.empty()){


        int candidata;
        double minDistancia;
        int escolhida;
        int ultima = rota.back ();
            minDistancia = 99999999999;
        escolhida = -1;


        for (list <int>::iterator it = naoVisitadas.begin(); it != naoVisitadas.end(); it++ ){

        candidata = *it;


        if (  distance [ultima][candidata] < minDistancia  ){

                escolhida = candidata;
                minDistancia =  distance [ultima][candidata];

        }


        }
        custo = minDistancia + custo;

        naoVisitadas.remove (escolhida);
        rota.push_back (escolhida);

    }
            rota.push_back(origem);

        cout << "a distancia percorrida foi: " << custo << endl;

        cout << "com origem em:" << origem << endl;

   for (vector <int>::iterator it = rota.begin(); it != rota.end(); it++ ){

            cout << *it << "\t";
   }

}
