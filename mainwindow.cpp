#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
// #include <iostream>
// #include <numeric>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer{new QTimer(this)}
    , UAR{}
    , krok_wykres{0}
    , arx_a_view{}
    , arx_b_view{}
    , graph_x{}
    , uar_wy_y{}
    , uchyb_y{}
    , pid_y{}
    , p_y{}
    , i_y{}
    , d_y{}
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(advance()));
    // on_spinBoxInterwal_valueChanged(ui->spinBoxInterwal->value());

    ui->graphUAR->xAxis->setNumberFormat("f");
    ui->graphUAR->xAxis->setNumberPrecision(0);
    ui->graphUAR->yAxis->setLabel("Sygnał wejściowy i wyjściowy");
    ui->graphUAR->xAxis->setLabel("Krok");
    ui->graphUAR->yAxis->setRange(0.0, 1.0);
    ui->graphUAR->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());

    ui->graphUchyb->xAxis->setNumberFormat("f");
    ui->graphUchyb->xAxis->setNumberPrecision(0);
    ui->graphUchyb->yAxis->setLabel("Wartość uchybu");
    ui->graphUchyb->xAxis->setLabel("Krok");
    ui->graphUchyb->yAxis->setRange(0.0, 1.0);
    ui->graphUchyb->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());

    ui->graphPidSum->xAxis->setNumberFormat("f");
    ui->graphPidSum->xAxis->setNumberPrecision(0);
    ui->graphPidSum->yAxis->setLabel("Sygnał regulatora PID");
    ui->graphPidSum->xAxis->setLabel("Krok");
    ui->graphPidSum->yAxis->setRange(0.0, 1.0);
    ui->graphPidSum->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());

    ui->graphPID->xAxis->setNumberFormat("f");
    ui->graphPID->xAxis->setNumberPrecision(0);
    ui->graphPID->yAxis->setLabel("Składowe P, I, D");
    ui->graphPID->xAxis->setLabel("Krok");
    ui->graphPID->yAxis->setRange(0.0, 1.0);
    ui->graphPID->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());

    setUpGraphs();
}

MainWindow::~MainWindow()
{
    delete ui;
}


double MainWindow::findMinRange(QVector<double> &y_data) {

    double min = std::numeric_limits<double>::max();

    for (int i = y_data.size()-1; i > std::max({static_cast<int>(y_data.size()-1 - ui->spinBoxWidokKrokow->value()), 0}); i--) {
        if (y_data[i] < min) {
            min = y_data[i];
        }
    }

    return min;
}

double MainWindow::findMaxRange(QVector<double> &y_data) {

    double max = std::numeric_limits<double>::min();

    for (int i = y_data.size()-1; i > std::max({static_cast<int>(y_data.size()-1 - ui->spinBoxWidokKrokow->value()), 0}); i--) {
        if (y_data[i] > max) {
            max = y_data[i];
        }
    }

    return max;
}

