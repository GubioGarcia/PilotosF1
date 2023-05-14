#ifndef PILOTO_H
#define PILOTO_H

#include <QString>

namespace ggs{
    class Piloto
    {
    private:
        int codigo;
        QString nome;
        QString pais;
        int idade;
        QString equipe;
        QString motor;
        int classificacao[7];
        int pontuacaoFinal; //armazena o valor após calculado pelo metodo
        //QString dados;//armazena dados recolhidos do arquivo //teste

    public:
        Piloto();
        Piloto(int codigo, QString nome, QString pais, int idade, QString equipe, QString motor, int classificacao[7]);

        void calcularPontuacaoFinal();
        //void toString();//testar os dados que a interface retorna

        int getCodigo() const;
        void setCodigo(int newCodigo);
        QString getNome() const;
        void setNome(const QString &newNome);
        QString getPais() const;
        void setPais(const QString &newPais);
        int getIdade() const;
        void setIdade(int newIdade);
        QString getEquipe() const;
        void setEquipe(const QString &newEquipe);
        QString getMotor() const;
        void setMotor(const QString &newMotor);
        int getPontuacaoFinal() const;
        void setPontuacaoFinal(int newPontuacaoFinal);
        QString getDados() const;
    };
}

#endif // PILOTO_H
