#ifndef AJOUTERVEHICULEPROMENADEGUI_H
#define AJOUTERVEHICULEPROMENADEGUI_H

#include <QtGui/QDialog>
#include "validationFormat.h"
#include "ui_ajoutervehiculepromenadegui.h"
#include <iostream>
#include <QMessageBox>

class ajouterVehiculePromenadeGUI : public QDialog
{
    Q_OBJECT

public:
    ajouterVehiculePromenadeGUI(QWidget *parent = 0);
    ~ajouterVehiculePromenadeGUI();
    QString reqNIV();
    QString reqImmat();
    QString reqNbPlaces();

private slots:
    	void validerEnregistrement();

private:
    Ui::ajouterVehiculePromenadeGUIClass ui;
};

#endif // AJOUTERVEHICULEPROMENADEGUI_H