void MainWindow::setUpGraphs() {
    ui->graphUAR->addGraph();  // 0 - graf WE
    ui->graphUAR->addGraph(ui->graphUAR->graph(0)->keyAxis(), ui->graphUAR->graph(0)->valueAxis());     // 1 - graf WY
    ui->graphUAR->graph(0)->setAntialiased(true);
    ui->graphUAR->graph(1)->setAntialiased(true);
    ui->graphUAR->xAxis->setRange(std::max({krok_wykres - ui->spinBoxWidokKrokow->value(), 0}), krok_wykres);
    ui->graphUAR->graph(0)->setPen(QPen(QColor(33,0,255), 2));
    ui->graphUAR->graph(1)->setPen(QPen(QColor(255,33,0), 2));
    ui->graphUAR->graph(0)->setName("WE");
    ui->graphUAR->graph(1)->setName("WY");
    ui->graphUAR->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(9);
    ui->graphUAR->legend->setFont(legendFont);
    ui->graphUAR->legend->setBrush(QBrush(QColor(255,255,255,100)));
    ui->graphUAR->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);


    ui->graphUchyb->addGraph();      // 0 - graf Uchyb
    ui->graphUchyb->graph(0)->setAntialiased(true);
    ui->graphUchyb->xAxis->setRange(std::max({krok_wykres - ui->spinBoxWidokKrokow->value(), 0}), krok_wykres);
    ui->graphUchyb->graph(0)->setPen(QPen(QColor(33,0,255), 2));
    ui->graphUchyb->graph(0)->setName("Uchyb");
    ui->graphUchyb->legend->setVisible(true);
    QFont legendFont2 = font();
    legendFont2.setPointSize(7);
    ui->graphUchyb->legend->setFont(legendFont2);
    ui->graphUchyb->legend->setBrush(QBrush(QColor(255,255,255,100)));
    ui->graphUchyb->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);

    ui->graphPidSum->addGraph();      // 0 - graf PID
    ui->graphPidSum->graph(0)->setAntialiased(true);
    ui->graphPidSum->xAxis->setRange(std::max({krok_wykres - ui->spinBoxWidokKrokow->value(), 0}), krok_wykres);
    ui->graphPidSum->graph(0)->setPen(QPen(QColor(33,0,255), 2));
    ui->graphPidSum->graph(0)->setName("PID");
    ui->graphPidSum->legend->setVisible(true);
    ui->graphPidSum->legend->setFont(legendFont2);
    ui->graphPidSum->legend->setBrush(QBrush(QColor(255,255,255,100)));
    ui->graphPidSum->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);

    ui->graphPID->addGraph();      // 0 - graf P
    ui->graphPID->addGraph(ui->graphPID->graph(0)->keyAxis(), ui->graphPID->graph(0)->valueAxis());      // 1 - graf I
    ui->graphPID->addGraph(ui->graphPID->graph(0)->keyAxis(), ui->graphPID->graph(0)->valueAxis());      // 2 - graf D
    ui->graphPID->graph(0)->setAntialiased(true);
    ui->graphPID->graph(1)->setAntialiased(true);
    ui->graphPID->graph(2)->setAntialiased(true);
    ui->graphPID->xAxis->setRange(std::max({krok_wykres - ui->spinBoxWidokKrokow->value(), 0}), krok_wykres);
    ui->graphPID->graph(0)->setPen(QPen(QColor(33,0,255), 2));
    ui->graphPID->graph(1)->setPen(QPen(QColor(255,33,0), 2));
    ui->graphPID->graph(2)->setPen(QPen(QColor(0, 255, 33),2));
    ui->graphPID->graph(0)->setName("P");
    ui->graphPID->graph(1)->setName("I");
    ui->graphPID->graph(2)->setName("D");
    ui->graphPID->legend->setVisible(true);
    ui->graphPID->legend->setFont(legendFont2);
    ui->graphPID->legend->setBrush(QBrush(QColor(255,255,255,100)));
    ui->graphPID->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);
}


// void MainWindow::keyPressEvent(QKeyEvent* event) {
//     switch (event->key()) {
//     case Qt::Key_Enter:
//         passToSetters();
//         break;
//     }
// }

