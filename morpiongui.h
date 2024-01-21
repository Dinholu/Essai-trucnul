// Dans le fichier morpiongui.h

#ifndef MORPIONGUI_H
#define MORPIONGUI_H

#include <QWidget>
#include "AJoueur.h"
#include "TypesJeu.h"
#include "IAffichage.h"
#include <memory>

namespace Ui {
class morpionGUI;
}

class morpionGUI : public QWidget
{
    Q_OBJECT

public:
    explicit morpionGUI(QWidget *parent = nullptr);
    ~morpionGUI();

public slots:
    void on_retourAccueil_clicked();
    void on_JouerButton_clicked();

private:
    std::unique_ptr<Ui::morpionGUI> ui;
    TypesJeu typeDeJeu = TypesJeu::Morpion;
    std::shared_ptr<AJoueur> joueur1;
    std::shared_ptr<AJoueur> joueur2;
    std::shared_ptr<IAffichage> modeAffichage;
    std::shared_ptr<Input> input;
    void ReinitialiserJeu();

signals:
    void showAccueil();
};

#endif // MORPIONGUI_H
