#include "Palavra.h"

    //construtor da classe palavra
    Palavra::Palavra(string nome, int nota) {
        Palavra::nome = nome;
        aparicoes = 1;
        score = double(nota);
    }


    void Palavra::atualizar(int nota) {
        /*Incrementa o numero de aparicoes em um e
         * soma a nova nota ao score total
         * */
        aparicoes++;
        score += nota;
    }

    double Palavra::scoreMedio(void) {
        /*Retorma o score medio
         * */

        return double(score)/aparicoes;
    }
