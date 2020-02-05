/**
 * \file Camion_Testeur.cpp
 * \brief Fichier de tests unitaires pour la classe Camion
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-21
 */

#include "Camion.h"
#include "ContratException.h"
#include <gtest/gtest.h>

using namespace std;
using namespace saaq;


/**
 * \brief Test du constructeur Camion_Testeur::VehiculePromenade(p_niv, p_immatriculation, p_poids, p_nbEssieux)
 *
 *        cas valide :
 *          Création d'un camion valide : ParametresValides
 *
 *        cas invalides :
 *        	immatriculation invalide : p_immatriculation Invalide
 *        	poids invalide : p_poids Invalide
 *        	nbEssieux invalide : p_nbEssieux Invalide
 */
TEST(Camion, constructeurParametresValides)
{
	Camion unCamion("1M8GDM9AXKP042788", "L098765", 3500, 3);

	ASSERT_TRUE(util::validerNiv("1M8GDM9AXKP042788"));
	ASSERT_TRUE(util::validationImmatriculationCamion("L098765"));
	ASSERT_GT(3500, 3000);
	ASSERT_GE(3, 2);
}

/**
* \brief Test du constructeur Camion_Testeur::VehiculePromenade(p_niv, p_immatriculation, p_poids, p_nbEssieux)
* 		cas invalides : p_immatriculation Invalide
*/
TEST(Camion, ConstructeurImmatriculationInvalide)
{
	ASSERT_THROW(Camion unCamion3("1M8GDM9AXKP042788", "GIF 003", 3500, 3), PreconditionException);
}

/**
* \brief Test du constructeur Camion_Testeur::VehiculePromenade(p_niv, p_immatriculation, p_poids, p_nbEssieux)
* 		cas invalides : poids invalide
*/
TEST(VehiculePromenade, ConstructeurPoidsInvalide)
{
	ASSERT_THROW(Camion unCamion4("1M8GDM9AXKP042788", "L098765", 3000, 3), PreconditionException);
}

/**
* \brief Test du constructeur Camion_Testeur::VehiculePromenade(p_niv, p_immatriculation, p_poids, p_nbEssieux)
* 		cas invalides : NbEssieux invalide
*/
TEST(VehiculePromenade, ConstructeurNbEssieuxInvalide)
{
	ASSERT_THROW(Camion unCamion5("1M8GDM9AXKP042788", "L098765", 3200, 1), PreconditionException);
}


/**
 * \class CamionValide
 * \brief Fixture pour les tests avec un Camion Valide
 */
class CamionValide: public :: testing :: Test
{
public:
	Camion camion2essieux;
	Camion camion2essieuxPlusLourd;
	Camion camion3essieux;
	Camion camion4essieux;
	Camion camion5essieux;
	Camion camion6essieux;
	Camion camion9essieux;

	CamionValide():
		camion2essieux("1M8GDM9AXKP042788", "L098760", 3500, 2),
		camion2essieuxPlusLourd("1M8GDM9AXKP042788", "L098761", 5500, 2),
		camion3essieux("1M8GDM9AXKP042788", "L098762", 3600, 3),
		camion4essieux("1M8GDM9AXKP042788", "L098763", 3700, 4),
		camion5essieux("1M8GDM9AXKP042788", "L098764", 3800, 5),
		camion6essieux("1M8GDM9AXKP042788", "L098765", 4900, 6),
		camion9essieux("1M8GDM9AXKP042788", "L098766", 6100, 9){
	}
};

/**
 * \brief Test de la methode Camion::reqPoids()
 *        cas valide: verifier le retour du poids du camion
 *        cas invalide: Aucun
 */
TEST_F(CamionValide, TestReqPoids)
{
	ASSERT_EQ(3600,camion3essieux.reqPoids());
}


/**
 * \brief Test de la methode Camion::reqNbEssieux()
 *        cas valide: verifier le retour du nombre d'essieux du camion
 *        cas invalide: Aucun
 */
TEST_F(CamionValide, TestReqNbEssieux)
{
	ASSERT_EQ(3, camion3essieux.reqNbEssieux());
}


/**
 * \brief Test de la méthode Camion::asgImmatriculation()
 *     Cas valide: format d'immatriculation valide selon le type de vehicule
 *     Cas invalide: format d'immatriculation invalide
 */
TEST_F(CamionValide, asgImmatriculationValide)
{
	string test = "L123879";
	camion3essieux.asgImmatriculation(test);
}

/**
 * \brief Test de la methode Camion::asgImmatriculation()
 *        cas invalide: format d'immatriculation invalide
 */
