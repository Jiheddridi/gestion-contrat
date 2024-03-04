#include "gestioncontrat.h"
#include "ui_gestioncontrat.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include "contrat.h"
gestioncontrat::gestioncontrat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestioncontrat)
{
    ui->setupUi(this);
    contrat *c=new contrat();
    ui->tableView->setModel(c->afficher_contrat());

}

gestioncontrat::~gestioncontrat()
{
    delete ui;
}

void gestioncontrat::on_pushButton_10_clicked()
{
    QMessageBox msgBox;
    int id = ui->lineEdit_cin->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString type = ui->lineEdit_type->text();
    QString date = ui->dateEdit_date->text();
    int montant = ui->lineEdit_montant->text().toInt();

    if (ui->lineEdit_cin->text().size() != 8) {
        msgBox.setText("Veuillez vérifier votre numéro de carte d'identité");
        msgBox.exec();

    }

    if (montant <= 0) {
        msgBox.setText("Le montant doit être un nombre positif");
        msgBox.exec();

    }

    contrat c(id, nom, type, montant, date);
    bool test = c.ajouter_contrat();
    if (test) {
        msgBox.setText("Ajout avec succès.");
        ui->tableView->setModel(c.afficher_contrat());
         msgBox.exec();
    }
    else {
        msgBox.setText("Échec d'ajout");
        msgBox.exec();
    }
}


void gestioncontrat::on_tableView_activated(const QModelIndex &index)
{
    QString val;QSqlQuery query;


        val=ui->tableView->model()->data(index).toString();
       int  x=ui->tableView->model()->data(index).toInt();

       query.prepare("select * from contrat where cin=:x or nom =:val or  datee=:val or type=:val or montant=:x  ");
         query.bindValue(":val",val);
         query.bindValue(":x",x);

         if (query.exec())
         {
             while (query.next())
             {
                 ui->lineEdit_cin_2->setText(query.value(0).toString());
                 ui->lineEdit_nom_2->setText(query.value(1).toString());
                 ui->lineEdit_type_2->setText(query.value(2).toString());
                 ui->lineEdit_montant_2->setText(query.value(3).toString());
                 ui->lineEdit_date_2->setText(query.value(4).toString());


             }
         }
         else
         {
             QMessageBox::critical(this ,tr("error::"),query.lastError().text());
         }
}

void gestioncontrat::on_pushButton_8_clicked()
{
    contrat c1;
    if(ui->lineEdit_cin_2->text()!="")
    {    c1.setCin(ui->lineEdit_cin_2->text().toInt());
    bool test=c1.supprimer_contrat(c1.getCin());
    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Suppression avec succes.");
        ui->tableView->setModel(c1.afficher_contrat());

    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
}
}

void gestioncontrat::on_pushButton_9_clicked()
{
    bool test;
    QMessageBox msgBox;
    if (ui->lineEdit_cin_2->text() != "") {
        int cin = ui->lineEdit_cin_2->text().toInt();
        QString nom = ui->lineEdit_nom_2->text();
        QString type = ui->lineEdit_type_2->text();
        QString date = ui->lineEdit_date_2->text();
        int montant = ui->lineEdit_montant_2->text().toInt();

        contrat c(cin, nom, type, montant, date);
        test = c.modifier_contrat();

        if (test) {
            msgBox.setText("Modification avec succès.");
            ui->tableView->setModel(c.afficher_contrat());
        }
        else {
            msgBox.setText("Échec de modification");
            msgBox.exec();
        }
    }
    else {
        msgBox.setText("Veuillez choisir un Contrat");
        msgBox.exec();
    }
}
