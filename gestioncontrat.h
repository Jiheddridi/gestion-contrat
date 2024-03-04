#ifndef GESTIONCONTRAT_H
#define GESTIONCONTRAT_H

#include <QDialog>

namespace Ui {
class gestioncontrat;
}

class gestioncontrat : public QDialog
{
    Q_OBJECT

public:
    explicit gestioncontrat(QWidget *parent = nullptr);
    ~gestioncontrat();

private slots:
    void on_pushButton_10_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::gestioncontrat *ui;
};

#endif // GESTIONCONTRAT_H
