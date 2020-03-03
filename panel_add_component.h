#ifndef PANEL_ADD_COMPONENT_H
#define PANEL_ADD_COMPONENT_H

#include <QDialog>

namespace Ui {
class Panel_add_component;
}

class Panel_add_component : public QDialog
{
    Q_OBJECT

public:
    explicit Panel_add_component(QWidget *parent = 0);
    ~Panel_add_component();

private:
    Ui::Panel_add_component *ui;
};

#endif // PANEL_ADD_COMPONENT_H
