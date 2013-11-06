#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mysyntaxhighlighter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    highlighter = new MySyntaxHighlighter(ui->textEdit->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}
