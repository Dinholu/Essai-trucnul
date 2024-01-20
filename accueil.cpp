#include "accueil.h"
#include "ui_accueil.h"

accueil::accueil(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::accueil)
{
    ui->setupUi(this);
}

accueil::~accueil()
{
    delete ui;
}


void accueil::on_morpionButton_clicked()
{
    // Votre logique pour afficher le widget Morpion
   emit showMorpion(); // Vous pouvez émettre un signal si vous voulez gérer l'affichage dans MainWindow
}
