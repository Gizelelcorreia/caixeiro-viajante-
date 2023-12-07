
#include "LeitorInstancia.h"

void lerDados(string nomeDaInstancia, vector<vector<double >> &distance, vector<Localidade> &localidades){

    ifstream arquivoPCV(nomeDaInstancia, ios::in);//lendo arquivo
    if (arquivoPCV) {
        cout << "arquivo lido com sucesso" << endl;
    } else {
        cout << "falha na leitura do arquivo" << endl;
        exit(1); //encerra o programa
    }

    string text;
    string nomeInstancia;
    int dimensao;

    arquivoPCV >> text; // chamada sequencial o primeiro valor foi armazenado
    arquivoPCV >> nomeInstancia;
    arquivoPCV >> text;

    while (text != "DIMENSION:") {
        arquivoPCV >> text;//armazenando os valores antes de dimension
    }

    arquivoPCV >> dimensao;//armazena a dimension
    while (text != "NODE_COORD_SECTION") {// armazenando as coordenadas
        arquivoPCV >> text;
    }

    for (int i = 0; i < dimensao; i++) {
        Localidade loc{}; // chamou a struct
        arquivoPCV >> loc.indice >> loc.x >> loc.y;// armazena os valores
        localidades.push_back(loc);// armazena para o valor n se perder
    }

    distance.resize(dimensao);//dimensao 52
    for (int i = 0; i < localidades.size(); i++) {
        distance[i].resize(dimensao);
    }

    for (int i = 0; i < localidades.size(); i++) {
        for (int j = 0; j < localidades.size(); j++) {
            if (i == j) {
                distance[i][j] = 999999999999999;
            } else {
                distance[i][j] = calcularDistancia(localidades[i], localidades[j]);
            }
        }
    }
}

