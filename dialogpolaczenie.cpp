#include "dialogpolaczenie.h"
#include "ui_dialogpolaczenie.h"

DialogPolaczenie::DialogPolaczenie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPolaczenie)
{
    ui->setupUi(this);
    ui->adresIP->setEnabled(true);
    ui->trybLacznosci->setCurrentIndex(-1);
}

DialogPolaczenie::~DialogPolaczenie()
{
    delete ui;
}

int DialogPolaczenie::get_trybPolaczenia()
{
    return ui->trybLacznosci->currentIndex();
}

QString DialogPolaczenie::get_ip()
{
    return ui->adresIP->text();
}

int DialogPolaczenie::get_port()
{
    return ui->port->value();
}

void DialogPolaczenie::on_comboBox_currentIndexChanged(int index)
{
    switch (index)
    {
        case 0:
        {
            ui->adresIP->setEnabled(false);
            break;
        }
        case 1:
        {
            ui->adresIP->setEnabled(true);
            break;
        }
        default:
        {
            ui->adresIP->setEnabled(true);
            break;
        }
    }
        qDebug() << index;
}

