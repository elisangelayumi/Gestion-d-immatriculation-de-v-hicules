#ifndef UTILISATIONUI_H
#define UTILISATIONUI_H

#include <QtGui/QMainWindow>
#include "ui_utilisationui.h"
#include <vector>
#include "Camion.h"
#include "Date.h"
#include "Proprietaire.h"
#include "Vehicule.h"
#include "VehiculePromenade.h"
#include "validationFormat.h"
#include "ajouterpropriogui.h"
#include "ajoutervehiculepromenadegui.h"
#include "ajoutercamiongui.h"
#include "supprimergui.h"
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QTableWidgetItem>
#include <iostream>
#include "VehiculeException.h"
using namespace std;
using namespace saaq;
using namespace util;

class UtilisationUI : public QMainWindow
{
    Q_OBJECT

public:
    UtilisationUI(QWidget *parent = 0);
    ~UtilisationUI();

private slots:
	void dialogAjouterProprietaire();
	void dialogAjouterVehiculePromenade();
	void dialogAjouterCamion();
	void dialogSuppression();
	void selectionProprietaire();

private:
	Ui::UtilisationUIClass ui;
	void suppresion(saaq::Proprietaire& p_proprio,const std::string& p_niv);
	void ajouterProprietaire(const std::string& p_nom, const std::string& p_prenom);
	void ajouterVehiculePromenade(saaq::Proprietaire& p_proprio,const std::string& p_niv, const std::string& p_immatriculation, const int p_nbPlaces );
	void ajouterCamion(saaq::Proprietaire& p_proprio,const std::string& p_niv, const std::string& p_immatriculation, double p_poids, int nbEssieux);
    vector<saaq::Proprietaire*> m_vProprietaire;
    int nombreDeLigne;
};

#endif // UTILISATIONUI_H
