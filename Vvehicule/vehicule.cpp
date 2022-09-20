#include "vehicule.h"

#include<QSqlQueryModel>
#include<QSqlQuery>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>

vehicule::vehicule()
{
     type="";
     marque="";
     matricule="";
     puissance="";
     energie="";
     dateS="";
}

vehicule::vehicule(QString t,QString mr,QString mt,QString p,QString e,QString d)
{
    type=t;
    marque=mr;
    matricule=mt;
    puissance=p;
    energie=e;
    dateS=d;
}

bool vehicule::ajouter()
{
  QSqlQuery  query;

   query.prepare("INSERT INTO VEHICULE (TYPE,MARQUE,MATRICULE,PUISSANCE,ENERGIE,DATES)""VALUES(:type,:marque,:matricule,:puissance,:energie,:dateS)") ;
   query.bindValue(":type",type);
   query.bindValue(":marque",marque);
   query.bindValue(":matricule",matricule);
   query.bindValue(":puissance",puissance);
   query.bindValue(":energie",energie);
   query.bindValue(":dateS",dateS);

   return query.exec();
}

QSqlQueryModel * vehicule::afficher()
{ QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from vehicule");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type de vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Puissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Energie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de mise en service"));
    return model;
}
bool vehicule::supprimer(QString matricule)
{
    QSqlQuery  query;
     query.prepare("Delete from vehicule where MATRICULE = :matricule");
     query.bindValue(":matricule",matricule);
return query.exec();

}

QSqlQueryModel *vehicule::rechercher(QString matricule)
{
    QSqlQuery query;
    QSqlQueryModel * model=new QSqlQueryModel();


    model->setQuery("select * from VEHICULE where MATRICULE LIKE '"+matricule+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Type de vehicule"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Marque"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Matricule"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Puissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Energie"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Date de mise en service"));


       return model;

}

bool vehicule::modifier(QString matricule)
{
    QSqlQuery  query;

     query.prepare("update VEHICULE set TYPE = :type, MARQUE = :marque, MATRICULE = :matricule, PUISSANCE = :puissance, ENERGIE = :energie, DATES =:dateS where MATRICULE = :matricule ") ;
     query.bindValue(":type",type);
     query.bindValue(":marque",marque);
     query.bindValue(":matricule",matricule);
     query.bindValue(":puissance",puissance);
     query.bindValue(":energie",energie);
     query.bindValue(":dateS",dateS);

     return query.exec();

}

QSqlQueryModel *vehicule::trierM()
{
              QSqlQuery * q = new  QSqlQuery ();
                     QSqlQueryModel * model = new  QSqlQueryModel ();
                     q->prepare("SELECT * FROM VEHICULE order by MATRICULE DESC");
                     q->exec();
                     model->setQuery(*q);
                     return model;

}

QSqlQueryModel *vehicule::trierD()
{

              QSqlQuery * q = new  QSqlQuery ();
                     QSqlQueryModel * model = new  QSqlQueryModel ();
                     q->prepare("SELECT * FROM VEHICULE order by DATES DESC");
                     q->exec();
                     model->setQuery(*q);
                     return model;

}

void vehicule::SAVE_PDF()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
       if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

       QPrinter printer(QPrinter::PrinterResolution);
       printer.setOutputFormat(QPrinter::PdfFormat);
       //printer.setPaperSize(QPrinter::A4));
       printer.setOutputFileName(fileName);

       QTextDocument doc;
       QSqlQuery q;
       q.prepare("SELECT * FROM VEHICULE ");
       q.exec();
       QString pdf="<br> <h1  style='color:red'>LISTE VEHICULE  <br></h1>\n <br> <table>  <tr>  <th>TYPE </th> <th>MARQUE </th> <th>MATRICULE </th> <th>PUISSANCE </tr> <th>ENERGIE </tr> <th>DATES </tr>" ;


       while ( q.next()) {

           pdf= pdf+ " <br> <tr> <td>"+ q.value(0).toString()+"   " + q.value(1).toString() +"</td>   <td>" +q.value(2).toString() +"   "+q.value(3).toString() +"   "+q.value(4).toString() +"   "+q.value(5).toString() +"</td> </td>" ;

       }
       doc.setHtml(pdf);
       //doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
       doc.print(&printer);
}
