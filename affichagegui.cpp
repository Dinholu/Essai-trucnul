#include "affichagegui.h"
#include <QMessageBox>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QObject>

AffichageGUI::AffichageGUI(QWidget *parentWidget) : parentWidget(parentWidget) {}

void AffichageGUI::AfficherGrille(const std::shared_ptr<AGrille>& grille) {
    QGridLayout *gridLayout = new QGridLayout(parentWidget);
    parentWidget->setLayout(gridLayout);

    for (int x = 0; x < grille->getNbLignes(); ++x) {
        for (int y = 0; y < grille->getNbColonnes(); ++y) {
            QPushButton *button = new QPushButton(parentWidget);
            button->setFixedSize(50, 50);  // Taille du bouton

            Jeton jeton = grille->GetCellule(x, y);
            if (jeton == Jeton::Vide) {
                button->setText("");
            } else {
                button->setText(jeton == Jeton::X ? "X" : "O");  // À adapter selon vos jetons
            }
            gridLayout->addWidget(button, x, y);

            QAction::connect(button, &QPushButton::clicked, [this, x, y]() {
                emit celluleBoutonClick(x, y);
            });
        }
    }
}


void AffichageGUI::AfficherMessage(const std::string& message, const int duree) const {
    // Affiche un message à l'utilisateur pour une durée spécifiée
    QMessageBox::information(parentWidget, "Message", QString::fromStdString(message));
}

void AffichageGUI::AfficherErreur(const std::string& erreur) const {
    // Affiche un message d'erreur
    QMessageBox::critical(parentWidget, "Erreur", QString::fromStdString(erreur));
}

void AffichageGUI::AfficherCoupsPossibles(const std::vector<std::pair<int, int>>& coups) const {
    // Affiche les coups possibles
    // Vous pouvez par exemple mettre en surbrillance les cellules de la grille où les coups sont possibles
}
