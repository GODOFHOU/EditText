#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
     //ui->menu_Format->addAction(green);
    ui->setupUi(this);

    FindDialog find_dialog;
    this->setCentralWidget(ui->plainTextEdit);
    /*
    find_dialog.show();
    find_dialog.exec();
    */
    this->setWindowTitle("侯亚威的记事本");
    ui->statusBar->showMessage(tr("我准备好了"),5000);
    ui->action_New->setStatusTip(tr("新建一个文件"));
    ui->action_Open->setStatusTip(tr("打开文件"));
    ui->action_Save->setStatusTip(tr("保存文件"));
    ui->action_Save_as->setStatusTip(tr("文件另存为"));
    ui->action_Copy->setStatusTip(tr("复制选中文本"));
    ui->action_Cut->setStatusTip(tr("剪切选中文本"));
    ui->action_Paste->setStatusTip(tr("粘贴文本"));
    ui->action_Find->setStatusTip(tr("查找"));

    ui->action_New->setShortcut(QKeySequence::New);
    ui->action_Open->setShortcut(QKeySequence::Open);
    ui->action_Save->setShortcut(QKeySequence::Save);
    ui->action_Save_as->setShortcut(QKeySequence::SaveAs);
    ui->action_Copy->setShortcut(QKeySequence::Copy);
    ui->action_Cut->setShortcut(QKeySequence::Cut);
    ui->action_Paste->setShortcut(QKeySequence::Paste);
    ui->action_Find->setShortcut(QKeySequence::Find);

    connect(ui->action_New, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->action_Open, &QAction::triggered, this, &MainWindow::open);
    connect(ui->action_Save, &QAction::triggered, this, &MainWindow::save);
    connect(ui->action_Save_as, &QAction::triggered, this, &MainWindow::saveAs);
    connect(ui->action_About,&QAction::triggered,this, &MainWindow::about);
    connect(ui->action_About_Qt,&QAction::triggered,this, &QApplication::aboutQt);
    connect(ui->action_Find, &QAction::triggered,this,&MainWindow::showFindDialog);
   // connect(find_dialog,&FindDialog::gettext(QString),this,SLOT(search()));
   // connect(find_dialog,findTextDataButtonClickedSignal(QString,bool,bool), this,SLOT(findAct(QString,bool,bool)));



}

void MainWindow::setCurrentFile(const QString &fileName)
{
    curFile=fileName;

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName="untitled.txt";

    setWindowTitle(shownName);
}

void MainWindow::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("Application"),tr("cannot read file"));
        return;
    }
    QTextStream in(&file);
    ui->plainTextEdit->setPlainText(in.readAll());
    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File load"),2000);
    ui->menu_History->addAction(fileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    ui->plainTextEdit->clear();
    setCurrentFile("");
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this);

    if(!fileName.isEmpty())
        loadFile(fileName);
    else
    {//
    }
}

bool MainWindow::save()
{

    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }

}

bool MainWindow::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName.isEmpty())
        return false;

    return saveFile(fileName);
}


bool MainWindow::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,tr("Application"),tr("cannot write file"));
        return false;
    }
    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out<<ui->plainTextEdit->toPlainText();
    QApplication::restoreOverrideCursor();
    setCurrentFile(fileName);
    return true;
}

void MainWindow::about()
{
    QMessageBox::about(this,tr("About Application"),tr(" The <b>Application</b> example"
                                                       " demostartes how to write modern GUI application using QT"
                                                       "with a BAr,toolbar,and a status bar"
                                                       "<b>Power By 侯亚威</b>"));
}

void MainWindow::showFindDialog()
{
    find_dialog.show();
    find_dialog.exec();
}

void MainWindow::search(QString text)
{

    QString findContent = find_dialog.gettext(text);
    bool hasfind;
    hasfind = ui->plainTextEdit->find(text);
    if (!hasfind)
               QMessageBox::information(this, "查找结果", "找不到目标内容", QMessageBox::Yes);

}



void MainWindow::on_actionGreen_triggered()
{
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{color:green; "
                                     "background-color: #ffffff;"
                                     " selection-background-color: #606060; "
                                     "selection-color: #ffffff;}");
    QTextCharFormat fmt;
    fmt.setForeground(QBrush(QColor(0,0,0)));
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actionBlue_triggered()
{
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{color:blue; "
                                     "background-color: #ffffff;"
                                     " selection-background-color: #606060; "
                                     "selection-color: #ffffff;}");
    QTextCharFormat fmt;
    fmt.setForeground(QBrush(QColor(0,0,0)));
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actionRed_triggered()
{
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{color:red; "
                                     "background-color: #ffffff;"
                                     " selection-background-color: #606060; "
                                     "selection-color: #ffffff;}");
    QTextCharFormat fmt;
    fmt.setForeground(QBrush(QColor(0,0,0)));
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actionBlack_triggered()
{
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{color:black; "
                                     "background-color: #ffffff;"
                                     " selection-background-color: #606060; "
                                     "selection-color: #ffffff;}");
    QTextCharFormat fmt;
    fmt.setForeground(QBrush(QColor(0,0,0)));
    ui->plainTextEdit->mergeCurrentCharFormat(fmt);
}
/*
void MainWindow::on_actionGreen_BG_triggered()
{
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{background-color: #000000;"
                                     " selection-background-color: #606060; "
                                     "selection-color: #ffffff;}");
    QTextCharFormat fm;
    fm.setForeground(QBrush(QColor(0,0,0)));
    ui->plainTextEdit->mergeCurrentCharFormat(fm);
}

void MainWindow::on_actionBlue_BG_triggered()
{
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{ "
                                     "background-color: blue;");
    QTextCharFormat fm;
    fm.setForeground(QBrush(QColor(0,0,0)));
    ui->plainTextEdit->mergeCurrentCharFormat(fm);
}
*/
void MainWindow::on_actionBlack_BG_triggered()
{
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{color:white; "
                                     "background-color: #000000;"
                                     " selection-background-color: #606060; "
                                     "selection-color: #ffffff;}");
    QTextCharFormat fm;
    fm.setForeground(QBrush(QColor(0,0,0)));
    ui->plainTextEdit->mergeCurrentCharFormat(fm);
}

void MainWindow::on_actionWhite_BG_triggered()
{
    ui->plainTextEdit->setStyleSheet("QPlainTextEdit{color:black; "
                                     "background-color: #ffffff;"
                                     " selection-background-color: #606060; "
                                     "selection-color: #ffffff;}");
    QTextCharFormat fm;
    fm.setForeground(QBrush(QColor(0,0,0)));
    ui->plainTextEdit->mergeCurrentCharFormat(fm);
}

void MainWindow::on_actionFont_triggered()
{
    bool ok ;
      QFont font = QFontDialog::getFont(&ok,this);
      if(ok)
      {
          ui->plainTextEdit->setFont(font);
      }
      else
      {
          QMessageBox::information(this,"Error Message","Error Set Font");
      }
}

/*void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::red,this);
        if(color.isValid())
        {
            ui->plainTextEdit->setTextColor(color);
        }
        else
        {
            QMessageBox::information(this,"Error Message","Color is unvalid");
            return ;
        }
}*/
