#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qcustomplot.h"
// #include <iostream>
// #include <numeric>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTcpServer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer{new QTimer(this)}
    , UAR{}
    , krok{0}
    , krok_czas{0.0}
    , interwal_wykres_sec{0.0}
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
    //m_kontrola_polaczenia.setTimer(timer);

    on_btnReset_clicked();

    initChartConfig(ui->graphUAR, "f", 1, "Czas, s", "Sygnał zadany i sterowany");
    initChartConfig(ui->graphUchyb, "f", 1, "Czas, s", "Uchyb");
    initChartConfig(ui->graphPidSum, "f", 1, "Czas, s", "Sygnał regulatora PID");
    initChartConfig(ui->graphPID, "f", 1, "Czas, s", "Składowe P, I, D");

    // Łączenie slotów kontrolera połączeń
    connect(&m_kontrola_polaczenia, &KontrolaPolaczenia::connected, this, &MainWindow::kontrola_connected);
    connect(&m_kontrola_polaczenia, &KontrolaPolaczenia::disconnected, this, &MainWindow::kontrola_disconnected);
    connect(&m_kontrola_polaczenia, &KontrolaPolaczenia::stateChanged, this, &MainWindow::kontrola_stateChanged);
    connect(&m_kontrola_polaczenia, &KontrolaPolaczenia::errorOccurred, this, &MainWindow::kontrola_errorOccurred);
    connect(&m_kontrola_polaczenia, &KontrolaPolaczenia::newClientConnected, this, &MainWindow::on_newClientConnected);

    connect(&m_kontrola_polaczenia, &KontrolaPolaczenia::dataRecived, this, &MainWindow::on_dataRecived);

    ui->bttRozlacz->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::advance() {
    //qDebug() << "Mia";
    double wy;
    if (m_kontrola_polaczenia.getIsClient()) {
        // Tutaj wykonanieobliczeń dla pojedynczego elementu z buforu
        QList<QByteArray> wartosc_do_parsowania = bufor_sieciowy.front();
        bufor_sieciowy.pop_front();

        /*UAR.setSygnStala()

        UAR.setPID_k(wartosc_do_parsowania[4].toDouble());
        UAR.setPID_tD(wartosc_do_parsowania[5].toDouble());
        UAR.setPID_tI(wartosc_do_parsowania[6].toDouble());

        if (ui->groupBoxSkok->isChecked()) {
            UAR.liczSygnalSkok();

        } else if (ui->groupBoxKwad->isChecked()) {
            UAR.liczSygnalKwad();

        } else if (ui->groupBoxSin->isChecked()) {
            UAR.liczSygnalSin();
        }

        // double wy; // jest zadeklarowane wyżej

        if (ui->radioStalaOut->isChecked())
            wy = UAR.symulujKrok_IConstOut();
        else
            wy = UAR.symulujKrok_IConstIn();*/

        // wy = 0.0;
        //if(wartosc_do_parsowania.size() > 0){

        // wy = wartosc_do_parsowania[0].toDouble();


        //qDebug() <<"wy: "<<wy;
        double siec_getSyg = wartosc_do_parsowania[1].toDouble();
        double siec_uchyb = wartosc_do_parsowania[2].toDouble();
        double siec_pid = wartosc_do_parsowania[3].toDouble();
        double siec_p = wartosc_do_parsowania[4].toDouble();
        double siec_i = wartosc_do_parsowania[5].toDouble();
        double siec_d = wartosc_do_parsowania[6].toDouble();
        //wy = 0.0;

        if (ui->radioStalaOut->isChecked())
            wy = UAR.symulujKrok_IConstOut(true, siec_pid);
        else
            wy = UAR.symulujKrok_IConstIn(true, siec_pid);

        graph_x.push_back(krok_czas);
        uar_wy_y.push_back(wy);
        uar_we_y.push_back(siec_getSyg);
        uchyb_y.push_back(siec_uchyb);
        pid_y.push_back(siec_pid);
        p_y.push_back(siec_p);
        i_y.push_back(siec_i);
        d_y.push_back(siec_d);


    }
    if (!m_kontrola_polaczenia.getIsClient()) {
        if (ui->groupBoxSkok->isChecked()) {
            UAR.liczSygnalSkok();

        } else if (ui->groupBoxKwad->isChecked()) {
            UAR.liczSygnalKwad();

        } else if (ui->groupBoxSin->isChecked()) {
            UAR.liczSygnalSin();
        }

        // double wy; // jest zadeklarowane wyżej

        if (ui->radioStalaOut->isChecked())
            wy = UAR.symulujKrok_IConstOut();
        else
            wy = UAR.symulujKrok_IConstIn();

        if(m_kontrola_polaczenia.get_server_started()){
            QByteArray dane = QByteArray::number(wy);
            dane +=";";
            dane += QByteArray::number(UAR.getSygn());
            dane +=";";
            dane += QByteArray::number(UAR.getUchyb());
            dane +=";";
            dane += QByteArray::number(UAR.getPID_output());
            dane +=";";
            dane += QByteArray::number(UAR.getPID_P());
            dane +=";";
            dane += QByteArray::number(UAR.getPID_I());
            dane +=";";
            dane += QByteArray::number(UAR.getPID_D());
            //dane +=";";
            //dane += QByteArray::number(UAR)

            m_kontrola_polaczenia.wyslijDoKlientow(dane);
        }
    }
    // std::cerr << wy << '\n';

    //przypisanie wartości kroku
    if(!m_kontrola_polaczenia.getIsClient()){
        graph_x.push_back(krok_czas);
        uar_wy_y.push_back(wy);
        uar_we_y.push_back(UAR.getSygn());
        uchyb_y.push_back(UAR.getUchyb());
        pid_y.push_back(UAR.getPID_output());
        p_y.push_back(UAR.getPID_P());
        i_y.push_back(UAR.getPID_I());
        d_y.push_back(UAR.getPID_D());
    }
    // qDebug() << "START\n" << graph_x.size();
    // qDebug() << uar_wy_y.size();
    // qDebug() << uar_we_y.size();
    // qDebug() << uchyb_y.size();
    // qDebug() << pid_y.size();
    // qDebug() << p_y.size();
    // qDebug() << i_y.size();
    // qDebug() << d_y.size() << "\nEND\n";

    if (graph_x.size() > 100000) {
        graph_x.pop_front();
        uar_wy_y.pop_front();
        uar_we_y.pop_front();
        uchyb_y.pop_front();
        pid_y.pop_front();
        p_y.pop_front();
        i_y.pop_front();
        d_y.pop_front();
    }

    krok++;
    krok_czas += interwal_wykres_sec;

    //graf WE / WY
    ui->graphUAR->graph(0)->setData(graph_x, uar_we_y);
    ui->graphUAR->graph(1)->setData(graph_x, uar_wy_y);
    // ui->graphUAR->graph(0)->addData(krok_czas, UAR.getSygn());
    // ui->graphUAR->graph(1)->addData(krok_czas, wy);

    //graf uchyb
    ui->graphUchyb->graph(0)->setData(graph_x, uchyb_y);
    // ui->graphUchyb->graph(0)->addData(krok_czas, UAR.getUchyb());

    //graf pid (sumarycznie)
    ui->graphPidSum->graph(0)->setData(graph_x, pid_y);
    // ui->graphPidSum->graph(0)->addData(krok_czas, UAR.getPID_output());

    //graf pid (składowe)
    ui->graphPID->graph(0)->setData(graph_x, p_y);
    ui->graphPID->graph(1)->setData(graph_x, i_y);
    ui->graphPID->graph(2)->setData(graph_x, d_y);
    // ui->graphPID->graph(0)->addData(krok_czas, UAR.getPID_P());
    // ui->graphPID->graph(1)->addData(krok_czas, UAR.getPID_I());
    // ui->graphPID->graph(2)->addData(krok_czas, UAR.getPID_D());

    //przesunięcie OX
    // if (krok_czas > ui->spinBoxWidokKrokow->value() * interwal_wykres_sec){
    //     //ui->graphUAR->xAxis->moveRange(interwal_wykres_sec);
    //     ui->graphUchyb->xAxis->moveRange(interwal_wykres_sec);
    //     ui->graphPidSum->xAxis->moveRange(interwal_wykres_sec);
    //     ui->graphPID->xAxis->moveRange(interwal_wykres_sec);
    // }

    double a = ui->spinBoxWidokKrokow->value();
    if(krok > a){
        ui->graphUAR->xAxis->setRange(graph_x[krok - a], graph_x.last());
        ui->graphUchyb->xAxis->setRange(graph_x[krok - a], graph_x.last());
        ui->graphPidSum->xAxis->setRange(graph_x[krok - a], graph_x.last());
        ui->graphPID->xAxis->setRange(graph_x[krok - a], graph_x.last());
    }
    else{
        ui->graphUAR->xAxis->setRange(0, interwal_wykres_sec * (a - krok) + krok_czas);
        ui->graphUchyb->xAxis->setRange(0, interwal_wykres_sec * (a - krok) + krok_czas);
        ui->graphPidSum->xAxis->setRange(0, interwal_wykres_sec * (a - krok) + krok_czas);
        ui->graphPID->xAxis->setRange(0, interwal_wykres_sec * (a - krok) + krok_czas);
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

    ui->graphUAR->replot();
    ui->graphUchyb->replot();
    ui->graphPidSum->replot();
    ui->graphPID->replot();
    if (m_kontrola_polaczenia.getIsClient() && bufor_sieciowy.size() > 0) {
        advance();
    }
}

void MainWindow::on_btnStart_clicked()
{
    ui->btnStop->setEnabled(true);
    ui->btnStart->setEnabled(false);
    ui->btnReset->setEnabled(false);
    ui->labelStatus->setText("Włączona");

    this->passToSetters();

    timer->start();
}

void MainWindow::on_groupBoxKwad_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxSin->setChecked(false);
        ui->groupBoxSkok->setChecked(false);
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsStepRight);     // linia równoległa do OY przy skoku
        on_btnZapisz_clicked();
    }
}

