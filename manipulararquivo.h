#ifndef MANIPULARARQUIVO_H
#define MANIPULARARQUIVO_H
#include <QDebug>
#include <QString>
#include <fstream> //Biblioteca para tratamento de arquivos
#include <QStringList>
#include <vector>
#include <piloto.h>

namespace ggs{
    class ManipularArquivo
    {
    private:
        QString nomeDoArquivoDisco = "";
        std::vector<Piloto> pilotosF1;

    public:
        ManipularArquivo(QString nomeDoArquivoDisco);
        void buscarDadosNoArquivo();

        const std::vector<Piloto> getPilotosF1() const;
    };
}

#endif // MANIPULARARQUIVO_H
