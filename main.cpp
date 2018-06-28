#include <iostream>
#include <fstream>
#include <sstream>

#include <cstdlib>
#include <algorithm>
#include "Vocabulario.h"

string normalizarLinha(string linha){
    /*Deixa todos os caracteres em lowercase
     *Substitui simbolos nao pertecentes ao alfabeto por espacos
     *Remove espacos contiguos
    */
    std::transform(linha.begin(), linha.end(), linha.begin(), ::tolower);
    ostringstream streamTemp;
    int isWhiteSpace = 0;

    for (int i = 0; i< linha.length(); i++){
        char temp = linha[i];
        if(temp <97 || temp >122){
            linha[i] = ' ';
            if(isWhiteSpace == 0) {
                streamTemp << linha[i];
            }
            isWhiteSpace = 1;
        }
        else {
            streamTemp << linha[i];
            isWhiteSpace = 0;
        }
    }
    return streamTemp.str();
}

void classificarComentario(Vocabulario vocab){
    string message = " ";

    while(message.length() > 0)
    {
        cout << "Escreva uma avaliacao (precione ESC para sair):"<<endl;
        getline(cin,message);
        message = normalizarLinha(message);
        //used for calculating the average
        double sum = 0;
        int count = 0;

        int len = message.size();
        //get each individual word from the input
        while(len != std::string::npos)
        {
            string sub;
            len = message.find(" ");
            if (len != string::npos)
            {
                sub = message.substr(0,len);
                message = message.substr(len+1,message.size());
            }
            else {
                sub = message;
            }
            sum += vocab.scoreMedio(sub);
            count++;
        }

        if (message.size() > 0)
        {
            double media = sum / count;
            cout << "O comentario tem um escore medio de " << media <<endl;
            if(media < 2)
                cout << "Sentimento negativo" << endl;
            else
                cout << "Sentimento positivo" << endl;
        }
    }
}

void alimentaVocabulario(Vocabulario vocab, ifstream *myfile ){
    string linha;
    int score;

    while (*myfile >> score &&  myfile->get() && getline(*myfile,linha))
    {
        linha = normalizarLinha(linha);

        int len = linha.size();

        while(len > 0) {
            string sub;
            len = linha.find(" ");
            if (len > 0)
            {
                sub = linha.substr(0,len);
                linha = linha.substr(len+1,linha.size());
                vocab.adicionar(sub, score);
            }
            else {
                sub = linha.substr(0,linha.size()-1);
            }
        }
    }
}

void alimentaVocabularioKaggle(Vocabulario vocab, ifstream *myfile ){
    string linha, nota, temp;
    int score, len;
    getline(*myfile, linha); // linha sem dados significativos

    while (getline(*myfile,linha))
    {

        len = linha.find(9);
        linha = linha.substr(len+1, linha.size());
        len = linha.find(9);
        linha = linha.substr(len+1, linha.size());
        len = linha.find(9);

        //pega ultima parte da linha onde fica a nota
        nota = linha.substr(len+1, linha.size());
        score = nota[0] - 48;
        //pega o comentario e normaliza
        linha = normalizarLinha(linha.substr(0,len));

        int len = linha.size();

        while(len > 0) {
            string sub;
            len = linha.find(" ");
            if (len > 0)
            {
                sub = linha.substr(0,len);
                linha = linha.substr(len+1,linha.size());
                vocab.adicionar(sub, score);
            }
            else {
                sub = linha.substr(0,linha.size()-1);
            }
        }
    }
}



int main() {

    int escolha = 1; //0 arquivo exemplo, 1 arquivo de treinamento do kaggle
    ifstream arquivo;

    Vocabulario vocab;

    if(escolha){
        arquivo.open("data/train.tsv");
        if (arquivo.fail() )
        {
            cout << "Nao foi possivel abrir o arquivo" <<endl;
            exit(0);
        }
        alimentaVocabularioKaggle(vocab, &arquivo);
    }
    else {
        arquivo.open("data/movieReviews.txt");
        if (arquivo.fail() )
        {
            cout << "Nao foi possivel abrir o arquivo" <<endl;
            exit(0);
        }
        alimentaVocabulario(vocab, &arquivo);
    }

    list<string> lista = vocab.buscaPalavrasPrefixo("a");
    std::list<string>::const_iterator iterator;
    for (iterator = lista.begin(); iterator != lista.end(); ++iterator) {
        cout << *iterator << " ";
    }
    classificarComentario(vocab);

    return 0;
  }