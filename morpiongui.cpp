#include "morpiongui.h"
#include "affichagegui.h"
#include "ui_morpiongui.h"
#include "inputgui.h"
#include "IJeu.h"
#include "jeufactory.h"
#include "joueurfactory.h"

morpionGUI::morpionGUI(QWidget *parent) : QWidget(parent), ui(new Ui::morpionGUI) {
    ui->setupUi(this);

    modeAffichage = std::make_shared<AffichageGUI>(this);
    input = std::make_shared<InputGUI>(this);

    connect(ui->retourAccueil, &QPushButton::clicked, this, &morpionGUI::on_retourAccueil_clicked);
    connect(modeAffichage.get(), &AffichageGUI::celluleBoutonClick, input.get(), &InputGUI::onCelluleClique);
    connect(ui->JouerButton, &QPushButton::clicked, this, &morpionGUI::on_JouerButton_clicked);
}

morpionGUI::~morpionGUI() {
}

void morpionGUI::on_retourAccueil_clicked() {
    hide();
    emit showAccueil();
}

void morpionGUI::ReinitialiserJeu() {
    modeAffichage = std::make_shared<AffichageGUI>(this);
    input = std::make_shared<InputGUI>(this);
}

void morpionGUI::on_JouerButton_clicked() {
    joueur1 = JoueurFactory::CreerJoueurHumain("prenomJoueur1", Jeton::X, *input);
    joueur2 = JoueurFactory::CreerJoueurOrdinateur(Jeton::O);

    std::unique_ptr<IJeu> jeu = JeuFactory::CreerJeu(typeDeJeu, joueur1, joueur2, modeAffichage);
    jeu->Jouer();
}
