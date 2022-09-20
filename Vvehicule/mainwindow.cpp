#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include"vehicule.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabView_vehicule->setModel(tempVehicule.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajou_clicked() //ajouter vehicule
{
     ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_aff_clicked() //afficher vehicule
{
     ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_bkaj_clicked() //back ajouter
{
     ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_bkaf_clicked() //back afficher
{
     ui->stackedWidget->setCurrentIndex(0);

}
void MainWindow::on_pushButton_aj1_clicked()
{


 QString type= ui->lineEdit_type->text();
 QString marque= ui->lineEdit_marque->text();
 QString matricule= ui->lineEdit_matricule->text();
 QString puissance= ui->lineEdit_puissance->text();
 QString energie= ui->lineEdit_energie->text();
 QString dateS= ui->lineEdit_date->text();
 vehicule v(type,marque,matricule,puissance,energie,dateS);
 bool test=v.ajouter();
 if(test)
 {
     ui->tabView_vehicule->setModel(tempVehicule.afficher());
     QMessageBox::information(nullptr, QObject::tr("ajout"),
              QObject::tr("ajout succès.\n""Click canal to exit"),QMessageBox::Cancel);
  }
 else
     QMessageBox::critical(nullptr, QObject::tr("ajout"),
             QObject::tr("ajout echoué.\n""Click canal to exit"),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supp_clicked()
{
    QString matricule = ui->lineEdit_surema->text();
    bool test=tempVehicule.supprimer(matricule);
    if(test)
    {
      ui->tabView_vehicule->setModel(tempVehicule.afficher());
      QMessageBox::information(nullptr, QObject::tr("suppression"),
               QObject::tr("suppression avec succès.\n""Click canal to exit"),QMessageBox::Cancel);
    }
    else
    { QMessageBox::critical(nullptr, QObject::tr("suppression"),
                            QObject::tr("suppression avec echoué.\n""Click canal to exit"),QMessageBox::Cancel);}

}
void MainWindow::on_pushButton_rech_clicked()
{
    QString matricule = ui->lineEdit_surema->text();
            ui->tabView_vehicule->setModel(tempVehicule.rechercher(matricule));
}

void MainWindow::on_pushButton_modi_clicked()
{
    QString type= ui->lineEdit_1->text();
    QString marque= ui->lineEdit_2->text();
    QString matricule= ui->lineEdit_3->text();
    QString puissance= ui->lineEdit_4->text();
    QString energie= ui->lineEdit_5->text();
    QString dateS= ui->lineEdit_6->text();
    vehicule v(type,marque,matricule,puissance,energie,dateS);
            bool test=v.modifier(matricule);
            if(test)
            {
               ui->tabView_vehicule->setModel(tempVehicule.afficher());
                QMessageBox::information(nullptr, QObject::tr("modifié"),
                            QObject::tr("modifié avec succés.\n" "Click Cancel to exit."), QMessageBox::Cancel);

            }
             else

                QMessageBox::critical(nullptr, QObject::tr("modifié"),
                            QObject::tr("modifié échoué.\n""Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_radioButton_mat_clicked()
{
 ui->tabView_vehicule->setModel(tempVehicule.trierM());
}

void MainWindow::on_radioButton_date_clicked()
{
 ui->tabView_vehicule->setModel(tempVehicule.trierD());
}

void MainWindow::on_pushButton_imp_clicked()
{
    vehicule v;
     v.SAVE_PDF();

}

void MainWindow::on_pushButton_back_clicked() //exit
{
  close();
}
