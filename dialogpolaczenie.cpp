#include "dialogpolaczenie.h"
#include "ui_dialogpolaczenie.h"

DialogPolaczenie::DialogPolaczenie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogPolaczenie)
{
    ui->setupUi(this);
}

DialogPolaczenie::~DialogPolaczenie()
{
    delete ui;
}

void DialogPolaczenie::on_comboBox_currentIndexChanged(int index)
{

}

