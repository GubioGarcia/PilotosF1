#ifndef INTERFACEGRAFICA_H
#define INTERFACEGRAFICA_H

#include <QMainWindow>
#include <QMessageBox>
#include <manipulararquivo.h>
#include <QFileDialog> //Biblioteca de manipulação dos diretorios do disco

QT_BEGIN_NAMESPACE
namespace Ui { class InterfaceGrafica; }
QT_END_NAMESPACE

class InterfaceGrafica : public QMainWindow
{
    Q_OBJECT

public:
    InterfaceGrafica(QWidget *parent = nullptr);
    ~InterfaceGrafica();

private slots:
    void on_pushButtonBuscar_clicked();
    void on_pushButtonClassificar_clicked();

private:
    Ui::InterfaceGrafica *ui;
    QString nomeDoArquivoDisco;
};
#endif // INTERFACEGRAFICA_H
