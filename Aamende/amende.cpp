#include "amende.h"
#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>

amende::amende()
{
 id=0;
 nom="";
 prenom="";
 typeA="";
 montant="";
 datea="";
}
amende::amende(int i,QString n,QString p,QString t,QString m,QString d)
{
    id=i;
    nom=n;
    prenom=p;
    typeA=t;
    montant=m;
    datea=d;
}

bool amende::ajouter()
{
    QSqlQuery  query;
    QString res= QString::number(id);
     query.prepare("INSERT INTO AMENDE(CIN,NOM,PRENOM,TYPE,MONTANT,DATEA)""VALUES(:id,:nom,:prenom,:typeA,:montant,:datea)") ;
     query.bindValue(":id",res);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":typeA",typeA);
     query.bindValue(":montant",montant);
     query.bindValue(":datea",datea);

     return query.exec();

}

QSqlQueryModel * amende::afficher()
{ QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from amende");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de amende"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Montant"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));
    return model;
}

bool amende::supprimer(int id)
{
    QSqlQuery  query;
    QString res= QString::number(id);
     query.prepare("Delete from AMENDE where CIN = :id");
     query.bindValue(":id",id);
return query.exec();

}

QSqlQueryModel *amende::rechercher(int id)
{
    QSqlQuery query;
    QSqlQueryModel * model1=new QSqlQueryModel();
    QString res=QString::number(id);


    model1->setQuery("select * from AMENDE where CIN LIKE '"+res+"%'");
    model1->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model1->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model1->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model1->setHeaderData(3, Qt::Horizontal, QObject::tr("Type de amende"));
    model1->setHeaderData(4, Qt::Horizontal, QObject::tr("Montant"));
    model1->setHeaderData(5, Qt::Horizontal, QObject::tr("Date"));


       return model1;

}

bool amende::modifier(int id)
{
    QSqlQuery  query;
    QString res= QString::number(id);
     query.prepare("update AMENDE set CIN = :id, NOM = :nom, PRENOM = :prenom, TYPE = :typeA, MONTANT = :montant, DATEA = :datea where CIN = :id") ;
     query.bindValue(":id",res);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":typeA",typeA);
     query.bindValue(":montant",montant);
     query.bindValue(":datea",datea);

     return query.exec();
}


QSqlQueryModel *amende::trierD()
{
             QSqlQuery * q = new  QSqlQuery ();
                     QSqlQueryModel * model = new  QSqlQueryModel ();
                     q->prepare("SELECT * FROM AMENDE order by DATEA DESC");
                     q->exec();
                     model->setQuery(*q);
                     return model;

}

QSqlQueryModel *amende::trierN()
{
              QSqlQuery * q = new  QSqlQuery ();
                     QSqlQueryModel * model = new  QSqlQueryModel ();
                     q->prepare("SELECT * FROM AMENDE order by NOM ASC");
                     q->exec();
                     model->setQuery(*q);
                     return model;

}

void amende::CREATE_PDF()
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
      //  printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(fileName);

        QTextDocument doc;
        QSqlQuery q;
        q.prepare("SELECT * FROM AMENDE  ");
        q.exec();
        QString pdf="<br> <h1  style='color:red'>LISTE AMENDE  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>NOM </th> <th>PRENOM </th> <th>TYPE </tr> <th>MONTANT </tr> <th>DATEA </tr> <th>DATEA </th> </th>" ;


        while ( q.next()) {

            pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+" " + q.value(1).toString() +"</td> <td>" +q.value(2).toString() +" "+q.value(3).toString() +" "+q.value(4).toString() +" "+q.value(5).toString() + "</td> </td>" ;

        }
        doc.setHtml(pdf);
       // doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
        doc.print(&printer);
}



