//
// Created by Rodrigo Machado on 27/06/2018.
//

#ifndef ANALISESENTIMENTO_TRIENODE_H
#define ANALISESENTIMENTO_TRIENODE_H
#include "Palavra.h"

const int alfabeto = 26;

class TrieNode {

public:
    TrieNode *filhos[alfabeto];
    bool endOfWord;
    Palavra *palavra;
    TrieNode();
};


#endif //ANALISESENTIMENTO_TRIENODE_H
