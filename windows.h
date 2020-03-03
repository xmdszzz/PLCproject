#ifndef WINDOWS_H
#define WINDOWS_H

#include <QDialog>

namespace Ui {
class windows;
}

class windows : public QDialog
{
    Q_OBJECT

public:
    explicit windows(QWidget *parent = 0);
    ~windows();

    void ui_label_2();


private slots:
    void on_pushButton_open_clicked();

    void on_pushButton_close_2_clicked();


private:
    Ui::windows *ui;
};

#endif // WINDOWS_H
