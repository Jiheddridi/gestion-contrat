#ifndef CONTRAT_H
#define CONTRAT_H
#include<QString>
#include <QSqlQueryModel>

class contrat
{
public:
    contrat();
    contrat(int,QString,QString,int,QString);

    // Getters
    int getIdContrat() const { return idcontrat; }
    int getCin() const { return cin; }
    int getMontant() const { return montant; }
    QString getType() const { return type; }
    QString getNom() const { return nom; }
    QString getDate() const { return date; }

    // Setters
    void setIdContrat(int id) { idcontrat = id; }
    void setCin(int c) { cin = c; }
    void setMontant(int m) { montant = m; }
    void setType(const QString& t) { type = t; }
    void setNom(const QString& n) { nom = n; }
    void setDate(const QString& d) { date = d; }

    bool ajouter_contrat();
    QSqlQueryModel* afficher_contrat();
    bool supprimer_contrat(int);
    bool modifier_contrat();
private:
    int idcontrat, cin, montant;
    QString type, nom, date;
};


#endif // CONTRAT_H
