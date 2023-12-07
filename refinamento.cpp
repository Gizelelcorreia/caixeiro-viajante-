#include <random>
#include <algorithm>

using namespace std;

#include "refinamento.h"
#include "BuscaLocal.h"
#include "Or-Opt2.h"
#include "Or-Opt3.h"
#include "insert.h"
#include "2Opt.h"

void refinou(double &custo, vector<int> &rota, const vector<vector<double >> &distance){

    double MelhorCusto = custo;

    vector <int> vizinhancas = {1,2,3,4};

    shuffle(vizinhancas.begin(),vizinhancas.end(),std::default_random_engine(0));
    //int tipo = 1;
    vector <int> vizinhancasBackup = vizinhancas;

    int tipo = vizinhancas.back();

    vizinhancas.pop_back();

    do{

    switch (tipo){

        case 1:
        cout << "\nexecutando troca" << endl;
            troca(custo,rota,distance);
            break;
        case 2:
            cout << "executando mover dois blocos" << endl;
            moverDoisBlocos(custo,rota,distance);
            break;
        case 3:
            cout << "executando mover tres blocos" << endl;
            moverTresBlocos(custo,rota,distance);
            break;
        case 4:
            cout << "executando insert" << endl;
            inserir (custo, rota, distance);
            break;
        case 5:
            cout << "executando Or-Opt2" << endl;
            doisOpt (custo, rota, distance);
            break;
        default:
            cout << "valor selecionado invalido" << endl;
      }
     if (custo < MelhorCusto){
        cout << "\ncusto melhorou" << endl;
        cout << "custo antigo:" << MelhorCusto << "\ncusto novo:" << custo << endl;
        cout << "tipo:" << tipo << endl;

        MelhorCusto = custo;
        vizinhancas = vizinhancasBackup;
       // tipo = 1;
     }else{
        //tipo++;
        tipo = vizinhancas.back ();
        vizinhancas.pop_back();
        cout << "tipo:" << tipo << endl;

     }
     //}while (tipo != 4);
     }while (!vizinhancas.empty());
        cout << "\nfinalizado" << endl;


}
