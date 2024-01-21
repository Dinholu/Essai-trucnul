#ifndef MORPIONGUI_H
#define MORPIONGUI_H

#include <QWidget>
#include "joueurhumain.h"
#include "jeumorpion.h"
#include "grille.h"
#include "affichagegui.h"
#include "TypesJeu.h"
#include "IAffichage.h"
#include "inputgui.h"

namespace Ui {
class morpionGUI;
}

class morpionGUI : public QWidget
{
    Q_OBJECT

public:
    explicit morpionGUI(QWidget *parent = nullptr);
 //   void mettreAJourGrille(int x, int y);
    ~morpionGUI();

public slots:
    void on_retourAccueil_clicked();
    void on_JouerButton_clicked();

private:
    Ui::morpionGUI *ui;
    TypesJeu typeDeJeu = TypesJeu::Morpion;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<IAffichage> affichage;
    InputGUI* input;
    void ReinitialiserJeu();

signals:
    void showAccueil();
};

#endif // MORPIONGUI_H
