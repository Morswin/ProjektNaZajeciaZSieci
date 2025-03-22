#include "dialogarx.h"
#include "ui_dialogarx.h"

DialogARX::DialogARX(DataDialog &data, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogARX)
    , dataOutIn(&data)
{
    ui->setupUi(this);

    a_params = data.a;
    b_params = data.b;
    insertIntoTextField(ui->lineEditARXView_A, data.a);
    insertIntoTextField(ui->lineEditARXView_B_2, data.b);
    ui->spinBoxARX_k->setValue(data.delay);
    if (data.czyZakl == true)
        ui->checkBoxARZ_z->setCheckState(Qt::Checked);
    else
        ui->checkBoxARZ_z->setCheckState(Qt::Unchecked);
    ui->doubleSpinBoxARX_z->setValue(data.zakl_std_dev);
}

DialogARX::DialogARX(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogARX)
    , dataOutIn(nullptr)
{
    ui->setupUi(this);
}

DialogARX::~DialogARX()
{
    delete ui;
}

void DialogARX::on_btnARXAdd_A_clicked()
{
    a_params.push_back(ui->doubleSpinBoxARX_A->value());

    insertIntoTextField(ui->lineEditARXView_A, a_params);
}


void DialogARX::on_btnARXClear_A_clicked()
{
    a_params.clear();
    ui->lineEditARXView_A->clear();
}


void DialogARX::on_btnARXAdd_B_2_clicked()
{
    b_params.push_back(ui->doubleSpinBoxARX_B_2->value());

    insertIntoTextField(ui->lineEditARXView_B_2, b_params);
}


void DialogARX::on_btnARXClear_B_2_clicked()
{
    b_params.clear();
    ui->lineEditARXView_B_2->clear();
}

void DialogARX::on_btnAccept_clicked()
{
    if (!a_params.empty() && !b_params.empty()) {
        // emit sendARX(a_params,
        //              b_params,
        //              ui->spinBoxARX_k->value(),
        //              ui->checkBoxARZ_z->isChecked(),
        //              ui->doubleSpinBoxARX_z->value());

        if(dataOutIn != nullptr) {
            dataOutIn->a = std::move(a_params);
            dataOutIn->b = std::move(b_params);
            dataOutIn->delay = ui->spinBoxARX_k->value();
            dataOutIn->czyZakl = ui->checkBoxARZ_z->isChecked();
            dataOutIn->zakl_std_dev = ui->doubleSpinBoxARX_z->value();
        }

        this->accept();
    }
    else
    {
        if (a_params.empty())
        {
            ui->lineEditARXView_A->clear();
            ui->lineEditARXView_A->insert("Należy podać przynajmniej jeden współczynnik!");
        }

        if (b_params.empty())
        {
            ui->lineEditARXView_B_2->clear();
            ui->lineEditARXView_B_2->insert("Należy podać przynajmniej jeden współczynnik!");
        }
    }
}


void DialogARX::on_checkBoxARZ_z_checkStateChanged(const Qt::CheckState &arg1)
{
    if(arg1 == Qt::Checked){
        ui->doubleSpinBoxARX_z->setDisabled(false);
    }
    else {
        ui->doubleSpinBoxARX_z->setDisabled(true);
        ui->doubleSpinBoxARX_z->setValue(0.0);
    }
}


void DialogARX::on_btnCancel_clicked()
{
    this->reject();
}

void DialogARX::insertIntoTextField(QLineEdit* field, const std::vector<double> &arx_params)
{
    field->clear();
    field->insert("{ ");
    for (const auto &p : arx_params) {
        field->insert(QString::number(p) + "; ");
    }
    field->insert("}");
}
