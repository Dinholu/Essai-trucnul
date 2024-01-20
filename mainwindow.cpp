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

    // Connecter le bouton du widget d'accueil pour afficher le morpion
    // Connectez les signaux pour passer entre les widgets
    connect(accueilWidget, &accueil::showMorpion, this, [=]() {
        accueilWidget->hide();
        morpionWidget->show();
    });

    connect(morpionWidget, &morpionGUI::showAccueil, this, [=]() {
        // Masquer le widget Morpion
        morpionWidget->hide();
        accueilWidget->show();
    });


    // Affichez initialement le widget d'accueil
    accueilWidget->show();
    morpionWidget->hide();
}
