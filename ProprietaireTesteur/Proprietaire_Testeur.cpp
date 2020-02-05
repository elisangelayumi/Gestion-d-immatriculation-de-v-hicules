/**
 * \file Proprietaire_Testeur.cpp
 * \brief Fichier de tests unitaires pour la classe Proprietaire
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-21
 */

#include "Proprietaire.h"
#include "VehiculePromenade.h"
#include "Camion.h"
#include "ContratException.h"
#include "VehiculeException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace saaq;



/**
 * \brief Test du constructeur Proprietaire_Testeur::Proprietaire(p_nom, p_prenom)
 *
 *        cas valide :
 *          Création d'un Proprietaire_Testeur valide : ParametresValides
 *
 *        cas invalides :
 *        	p_nom invalide : p_nom vide
 *        	p_prenom invalide : p_prenom vide
 */
TEST(Proprietaire, constructeurParametresValides)
{
	Proprietaire unProprietaire("Tremblay", "Louise");

	ASSERT_EQ("Tremblay", unProprietaire.reqNom());
	ASSERT_EQ("Louise", unProprietaire.reqPrenom());
}

/**
* \brief Test du constructeur Camion_Testeur::VehiculePromenade(p_niv, p_immatriculation, p_poids, p_nbEssieux)
* 		cas invalides : p_nom invalide
*/
TEST(Proprietaire, constructeurNomvalide)
{
	ASSERT_THROW(Proprietaire unProprietaire("", "Marie"), PreconditionException);
}

/**
* \brief Test du constructeur Camion_Testeur::VehiculePromenade(p_niv, p_immatriculation, p_poids, p_nbEssieux)
* 		cas invalides : p_prenom invalide
*/
TEST(Proprietaire, constructeurPrenomvalide)
{
	ASSERT_THROW(Proprietaire unProprietaire("Joyal", ""), PreconditionException);
}


/**
 * \class ProprietaireValide
 * \brief Fixture pour les tests avec un Proprietaire Valide
 */
class ProprietaireValide: public ::testing:: Test
{
public:
	Proprietaire monProprietaire;

	ProprietaireValide():
		monProprietaire("Tremblay", "Louise"){
	}

};

/**
 * \brief Test du constructeur copie
 * 		Cas valide: Donne une copie avec les memes valeurs que l'original
 * 		Cas invalide: aucun
 */
TEST_F(ProprietaireValide,TestConstructeurCopie)
{
	VehiculePromenade voiture2("1M8GDM9AXKP042788", "HYF 003", 7);
	monProprietaire.ajouterVehicule(voiture2);

	Proprietaire foo(monProprietaire);

	ASSERT_EQ(foo.reqNom(),monProprietaire.reqNom());
	ASSERT_EQ(foo.reqPrenom(),monProprietaire.reqPrenom());
	ASSERT_EQ(monProprietaire.reqProprietaireFormate(), foo.reqProprietaireFormate());
}

/**
 * \brief Test de la methode ProprietaireValide::operator=()
 *        cas valide: verifier l'operateur d'assignment fait bien la copie profonde
 *        cas invalide: Aucun
 */
TEST_F(ProprietaireValide, TestAssignmentOperator)
{
	Proprietaire monProprietaire2 = monProprietaire;

	ASSERT_EQ(monProprietaire2.reqProprietaireFormate( ), monProprietaire.reqProprietaireFormate());
}

/**
 * \brief Test de la methode Proprietaire::ajouterVehicule()
 *        cas valide 1: verifier si les objets qu' on a ajoute dans le vecteur sont bien corrects
 *        cas valide 2: ajouter un vehicule deja existant et obtenir une exception
 *        cas invalide: Aucun
 */
TEST_F(ProprietaireValide, TestAjouterVehicule)
{
	VehiculePromenade voiture2("1M8GDM9AXKP042788", "HYF 003", 7);
	Camion camion2("2T3R1RfV7KW049674", "L198756", 3900,2);
	monProprietaire.ajouterVehicule(voiture2);
	monProprietaire.ajouterVehicule(camion2);

	string separateur = "-----------------------------------------";
	std::ostringstream os;
	os << "Proprietaire : " << endl
	   << separateur << endl
	   << " Nom    : " << monProprietaire.reqNom() << endl
	   << " Prenom : " << monProprietaire.reqPrenom() << endl
	   << separateur << endl;
	os <<"Numero de serie : " << voiture2.reqNiv() << endl
	<< "Numero d’immatriculation : " << voiture2.reqImmatriculation() << endl
	<< "Date d’enregistrement : " << voiture2.reqdateEnregistrement().reqDateFormatee() << endl;
	os << "Nombre de place : " << voiture2.reqNbPlaces() << endl
	<< "Tarif : " << voiture2.tarificationAnnuelle() << "$" << endl
	<< separateur << endl;
	os <<"Numero de serie : " << camion2.reqNiv() << endl
	<< "Numero d’immatriculation : " << camion2.reqImmatriculation() << endl
	<< "Date d’enregistrement : " << camion2.reqdateEnregistrement().reqDateFormatee() << endl;
	os << "Nombre d'essieux : " << camion2.reqNbEssieux() << endl
	<< "Poids : " << camion2.reqPoids() << " kg" << endl
	<< "Tarif : " << camion2.tarificationAnnuelle() << "$" << endl
	<< separateur << endl;

	ASSERT_EQ(os.str(),monProprietaire.reqProprietaireFormate());
}

