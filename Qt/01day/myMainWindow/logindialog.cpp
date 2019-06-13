#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    ui->usrLineEdit->setFocus();
}

loginDialog::~loginDialog()
{
    delete ui;
}

void loginDialog::on_loginButton_clicked()
{

    if(ui->usrLineEdit->text().trimmed()== tr("z") &&
            ui->pwdLineEdit->text() == tr("z"))
    {
        accept();
    }
    else{
        QMessageBox::warning(this, tr("warning"),
                             tr("usr name or password error!"),
                             QMessageBox::Yes);

        ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->usrLineEdit->setFocus();
    }

}
