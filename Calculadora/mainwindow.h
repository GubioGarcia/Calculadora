#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <calculadora.h>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString termo;
    Ui::MainWindow *ui;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void inserirTermo(QString valor);

private slots:
    void on_pushButtonAbout_clicked();
    void on_pushButtonAdcao_clicked();
    void on_pushButtonSubtracao_clicked();
    void on_pushButtonMultiplicacao_clicked();
    void on_pushButtonDivisao_clicked();
    void on_pushButtonPotenciacao_clicked();
    void on_pushButtonRadiciacao_clicked();
    void on_pushButtonPorcentagem_clicked();
    void on_pushButtonIgual_clicked();
    void on_pushButtonPonto_clicked();
    void on_pushButtonZero_clicked();
    void on_pushButtonNumeroUm_clicked();
    void on_pushButtonNumero2_clicked();
    void on_pushButtonNumero3_clicked();
    void on_pushButtonNumero4_clicked();
    void on_pushButtonNumeroCinco_clicked();
    void on_pushButtonNumeroSeis_clicked();
    void on_pushButtonNumeroSete_clicked();
    void on_pushButtonNumeroOito_clicked();
    void on_pushButtonNumeroNove_clicked();
};
#endif // MAINWINDOW_H
