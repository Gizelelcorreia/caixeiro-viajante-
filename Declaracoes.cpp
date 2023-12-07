#include <cmath>
#include "declaracoes.h"

double calcularDistancia(const Localidade &l1, const Localidade &l2) {
    double distance = sqrt(pow(l1.x - l2.x, 2) + pow(l1.y - l2.y, 2));
    distance = floor(distance + 0.5);
    return distance;
}

