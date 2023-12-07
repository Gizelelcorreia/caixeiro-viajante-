#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctime>
#include <list>
#include <set>

using namespace std;

#include "Declaracoes.h"
#include "LeitorInstancia.h"
#include "InsercaoMaisBarata.h"
#include "vizinhanca.h"
#include "exportarRota.h"
#include "refinamento.h"
#include "perturbacao.h"
#include "2Opt.h"
#include "twoBrid.h"

int main() {

    //string nomeInstancia = "berlin52.tsp";
    string nomeInstancia = "KroA100.tsp";
    vector<vector<double >> distance;
    vector<Localidade> localidades;
    lerDados(nomeInstancia,distance,localidades);
    vector<int> rota;
    double custo = 0;
    int dimensao = localidades.size();
    int tipo;

    tipo = 1;

    switch (tipo){

        case 1:
            cout << "executando insercao mais barata" << endl;
         InsercaoMaisBarata(distance,dimensao,custo,rota);
            break;
        case 2:
            cout << "excutando vizinho mais proximo" << endl;
            vizinhoMaisProximo(distance,dimensao,custo,rota);
            break;
        default:
            cout << "valor selecionado invalido" << endl;

    }

    cout << endl;



    int itSemMelhoras = 0;
    double melhorCusto = 0;


       cout << "\ndimensao:" << dimensao << endl;
       cout << "\ncusto:" << custo << endl;


    while (itSemMelhoras  < 5){

        refinou(custo,rota,distance);

        melhorCusto = custo;

        disturbance(melhorCusto,rota,distance,dimensao);
        twoBri(melhorCusto,rota,distance,dimensao);

        refinou(melhorCusto,rota,distance);


     if (melhorCusto < custo){

       custo = melhorCusto;
       itSemMelhoras = 0;

     }else{

         itSemMelhoras++;
     }
     }

     cout << "\npertubacao finalizada!\ncom custo: " << custo << endl;

     for (int i : rota){

        cout << i << "\t";
     }

    exportarRota (rota);

    return 0;
}

