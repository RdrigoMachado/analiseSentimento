#ifndef ANALISESENTIMENTO_PALAVRA_H
#define ANALISESENTIMENTO_PALAVRA_H

#include <string>
using namespace std;
class Palavra {
    public:
        string nome;
        int aparicoes;
        double score;
        Palavra(string nome, int nota);
        void atualizar(int nota);
};


#endif //ANALISESENTIMENTO_PALAVRA_H
