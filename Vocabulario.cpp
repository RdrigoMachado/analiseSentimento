#include "Vocabulario.h"

Vocabulario::Vocabulario() {
    raiz = new TrieNode();
}

void Vocabulario::adicionar(string palavra, int nota, meta_dados dados){
    TrieNode *auxiliar = Vocabulario::raiz;
    for(int i= 0; i < palavra.length(); i++){
        int index = palavra[i] - 'a';
        if(auxiliar->filhos[index] == NULL){
            auxiliar->filhos[index] = new TrieNode();
        }
        auxiliar = auxiliar->filhos[index];
    }
    if(auxiliar->palavra == NULL) {
        auxiliar->endOfWord = true;
        auxiliar->palavra = new Palavra(palavra, nota);
        auxiliar->palavra->incluiMetaDado(&dados);
    }
    else{
       auxiliar->palavra->atualizar(nota);
        auxiliar->palavra->incluiMetaDado(&dados);
    }
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

list<string> retornaPalavrasSubArvores(TrieNode *auxiliar){
    list<string> palavras = {};
    for(int i =0; i < alfabeto; i++) {
        if (auxiliar->filhos[i] != NULL) {
            if (auxiliar->filhos[i]->endOfWord) {
                palavras.push_back(auxiliar->filhos[i]->palavra->nome);
            }
            palavras.merge(retornaPalavrasSubArvores(auxiliar->filhos[i]));
        }
    }
    return palavras;
}

list<string> Vocabulario::buscaPalavrasPrefixo(string prefixo) {
    TrieNode *auxiliar = Vocabulario::raiz;
    list<string> palavras = {};

    for (int i = 0; i < prefixo.length(); i++) {
        int index = prefixo[i] - 'a';
        if (auxiliar->filhos[index] == NULL)
            return palavras;
        else
            auxiliar = auxiliar->filhos[index];
    }

    if (auxiliar == NULL)
        return palavras;
    else{
        if (auxiliar->endOfWord) {
            palavras.push_back(auxiliar->palavra->nome);
        }
        palavras.merge(retornaPalavrasSubArvores(auxiliar));
    }
}

list<meta_dados> Vocabulario::devolvePalavraMetaDado(string palavra){
        TrieNode *auxiliar = Vocabulario::raiz;
        list<meta_dados> foo;
        for(int i = 0; i < palavra.length(); i++){
            int index = palavra[i] - 'a';
            if(auxiliar->filhos[index] == NULL)
                return foo;
            else
                auxiliar = auxiliar->filhos[index];
        }
        if(auxiliar!= NULL && auxiliar->endOfWord)
            return auxiliar->palavra->dadosAparicoes;
        else{

            return foo;
        }
}

double Vocabulario::scoreMedio(string palavra){
    TrieNode *auxiliar = Vocabulario::raiz;
    for(int i = 0; i < palavra.length(); i++){
        int index = palavra[i] - 'a';
        if(auxiliar->filhos[index] == NULL){
             return 2;
        }
        else
            auxiliar = auxiliar->filhos[index];
    }

    if(auxiliar!= NULL && auxiliar->endOfWord)
        return auxiliar->palavra->scoreMedio();
    else {
        return 2;
    }
}