#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtDebug>
#include <QLibrary>
#include <include/set_dll.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
int in = ui->comboBox->currentIndex();
QString text_1=ui->lineEdit->text();
QString text_2=ui->lineEdit_2->text();

Set_dll data;
switch (in) {
    case 0:
        ui->textEdit->setText(data.get_text(data.addition(data.get_set(text_1),data.get_set(text_2))));
        break;

    case 1: ui->textEdit->setText("2");
        ui->textEdit->setText(data.get_text(data.disjunction(data.get_set(text_1),data.get_set(text_2))));
        break;
    case 2: ui->textEdit->setText("3");
        ui->textEdit->setText(data.get_text(data.difference(data.get_set(text_1),data.get_set(text_2))));
        break;
    case 3:
        ui->textEdit->setText(data.get_text(data.symmetrical_difference(data.get_set(text_1),data.get_set(text_2))));
        break;

    case 4: ui->textEdit->setText("2");
        data.equality(data.get_set(text_1),data.get_set(text_2))? ui->textEdit->setText("Множества равны") : ui->textEdit->setText("Множества не равны");
        break;

    case 5: ui->textEdit->setText("3");
        data.subset(data.get_set(text_1),data.get_set(text_2))? ui->textEdit->setText("Множество 'B' является подмножеством 'A'") : ui->textEdit->setText("Множество 'B' не является подмножеством 'A'");
        break;
    }
}
