#ifndef AJOUTERCAMIONGUI_H
#define AJOUTERCAMIONGUI_H

#include <QtGui/QDialog>
#include "ui_ajoutercamiongui.h"
#include "validationFormat.h"
#include <iostream>
#include <QMessageBox>

class ajouterCamionGUI : public QDialog
{
    Q_OBJECT

public:
    ajouterCamionGUI(QWidget *parent = 0);
    ~ajouterCamionGUI();
    QString reqNIV();
    QString reqImmat();
    QString reqPoids();
    QString reqNbEssieux();

private slots:
	void validerEnregistrement();

private:
    Ui::ajouterCamionGUIClass ui;
};

#endif // AJOUTERCAMIONGUI_H
