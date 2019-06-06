#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0);
    ~FindDialog();
   //void settext(QString text);
   QString gettext(const QString& value);


private:
    Ui::FindDialog *ui;
private slots:
    void findButtonState();
    void findtext();

    void on_FindpushButton_clicked();
};

#endif // FINDDIALOG_H
