#include <iostream>
#include <fstream>

using namespace std;

#include "exportarRota.h"

void exportarRota (vector <int> &rota){

    ofstream myFile("rota.txt");
    for (int i:rota){
        myFile << i << "\t";
    }
    myFile.close();
}
