#include "panel_add_component.h"
#include "ui_panel_add_component.h"

Panel_add_component::Panel_add_component(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Panel_add_component)
{
    ui->setupUi(this);
}

Panel_add_component::~Panel_add_component()
{
    delete ui;
}
