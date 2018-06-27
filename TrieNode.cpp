//
// Created by Rodrigo Machado on 27/06/2018.
//

#include "TrieNode.h"


TrieNode::TrieNode(){
    TrieNode::palavra = NULL;
    endOfWord = false;
    for(int i = 0; i < alfabeto; i++)
        filhos[i] = NULL;
}
