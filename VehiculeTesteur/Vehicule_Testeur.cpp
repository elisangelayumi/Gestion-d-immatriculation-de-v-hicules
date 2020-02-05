/**
 * \file Vehicule_Testeur.cpp
 * \brief Fichier de tests unitaires pour la classe Vehicule
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-21
 */

#include "Vehicule.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace saaq;


/**
 * \class VehiculeTest
 * \brief class qui permet de tester les methodes d'un Vehicule
 */
class VehiculeTest: public Vehicule
{
public:
	VehiculeTest(const std::string& p_niv, const std::string& p_immatriculation):
		Vehicule(p_niv, p_immatriculation){};

	virtual Vehicule* clone() const
	{
		return new VehiculeTest(*this);
	}

	virtual double tarificationAnnuelle() const
	{
		return 0.0;
	}

	void asgImmatriculation(std::string& p_immatriculation)
	{
		PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation) || util::validationImmatriculationCamion(p_immatriculation));

		Vehicule::asgImmatriculation(p_immatriculation);
	}

	virtual std::string reqVehiculeFormate() const
	{
		std::ostringstream os;
		os << Vehicule::reqVehiculeFormate();
		return os.str();
	}
};


/**
 * \brief Test du constructeur
 * 		Cas valides: Création d'un objet Vehicule et vérification de l'assignation de tous les attributs
 *		Cas invalides:
 *		    Niv invalide
 */
TEST(VehiculeTest,Constructeur)
{
	VehiculeTest unVehicule("1M8GDM9AXKP042788", "IFT 007");

	ASSERT_EQ("1M8GDM9AXKP042788", unVehicule.reqNiv());
	ASSERT_EQ("IFT 007", unVehicule.reqImmatriculation());
	ASSERT_EQ(util::Date(), unVehicule.reqdateEnregistrement());
}

//NIV invalide
TEST(VehiculeTest, ConstructeurNivInvalide)
{
	ASSERT_THROW(VehiculeTest unVehicule2("1M8GDM9A1KP042788", "IFT 007"), PreconditionException);
}


/**
 * \brief Création d'une fixture à utiliser pour les méthodes public de la classe de test
 */
class UnVehicule: public ::testing::Test
{
public:

	VehiculeTest monVehicule;

	UnVehicule() :
		monVehicule("1M8GDM9AXKP042788", "IFT 007")
	{};

};

/**
 * \brief Test de la methode VehiculeTest::clone()
 *        cas valide: verifier si la methode fait bien un clone d'un Vehicule
 *        cas invalide: Aucun
 */
TEST_F(UnVehicule, TestClone)
{
	VehiculeTest* monClone = (VehiculeTest*) monVehicule.clone();

	ASSERT_EQ(monClone->reqVehiculeFormate(), monVehicule.reqVehiculeFormate());
}


/**
 * \brief Test de la méthode VehiculeTest::asgImmatriculation()
 *     Cas valide: format d'immatriculation valide selon le type de vehicule
 *     Cas invalide: format d'immatriculation invalide
 */
TEST_F(UnVehicule, asgImmatriculationValide)
{
	string test = "SAAQ";
	monVehicule.asgImmatriculation(test);
}

TEST_F(UnVehicule, asgImmatriculationInvalide)
{
	string test = "saaq";
	ASSERT_THROW(monVehicule.asgImmatriculation(test), PreconditionException);
}


/**
 * \brief Test de la methode VehiculeTest::reqNiv()
 *        cas valide: verifier le retour du Niv
 *        cas invalide: Aucun
 */
TEST_F(UnVehicule, TestReqNiv)
{
	ASSERT_EQ("1M8GDM9AXKP042788", monVehicule.reqNiv());
}


/**
 * \brief Test de la methode VehiculeTest::reqImmatriculation()
 *        cas valide: verifier le retour de la plaque
 *        cas invalide: Aucun
 */
TEST_F(UnVehicule, TestReqImmatriculation)
{
	ASSERT_EQ("IFT 007", monVehicule.reqImmatriculation() );
}


/**
 * \brief Test de la methode VehiculeTest::reqdateEnregistrement()
 *        cas valide: verifier le retour de la date d'enregistrement
 *        cas invalide: Aucun
 */
TEST_F(UnVehicule, TestReqDate)
{
	ASSERT_EQ(util::Date(), monVehicule.reqdateEnregistrement());
}


/**
 * \brief Test de la methode VehiculeTest::reqVehiculeFormate()
 *        cas valide: verifier le retour des information sur l'objets Vehicule
 *        cas invalide: Aucun
 */
TEST_F(UnVehicule, TestVehiculeFormate)
{
	std::ostringstream os;
	os <<"Numero de serie : " << monVehicule.reqNiv() << endl
	<< "Numero d’immatriculation : " << monVehicule.reqImmatriculation() << endl
	<< "Date d’enregistrement : " << monVehicule.reqdateEnregistrement().reqDateFormatee();

	ASSERT_EQ(os.str(),monVehicule.reqVehiculeFormate());
}


/**
 * \class DeuxVehicules
 * \brief Fixture pour les tests comparaisons de Deux vehicules
 */
class DeuxVehicules: public ::testing::Test
{
public:
	VehiculeTest monVehicule1;
	VehiculeTest monVehicule2;

	DeuxVehicules():
		monVehicule1("1M8GDM9AXKP042788", "IFT 007"),
		monVehicule2("2T3R1RFV7KW049674", "SAAQ"){
	}
};


/**
 * \brief  Test de la méthode bool VehiculeTest::operator== (const Vehicule& obj)
 *        cas valide:
 *   		OperatorEgalEgalVrai: 	Vehicule indentique à lui-même.
 *  		OperatorEgalEgalFaux: 	Vehicules différentes
 *        cas invalide Aucun d'identifié
 */
TEST_F(DeuxVehicules, OperatorEgalEgalVrai)
{
	ASSERT_TRUE(monVehicule1 == monVehicule1);
}


TEST_F(DeuxVehicules, OperatorEgalEgalFaux)
{
	ASSERT_FALSE(monVehicule1 == monVehicule2);
}


