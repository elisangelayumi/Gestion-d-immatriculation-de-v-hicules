#ifndef SUPPRIMERGUI_H
#define SUPPRIMERGUI_H

#include <QtGui/QDialog>
#include "ui_supprimergui.h"
#include "validationFormat.h"
#include <iostream>
#include <QMessageBox>

class supprimerGUI : public QDialog
{
    Q_OBJECT

public:
    supprimerGUI(QWidget *parent = 0);
    ~supprimerGUI();
    QString reqNIV();

private slots:
	void validerSuppression();

private:
    Ui::supprimerGUIClass ui;
};

#endif // SUPPRIMERGUI_H