/**
 * \brief Test de la methode Proprietaire::ajouterVehicule()
 *       cas valide 2: ajouter un vehicule deja existant et obtenir une exception
 */
TEST_F(ProprietaireValide, TestAjouterVehiculeDoublon)
{
	VehiculePromenade voiture2("1M8GDM9AXKP042788", "HYF 003", 7);
	VehiculePromenade voiture3("1M8GDM9AXKP042788", "SAAQ", 5);
	monProprietaire.ajouterVehicule(voiture2);

	ASSERT_THROW(monProprietaire.ajouterVehicule(voiture3), VehiculeDejaPresentException);
}


/**
 * \brief Test de la methode Proprietaire::supprimerVehicule()
 * 		 cas valide 1: supprimer un vehicule existant
 *       cas valide 2: essayer de supprimer un vehicule que n'existe pas et obtenir une exception
 */
TEST_F(ProprietaireValide, TestSupprimerVehicule)
{
	VehiculePromenade voiture4("1M8GDM9AXKP042788", "HYF 003", 7);
	Camion camion4("3VWFE21C04M000001", "L198756", 3900,2);

	monProprietaire.ajouterVehicule(voiture4);
	monProprietaire.ajouterVehicule(camion4);

	monProprietaire.supprimerVehicule("3VWFE21C04M000001");

	string separateur = "-----------------------------------------";
	std::ostringstream os;
	os << "Proprietaire : " << endl
	   << separateur << endl
	   << " Nom    : " << monProprietaire.reqNom() << endl
	   << " Prenom : " << monProprietaire.reqPrenom() << endl
	   << separateur << endl ;
	os <<"Numero de serie : " << voiture4.reqNiv() << endl
	<< "Numero d’immatriculation : " << voiture4.reqImmatriculation() << endl
	<< "Date d’enregistrement : " << voiture4.reqdateEnregistrement().reqDateFormatee() << endl;
	os << "Nombre de place : " << voiture4.reqNbPlaces() << endl
	<< "Tarif : " << voiture4.tarificationAnnuelle() << "$" << endl
	<< separateur << endl;



	ASSERT_EQ(os.str(),monProprietaire.reqProprietaireFormate());

}


TEST_F(ProprietaireValide, TestSupprimerVehiculeInexistant)
{
	ASSERT_THROW(monProprietaire.supprimerVehicule("3VWFE21C04M000001"), VehiculeAbsentException);
}



/**
 * \brief Test de la methode Proprietaire::reqNom()
 *        cas valide: verifier le retour du nom du proprietaire
 *        cas invalide: Aucun
 */
TEST_F(ProprietaireValide, TestReqNom)
{
	ASSERT_EQ("Tremblay", monProprietaire.reqNom());
}


/**
 * \brief Test de la methode Proprietaire::reqPrenom()
 *        cas valide: verifier le retour du Prenom du proprietaire
 *        cas invalide: Aucun
 */
TEST_F(ProprietaireValide, TestReqPrenom)
{
	ASSERT_EQ("Louise", monProprietaire.reqPrenom());
}


/**
 * \brief Test de la methode Proprietaire::reqProprietaireFormate()
 *        cas valide: verifier le retour des information sur l'objets Proprietaire
 *        cas invalide: Aucun
 */
TEST_F(ProprietaireValide, TestReqProprietaireFormate)
{
	// on ajoute des vehicules dans le vecteur pour valider reqProprietaireFormate
	VehiculePromenade voiture1("1M8GDM9AXKP042788", "GIF 003", 5);
	Camion camion1("2t3r1rfv7kw049674", "L123456", 3500,4);
	monProprietaire.ajouterVehicule(voiture1);
	monProprietaire.ajouterVehicule(camion1);

	string separateur = "-----------------------------------------";
	std::ostringstream os;
	os << "Proprietaire : " << endl
	   << separateur << endl
	   << " Nom    : " << monProprietaire.reqNom() << endl
	   << " Prenom : " << monProprietaire.reqPrenom() << endl
	   << separateur << endl;
	os <<"Numero de serie : " << voiture1.reqNiv() << endl
	<< "Numero d’immatriculation : " << voiture1.reqImmatriculation() << endl
	<< "Date d’enregistrement : " << voiture1.reqdateEnregistrement().reqDateFormatee() << endl;
	os << "Nombre de place : " << voiture1.reqNbPlaces() << endl
	<< "Tarif : " << voiture1.tarificationAnnuelle() << "$" << endl
	<< separateur << endl;
	os <<"Numero de serie : " << camion1.reqNiv() << endl
	<< "Numero d’immatriculation : " << camion1.reqImmatriculation() << endl
	<< "Date d’enregistrement : " << camion1.reqdateEnregistrement().reqDateFormatee() << endl;
	os << "Nombre d'essieux : " << camion1.reqNbEssieux() << endl
	<< "Poids : " << camion1.reqPoids() << " kg" << endl
	<< "Tarif : " << camion1.tarificationAnnuelle() << "$" << endl
	<< separateur << endl;

	ASSERT_EQ(os.str(),monProprietaire.reqProprietaireFormate());
}


