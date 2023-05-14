#include "interfacegrafica.h"
#include "ui_interfacegrafica.h"

InterfaceGrafica::InterfaceGrafica(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::InterfaceGrafica),
      nomeDoArquivoDisco("")
{
    ui->setupUi(this);
    ui->lineEditNomeArquivo->setEnabled(false);
    ui->tableWidgetClassificacao->setEnabled(false);
    ui->pushButtonClassificar->setEnabled(false);
}

InterfaceGrafica::~InterfaceGrafica()
{
    delete ui;
}


void InterfaceGrafica::on_pushButtonBuscar_clicked()
{
    try {
        //Buscando o arquivo no disco
        nomeDoArquivoDisco = QFileDialog::getOpenFileName(this, "Abrir Arquivo", QDir::currentPath(), "Arquivos Textos (*.csv *.txt )");
        if(nomeDoArquivoDisco.isEmpty()) throw QString("Arquivo não foi selecionado");
        ui->lineEditNomeArquivo->setText(nomeDoArquivoDisco);
        ui->pushButtonClassificar->setEnabled(true);
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO",erro);
    }
}


void InterfaceGrafica::on_pushButtonClassificar_clicked()
{
    try {
        ggs::ManipularArquivo objArquivos(this->nomeDoArquivoDisco);
        objArquivos.buscarDadosNoArquivo();
        std::vector<ggs::Piloto> pilotosF1 = objArquivos.getPilotosF1();

        //QString saida = ""; //teste saida
        for(int i=0; i<(int)pilotosF1.size(); i++){
            /*saida += pilotosF1[i].getDados() + "\n\n" ;
            ui->textEditSaida->setText(saida);*/
            QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(pilotosF1[i].getCodigo()));
            ui->tableWidgetClassificacao->setItem(i, 0, item1);

            QTableWidgetItem *item2 = new QTableWidgetItem(pilotosF1[i].getNome());
            ui->tableWidgetClassificacao->setItem(i, 1, item2);

            QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(pilotosF1[i].getPontuacaoFinal()));
            ui->tableWidgetClassificacao->setItem(i, 2, item3);

            QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(i+1));
            ui->tableWidgetClassificacao->setItem(i, 3, item4);
        }
    } catch (QString &erro){
        QMessageBox::information(this, "ERRO", erro);
    }
}
