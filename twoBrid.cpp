#include "twoBrid.h"

void twoBri(double &custo, vector<int> &rota, const vector<vector<double >> &distance,int const &dimensao){

   cout << "\nAplicando two brid..." << endl;

    vector <int> fim;
    set<int> numerosIni;

    srand(1);

    while (numerosIni.size() != 8) {
        int num = 1+(rand() % dimensao-1);

        numerosIni.insert(num);
        numerosIni.insert(num+1);

    }
    vector <int> numeros;

    for (int i : numerosIni){
        numeros.push_back(i);
     }

    for (int i = 0; i < numeros.size();i++){

        if ( i%2 == 1 ){
        continue;
      }
        fim.push_back(numeros[i]);
    }

     sort(fim.begin(), fim.end());


////////////////////////////////////////////////////////////
    vector <int> posiInicial;
    vector <int> posiFinal;

    for (int i = 0; i < fim.at(0); i++){

        posiInicial.push_back (rota[i]);

    }

    for (int i = 1; i < posiFinal.size(); i++){

        rota.push_back (posiFinal[i]);

    }

////////////////////////////////////////////////////////////////////////
   /* cout << "inicio de i: " << rota[0] << endl;
    cout << "fim de i: " << rota[fim[0]] << endl;
    cout << endl;
    cout << "inicio de j: " << rota[fim[0]+1] << endl;
    cout << "fim de j: " << rota[fim[1]] << endl;
    cout << endl;
    cout << "inicio de k: " << rota[fim[1]+1] << endl;
    cout << "fim de k: " << rota[fim[2]] << endl;
    cout << endl;
    cout << "inicio de l: " << rota[fim[2]+1] << endl;
    cout << "fim de l: " << rota[fim[3]] << endl;
    cout << endl;
    cout << "inicio de i: " << rota[fim[3]+1] << endl;
    cout << "fim de i: " << rota[rota.size()-1] << endl;*/

    cout << "\no l esta entre " << rota[fim[0]] << " e " << rota[fim[1]+1] << endl;
    cout << "\no j esta entre " << rota[fim[2]]<< " e " << rota[fim[3]+1]<< endl;

    vector <int> rotaAux;

    rotaAux.swap(rota);

    rota.clear();

    rota.insert(rota.begin(),rotaAux.begin(), rotaAux.begin() + fim[0]+1);//i
    rota.insert(rota.begin() + rota.size(), rotaAux.begin() + fim[2]+1, rotaAux.begin() + fim[3]+1);//l
    rota.insert(rota.begin() + rota.size(), rotaAux.begin() + fim[1]+1, rotaAux.begin() + fim[2]+1);//k
    rota.insert(rota.begin() + rota.size(), rotaAux.begin() + fim[0]+1, rotaAux.begin() + fim[1]+1);//j

        if (fim[3] != rotaAux.size()-1){
            rota.insert(rota.begin() + rota.size(), rotaAux.begin() + rota.size(), rotaAux.begin () + rotaAux.size()-1);//l
        }

    rota.push_back (rota[0]);

    custo = 0;

     for (int i = 0; i < rota.size() - 1; i++) {
        custo = distance[rota[i]][rota[i + 1]] + custo;
    }

    cout << "\n\n\n";
    for (vector<int>::iterator it = rota.begin(); it != rota.end(); it++) {
        cout << *it << "\t";

    }
    cout << "\n novo custo:" << custo << endl;


}