void MainWindow::on_groupBoxSin_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxKwad->setChecked(false);
        ui->groupBoxSkok->setChecked(false);
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsLine);     // linia bezpośrednio pomiędzzy punktami
        on_btnZapisz_clicked();
    }
}

void MainWindow::on_groupBoxSkok_toggled(bool arg1)
{
    if(arg1) {
        ui->groupBoxKwad->setChecked(false);
        ui->groupBoxSin->setChecked(false);
        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsStepRight);     // linia równoległa do OY przy skoku
        on_btnZapisz_clicked();
    }
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
    UAR.addARX_a(-0.4);
    UAR.addARX_b(0.6);
    UAR.setARX_k(1);
    UAR.setARX_z(false);
    UAR.setARX_z_val(0.0);
    UAR.clearARXBuffers();

    UAR.resetInternalKrok();
    UAR.resetUchyb();
    krok = 0;
    krok_czas = 0.0;

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

    insertIntoTextField(ui->lineEditARXView_A, UAR.getARX_a_vector());
    insertIntoTextField(ui->lineEditARXView_B, UAR.getARX_b_vector());
    ui->spinBoxARX_k->setValue(UAR.getARX_k());
    ui->doubleSpinBoxARX_z->setValue(UAR.getARX_z_std_dev());

    ui->spinBoxInterwal->setValue(100);
    ui->spinBoxWidokKrokow->setValue(200);
    interwal_wykres_sec = ui->spinBoxInterwal->value() / 1000.0;

    ui->graphUAR->clearGraphs();
    uar_we_y.clear();
    uar_wy_y.clear();
    graph_x.clear();
    ui->graphUAR->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value() * interwal_wykres_sec);

    ui->graphUchyb->clearGraphs();
    uchyb_y.clear();
    ui->graphUchyb->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value() * interwal_wykres_sec);

    ui->graphPidSum->clearGraphs();
    pid_y.clear();
    ui->graphPidSum->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value() * interwal_wykres_sec);

    ui->graphPID->clearGraphs();
    p_y.clear();
    i_y.clear();
    d_y.clear();
    ui->graphPID->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value() * interwal_wykres_sec);

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

