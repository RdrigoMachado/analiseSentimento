#ifndef ANALISESENTIMENTO_PALAVRA_H
#define ANALISESENTIMENTO_PALAVRA_H

#include <string>
#include <list>


using namespace std;
struct meta_dados{
    int palavra;
    int comentario;
    int score;
};

class Palavra {
    public:
        string nome;
        int aparicoes;
        double score;
        list<meta_dados> dadosAparicoes;
        Palavra(string nome, int nota);
        void atualizar(int nota);
        double scoreMedio(void);
        void incluiMetaDado(meta_dados *metadados);
};


#endif //ANALISESENTIMENTO_PALAVRA_H
