#include "mainwindow.h"
#include "./ui_mainwindow.h"

double num_first;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digits_numbers()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));

    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT( operations_dot_devide_minus_plus()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT( operations_dot_devide_minus_plus()));
    connect(ui->pushButton_devide, SIGNAL(clicked()), this, SLOT( operations_dot_devide_minus_plus()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT( operations_dot_devide_minus_plus()));

    ui->pushButton_devide->setCheckable(true);
    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;
    QString new_label;

    if(ui->result_show->text().contains(".") && button->text() == "0")
    {
        new_label = ui->result_show->text() + button->text();
    } else {
        all_numbers = (ui->result_show->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }
    ui->result_show->setText(new_label);
}


void MainWindow::on_pushButton_dot_clicked()
{
    if(!ui->result_show->text().contains(".")){
         ui->result_show->setText(ui->result_show->text() + ".");
    }

}

void MainWindow::operations()
{
    QPushButton *button = (QPushButton *)sender();

    double all_numbers;

    QString new_label;

    if(button->text() == "+/-")
    {
          all_numbers = (ui->result_show->text()).toDouble();
          all_numbers = all_numbers * -1;
          new_label = QString::number(all_numbers, 'g', 15);
          ui->result_show->setText(new_label);
    } else  if(button->text() == "%")
    {
        all_numbers = (ui->result_show->text()).toDouble();
        all_numbers = all_numbers * 0.01;
        new_label = QString::number(all_numbers, 'g', 15);
        ui->result_show->setText(new_label);
    }
}



void MainWindow::on_pushButton_ac_clicked()
{
    double all_numbers;
    QString new_label;
    num_first = 0;
    all_numbers = 0;
    ui->pushButton_plus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_devide->setChecked(false);
    new_label = QString::number(all_numbers, 'g', 15);
    ui->result_show->setText(new_label);

}


void MainWindow::on_pushButton_eqval_clicked()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    double num_second = (ui->result_show->text()).toDouble();

    if(ui->pushButton_multiply->isChecked()){
        all_numbers = num_first * num_second;
//        ui->pushButton_multiply->setChecked(false);
    } else if(ui->pushButton_plus->isChecked()){
        all_numbers = num_first + num_second;
//        ui->pushButton_plus->setChecked(false);
    } else if(ui->pushButton_minus->isChecked()){
        all_numbers = num_first - num_second;
//        ui->pushButton_minus->setChecked(false);
    } else if(ui->pushButton_devide->isChecked() && num_second != 0){
        all_numbers = num_first / num_second;
//        ui->pushButton_devide->setChecked(false);
    }

    num_first = all_numbers;
    new_label = QString::number(all_numbers, 'g', 15);
    ui->result_show->setText(new_label);

}

void MainWindow::operations_dot_devide_minus_plus()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    ui->pushButton_plus->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_devide->setChecked(false);

    button->setChecked(true);
    num_first = (ui->result_show->text()).toDouble();
    ui->result_show->setText("");

}



