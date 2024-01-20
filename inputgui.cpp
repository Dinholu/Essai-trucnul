#include "inputgui.h"

InputGUI::InputGUI(QObject *parent) : QObject(parent) {}

void InputGUI::onCelluleClique(int x, int y) {
    dernierCoup = {x, y};
    loop.quit(); // Arrête l'attente
}

std::pair<int, int> InputGUI::demanderCoordonnees() const {
    loop.exec(); // Attend que l'utilisateur clique sur une cellule
    return dernierCoup;
}
