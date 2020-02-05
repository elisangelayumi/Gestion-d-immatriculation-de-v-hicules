#include "supprimergui.h"

supprimerGUI::supprimerGUI(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
}

supprimerGUI::~supprimerGUI()
{
}


QString supprimerGUI::reqNIV(){
	return ui.NIV->text();
}

void supprimerGUI::validerSuppression(){
	if(!util::validerNiv(ui.NIV->text().toStdString())){
			QString message("Le NIV est invalide");
			QMessageBox::information(this, "ERREUR", message);
			return;
	}
	accept();
}
