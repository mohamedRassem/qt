#include "connexion.h"
#include "QSqlDatabase"

connexion::connexion()
{

}
bool connexion::createConnexion(){
   bool test=false;
   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("test");
   db.setUserName("SYSTEM");
   db.setPassword("system");
   if(db.open())
test=true;
return test;
}
