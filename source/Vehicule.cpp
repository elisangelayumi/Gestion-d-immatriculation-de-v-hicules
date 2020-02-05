/**
 * \file Vehicule.cpp
 * \brief Implementation de la classe vehicule
 * \author Elisangela Yumi
 * \version 0.1
 * \date: 2019-10-12
 */

#include "Vehicule.h"
#include <iostream>
#include <sstream>

using namespace std;

namespace saaq {

/**
 * \brief Constructeur avec parametres
 * \param[in] p_niv Le numero de serie du vehicule;
 * \param[in] p_immatriculation Le numero de la plaque du vehicule;
 * \pre p_niv est un NIV valide;
 * \pre p_immatriculation est une plaque valide;
 * \pos m_immatriculation prends la valeur de p_immatriculation;
 * \pos m_niv prends la valeur de p_niv;
 * \return Un objet vehicule
 */
Vehicule::Vehicule(const string& p_niv, const string& p_immatriculation):
		m_niv(p_niv), m_immatriculation(p_immatriculation)
{
	util::Date dateCreation;
	m_dateEnregistrement = dateCreation;

	PRECONDITION(util::validerNiv(p_niv));

	POSTCONDITION(m_immatriculation == p_immatriculation);
	POSTCONDITION(m_niv == p_niv);

	INVARIANTS();
}


/**
 * \brief Acceseur pour NIV
 * \return m_niv Le numero de serie de l'objet
 */
const string Vehicule::reqNiv() const
{
	return m_niv;
}

/**
 * \brief Acceseur pour Immatriculation
 * \return m_immatriculation Le numero de la plaque de l'objet
 */
const string Vehicule::reqImmatriculation() const
{
	return m_immatriculation;
}

/**
 * \brief Acceseur pour date
 * \return m_dateEnregistrement La date de creation de l'objet
 */
const util::Date Vehicule::reqdateEnregistrement() const
{
	return m_dateEnregistrement;
}

/**
 * \brief Mutateur pour Immatriculation. Modifie la plaque du vehicule
 * \param[in] p_immatriculation String qui represente la nouvelle plaque
 * \pos m_immatriculation prends la valeur de p_immatriculation;
 */
void Vehicule::asgImmatriculation(string& p_immatriculation)
{
	m_immatriculation = p_immatriculation;

	POSTCONDITION(m_immatriculation == p_immatriculation);
	INVARIANTS();
}

/**
 * \brief Retourne une chaine de caractere formate qui contient l'information de l'objet vehicule
 * \return un string qui contient l'information de l'objet vehicule
 */
string Vehicule::reqVehiculeFormate() const
{
	std::ostringstream os;
	os << "Numero de serie : " << m_niv << endl
	 << "Numero d’immatriculation : " << m_immatriculation << endl
	 << "Date d’enregistrement : " << m_dateEnregistrement.reqDateFormatee();

	return os.str();
}

/**
 * \brief Surcharge de l'operateur == pour l'egalite entre de deux objets vehicule.
 * La comparaison est faite par rapport a tous les attributs de l'objet.
 * \param[in] p_vehicule Objet vehicule qu'on veut comparer par rapport au objet courant
 * \return un booleen qui indique si c'est egal ou non
 */
bool Vehicule::operator== (const Vehicule& p_vehicule) const
{
	return ( p_vehicule.m_niv == m_niv) && (p_vehicule.m_immatriculation == m_immatriculation) &&
			(p_vehicule.m_dateEnregistrement == m_dateEnregistrement);
}


/**
 * \brief pour vérifier l'invariant de classe dans l'implantation de la théorie du contrat
 */
void Vehicule::verifieInvariant() const
{
	INVARIANT(util::validerNiv(m_niv));
}

} /* namespace saaq */
