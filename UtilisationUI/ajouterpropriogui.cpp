#include "ajouterpropriogui.h"

ajouterProprioGUI::ajouterProprioGUI(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

ajouterProprioGUI::~ajouterProprioGUI()
{

}
QString ajouterProprioGUI::reqPrenom(){
	return ui.prenomPro->text();
}

QString ajouterProprioGUI::reqNom(){
	return ui.nomPro->text();
}

void ajouterProprioGUI::validerEnregistrement(){
	if(ui.prenomPro->text().isEmpty()){
		QString message("Le prenom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	if(ui.nomPro->text().isEmpty()){
		QString message("Le nom ne doit pas etre vide");
		QMessageBox::information(this, "ERREUR", message);
		return;
	}
	accept();
}
