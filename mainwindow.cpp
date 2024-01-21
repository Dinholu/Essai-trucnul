#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initWidgets();
}

MainWindow::~MainWindow()
{
    delete accueilWidget;
    delete morpionWidget;
    delete ui;
}

void MainWindow::initWidgets()
{
    accueilWidget = new accueil(this);
    morpionWidget = new morpionGUI(this);

    connect(accueilWidget, &accueil::showMorpion, this, [=]() {
        accueilWidget->hide();
        morpionWidget->show();
    });

    connect(morpionWidget, &morpionGUI::showAccueil, this, [=]() {
        morpionWidget->hide();
        accueilWidget->show();
    });

    accueilWidget->show();
    morpionWidget->hide();
}
