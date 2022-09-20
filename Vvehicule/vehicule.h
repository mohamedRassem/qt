#ifndef VEHICULE_H
#define VEHICULE_H
#include<QString>
#include<QSqlQueryModel>
#include<QSqlQuery>

class vehicule
{
public:

        vehicule();
        vehicule(QString,QString,QString,QString,QString,QString);
        QString get_type(){return type;}
        QString get_marque(){return marque;}
        QString get_matricule(){return matricule;}
        QString get_puissance(){return puissance;}
        QString get_energie(){return energie;}
        QString get_dateS(){return dateS;}
        bool ajouter();
        QSqlQueryModel * afficher();
        bool supprimer(QString);
        QSqlQueryModel* rechercher(QString);
        bool modifier(QString matricule);
        QSqlQueryModel *trierM();
        QSqlQueryModel *trierD();

        void SAVE_PDF();


private:
    QString type,marque,matricule,puissance,energie,dateS;

};

#endif // VEHICULE_H
