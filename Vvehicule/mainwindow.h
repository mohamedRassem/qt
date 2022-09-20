#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"vehicule.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_ajou_clicked();
    void on_pushButton_aff_clicked();
    void on_pushButton_bkaj_clicked();
    void on_pushButton_bkaf_clicked();
    void on_pushButton_back_clicked();
    void on_pushButton_aj1_clicked();
    void on_pushButton_supp_clicked();
    void on_pushButton_rech_clicked();
    void on_pushButton_modi_clicked();
    void on_pushButton_imp_clicked();
    void on_radioButton_mat_clicked();
    void on_radioButton_date_clicked();


private:
    Ui::MainWindow *ui;
    vehicule tempVehicule;
};
#endif // MAINWINDOW_H
