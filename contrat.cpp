#include "contrat.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
contrat::contrat()
{

}

contrat::contrat(int cin,QString nom,QString type,int montant,QString date)
{
    this->cin=cin;
    this->nom=nom;
    this->type=type;
    this->montant=montant;
    this->date=date;
}

bool contrat::ajouter_contrat()
{

    QSqlQuery query;
  QString cin_string= QString::number(cin);
  QString montant_string= QString::number(montant);

         query.prepare("INSERT INTO contrat (cin, nom, type,montant,datee) "
                       "VALUES (:cin, :forename, :type,:montant,:date)");
         query.bindValue(":cin",cin_string);
         query.bindValue(":forename", nom);
         query.bindValue(":type", type);
         query.bindValue(":montant", montant_string);
         query.bindValue(":date", date);
        return query.exec();
}
bool contrat::supprimer_contrat(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM contrat WHERE cin = :id");
    query.bindValue(":id", id);
    return query.exec();
}

bool contrat::modifier_contrat()
{
    QSqlQuery query;
    QString cin_string = QString::number(cin);
    QString montant_string = QString::number(montant);

    query.prepare("UPDATE contrat SET type=:type, nom=:nom, datee=:date, montant=:montant WHERE cin=:id");
    query.bindValue(":type", type);
    query.bindValue(":nom", nom);

    query.bindValue(":date", date);
    query.bindValue(":montant", montant_string);

    query.bindValue(":id", cin);


    return query.exec();
}

QSqlQueryModel* contrat::afficher_contrat()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM contrat ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATE"));

    return model;
}
