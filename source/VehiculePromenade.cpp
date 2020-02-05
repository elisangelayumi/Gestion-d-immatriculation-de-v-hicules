/**
 * \file VehiculePromenade.cpp
 * \brief Implementation de la classe VehiculePromenade
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-20
 */

#include "VehiculePromenade.h"
#include <sstream>

using namespace std;

namespace saaq {

/**
 * \brief Constructeur avec parametres
 * \param[in] p_niv Le numero de serie du vehicule;
 * \param[in] p_immatriculation Le numero de la plaque du vehicule;
 * \param[in] p_nbPlaces Le nombre de place que le vehicule possede.
 * \pre p_nbPlaces est un entier plus grand que zero;
 * \pre p_immatriculation est une plaque valide selon leur type promenade;
 * \pos m_nbPlaces prends la valeur de p_nbPlaces;
 * \return Un objet vehicule
 */
VehiculePromenade::VehiculePromenade(const std::string& p_niv, const std::string& p_immatriculation, const int p_nbPlaces):
	 Vehicule(p_niv, p_immatriculation), m_nbPlaces(p_nbPlaces)
	  {
		PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation));
		PRECONDITION(p_nbPlaces>0);

		POSTCONDITION(m_nbPlaces == p_nbPlaces);

		INVARIANTS();
	  }

/**
 * \brief Mutateur pour Immatriculation. Modifie la plaque du vehicule
 * \param[in] p_immatriculation String qui represente la nouvelle plaque
 * \pre p_immatriculation est une plaque valide selon leur type promenade
 */
void VehiculePromenade::asgImmatriculation(std::string& p_immatriculation)
{
	PRECONDITION(util::validationImmatriculationPromenade(p_immatriculation));

	Vehicule::asgImmatriculation(p_immatriculation);

	INVARIANTS();
}

/**
 * \brief Acceseur pour le nombre de places
 * \return m_nbPlaces Le nombre de places que le vehicule possede
 */
const int VehiculePromenade::reqNbPlaces() const
{
	return m_nbPlaces;
}

/**
 * \brief Methode permet de determiner la tarification annuelle de l’immatriculation d’un véhicule. Pour un
 * VehiculePromenade la la tarification est fixe.
 * \return tarif la tarification
 */
double VehiculePromenade::tarificationAnnuelle() const
{
	double tarif = 224.04;

	return tarif;
}

/**
 * \brief Permet de faire une copie allouée sur le monceau de l'objet courant
 * \return l'adresse d'un nouveau objet VehiculePromenade (clone)
 */
Vehicule* VehiculePromenade::clone() const
{
	return new VehiculePromenade(*this);
}

/**
 * \brief Retourne une chaine de caractere formate qui contient l'information de l'objet vehicule promenade
 * \return un string qui contient l'information de l'objet vehicule promenade
 */
std::string VehiculePromenade::reqVehiculeFormate() const
{
	std::ostringstream os;
	os << Vehicule::reqVehiculeFormate() << endl
	 << "Nombre de place : " << m_nbPlaces << endl
	 << "Tarif : " << this->tarificationAnnuelle() << "$" << endl;

	return os.str();
}

/**
 * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
 */
void VehiculePromenade::verifieInvariant() const
{
	INVARIANT(m_nbPlaces > 0);
	INVARIANT(util::validationImmatriculationPromenade(VehiculePromenade::reqImmatriculation()));

}

} /* namespace saaq */
