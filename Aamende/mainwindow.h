#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"amende.h"
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
    void on_pushButton_affi_clicked();
    void on_pushButton_bkaj2_clicked();
    void on_pushButton_bkaf2_clicked();
    void on_pushButton_back2_clicked();
    void on_pushButton_aj2_clicked();
    void on_pushButton_suppr_clicked();
    void on_pushButton_reche_clicked();
    void on_pushButton_mod_clicked();
    void on_pushButton_impr_clicked();
    void on_radioButton_nom_clicked();
    void on_radioButton_dat_clicked();


private:
    Ui::MainWindow *ui;
    amende temAmende;
};
#endif // MAINWINDOW_H