TEST_F(CamionValide, asgImmatriculationInvalide)
{
	string test = "L09 654";
	ASSERT_THROW(camion3essieux.asgImmatriculation(test), PreconditionException);
}


/**
 * \brief Test de la methode Camion::tarificationAnnuelle()
 *  La valeur de tarification varie selon le nombre de essieux et le poids.
 *        	6 cas valides:
 *        		NbEssieux est egal a 2 et le poids est plus petit ou egal a 4000
 *        		Nb6 cas valides:Essieux est egal a 2 et le poids est plus grand ou egal a 4001
 *        		NbEssieux est egal a 3
 *        		NbEssieux est egal a 4
 *        		NbEssieux est egal a 5
 *        		NbEssieux est plus grand ou egal a 6
 *        	cas invalide: aucun
 */


/**
* \brief Test de la methode Camion::tarificationAnnuelle()
* 			cas valide 1 - NbEssieux est egal a 2 et le poids est plus petit ou egal a 4000
*/
TEST_F(CamionValide, TestTarificationAnnuelle1)
{
	ASSERT_EQ(2, camion2essieux.reqNbEssieux());
	ASSERT_LE(camion2essieux.reqPoids(), 4000);
	ASSERT_EQ(570.28, camion2essieux.tarificationAnnuelle());
}

/**
* \brief Test de la methode Camion::tarificationAnnuelle()
* 			cas valide 2 - NbEssieux est egal a 2 et le poids est plus grand ou egal a 4001
*/
TEST_F(CamionValide, TestTarificationAnnuelle2)
{
	ASSERT_EQ(2, camion2essieuxPlusLourd.reqNbEssieux());
	ASSERT_GE(camion2essieuxPlusLourd.reqPoids(),4001);
	ASSERT_EQ(905.28, camion2essieuxPlusLourd.tarificationAnnuelle());
}

/**
* \brief Test de la methode Camion::tarificationAnnuelle()
* 			cas valide 3 - NbEssieux est egal a 3
*/
TEST_F(CamionValide, TestTarificationAnnuelle3)
{
	ASSERT_EQ(3, camion3essieux.reqNbEssieux());
	ASSERT_EQ(1566.19, camion3essieux.tarificationAnnuelle());
}

/**
* \brief Test de la methode Camion::tarificationAnnuelle()
* 			cas valide 4 - NbEssieux est egal a 4
*/
TEST_F(CamionValide, TestTarificationAnnuelle4)
{
	ASSERT_EQ(4, camion4essieux.reqNbEssieux());
	ASSERT_EQ(2206.19, camion4essieux.tarificationAnnuelle());
}

/**
* \brief Test de la methode Camion::tarificationAnnuelle()
* 			cas valide 5 - NbEssieux est egal a 5
*/
TEST_F(CamionValide, TestTarificationAnnuelle5)
{
	ASSERT_EQ(5, camion5essieux.reqNbEssieux());
	ASSERT_EQ(2821.76, camion5essieux.tarificationAnnuelle());
}

/**
* \brief Test de la methode Camion::tarificationAnnuelle()
* 			cas valide 6 - NbEssieux est egal a 6
*/
TEST_F(CamionValide, TestTarificationAnnuelle6)
{
	ASSERT_EQ(6, camion6essieux.reqNbEssieux());
	ASSERT_EQ( 3729.76, camion6essieux.tarificationAnnuelle());
}

/**
 * \brief Test de la methode Camion::clone()
 *        cas valide: verifier si la methode fait bien un clone d'un camion
 *        cas invalide: Aucun
 */
TEST_F(CamionValide, TestClone)
{
	Camion* monClone = (Camion*) camion2essieux.clone();

	ASSERT_EQ(monClone->reqVehiculeFormate(), camion2essieux.reqVehiculeFormate());
}

/**
 * \brief Test de la methode Camion::reqVehiculeFormate()
 *        cas valide: verifier le retour des information sur l'objets Camion
 *        cas invalide: Aucun
 */
TEST_F(CamionValide, TestVehiculeFormate)
{
	std::ostringstream os;
	os <<"Numero de serie : " << camion2essieux.reqNiv() << endl
	<< "Numero d’immatriculation : " << camion2essieux.reqImmatriculation() << endl
	<< "Date d’enregistrement : " << camion2essieux.reqdateEnregistrement().reqDateFormatee() << endl;
	os << "Nombre d'essieux : " << camion2essieux.reqNbEssieux() << endl
	<< "Poids : " << camion2essieux.reqPoids() << " kg" << endl
	<< "Tarif : " << camion2essieux.tarificationAnnuelle() << "$" << endl;

	ASSERT_EQ(os.str(),camion2essieux.reqVehiculeFormate());
}

