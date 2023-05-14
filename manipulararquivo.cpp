#include "manipulararquivo.h"

namespace ggs{
    ManipularArquivo::ManipularArquivo(QString nomeDoArquivoDisco):
        nomeDoArquivoDisco(nomeDoArquivoDisco)
    {}

    const std::vector<Piloto> ManipularArquivo::getPilotosF1() const{
        return pilotosF1;
    }

    void ManipularArquivo::buscarDadosNoArquivo(){
        try{
            std::ifstream arquivo; //criando um arquivo de entrada
            arquivo.open(nomeDoArquivoDisco.toStdString().c_str()); //abrindo um arquivo de entrada
            if(!arquivo.is_open()) throw QString("ERRO. Arquivo não pode ser aberto");

            std::string linha;

            getline(arquivo,linha); // lendo do arquivo

            while(!arquivo.eof()){ // Teste de fim do arquivo
                QString texto = QString::fromStdString(linha);
                QStringList strList = texto.split(';');
                int codigo = strList[0].toInt();
                QString nome = strList[1];
                QString pais = strList[2];
                int idade = strList[3].toInt();
                QString equipe = strList[4];
                QString motor = strList[5];
                int classificacao[7];
                for(int i=0, j=6; i<7; i++, j++) classificacao[i] = strList[j].toInt();

                Piloto objetoPiloto(codigo, nome, pais, idade, equipe, motor, classificacao);
                objetoPiloto.calcularPontuacaoFinal();

                //objetoPiloto.toString();//teste saida

                this->pilotosF1.push_back(objetoPiloto);

                getline(arquivo,linha); //lendo do arquivo
            }
            arquivo.close(); //fechando o arquivo de entrada

            std::sort(pilotosF1.begin(), pilotosF1.end(), [](Piloto A, Piloto B){
                if(A.getPontuacaoFinal() != B.getPontuacaoFinal()) return A.getPontuacaoFinal() > B.getPontuacaoFinal();
            });
        } catch (QString &erro){
            throw erro;
        }
    }
}
