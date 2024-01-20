#include "morpiongui.h"
#include "ui_morpiongui.h"
#include "affichagegui.h"
#include "inputgui.h"
#include "joueurfactory.h"
#include "jeufactory.h"


morpionGUI::morpionGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::morpionGUI)
{
    ui->setupUi(this);
    affichage = new AffichageGUI(this) ;
    input = new InputGUI(this);

    connect(ui->retourAccueil, &QPushButton::clicked, this, &morpionGUI::on_retourAccueil_clicked);
    connect(affichage, &AffichageGUI::celluleBoutonClick, input, &InputGUI::onCelluleClique);
    connect(ui->JouerButton, &QPushButton::clicked, this, &morpionGUI::on_JouerButton_clicked);
}


morpionGUI::~morpionGUI()
{
    delete ui;
}

void morpionGUI::on_retourAccueil_clicked()
{
    hide();
    emit showAccueil();

}

void morpionGUI::ReinitialiserJeu()
{
    delete affichage;
    delete input;
    affichage = new AffichageGUI(this) ;
    input = new InputGUI(this);
}

void morpionGUI::on_JouerButton_clicked(){

    joueur1 = JoueurFactory::CreerJoueurHumain("prenomJoueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("prenomJoueur2", Jeton::O, *input);

    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, affichage);
    jeu->Jouer();
}
