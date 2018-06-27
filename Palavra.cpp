#include "Palavra.h"

    //construtor da classe palavra
    Palavra::Palavra(string nome, int nota) {
        Palavra::nome = nome;
        aparicoes = 1;
        score = double(nota);
    }


    void Palavra::atualizar(int nota) {
        /*objetivo: atualizar o score fazendo a media entre
         o valor anterior e a nova nota*/
        aparicoes++;
        score = (score + double(nota)) / 2;
    }

