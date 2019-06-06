#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include "finddialog.h"
#include <QFontDialog>
#include <QColorDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    void setCurrentFile(const QString &fileName);
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void readSettings();
    void writeSettings();

     QString curFile;
     
public:
    explicit MainWindow(QWidget *parent = 0);
     void search(QString text);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    FindDialog find_dialog;

    //QAction *green;

private slots:
void about();
void newFile();
void open();
bool saveAs();
bool save();
void showFindDialog();

void on_actionGreen_triggered();
void on_actionBlue_triggered();
void on_actionRed_triggered();
void on_actionBlack_triggered();

//void on_actionGreen_BG_triggered();
//void on_actionBlue_BG_triggered();
void on_actionBlack_BG_triggered();
void on_actionWhite_BG_triggered();
void on_actionFont_triggered();
//void on_actionColor_triggered();
};

#endif // MAINWINDOW_H
