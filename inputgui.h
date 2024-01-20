#ifndef INPUTGUI_H
#define INPUTGUI_H

#include "Input.h"
#include <QObject>
#include <QEventLoop>

class InputGUI : public QObject, public Input {
    Q_OBJECT

public:
    explicit InputGUI(QObject *parent = nullptr);

    std::pair<int, int> demanderCoordonnees() const override;
    int demanderColonne() const override { return 0; } // Pas utilisé pour le morpion
    std::string getString(const std::string &) const override { return ""; } // Pas nécessaire pour le morpion
    int getInt(const std::string &) const override { return 0; } // Pas nécessaire pour le morpion

signals:
    void celluleChoisie(int x, int y);
   // void coupJoue(int x, int y);

public slots:
    void onCelluleClique(int x, int y);

private:
    mutable std::pair<int, int> dernierCoup;
    mutable QEventLoop loop;
};

#endif // INPUTGUI_H
