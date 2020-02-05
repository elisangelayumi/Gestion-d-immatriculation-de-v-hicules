/**
 * \file VehiculePromenade_Testeur.cpp
 * \brief Fichier de tests unitaires pour la classe VehiculePromenade
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-21
 */

#include "VehiculePromenade.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace saaq;


/**
 * \brief Test du constructeur VehiculePromenade::VehiculePromenade(p_niv, p_immatriculation, p_nbPlace)
 *
 *        cas valide :
 *          Création d'un vehicule promenade valide : ParametresValides
 *
 *        cas invalides :
 *        	immatriculation invalide : p_immatriculation Invalide
 *        	nbPlace invalide : p_nbPlace Invalide
 */
TEST(VehiculePromenade, constructeurParametresValides)
{
	VehiculePromenade unVehiculePro("1M8GDM9AXKP042788", "GIF 003", 5);

	ASSERT_TRUE(util::validerNiv("1M8GDM9AXKP042788"));
	ASSERT_TRUE(util::validationImmatriculationPromenade("GIF 003"));
	ASSERT_GT(5, 0);
}

//immatriculation invalide
TEST(VehiculePromenade, ConstructeurImmatriculationInvalide)
{
	ASSERT_THROW(VehiculePromenade vehiculeP1("1M8GDM9AXKP042788", "GIF003", 5), PreconditionException);
}

//nbPlace invalide
TEST(VehiculePromenade, ConstructeurNombrePlaceInvalide)
{
	ASSERT_THROW(VehiculePromenade vehiculeP2("1M8GDM9AXKP042788", "GIF 003", 0), PreconditionException);
}


/**
 * \class VehiculePromenadeValide
 * \brief Fixture pour les tests avec un Vehicule Promenade Valide
 */
class VehiculePromenadeValide: public :: testing :: Test
{
public:
	VehiculePromenade vehiculeProTest;

	VehiculePromenadeValide():
		vehiculeProTest("1M8GDM9AXKP042788", "GIF 003", 5){

	}
};


/**
 * \brief Test de la méthode VehiculePromenade::asgImmatriculation()
 *     Cas valide: format d'immatriculation valide selon le type de vehicule
 *     Cas invalide: format d'immatriculation invalide
 */
TEST_F(VehiculePromenadeValide, asgImmatriculationValide)
{
	string test = "TEST";
	vehiculeProTest.asgImmatriculation(test);
}

//cas invalide
TEST_F(VehiculePromenadeValide, asgImmatriculationInvalide)
{
	string test = "L098654";
	ASSERT_THROW(vehiculeProTest.asgImmatriculation(test), PreconditionException);
}


/**
 * \brief Test de la methode VehiculePromenade::reqNbPlaces()
 *        cas valide: verifier le retour de nombre de place du vehicule
 *        cas invalide: Aucun
 */
TEST_F(VehiculePromenadeValide, TestNombrePlace)
{
	ASSERT_EQ(5, vehiculeProTest.reqNbPlaces());
}


/**
 * \brief Test de la methode VehiculePromenade::tarificationAnnuelle()
 *        cas valide: verifier le retour de la valeur de tarification pour un vehicule promenade
 *        cas invalide: Aucun
 */
TEST_F(VehiculePromenadeValide, TestTarificationAnnuelle)
{
	ASSERT_EQ(224.04, vehiculeProTest.tarificationAnnuelle());
}


/**
 * \brief Test de la methode VehiculePromenade::clone()
 *        cas valide: verifier si la methode fait bien un clone de vehicule promenade
 *        cas invalide: Aucun
 */
TEST_F(VehiculePromenadeValide, TestClone)
{
	VehiculePromenade* monClone = (VehiculePromenade*) vehiculeProTest.clone();

	ASSERT_EQ(monClone->reqVehiculeFormate(), vehiculeProTest.reqVehiculeFormate());
}


/**
 * \brief Test de la methode VehiculePromenade::reqVehiculeFormate()
 *        cas valide: verifier le retour des information sur l'objets Vehicule Promenade
 *        cas invalide: Aucun
 */
TEST_F(VehiculePromenadeValide, TestVehiculeFormate)
{
	std::ostringstream os;
	os <<"Numero de serie : " << vehiculeProTest.reqNiv() << endl
	<< "Numero d’immatriculation : " << vehiculeProTest.reqImmatriculation() << endl
	<< "Date d’enregistrement : " << vehiculeProTest.reqdateEnregistrement().reqDateFormatee() << endl;
	os << "Nombre de place : " << vehiculeProTest.reqNbPlaces() << endl
	<< "Tarif : " << vehiculeProTest.tarificationAnnuelle() << "$" << endl;

	ASSERT_EQ(os.str(),vehiculeProTest.reqVehiculeFormate());
}