void MainWindow::on_btnZapisz_clicked()
{
    passToSetters();
}

void MainWindow::on_btnARX_clicked()
{
    ui->btnARX->setDisabled(true);

    DataDialog data;
    data.a = UAR.getARX_a_vector();
    data.b = UAR.getARX_b_vector();
    data.delay = UAR.getARX_k();
    data.czyZakl = UAR.getARX_isZ();
    data.zakl_std_dev = UAR.getARX_z_std_dev();

    dialog = new DialogARX(data, this);

    if (dialog->exec())
    {
        UAR.clearARX_a();
        UAR.clearARX_b();

        for (const auto &_a : data.a) {
            UAR.addARX_a(_a);
        }

        for (const auto &_b : data.b) {
            UAR.addARX_b(_b);
        }

        UAR.setARX_k(data.delay);
        UAR.setARX_z(data.czyZakl);
        UAR.setARX_z_val(data.zakl_std_dev);

        insertIntoTextField(ui->lineEditARXView_A, data.a);
        insertIntoTextField(ui->lineEditARXView_B, data.b);
        ui->spinBoxARX_k->setValue(data.delay);
        ui->doubleSpinBoxARX_z->setValue(data.zakl_std_dev);
    }

    ui->btnARX->setDisabled(false);

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
    // if (graph_x.size()-1 - ui->spinBoxWidokKrokow->value() >= 0)
    //     ui->graphUAR->xAxis->setRange(krok_czas - graph_x.at(graph_x.size()-1 - ui->spinBoxWidokKrokow->value()), krok_czas);
    // else
    ui->graphUAR->xAxis->setRange(0.0, krok_czas);
    ui->graphUAR->graph(0)->setPen(QPen(QColor(33,0,255), 2));
    ui->graphUAR->graph(1)->setPen(QPen(QColor(255,33,0), 2));
    ui->graphUAR->graph(0)->setName("W. zadana");
    ui->graphUAR->graph(1)->setName("W. regulowana");
    ui->graphUAR->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(9);
    ui->graphUAR->legend->setFont(legendFont);
    ui->graphUAR->legend->setBrush(QBrush(QColor(255,255,255,100)));
    ui->graphUAR->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignLeft);


    ui->graphUchyb->addGraph();      // 0 - graf Uchyb
    ui->graphUchyb->graph(0)->setAntialiased(true);
    // if (graph_x.size()-1 - ui->spinBoxWidokKrokow->value() >= 0)
    //     ui->graphUAR->xAxis->setRange(krok_czas - graph_x.at(graph_x.size()-1 - ui->spinBoxWidokKrokow->value()), krok_czas);
    // else
    ui->graphUAR->xAxis->setRange(0.0, krok_czas);
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
    // if (graph_x.size()-1 - ui->spinBoxWidokKrokow->value() >= 0)
    //     ui->graphUAR->xAxis->setRange(krok_czas - graph_x.at(graph_x.size()-1 - ui->spinBoxWidokKrokow->value()), krok_czas);
    // else
    ui->graphUAR->xAxis->setRange(0.0, krok_czas);
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
    // if (graph_x.size()-1 - ui->spinBoxWidokKrokow->value() >= 0)
    //     ui->graphUAR->xAxis->setRange(krok_czas - graph_x.at(graph_x.size()-1 - ui->spinBoxWidokKrokow->value()), krok_czas);
    // else
    ui->graphUAR->xAxis->setRange(0.0, krok_czas);
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

