#ifndef DIALOGARX_H
#define DIALOGARX_H

#include "qlineedit.h"
#include <QDialog>

namespace Ui {
class DialogARX;
}

struct DataDialog {
    std::vector<double> a;
    std::vector<double> b;
    int delay;
    bool czyZakl;
    double zakl_std_dev;
};

class DialogARX : public QDialog
{
    Q_OBJECT

public:
    explicit DialogARX(DataDialog &data, QWidget *parent = nullptr);
    explicit DialogARX(QWidget *parent = nullptr);
    ~DialogARX();

// signals:
//     void sendARX(const std::vector<double> a,
//                  const std::vector<double> b,
//                  int delay,
//                  bool czyZakl,
//                  double zakl_std_dev);

private slots:
    void on_btnARXAdd_A_clicked();

    void on_btnARXClear_A_clicked();

    void on_btnARXAdd_B_2_clicked();

    void on_btnARXClear_B_2_clicked();

    void on_btnAccept_clicked();

    void on_checkBoxARZ_z_checkStateChanged(const Qt::CheckState &arg1);

    void on_btnCancel_clicked();

private:
    Ui::DialogARX *ui;
    DataDialog *dataOutIn;
    std::vector<double> a_params;
    std::vector<double> b_params;

    void insertIntoTextField(QLineEdit* field, const std::vector<double> &arx_params);
};

#endif // DIALOGARX_H
