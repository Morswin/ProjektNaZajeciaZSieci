#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "symulacja.h"
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    double findMinRange(QVector<double> &y_data);
    double findMaxRange(QVector<double> &y_data);
    void setUpGraphs();

    void on_btnStart_clicked();
    void advance();
    void on_groupBoxKwad_toggled(bool arg1);
    void on_groupBoxSin_toggled(bool arg1);
    void on_groupBoxSkok_toggled(bool arg1);
    void on_btnARXAdd_A_clicked();
    void on_btnARXAdd_B_clicked();
    void on_btnARXClear_A_clicked();
    void on_btnARXClear_B_clicked();
    void on_btnReset_clicked();
    void on_btnResetD_clicked();
    void on_btnResetI_clicked();
    void on_btnStop_clicked();
    void on_spinBoxInterwal_valueChanged(int arg1);
    void on_spinBoxWidokKrokow_valueChanged(int arg1);
    void on_doubleSpinBoxP_valueChanged(double arg1);
    void on_doubleSpinBoxI_valueChanged(double arg1);
    void on_doubleSpinBoxD_valueChanged(double arg1);
    void on_spinBoxARX_k_valueChanged(int arg1);
    void on_checkBoxARZ_z_checkStateChanged(const Qt::CheckState &arg1);
    void on_groupBoxSkok_clicked();
    void on_groupBoxKwad_clicked();
    void on_groupBoxSin_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* timer = nullptr;
    Symulacja UAR;
    int krok_wykres;\
    std::vector<double> arx_a_view;
    std::vector<double> arx_b_view;
    QVector<double> graph_x;
    QVector<double> uar_we_y;
    QVector<double> uar_wy_y;
    QVector<double> uchyb_y;
    QVector<double> pid_y;
    QVector<double> p_y;
    QVector<double> i_y;
    QVector<double> d_y;
};

#endif // MAINWINDOW_H
