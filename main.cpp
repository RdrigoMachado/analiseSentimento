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
        getline(cin, message);
        cout << "Escreva uma avaliacao (precione ESC para sair):"<<endl;
        getline(cin, message);
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
    int score, comentario = 0;
    meta_dados metadado;

    while (*myfile >> score &&  myfile->get() && getline(*myfile,linha))
    {
        comentario++;
        metadado.score = score;
        metadado.comentario = comentario;
        linha = normalizarLinha(linha);

        int len = linha.size();

        while(len > 0) {
            int palavra = 0;
            string sub;
            len = linha.find(" ");
            if (len > 0)
            {

                sub = linha.substr(0,len);
                linha = linha.substr(len+1,linha.size());
                palavra++;
                metadado.palavra = palavra;
                vocab.adicionar(sub, score, metadado);
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

    int comentario = 0;
    while (getline(*myfile,linha))
    {
        len = linha.find(9);
        comentario++;

        linha = linha.substr(len+1, linha.size());

        len = linha.find(9);
        linha = linha.substr(len+1, linha.size());
        len = linha.find(9);

        //pega ultima parte da linha onde fica a nota
        nota = linha.substr(len+1, linha.size());
        score = nota[0] - 48;
        //pega o comentario e normaliza
        linha = normalizarLinha(linha.substr(0,len));
        //cout << "comentario #" << comentario<< endl;
        meta_dados metadado;
        metadado.score = score;
        metadado.comentario = comentario;

        int len = linha.size();
        int palavra = 0;
        while(len > 0) {

            string sub;
            len = linha.find(" ");
            if (len > 0)
            {
                sub = linha.substr(0,len);
                linha = linha.substr(len+1,linha.size());
                palavra++;
                metadado.palavra = palavra;
                vocab.adicionar(sub, score, metadado);
            }
            else {
                sub = linha.substr(0,linha.size()-1);
            }
        }
    }
}

void listaMetaDados(Vocabulario vocab, string buscar){
    list<meta_dados> metadados = vocab.devolvePalavraMetaDado(buscar);
    cout << "Comentarios associados a " << buscar << ":" << endl;
    std::list<meta_dados>::const_iterator iterator;
    for (iterator = metadados.begin(); iterator != metadados.end(); ++iterator) {
        cout << "Comentario #" << iterator->comentario<< ", ";
        cout << "Palavra #" << iterator->palavra << ", ";
        cout << "Sentimento " << iterator->score << endl;
    }
}

void listarPalavrasPrefixo(Vocabulario vocab, string prefixo){
    list<string> lista = vocab.buscaPalavrasPrefixo(prefixo);
    std::list<string>::const_iterator iterator;
    cout << "Palavras que comecam por '" << prefixo <<" ':\n";
    for (iterator = lista.begin(); iterator != lista.end(); ++iterator) {
        cout << *iterator << "\n";
    }
}






int main() {

    char escolha = 1; //0 arquivo exemplo, 1 arquivo de treinamento do kaggle
    ifstream arquivo;
    while(escolha != '1' && escolha !='0'){
        cout << "Digite o para carregar vocabulario compacto" << endl;
        cout << "ou 1 para carregar vocabulario do Kaggle: ";
        escolha = getchar();
    }

    Vocabulario vocab;

    if (escolha == 1) {
        arquivo.open("data/train.tsv");
        if (arquivo.fail()) {
            cout << "Nao foi possivel abrir o arquivo" << endl;
            exit(0);
        }
        cout << "Carregando Vocabulario Kaggle" << endl;
        alimentaVocabularioKaggle(vocab, &arquivo);
    } else {
        arquivo.open("data/movieReviews.txt");
        if (arquivo.fail()) {
            cout << "Nao foi possivel abrir o arquivo" << endl;
            exit(0);
        }
        cout << "Carregando Vocabulario Compacto" << endl;
        alimentaVocabulario(vocab, &arquivo);
    }

    escolha = 0;
    while(escolha != '0' && escolha !='1' && escolha !='2' && escolha !='3'){
        cout << "Digite o para analizar novo comentario" << endl;
        cout << "Digite 1 para identificar as k palavras de grande ocorrencia" << endl;
        cout << "Digite 2 para listar comentarios associados a uma palavra" << endl;
        cout << "Digite 3 para listar palavras que comecam com um prefixo indicado" << endl;
        cin.clear();
        cin.get(escolha);
    }

    switch(escolha){
        case '0':
            classificarComentario(vocab);
            break;
        case '1':

            break;
        case '2':
            listaMetaDados(vocab, "loved");
            break;
        case '3':
            string prefixo;
            cout << "Digite o prefixo que deseja procurar: ";
            cin >> prefixo;
            listarPalavrasPrefixo(vocab, prefixo);
            break;
    }

    return 0;
};