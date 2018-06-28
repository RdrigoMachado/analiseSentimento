#ifndef ANALISESENTIMENTO_VOCABULARIO_H
#define ANALISESENTIMENTO_VOCABULARIO_H

#include "TrieNode.h"
#include "Palavra.h"
#include <string>
#include <list>
#include <iostream>


using namespace std;

class Vocabulario {

    public:
        TrieNode *raiz;
        void adicionar(string palavra, int nota, meta_dados dados);
        bool procurar(string palavra);
        list<meta_dados> devolvePalavraMetaDado(string palavra);
        double scoreMedio(string palavra);
        Vocabulario();
        list<string> buscaPalavrasPrefixo(string prefixo);
};


#endif //ANALISESENTIMENTO_VOCABULARIO_H
