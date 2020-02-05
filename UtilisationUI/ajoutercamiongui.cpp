#include "ajoutercamiongui.h"

ajouterCamionGUI::ajouterCamionGUI(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

ajouterCamionGUI::~ajouterCamionGUI()
{

}

QString ajouterCamionGUI::reqImmat(){
	return ui.Immat->text();
}

QString ajouterCamionGUI::reqNIV(){
	return ui.NIV->text();
}

QString ajouterCamionGUI::reqNbEssieux(){
	return ui.NbEssieux->text();
}

QString ajouterCamionGUI::reqPoids(){
	return ui.Poids->text();
}

void ajouterCamionGUI::validerEnregistrement(){
	if(!util::validationImmatriculationCamion(ui.Immat->text().toStdString())){
		QString message("Numero d'immatriculation invalide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(!util::validerNiv(ui.NIV->text().toStdString())){
		QString message("Le NIV est invalide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.Poids->text().toInt()<3001){
		QString message("Le camion doit peser plus de 3000 livres.");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.NbEssieux->text().toInt()<2){
		QString message("Le camion doit avoir au moins deux essieux");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	accept();
}