void MainWindow::advance() {

    if (ui->groupBoxSkok->isChecked()) {
        // UAR.liczSygnalSkok(ui->doubleSpinBoxSkokAmp->value(), ui->spinBoxSkokAkt->value());
        UAR.liczSygnalSkok();
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsStepLeft);
        ui->groupBoxKwad->setDisabled(true);
        ui->groupBoxSin->setDisabled(true);

    } else if (ui->groupBoxKwad->isChecked()) {
        // UAR.liczSygnalKwad(ui->doubleSpinBoxKwadAmp->value(), ui->spinBoxKwadAkt->value(), ui->doubleSpinBoxKwadWyp->value());
        UAR.liczSygnalKwad();
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsStepLeft);
        ui->groupBoxSin->setDisabled(true);
        ui->groupBoxSkok->setDisabled(true);

    } else if (ui->groupBoxSin->isChecked()) {
        // UAR.liczSygnalSin(ui->doubleSpinBoxSinAmp->value(), ui->spinBoxSinOkr->value());
        UAR.liczSygnalSin();
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->groupBoxSkok->setDisabled(true);
        ui->groupBoxKwad->setDisabled(true);

    }

    double wy = UAR.symulujKrok();
    // std::cerr << wy << '\n';

    //przypisanie wartości kroku
    uar_wy_y.push_back(wy);
    graph_x.push_back(krok_wykres);
    uar_we_y.push_back(UAR.getSygn());
    uchyb_y.push_back(UAR.getUchyb());
    pid_y.push_back(UAR.getPID_output());
    p_y.push_back(UAR.getPID_P());
    i_y.push_back(UAR.getPID_I());
    d_y.push_back(UAR.getPID_D());
    krok_wykres++;

    //graf WE / WY
    ui->graphUAR->graph(0)->setData(graph_x, uar_we_y);
    ui->graphUAR->graph(1)->setData(graph_x, uar_wy_y);

    //graf uchyb
    ui->graphUchyb->graph(0)->setData(graph_x, uchyb_y);

    //graf pid (sumarycznie)
    ui->graphPidSum->graph(0)->setData(graph_x, pid_y);

    //graf pid (składowe)
    ui->graphPID->graph(0)->setData(graph_x, p_y);
    ui->graphPID->graph(1)->setData(graph_x, i_y);
    ui->graphPID->graph(2)->setData(graph_x, d_y);

    //przesunięcie OX
    if (krok_wykres > ui->spinBoxWidokKrokow->value()){
        ui->graphUAR->xAxis->moveRange(1.0);
        ui->graphUchyb->xAxis->moveRange(1.0);
        ui->graphPidSum->xAxis->moveRange(1.0);
        ui->graphPID->xAxis->moveRange(1.0);
    }

    //wstępne skalowanie
    ui->graphUAR->graph(0)->rescaleValueAxis(false, true);
    ui->graphUchyb->graph(0)->rescaleValueAxis(false, true);
    ui->graphPidSum->graph(0)->rescaleValueAxis(false, true);
    ui->graphPID->graph(0)->rescaleValueAxis(false, true);

    //graf we / wy - skalowanie OY
    double min = findMinRange(uar_we_y);
    double max = findMaxRange(uar_we_y);

    if(min > findMinRange(uar_wy_y))
        min = findMinRange(uar_wy_y);
    if(max < findMaxRange(uar_wy_y))
        max = findMaxRange(uar_wy_y);

    double margin = (max - min) * 0.05;
    ui->graphUAR->yAxis->setRange(min - margin, max + margin);
    ui->graphUAR->replot();

    //graf uchyb - skalowanie OY
    min = findMinRange(uchyb_y);
    max = findMaxRange(uchyb_y);

    margin = (max - min) * 0.05;
    ui->graphUchyb->yAxis->setRange(min - margin, max + margin);
    ui->graphUchyb->replot();

    //graf pid (sumaryczny) - skalowanie OY
    min = findMinRange(pid_y);
    max = findMaxRange(pid_y);

    margin = (max - min) * 0.05;
    ui->graphPidSum->yAxis->setRange(min - margin, max + margin);
    ui->graphPidSum->replot();

    //graf pid (składowe) - skalowanie OY
    min = findMinRange(p_y);
    max = findMaxRange(p_y);

    if(min > findMinRange(i_y))
        min = findMinRange(i_y);
    if(max < findMaxRange(i_y))
        max = findMaxRange(i_y);

    if(min > findMinRange(d_y))
        min = findMinRange(d_y);
    if(max < findMaxRange(d_y))
        max = findMaxRange(d_y);

    margin = (max - min) * 0.05;
    ui->graphPID->yAxis->setRange(min - margin, max + margin);
    ui->graphPID->replot();
}

