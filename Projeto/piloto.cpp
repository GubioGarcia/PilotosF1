#include "piloto.h"

namespace ggs{
    Piloto::Piloto()
    {}

    Piloto::Piloto(int codigo, QString nome, QString pais, int idade, QString equipe, QString motor, int classificacao[7]):
        codigo(codigo), nome(nome), pais(pais), idade(idade), equipe(equipe), motor(motor), classificacao(), pontuacaoFinal(0)//, dados("")
    {
        for(int pos = 0; pos < 7; pos++){
            this->classificacao[pos] = classificacao[pos];
        }
    }

    void Piloto::calcularPontuacaoFinal(){
        this->setPontuacaoFinal(0);
        int pontos[7]={0,40,30,25,20,15,10};
        for(int i=0; i<7; i++) pontuacaoFinal += pontos[classificacao[i]];
    }

    /*void Piloto::toString(){//armazena dados recolhidos do arquivo //teste
        QString saida = "";
        saida += "Codigo: " + QString::number(codigo) +  "\n";
        saida += "Nome: " + nome + "\n";
        saida += "Pais: " + pais + "\n";
        saida += "Idade: " + QString::number(idade) + "\n";
        saida += "Equipe: " + equipe + "\n";
        saida += "Motor: " + motor + "\n";
        saida += "1 - Classificação => "+ QString::number(classificacao[0]) + "\n";
        saida += "2 - Classificação => "+ QString::number(classificacao[1]) + "\n";
        saida += "3 - Classificação => "+ QString::number(classificacao[2]) + "\n";
        saida += "4 - Classificação => "+ QString::number(classificacao[3]) + "\n";
        saida += "5 - Classificação => "+ QString::number(classificacao[4]) + "\n";
        saida += "6 - Classificação => "+ QString::number(classificacao[5]) + "\n";
        saida += "7 - Classificação => "+ QString::number(classificacao[6]) + "\n";
        saida += "Pontuação Final: " + QString::number(pontuacaoFinal) + "\n";
        this->dados = saida;
    }

    QString Piloto::getDados() const{//armazena dados recolhidos do arquivo //teste
        return dados;
    }*/

    int Piloto::getCodigo() const{
        return codigo;}
    void Piloto::setCodigo(int newCodigo){
        codigo = newCodigo;}
    QString Piloto::getNome() const{
        return nome;}
    void Piloto::setNome(const QString &newNome){
        nome = newNome;}
    QString Piloto::getPais() const{
        return pais;}
    void Piloto::setPais(const QString &newPais){
        pais = newPais;}
    int Piloto::getIdade() const{
        return idade;}
    void Piloto::setIdade(int newIdade){
        idade = newIdade;}
    QString Piloto::getEquipe() const{
        return equipe;}
    void Piloto::setEquipe(const QString &newEquipe){
        equipe = newEquipe;}
    QString Piloto::getMotor() const{
        return motor;}
    void Piloto::setMotor(const QString &newMotor){
        motor = newMotor;}
    int Piloto::getPontuacaoFinal() const{
        return pontuacaoFinal;}
    void Piloto::setPontuacaoFinal(int newPontuacaoFinal){
        pontuacaoFinal = newPontuacaoFinal;}
}
