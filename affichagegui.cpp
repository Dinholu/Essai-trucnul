#include "affichagegui.h"
#include <QMessageBox>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>

AffichageGUI::AffichageGUI(QWidget *parentWidget) : parentWidget(parentWidget) {}

void AffichageGUI::AfficherGrille(const std::shared_ptr<AGrille>& grille)
{
    QGridLayout *gridLayout = new QGridLayout(parentWidget);
    grilleJeu = grille;
    parentWidget->setLayout(gridLayout);
    boutonsGrille.resize(grille->getNbLignes()); // Initialiser la taille de la première dimension
    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        boutonsGrille[x].resize(grille->getNbColonnes()); // Initialiser la taille de chaque QVector interne
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            QPushButton *button = new QPushButton(parentWidget);
            button->setFixedSize(50, 50); // Taille du bouton

            Jeton jeton = grille->GetCellule(x, y);
            button->setText(QString(static_cast<char>(jeton)));

            gridLayout->addWidget(button, x, y);
            boutonsGrille[x][y] = button; // Stocke la référence du bouton
            QAction::connect(button, &QPushButton::clicked, [this, x, y](){
                emit celluleBoutonClick(x, y); });
        }
    }
}

void AffichageGUI::MettreAJourGrille(const std::shared_ptr<AGrille>& grille)
{
    for (int x = 0; x < grille->getNbLignes(); ++x)
    {
        for (int y = 0; y < grille->getNbColonnes(); ++y)
        {
            Jeton jeton = grille->GetCellule(x, y);
            boutonsGrille[x][y]->setText(QString(static_cast<char>(jeton)));
        }
    }
}

void AffichageGUI::AfficherMessage(const std::string& message, const int duree) const {
    QMessageBox::information(parentWidget, "Message", QString::fromStdString(message));
}

void AffichageGUI::AfficherErreur(const std::string &erreur) const
{
    QMessageBox::critical(parentWidget, "Erreur", QString::fromStdString("Saisie invalide. Veuillez réessayer. " + erreur));
}

void AffichageGUI::AfficherCoupsPossibles(const std::vector<std::pair<int, int>> &coups) const
{
    // Affiche les coups possibles
    // Vous pouvez par exemple mettre en surbrillance les cellules de la grille où les coups sont possibles
}
