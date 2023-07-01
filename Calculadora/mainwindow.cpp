#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , termo("")
{
    ui->setupUi(this);
    setWindowTitle("CALCULADORA");
    ui->lineEditResultado->setEnabled(false);
    // Representação das operações nos botões
    ui->pushButtonRadiciacao->setText(QString::fromUtf8("\u221A"));
    ui->pushButtonDivisao->setText(QString::fromUtf8("\u00F7"));
    ui->pushButtonPotenciacao->setText(QString::fromUtf8("\u005E"));
    ui->pushButtonTeste->setText(QString::fromUtf8("\u00B1"));
    ui->pushButtonPotenciacao->setText("x" + QString::fromUtf8("\u02b8"));
    ui->pushButtonPotenciacao->show();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::inserirTermo(QString valor){
    termo += valor;
    ui->lineEditTermos->setText(termo);
}

void MainWindow::on_pushButtonAbout_clicked(){
    QString about = "CALCULADORA 3.1\n";
    about += "Desenvolvido por Gubio Garcia.\n";
    about += "Programa desenvolvido para atendimento das demandas de calculos matematicos básicos.";
    QMessageBox::information(this,"About Calculadora",about);
}

void MainWindow::on_pushButtonPonto_clicked(){
    if(termo.isEmpty()) return; // verificar se o termo está vazio
    // inibir entrada de ponto após caractere diferente de números
    QChar ultimoCaractere = termo.at(termo.length() - 1);
    if(!ultimoCaractere.isNumber()) return;
    if(termo.contains("..")) return; // inibir entrada de pontos duplos seguidos
    // inclementar proibição de pontos duplos expaçados em um termo
    inserirTermo(".");
}

void MainWindow::on_pushButtonZero_clicked(){
    if(termo.isEmpty()) // verificar se o termo está vazio
    //verificar se termo anterior é válido (1 a 9)
    if (termo.length() > 0) {
        QChar ultimoCaractere = termo.at(termo.length() - 1);
        if (!ultimoCaractere.isNumber() || ultimoCaractere != '.') return;
    }
    inserirTermo("0");
}

void MainWindow::on_pushButtonNumeroUm_clicked(){
    inserirTermo("1");
}

void MainWindow::on_pushButtonNumero2_clicked(){
    inserirTermo("2");
}

void MainWindow::on_pushButtonNumero3_clicked(){
    inserirTermo("3");
}

void MainWindow::on_pushButtonNumero4_clicked(){
    inserirTermo("4");
}

void MainWindow::on_pushButtonNumeroCinco_clicked(){
    inserirTermo("5");
}

void MainWindow::on_pushButtonNumeroSeis_clicked(){
    inserirTermo("6");
}

void MainWindow::on_pushButtonNumeroSete_clicked(){
    inserirTermo("7");
}

void MainWindow::on_pushButtonNumeroOito_clicked(){
    inserirTermo("8");
}

void MainWindow::on_pushButtonNumeroNove_clicked(){
    inserirTermo("9");
}

void MainWindow::on_pushButtonAdcao_clicked(){
    inserirTermo("+");
    ggm::Calculadora objeto(ui->lineEditTermos->text().toDouble(), ui->lineEditTermos->text().toDouble());
    ui->lineEditResultado->setText(QString::number(objeto.calcularAdcao()));
}

void MainWindow::on_pushButtonSubtracao_clicked(){
    inserirTermo("-");
    ggm::Calculadora objeto(ui->lineEditTermos->text().toDouble(), ui->lineEditTermos->text().toDouble());
    ui->lineEditResultado->setText(QString::number(objeto.calcularSubtracao()));
}

void MainWindow::on_pushButtonMultiplicacao_clicked(){
    inserirTermo("*");
    ggm::Calculadora objeto(ui->lineEditTermos->text().toDouble(), ui->lineEditTermos->text().toDouble());
    ui->lineEditResultado->setText(QString::number(objeto.calcularMultiplicacao()));
}

void MainWindow::on_pushButtonDivisao_clicked(){
    try {
        inserirTermo(QString::fromUtf8("\u00F7"));
        ggm::Calculadora objeto(ui->lineEditTermos->text().toDouble(), ui->lineEditTermos->text().toDouble());
        ui->lineEditResultado->setText(QString::number(objeto.calcularDivisao()));
    } catch (QString erro) {
        QMessageBox::information(this,"Erro de Sistema",erro);
    }
}

void MainWindow::on_pushButtonPotenciacao_clicked(){
    inserirTermo("^");
    ggm::Calculadora objeto(ui->lineEditTermos->text().toDouble(),  ui->lineEditTermos->text().toDouble());
    QString instrucao = "Indique o Primerio Termo como a BASE e o Segundo Termo como o EXPOENTE de sua potenciacao";
    QMessageBox::information(this,"Instruções de uso",instrucao);
    ui->lineEditResultado->setText(QString::number(objeto.calcularPotenciacao(),'g',15));
}

void MainWindow::on_pushButtonRadiciacao_clicked(){
    try {
        inserirTermo("sqrt(");
        ggm::Calculadora objeto(ui->lineEditTermos->text().toDouble(), ui->lineEditTermos->text().toDouble());
        QString instrucao = "Indique o Primeiro Termo como o RADICANDO e o Segundo Termo como o RADICAL de sua radiciacao";
        int auxiliar;
        auxiliar = objeto.getSegundoTermo();
        if (auxiliar % 2 == 1 && objeto.getPrimeiroTermo() < 0){
        QMessageBox::information(this, "Instruções de uso", instrucao);
        ui->lineEditResultado->setText("-" + QString::number(objeto.calcularRadiciacao()));
        }
        else{
            QMessageBox::information(this,"Instruções de uso",instrucao);
            ui->lineEditResultado->setText(QString::number(objeto.calcularRadiciacao()));
        }
    } catch (QString &erro) {
        QMessageBox::information(this,"Erro de Sistema",erro);
    }
}

void MainWindow::on_pushButtonPorcentagem_clicked(){
    ggm::Calculadora objeto(ui->lineEditTermos->text().toDouble(),  ui->lineEditTermos->text().toDouble());
    QString instrucao = "Indique o Primeiro Termo como o TODO e o Segundo Termo como as PARTES";
    QMessageBox::information(this,"Instruções de uso",instrucao);
    QString saida = QString::number(objeto.getSegundoTermo()) + "% de " + QString::number(objeto.getPrimeiroTermo()) + " = ";
    ui->lineEditResultado->setText(saida + QString::number(objeto.calcularPorcentagem()));
}

void MainWindow::on_pushButtonIgual_clicked(){
    try {
        if(termo.isEmpty()) // verificar se o termo está vazio
        // verificar se termo anterior é válido (1 a 9 ou ')')
        if (termo.length() > 0) {
            QChar ultimoCaractere = termo.at(termo.length() - 1);
            if (ultimoCaractere.isNumber() || ultimoCaractere == ')') {
                // chama a calculadora
            } else throw QString("Erro na equação");
        }
    } catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}
