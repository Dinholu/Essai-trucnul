#include "inputgui.h"

InputGUI::InputGUI(QObject *parent) : QObject(parent) {}

void InputGUI::onCelluleClique(int x, int y) {
    // affiche un messag epour dire le coup
    dernierCoup = {x, y};
    loop.quit(); // Arrête l'attente
//    emit coupJoue(x, y);


}

std::pair<int, int> InputGUI::demanderCoordonnees() const {
    loop.exec(); // Attend que l'utilisateur clique sur une cellule
    return dernierCoup;
}
