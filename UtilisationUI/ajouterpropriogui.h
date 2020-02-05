#ifndef AJOUTERPROPRIOGUI_H
#define AJOUTERPROPRIOGUI_H

#include <QtGui/QDialog>
#include "ui_ajouterpropriogui.h"
#include <QMessageBox>

class ajouterProprioGUI : public QDialog
{
    Q_OBJECT

public:
    ajouterProprioGUI(QWidget *parent = 0);
    ~ajouterProprioGUI();
    QString reqPrenom();
    QString reqNom();

private slots:
	void validerEnregistrement();

private:
    Ui::ajouterProprioGUIClass ui;


};

#endif // AJOUTERPROPRIOGUI_H
