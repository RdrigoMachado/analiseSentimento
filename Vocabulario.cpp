#include "Vocabulario.h"
#include <iostream>

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
    if(auxiliar->palavra == NULL) {
        //cout << "adicionando " << palavra << "\n";
        auxiliar->endOfWord = true;
        auxiliar->palavra = new Palavra(palavra, nota);
    }
    else{
        //cout << "atualizando " << palavra << "\n";
        auxiliar->palavra->atualizar(nota);
        //cout << "nota atual: " << auxiliar->palavra->scoreMedio() << "\n";
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

double Vocabulario::scoreMedio(string palavra){
    TrieNode *auxiliar = Vocabulario::raiz;
    for(int i = 0; i < palavra.length(); i++){
        int index = palavra[i] - 'a';
        if(auxiliar->filhos[index] == NULL){
            cout << "Palavra: " << palavra << ", nao existe no vocabulario." << endl;
            cout << "Retornando valor central da distribuicao de notas: 2" << endl;
            return 2;
        }
        else
            auxiliar = auxiliar->filhos[index];
    }

    if(auxiliar!= NULL)
        return auxiliar->palavra->scoreMedio();
    else {
        cout << "Palavra: " << palavra << ", nao existe no vocabulario." << endl;
        cout << "Retornando valor central da distribuicao de notas: 2" << endl;
        return 2;
    }
}