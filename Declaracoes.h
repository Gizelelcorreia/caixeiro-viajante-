#ifndef DECLARACOES_H_INCLUDED
#define DECLARACOES_H_INCLUDED

struct Localidade {
    int indice;
    double x;
    double y;
};


double calcularDistancia(const Localidade &l1, const Localidade &l2);


#endif // DECLARACOES_H_INCLUDED
