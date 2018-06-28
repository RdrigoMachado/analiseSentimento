#include <iostream>
#include <fstream>
#include <sstream>

#include <cstdlib>
#include <algorithm>
#include "Vocabulario.h"
int main() {

    /* Codigo Auxiliar modificado*/
    //declare a few needed variables for inputing the data
    string linha;
    int score;
    string message = " ";

    //open input file
    ifstream myfile ("data/movieReviews.txt");
    if (myfile.fail() )
    {
        cout << "could not open file" <<endl;
        exit(0);
    }

    //create trie
    Vocabulario vocab;

    while (myfile >> score &&  myfile.get() && getline(myfile,linha))
    {
        //deixa todos os caracteres em lowercase
        std::transform(linha.begin(), linha.end(), linha.begin(), ::tolower);
        ostringstream streamTemp;
        int isWhiteSpace = 0;
        /*atualiza a linha:
         * substituindo simbolos nao pertecentes ao alfabeto por espacos
         *e removendo espacos contiguos
        */
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
        linha = streamTemp.str();
        //cout << "Linha: " << linha << endl;

        int len = linha.size();

        while(len > 0) {  //identify all individual strings
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

    //after data is entered in hash function
    //prompt user for a new movie review
    while(message.length() > 0)
    {
        cout << "enter a review -- Press return to exit: "<<endl;
        getline(cin,message);

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
            //calculate the score of each word
            sum += vocab.scoreMedio(sub);
            count++;
        }

        if (message.size() > 0)
        {
            cout << "The review has an average value of " << sum/count <<endl;
        }
    }

    return 0;
  }