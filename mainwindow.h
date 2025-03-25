#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qcustomplot.h"
#include "symulacja.h"
#include "dialogarx.h"
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>

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
    void advance();

    void keyPressEvent(QKeyEvent* event);
    void on_btnStart_clicked();
    void on_groupBoxKwad_toggled(bool arg1);
    void on_groupBoxSin_toggled(bool arg1);
    void on_groupBoxSkok_toggled(bool arg1);
    void on_btnReset_clicked();
    void on_btnResetD_clicked();
    void on_btnResetI_clicked();
    void on_btnStop_clicked();
    void on_groupBoxSkok_clicked();
    void on_groupBoxKwad_clicked();
    void on_groupBoxSin_clicked();
    void on_btnZapisz_clicked();
    void on_btnARX_clicked();

private:
    Ui::MainWindow *ui;
    DialogARX *dialog = nullptr;
    QTimer* timer = nullptr;
    Symulacja UAR;
    int krok;
    double krok_czas;
    double interwal_wykres_sec;
    QVector<double> graph_x;
    QVector<double> uar_we_y;
    QVector<double> uar_wy_y;
    QVector<double> uchyb_y;
    QVector<double> pid_y;
    QVector<double> p_y;
    QVector<double> i_y;
    QVector<double> d_y;

    double findMinRange(QVector<double> &y_data);
    double findMaxRange(QVector<double> &y_data);
    void setUpGraphs();
    void passToSetters();
    void insertIntoTextField(QLineEdit* field, const std::vector<double> &arx_params);
    void initChartConfig(QCustomPlot *chart, const QString OX_num_format, const int OX_num_precision, const QString OX_label, const QString OY_label);
};

#endif // MAINWINDOW_H
