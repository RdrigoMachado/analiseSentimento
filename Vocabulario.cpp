//
// Created by Rodrigo Machado on 27/06/2018.
//

#include "Vocabulario.h"

Vocabulario::Vocabulario() {
    raiz = new TrieNode();
}

void Vocabulario::adicionar(string palavra, int nota){
    TrieNode *auxiliar = Vocabulario::raiz;
    for(int i= 0; i < palavra.length(); i++){
        int index = palavra[i] - 'a';
        if(auxiliar->filhos[index] == NULL){
            auxiliar->filhos[index] = new TrieNode();
        }
        auxiliar = auxiliar->filhos[index];
    }
    auxiliar->endOfWord = true;
    auxiliar->palavra = new Palavra(palavra, nota);
}


bool Vocabulario::procurar(string palavra){
        TrieNode *auxiliar = Vocabulario::raiz;
        for(int i = 0; i < palavra.length(); i++){
            int index = palavra[i] - 'a';
            if(auxiliar->filhos[index] == NULL)
                return false;
            else
                auxiliar = auxiliar->filhos[index];
        }

        if(auxiliar!= NULL)
            return auxiliar->endOfWord;
        else
            return false;
}

TrieNode* Vocabulario::devolvePalavra(string palavra){
        TrieNode *auxiliar = Vocabulario::raiz;
        for(int i = 0; i < palavra.length(); i++){
            int index = palavra[i] - 'a';
            if(auxiliar->filhos[index] == NULL)
                return NULL;
            else
                auxiliar = auxiliar->filhos[index];
        }

        if(auxiliar!= NULL)
            return auxiliar;
        else
            return NULL;
}