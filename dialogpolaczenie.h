#ifndef DIALOGPOLACZENIE_H
#define DIALOGPOLACZENIE_H

#include <QDialog>

namespace Ui {
class DialogPolaczenie;
}

class DialogPolaczenie : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPolaczenie(QWidget *parent = nullptr);
    ~DialogPolaczenie();
    int get_trybPolaczenia();
    QString get_ip();
    int get_port();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::DialogPolaczenie *ui;
};

#endif // DIALOGPOLACZENIE_H
