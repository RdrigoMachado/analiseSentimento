#ifndef ANALISESENTIMENTO_VOCABULARIO_H
#define ANALISESENTIMENTO_VOCABULARIO_H

#include "TrieNode.h"
#include "Palavra.h"
#include <string>

using namespace std;

class Vocabulario {

    public:
        TrieNode *raiz;
        void adicionar(string palavra, int nota);
        bool procurar(string palavra);
        TrieNode* devolvePalavra(string palavra);
        double scoreMedio(string palavra);
        Vocabulario();

};


#endif //ANALISESENTIMENTO_VOCABULARIO_H
