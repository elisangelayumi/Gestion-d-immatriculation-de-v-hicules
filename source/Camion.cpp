/**
 * \file Camion.cpp
 * \brief Implementation de la classe Camion
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-11-21
 */

#include "Camion.h"
#include <sstream>

using namespace std;

namespace saaq {


/**
 * \brief Constructeur avec parametres
 * \param[in] p_niv Le numero de serie du vehicule;
 * \param[in] p_immatriculation Le numero de la plaque du vehicule;
 * \param[in] p_poids Le poids du camion;
 * \param[in] p_nbEssieux Le nombre de essieux du camion;
 * \pre p_immatriculation est une plaque valide selon leur type camion;
 * \pre p_poids est un double plus grand que 3000;
 * \pre p_nbEssieux est un entier plus grand ou egal a 2;
 * \pos m_poids prends la valeur de p_poids;
 * \pos m_nbEssieux prends la valeur de p_nbEssieux;
 * \return Un objet vehicule
 */
Camion::Camion(const std::string& p_niv, const std::string& p_immatriculation, double p_poids, int p_nbEssieux):
		Vehicule(p_niv, p_immatriculation), m_poids(p_poids), m_nbEssieux(p_nbEssieux)
{
	PRECONDITION(util::validationImmatriculationCamion(p_immatriculation));
	PRECONDITION(p_poids > 3000);
	PRECONDITION(p_nbEssieux >= 2);

	POSTCONDITION(m_poids == p_poids);
	POSTCONDITION(m_nbEssieux == p_nbEssieux);

	INVARIANTS();

}

/**
 * \brief Acceseur pour le poids du camion
 * \return m_poids Le poids du camion
 */
const double Camion::reqPoids() const
{
	return m_poids;
}


/**
 * \brief Acceseur pour le nombre de essieux du camion
 * \return m_poids Le nombre de essieux du camion
 */
const int Camion::reqNbEssieux() const
{
	return m_nbEssieux;
}


/**
 * \brief Mutateur pour Immatriculation. Modifie la plaque du vehicule
 * \param[in] p_immatriculation String qui represente la nouvelle plaque
 * \pre p_immatriculation est une plaque valide selon leur type camion
 */
void Camion::asgImmatriculation(std::string& p_immatriculation)
{
	PRECONDITION(util::validationImmatriculationCamion(p_immatriculation));

	Vehicule::asgImmatriculation(p_immatriculation);

	INVARIANTS();
}

/**
 * \brief Methode permet de determiner la tarification annuelle de l’immatriculation d’un camion selon le nombre de
 * essieux et le poids.
 * \return tarif la tarification
 */
double Camion::tarificationAnnuelle() const
{
	double tarif = 0;

	if (m_nbEssieux == 2 && m_poids <= 4000)
		{
			tarif = 570.28;
			return tarif;
		}

	if (m_nbEssieux == 2 && m_poids >= 4001)
		{
			tarif = 905.28;
			return tarif;
		}

	switch(m_nbEssieux)
	{
		case 3:
			tarif = 1566.19;
			break;
		case 4:
			tarif = 2206.19;
			break;
		case 5:
			tarif = 2821.76;
			break;
		default:
			tarif = 3729.76;
	}

	return tarif;
}

/**
 * \brief Permet de faire une copie allouée sur le monceau de l'objet courant
 * \return l'adresse d'un nouveau objet Camion (clone)
 */
Vehicule* Camion::clone() const
{
	return new Camion(*this);
}


/**
 * \brief Retourne une chaine de caractere formate qui contient l'information de l'objet camion
 * \return un string qui contient l'information de l'objet camion
 */
std::string Camion::reqVehiculeFormate() const
{
	std::ostringstream os;
	os << Vehicule::reqVehiculeFormate() << endl
	<< "Nombre d'essieux : " << m_nbEssieux << endl
	<< "Poids : " << m_poids << " kg" << endl
	<< "Tarif : " << this->tarificationAnnuelle() << "$" << endl;

	return os.str();
}

/**
 * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
 */
void Camion::verifieInvariant() const
{
	INVARIANT(m_nbEssieux >= 2);
	INVARIANT(m_poids > 3000);
	INVARIANT(util::validationImmatriculationCamion(Camion::reqImmatriculation()));

}


} /* namespace saaq */
