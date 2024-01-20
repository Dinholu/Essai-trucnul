#ifndef AFFICHAGEGUI_H
#define AFFICHAGEGUI_H

#include "IAffichage.h"
#include <QWidget>
#include <memory>
#include <vector>
#include <string>
#include <QObject>

class AffichageGUI : public QObject,  public IAffichage {
    Q_OBJECT
public:
    AffichageGUI(QWidget *parentWidget);

    virtual void AfficherGrille(const std::shared_ptr<AGrille>& grille) override;
    virtual void AfficherMessage(const std::string& message, const int duree = 1) const override;
    virtual void AfficherErreur(const std::string& erreur) const override;
    virtual void AfficherCoupsPossibles(const std::vector<std::pair<int, int>>& coups) const override;

signals:
    void celluleBoutonClick(int x, int y);

private:
    QWidget *parentWidget;  // Référence à votre widget parent (ex. morpionGUI)
public slots:
    //void celluleBoutonClick(int x, int y);
};


#endif // AFFICHAGEGUI_H
