#include "finddialog.h"
#include "ui_finddialog.h"
#include "mainwindow.h"
#include <QDebug>
FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("请输入你要查找的内容");
    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(findButtonState()));

   // connect(ui->FindpushButton, SIGNAL(triggered()),this,SLOT(findtext()));
   // connect(ui->FindpushButton, &QPushButton::clicked, this, &FindDialog::findtext);
}

FindDialog::~FindDialog()
{
    delete ui;
}

void FindDialog::findButtonState()
{
    if(ui->lineEdit->text().isEmpty())
    {
        ui->FindpushButton->setEnabled(false);
    }
    else
        ui->FindpushButton->setEnabled(true);
}

void FindDialog::findtext()
{
     QString finddialogtext;
     finddialogtext = ui->lineEdit->text();
     qDebug()<<"正在查找"+finddialogtext;
}

/*void FindDialog::settext(QString text)
{
    text =settext(value);
}*/

QString FindDialog::gettext(const QString& value)
{
    return ui->lineEdit->text();
}

void FindDialog::on_FindpushButton_clicked()
{
    QString finddialogtext;
    finddialogtext = ui->lineEdit->text();
    qDebug()<<"正在查找"+finddialogtext;
}
