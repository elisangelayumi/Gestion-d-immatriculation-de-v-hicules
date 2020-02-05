#include "ajoutervehiculepromenadegui.h"

ajouterVehiculePromenadeGUI::ajouterVehiculePromenadeGUI(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

ajouterVehiculePromenadeGUI::~ajouterVehiculePromenadeGUI()
{

}

QString ajouterVehiculePromenadeGUI::reqImmat(){
	return ui.Immat->text();
}

QString ajouterVehiculePromenadeGUI::reqNIV(){
	return ui.NIV->text();
}

QString ajouterVehiculePromenadeGUI::reqNbPlaces(){
	return ui.NbPlaces->text();
}


void ajouterVehiculePromenadeGUI::validerEnregistrement(){
	if(!util::validationImmatriculationPromenade(ui.Immat->text().toStdString())){
		QString message("Numero d'immatriculation invalide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(!util::validerNiv(ui.NIV->text().toStdString())){
		QString message("Le NIV est invalide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.NbPlaces->text().toInt()<2){
		QString message("Le vehicule doit avoir au moins deux place");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	accept();
}