void MainWindow::passToSetters() {

    if (ui->groupBoxSkok->isChecked()) {
        UAR.setSygnAmp(ui->doubleSpinBoxSkokAmp->value());
        UAR.setSygnOkrAkt(ui->spinBoxSkokAkt->value());
        UAR.setSygnWyp(0.0);

    } else if (ui->groupBoxKwad->isChecked()) {
        UAR.setSygnAmp(ui->doubleSpinBoxKwadAmp->value());
        UAR.setSygnOkrAkt(ui->spinBoxKwadAkt->value());
        UAR.setSygnWyp(ui->doubleSpinBoxKwadWyp->value());

    } else if (ui->groupBoxSin->isChecked()) {
        UAR.setSygnAmp(ui->doubleSpinBoxSinAmp->value());
        UAR.setSygnOkrAkt(ui->spinBoxSinOkr->value());
        UAR.setSygnWyp(0.0);

    }

    UAR.setPID_k(ui->doubleSpinBoxP->value());
    UAR.setPID_tI(ui->doubleSpinBoxI->value());
    UAR.setPID_tD(ui->doubleSpinBoxD->value());
    UAR.setARX_k(ui->spinBoxARX_k->value());

    if (ui->checkBoxARZ_z->isChecked()) {
        UAR.setARX_z(true);
        UAR.setARX_z_val(ui->doubleSpinBoxARX_z->value());
    }
    else {
        UAR.setARX_z(false);
        UAR.setARX_z_val(0.0);
    }

    timer->setInterval(ui->spinBoxInterwal->value());

    if (krok_wykres <= ui->spinBoxWidokKrokow->value()) {
        ui->graphUAR->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());
        ui->graphUchyb->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());
        ui->graphPidSum->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());
        ui->graphPID->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());
    }
    else {
        ui->graphUAR->xAxis->setRange(krok_wykres - ui->spinBoxWidokKrokow->value(), krok_wykres);
        ui->graphUchyb->xAxis->setRange(krok_wykres - ui->spinBoxWidokKrokow->value(), krok_wykres);
        ui->graphPidSum->xAxis->setRange(krok_wykres - ui->spinBoxWidokKrokow->value(), krok_wykres);
        ui->graphPID->xAxis->setRange(krok_wykres - ui->spinBoxWidokKrokow->value(), krok_wykres);
    }
}

void MainWindow::on_btnStart_clicked()
{
    ui->btnStop->setEnabled(true);
    ui->btnStart->setEnabled(false);
    ui->btnReset->setEnabled(false);
    ui->labelStatus->setText("Włączona");

    // UAR.setPID_k(ui->doubleSpinBoxP->value());
    // UAR.setPID_tI(ui->doubleSpinBoxI->value());
    // UAR.setPID_tD(ui->doubleSpinBoxD->value());
    // UAR.setARX_k(ui->spinBoxARX_k->value());
    // UAR.setARX_z(ui->checkBoxARZ_z->isChecked());
    // UAR.setARX_z_val(ui->doubleSpinBoxARX_z->value());

    this->passToSetters();

    timer->start();
}

void MainWindow::on_groupBoxKwad_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxSin->setChecked(false);
        ui->groupBoxSkok->setChecked(false);
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsStepRight);     // linia równoległa do OY przy skoku
    }
}

void MainWindow::on_groupBoxSin_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxKwad->setChecked(false);
        ui->groupBoxSkok->setChecked(false);
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsLine);     // linia bezpośrednio pomiędzzy punktami
    }
}

void MainWindow::on_groupBoxSkok_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxKwad->setChecked(false);
        ui->groupBoxSin->setChecked(false);
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsStepRight);     // linia równoległa do OY przy skoku
    }
}

void MainWindow::on_btnARXAdd_A_clicked()
{
    if (arx_a_view.size() == 1 && arx_a_view.at(0) == 0.0) {
        UAR.clearARX_a();
        arx_a_view.clear();
    }

    UAR.addARX_a(ui->doubleSpinBoxARX_A->value());
    arx_a_view.push_back(ui->doubleSpinBoxARX_A->value());

    ui->lineEditARXView_A->clear();
    ui->lineEditARXView_A->insert("{ ");
    for(const double &a : arx_a_view) {
        ui->lineEditARXView_A->insert(QString::number(a));
        ui->lineEditARXView_A->insert("; ");
    }
    ui->lineEditARXView_A->insert("}");
}

