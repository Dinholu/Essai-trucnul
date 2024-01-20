#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class accueil;
}

class accueil : public QWidget
{
    Q_OBJECT

public:
    explicit accueil(QWidget *parent = nullptr);
    QPushButton* getMorpionButton() const;
    ~accueil();

public slots:
    void on_morpionButton_clicked();

private:
    Ui::accueil *ui;

signals:
    void showMorpion();
};

#endif // ACCUEIL_H
