#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include<QMessageBox>
#include <QPrinter>
#include <QPrintDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QSystemTrayIcon>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabView_amende->setModel(temAmende.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ajou_clicked() //ajouter vehicule
{
     ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_affi_clicked() //afficher vehicule
{
     ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_bkaj2_clicked() //back ajouter
{
     ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_bkaf2_clicked() //back afficher
{
     ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_aj2_clicked()
{
    int id= ui->lineEdit_cin->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString typeA= ui->lineEdit_typea->text();
    QString montant= ui->lineEdit_montant->text();
    QString datea= ui->lineEdit_datea->text();
    amende v(id,nom,prenom,typeA,montant,datea);
    bool test=v.ajouter();
    if(test)
    {
        ui->tabView_amende->setModel(temAmende.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout"),
                 QObject::tr("ajout succès.\n""Click canal to exit"),QMessageBox::Cancel);
     }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                QObject::tr("ajout echoué.\n""Click canal to exit"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_suppr_clicked() //supprimer
{
    int id= ui->lineEdit_cinsr->text().toInt();
    bool test=temAmende.supprimer(id);
    if(test)
    {
      ui->tabView_amende->setModel(temAmende.afficher());
      QMessageBox::information(nullptr, QObject::tr("suppression"),
               QObject::tr("suppression avec succès.\n""Click canal to exit"),QMessageBox::Cancel);
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("suppression"),
                            QObject::tr("suppression avec echoué.\n""Click canal to exit"),QMessageBox::Cancel);}

}


void MainWindow::on_pushButton_reche_clicked() //chercher
{
    int id=ui->lineEdit_cinsr->text().toInt();
            ui->tabView_amende->setModel(temAmende.rechercher(id));


}

void MainWindow::on_pushButton_mod_clicked() //modifier
{

    int id= ui->lineEdit_2->text().toInt();
    QString nom= ui->lineEdit_3->text();
    QString prenom= ui->lineEdit_4->text();
    QString typeA= ui->lineEdit_5->text();
    QString montant= ui->lineEdit_6->text();
    QString datea= ui->lineEdit_7->text();
    amende a(id,nom,prenom,typeA,montant,datea);

            bool test=a.modifier(id);
            if(test)
            {
               ui->tabView_amende->setModel(temAmende.afficher());
                QMessageBox::information(nullptr, QObject::tr("modifié"),
                            QObject::tr("modifié avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else

                QMessageBox::critical(nullptr, QObject::tr("modifié"),
                            QObject::tr("modifié échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_radioButton_nom_clicked()
{
    ui->tabView_amende->setModel(temAmende.trierN());
}

void MainWindow::on_radioButton_dat_clicked()
{
    ui->tabView_amende->setModel(temAmende.trierD());
}

void MainWindow::on_pushButton_impr_clicked() //imprimer pdf
{
           amende a;
            a.CREATE_PDF();

}



void MainWindow::on_pushButton_back2_clicked() //exit
{
   close();
}