void MainWindow::on_btnARXAdd_B_clicked()
{
    if (arx_b_view.size() == 1 && arx_b_view.at(0) == 0.0) {
        UAR.clearARX_b();
        arx_b_view.clear();
    }

    UAR.addARX_b(ui->doubleSpinBoxARX_B->value());
    arx_b_view.push_back(ui->doubleSpinBoxARX_B->value());

    ui->lineEditARXView_B->clear();
    ui->lineEditARXView_B->insert("{ ");
    for(const double &b : arx_b_view) {
        ui->lineEditARXView_B->insert(QString::number(b));
        ui->lineEditARXView_B->insert("; ");
    }
    ui->lineEditARXView_B->insert("}");
}

void MainWindow::on_btnARXClear_A_clicked()
{
    UAR.clearARX_a();
    arx_a_view.clear();
    UAR.addARX_a(0.0);
    arx_a_view.push_back(0.0);
    ui->lineEditARXView_A->setText("{ 0.0 }");
    ui->doubleSpinBoxARX_A->setValue(0.0);
}

void MainWindow::on_btnARXClear_B_clicked()
{
    UAR.clearARX_b();
    arx_b_view.clear();
    UAR.addARX_b(0.0);
    arx_b_view.push_back(0.0);
    ui->lineEditARXView_B->setText("{ 0.0 }");
    ui->doubleSpinBoxARX_B->setValue(0.0);
}

void MainWindow::on_btnReset_clicked()
{   
    UAR.setPID_k(0.0);
    UAR.setPID_tI(0.0);
    UAR.setPID_tD(0.0);
    UAR.resetPID_I();
    UAR.resetPID_D();
    UAR.clearARX_a();
    UAR.clearARX_b();
    UAR.setARX_k(1);
    UAR.setARX_z(true);
    UAR.clearARXBuffers();
    UAR.resetInternalKrok();
    UAR.resetUchyb();
    krok_wykres = 0;

    ui->labelStatus->setText("Wyłączona");

    ui->groupBoxSkok->setChecked(true);
    ui->groupBoxSin->setChecked(false);
    ui->groupBoxKwad->setChecked(false);
    ui->spinBoxSkokAkt->setValue(1);
    ui->doubleSpinBoxSkokAmp->setValue(1.0);
    ui->doubleSpinBoxSinAmp->setValue(1.0);
    ui->spinBoxSinOkr->setValue(10);
    ui->spinBoxKwadAkt->setValue(10);
    ui->doubleSpinBoxKwadAmp->setValue(1.0);
    ui->doubleSpinBoxKwadWyp->setValue(0.5);

    ui->doubleSpinBoxP->setValue(0.3);
    ui->doubleSpinBoxI->setValue(6.0);
    ui->doubleSpinBoxD->setValue(0.0);

    on_btnARXClear_A_clicked();
    on_btnARXClear_B_clicked();
    ui->doubleSpinBoxARX_A->setValue(-0.4);
    ui->doubleSpinBoxARX_B->setValue(0.6);
    ui->spinBoxARX_k->setValue(1);
    ui->checkBoxARZ_z->setCheckState(Qt::Unchecked);
    ui->doubleSpinBoxARX_z->setValue(0.0);
    // ui->lineEditARXView_A->clear();
    // ui->lineEditARXView_B->clear();
    // arx_a_view.clear();
    // arx_b_view.clear();

    ui->spinBoxInterwal->setValue(100);
    ui->spinBoxWidokKrokow->setValue(200);

    ui->graphUAR->clearGraphs();
    uar_we_y.clear();
    uar_wy_y.clear();
    graph_x.clear();
    ui->graphUAR->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());

    ui->graphUchyb->clearGraphs();
    uchyb_y.clear();
    ui->graphUchyb->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());

    ui->graphPidSum->clearGraphs();
    pid_y.clear();
    ui->graphPidSum->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());

    ui->graphPID->clearGraphs();
    p_y.clear();
    i_y.clear();
    d_y.clear();
    ui->graphPID->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value());

    setUpGraphs();
}

