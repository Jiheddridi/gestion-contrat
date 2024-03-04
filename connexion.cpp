#include "connexion.h"
#include <QMessageBox>

connexion::connexion()
{

}
bool connexion::ouvrirconnexion()
{bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("database");
    db.setUserName("firas");
    db.setPassword("firas");

  if(db.open())
  {
      test=true;
  }
  return test;

}

void connexion::fermerconnexion()
{
    db.close();
}