void MainWindow::keyPressEvent(QKeyEvent* event) {

    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
        on_btnZapisz_clicked();
}

void MainWindow::passToSetters() {

    if (ui->groupBoxSkok->isChecked() && !m_kontrola_polaczenia.getIsClient()) {
        UAR.setSygnAmp(ui->doubleSpinBoxSkokAmp->value());
        UAR.setSygnOkrAkt(ui->spinBoxSkokAkt->value());
        UAR.setSygnWyp(0.0);
        UAR.setSygnStala(0.0);

        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsStepLeft);
        ui->groupBoxKwad->setChecked(false);
        ui->groupBoxSin->setChecked(false);

    } else if (ui->groupBoxKwad->isChecked() && !m_kontrola_polaczenia.getIsClient()) {
        UAR.setSygnAmp(ui->doubleSpinBoxKwadAmp->value());
        UAR.setSygnOkrAkt(ui->spinBoxKwadAkt->value());
        UAR.setSygnWyp(ui->doubleSpinBoxKwadWyp->value());
        UAR.setSygnStala(ui->doubleSpinBoxKwadStala->value());

        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsStepLeft);
        ui->groupBoxSin->setChecked(false);
        ui->groupBoxSkok->setChecked(false);

    } else if (ui->groupBoxSin->isChecked() && !m_kontrola_polaczenia.getIsClient()) {
        UAR.setSygnAmp(ui->doubleSpinBoxSinAmp->value());
        UAR.setSygnOkrAkt(ui->spinBoxSinOkr->value());
        UAR.setSygnWyp(0.0);
        UAR.setSygnStala(ui->doubleSpinBoxSinStala->value());

        ui->graphUAR->graph(0)->setLineStyle(QCPGraph::lsLine);
        ui->groupBoxSkok->setChecked(false);
        ui->groupBoxKwad->setChecked(false);

    }

    if(!m_kontrola_polaczenia.getIsClient()){
        UAR.setPID_k(ui->doubleSpinBoxP->value());
        UAR.setPID_tI(ui->doubleSpinBoxI->value());
        UAR.setPID_tD(ui->doubleSpinBoxD->value());
    }
    timer->setInterval(ui->spinBoxInterwal->value());
    interwal_wykres_sec = ui->spinBoxInterwal->value() / 1000.0;

    if (krok_czas <= ui->spinBoxWidokKrokow->value() * interwal_wykres_sec ) {
        ui->graphUAR->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value() * interwal_wykres_sec);
        ui->graphUchyb->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value() * interwal_wykres_sec);
        ui->graphPidSum->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value() * interwal_wykres_sec);
        ui->graphPID->xAxis->setRange(0.0, ui->spinBoxWidokKrokow->value() * interwal_wykres_sec);
    }
    else {
        ui->graphUAR->xAxis->setRange(krok_czas - ui->spinBoxWidokKrokow->value() * interwal_wykres_sec, krok_czas);
        ui->graphUchyb->xAxis->setRange(krok_czas - ui->spinBoxWidokKrokow->value() * interwal_wykres_sec, krok_czas);
        ui->graphPidSum->xAxis->setRange(krok_czas - ui->spinBoxWidokKrokow->value() * interwal_wykres_sec, krok_czas);
        ui->graphPID->xAxis->setRange(krok_czas - ui->spinBoxWidokKrokow->value() * interwal_wykres_sec, krok_czas);
    }
}

