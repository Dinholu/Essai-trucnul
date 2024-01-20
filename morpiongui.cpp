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

    affichage = new AffichageGUI(this) ; // 'this' est votre widget parent, par exemple morpionGUI
    InputGUI *input = new InputGUI(this);

    connect(ui->retourAccueil, &QPushButton::clicked, this, &morpionGUI::on_retourAccueil_clicked);
    connect(affichage, &AffichageGUI::celluleBoutonClick, input, &InputGUI::onCelluleClique);

    joueur1 = JoueurFactory::CreerJoueurHumain("prenomJoueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurHumain("prenomJoueur2", Jeton::X, *input);

     std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, affichage);
    jeu->Jouer();
}

morpionGUI::~morpionGUI()
{
    delete ui;
}

void morpionGUI::on_retourAccueil_clicked()
{
    // Votre logique pour retourner à l'accueil
    emit showAccueil(); // Vous pouvez émettre un signal si vous voulez gérer l'affichage dans MainWindow
}