void MainWindow::on_btnResetD_clicked()
{
    UAR.resetPID_D();
}

void MainWindow::on_btnResetI_clicked()
{
    UAR.resetPID_I();
}

void MainWindow::on_btnStop_clicked()
{
    timer->stop();
    ui->btnStop->setEnabled(false);
    ui->btnStart->setEnabled(true);
    ui->btnReset->setEnabled(true);
    ui->labelStatus->setText("Zatrzymana");
    ui->groupBoxSkok->setDisabled(false);
    ui->groupBoxKwad->setDisabled(false);
    ui->groupBoxSin->setDisabled(false);
}

// void MainWindow::on_spinBoxInterwal_valueChanged(int arg1)
// {
//     timer->setInterval(arg1);
// }

// void MainWindow::on_spinBoxWidokKrokow_valueChanged(int arg1)
// {
//     if (krok_wykres <= ui->spinBoxWidokKrokow->value()) {
//         ui->graphUAR->xAxis->setRange(0.0, arg1);
//         ui->graphUchyb->xAxis->setRange(0.0, arg1);
//         ui->graphPidSum->xAxis->setRange(0.0, arg1);
//         ui->graphPID->xAxis->setRange(0.0, arg1);
//     }
//     else {
//         ui->graphUAR->xAxis->setRange(krok_wykres - arg1, krok_wykres);
//         ui->graphUchyb->xAxis->setRange(krok_wykres - arg1, krok_wykres);
//         ui->graphPidSum->xAxis->setRange(krok_wykres - arg1, krok_wykres);
//         ui->graphPID->xAxis->setRange(krok_wykres - arg1, krok_wykres);
//     }
// }


// void MainWindow::on_doubleSpinBoxP_valueChanged(double arg1)
// {
//     UAR.setPID_k(arg1);
// }


// void MainWindow::on_doubleSpinBoxI_valueChanged(double arg1)
// {
//     UAR.setPID_tI(arg1);
// }


// void MainWindow::on_doubleSpinBoxD_valueChanged(double arg1)
// {
//     UAR.setPID_tD(arg1);
// }


// void MainWindow::on_spinBoxARX_k_valueChanged(int arg1)
// {
//     UAR.setARX_k(arg1);
// }


void MainWindow::on_checkBoxARZ_z_checkStateChanged(const Qt::CheckState &arg1)
{
    if(arg1 == Qt::Checked){
        UAR.setARX_z(true);
        ui->doubleSpinBoxARX_z->setDisabled(false);
    }
    else {
        UAR.setARX_z(false);
        ui->doubleSpinBoxARX_z->setDisabled(true);
    }
}


void MainWindow::on_groupBoxSkok_clicked()
{
    // zapobieganie odkliknięciu checkboxa

    if (!ui->groupBoxSkok->isChecked()) {
        ui->groupBoxSkok->setChecked(true);
    }
}


void MainWindow::on_groupBoxKwad_clicked()
{
    // zapobieganie odkliknięciu checkboxa

    if (!ui->groupBoxKwad->isChecked()) {
        ui->groupBoxKwad->setChecked(true);
    }
}


void MainWindow::on_groupBoxSin_clicked()
{
    // zapobieganie odkliknięciu checkboxa

    if (!ui->groupBoxSin->isChecked()) {
        ui->groupBoxSin->setChecked(true);
    }
}


// void MainWindow::on_doubleSpinBox_z_valueChanged(double arg1)
// {
//     UAR.setARX_z_val(arg1);
// }


void MainWindow::on_btnZapisz_clicked()
{
    passToSetters();


}