void MainWindow::insertIntoTextField(QLineEdit* field, const std::vector<double> &arx_params)
{
    field->clear();
    field->insert("{ ");
    for (const auto &p : arx_params) {
        field->insert(QString::number(p) + "; ");
    }
    field->insert("}");
}

void MainWindow::initChartConfig(QCustomPlot *chart, const QString OX_num_format, const int OX_num_precision, const QString OX_label, const QString OY_label)
{
    chart->xAxis->setNumberFormat(OX_num_format);
    chart->xAxis->setNumberPrecision(OX_num_precision);
    chart->yAxis->setLabel(OY_label);
    chart->xAxis->setLabel(OX_label);
}


void MainWindow::on_radioStalaOut_toggled(bool checked)
{
    UAR.setPID_adjust_mem_on_change(checked);
}


void MainWindow::on_btnPolacz_clicked()
{
    // Dialog do łączności
    dialog_polaczenie = new DialogPolaczenie();
    if (dialog_polaczenie->exec())
    {
        // Ogarnianie spraw odnośnie połączenia...
        switch (dialog_polaczenie->get_trybPolaczenia())
        {
        case 0:
            // Użytkownik chce być hostem/serwerem
            {
                m_kontrola_polaczenia.hostuj(dialog_polaczenie->get_port());
                if (m_kontrola_polaczenia.get_server_started())
                {
                    ui->statusPolaczenia->setText("Włączono server.");
                    //ui->bttRozlacz->setDisabled(false);

                    ui->pageARX->setDisabled(true);
                }
                else
                {
                    ui->statusPolaczenia->setText("Nie udało się\nwłączyć servera");
                }
                break;
            }
        case 1:
            // Użytkownik chce być klientem
            {
                QHostAddress adres(dialog_polaczenie->get_ip());
                if (adres.protocol() == QAbstractSocket::IPv4Protocol)
                {
                    // Działamy na czymś co jest prawidłowym adresem IPv4
                    ui->statusPolaczenia->setText("Łączę się z\n" + dialog_polaczenie->get_ip());
                    m_kontrola_polaczenia.polacz_z_urzadzeniem(dialog_polaczenie->get_ip(), dialog_polaczenie->get_port());
                    m_kontrola_polaczenia.set_ip(dialog_polaczenie->get_ip());
                    ui->pageARX->setDisabled(false);
                }
                else
                {
                    //Użytkownik bredzi w inpucie adresu
                    ui->statusPolaczenia->setText("Połączenie nieudane.\nWprowadzono\nnieprawidłowe IP.");
                }
                break;
            }
        default:
            // Użytkownik schrzanił użycie prostego dialogu
            ui->statusPolaczenia->setText("Połączenie nieudane.\nWprowadzono błędny\ntryb połączenia.");
            break;
        }
    }
    // Czyszczenie klasy dialogu łączności
    if (dialog_polaczenie != nullptr) delete dialog_polaczenie;
}

