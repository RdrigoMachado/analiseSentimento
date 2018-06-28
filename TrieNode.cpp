#include "TrieNode.h"


TrieNode::TrieNode(){
    TrieNode::palavra = NULL;
    endOfWord = false;
    for(int i = 0; i < alfabeto; i++)
        filhos[i] = NULL;
}
