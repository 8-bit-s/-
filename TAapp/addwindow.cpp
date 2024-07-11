#include "addwindow.h"
#include "ui_addwindow.h"

AddWindow::AddWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AddWindow)
{
    ui->setupUi(this);
}

AddWindow::~AddWindow()
{
    delete ui;
}

void AddWindow::on_addBtn_clicked()
{
    emit add(ui->CityLable->text());
    this->close();
}
