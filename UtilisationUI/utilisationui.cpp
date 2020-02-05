#include "utilisationui.h"


UtilisationUI::UtilisationUI(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	nombreDeLigne = 0;
	ui.tableProprio->setColumnWidth(0, 160);
	ui.tableProprio->setColumnWidth(1, 160);
	ui.tableProprio->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui.actionSupprimer->setEnabled(false);
	ui.menuAjouter->setEnabled(false);
}

//destructeur qui vide le vecteur
UtilisationUI::~UtilisationUI()
{
	for(size_t i = 0; i < m_vProprietaire.size(); i++)
		delete m_vProprietaire[i];
}

//Methode pour ajouter un camion au proprietaire reference en parametre
void UtilisationUI::ajouterCamion(saaq::Proprietaire& p_proprio,const std::string& p_niv, const std::string& p_immatriculation, double p_poids, int nbEssieux){
	try{
		saaq::Camion unCamion(p_niv,p_immatriculation,p_poids,nbEssieux);
		p_proprio.ajouterVehicule(unCamion);
	}catch(VehiculeDejaPresentException& erreur){
		QString message = erreur.what();
		QMessageBox::information(this, "ERREUR", message);
	}
}

//Methode pour ajouter un proprietaire
void UtilisationUI::ajouterProprietaire(const std::string& p_nom, const std::string& p_prenom){
	saaq::Proprietaire unProprio(p_nom,p_prenom);
	m_vProprietaire.push_back(new saaq::Proprietaire(unProprio));
}

//Methode pour ajouter un vehicule promenade au proprietaire recu en reference
void UtilisationUI::ajouterVehiculePromenade(saaq::Proprietaire& p_proprio,const std::string& p_niv, const std::string& p_immatriculation, const int p_nbPlaces ){
	try{
		saaq::VehiculePromenade unVP(p_niv,p_immatriculation,p_nbPlaces);
		p_proprio.ajouterVehicule(unVP);
	} catch(VehiculeDejaPresentException& erreur){
		QString message = erreur.what();
		QMessageBox::information(this, "ERREUR", message);
	}
}

//Methode pour supprimer un vehicule du proprietaire recu en parametre
void UtilisationUI::suppresion(saaq::Proprietaire& p_proprio,const std::string& p_niv){
	try{
		p_proprio.supprimerVehicule(p_niv);
	} catch(VehiculeAbsentException& erreur){
		QString message = erreur.what();
		QMessageBox::information(this, "ERREUR", message);
	}
}

//Method pour appeler le dialog d'ajout de proprietaire
void UtilisationUI::dialogAjouterProprietaire(){
	ajouterProprioGUI saisieProprio(this);
	if (saisieProprio.exec()){
		UtilisationUI::ajouterProprietaire(saisieProprio.reqNom().toStdString(), saisieProprio.reqPrenom().toStdString());
		nombreDeLigne = ui.tableProprio->rowCount();
		ui.tableProprio->setRowCount(nombreDeLigne + 1);
		ui.tableProprio->setItem(nombreDeLigne, 0, new QTableWidgetItem(saisieProprio.reqNom()));
		ui.tableProprio->setItem(nombreDeLigne, 1, new QTableWidgetItem(saisieProprio.reqPrenom()));
		ui.tableProprio->setCurrentCell(nombreDeLigne,0);
		ui.actionSupprimer->setEnabled(true);
		ui.menuAjouter->setEnabled(true);
		int ligne = ui.tableProprio->currentRow();
		ui.textVehicule->setText(QString::fromUtf8(m_vProprietaire[ligne]->reqProprietaireFormate().c_str()));
	}
}

//Methode pour appeler le dialog d'ajout vehicule promenade
void UtilisationUI::dialogAjouterVehiculePromenade(){
	int ligne = ui.tableProprio->currentRow();
	ajouterVehiculePromenadeGUI saisieVP(this);
	if (saisieVP.exec()){
		UtilisationUI::ajouterVehiculePromenade(*m_vProprietaire[ligne],saisieVP.reqNIV().toStdString(), saisieVP.reqImmat().toStdString(), saisieVP.reqNbPlaces().toInt());
	}
	ui.textVehicule->setText(QString::fromUtf8(m_vProprietaire[ligne]->reqProprietaireFormate().c_str()));
}

//Methode pour appeler le dialog d'ajout d'un camion
void UtilisationUI::dialogAjouterCamion(){
	int ligne = ui.tableProprio->currentRow();
	ajouterCamionGUI saisieVP(this);
	if (saisieVP.exec()){
		UtilisationUI::ajouterCamion(*m_vProprietaire[ligne],saisieVP.reqNIV().toStdString(), saisieVP.reqImmat().toStdString(), saisieVP.reqPoids().toInt(),saisieVP.reqNbEssieux().toInt());
	}
	ui.textVehicule->setText(QString::fromUtf8(m_vProprietaire[ligne]->reqProprietaireFormate().c_str()));
}

//Methode qui active le boutun qui affecte un proprietaire et affiche l'information du proprietaire dans la champs de l'interface
void UtilisationUI::selectionProprietaire(){
	int ligne = ui.tableProprio->currentRow();
	ui.textVehicule->setText(QString::fromUtf8(m_vProprietaire[ligne]->reqProprietaireFormate().c_str()));
}

//Methode qui appel le dialog de supression de vehicule
void UtilisationUI::dialogSuppression(){
	int ligne = ui.tableProprio->currentRow();
	supprimerGUI saisieSup(this);
	if(saisieSup.exec()){
		UtilisationUI::suppresion(*m_vProprietaire[ligne],saisieSup.reqNIV().toStdString());
	}
	ui.textVehicule->setText(QString::fromUtf8(m_vProprietaire[ligne]->reqProprietaireFormate().c_str()));
}
