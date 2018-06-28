#ifndef ANALISESENTIMENTO_TRIENODE_H
#define ANALISESENTIMENTO_TRIENODE_H
#include "Palavra.h"

const int alfabeto = 26;
const int alfabetoCaseSensitive = 52;

class TrieNode {

public:
    TrieNode *filhos[alfabeto];
    bool endOfWord;
    Palavra *palavra;
    TrieNode();
};


#endif //ANALISESENTIMENTO_TRIENODE_H
