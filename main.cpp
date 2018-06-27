#include <iostream>
#include "Vocabulario.h"
int main() {

    string palavras[]= {"combination", "combi", "log", "logged"};
    Vocabulario vocab;

    vocab.adicionar(palavras[0], 1);
    vocab.adicionar(palavras[1], 2);
    vocab.adicionar(palavras[2], 4);
    vocab.adicionar(palavras[3], 4);


    /*Know if word is in vocabulary */
    /*
     * if(vocab.procurar("combi")){
        cout << "combi sucesso";
    }
    if(vocab.procurar("combination")){
        cout << "combination sucesso";
    }

    if(vocab.procurar("log")){
        cout << "log sucesso";
    }
    if(vocab.procurar("com")){
        cout << "com sucesso";
    }
    if(vocab.procurar("tra")){
        cout << "tra sucesso";
    }
     */

    /*Get word Back*/
    /*TrieNode *aux;
    Palavra *palavra;
    aux = vocab.devolvePalavra("combis");
    if(aux!= NULL){
        cout << "palavra devolvida";
        palavra = aux->palavra;
        cout << "Nota: " << palavra->score << "\nPalavra: " << palavra->nome;
    }
    else{
        cout << "Palavra nao existe";
    }
    */


    return 0;
    /* Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);

    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
    cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
    cout << "No\n";
    return 0;
    return 0;*/
}