void MainWindow::kontrola_connected()
{
    ui->statusPolaczenia->setText("Połączenie udane.\nPołączono z\n" + m_kontrola_polaczenia.get_ip());
    ui->bttRozlacz->setDisabled(false);
    m_kontrola_polaczenia.set_client(true);

    ui->pagePID->setEnabled(false);
    ui->pageSygnaly->setEnabled(false);
    ui->pageSymulacja->setEnabled(false);
    ui->pageARX->setDisabled(false);

    ui->btnStart->setDisabled(true);
    ui->btnReset->setDisabled(true);
    ui->btnStop->setDisabled(true);
}

void MainWindow::kontrola_disconnected()
{
    ui->statusPolaczenia->setText("Połączenie\nzakończone.\nRozołączono z\n" + m_kontrola_polaczenia.get_ip());
    ui->bttRozlacz->setDisabled(true);
    m_kontrola_polaczenia.set_client(false);

    ui->pagePID->setEnabled(true);
    ui->pageSygnaly->setEnabled(true);
    ui->pageSymulacja->setEnabled(true);

    ui->pageARX->setEnabled(true);

    ui->btnStart->setDisabled(false);
    ui->btnReset->setDisabled(false);
    ui->btnStop->setDisabled(false);
}

void MainWindow::kontrola_stateChanged(QAbstractSocket::SocketState state)
{
    if (state == QAbstractSocket::UnconnectedState)
    {
        m_kontrola_polaczenia.rozlacz();
        ui->bttRozlacz->setDisabled(true);
    }
}

void MainWindow::kontrola_errorOccurred(QAbstractSocket::SocketError error)
{
    ui->statusPolaczenia->setText("Błąd połączenia:\n" + QString::number(error));
}

void MainWindow::on_newClientConnected(QTcpSocket *socket_klienta)
{
    // Obsłużyć połączenie z nowym klientem jak już będzie po co
    ui->statusPolaczenia->setText("Wykryto połączeni\n noewgo klienta\nz serverem " + QString(socket_klienta->peerAddress().toString()));
}

void MainWindow::on_bttRozlacz_clicked()
{
    m_kontrola_polaczenia.rozlacz();
    ui->bttRozlacz->setDisabled(true);
}

void MainWindow::on_dataRecived(const QByteArray &dane){
    //qDebug("siem
    QList<QByteArray> pola = dane.split(';');
    bufor_sieciowy.push_back(pola);
    advance();
}
